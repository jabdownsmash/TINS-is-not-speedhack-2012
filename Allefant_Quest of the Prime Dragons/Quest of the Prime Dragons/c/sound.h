/* This file was generated by scramble.py. */
#ifndef _SOUND_
#define _SOUND_
typedef struct Envelope Envelope;
#line 1 "src/sound.py"
#include "main.h"
#line 3
struct Envelope {
    float attack;
    float decay;
    float hold;
    float release;
#line 9
    float volume;
    float sustain;
};
#line 41
LandSound * sound_synthesize(Envelope * e, int note);
#endif
/* This file was generated by scramble.py. */