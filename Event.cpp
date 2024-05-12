#include "Event.h"
#include "Time.h"
#include "Date.h"
#include <iostream>
using namespace std;

Event::Event() {
    eventId = 0; // Initialize eventId to a default value
    eventName = ""; // Initialize eventName to an empty string
    eventCategory = ""; // Initialize eventCategory to an empty string
    participants = nullptr; // Initialize participants to nullptr
    numParticipants = 0; // Initialize numParticipants to 0
}

Event::Event(int id, const string& name, const string& category, const string& participant,
             int year, int month, int day, int startHour, int startMinute)
    : eventId(id), eventName(name), eventCategory(category), numParticipants(0),
      eventDate(day, month, year), startTime(startHour, startMinute) {
    participants = new string[1];
    participants[0] = participant;
    numParticipants++;
}

int Event::getId() {
    return eventId;
}

string Event::getCategory() {
    return eventCategory;
}

Date Event::getDate() {
    return eventDate;
}

void Event::set(Event& e) {
    eventId = e.eventId;
    eventName = e.eventName;
    eventCategory = e.eventCategory;
    numParticipants = e.numParticipants;
    eventDate.set(e.eventDate); // Modify this line
    startTime.set(e.startTime); // Modify this line

    delete[] participants;
    participants = new string[numParticipants];
    for (int i = 0; i < numParticipants; ++i) {
        participants[i] = e.participants[i];
    }
}

void Event::addParticipant(string& p) {
    string* newParticipants = new string[numParticipants + 1];
    for (int i = 0; i < numParticipants; ++i) {
        newParticipants[i] = participants[i];
    }
    newParticipants[numParticipants] = p;

    delete[] participants;
    participants = newParticipants;
    numParticipants++;
}

bool Event::lessThan(Event& e) {
    if (eventDate.lessThan(e.eventDate)) { // Modify this line
        return true;
    } else if (eventDate.equals(e.eventDate)) { // Modify this line
        return startTime.lessThan(e.startTime); // Modify this line
    }
    return false;
}

void Event::print() {
    cout << "Event ID: " << eventId << endl;
    cout << "Event Name: " << eventName << endl;
    cout << "Event Category: " << eventCategory << endl;
    cout << "Event Participants: ";
    for (int i = 0; i < numParticipants; ++i) {
        cout << participants[i] << ", ";
    }
    cout << endl;
    cout << "Event Date: ";
    eventDate.print(); // Modify this line
    cout << endl;
    cout << "Start Time: ";
    startTime.print(); // Modify this line
    cout << endl;
}
