# 6-4 插入排序

# 题目描述

实现函数

```cpp
template<typename T>
void insertionSort(T begin, T end) {
```

以插入排序算法，按升序排序`[begin, end)`范围的元素。

`T`为随机访问迭代器，只能使用`operator <`比较元素大小，不需要`include`头文件。