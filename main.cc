#include <iostream>
using namespace std;
#include <string>
#include "Calendar.h"
#include "defs.h"




int main() {
    // Declare a local Calendar object to represent the user’s calendar in the program
    Calendar timmysCalendar("Timmy Tortoise");

    // Load Timmy’s calendar data into the local calendar object
    loadEvents(timmysCalendar);

    int choice;
    do {
        // Show the menu and get user's choice
        showMenu(choice);

        // Process each user selection
        switch (choice) {
            case 1:
                // View calendar
                timmysCalendar.print();
                break;
            case 2: {
                // View day calendar
                int year, month, day;
                cout << "Enter year, month, and day: ";
                cin >> year >> month >> day;
                timmysCalendar.printByDay(year, month, day);
                break;
            }
            case 3: {
                // View category calendar
                string category;
                cout << "Enter category: ";
                cin >> category;
                timmysCalendar.printByCat(category);
                break;
            }
            case 4: {
                // Add an event
                string eventName, category, participant;
                int year, month, day, hours, minutes;
                cout << "Enter event name: ";
                cin.ignore(); // Ignore newline character
                getline(cin, eventName);
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter main participant: ";
                cin >> participant;
                cout << "Enter year, month, day: ";
                cin >> year >> month >> day;
                cout << "Enter start hour and minutes: ";
                cin >> hours >> minutes;
                // Call the addEvent function to create a new event and add it to Timmy’s calendar
                bool success = timmysCalendar.addEvent(eventName, category, participant, year, month, day, hours, minutes);
                if (success) {
                    cout << "Event added successfully." << endl;
                } else {
                    cout << "Failed to add event." << endl;
                }
                break;
            }
            case 0:
                // Exit program
                cout << "Exiting program." << endl;
                break;
            default:
                // Handle invalid menu choices
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}


void showMenu(int& choice)
{
 int numOptions = 4;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) View calendar" << endl;
  cout << "  (2) View day calendar" << endl;
  cout << "  (3) View category calendar" << endl;
  cout << "  (4) Add an event" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void loadEvents(Calendar& cal)
{
  cal.addEvent("2024 National Heroes Conference", "Work",  "Timmy", 2024,  2, 25,  8, 30);
  cal.addEvent("2023 National Heroes Conference", "Work",  "Timmy", 2023,  2, 24,  8, 30);
  cal.addEvent("Slay dragon",                     "Work",  "Timmy", 2024,  4, 11,  9, 30);
  cal.addEvent("Climb Mount of Dooom",            "Work",  "Timmy", 2024,  4,  8, 10,  0);
  cal.addEvent("some thing",                      "Work",  "Timmy", 2024,  3, 32, 10,  0);
  cal.addEvent("some other thing",                "Other", "Timmy", 2023,  2,  1, 24,  0);
  cal.addEvent("some new thing",                  "Test",  "Timmy", 2023,  2, 18, 14,  0);
  cal.addEvent("Lunch with Gwendolyn",            "Home",  "Timmy", 2024,  3, 29, 11, 45);
  cal.addEvent("Heroes meeting",                  "Work",  "Timmy", 2024,  1,  8,  9,  0);
  cal.addEvent("Practice sparring",               "Work",  "Timmy", 2024,  1, 10, 13, 45);
  cal.addEvent("Sharpen sword",                   "Work",  "Timmy", 2024,  1, 10, 13,  5);
  cal.addEvent("Dinner with Harold",              "Home",  "Timmy", 2024,  3, 30, 18, 30);
  cal.addEvent("Theatre with Harold",             "Home",  "Timmy", 2024,  3, 30, 16,  0);
  cal.addEvent("Grocery shopping",                "Home",  "Timmy", 2024,  1, 20,  9, 45);
  cal.addEvent("Meeting with Wizard",             "Work",  "Timmy", 2024,  3, 28,  6, 15);
  cal.addEvent("some bad thing",                  "Home",  "Timmy", 2023, 22, 18, 14,  0);

  cal.addParticipant(3012, "Harold");
  cal.addParticipant(3011, "Harold");
  cal.addParticipant(3004, "Harold");
  cal.addParticipant(3009, "Harold");
  cal.addParticipant(3004, "Dorc friends");
  cal.addParticipant(3003, "Harold");
  cal.addParticipant(3007, "Gwendolyn");
}

