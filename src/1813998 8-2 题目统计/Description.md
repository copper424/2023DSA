# 8-2 题目统计

每一行代表一条提交记录，有3个数字M、N和T，中间用空格隔开，M代表用户id，N代表题号，T代表本次提交是否通过该题（T为0表示不通过，为1表示通过），这一条记录表示id为M的用户提交了题号为N的题。

请统计一下每个同学在每个题目上提交通过和不通过的次数。

**输入格式：**
只有一个测试用例
第1行有两个整数A和B，代表分别代表学生数量和当周的题目数量
（1 <= A <= 300，1 <= B <= 10）
接下来输入TA拿到的数据，有多行，以EOF结束
每一行是3个整数M、N和T，中间用空格隔开
（1 <= M <= A，1 <= N <= B）

**输出格式：**
输出共A行，每行有2*B个整数，中间用空格隔开
第i行第(2*j-1)和(2*j)个整数分别代表id为i的同学提交第j个题目通过和不通过的次数。（1<= i <= A，1 <= j <= B）

**样例输入：**
3 3
1 1 1
2 3 0
1 2 1
3 1 1
1 3 1
3 2 0

**样例输出：**
1 0 1 0 1 0
0 0 0 0 0 1
1 0 0 1 0 0