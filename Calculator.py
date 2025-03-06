def calculatorDisplay():  
    display = """Welcome to Calculator  

    Choose one operation:  
    1. Add  
    2. Subtract  
    3. Multiply  
    4. Divide  
    5. Exit  
    """  
    return display  

def calculatorFunction(user_choice):  
    try:  
        if user_choice == 1:  
            print("Let's perform addition!")  
            a, b = user_input()  
            output = addition(a, b)  
            return f"The sum is: {output}"
          
        elif user_choice == 2:  
            print("Let's perform subtraction!")  
            a, b = user_input()  
            output = subtraction(a, b)  
            return f"The difference is: {output}"  
          
        elif user_choice == 3:  
            print("Let's perform multiplication!")  
            a, b = user_input()  
            output = multiplication(a, b)  
            return f"The product is: {output}"  
          
        elif user_choice == 4:  
            print("Let's perform division!")  
            a, b = user_input()  
            quotient, remainder = division(a, b)  
            return f"The quotient is: {quotient}, and the remainder is: {remainder}"
          
        elif user_choice == 5:  
            return "Exiting the calculator... Thank you!"  
          
        else:  
            raise ValueError  
          
    except ValueError:  
        return "Operation does not exist - please provide the correct input"  
      
    except ZeroDivisionError:  
        return "Cannot divide by zero."  

def user_input():  
    print("Give two numbers on two lines")  
  
    while True:  
        try:  
            a = int(input("Number 1 is: "))  
            b = int(input("Number 2 is: "))  
            return a, b 
          
        except ValueError:  
            print("Invalid input. Please enter integers only.")  

def addition(a, b):  
    sum = a + b  
    return sum

def subtraction(a, b):  
    difference = a - b
    return difference

def multiplication(a, b):  
    product = a * b  
    return product

def division(a, b):  
    if b == 0:  
        raise ZeroDivisionError 
      
    quotient = a // b  # Integer division to get the quotient  
    remainder = a % b   # Modulo operator to get the remainder  
    return quotient, remainder  

if __name__ == '__main__':  
    while True:  
        print(calculatorDisplay())
      
        while True:  
            try:  
                user_choice = int(input("Select the operation: "))  
                break  # Exit the inner loop if input is valid  
              
            except ValueError:  
                print("Invalid input. Please enter an integer.")  

        value = calculatorFunction(user_choice)  
        print(value)  

        if user_choice == 5:  
            break  
