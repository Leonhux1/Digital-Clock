// Name: Faizan Rafieuddin
// Clock Program

// Including the necessary header files for functionality
#include <iostream>
#include <iomanip>
#include <string>
#include "Clock.h"

using namespace std;

// The Modifiers for the member variables.
void Clock::setHour(int newHour) {
    if (0 <= newHour && newHour < 24) {
        hour = newHour;
    }
    else {
        hour = 0;
    }
}

void Clock::setMinute(int newMinute) {
    if (0 <= newMinute && newMinute < 60) {
        minute = newMinute;
    }
    else {
        minute = 0;
    }
}

void Clock::setSecond(int newSecond) {
    if (0 <= newSecond && newSecond < 60) {
        second = newSecond;
    }
    else {
        second = 0;
    }
}

// The Accessors for the member variables
int Clock::getHour() const {
    return hour;
}

int Clock::getMinute() const {
    return minute;
}

int Clock::getSecond() const {
    return second;
}

// Copy constructor
Clock::Clock(const Clock &obj) {
    setHour(obj.getHour());
    setMinute(obj.getMinute());
    setSecond(obj.getSecond());
}

// Default Constructor
Clock::Clock() {
    setHour(0);
    setMinute(0);
    setSecond(0);
}

// Custom Constructor when all three time components are given
Clock::Clock(int newHour, int newMinute, int newSecond) {
    if(0 <= newHour && newHour < 24) {
        setHour(newHour);
    }
    else {
        setHour(0);
    }
    if(0 <= newMinute && newMinute < 60) {
        setMinute(newMinute);
    }
    else {
        setMinute(0);
    }
    if(0 <= newSecond && newSecond < 60) {
        setSecond(newSecond);
    }
    else {
        setSecond(0);
    }
}

// Custom constructor when two time components are given
Clock::Clock(int newHour, int newMinute) {
    if(0 <= newHour && newHour < 24) {
        setHour(newHour);
    }
    else {
        setHour(0);
    }
    if(0 <= newMinute && newMinute < 60) {
        setMinute(newMinute);
    }
    else {
        setMinute(0);
    }
    setSecond(0);
}

// Custom constructor when one time component is given
Clock::Clock(int newHour) {
    if(0 <= newHour && newHour < 24) {
        setHour(newHour);
    }
    else {
        setHour(0);
    }
    setMinute(0);
    setSecond(0);
}

// This function overloads the less than operator by making appropriate comparisions
// and returns a bool value accordingly
bool Clock::operator < (const Clock &obj) {
    if(getHour() < obj.getHour()) {
        return true;
    }
    if(getHour() == 0) {
        if(getMinute() < obj.getMinute()) {
            return true;
        }
    }
    if(getMinute() == 0) {
        if(getSecond() < obj.getSecond()) {
            return true;
        }
    }
    return false;
}

// This function overloads the less than or equal to operator by making appropriate comparisions
// and returns a bool value accordingly
bool Clock::operator <= (const Clock &obj) {
    if(getHour() < obj.getHour()) {
        return true;
    }
    if(getHour() == 0) {
        if(getMinute() < obj.getMinute()) {
            return true;
        }
    }
    if(getMinute() == 0) {
        if(getSecond() < obj.getSecond()) {
            return true;
        }
    }
    
    if(getHour() == obj.getHour() && getMinute() == obj.getMinute() && getSecond() == obj.getSecond()) {
        return true;
    }
    
    return false;
}

// This function overloads the greater than operator by making appropriate comparisions
// and returns a bool value accordingly
bool Clock::operator > (const Clock &obj) {
    if(getHour() > obj.getHour()) {
        return true;
    }
    if(getHour() == 0) {
        if(getMinute() > obj.getMinute()) {
            return true;
        }
    }
    if(getMinute() == 0) {
        if(getSecond() > obj.getSecond()) {
            return true;
        }
    }
    return false;
}

// This function overloads the greater than or equal to operator by making appropriate comparisions
// and returns a bool value accordingly
bool Clock::operator >= (const Clock &obj) {
    if(getHour() > obj.getHour()) {
        return true;
    }
    if(getHour() == 0) {
        if(getMinute() > obj.getMinute()) {
            return true;
        }
    }
    if(getMinute() == 0) {
        if(getSecond() > obj.getSecond()) {
            return true;
        }
    }
    
    if(getHour() == obj.getHour() && getMinute() == obj.getMinute() && getSecond() == obj.getSecond()) {
        return true;
    }
    
    return false;
}

// This function overloads the equal to operator by making appropriate comparisions
// and returns a bool value accordingly
bool Clock::operator == (const Clock &obj) {
    if(getHour() == obj.getHour() && getMinute() == obj.getMinute() && getSecond() == obj.getSecond()) {
        return true;
    }
    return false;
}

// This function overloads the not equal to  operator by making appropriate comparisions
// and returns a bool value accordingly
bool Clock::operator != (const Clock &obj) {
    if(getHour() != obj.getHour() || getMinute() != obj.getMinute() || getSecond() != obj.getSecond()) {
        return true;
    }
    return false;
}

// Prints out the information inside the member variables         
// void Clock::print() const {
// }

// Overloading the stream insertion operator
ostream& operator << (ostream &out, const Clock &obj) {
    out << obj.hour << ":" << obj.minute << ":" << obj.second;
    return out;
}

// Overloading the stream extraction operator
istream& operator >> (istream &in, Clock &obj) {
    if(obj.second > 59) {
        obj.second = 0;
        obj.minute++;
        if(obj.minute > 59) {
            obj.minute = 0;
            obj.hour++;
            if(obj.hour > 23) {
                obj.hour = 0;
                obj.minute = 0;
                obj.second = 0;
            }
        }
    }
    // Taking care of all the values that make the time out of bounds.
    if(obj.hour > 23) {
        obj.hour = 0;
        obj.minute = 0;
        obj.second = 0;
    }
    if(obj.minute > 59) {
        obj.minute = 0;
        obj.hour++;
        if(obj.hour > 23) {
                obj.hour = 0;
                obj.minute = 0;
                obj.second = 0;
            }
    }
    in >> obj.hour >> obj.minute >> obj.second;

    return in;
}

// Overloading the increment operator
Clock& Clock::operator ++ () {
    second++;
    if(second > 59) {
        second = 0;
        minute++;
        if(minute > 59) {
            minute = 0;
            hour++;
            if(hour > 23) {
                hour = 0;
                minute = 0;
                second = 0;
            }
        }
    }
    // Taking care of all the values that make the time out of bounds.
    if(hour > 23) {
        hour = 0;
        minute = 0;
        second = 0;
    }
    if(minute > 59) {
        minute = 0;
        hour++;
        if(hour > 23) {
                hour = 0;
                minute = 0;
                second = 0;
            }
    }
    return *this;
}




