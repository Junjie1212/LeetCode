/*
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]
*/

//BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>> vec1;
        vector<int> vec2;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t==nullptr)
                    continue;
                vec2.push_back(t->val);

                if(t->left != nullptr && t->right == nullptr)
                    q.push(t->left);  
                if(t->left==nullptr && t->right != nullptr)
                    q.push(t->right);
                if(t->left != nullptr && t->right != nullptr)
                {
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            vec1.push_back(vec2);
            while(!vec2.empty())
                vec2.pop_back();
        }
        return vec1;
    }
};
