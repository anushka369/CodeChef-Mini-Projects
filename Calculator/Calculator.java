import java.util.*;

public class Codechef 
{
    // Function to display the calculator menu
    public static String calculatorDisplay() 
    {
        return "Welcome to Calculator\n\n" +
               "Choose one operation:\n" +
               "1. Add\n" +
               "2. Subtract\n" +
               "3. Multiply\n" +
               "4. Divide\n" +
               "5. Exit\n";
    }

    // Function to get user input and store in an array
    public static void userInput(Scanner scanner, int[] numbers) 
    {
        System.out.println("Give two numbers on two lines");

        System.out.print("Number 1 is: ");
        numbers[0] = scanner.nextInt();

        System.out.print("Number 2 is: ");
        numbers[1] = scanner.nextInt();
    }

    // Function to perform addition
    public static int addition(int a, int b) 
    {
        return (a + b);
    }

    // Function to perform subtraction
    public static int subtraction(int a, int b) 
    {
        return (a - b);
    }

    // Function to perform multiplication
    public static int multiplication(int a, int b) 
    {
        return (a * b);
    }

    // Function to perform division
    public static String division(int a, int b) 
    {
        if (b == 0) 
        {
            return "Error: Division by zero is not allowed";
        }
      
        return "Quotient: " + (a / b) + ", Remainder: " + (a % b);
    }

    // Function to handle the calculator operations
    public static String calculatorFunction(int userChoice, Scanner scanner) 
    {
        int[] numbers = new int[2];
        String result = "";

        // Switch case to handle user's choice
        switch (userChoice) 
        {
            case 1:
                userInput(scanner, numbers);
                result = "The sum is: " + addition(numbers[0], numbers[1]);
                break;
            
            case 2:
                userInput(scanner, numbers);
                result = "The difference is: " + subtraction(numbers[0], numbers[1]);
                break;
            
            case 3:
                userInput(scanner, numbers);
                result = "The product is: " + multiplication(numbers[0], numbers[1]);
                break;
            
            case 4:
                userInput(scanner, numbers);
                result = division(numbers[0], numbers[1]);
                break;
            
            case 5:
                return "Exiting the calculator, bye bye!";
            
            default:
                return "Operation does not exist - please provide the correct input";
        }
      
        return result;
    }

    // Driver code
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        // Repeat until user exits
        while (true) 
        {
            try 
            {
                // Display the calculator menu
                System.out.println(calculatorDisplay());

                // Choosing the operation
                System.out.print("Select the operation: ");
                int userChoice = scanner.nextInt();

                // Process the user choice and get result
                String result = calculatorFunction(userChoice, scanner);
                System.out.println(result);

                // Break out of the loop
                if (userChoice == 5) 
                {
                    break;
                }
            } 

            // Handle wrong input entered by the user
            catch (InputMismatchException e) 
            {
                System.out.println("Invalid input! Please enter a number between 1 and 5.");
                scanner.next(); 
            }
        }
      
        // Close scanner to prevent resource leak
        scanner.close();
    }
}
