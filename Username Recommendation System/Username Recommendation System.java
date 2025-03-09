import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

public class UsernameGenerator 
{
    // Global strings for generating username components
    private static final String STRING_CHAR = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String STRING_NUM = "0123456789";
    private static final String STRING_SPECIAL = "~!@#$%^&*()";
    
    // Scanner object for user input
    private static final Scanner scanner = new Scanner(System.in);
    private static final Random random = new Random();

    public static class UserPreferences 
    {
        String email;
        boolean useSpecialChars;
        boolean useNumbers;

        UserPreferences(String email, boolean useSpecialChars, boolean useNumbers) 
        {
            this.email = email;
            this.useSpecialChars = useSpecialChars;
            this.useNumbers = useNumbers;
        }
    }

    public static UserPreferences userInput() 
    {
        System.out.print("Enter your email ID: ");
        String email = scanner.nextLine();
        
        System.out.print("Include special characters in username? (yes/no): ");
        boolean useSpecialChars = scanner.nextLine().trim().toLowerCase().equals("yes");
        
        System.out.print("Include numbers in username? (yes/no): ");
        boolean useNumbers = scanner.nextLine().trim().toLowerCase().equals("yes");
        
        return new UserPreferences(email, useSpecialChars, useNumbers);
    }

    public static ArrayList<String> generateUsername(String email, boolean useSpecialChars, boolean useNumbers) 
    {
        // Extract the username part from the email
        String username = email.split("@")[0];
        
        // Create a list to hold the recommended usernames
        HashSet<String> usernameSet = new HashSet<>();
        
        // Add the base username
        usernameSet.add(username);

        // Generate variations with numbers
        if (useNumbers) 
        {
            for (int i = 1; i <= 3; i++) 
            {  // Generate 3 variations with numbers
                int randomNum = random.nextInt(99) + 1;  // Random number between 1 and 99
                usernameSet.add(username + randomNum);
            }
        }

        // Generate variations with special characters
        if (useSpecialChars) 
        {
            for (char special : STRING_SPECIAL.toCharArray()) 
            {
                usernameSet.add(username + special);
            }
        }

        // Convert set to list to return
        return new ArrayList<>(usernameSet);
    }

    public static void main(String[] args) 
    {
        UserPreferences prefs = userInput();
        ArrayList<String> recommendedUsernames = generateUsername(prefs.email, prefs.useSpecialChars, prefs.useNumbers);
        
        System.out.println("\nRecommended Usernames:");
        for (String username : recommendedUsernames) 
        {
            System.out.println(username);
        }
        
        scanner.close();
    }
}
