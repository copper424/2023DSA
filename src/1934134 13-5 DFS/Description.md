# 13-5 DFS

# Problem

Given an undirected graph, compute the number of components.

# Input

The first line is the number of test cases `t`.

For every test case, the first line is the number of node `n`, meaning nodes are `1, 2, ..., n`.

The next line is the number of edges `m`, then `m` lines are followed, where each line is in the form of `u` `v`, meaning `(u,v)` is an undirected edge.

# Output

For each test case, print whether the graph is connected and the number of components:

```plain
YES, 1 component.
NO, 2 components.
```

# Sample Input

```plain
2

3
1
3 2

3
3
2 1
3 1
3 2
```

# Sample Output

```plain
NO, 2 components.
YES, 1 component.
```



