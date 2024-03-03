#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool bigger(string x, string y)
{
    if((x+y)>(y+x))
        return true;
    else
        return false;

}

void PrintMinNumber(vector<string> numbers_str) {
    if(numbers_str.empty())
        cout<<""<<endl;
    int len=numbers_str.size();
    for(int i=0;i<len-1;++i)
        for(int j=0;j<len-i-1;++j)
        {
            if(bigger(numbers_str[j],numbers_str[j+1]))
            {
                string temp=numbers_str[j];
                numbers_str[j]=numbers_str[j+1];
                numbers_str[j+1]=temp;
            }
        }
    string result="";
    for(int i=0;i<len;++i)
        result += numbers_str[i];

    cout<<result<<endl;
}

int main()
{
    int n=-1;
    cin>>n;
    getchar();
    vector<vector<string> > sv;
    for(int i=0; i<n; ++i)
    {
        string str;
        getline(cin,str);
        stringstream ss(str);
        string temp;
        vector<string> line;
        while(ss>>temp)
        {
            line.push_back(temp);
        }
        sv.push_back(line);
    }
    for(int i=0;i<sv.size();++i)
    {
        PrintMinNumber(sv[i]);
    }
    return 0;
}