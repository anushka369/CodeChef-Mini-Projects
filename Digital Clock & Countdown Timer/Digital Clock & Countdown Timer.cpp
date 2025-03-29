#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

// Function declarations
void userChoice(int choice);
void digital_clock();
void countdown_timer(int seconds);

// Function to accept the user's choice
void userChoice(int choice)
{
    if (choice == 1) 
    {
        digital_clock();
    }
    
    else if (choice == 2) 
    {
        int seconds;
        cout << "Enter the number of seconds to countdown: ";
        cin >> seconds;
        countdown_timer(seconds);
    } 
    
    else
    {
        cout << "Invalid choice!" << endl;
    }
}

// Function for displaying a digital clock
void digital_clock() 
{
    while (true) 
    {
        // Get the current time
        time_t now = time(nullptr);
        tm* local_time = localtime(&now);

        // Print the current time
        cout << "\rCurrent Time: " << put_time(local_time, "%H:%M:%S") << flush;

        // Pause for 1 second
        this_thread::sleep_for(chrono::seconds(1));
    }
}

// Function to display a countdown timer
void countdown_timer(int seconds) 
{
    cout << "Countdown Timer started!" << endl;
  
    while (seconds > 0) 
    {
        cout << "\rTime remaining: " << seconds << " seconds" << flush;
        this_thread::sleep_for(chrono::seconds(1));
        seconds--;
    }
  
    cout << "\nTime's up!" << endl;
}

// Driver code
int main() 
{
    while (true) 
    {
        int choice;
        cout << "Choose an option (1: Digital Clock, 2: Countdown Timer): ";
        cin >> choice;
        userChoice(choice);
    }

    return 0;
}
