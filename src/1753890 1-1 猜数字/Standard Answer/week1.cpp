#include <iostream>
using namespace std;
int main()
{
    int a[3];
    int b[3];
    int n;

    cin >> n;

    while (n--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < 3; i++)
        {
            cin >> b[i];
        }

        int total = 0;
        for (int i = 0; i < 3; i++)
        {
            if (a[i] == b[i])
            {
                ++total;
            }
        }
        cout << total << endl;
    }
}
