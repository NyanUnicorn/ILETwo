#include <Arduino.h>
#include "profile.h"
#include "timed_counter.h"

//TimedCounter * Acounter;

PROFILE_HUE_RGB* Ahue[PROFILE_HUE_SIZE];
Lightstrip lightstrip = Lightstrip();
//Profile * A;

void setup() {
  Serial.begin(9600);
  delay(1000);
  //Acounter = (TimedCounter *) malloc(sizeof(TimedCounter));
  Serial.print("malloc hue\n");
  *Ahue = (PROFILE_HUE_RGB *) calloc(PROFILE_HUE_SIZE,sizeof(*Ahue));
  //Serial.print("malloc strip\n");
  //A = (Profile*) malloc(sizeof(Profile));
  // put your setup code here, to run once:
  //Acounter[0] = TimedCounter();
  Serial.print("declare strip\n");
  //lightstrip->Lightstrip();
  //Serial.print("strip");
  for(int i = 0; i < PROFILE_HUE_SIZE; i++){
    Serial.print(i);
    Ahue[i]->r = 200;
  }
  //A[0] = Profile(PROFILE_HUE_EFFECT_SHIFT_LOOP_L,Acounter[0],Ahue, PROFILE_ARRANGE_NO_SPLIT, 10, lightstrip[0]);
}

void loop() {
  Serial.print("update");
  //A[0].update();
  Serial.print(Ahue[0]->r);
  delay(1000);
  lightstrip.display(*Ahue);
}

