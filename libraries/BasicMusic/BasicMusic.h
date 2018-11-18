#ifndef blasticMusic
#define blasticMusic
#include "Arduino.h"
#include <WString.h>
class MusicGenerator
{
public:
  MusicGenerator(int, int);
  void playNote(int);
  void playNote(int, int);
  void playNote(int, int, int);
  void repeatNote(int, int, int, int);
  void appregio(int, int, int, int);
  void randChord(int, int, int, int, int, int);
  void noteChord(int, int, int, int, int, int, int, int);

private:
  int _pin, _base;
  static const float _maj[4];
  static const float _min[4];
  static const float _aug[4];
  static const float _hdim[4];
  static const float _dim[4];
  static const float *_chords[5];
};
int toNote(int, int);
int nameToNote(String s);
#endif // !blasticMusic
