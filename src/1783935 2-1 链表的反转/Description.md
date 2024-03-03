# 2-1 链表的反转

# 题目描述

下面所给的是链表节点的结构，你的任务是写一个函数将链表反转。

```cpp
struct ListNode
{
    int val;
    ListNode *next = nullptr;
    ListNode(int n=0) : val(n) {}
};
```

上述结构定义在头文件ListNode.h中，而你所需实现的函数为：

```cpp
ListNode* reverseList(ListNode* head);
```

**提示**：请记得将头文件包含进去，即#include"ListNode.h"

## 注意事项：

- 只需写出reverseList函数实现即可，不用提交main函数。
- 传入的链表与反转后的链表均有头节点

![file](/api/users/image?path=5970/images/1630305297326.png)