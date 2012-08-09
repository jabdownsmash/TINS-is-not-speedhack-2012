/* This file was generated by scramble.py. */
#include "music.h"
#line 4 "src/music.py"
static LandSound * samples[128][64];
#line 47
static NotesPlayer global_player;
static char const * current_tune;
#line 50
char const * music_tune1 = "\n"
    "X: 0\n"
    "T: Allefant Song\n"
    "M: 2/4\n"
    "L: 1/8\n"
    "K: Am\n"
    "|: \"Am\" A2 ^A2 B2 \"F\" c3d1c4z2 | \"Am\"A2^A2B2 \"F\" c3d1c4z2 | \"F\" f2c2A2F2 \"C\"  F2E1G3z2 | \"C\" ^A2G2G2 \"F\" E1 F7z2 :|\n"
    "|: \"C\" E2 G2 c1 \"F\" x1 B4 A2 F2 z2 | \"Bdim\" D2F2B2 \"C\" A4G2E2 z2 :|\n"
    "";
#line 60
char const * music_tune2 = "\n"
    "X: 0\n"
    "T: Katyusha\n"
    "M: 2/4\n"
    "L: 1/8\n"
    "K: Am\n"
    "[| \"Am\"A3 B | c3 A | cc BA | \"E7\"B2 E2 | B3 c | d3 B | dd cB | \"Am\"A4 ||\n"
    "|: \"Am\"e2 \"F\"a2 | \"C\"g2 \"A7\"ag | \"Dm\"ff ed | \"Am\"e2 A2 | \"Dm\"zf2 d | \"Am\"e3 c | \"E7\"BE cB | \"Am\"A4 :|\n"
    "K: Em\n"
    "[| \"Em\"E3 F | G3 E | GG FE | \"B7\"F2 B,2 | F3 G | A3 F | AA GF | \"Em\"E4 ||\n"
    "|: \"Em\"B2 \"C\"e2 | \"G\"d2 \"E7\"ed | \"Am\"cc BA | \"Em\"B2 E2 | \"Am\"zc2 A | \"Em\"B3 G | \"B7\"FB, GF | \"Em\"E4 :|\n"
    "K: Gm\n"
    "[| \"Gm\"G3 A | B3 G | BB AG | \"D7\"A2 D2 | A3 B | c3 A | cc BA | \"Gm\"G4 ||\n"
    "|: \"Gm\"d2 \"E\"g2 | \"B\"f2 \"G7\"gf | \"Cm\"ee dc | \"Gm\"d2 G2 | \"Cm\"ze2 c | \"Gm\"d3 B | \"D7\"AD BA | \"Gm\"G4 :|\n"
    "K: Dm\n"
    "[| \"Dm\"D3 E | F3 D | FF ED | \"A7\"E2 A,2 | E3 F | G3 E | GG FE | \"Dm\"D4 ||\n"
    "|: \"Dm\"A2 \"B\"d2 | \"F\"c2 \"D7\"dc | \"Gm\"BB AG | \"Dm\"A2 D2 | \"Gm\"zB2 G | \"Dm\"A3 F | \"A7\"EA, FE | \"Dm\"D4 :|\n"
    "";
#line 79
char const * music_tune3 = "\n"
    "X:10\n"
    "T:Baron O' Brackley, The\n"
    "M:3/4\n"
    "L:1/8\n"
    "Q:1/4=100\n"
    "K:C\n"
    "D2|\"Dm\"D2 F3E|\"Dm\"D3C D2|\"F\"F2 G2 A2|\"C\"GG- G4|z4 A2|\\n"
    "\"Dm\"Ad3 c2|\"F\"c2 A2 G2|\"F\"F3D C2|\"Dm\"DD3 A-c|\n"
    "\"Dm\"dd3 e2|\"dm\"d2 c2 e2|\"F\"d2 A3F|\"C\"G6|z4 A2|\\n"
    "\"Dm\"A2 d3c|\"F\"c2 A2 G2|\"F\"F3D C2|\"Dm\"D6||\n"
    "";
#line 92
char const * music_tune4 = "\n"
    "X: 1\n"
    "T: the Drunken Sailor\n"
    "M: C|\n"
    "L: 1/8\n"
    "K: Ddor\n"
    "[| \"Dm\"A2AA A2AA | A2D2 F2A2 | \"C\"G2GG G2GG | G2C2 E2G2 \\n"
    "|  \"Dm\"A2AA A2AA | A2B2 c2d2 | \"Am\"c2A2 G2E2 | \"Dm\"D4 D4 |]\n"
    "[| \"Dm\"A4 A4 | A2D2 F2A2 | \"C\"G4 G4 | G2C2 E2G2 \\n"
    "|  \"Dm\"A4 A4 | A2B2 c2c2 | \"Am\"c2A2 G2E2 | \"Dm\"D4 D4 |]\n"
    "";
#line 104
char const * music_tune5 = "\n"
    "X: 1\n"
    "T:Battle of Aughrim march\n"
    "M:2/4\n"
    "L:1/8\n"
    "S:120 Favorite Irish Session Tunes\n"
    "R:march\n"
    "N:Douglas Cole St. Paul Slow Session\n"
    "K:Ador\n"
    "|: \"am\"EA A B/d/| \"am(C)\"ed cA| \"G\"BG G/F/G/A/| \"em\"B A/G/ ED|\n"
    "\"am\"EA A B/d/| \"am(C)\"e e/d/ e a/g/| \"G(em)\"a/g/e/d/ \"em(G)\"B/e/d/B/|\n"
    "\"am\"A2 A2 :|\n"
    "|: \"am\"a/b/a/g/ e f/g/| \"am(bm)\"a/b/a/g/ e f/g/| \"am(C)\"a a/f/ g g/e/|\n"
    "\"G(D)\"d B G2|\n"
    "\"am\"a/b/a/g/ e f/g/| \"am(bm)\"a/b/a/g/ e e/d/| \"G(em)\"Be \"em(G)\"dB|\n"
    "\"em(am)\"A2 A2 :|\n"
    "";
#line 122
static LandStream * stream;
#line 124
static int const notevals[3][7] = {{0, 2, 4, 5, 7, 9, 11} , {0, 2, 3, 5, 7, 8, 10} , {0, 2, 3, 5, 7, 9, 10} , };
#line 130
int noteval(int key, int scale, int note) {
#line 130
    /* key: 0..6
     * note: 0..6
     * scale: 0: major
     * 1: minor
     * 2: dorian
     */
#line 139
    int table[8];
    int base = notevals[0][key];
    for (int i = 0; i < 7; i += 1) {
        int j = (key + i) % 7;
        table[j] = (base + notevals[scale][i]) % 12;
    }
    return table[note];
}
static void read_fraction(char const * s, int * num, int * den) {
    bool divide = 0;
    int l = strlen(s);
    for (int i = 0; i < l; i += 1) {
        int c = s[i];
        if (c >= '0' && c <= '9') {
            if (divide) {
#line 153
                * den = c - '0';
            }
#line 154
            else {
#line 154
                * num = c - '0';
            }
        }
#line 155
        else if(c == '/') {
            divide = 1;
        }
    }
}
#line 158
static char const * note_names[12] = {"C", "^C", "D", "^D", "E", "F", "^F", "G", "^G", "A", "^A", "B"};
#line 160
static int chords[][5] = {{99} , {0, 4, 7, 99} , {0, 3, 7, 99} , {0, 4, 7, 10, 99} , {0, 3, 6, 99} , };
#line 168
char * note_string(int note, char * out) {
    out[0] = 0;
    if (note == 0) {
        strcat(out, "-");
    }
#line 172
    else if(note == 128) {
        strcat(out, "z");
    }
#line 174
    else {
        int octave = note / 12;
        note %= 12;
        strcat(out, note_names[note]);
        if (octave < 5) {
            for (int i = 0; i < 5 - octave; i += 1) {
                strcat(out, ",");
            }
        }
#line 181
        else if(octave >= 6) {
            out[strlen(out) - 1] += 'a' - 'A';
#line 184
            for (int i = 7; i < octave; i += 1) {
                strcat(out, "'");
            }
        }
    }
#line 186
    return out;
}
static void note_add(NotesPlayer * player, int note, int ticks, int timestamp) {
    int prev = player->last_note;
    int i = player->highest_index++;
    if (i == 0) {
        i++;
        player->highest_index++;
        if (player->highest_index >= 8192) {
            player->highest_index--;
            printf("FIXME: music is fixed length right now!\n");
        }
    }
#line 198
    if (prev) {
        while (prev) {
            if (timestamp > player->notes[prev] .timestamp) {
#line 200
                break;
            }
#line 201
            prev = player->notes[prev] .prev_index;
        }
    }
#line 203
    if (prev) {
        player->notes[i] .prev_index = prev;
        player->notes[i] .next_index = player->notes[prev] .next_index;
        player->notes[prev] .next_index = i;
    }
#line 207
    else {
        player->notes[i] .prev_index = 0;
        player->notes[i] .next_index = player->first_note;
        player->first_note = i;
    }
    if (player->notes[i] .next_index) {
        player->notes[player->notes[i] .next_index] .prev_index = i;
    }
#line 214
    else {
        player->last_note = i;
    }
    player->notes[i] .timestamp = timestamp;
    player->notes[i] .ticks = ticks;
    player->notes[i] .note = note;
}
#line 224
static int letter_to_note(int c) {
    c -= 'C';
    if (c < 0) {
#line 226
        c += 7;
    }
#line 227
    return c;
}
static void parse_note(ABCParser * abc) {
    int note = 0;
    int duration = 0;
    int octave = 0;
    bool divide = 0;
    int divisor = 1;
    int half = 0;
    bool string = 0;
    char stringval[100];
#line 239
    while (1) {
        int c = abc->tune[abc->pos];
#line 242
        if (! c) {
            break;
        }
#line 244
        if (c == '\n') {
            break;
        }
        abc->pos++;
#line 249
        int next_c = abc->tune[abc->pos];
#line 251
        if (string) {
            int s = strlen(stringval);
            if (c == '"') {
                abc->chord_note = letter_to_note(stringval[0]);
                abc->chord_type = 1;
                if (s >= 2) {
                    if (stringval[1] == 'm') {
                        abc->chord_type = 2;
                    }
#line 259
                    else if(stringval[1] == '7') {
                        abc->chord_type = 3;
                    }
#line 261
                    else if(stringval[1] == 'd') {
                        abc->chord_type = 4;
                    }
                }
#line 263
                string = 0;
            }
#line 264
            else {
                stringval[s] = c;
                stringval[s + 1] = 0;
            }
#line 267
            continue;
        }
        if (c == '"') {
            stringval[0] = 0;
            string = 1;
        }
#line 272
        else if(c >= 'A' && c <= 'G') {
            if (note) {
#line 273
                abc->pos--;
#line 273
                break;
            }
#line 274
            note = 60 + noteval(abc->key_note, abc->key_scale, letter_to_note(c));
        }
        else if(c >= 'a' && c <= 'g') {
            if (note) {
#line 277
                abc->pos--;
#line 277
                break;
            }
#line 278
            note = 60 + noteval(abc->key_note, abc->key_scale, letter_to_note(c + 'C' - 'c')) + 12;
        }
        else if(c == 'z') {
            if (note) {
#line 281
                abc->pos--;
#line 281
                break;
            }
#line 282
            note = 128;
        }
#line 283
        else if(c == '(') {
            if (note) {
#line 284
                abc->pos--;
#line 284
                break;
            }
#line 285
            if (next_c >= '0' && next_c <= '9') {
                abc->pos++;
            }
        }
#line 288
        else if(c == 'x') {
            if (note) {
#line 289
                abc->pos--;
#line 289
                break;
            }
#line 290
            note = 128;
        }
#line 291
        else if(c == '^') {
            if (note) {
#line 292
                abc->pos--;
#line 292
                break;
            }
#line 293
            half = 1;
        }
#line 294
        else if(c == '_') {
            if (note) {
#line 295
                abc->pos--;
#line 295
                break;
            }
#line 296
            half = - 1;
        }
#line 297
        else if(c == ',') {
            octave--;
        }
#line 299
        else if(c == '\'') {
            octave++;
        }
#line 301
        else if(c >= '0' && c <= '9') {
            if (divide) {
#line 302
                divisor = c - '0';
            }
#line 303
            else {
                duration *= 10;
                duration += c - '0';
            }
        }
#line 306
        else if(c == '/') {
            divide = 1;
        }
#line 308
        else if(c == '|') {
            if (note) {
#line 309
                abc->pos--;
#line 309
                break;
            }
#line 310
            if (next_c == ':') {
#line 312
                abc->pos++;
                abc->repeat_start_pos = abc->pos;
            }
#line 314
            else if(next_c >= '0' && next_c <= '9') {
                abc->pos++;
                if (next_c == '1') {
                    if (abc->repeating) {
                        abc->repeating = 0;
                        abc->pos = abc->repeat_end_pos;
                    }
                }
            }
        }
#line 320
        else if(c == ':') {
            if (next_c == '|') {
                if (abc->repeating) {
                    abc->repeating = 0;
                }
#line 324
                else {
#line 326
                    abc->repeat_end_pos = abc->pos;
                    abc->pos = abc->repeat_start_pos;
                    abc->repeating = 1;
                }
            }
        }
    }
#line 330
    if (! duration) {
#line 330
        duration = 1;
    }
    int ticks = abc->ticks64 * 64 * abc->note_numerator * duration;
    ticks /= divisor * abc->note_denominator;
#line 335
    if (note > 0 && note < 128) {
        note += octave * 12 + half;
#line 341
        note_add(abc->player, note, ticks, abc->timestamp);
    }
    if (abc->chord_type) {
#line 345
        int chord_span = abc->ticks64 * 64 * abc->meter_numerator / abc->meter_denominator / 2;
#line 347
        while (abc->chord_tick < abc->timestamp + ticks) {
#line 349
            int i = 0;
            int chord_octave = 4;
            int base = chord_octave * 12 + notevals[0][abc->chord_note];
#line 353
            note_add(abc->player, base + chords[abc->chord_type][0] - 12, chord_span / 4, abc->chord_tick);
#line 356
            while (chords[abc->chord_type][i] != 99) {
                note_add(abc->player, base + chords[abc->chord_type][i] , chord_span / 4, abc->chord_tick + chord_span / 2);
#line 359
                i++;
            }
            abc->chord_tick += chord_span;
        }
    }
#line 363
    abc->timestamp += ticks;
}
static void parse_notes(ABCParser * abc) {
    while (1) {
        char c = abc->tune[abc->pos];
        if (! c) {
#line 368
            break;
        }
#line 369
        if (c == '\n') {
#line 369
            break;
        }
#line 370
        parse_note(abc);
    }
}
#line 372
void music_parse_abc(char const * tune, NotesPlayer * player) {
    int tag = 0;
    int const OUTSIDE = 0;
    int const INSIDE = 1;
    int const COMMENT = 2;
    int mode = OUTSIDE;
    char line[1024];
#line 380
    ABCParser abc_;
    ABCParser * abc = & abc_;
    abc->player = player;
    abc->pos = 0;
    abc->tune = tune;
    abc->timestamp = 0;
    abc->key_note = 0;
    abc->key_scale = 0;
    abc->chord_note = 0;
    abc->chord_type = 0;
    abc->note_numerator = 1;
    abc->note_denominator = 8;
    abc->chord_tick = 0;
    abc->repeat_start_pos = 0;
    abc->repeating = 0;
    abc->ticks64 = 1500;
    abc->meter_numerator = 2;
    abc->meter_denominator = 4;
#line 399
    while (1) {
        char c = abc->tune[abc->pos++];
        if (! c) {
#line 401
            break;
        }
#line 402
        if (mode == OUTSIDE) {
            if (c <= 32) {
#line 403
                continue;
            }
#line 404
            if (c == '%') {
                mode = COMMENT;
                continue;
            }
            if (tune[abc->pos] == ':') {
                if ((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z')) {
                    abc->pos++;
                    tag = c;
                    mode = INSIDE;
                    line[0] = 0;
                    continue;
                }
            }
            abc->pos--;
            parse_notes(abc);
        }
#line 422
        else if(mode == INSIDE) {
            int s = strlen(line);
            if (c == '\n') {
                mode = OUTSIDE;
                if (tag == 'K') {
                    abc->key_note = 0;
                    abc->key_scale = 0;
#line 431
                    bool got_note = 0;
                    for (int i = 0; i < s; i += 1) {
                        if (! got_note) {
                            if (line[i] >= 'A' && line[i] <= 'G') {
                                abc->key_note = letter_to_note(line[i]);
                                got_note = 1;
                            }
                        }
#line 437
                        else {
                            if (line[i] == 'm') {
                                abc->key_scale = 1;
                            }
#line 440
                            else if(line[i] == 'd') {
                                abc->key_scale = 2;
                            }
                        }
                    }
                }
#line 442
                else if(tag == 'L') {
                    read_fraction(line, & abc->note_numerator, & abc->note_denominator);
                }
#line 446
                else if(tag == 'M') {
                    read_fraction(line, & abc->meter_numerator, & abc->meter_denominator);
                }
            }
            else {
                line[s] = c;
                line[s + 1] = 0;
            }
        }
#line 453
        else if(mode == COMMENT) {
            if (c == '\n') {
                mode = OUTSIDE;
            }
        }
    }
}
#line 457
int timestamp_to_samples(int ticks) {
    return ticks;
}
int mix_note(NotesPlayer * player, Envelope * e, Note * note, int16_t * b, int count) {
#line 462
    if (! samples[note->note][note->ticks / 750]) {
        e->hold = note->ticks / 750 / 64.0 - e->attack - e->decay - e->release;
        samples[note->note][note->ticks / 750] = sound_synthesize(e, note->note);
    }
    LandSound * sample = samples[note->note][note->ticks / 750];
#line 468
    int start = timestamp_to_samples(note->timestamp);
    int n = land_sound_length(sample);
#line 471
    if (start >= player->sample_pos + count) {
#line 471
        return 1;
    }
#line 472
    if (player->sample_pos >= start + n) {
#line 472
        return - 1;
    }
    int16_t * s = land_sound_sample_pointer(sample);
#line 476
    if (start + n > player->sample_pos + count) {
        n = player->sample_pos + count - start;
    }
    if (start < player->sample_pos) {
        n += start - player->sample_pos;
        s += (player->sample_pos - start) * 2;
        start = player->sample_pos;
    }
    if (player->sample_pos < start) {
        b += (start - player->sample_pos) * 2;
    }
#define mix(a, b) \
        v = a + b; \
        if (v < - 32768) { \
            v = - 32768; \
        } \
        if (v > 32767) { \
            v = 32767; \
        } \
        a = v;
#line 493
    for (int i = 0; i < n; i += 1) {
        int v;
        mix(b[i * 2 + 0] , s[i * 2 + 0]);
        mix(b[i * 2 + 1] , s[i * 2 + 1]);
    }
    return 0;
}
static int start = 0;
#line 502
void music_play_tune(char const * tune) {
    NotesPlayer * player = & global_player;
#line 505
    player->highest_index = 0;
    player->first_note = 0;
    player->last_note = 0;
    music_parse_abc(tune, player);
    current_tune = tune;
    player->oldest_active_note = player->first_note;
    player->sample_pos = 0;
#line 513
    start = land_get_ticks();
}
void music_tick(void) {
#line 517
    NotesPlayer * player = & global_player;
#line 519
    if (! current_tune) {
#line 519
        return;
    }
    int fragment_samples = 2048;
#line 523
    if (! stream) {
        stream = land_stream_new(fragment_samples, 4, 48000, 16, 2);
    }
    int16_t * b = land_stream_buffer(stream);
    if (! b) {
#line 527
        return;
    }
    memset(b, 0, fragment_samples * 4);
#line 535
    if (! player->oldest_active_note) {
        player->oldest_active_note = player->first_note;
        player->sample_pos = 0;
        start = land_get_ticks();
    }
    Envelope e = {.attack = 0.025, .decay = 0.025, .hold = 0, .release = 0.025, .volume = 0.2, .sustain = 0.1};
#line 548
    int ni = player->oldest_active_note;
    while (1) {
        Note * n = player->notes + ni;
        if (n->note > 0 && n->note < 128) {
            int r = mix_note(player, & e, n, b, fragment_samples);
            if (r == 1) {
#line 553
                break;
            }
#line 554
            if (r == - 1 && ni == player->oldest_active_note) {
                player->oldest_active_note = n->next_index;
            }
        }
#line 556
        ni = n->next_index;
#line 560
        if (! ni) {
            break;
        }
#line 562
        n = player->notes + ni;
    }
#line 565
    land_stream_fill(stream);
#line 567
    player->sample_pos += fragment_samples;
}
int music_ticks(void) {
    if (! current_tune) {
#line 570
        return 0;
    }
#line 571
    return land_get_ticks() - start;
}
/* This file was generated by scramble.py. */
