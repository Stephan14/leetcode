/*************************************************************************
	> File Name: q94.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  4/21 15:58:09 2017
 ************************************************************************/

#include<iostream>
#include<vector>

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
            recursiveInorderTraversal(root, result);
        return result;
    }

private:
    
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
};

