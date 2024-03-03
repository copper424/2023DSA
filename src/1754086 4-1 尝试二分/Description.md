# 4-1 尝试二分

# 题目描述

实现函数
```cpp
vector<int> searchRange(vector<int>& nums, int target);
```

给定一个按照升序排列的整数数组`nums`，和一个目标值`target`。找出给定目标值在数组中的开始位置和结束位置

如果数组中不存在目标值`target`，返回`[-1, -1]`

尝试使用`O(log n)`时间复杂度的方法解决

# 示例

```
nums = [5,7,7,8,8,10], target = 8
returns = [3,4]
```