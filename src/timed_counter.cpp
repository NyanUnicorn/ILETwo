#include "timed_counter.h"


unsigned long TimedCounter::LastValue() {
    return lastValue;
}
//getter
unsigned long TimedCounter::Value() {
    return value;
}
//returns next value
unsigned long TimedCounter::NextValue() {
    unsigned long t = millis();
    unsigned long delta = this->lastTime - t;
    this->lastTime = t;
    this->shiftProgress = this->correctShiftProgress(this->shiftProgress+=delta);
    return this->shiftProgress;
}
//getter
int TimedCounter::IncrementStyle(){
    return this->incrementStyle;
}
//returns corrected value
unsigned long TimedCounter::correctShiftProgress(unsigned long _shift){
    return _shift <= COUNTER_MAX_VALUE ? _shift : this->correctShiftProgress(_shift - COUNTER_MAX_VALUE);
}

TimedCounter::TimedCounter()
:Counter(COUNTER_INCREMENT_TIMED)
{

}

