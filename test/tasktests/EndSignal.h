#ifndef TEST_ENDSIGNAL_H_
#define TEST_ENDSIGNAL_H_

class EndSignal {
public:
    EndSignal();
    ~EndSignal();
    
    bool hasEnded();
    void setEnded(bool ended);
private:
    bool ended;
};

#endif
