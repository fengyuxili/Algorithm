# 二分查找算法
* 二分查找算法适用于已经排好序的序列
* 根据3个索引low mid high 和 mid=(low + high)/2 的关系快速折半比较和查找
* 大于mid索引的数值时low=mid+1；小于mid索引的数值时，high=mid-1
* low > high 跳出查找循环