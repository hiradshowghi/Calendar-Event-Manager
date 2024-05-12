#ifndef CALENDAR_H
#define CALENDAR_H

#define MAX_ARR_SIZE  128
#include "Event.h"
#include "defs.h"


class Calendar {
public:
    Calendar(const string& userName);
    bool addEvent(string n, string cat, string part, int yr, int mth, int day, int hrs, int mins);
    bool addParticipant(int id, string n);
    void print();
    void printByDay(int yr, int mth, int day);
    void printByCat(string cat);
    int findInsertionPoint( Event& newEvent) ;
    void shiftEvents(int startIndex);


private:
    string userName;
    Event events[MAX_ARR];
    int numEvents;
    int nextEventId;

};

#endif

