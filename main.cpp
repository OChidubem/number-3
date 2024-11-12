#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cctype>  // For isdigit() function
#include <stdexcept>  // For runtime_error
#include <fstream>  // For file input/output

using namespace std;

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> opStack; // Stack to hold operators
    string postfix = "";  // Output string for postfix expression

    for (char ch : infix) {
        // If it's a number or letter, add it to the output
        if (isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        }
        // If it's '(', push it onto the stack
        else if (ch == '(') {
            opStack.push(ch);
        }
        // If it's ')', pop from the stack until '(' is encountered
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty()) {
                opStack.pop(); // Discard '('
            }
        }
        // If it's an operator, pop from stack to output based on precedence
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix, const int values[6]) {
    stack<int> stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0');  // Push the number (converted from char)
        } else if (isalpha(ch)) {
            // Handle variables like 'a', 'b', etc.
            int index = ch - 'a';  // Convert char to array index (a -> 0, b -> 1, etc.)
            stack.push(values[index]);
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            switch (ch) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': 
                    if (b == 0) {
                        throw runtime_error("Division by zero error");
                    }
                    stack.push(a / b); break;
                default: throw runtime_error("Unsupported operator");
            }
        }
    }
    
    // Ensure the stack has exactly one element (the result)
    if (stack.size() != 1) {
        throw runtime_error("Error in postfix expression evaluation");
    }

    return stack.top();
}

int main() {
    int values[6] = {0};  // Array to store a - f values

    // Read values from the file (values.txt)
    string filename = "values.txt";
    ifstream inFile(filename);  // File handling (ifstream)
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;  // Exit if there's an error reading the file
    }

    string line;
    int index = 0;
    while (getline(inFile, line) && index < 6) {
        stringstream ss(line);
        ss >> values[index++];
    }

    // Expressions (a-h)
    string expressions[8] = {
        "a - b + c", 
        "a - (b / c * d)", 
        "a / (b * c)", 
        "a / b / c - (d + e) * f", 
        "(a + b) * c", 
        "a * (b / c / d) + e", 
        "a - (b + c)", 
        "a - (b + c * d) / e"
    };

    // Replace variables with values from array and display conversion to postfix
    for (const string& infix : expressions) {
        cout << "Infix expression: " << infix << endl;

        // Replace variables with corresponding values from the array
        string infixWithValues = infix;
        for (int i = 0; i < infixWithValues.length(); i++) {
            if (infixWithValues[i] == 'a' || infixWithValues[i] == 'b' || infixWithValues[i] == 'c' || infixWithValues[i] == 'd' || infixWithValues[i] == 'e' || infixWithValues[i] == 'f') {
                infixWithValues[i] = '0' + values[infixWithValues[i] - 'a'];  // Convert char to corresponding value
            }
        }

        // Debugging: Show modified infix expression
        cout << "Modified Infix expression: " << infixWithValues << endl;

        // Convert infix to postfix and show the result
        string postfix = infixToPostfix(infixWithValues);
        cout << "Postfix expression: " << postfix << endl;

        // Evaluate the postfix expression
        try {
            int result = evaluatePostfix(postfix, values);
            cout << "The result of the expression is: " << result << endl;
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "----------------------------------------" << endl;
    }

    return 0;
}
