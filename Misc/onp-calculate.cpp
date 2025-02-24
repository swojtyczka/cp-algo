#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> S;

int main()
{
    string s = "a";
    while (s != "=")
    {
        cin >> s;
        if (string("+-*/").find_first_of(s) != string::npos)
        {
            int b = S.top();
            S.pop();
            int a = S.top();
            S.pop();

            switch (s[0])
            {
            case '+':
                S.push(a + b);
                break;

            case '-':
                S.push(a - b);
                break;

            case '*':
                S.push(a * b);
                break;

            case '/':
                S.push(a / b);
                break;
            }
        }
        else if (s != "=")
            S.push(stoi(s));
    }

    cout << S.top();

    return 0;
}