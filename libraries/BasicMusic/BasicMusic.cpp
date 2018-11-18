#include "Arduino.h"
#include "BasicMusic.h"
#include <WString.h>
constexpr float MusicGenerator::_maj[4] = {0, 4, 7, 11};
constexpr float MusicGenerator::_min[4] = {0, 3, 7, 10};
constexpr float MusicGenerator::_aug[4] = {0, 4, 8, 12};
constexpr float MusicGenerator::_hdim[4] = {0, 3, 6, 10};
constexpr float MusicGenerator::_dim[4] = {0, 3, 6, 9};
const float *MusicGenerator::_chords[5] = {MusicGenerator::_maj, MusicGenerator::_min, MusicGenerator::_aug, MusicGenerator::_hdim, MusicGenerator::_dim};
MusicGenerator::MusicGenerator(int pin, int base)
{
    _pin = pin;
    _base = base;
}
void MusicGenerator::playNote(int note)
{
    tone(_pin, (int)(_base * pow(2, note / 12.0)));
}
void MusicGenerator::playNote(int note, int dur)
{
    playNote(note);
    delay(dur);
    noTone(_pin);
}
void MusicGenerator::playNote(int note, int playDur, int pauseDur)
{
    playNote(note);
    delay(playDur);
    noTone(_pin);
    delay(pauseDur);
}
void MusicGenerator::repeatNote(int note, int playDur, int pauseDur, int reps)
{
    for (int i = 0; i < reps; i++)
    {
        playNote(note, playDur);
        delay(pauseDur);
    }
}
void MusicGenerator::appregio(int baseNote, int chord, int playDur, int pauseDur)
{
    for (int i = 0; i < 4; i++)
    {
        playNote(_chords[chord][i] + baseNote, playDur);
        delay(pauseDur);
    }
}
void MusicGenerator::randChord(int baseNote, int chord, int octaves, int playDur, int pauseDur, int reps)
{
    for (int i = 0; i < reps; i++)
    {
        playNote(toNote(_chords[chord][(int)random(4)] + baseNote, random(octaves)), playDur);
        delay(pauseDur);
    }
}
void MusicGenerator::noteChord(int note, int nplayDur, int baseNote, int chord, int octaves, int cPlayDur, int cPauseDur, int tReps)
{
    for (int i = 0; i < tReps; i++)
    {
        playNote(toNote(_chords[chord][(int)random(4)] + baseNote, random(octaves)), cPlayDur);
        playNote(note, nplayDur);
        delay(cPauseDur);
    }
}
int nameToNote(String s)
{
    static const int ltn[] = {12, 4, 3, 5, 7, 8, 10};
    int note = s[0] <= 'g' && s[0] >= 'a' ? s[0] - 'a': s[0] - 'A';
    if (note < 0 || note > 6)
        return 0;
    note = ltn[note];
    int curi = 1;
    while (s[curi] == 'b')
    {
        note--;
        curi++;
    }
    while (s[curi] == '#')
    {
        note++;
        curi++;
    }
    int oct = 2;
    if (s[curi] >= '0' || s[curi] <= '9')
        oct = s[curi] - '0';
    return toNote(note, oct);
}
int toNote(int note, int octave)
{
    return 12 * octave + note;
}