#include <string>
#include <stack>

using namespace std;

bool isLeft(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isRight(char c)
{
    return c == ')' || c == ']' || c == '}';
}

bool match(char a, char b)
{
    return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
}
bool match(const string & line)
{
    stack<char> s;
    for (int i = 0; i < line.size(); i++)
    {
        if (isLeft(line[i]))
            s.push(line[i]);
        else if (isRight(line[i]))
            if (s.empty() || !match(s.top(), line[i]))
                return false;
            else
                s.pop();
    }
    if (s.empty())
        return true;
    else
        return false;
}
