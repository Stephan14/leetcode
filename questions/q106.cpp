/*************************************************************************
	> File Name: q106.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  4/ 5 14:30:06 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, int inorder_begin, int inorder_end, vector<int>& postorder, int postorder_begin, int postorder_end)
    {
        if(inorder_begin > inorder_end && postorder_begin > postorder_end)
            return NULL;

        int index = inorder_begin;
        for(; index < inorder_end; index++)
        {
            if(postorder[postorder_end] == inorder[index]) 
                break; 
        }

        TreeNode* root = new TreeNode(postorder[postorder_end]);
        root->left = buildTree(inorder, inorder_begin, index - 1, postorder, postorder_begin, postorder_begin + index - inorder_begin - 1);
        root->right = buildTree(inorder, index + 1, inorder_end, postorder, postorder_begin + index - inorder_begin, postorder_end - 1);

        return root;
    }
};
