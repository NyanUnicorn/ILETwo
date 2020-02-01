#include "statics.h"


PROFILE_HUE_RGB averageRGB(PROFILE_HUE_RGB* _cs, double _pcs[], int _num){
    int r = 0,g=0,b=0;
    for(int i = 0; i < _num; i++){
        r += (int) _cs[i].r * _pcs[i];
        g += (int) _cs[i].g * _pcs[i];
        b += (int) _cs[i].b * _pcs[i];
    }
    return {r,g,b};
}
