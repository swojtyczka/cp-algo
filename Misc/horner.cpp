#include <iostream>
using namespace std;

const int MAX_SIZE = 1000000 + 7;
int coeffs[MAX_SIZE], horner[MAX_SIZE];


int main()
{
    int a, n;
    cin >> a >> n;

    for (int i = n; i >= 0; i--)
        cin >> coeffs[i];

    horner[n] = coeffs[n];

    for (int i = n - 1; i >= 0; i--)
        horner[i] = horner[i + 1] * a + coeffs[i];
    
    cout << "    ";

    for(int i = n; i >=0;i--)
        cout << coeffs[i] << "  ";

    cout << "\n" << a << "  ";
    for(int i = n; i >=0;i--)
        cout << horner[i] << "  ";

    cout << '\n';

    return 0;
}