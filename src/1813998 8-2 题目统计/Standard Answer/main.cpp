#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int hashTable[301][11][2];
	int a, b, m, n, t;
	cin >> a >> b;
	memset(hashTable, 0, sizeof(hashTable));
	while (cin >> m)
	{
		cin >> n >> t;
		hashTable[m][n][t]++;
	}
	for (int i=1; i<=a; i++)
	{
		cout << hashTable[i][1][1] << " " << hashTable[i][1][0];
		for (int j=2; j<=b; j++)
		{
			cout << " " << hashTable[i][j][1] << " " << hashTable[i][j][0];
		}
		cout << endl;
	}

	return 0;
}