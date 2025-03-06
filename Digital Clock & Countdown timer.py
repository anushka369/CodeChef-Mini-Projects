import time
import sys
import select

def userChoice(choice):
    if choice == "1":
        digital_clock()
        
    elif choice == "2":
        seconds = int(input("Enter the number of seconds to countdown: "))
        countdown_timer(seconds)
        
    else:
        print("Invalid choice!")

def digital_clock():
    print("\n+-----------------------+")
    print("|  Current Time:        |")
    
    while True:
        current_time = time.localtime()
        time_string = time.strftime("%Y-%m-%d %H:%M:%S", current_time)
        
        # Clear the line for the time and print the updated time
        print(f"\r|  {time_string}  |", end="")        
        time.sleep(1)
        
        # Check for user input to quit
        if sys.stdin in select.select([sys.stdin], [], [], 0)[0]:
            user_input = sys.stdin.read(1).strip().lower()
            if user_input == 'q':
                break

    print("\n+-----------------------+")

def countdown_timer(seconds):
    while seconds > 0:
        print(f"\rTime remaining: {seconds} seconds", end="", flush = True)
        time.sleep(1)
        seconds -= 1
    print("Time's up!")

if __name__ == '__main__':
    while True:
        try:
            choice = input("Choose an option (1: Digital Clock, 2: Countdown Timer, q: Quit): ")
            if choice.lower() == 'q':
                break
            userChoice(choice)

        except EOFError:
            break
