/*Single Number
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
分析：
 定义result=0；然后将result与数组的每一个数进行异或操作，这样出现两次的数字都被抵消，最后剩下的就是
 所要找的数字
 
 线性运行时间需要的就是只执行一次循环，而不能有额外的内存是需要不能有辅助数组之类的定义
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i=0; i<n; i++) {
            result ^= A[i];
        }
        return result;
    }
};