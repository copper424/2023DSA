# 14-1 广度优先搜索

## 问题描述：
读入图的邻接矩阵(连通图）以及一个顶点的编号（图中顶点的编号为从1开始的连续正整数。顶点在邻接矩阵的行和列上按编号递增的顺序排列。邻接矩阵中元素值为1，表示对应顶点间有一条边，元素值为0，表示对应顶点间没有边），输出从该顶点开始进行广度优先搜索（Breadth-First Search, BFS）的顶点访问序列。假设顶点数目<=100，并且，对于同一顶点的多个邻接顶点，按照顶点编号从小到大的顺序进行搜索。
## 输入描述：
第一行为两个整数n和s (0<n<=100, 0<s<=n)，n表示图中顶点的数目，s为搜索的起始顶点的编号。后面的n行表示图的邻接矩阵(连通图)，每行为n个整数，相邻整数间用一个空格间隔。
## 输出描述：
一行（行末没有换行符，也没有空格符），表示从顶点s开始进行BFS的顶点访问序列，相邻顶点间用一个空格间隔。
## 输入样例：
4 3</br>
0 1 1 0</br>
1 0 1 1</br>
1 1 0 1</br>
0 1 1 0</br>
## 输出样例：
3 1 2 4