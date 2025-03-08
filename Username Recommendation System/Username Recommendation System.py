import random
import string

# Global strings to be used for generating username components
string_char = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
string_num = '0123456789'
string_special = '~!@#$%^&*()'

def userInput():
    email = input("Enter your email ID: ")
    use_special_chars = input("Include special characters in username? (yes/no): ").lower() == 'yes'
    use_numbers = input("Include numbers in username? (yes/no): ").lower() == 'yes'
    return email, use_special_chars, use_numbers

def generate_username(email, use_special_chars, use_numbers):
    """Generates a username based on the email ID and user preferences."""
    # Extract the username part from the email
    username = email.split('@')[0]
    
    # Create a list to hold the recommended usernames
    recommended_usernames = []

    # Add the base username
    recommended_usernames.append(username)

    # Generate variations
    if use_numbers:
        for i in range(1, 4):  # Generate 3 variations with numbers
            recommended_usernames.append(f"{username}{random.randint(1, 99)}")

    if use_special_chars:
        for special in string_special:
            recommended_usernames.append(f"{username}{special}")

    # Ensure uniqueness by converting to a set and back to a list
    recommended_usernames = list(set(recommended_usernames))
    return recommended_usernames

if __name__ == '__main__':
    email, use_special_chars, use_numbers = userInput()
    recommended_usernames = generate_username(email, use_special_chars, use_numbers)
    print("\nRecommended Usernames:")
    for username in recommended_usernames:
        print(username)
