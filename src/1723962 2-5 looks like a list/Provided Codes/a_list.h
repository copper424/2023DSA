#ifndef A_LIST
#define A_LIST

#include <utility>

template <typename T>
struct list_node
{
    list_node *prev = nullptr;
    list_node *next = nullptr;
    T data;

    list_node() : data() {}
    list_node(const T &data) : data(data) {}
    list_node(T &&data) : data(std::move(data)) {}
};

template <typename T>
struct list_iter
{
    using link_type = list_node<T> *;

    link_type link = nullptr;

    list_iter(link_type l) : link(l) {}

    bool operator==(const list_iter &rhs) const { return link == rhs.link; }
    bool operator!=(const list_iter &rhs) const { return link != rhs.link; }

    list_iter &operator++()
    {
        link = link->next;
        return *this;
    }
    list_iter &operator--()
    {
        link = link->prev;
        return *this;
    }

    T &operator*() { return link->data; }
};

template <typename T>
struct a_list
{
    using value_type = T;
    using reference = value_type &;
    using size_type = std::size_t;
    using iterator = list_iter<T>;

    a_list() : node(new list_node<T>)
    {
        node->next = node;
        node->prev = node;
    }
    a_list(const a_list &other) : node(new list_node<T>)
    {
        for (auto it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
    }
    a_list(a_list &&other) : node(other.node), size_count(other.size_count)
    {
        other.node = new list_node<T>;
        other.node->prev = other.node->next = other.node;
        other.size_count = 0;
    }
    a_list &operator=(const a_list &);
    a_list &operator=(a_list &&);

    ~a_list();

    bool operator==(const a_list &rhs) const;
    bool operator!=(const a_list &rhs) const;

    // front 返回到容器首元素的引用。
    // 在空容器上对 front 的调用是未定义的。
    reference front();

    // back 返回到容器中最后一个元素的引用。
    // 在空容器上对 back 的调用是未定义的。
    reference back();

    // empty 检测容器是否无元素
    bool empty() const noexcept;
    // size 返回容器中的元素数
    size_type size() const noexcept;

    // begin 返回指向 list 首元素的迭代器
    iterator begin() noexcept;
    iterator begin() const noexcept;
    // end 返回指向 list 末元素后一元素的迭代器
    iterator end() noexcept;
    iterator end() const noexcept;

    // clear 擦除所有元素。此调用后 size() 返回零。
    // 非法化任何指代所含元素的引用、指针或迭代器。任何尾后迭代器保持合法。
    void clear() noexcept;

    // insert 在 pos 前插入 value，返回指向插入元素的迭代器
    iterator insert(iterator pos, const T &value);
    iterator insert(iterator pos, T &&value);

    // erase 擦除指定的元素。返回后随最后移除元素的迭代器。
    // 移除位于 pos 的元素。
    iterator erase(iterator pos);
    // 移除范围 [first; last) 中的元素
    iterator erase(iterator first, iterator last);

    // push_back 后附给定元素 value 到容器尾。没有引用和迭代器被非法化。
    void push_back(const T &value);
    void push_back(T &&value);

    // pop_back 移除容器的末元素。指向被擦除元素的迭代器和引用被非法化。
    void pop_back();

    // push_front 前附给定元素 value 到容器起始
    void push_front(const T &value);
    void push_front(T &&value);

    // pop_front 移除容器首元素
    void pop_front();

private:
    list_node<T> *node = nullptr;
    size_type size_count = 0;
};

#endif
