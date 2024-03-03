#include "a_list.h"

// front 返回到容器首元素的引用。
// 在空容器上对 front 的调用是未定义的。
template <typename T>
typename a_list<T>::reference a_list<T>::front()
{
    return node->next->data;
}
// back 返回到容器中最后一个元素的引用。
// 在空容器上对 back 的调用是未定义的。
template <typename T>
typename a_list<T>::reference a_list<T>::back()
{
    return node->prev->data;
}
// empty 检测容器是否无元素
template <typename T>
bool a_list<T>::empty() const noexcept
{
    return size_count == 0;
}
// size 返回容器中的元素数
template <typename T>
typename a_list<T>::size_type a_list<T>::size() const noexcept
{
    return size_count;
}
// begin 返回指向 list 首元素的迭代器
template <typename T>
typename a_list<T>::iterator a_list<T>::begin() noexcept
{
    return iterator(this->node->next);
}
template <typename T>
typename a_list<T>::iterator a_list<T>::begin() const noexcept
{
    return iterator(this->node->next);
}
// end 返回指向 list 末元素后一元素的迭代器
template <typename T>
typename a_list<T>::iterator a_list<T>::end() noexcept
{
    return iterator(this->node);
}
template <typename T>
typename a_list<T>::iterator a_list<T>::end() const noexcept
{
    return iterator(this->node);
}
// clear 擦除所有元素。此调用后 size() 返回零。
// 非法化任何指代所含元素的引用、指针或迭代器。任何尾后迭代器保持合法。
template <typename T>
void a_list<T>::clear() noexcept
{
    auto curr = this->node->next;
    while (curr != this->node) {
        auto next = curr->next;
        delete curr;
        curr = next;
    }
    size_count = 0;
    this->node->prev = this->node;
    this->node->next = this->node;
}
// insert 在 pos 前插入 value，返回指向插入元素的迭代器
template <typename T>
typename a_list<T>::iterator a_list<T>::insert(iterator pos, const T& value)
{
    auto temp = new list_node<T>(value);

    temp->prev = pos.link->prev;
    pos.link->prev = temp;

    temp->prev->next = temp;
    temp->next = pos.link;

    ++size_count;

    return temp;
}
template <typename T>
typename a_list<T>::iterator a_list<T>::insert(typename a_list<T>::iterator pos, T&& value)
{
    auto temp = new list_node<T>(std::move(value));

    temp->prev = pos.link->prev;
    pos.link->prev = temp;

    temp->prev->next = temp;
    temp->next = pos.link;

    ++size_count;

    return temp;
}
// erase 擦除指定的元素。返回后随最后移除元素的迭代器。
// 移除位于 pos 的元素。
template <typename T>
typename a_list<T>::iterator a_list<T>::erase(iterator pos)
{
    if (pos == end()) {
        return end();
    }
    auto prev = pos.link->prev;
    auto next = pos.link->next;
    delete pos.link;
    prev->next = next;
    next->prev = prev;
    size_count -= 1;
    return iterator(next);
}
// 移除范围 [first; last) 中的元素
template <typename T>
typename a_list<T>::iterator a_list<T>::erase(iterator first, iterator last)
{
    while (first != last) {
        first = erase(first);
    }
    return last;
}
// push_back 后附给定元素 value 到容器尾。没有引用和迭代器被非法化。
template <typename T>
void a_list<T>::push_back(const T& value)
{
    insert(end(), value);
}
template <typename T>
void a_list<T>::push_back(T&& value)
{
    insert(end(), std::move(value));
}
// pop_back 移除容器的末元素。指向被擦除元素的迭代器和引用被非法化。
template <typename T>
void a_list<T>::pop_back()
{
    erase(--end());
}
// push_front 前附给定元素 value 到容器起始
template <typename T>
void a_list<T>::push_front(const T& value)
{
    insert(begin(), value);
}
template <typename T>
void a_list<T>::push_front(T&& value)
{
    insert(begin(), std::move(value));
}
// pop_front 移除容器首元素
template <typename T>
void a_list<T>::pop_front()
{
    erase(begin());
}
template <typename T>
a_list<T>& a_list<T>::operator=(a_list<T>&& rhs)
{
    clear();

    std::swap(size_count, rhs.size_count);
    std::swap(node, rhs.node);

    return *this;
}
template <typename T>
a_list<T>& a_list<T>::operator=(const a_list& rhs)
{
    if (this == &rhs) {
        return *this;
    }
    clear();

    this->size_count = 0;
    for (auto iter = rhs.begin(); iter != rhs.end(); ++iter) {
        push_back(*iter);
    }

    return *this;
}
template <typename T>
a_list<T>::~a_list()
{
    clear();
    delete node;
}

template <typename T>
bool a_list<T>::operator==(const a_list& rhs) const
{
    if (rhs.size_count != this->size_count) {
        return false;
    }
    auto iter1 = this->begin();
    auto iter2 = rhs.begin();
    for (; iter1 != this->end() && iter2 != rhs.end(); ++iter1, ++iter2) {
        if (*iter1 != *iter2) {
            return false;
        }
    }
    return true;
}
template <typename T>
bool a_list<T>::operator!=(const a_list& rhs) const
{
    return !((*this) == rhs);
}