/*
Remove Duplicates from Sorted Array 
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
分析：
本题有一定的技巧性

其中要注意的是要分析当n=0的情况，这种题注意怎么解很重要，但是绝对不能忽视了
对各种临界情况的分析，这关系到自己的思路是否够严谨

*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n==0) return 0;
        
        int index = 0;
        for (int i=1; i<n; i++) {
            if(A[index] != A[i]) {
                A[++index] = A[i];
            }
        }
        return ++index;
    }
};