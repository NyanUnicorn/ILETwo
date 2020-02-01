#include  "profile.h"


void Profile::update(){
    unsigned long inc = counter.NextValue();
    switch (counter.IncrementStyle())
    {
    case COUNTER_INCREMENT_TIMED :
        //correct increment value;
        //inc = (long)( inc/ (speed * 10));
        this->addEffect((long)( (speed * 10)/inc));
        //caltulate a hue table for display depending on effect
            //stretch averages colors under increment value (recreate->volatilehue)
            //build only shows colors below increment value (recreate->volatilehue)
            //shift moves colors sideways (update->volatilehue)
        
        break;
    case COUNTER_INCREMENT_READ :
        this->addEffect(inc);
        break;
    case COUNTER_INCREMENT_INC :
        this->addEffect(inc * speed);
        break;
    
    default:
        break;
    }

    //display hue table
            //fade colors to fit number of leds
            //asigne color to each led
    output.display(this->hueOutput);
}


void Profile::addEffect(unsigned long _inc){
    int val = (int) _inc;
    int ival = 0;
    switch (hueEffect)
    {
    case PROFILE_HUE_EFFECT_BUILD :
        for(int i = 0; i < COUNTER_MAX_VALUE; ++i){
            hueVolatile[i] = i < val ? hue[i] : PROFILE_HUE_RGB{0,0,0};
        }
        break;
    case PROFILE_HUE_EFFECT_STRETCH:
            *hueVolatile = *stretchrgb(hue,0,_inc);
        break;
    case PROFILE_HUE_EFFECT_SHIFT_CUT_L :
        for(int i = 0; i < COUNTER_MAX_VALUE; ++i){
            ival = val - i;
            hueVolatile[i] = i >= val ? hue[ival] : PROFILE_HUE_RGB{0,0,0};
        }
        break;
    case PROFILE_HUE_EFFECT_SHIFT_CUT_R:
        for(int i = 0; i < COUNTER_MAX_VALUE; ++i){
            ival = val - i;
            hueVolatile[COUNTER_MAX_VALUE - i] = i >= val ? hue[ival] : PROFILE_HUE_RGB{0,0,0};
        }
        break;
    case PROFILE_HUE_EFFECT_SHIFT_LOOP_L:
        for(int i = 0; i < COUNTER_MAX_VALUE; ++i){
            ival = val - i;
            hueVolatile[i] = i >= val ? hue[ival] : hue[COUNTER_MAX_VALUE - ival];
        }
        break;
    case PROFILE_HUE_EFFECT_SHIFT_LOOP_R:
        for(int i = 0; i < COUNTER_MAX_VALUE; ++i){
            ival = val - i;
            hueVolatile[COUNTER_MAX_VALUE - i] = i >= val ? hue[ival] : hue[COUNTER_MAX_VALUE - ival];
        }
        break;
    default:
        break;
    }
}


void Profile::addLayout(){
    switch (this->layout)
    {
    case PROFILE_ARRANGE_NO_SPLIT:
        for(int i = 0;i < PROFILE_HUE_SIZE; i++){
            this->hueOutput[i] = this->hueVolatile[i];
        }
        break;
    case PROFILE_ARRANGE_CENTER_SPLIT:
        for(int i = 0;i < PROFILE_HUE_SIZE; i++){
            //TODO
            this->hueOutput[i] = this->hueVolatile[i];
        }
        break;
    case PROFILE_ARRANGE_CENTER_SPLIT_CROSS:
        for(int i = 0;i < PROFILE_HUE_SIZE; i++){
            //TODO
            this->hueOutput[i] = this->hueVolatile[i];
        }
        break;
    
    default:
        break;
    }
}




PROFILE_HUE_RGB* Profile::stretchrgb(PROFILE_HUE_RGB* _hue, int _start, int _end){
    //no security and checks... don't want the overhead, just keep in min end is bigger that start
    PROFILE_HUE_RGB _hueAvg[PROFILE_HUE_SIZE];
    int len = _end - _start;
    double step = (double) len / PROFILE_HUE_SIZE;
    double steps;
    for(int i = 0; i < PROFILE_HUE_SIZE; i++){
        steps += step;
        
        if(steps <= 1){
            _hueAvg[i] = _hue[i];
        }else{
            PROFILE_HUE_RGB set[] = {_hueAvg[i-1],_hueAvg[i]};
            //double av1 = steps -1.0f;
            //double av2 = 1.0f - steps;
            //              av1 , av2
            double avs[] = {steps -1.0f, 1.0f - steps};
            _hueAvg[i] = averageRGB(set, avs, ceil(steps));
        }
    }
    return _hue;
}



/*
PROFILE_HUE_RGB Profile::averageRGB(PROFILE_HUE_RGB* _cs, double _pcs[], int _num){
    int r = 0,g=0,b=0;
    for(int i = 0; i < _num; i++){
        r += (int) _cs[i].r * _pcs[i];
        g += (int) _cs[i].g * _pcs[i];
        b += (int) _cs[i].b * _pcs[i];
    }
    return {r,g,b};
}*/

Profile::Profile(){
    
}


Profile::Profile(int _effect,Counter _counter, PROFILE_HUE_RGB _hue[], int _layout, int _speed,Lightstrip _lightstrip){
    *hue = *_hue;
    *hueVolatile = *_hue;
    counter = _counter;
    speed = _speed;
    hueEffect = _effect;
    layout = _layout;
    this->output = _lightstrip;
}
Profile::~Profile(){

}