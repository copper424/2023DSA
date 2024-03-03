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

int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.empty())
        return 0;
    int len=numbers.size();
    int item;
    int time=0;
    for(int i =0; i<len; ++i)
    {
        if(time==0)
        {
            item=numbers[i];
            time++;
        }
        else
        {
            if(numbers[i]!=item)
                time--;
            else
                time++;
        }
    }

    //item
    int count=0;
    for(int i=0;i<len;++i)
    {
        if(numbers[i]==item)
            count++;
    }
    if(count<=len/2)
        item=0;
    return item;
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
        cout<<MoreThanHalfNum_Solution(sv[i])<<endl;
    return 0;
}