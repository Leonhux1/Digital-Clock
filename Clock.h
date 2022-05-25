// Name: Faizan Rafieuddin
// Clock Program

// Avoids redefinition
#ifndef H_Clock
#define H_Clock

// Including necessary header files for functionality
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Creating a class called clock.
class Clock {
    public:
         // Overloading the incrementing operator
         Clock& operator ++ ();
         
         // Overloading the relational operators
         bool operator < (const Clock &obj);
         bool operator <= (const Clock &obj);
         bool operator > (const Clock &obj);
         bool operator >= (const Clock &obj);
         bool operator == (const Clock &obj);
         bool operator != (const Clock &obj);
         
         // Constructors
         Clock();
         Clock(int newHour, int newMinute, int newSecond);
         Clock(int newHour, int newMinute);
         Clock(int newHour);
         
         // Copy Constructor
         Clock(const Clock &obj);
         
         // Modifiers
         void setHour(int newHour);
         void setMinute(int newMinute);
         void setSecond(int newSecond);
         
         // Accessors
         int getHour() const;
         int getMinute() const;
         int getSecond() const;
         
    private:
        // Private data members for a clock
        int hour;
        int minute;
        int second;
        
        // Friend functions can be put anywhere in the program
        friend ostream & operator << (ostream &out, const Clock &obj);     // Overloading stream insertion operator
        friend istream & operator >> (istream &in,  Clock &obj);       // Overloading the stream extraction operator
};
#endif