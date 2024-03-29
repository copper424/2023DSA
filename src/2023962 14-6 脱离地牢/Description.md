# 14-6 脱离地牢

# 题目描述

在一个神秘的国度里，年轻的王子Paris与美丽的公主Helen在一起过着幸福的生活。他们都随身带有一块带磁性的阴阳魔法石，身居地狱的魔王Satan早就想得到这两块石头了，只要把它们熔化，Satan就能吸收其精华大增自己的魔力。于是有一天他趁二人不留意，把他们带到了自己的地牢，分别困在了不同的地方。然后Satan念起了咒语，准备炼狱，界时二人都将葬身于这地牢里。

危险！Paris与Helen都知道了Satan的意图，他们要怎样才能打败魔王，脱离地牢呢？Paris想起了父王临终前留给他的备忘本，原来他早已料到了Satan的野心，他告诉Paris只要把两块魔法石合在一起，念出咒语，它们便会放出无限的光亮，杀死魔王，脱离地牢，而且本子上还附下了地牢的地图，Paris从中了解到了Helen的位置所在。于是他决定首先要找到Helen，但是他发现这个地牢很奇怪，它会增强二人魔法石所带磁力的大小，而且会改变磁力的方向。这就是说，每当Pairs向南走一步，Helen有可能会被石头吸引向北走一步。而这个地狱布满了岩石与熔浆，Pairs必须十分小心，不仅他不能走到岩石或熔浆上，而且由于他行走一步，Helen的位置也会改变，如果Helen碰到岩石上，那么她将停留在原地，但如果Helen移动到了熔浆上，那么她将死去，Paris就找不到她了。

Pairs仔细分析了地图，他找出了一条最快的行走方案，最终与Helen相聚。他们一起念出了咒语"@^&#……%@%&$"，轰隆一声，地牢塌陷了，他们又重见光明……

# 输入

输入数据第一行为两个整数`n,m (3<=n,m<=20)`，表示地牢的大小，`n`行`m`列。

接下来`n`行，每行`m`个字符，描述了地牢的地图，`.`代表通路，`#`代表岩石，`!`代表熔浆。

输入保证地牢是封闭的，即四周均是均是岩石或熔浆。接下来一行有四个字符`N`（北），`S`（南），`W`（西），`E`（东）的排列，表示Paris分别向NSWE四个方向走时Helen受磁石磁力影响的移动方向。

# 输出

输出文件只有一行，如果Paris能找到Helen，输出一整数`d`，为Paris最少需要行走的步数；如果Paris在`255`步之后仍找不到Helen，则输出`"Impossible"`。

注意相遇是指Paris与Helen最终到达同一个格子，或者二人在相邻两格移动后碰在了一起，而后者的步数算他们移动后的步数。

# 样例输入

```plain
5 5
#####
#H..#
#.!.#
#.#P#
#####
WNSE
```

# 样例输出

```plain
5
```

解释：Paris行走方案为NNWWS，每步过后Helen位置在(2,2), (2,2), (3,2), (4,2), (3,2)。

