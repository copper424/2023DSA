#include <iostream>
using namespace std;

int jumpFloor(int number)
{
    if (number == 0 || number == 1)
    {
        return number;
    }
    int pre = 1, res = 1;
    while (number-- > 1)
    {
        int tmp = res;
        res += pre;
        pre = tmp;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        cout << jumpFloor(n) << endl;
    }
}
