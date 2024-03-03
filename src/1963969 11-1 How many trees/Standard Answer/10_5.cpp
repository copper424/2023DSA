#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long N = 36;
long long dp[N][N];
void init()
{
	for (int i = 0; i<N; i++)
		dp[0][i] = 1;
	for (int i = 1; i<N; i++){
		for (int j = 1; j<N; j++){
			for (int k = 0; k<i; k++)
				dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1];
		}
	}
}
int main()
{
	int n, h;
	init();
	while (cin >> n >> h){
		cout << dp[n][35] - dp[n][h - 1] << endl;
	}
	return 0;
}