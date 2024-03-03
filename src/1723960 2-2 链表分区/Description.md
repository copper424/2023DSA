# 2-2 链表分区

# 题目描述：

下面所给的是链表节点的结构，给定一个链表和一个值X，对其进行分区，使得节点值小于X的节点放在前面，大于等于X的节点放在后面，保持每个分区节点的原始顺序：

```cpp
struct ListNode
{
    int val = 0;
    ListNode *next = nullptr;
    ListNode(int x = 0) : val(x) {}
};
```

示例：
输入`5->7->44->1->35  10`

返回`5->7->1->44->35`

上述结构定义在头文件ListNode.h中，而你所需实现的函数为：

```cpp
ListNode* partList(ListNode* list, int x);
```

**提示**：

- 请记得将头文件包含进去，即`#include"ListNode.h"`
- 你只需写出partList函数实现即可，不用提交main函数
- 传入及返回的链表均无头节点
- 不要申请额外的内存
- `allNodes`仅测试用，不代表链表长度，请不要使用