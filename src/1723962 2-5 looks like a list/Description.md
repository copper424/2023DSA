# 2-5 looks like a list

# 题目描述

实现一个长得像`std::list`，包含其部分功能与迭代器的类，详见`a_list.h`

实现头文件中`struct a_list`未实现的各函数

`a_list`为循环双链表

`a_list`总是持有一个哨兵节点，此节点等价于`end()`所指代的节点，不存储数据

`a_list`哨兵节点的`next`为链表第一个元素，`prev`为最后一个元素

**提示**

- 请记得将头文件包含进去，即`#include"a_list.h"`
- 一些函数的实现已作为示例给出
- 对于移动构造/移动赋值/参数为右值引用的函数，务必正确使用`std::move`，可以参考示例，会检测实现是否正确
- 合理地用`new`与`delete`创建与销毁对象，不要有内存泄漏
- 忽略常迭代器与常引用类型

**示例**

```cpp
template <typename T>
typename a_list<T>::reference a_list<T>::front()
{
    return node->next->data;
}

template <typename T>
typename a_list<T>::reference a_list<T>::back()
{
    return node->prev->data;
}

template <typename T>
typename a_list<T>::iterator a_list<T>::insert(typename a_list<T>::iterator pos, T &&value)
{
    auto temp = new list_node<T>(std::move(value));

    temp->prev = pos.link->prev;
    pos.link->prev = temp;

    temp->prev->next = temp;
    temp->next = pos.link;

    ++size_count;

    return temp;
}

template <typename T>
void a_list<T>::push_back(T &&value)
{
    insert(end(), std::move(value));
}

template <typename T>
void a_list<T>::push_front(T &&value)
{
    insert(begin(), std::move(value));
}

template <typename T>
a_list<T> &a_list<T>::operator=(a_list<T> &&rhs)
{
    clear();

    std::swap(size_count, rhs.size_count);
    std::swap(node, rhs.node);

    return *this;
}
```

![file](/api/users/image?path=5970/images/1630395799348.jpg)