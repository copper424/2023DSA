# 3-2 基于数组的栈

### 题目描述
请实现以下定义的栈类：
```
enum ErrorCode
{
	success,
	underflow,
	overflow
};

const int maxStack = 100;		// 栈的最大容量

template <class StackEntry>
class MyStack
{
public:
	MyStack();
	/*
		判断栈是否为空，若为空则返回true，非空则返回false
	 */
	bool empty() const;
	/*
		出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow
	 */
	ErrorCode pop();
	/*
		获取栈顶元素，若正常出栈则返回success，若栈内无元素则返回underflow
		元素内容保存在引用参数item中
	 */
	ErrorCode top(StackEntry &item) const;
	/*
		入栈操作，若正常入栈则返回success，若栈满则返回overflow
	 */
	ErrorCode push(const StackEntry &item);

private:
	int size;
	StackEntry entry[maxStack];
};
```

### 注意
需要提交枚举类型ErrorCode的定义，类MyStack的声明以及函数实现，不需要提交main函数。
