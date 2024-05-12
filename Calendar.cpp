#include "defs.h"
#include "Event.h"
#include "Date.h"
#include "Time.h"
#include "Calendar.h"
#include <iostream>
#include <string>

using namespace std;

Calendar::Calendar(const string& userName) : userName(userName), numEvents(0), nextEventId(EVENTS_ID) {
    // Initialize other data members if necessary
        // Initialize events array
    for (int i = 0; i < MAX_ARR; ++i) {
        events[i] = Event(0, "", "", "", 0, 0, 0, 0, 0); // Use appropriate values or default values
    }
}

bool Calendar::addEvent(string n, string cat, string part, int yr, int mth, int day, int hrs, int mins) {
    // Verify capacity
    if (numEvents >= MAX_ARR) {
        cout << "Error: Maximum capacity reached. Cannot add new event." << endl ;
        return false;
    }

    // Validate date and time parameters
    Date eventDate(day, mth, yr);
    Time startTime(hrs, mins);
    if (!eventDate.validate(day, mth, yr) || !startTime.validate(hrs, mins)) {
        cout << "Error: Invalid date or time parameters. Event not added." << endl ;
        return false;
    }

    // Create new event
    Event newEvent(nextEventId++, n, cat, part, yr, mth, day, hrs, mins);

    // Find insertion point
    int insertionPoint = findInsertionPoint(newEvent);

    // Shift events to make room for the new event
    shiftEvents(insertionPoint);

    // Insert new event at the insertion point
    events[insertionPoint] = newEvent;

    // Increment number of events
    numEvents++;

    return true;
}

bool Calendar::addParticipant(int id, string n) {
    // Search for the event with the given id
    for (int i = 0; i < numEvents; ++i) {
        if (events[i].getId() == id) {
            // Add participant to the event
            events[i].addParticipant(n);
            return true;
        }
    }
    // Event with the given id not found
    return false;
}

void Calendar::print() {
    cout << "Calendar user's name: " << userName << endl;
    for (int i = 0; i < numEvents; ++i) {
        events[i].print();
    }
}

void Calendar::printByDay(int yr, int mth, int day) {
    // Validate parameters
    Date targetDate(day, mth, yr);
    if (!targetDate.validate(day, mth, yr)) {
        cout << "Error: Invalid date. Cannot print events." << endl ;
        return;
    }

    // Print user's name and user-entered date
    cout << "Calendar user's name: " << userName << endl;
    cout << "User-entered date: ";
    targetDate.print();
    cout << endl;

    // Print events on the target date
    for (int i = 0; i < numEvents; ++i) {
        if (events[i].getDate().equals(targetDate)) {
            events[i].print();
        }
    }
}

void Calendar::printByCat(string cat) {
    cout << "Calendar user's name: " << userName << endl;
    cout << "Events in category \"" << cat << "\":" << endl;
    for (int i = 0; i < numEvents; ++i) {
        if (events[i].getCategory() == cat) {
            events[i].print();
        }
    }
}

int Calendar::findInsertionPoint(Event& newEvent) {
    for (int i = 0; i < numEvents; ++i) {
        if (events[i].lessThan(newEvent)) {
            continue;
        } else {
            return i; // Insert the new event at index i
        }
    }
    return numEvents; // If no suitable insertion point found, insert at the end
}

void Calendar::shiftEvents(int startIndex) {
    for (int i = numEvents - 1; i >= startIndex; --i) {
        events[i + 1] = events[i];
    }
}


