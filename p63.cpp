#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char operation)
{
    if(operation == '^')
    {
        return 3;
    }
    else if(operation == '*' || operation == '/')
    {
        return 2;
    }
    else if(operation == '+' || operation == '-')
    {
        return 1;
    }

    return 0;
}

string infixToPostfix(string expression)
{
    stack<char> operators;
    string postfix = "";

    for(int i = 0; i < expression.length(); i++)
    {
        char current = expression[i];

        if(current == ' ')
        {
            continue;
        }

        if((current >= 'a' && current <= 'z') ||
           (current >= 'A' && current <= 'Z') ||
           (current >= '0' && current <= '9'))
        {
            postfix += current;
        }
        else if(current == '(')
        {
            operators.push(current);
        }
        else if(current == ')')
        {
            while(!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }

            if(!operators.empty())
            {
                operators.pop();
            }
        }
        else
        {
            while(!operators.empty() &&
                  operators.top() != '(' &&
                  priority(operators.top()) >= priority(current))
            {
                postfix += operators.top();
                operators.pop();
            }

            operators.push(current);
        }
    }

    while(!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main()
{
    string expression;

    cout << "Enter infix expression: ";
    getline(cin, expression);

    cout << "Postfix expression: " << infixToPostfix(expression) << endl;

    return 0;
}