#ifndef PROFILE
#define PROFILE

#include "timed_counter.h"
#include "stdlib.h"
#include <math.h> 
#include "lightstrip.h" 
#include "statics.h"

//led layout pattern
#define PROFILE_ARRANGE_CENTER_SPLIT 0
#define PROFILE_ARRANGE_CENTER_SPLIT_CROSS 1
#define PROFILE_ARRANGE_NO_SPLIT 2

//effects
#define PROFILE_HUE_EFFECT_STRETCH 0
#define PROFILE_HUE_EFFECT_BUILD 1
#define PROFILE_HUE_EFFECT_SHIFT_CUT_L 2
#define PROFILE_HUE_EFFECT_SHIFT_CUT_R 3
#define PROFILE_HUE_EFFECT_SHIFT_LOOP_L 4
#define PROFILE_HUE_EFFECT_SHIFT_LOOP_R 5
//properties
//#define PROFILE_COUNTER_MAX_VALUE 255       //1 byte
//#define PROFILE_HUE_EFFECT_MAX_SPEED 255    //1 byte / interpreted differently by each increment method: TIMED->x/10seconds; INC->x/10 refreshes



class Profile{
private:
    PROFILE_HUE_RGB hue[PROFILE_HUE_SIZE];
    PROFILE_HUE_RGB hueVolatile[PROFILE_HUE_SIZE];
    PROFILE_HUE_RGB hueOutput[PROFILE_HUE_SIZE];
    Lightstrip output;
    Counter counter;
    int speed;
    int hueEffect;
    int layout;
    int effect;
private:
    void initialize();
    void addEffect(unsigned long);
    void addLayout();
public:
    void reinitialize();
    void update();
    static PROFILE_HUE_RGB* stretchrgb(PROFILE_HUE_RGB[], int, int);
    //static PROFILE_HUE_RGB averageRGB(PROFILE_HUE_RGB[], double[], int);
public:
    Profile(int _effect,Counter _counter, PROFILE_HUE_RGB _hue[], int _layout, int _speed,Lightstrip _lightstrip);
    Profile();
    ~Profile();
};




#endif
