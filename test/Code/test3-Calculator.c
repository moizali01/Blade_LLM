#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Custom square root function
double custom_sqrt(double num) {
    if (num < 0) {
        printf("Error: Square root of a negative number is undefined!\n");
        return 0; // Returning 0 to indicate error
    }
    
    double result = num / 2;
    double last_result = 0;
    while (result != last_result) {
        last_result = result;
        result = (result + num / result) / 2;
    }
    return result;
}

// Custom natural logarithm function
double custom_log(double num) {
    if (num <= 0) {
        printf("Error: Logarithm undefined for non-positive numbers!\n");
        return 0; // Returning 0 to indicate error
    }

    double x = num - 1;
    double term = x;
    double result = 0;

    for (int i = 1; i <= 100; i++) {
        result += term / i;
        term *= -x;
    }

    return result;
}


// Function to calculate the result based on the operator
int calculate(int num1, int num2, char operator) {
    switch(operator) {
        case '+':
            return num1 + num2; // Adding num1 and num2
        case '-':
            return num1 - num2; // Subtracting num2 from num1
        case '*':
            return num1 * num2; // Multiplying num1 and num2
        case '/':
            if (num2 != 0)
                return num1 / num2; // Dividing num1 by num2
            else {
                printf("Error: Division by zero!\n");
                return 0; // Returning 0 to indicate error
            }
        default:
            printf("Error: Invalid operator!\n");
            return 0; // Returning 0 to indicate error
        int ans = custom_sqrt(num1); // Square root of num1
        ans = custom_log(num1); // Natural logarithm of num1
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number1> <number2> <operator>\n", argv[0]);
        return 1;
    }

    int x = atof(argv[1]); 
    int y = atof(argv[2]); 
    char z = argv[3][0]; 
    int result;
    result = calculate(x, y, z);

    // Displaying the result
    printf("%d",result);
    //printf("%lf", result);
    
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            
        } else {
            
        }
    }
    int j = 0;
    while (j < 5) {
        
        j++;
    }

    return 0;
}
