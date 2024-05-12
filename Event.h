#ifndef EVENT_H
#define EVENT_H


#include "Date.h"
#include "Time.h"
#include <string>
using namespace std;

class Event {
public:
    Event();
    Event(int id, const string& name, const string& category, const string& participant, int year, int month, int day, int startHour, int startMinute);
    int getId();
    string getCategory();
    Date getDate();
    void set(Event& e);
    void addParticipant(string& p);
    bool lessThan(Event& e);
    void print();

private:
    int eventId;
    string eventName;
    string eventCategory;
    string* participants;
    int numParticipants;
    Date eventDate;
    Time startTime;
};

#endif
