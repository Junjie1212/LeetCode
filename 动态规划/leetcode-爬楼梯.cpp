/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

示例1:
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶

示例2：
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
*/

class Solution {
public:

    // 方法1 递归
    int climbStairs(int n) {
        // 偷个懒
        if(n==1)    
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 3;
        if(n==4)    
            return 5;
        if(n==5)
            return 8;
        if(n==6)
            return 13;
        if(n==7)
            return 21;
        return climbStairs(n-1)+climbStairs(n-2);
    }

    //方法2 记忆化搜索
    int climbStairs(int n) 
    {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        vector<int> dp(n+1,0);
        dp[1]=1,dp[2]=2;
        for(int i=3; i<n+1;i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};