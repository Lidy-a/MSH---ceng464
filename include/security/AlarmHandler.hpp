#ifndef ALARM_HANDLER_HPP
#define ALARM_HANDLER_HPP

#include <string>

class AlarmHandler {
protected:
    AlarmHandler* next;

public:
    AlarmHandler() : next(0) {}
    virtual ~AlarmHandler() {}

    void setNext(AlarmHandler* n) { next = n; }

    virtual void handle(const std::string& event) {
        if (next)
            next->handle(event);
    }
};

#endif