# 4-3 栈或队列

# 问题描述
给出进入结构和离开结构的整数的次序（假定在栈和队列中都是整数），请确定该结构是栈还是队列，或者既可以是栈又可以是队列？
注意：在所有整数进入结构之后，才会有整数被弹出。

# 输入
第一行输入一个整数N（1≤N≤100），表示即将进入结构的整数个数.
第二行输入以空格分开的N个整数，表示进入结构的次序（第一个数据最先进入）。
第三行输入以空格分开的N个整数，表示离开结构的次序（第一个数据最先离开）。
# 输出
如果结构只能是一个栈，则输出“stack”
如果结构只能是一个队列，则输出“queue”
如果结构既可以是栈，也可以是队列，则输出“both”
否则输出“neither”

# 输入样例
```
3
1 2 3
3 2 1
```

# 输出样例
```
stack
```