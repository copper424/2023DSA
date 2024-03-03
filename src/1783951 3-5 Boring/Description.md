# 3-5 Boring

## 题目描述
After the make-up examine,Tiantian is bored because he needn’t review digital circuit now.So he decides to calculate the number of people in the queue.What a boring boy!
There are three operations of the queue:
In x: push x(x <= 10000) in the end of the queue.
Out: write out the first element of the queue and erase it.If the queue is empty,write out -1.
Count: return the length of the queue.

## 输入描述
Each test contains a single number N(N <= 1000) means the number of operations.Following n lines describe the operation of the queue.

## 输出描述
For each Out and Count operation,write out its expected answer.

## 样例输入
10

Count

Count

In 9035

Out

Out

In 9809

In 4983

Out

Count

Out

## 样例输出
0

0

9035

-1

9809

1

4983

