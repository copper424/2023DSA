# 8-1 查找和最小的前K个对数字

## 问题描述:<br>
给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。<br>
定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。<br>
找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。若k大于总数对的数量，则输出所有数对<br>

输入格式：<br>
三行，第一行三个数字k,m,n，其中m和n为第一第二个数组的大小，第二行为第一个数组，第三行为第二个数组<br>
输出格式：<br>
前k个和最小的数对，以空格分隔<br>

## 输入样例<br>
3 3 3<br>
1 7 11<br>
2 4 6 <br>


## 输出样例<br>
1,2 1,4 1,6<br>
