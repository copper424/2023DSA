#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void reOrderArray(vector<int> &array) {
    int len=array.size();
    if(len<=1)
        return;
    for(int i=0;i<len-1;++i)
        for(int j=0;j<len-1-i;++j)
        {
            if((array[j]%2==0)&&(array[j+1]%2==1))
            {
                int temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    for(auto item : array)
        cout << item << " ";
    cout<<endl;
}

int  main()
{
    int n=-1;
    cin>>n;
    getchar();
    vector<vector<int> > sv;
    for(int i=0; i<n; ++i)
    {
        string str;
        getline(cin,str);
        stringstream ss(str);
        int temp;
        vector<int> line;
        while(ss>>temp)
        {
            line.push_back(temp);
        }
        sv.push_back(line);
    }

    for(int i=0;i<sv.size();++i)
        reOrderArray(sv[i]);
    return 0;
}