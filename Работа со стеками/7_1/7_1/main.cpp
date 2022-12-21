#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <sstream>
#include <stack>
using namespace std;

bool isOperator(char currentChar)
{
    switch (currentChar) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '%':
        return true;
    default:
        return false;
    }
}

// returns whether a `lOp` b `rOp` c == (a `lOp` b) `rOp` c
bool precedence(char leftOperator, char rightOperator)
{
    if ( leftOperator == '^' ) {
        return true;
    } else if ( rightOperator == '^' ) {
        return false;
    } else if ( leftOperator == '*' || leftOperator == '/' || leftOperator == '%' ) {
        return true;
    } else if ( rightOperator == '*' || rightOperator == '/' || rightOperator == '%' ) {
        return false;
    }

    return true;
}

string convertToPostfix(const string& infix)
{
    stringstream postfix; // Our return string
    stack<char> stack;
    stack.push('('); // Push a left parenthesis ‘(‘ onto the stack.

    for(size_t i = 0, l = infix.size(); i < l; ++i) {
        const char current = infix[i];

        if (isspace(current)) {
            // ignore
        }
        // If it's a digit or '.' or a letter ("variables"), add it to the output
        else if(isalnum(current) || '.' == current) {
            postfix << current;
        }

        else if('(' == current) {
            stack.push(current);
        }

        else if(isOperator(current)) {
            char rightOperator = current;
            while(!stack.empty() && isOperator(stack.top()) && precedence(stack.top(), rightOperator)) {
                postfix << stack.top();
                stack.pop();
            }
            stack.push(rightOperator);
        }

        // We've hit a right parens
        else if(')' == current) {
            // While top of stack is not a left parens
            while(!stack.empty() && '(' != stack.top()) {
                postfix << stack.top();
                stack.pop();
            }
            if (stack.empty()) {
                throw runtime_error("missing left paren");
            }
            // Discard the left paren
            stack.pop();
        } else {
            throw runtime_error("invalid input character");
        }
    }


    // Started with a left paren, now close it:
    // While top of stack is not a left paren
    while(!stack.empty() && '(' != stack.top()) {
        postfix << stack.top();
        stack.pop();
    }
    if (stack.empty()) {
        throw runtime_error("missing left paren");
    }
    // Discard the left paren
    stack.pop();

    // all open parens should be closed now -> empty stack
    if (!stack.empty()) {
        throw runtime_error("missing right paren");
    }

    return postfix.str();
}

int main()
{
    for (;;) {
        if (!cout.good()) break;
        cout << "Enter the Arithmetic Expression: ";
        string infix;
        getline(cin, infix);
        if (infix.empty()) break;

        cout << "Postfix: '" << convertToPostfix(infix) << "'\n";
    }

    return 0;
}
