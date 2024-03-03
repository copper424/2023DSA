template<typename T>
void insertionSort(T begin, T end) {
    for (auto i = begin + 1; i != end; ++i) {
        auto key = *i;
        auto j = i - 1;
        while(j >= begin && key < *j) {
            std::swap(*j, *(j + 1));
            --j;
        }

        *(j+1) = key;
    }
}
