#include<algorithm>
template <typename T>
void insertionSort(T begin, T end)
{
    std::stable_sort(begin,end);
    // for (auto iter = begin + 1; iter < end; iter++) {
    //     auto iter3 = iter;
    //     auto iter2 = iter - 1;
    //     for (; iter3 >= begin + 1; iter2--, iter3--) {
    //         if (iter3[0] < iter2[0]) {
    //             auto temp = iter3[0];
    //             iter3[0] = iter2[0];
    //             iter2[0] = temp;
    //         }
    //     }
    // }
}