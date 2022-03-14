/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例1：
输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

示例2：
输入: numRows = 1
输出: [[1]]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>>ans(numRows);
       for(int i=0;i<numRows;i++)
       {
           ans[i].resize(i+1);
           ans[i][0]=ans[i][i]=1;
           for(int j=1;j<i;j++)
           {
               ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
           }
       }
       return ans;
    }
};
