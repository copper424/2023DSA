# 4-5 归并排序

# 问题描述

实现函数

```cpp
template <typename T>
void mergeSort(T begin, T end);
```

以实现升序（`operator<`）归并排序随机迭代器范围`[begin, end)`内的元素

**提示**：`typename T::value_type`指代迭代器指向的类型

## 注意事项：

- 只需实现相关函数即可，不用提交main函数。