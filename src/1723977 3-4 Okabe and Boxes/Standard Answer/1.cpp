#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main()
{
    int nb;
    cin >> nb;

    string cmd;
    int x;
    int curNum = 0;
    int nr = 0;
    stack<int> stk;

    for (int i = 0; i < 2 * nb; i++)
    {
        cin >> cmd;
        if (cmd[0] == 'a')
        {
            cin >> x;
            stk.push(x);
        }
        else
        {
            ++curNum;
            if (!stk.empty())
            {
                if (stk.top() == curNum)
                {
                    stk.pop();
                }
                else
                {
                    ++nr;
                    while (!stk.empty())
                    {
                        stk.pop();
                    }
                }
            }
        }
    }
    cout << nr << endl;
    return 0;
}
