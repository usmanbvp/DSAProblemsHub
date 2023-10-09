#include <iostream>
#include <stack>
#include <string>
using namespace std;
void valid_paren(string input)
{

    stack<char> s;
    int length = input.length();
    char top;

    for (int i = 0; i < length; i++)
    {

        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            s.push(input[i]);
        }
        else
        {
            if (s.empty())
            {
                cout << input << " contains invalid parentheses." << endl;
                return;
            }
            else
            {
                top = s.top();

                if (input[i] == ')' && top == '(' ||
                    input[i] == '}' && top == '{' ||
                    input[i] == ']' && top == '[')
                {
                    s.pop();
                }
                else
                {

                    cout << input << " contains invalid parentheses." << endl;
                    return;
                }
            }
        }
    }

    if (s.empty())
    {
        cout << input << " contains valid parentheses." << endl;
    }
    else
    {
        cout << input << " contains invalid parentheses." << endl;
    }
}
int main()
{
    string input;
    cin >> input;
    valid_paren(input);
    return 0;
}