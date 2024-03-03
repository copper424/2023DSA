# 15-5 Hardest Job Ever!

# 题目描述

This is really hard, find the number of zeros in the number 12345678987654321!, here ‘!’ means factorial.

Well, I’m kidding. No one on earth may ever solve this successfully.

In fact, you are a spy, and you have stolen some top secret of the enemy, now you are to find a way which takes you least time to escape.

There are some many crosspoints and some many roads, even between two crosspoints there can be multiple roads. You are confused, but happily you have your laptop with you.

# 输入格式

The first line contains number `T (T<=10)`, the number of test cases.

Each test case begins with two integers `n (1<=n<=200)` and `m (0<=m<=10000)`, number of crosspoints and number of roads respectively. Next m lines each has three integers `i,j,k (i!=j, 1<=k<=10000)`, indicating there is a road of length `k` connecting city `i` and city `j`.

You can assume that the crosspoints are numbered from `1` to `n`. `1` is your starting point and you need to go to crosspoint `n`.

Roads are bidirectional.

# 输出格式

For each test case, output one number, the shortest distance. If there is no path exist, output `-1`.

# 样例输入

```plain
1
2 1
1 2 3
```

# 样例输出

```plain
3
```
