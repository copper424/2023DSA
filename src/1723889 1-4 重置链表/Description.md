# 1-4 重置链表

## 题目描述：

下面所给的是链表节点的结构，你的任务是写一个函数将链表中奇数位节点放在一起，偶数位节点放在一起

```cpp
struct ListNode
{
    int val = 0;
    ListNode *next = nullptr;
    ListNode(int x = 0) : val(x) {}
};
```

实现函数

```cpp
ListNode* resetList(ListNode* head);
```

示例：
已知链表：`4->8->45->67->58->94->48`

返回：    `4->45->58->48->8->67->94`

**提示**

- 请记得将头文件包含进去，即#include"ListNode.h" ，链表的节点从1开始计数
- 无头节点
- 不要申请额外的内存
- `allNodes`仅测试用，不代表链表长度，请不要使用