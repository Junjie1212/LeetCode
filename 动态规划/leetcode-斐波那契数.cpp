/*
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。

示例1：
输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1

示例2：
输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
*/

class Solution {
public:
    //方法1 递归
    int F(int a, int b)
    {
        if(b==0)
            return 1;
        if(b==1)
            return 2;
        return F(a-1,a-2)+F(b-1,b-2);
        
    }

    
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return F(n-1,n-2);
    }

    //方法2 记忆化搜索
    int fib(int n)
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=2; i<n+1; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};