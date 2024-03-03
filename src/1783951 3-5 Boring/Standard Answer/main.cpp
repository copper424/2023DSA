#include <iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
    int operation;
    cin >> operation;
    queue<double>numbers;
    for (int i = 1;i <= operation;i++)
    {
        string n;
        double members;
        cin >> n;
        if (n == "Count")
        {
            cout << numbers.size() << endl;
        }
        if (n == "In")
        {
            cin >> members;
            numbers.push(members);
        }
        if (n == "Out")
        {
            if (numbers.empty())
                cout << -1 << endl;
            if (!numbers.empty())
            {
                cout << numbers.front() << endl;
                numbers.pop();
            }
        }
    }
    while (!numbers.empty())
        numbers.pop();
    return 0;
}