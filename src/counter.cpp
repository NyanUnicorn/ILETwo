#include "counter.h"

ICounter::ICounter(){

}

unsigned long Counter::LastValue() {return 0L;}
unsigned long Counter::Value() {return 0L;}
unsigned long Counter::NextValue() {return 0L;}
int Counter::IncrementStyle() {return 0;};

Counter::Counter(int _incs)
: ICounter(){
    this->lastValue = 0;
    this->value = 0;
    this->incrementStyle = _incs;
}


Counter::Counter()
: ICounter(){
    this->lastValue = 0;
    this->value = 0;
    this->incrementStyle = 0;

}
Counter::~Counter()
{

}