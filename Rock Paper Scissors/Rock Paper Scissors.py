import random

you_score = 0         # to track the user's score
computer_score = 0    # to track the computer's score

# Function to get the user's choice
def get_user_choice():
    """
    Function to get user's choice (rock, paper, or scissors)
    """
    while True:
        # remove any leading or trailing whitespaces in the input and convert it to lowercase before storing it
        user_choice = input("Enter your choice (rock, paper, or scissors): ").strip().lower()
        
        if user_choice in ['rock', 'paper', 'scissors']:
            return user_choice

        else:
            print("Invalid choice! Please enter 'rock', 'paper', or 'scissors'.")


# Function to get the computer's choice
def get_computer_choice():
    """
    Function to randomly generate computer's choice
    """
    return random.choice(['rock', 'paper', 'scissors'])


# Function to determine the winner of each round
def determine_winner(user_choice, computer_choice):
    """
    Function to determine the winner of the game
    """
    global you_score, computer_score

    if user_choice == computer_choice:
        return "It's a tie!"

    elif (user_choice == 'rock' and computer_choice == 'scissors') or \
         (user_choice == 'paper' and computer_choice == 'rock') or \
         (user_choice == 'scissors' and computer_choice == 'paper'):
         
        you_score = you_score + 1
        return "Congratulations! You win this round!"

    else:
        computer_score = computer_score + 1
        return "Computer wins this round!"


# Function to determine the winner of the match
def overall_winner(you_score, computer_score):
    if you_score > computer_score:
        return("You won the overall match")

    elif you_score < computer_score:
        return("Computer won the overall match")

    else:
        return("The match is tied")


# Main block
if __name__ == '__main__':
    print("Let's play Rock, Paper, Scissors!")
    print("This game is the best of 3!")
    print("\n")

    n = int(input("How many rounds do you want to play? : "))
    print("")
    count = 1     # to keep a track of the rounds

    while n > 0:
        print(f"Round: {count}")
        user_choice = get_user_choice()
        computer_choice = get_computer_choice()
        print(f"You chose: {user_choice}")
        print(f"Computer chose: {computer_choice}")
        print(determine_winner(user_choice, computer_choice))
        print("")
        n = n - 1
        count = count + 1
        
    print(overall_winner(you_score, computer_score))
