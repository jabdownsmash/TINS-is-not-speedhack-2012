/*
Copyright 2012 Pavel Sountsov

This file is part of TINSEngine.

TINSEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TINSEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TINSEngine.  If not, see <http://www.gnu.org/licenses/>.
*/
module game.Game;

import engine.BitmapManager;
import engine.Gfx;
import engine.Sfx;
import engine.Disposable;
import engine.Config;
import engine.Util;

import game.IGame;
import game.Mode;
import game.MainMenuMode;
import game.GameMode;

import tango.io.Stdout;
import tango.text.convert.Format;

import allegro5.allegro;
import allegro5.allegro_image;
import allegro5.allegro_primitives;
import allegro5.allegro_font;
import allegro5.allegro_ttf;

class CGame : CDisposable, IGame
{
	this()
	{
		al_init();
		al_install_keyboard();
		al_install_mouse();
		al_init_font_addon();
		al_init_ttf_addon();
		al_init_image_addon();
		
		Options = new CConfig("game.cfg");
		Gfx = new CGfx(Options);
		Sfx = new CSfx();
		
		Queue = al_create_event_queue();
		al_register_event_source(Queue, al_get_keyboard_event_source());
		al_register_event_source(Queue, al_get_mouse_event_source());
		al_register_event_source(Queue, al_get_display_event_source(Gfx.Display));
	}
	
	override
	void Dispose()
	{
		super.Dispose;
		
		al_destroy_event_queue(Queue);
		
		Sfx.Dispose;
		Gfx.Dispose;
		Options.Dispose;
	}
	
	void Run()
	{
		CMode mode;
		EMode next_mode = EMode.MainMenu;
		while(true)
		{
			scope(exit) if(mode) mode.Dispose;
			final switch(next_mode)
			{
				case EMode.MainMenu:
				{
					mode = new CMainMenuMode(this);
					break;
				}
				case EMode.Game:
				{
					mode = new CGameMode(this);
					break;
				}
				case EMode.Exit:
					goto exit;
			}
			next_mode = GameLoop(mode, next_mode);
		}
exit:{}
	}

	mixin(Prop!("double", "Time", "override", "protected"));
	mixin(Prop!("CGfx", "Gfx", "override", "protected"));
	mixin(Prop!("CSfx", "Sfx", "override", "protected"));
	mixin(Prop!("CConfig", "Options", "override", "protected"));
protected:
	EMode GameLoop(CMode mode, EMode old_mode)
	{
		ALLEGRO_EVENT event;
		Time = 0;
		
		float cur_time = al_get_time();
		float accumulator = 0;
		//float physics_alpha = 0;
		
		while(1)
		{
			float new_time = al_get_time();
			float delta_time = new_time - cur_time;
			al_rest(FixedDt - delta_time);
			
			delta_time = new_time - cur_time;
			cur_time = new_time;

			accumulator += delta_time;

			while (accumulator >= FixedDt)
			{
				while(al_get_next_event(Queue, &event))
				{
					auto new_mode = mode.Input(&event);
					if(new_mode != old_mode)
						return new_mode;
				}
				
				auto new_mode = mode.Logic(FixedDt);
				if(new_mode != old_mode)
					return new_mode;
				
				Time = Time + FixedDt;
				accumulator -= FixedDt;
			}

			//physics_alpha = accumulator / FixedDt;
			
			mode.Draw();
			
			Gfx.FlipDisplay();
		}
		assert(0);
	}
	
	override
	@property
	int Password()
	{
		return PasswordVal;
	}
	
	override
	@property
	void Password(int pass)
	{
		PasswordVal = pass;
	}

	int PasswordVal;

	ALLEGRO_EVENT_QUEUE* Queue;
	double TimeVal = 0.0f;
	
	CConfig OptionsVal;
	CGfx GfxVal;
	CSfx SfxVal;
	bool LoadVal = false;
}
