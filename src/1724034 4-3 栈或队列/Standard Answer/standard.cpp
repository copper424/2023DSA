#include <iostream>
#include <vector>
using namespace std;
bool is_stack(const vector<int> & in, const vector<int> & out)
{
	int size = in.size();
	for (int i = 0; i < size; i++)
	{
		if (in[i] != out[size - i - 1]) return false;
	}
	return true;
}
bool is_queue(const vector<int> & in, const vector<int> & out)
{
	int size = in.size();
	for (int i = 0; i < size; i++)
	{
		if (in[i] != out[i]) return false;
	}
	return true;
}
int main()
{
	int N;
	cin >> N;
	vector<int> in(N, 0);
	vector<int> out(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> in[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> out[i];
	}
	if (is_stack(in, out) && is_queue(in, out)) cout << "both";
	else
		if (is_stack(in, out)) cout << "stack";
		else
			if (is_queue(in, out)) cout << "queue";
			else cout << "neither";
			return 0;
}