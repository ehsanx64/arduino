#include <Arduino.h>
// #include "../../config.h"
#include "tone.h"

void Tone_Setup() {
#ifdef TONE_ENABLED
    Tone_Main();
#endif
}

void Tone_Loop() {
}

#ifdef TONE_ENABLED

void Tone_Main() {
    noTone(TONE_BUZZER);
#ifdef TONE_MELODY_ENABLED
    Tone_Melody_Play();
#else
    tone(TONE_BUZZER, 62, 1000);
#endif
}
#ifdef TONE_MELODY_ENABLED
// Notes in the melody:
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// Note durations: 4 = Quarter note, 8 = Eighth note, etc.:
int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
};

void Tone_Melody_Play() {
    // Iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++) {
        // To calculate the note duration, take one second divided by the note 
        // type. e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(TONE_BUZZER, melody[thisNote], noteDuration);

        // To distinguish the notes, set a minimum time between them. the note's
        // duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        // Stop the tone playing:
        noTone(TONE_BUZZER);
    }
}
#endif // TONE_MELODY_ENABLED

#endif // TONE_ENABLED






