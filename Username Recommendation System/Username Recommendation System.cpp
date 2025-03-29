#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

// Function to convert a string to lowercase
void toLower(string &input)
{
    for (char &ch : input)
    {
        ch = tolower(ch);
    }
}

// Function to extract the local part (before '@') from the email
string extractLocalPart(const string &email)
{
    size_t pos = email.find('@');
  
    if (pos != string::npos)
    {
        return email.substr(0, pos);
    }
  
    return ""; // Return empty string if '@' not found
}

// Function to generate random numbers
int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Function to generate and recommend usernames
void generateUsernames(const string &email)
{
    string localPart = extractLocalPart(email);
    toLower(localPart);
    
    cout << "\nRecommended Usernames:" << endl;
    cout << "1. " << localPart << endl;
    cout << "2. " << localPart << getRandomNumber(100, 999) << endl;
    cout << "3. " << localPart << "_" << static_cast<char>('a' + getRandomNumber(0, 25))
         << static_cast<char>('a' + getRandomNumber(0, 25)) << endl;
    cout << "4. " << localPart << "_" << getRandomNumber(10, 99) << endl;
    cout << "5. " << localPart[0] << localPart.substr(1) << getRandomNumber(1000, 9999) << endl;
}

// Driver Code
int main()
{
    srand(time(0)); // Seed random number generator
    string email;
  
    cout << "Enter your email ID: ";
    cin >> email;  
  
    generateUsernames(email);    
    return 0;
}
