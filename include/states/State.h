#ifndef STATE_H
#define STATE_H

class State {
public:
    virtual ~State() = default;
    virtual void applySettings() = 0;  // This is the required method for all states
};

#endif
