#include <iostream>

using namespace std;

int nums[10], n;

void swapNum(const int pos1, const int pos2);
void permute(const int startPos);

int main()
{
	for (int i=1; i<10; i++)
		nums[i] = i;
	int m;
	cin >> m;
	while (m--)
	{
		cin >> n;
		permute(1);
	}

	return 0;
}

void swapNum( const int pos1, const int pos2 )
{
	int temp = nums[pos2];
	if (pos1 < pos2)
	{
		for (int i=pos2; i>pos1; i--)
			nums[i] = nums[i-1];
	} else {
		for (int i=pos2; i<pos1; i++)
			nums[i] = nums[i+1];
	}
	nums[pos1] = temp;
}

void permute( const int startPos )
{
	if (startPos == n)
	{
		for (int i=1; i<=n; i++)
			cout << nums[i];
		cout << endl;
	}
	for (int i=startPos; i<=n; i++)
	{
		swapNum(startPos, i);
		permute(startPos+1);
		swapNum(i, startPos);
	}
}
