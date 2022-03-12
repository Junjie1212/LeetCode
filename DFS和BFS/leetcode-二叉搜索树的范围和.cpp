/*
给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。

示例1
输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
输出：32

示例2
输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
输出：23
*/

class Solution {
public:

    //方法1 dfs   
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        int sum=0;
        if(root==NULL)
            return 0;
        if((root->val) >= low && (root->val) <= high)
            sum+= (root->val);
        int leftsum = rangeSumBST(root->left,low,high);
        int rightsum = rangeSumBST(root->right,low,high);
        return leftsum+rightsum+sum;
    }

    //方法2 BFS
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        int res = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t==NULL)
                    continue;
                if(t->val > high)
                    q.push(t->left);
                if(t->val < low)
                    q.push(t->right);
                if(t->val <= high && t->val >= low)
                {
                    res+=t->val;
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        return res;
    }
};
