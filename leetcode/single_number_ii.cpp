/*
Single Number II 
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

分析：
其实此题与single number相差不多，如果把每一个数都看做是二进制的数，那么我们只需要对
int类型32位的1进行计数，然后对3进行取余，最后就得到了所需要的那个数
*/

//最朴素的方法如下，对每一位进行计数，然后对3取余，最后就得到了所要找的那个数
class Solution1 {
public:
    int singleNumber(int A[], int n) {
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j=0; j<n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i] ++;
                }
            }
            result |= (count[i]%3 << i);
        }
        return result;
    }
};

//然后可以对问题进行深一步的简化
/*
令
ones表示每一位上1出现过奇数次
twos表示每一位上1出现过两次
threes表示每一位上出现过3次
那么我们可以知道，如果在每一位上ones为1，且twos也为1，那么表示该位上1已经出现过
3次了，然后threes为1，然后对ones和twos进行清零，最后得到的就是只出现过一次的数了
*/
class Solution2 {
public:
    int singleNumber(int A[], int n) {
        int ones = 0;
        int twos = 0;
        int threes = 0;
        
        for (int i=0; i<n; i++) {
            twos |= (ones & A[i]); //twos依据上次一ones的结果来定
            ones ^= A[i];    	   //出现过奇数次
            threes = twos & ones;  //如果已经出现过两次，并且又出现了一次，则这是第三次
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};