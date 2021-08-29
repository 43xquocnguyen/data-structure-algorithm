#include <iostream>
#include <ctype.h> //for isdigit function
using namespace std;

int stack[100];
int top = -1;
int value = 0; //Global Declarations
int pop()
{
    return (stack[top--]);
}
void push(int x)
{
    if (value == 1)
    {
        int y;
        y = pop();
        stack[++top] = x + 10 * y; //for more than one digit
    }
    else if (value == 0)
    {
        stack[++top] = x;
        value = 1;
    }
}
main()
{
    char c, postfix[100];
    int i = 0, y, x;
    cin.getline(postfix, 100);
    while ((c = postfix[i++]) != '\0')
    {
        if (isdigit(c))
            push(c - '0'); //for converting datatype
        else if (c == ' ')
        {
            value = 0;
        }
        else
        {
            x = pop(); //top element
            y = pop(); //next top element
            switch (c)
            {
            case '+':
                push(x + y);
                break;
            case '-':
                push(y - x);
                break;
            case '*':
                push(y * x);
                break;
            case '/':
                push(y / x);
                break;
            default:
                cout << "\nInvalid Operator";
            }
        }
    }
    cout << stack[top];
}