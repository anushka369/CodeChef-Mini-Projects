#include <stdio.h>
#include <time.h>
#include <unistd.h>  // For sleep function
#include <pthread.h> // For multi-threading
#include <termios.h> // For non-blocking input

// Function declarations
void userChoice(int choice);
void digital_clock();
void countdown_timer(int seconds);
char getKeyPress();

// Function to get a keypress without waiting for Enter
char getKeyPress() 
{
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);  // Get current terminal attributes
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode & echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal settings
    return ch;
}

// User choice function
void userChoice(int choice) 
{
    if (choice == 1) 
    {
        digital_clock();
    } 
    
    else if (choice == 2) 
    {
        int seconds;
        printf("Enter the number of seconds to countdown (or press 'q' to stop): ");
        scanf("%d", &seconds);
        countdown_timer(seconds);
    }
    
    else 
    {
        printf("Invalid choice!\n");
    }
}

// Digital Clock function
void digital_clock() 
{
    printf("Press 'q' to exit the Digital Clock\n");
    
    while (1) 
    {
        time_t now = time(NULL);
        struct tm* local_time = localtime(&now);

        // Print the current time
        printf("\rCurrent Time: %02d:%02d:%02d | Press 'q' to stop ",
               local_time->tm_hour,
               local_time->tm_min,
               local_time->tm_sec);
        fflush(stdout);

        // Check for user input
        usleep(500000);  // Sleep for 0.5 seconds (to check input more frequently)
        if (getchar() == 'q')
        {
            printf("\nExiting Digital Clock...\n");
            break;
        }
    }
}

// Countdown Timer function
void countdown_timer(int seconds) 
{
    printf("Countdown Timer started! Press 'q' to stop.\n");

    while (seconds > 0) 
    {
        printf("\rTime remaining: %d seconds | Press 'q' to stop ", seconds);
        fflush(stdout);
        sleep(1);
        seconds--;

        // Check for user input
        if (getchar() == 'q') 
        {
            printf("\nCountdown Timer Stopped!\n");
            return;
        }
    }

    printf("\nTime's up!\n");
}

// Main function
int main() 
{
    while (1) 
    {
        int choice;
        printf("\nChoose an option (1: Digital Clock, 2: Countdown Timer, 3: Exit): ");
        scanf("%d", &choice);

        if (choice == 3) 
        {
            printf("Exiting Program...\n");
            break;
        }
      
        userChoice(choice);
    }

    return 0;
}
