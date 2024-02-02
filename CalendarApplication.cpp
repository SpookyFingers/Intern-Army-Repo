#include <iostream>
#include <string>
#include <map>

using namespace std;

// Structure to represent an event
struct Event {
    string description;
    string time;
};

// Calendar class to manage events
class Calendar {
private:
    map<string, Event> events;

public:
    void addEvent(string date, string description, string time) {
        Event event;
        event.description = description;
        event.time = time;
        events[date] = event;
        cout << "Event added successfully." << endl;
    }

    void editEvent(string date, string description, string time) {
        if (events.find(date) != events.end()) {
            events[date].description = description;
            events[date].time = time;
            cout << "Event edited successfully." << endl;
        } else {
            cout << "Event not found." << endl;
        }
    }

    void deleteEvent(string date) {
        if (events.find(date) != events.end()) {
            events.erase(date);
            cout << "Event deleted successfully." << endl;
        } else {
            cout << "Event not found." << endl;
        }
    }

    void displayEvents() {
        cout << "----- Events -----" << endl;
        for (auto const& event : events) {
            cout << "Date: " << event.first << endl;
            cout << "Description: " << event.second.description << endl;
            cout << "Time: " << event.second.time << endl;
            cout << "-------------------" << endl;
        }
    }
};

int main() {
    Calendar calendar;
    int choice;
    string date, description, time;

    while (true) {
        cout << "\n1. Add Event\n2. Edit Event\n3. Delete Event\n4. Display Events\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter date (DD/MM/YYYY): ";
                cin >> date;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Enter time: ";
                cin >> time;
                calendar.addEvent(date, description, time);
                break;
            case 2:
                cout << "Enter date (DD/MM/YYYY) to edit: ";
                cin >> date;
                cout << "Enter new description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Enter new time: ";
                cin >> time;
                calendar.editEvent(date, description, time);
                break;
            case 3:
                cout << "Enter date (DD/MM/YYYY) to delete: ";
                cin >> date;
                calendar.deleteEvent(date);
                break;
            case 4:
                calendar.displayEvents();
                break;
            case 5:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
