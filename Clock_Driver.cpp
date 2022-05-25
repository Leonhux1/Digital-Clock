// Name: Faizan Rafieuddin
// Clock Program

// Including the necessary header files for functionality
#include <iostream>
#include "Clock.h"
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// Function prototype to clear the screen
void clearScreen();

int main()
{
    // Creating two Clock objects   
    Clock currClock, alarmClock;
    
    // Asking the user for the current and target time and storing the times accordingly
    cout << "Please enter the time right now in the sequence Hours, Minutes, Seconds: " << endl;
    cin >> currClock;
    cout << endl;
    cout << "Please enter the time for which you want to set the alarm: " << endl;
    cin >> alarmClock;
    
    cout << endl;   // Leaving a blank line
    
    // Looping through the current time and incrementing it until it reaches the target time
    while(currClock != alarmClock) {
        
        ++currClock;    // Incrementing the current time
        
        cout << currClock << endl;  // Printing out the incremented time
        
        sleep(1);   // Delaying the output by 1 second
        
        clearScreen();  // Calling the clearScreen() function to clear the screen to give clock like effect
    }
  
    // Returning 0 to the OS to indicate that the program has terminated
    return 0;
}

// This function clears the screen
void clearScreen()
{
  system("clear");
}
