#include <stack>
#include <string>

inline int pre(int i, char preSign)
{
    if (preSign == '-')
        return -i;
    return i;
}

int calculate(const std::string &s)
{
    std::stack<int> stk;
    char preSign = '+';
    char operate = '+';
    bool isPreSign = true;

    int num = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + int(s[i] - '0');
            isPreSign = false;
        }

        if (i == s.size() - 1 || !isdigit(s[i]) && s[i] != ' ')
        {
            if (isPreSign)
            {
                if (s[i] == '-')
                    preSign = (preSign == '+' ? '-' : '+');
            }
            else
            {
                switch (operate)
                {
                case '+':
                    stk.push(pre(num, preSign));
                    break;
                case '-':
                    stk.push(-pre(num, preSign));
                    break;
                case '*':
                    stk.top() *= pre(num, preSign);
                    break;
                case '/':
                    stk.top() /= pre(num, preSign);
                    break;
                case '%':
                    stk.top() %= pre(num, preSign);
                    break;
                }

                operate = s[i];
                num = 0;
                isPreSign = true;
                preSign = '+';
            }
        }
    }

    int res = 0;

    while (!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }
    return res;
}
