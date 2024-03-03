#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void mergeSort(T begin, T end)
{
    if (end - begin > 1)
    {
        T mid = begin + (end - begin) / 2;

        mergeSort(begin, mid);
        mergeSort(mid, end);

        inplace_merge(begin, mid, end);
    }
}
