#ifndef COUNTER
#define COUNTER

//increment method
#define COUNTER_INCREMENT_TIMED 0
#define COUNTER_INCREMENT_READ 1
#define COUNTER_INCREMENT_INC 2
//properties
#define COUNTER_MAX_VALUE 255

class ICounter
{
public:
    ICounter();
    virtual ~ICounter() {};
    virtual unsigned long LastValue() = 0;
    virtual unsigned long Value() = 0;
    virtual unsigned long NextValue() = 0;
    virtual int IncrementStyle() = 0;
};

class Counter : public ICounter{
protected:
    unsigned long lastValue;
    unsigned long value;
    int incrementStyle;
public:
    unsigned long LastValue() override;
    unsigned long Value() override;
    unsigned long NextValue() override;
    int IncrementStyle() override;
public:
    Counter(int increment_style);
    Counter();
    virtual ~Counter();
};

#endif
