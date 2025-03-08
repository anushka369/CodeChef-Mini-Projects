import time
import random


# Function to pick a word to guess
def choose_word():
    # List of words to choose from
    words = ['python', 'programming', 'treasure', 'creative', 'medium', 'horror']
  
    # Randomly select and return a word from the list
    return random.choice(words)


# Function to display the word
def wordDisplay(word, guesses):
    # Initialize an empty string to build the display word
    display_word = ''
  
    # Loop through each character in the chosen word
    for char in word:
      
        # If the character has been guessed, add it to the display
        if char in guesses:
            display_word += char + ' '
          
        else:
            # If not guessed, add an underscore to represent the letter
            display_word += '_ '
          
    # Return the display word, removing any trailing spaces
    return display_word.strip()


# Function to identify the winning status
def winningCondition(updated_word, turns):
    # Check if the user has won (no underscores left)
    if '_' not in updated_word:
        return 1  # User has won
      
    # Check if the user has lost (no turns left)
    elif turns == 0:
        return 0  # User has lost


if __name__ == '__main__':
    # Get the player's name
    name = input("What is your name? ")
    print("Hello, " + name + ", time to play hangman!")
  
    time.sleep(1)  # Pause for a moment
    print("Start guessing...\n")
    time.sleep(0.5)  # Pause for a moment

    # Choose a random word for the game
    word = choose_word()
  
    # Set the number of turns to the length of the word
    turns = len(word)   
  
    # Initialize an empty string to keep track of guessed letters
    guesses = ''

    # Main game loop
    while turns > 0:
        # Display the number of guesses remaining
        print("\nYou have", turns, 'guesses remaining')
      
        # Show the current state of the word
        print(wordDisplay(word, guesses))
      
        # Prompt the user to guess a character
        guess = input("\nguess a character: ").lower()

        # Check if the letter has already been guessed
        if guess in guesses:
            print("\nYou have already tried this letter")
            continue  # Skip to the next iteration of the loop
          
        else:
            # Add the new guess to the list of guesses
            guesses += guess

        # Check if the guessed letter is not in the word
        if guess not in word:
            print("\nWrong, Try again")

        # Update the display word based on current guesses
        updated_word = wordDisplay(word, guesses)
      
        # Decrease the number of turns remaining
        turns -= 1
      
        # Check for winning or losing conditions
        flag = winningCondition(updated_word, turns)

        # If the user has lost
        if flag == 0:
            print("\nYou Lose")
            print("The word was", word)
            break
          
        # If the user has won
        elif flag == 1:
            print("\nYou won!")
            print("You guessed", word, "correctly")
            break
          
    else:
        # This else corresponds to the while loop; it executes if the loop exits normally (not via break)
        print("\nYou Lose")
        print("The word was", word)
