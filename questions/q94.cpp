/*************************************************************************
	> File Name: q94.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  4/21 15:58:09 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/**
Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if(root != NULL)
            //recursiveInorderTraversal(root, result);
        return result;
    }

private:
    
    /*
    void recursiveInorderTraversal(TreeNode* root, vector<int> &result)
    {
        if(root == NULL) 
            return;
        
        if(root->left != NULL)
            recursiveInorderTraversal(root->left, result);

        result.push_back(root->val);

        if(root->right != NULL)
            recursiveInorderTraversal(root->right, result);
            
    }
    */
    void iterativelInorderTraversal(TreeNode* root, vector<int> &result)
    {
        
        stack<TreeNode *> leftSubTree;
        TreeNode *p = root;

        while(p != NULL || !leftSubTree.empty())
        {
            while(p != NULL) //将左子树一直入栈
            {
                leftSubTree.push(p);
                p = p->left;
            }

            if(!leftSubTree.empty())
            {
                p = leftSubTree.top();
                result.push_back(p->val);
                leftSubTree.pop();
                p = p->right; //开始遍历右子树
            }
        }

    }


};

