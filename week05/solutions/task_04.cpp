#pragma once
#include <iostream>
#include <cstring>

struct Event {
    char* description;

    Event() : description(nullptr) {} 

    Event(const char* desc) {
        setDescription(desc);
    }

    ~Event() {
        delete[] description;
    }

    void setDescription(const char* desc) {
        if (description){
            delete[] description;
	}
        if (desc && strlen(desc) > 0) {
            description = new char[strlen(desc) + 1];
            strcpy(description, desc);
        } else {
            description = nullptr;
        }
    }

    const char* getDescription() const {
        return description;
    }

    void print() const {
        std::cout << getDescription() << std::endl;
    }
};

struct EventLog {
    Event* events;
    int size;
    int capacity;

    EventLog() : events(nullptr), size(0), capacity(1) {}

    ~EventLog() {
        delete[] events;
    }

    void setSize(int newSize) {
	    size = newSize; 
    }
    int getSize() const { 
	    return size;
    }

    void setCapacity(int newCapacity) {
	    capacity = newCapacity; 
}
    int getCapacity() const {
	    return capacity;
    }

    void addEvent(const char* desc) {
        if (desc == nullptr || strlen(desc) == 0) {
            std::cout << "Invalid event description!" << std::endl;
            return;
        }

        if (size == capacity) {
            int newCapacity = capacity * 2;
            Event* newEvents = new Event[newCapacity];

            for (int i = 0; i < size; ++i) {
                newEvents[i] = events[i];
            }

            delete[] events;
            events = newEvents;
            capacity = newCapacity;
        }

        events[size++].setDescription(desc);
    }

    void print() const {
        if (size == 0) {
            std::cout << "No events recorded." << std::endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            std::cout << "Event " << (i + 1) << ": ";
            events[i].print();
        }
    }
Event getEventAt(size_t index)const {

	if (index < 0 || index >= size) {
		std::cout << "Invalid index!\n";
		return Event();
	}

	return events[index];
}
};

int main() {
    EventLog log;
    log.addEvent("Conference");
    log.addEvent(""); // Invalid event
    log.addEvent("Meeting with Team");
    log.addEvent("Project Deadline");

    log.print();

    return 0;
}
