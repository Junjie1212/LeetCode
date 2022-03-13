/*
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]
*/

 /*
 和二叉树的层次遍历I一样，最后逆输出
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>vec1;
        queue<TreeNode*>q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> vec2;
            for(int i=0; i<n; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t==nullptr)
                    continue;
                vec2.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            vec1.push_back(vec2);
        }
        reverse(vec1.begin(),vec1.end());
        return vec1;
    }
};
