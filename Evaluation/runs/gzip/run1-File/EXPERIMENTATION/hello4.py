class Greeter:
    def __init__(self):
        pass
    
    def greet(self):
        # Prompt the user to enter their name
        name = input("Enter your name: ")
        
        # Greet the user
        print("Hello, " + name + "! Nice to meet you!")

# Create an instance of the Greeter class
greeter = Greeter()

# Call the greet method to greet the user
greeter.greet()

