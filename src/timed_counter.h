#ifndef TIMED_COUNTER
#define TIMED_COUNTER

#include "counter.h"
#include <Arduino.h> 

class TimedCounter : public Counter{
private:
    unsigned long lastTime;
    unsigned long shiftProgress;
public:
    TimedCounter();
    virtual ~TimedCounter(){};
private:
    unsigned long correctShiftProgress(unsigned long);
public:
    unsigned long LastValue() override;
    unsigned long Value() override;
    unsigned long NextValue() override;
    int IncrementStyle() override;

    unsigned long ShiftProgress();
};

#endif
