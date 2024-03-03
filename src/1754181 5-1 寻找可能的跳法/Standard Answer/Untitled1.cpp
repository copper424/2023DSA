#include<iostream> 
using namespace std;
#include<vector>
#include<string>





int jump(int n,int memo[]) {
        if (memo[n] != -1) {
            return memo[n];
        }
        if (n == 1 || n == 0) {
            return 1;
        }
        memo[n] = (jump(n - 1,memo) + jump(n - 2,memo)) % 1000000007;
        return memo[n];
    }
	
int numWays(int n) {
		//int memo;
        int memo[100000];
        for(int i=0;i<100000;i++){
        	memo[i]=-1;
		}
        return jump(n,memo);
    }


int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin >>n;

		
		cout<<numWays(n)<<'\n';
	}
}
    
    
    
