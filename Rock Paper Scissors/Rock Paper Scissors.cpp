#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int you_score = 0;
int computer_score = 0;

// Function to convert a string to lowercase
string toLower(string str) 
{
    for (char &c : str) 
    {
        c = tolower(c);
    }
  
    return str;
}

// Function to get the user's choice (rock, paper, or scissors)
string get_user_choice(string user_choice) 
{
    user_choice = toLower(user_choice);
  
    if (user_choice == "rock" || user_choice == "paper" || user_choice == "scissors") 
    {
        return user_choice;
    }
  
    return ("Invalid choice! Please enter 'rock', 'paper', or 'scissors'.\n");
}

// Function to get computer's choice (rock, paper, or scissors)
string random_choice(int rand_num) 
{
    if (rand_num == 0) 
    {
        return "rock";
    } 
    
    else if (rand_num == 1) 
    {
        return "paper";
    } 
    
    else 
    {
        return "scissors";
    }
}

// Function to generate the computer's choice (rock, paper, or scissors)
string get_computer_choice() 
{
    int rand_num = rand() % 3;
    return random_choice(rand_num);
}

// Function to determine the winner of the round and return the result as a string
string determine_winner(string user_choice, string computer_choice) 
{
    if (user_choice == computer_choice) 
    {
        return "It's a tie!";
    }
    
    else if ((user_choice == "rock" && computer_choice == "scissors") ||
               (user_choice == "paper" && computer_choice == "rock") ||
               (user_choice == "scissors" && computer_choice == "paper")) 
    {
        you_score++;
        return "Congratulations! You win this round!";
    } 
    
    else 
    {
        computer_score++;
        return "Computer wins this round!";
    }
}

// Function to compare the scores and return the overall result as a string
string compare_scores() 
{
    if (you_score < computer_score) 
    {
        return "Computer won the overall match";
    } 
    
    else if (you_score > computer_score) 
    {
        return "You won the overall match";
    } 
    
    else 
    {
        return "The match is tied";
    }
}

// Driver Code
int main() 
{
    srand(time(0));

    cout << "Let's play Rock, Paper, Scissors!" << endl;
    cout << "This game is the best of 3!\n" << endl;
    cout << "How many rounds do you want to play? ";
  
    int rounds;
    cin >> rounds;
    int n = 0;
  
    while (n < rounds) 
    {
        cout << "Round: " << n + 1 << endl;

        while (true) 
        {
            string input;
            cout << "Enter your choice (rock, paper, or scissors): ";
            cin >> input;

            string user_choice = get_user_choice(input);

            if (user_choice == "Invalid choice! Please enter 'rock', 'paper', or 'scissors'.\n") 
            {
                cout << user_choice;
            } 
            
            else 
            {
                string computer_choice = get_computer_choice();
                cout << "You chose: " << user_choice << endl;
                cout << "Computer chose: " << computer_choice << endl;

                // Get the winner result as a string
                string result = determine_winner(user_choice, computer_choice);
                cout << result << endl;

                n++;
                break;
            }
        }
    }

    // Compare scores and output the overall result
    string final_result = compare_scores();
    cout << final_result << endl;

    return 0;
}
