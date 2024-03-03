#include <iostream>
using namespace std;

int findNthDigit(int n)
{
    long base = 9, digits = 1;
    while (n - base * digits > 0)
    {
        n -= base * digits;
        base *= 10;
        ++digits;
    }

    int idx = n % digits;
    if (idx == 0)
        idx = digits;
    long number = 1;
    for (int i = 1; i < digits; ++i)
        number *= 10;
    number += (idx == digits) ? n / digits - 1 : n / digits;

    for (auto i = idx; i < digits; ++i)
        number /= 10;

    return number % 10;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << findNthDigit(n) << endl;
    }
}
