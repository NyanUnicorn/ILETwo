#ifndef LIGHTSTRIP
#define LIGHTSTRIP

#include "Arduino.h"
#include <FastLED.h>
#include <math.h>
#include "statics.h"
//parameters
#define LIGHTSTRIP_LEDCOUNT 30
#define LIGHTSTRIP_LEDPIN 7


class Lightstrip
{
private:
    CRGB leds[LIGHTSTRIP_LEDCOUNT];
    PROFILE_HUE_RGB hueAvg[LIGHTSTRIP_LEDCOUNT];
private:
    void fadeHueToStripSize(PROFILE_HUE_RGB*);

public:
    void display(PROFILE_HUE_RGB []);
public:
    Lightstrip();
    ~Lightstrip();
};


#endif