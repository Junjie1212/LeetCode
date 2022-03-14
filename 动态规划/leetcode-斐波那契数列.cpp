/*
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/

class Solution {
public:

    //方法1 记忆化搜索
    int fib(int n) 
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        vector<int> dp(n+1,0);
        dp[1] = 1;  
        for(int i=2;i<n+1;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
            if(dp[i]>=1000000007)
                dp[i] -= 1000000007; 
        }
        return dp[n];
    }
};