#include "lightstrip.h"

void Lightstrip::display(PROFILE_HUE_RGB* _hue){
    /*
    PROFILE_HUE_RGB hue[LIGHTSTRIP_LEDCOUNT];
    fadeHueToStripSize(_hue);
    *hue = *hueAvg;
    //for(int i = 0; i < LIGHTSTRIP_LEDCOUNT; i++){

    //}
    for(int i = 0; i < LIGHTSTRIP_LEDCOUNT; i++){
        this->leds[i] = CRGB(hue[i].r,hue[i].g,hue[i].b);
    }*/
    this->leds[0] = CRGB(255,0,0);
    FastLED.show();
}

Lightstrip::Lightstrip(){
    FastLED.addLeds<WS2812, LIGHTSTRIP_LEDPIN, GRB>(this->leds, LIGHTSTRIP_LEDCOUNT);
}


void Lightstrip::fadeHueToStripSize(PROFILE_HUE_RGB* _hue){
    double stripChunk = 1.0f;
    double diff = (double) PROFILE_HUE_SIZE / (double) LIGHTSTRIP_LEDCOUNT;
    double oppDiff = (double) PROFILE_HUE_SIZE / (double)LIGHTSTRIP_LEDCOUNT;
    PROFILE_HUE_RGB composite[(int)ceil(oppDiff)];
    double compValList[(int)ceil(oppDiff)];
    int compCount = 0;
    int stripCount = 0;
    for(int i = 0; i < PROFILE_HUE_SIZE; i++){
        composite[compCount] = _hue[i];
        stripChunk-=diff;

        if(stripChunk <= .0f){
            compValList[compCount] = -stripChunk;
            hueAvg[stripCount] = averageRGB(composite, compValList, (int)ceil(oppDiff));
            ++stripCount;
            ++compCount;
            stripChunk+=diff;
            compValList[compCount] = -stripChunk;
            composite[compCount] = _hue[i];
            stripChunk-=diff;
            stripChunk+=1.0f;
        }else{
            compValList[compCount] = diff;
            ++compCount;
        }
        
    }
}

Lightstrip::~Lightstrip(){

}