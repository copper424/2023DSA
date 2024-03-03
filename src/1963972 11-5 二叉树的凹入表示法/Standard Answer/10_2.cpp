#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100001;
char a[maxn],b[maxn],c[maxn];
int dfs(int l1,int r1,int l2,int r2)
{
    if(l1==r1)
    {
        c[l1]=1;
        return c[l1];
    }
    int i;
    for(i=l2;i<=r2;i++)//找出根在中序序列中的位置
        if(a[l1]==b[i])
            break;
    if(l2<i)//如果有左子树，递归寻找孩子，累加，右子树同理
        c[l1]+=dfs(l1+1,(i-1-l2)+(l1+1),l2,i-1);
    if(i<r2)
        c[l1]+=dfs(r1-(r2-(i+1)),r1,i+1,r2);
    return c[l1];//返回每个节点的孩子个数
}
int main()
{
    cin>>a>>b;
    int lena=strlen(a);
    int lenb=strlen(b);
    dfs(0,lena-1,0,lenb-1);
    for(int i=0;i<lena;i++)
    {
        for(int j=1;j<=c[i];j++)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}
