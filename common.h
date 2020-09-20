
#pragma once
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <functional>
#include<unordered_set>
#include <unordered_map>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
inline void initTree(TreeNode* node, int* arr, unsigned int num, int index = 0)
{
	if (2 * index + 1 < num)
	{
		node->left = new TreeNode(arr[2 * index + 1]);
		initTree(node->left, arr, num, 2 * index + 1);
	}
	if (2 * index + 2 < num)
	{
		node->right = new TreeNode(arr[2 * index + 2]);
		initTree(node->right, arr, num, 2 * index + 2);
	}
}
inline unsigned int getTreeHeight(TreeNode* root) {
    static function<void(TreeNode*,unsigned int&,unsigned int& )> func = [](TreeNode* node,unsigned int& res,unsigned int& h) {
        if (node == nullptr)return;
        h++;
        res = res > h?res:h;
        if (node->left != nullptr)func(node->left,res,h);
        if (node->right!= nullptr)func(node->right,res,h);
        h--;
    };
    unsigned int res = 0,temph=0;
    func(root,res,temph);
    return res;
}

inline void printTree(TreeNode* root)
{
	if (root == nullptr)
    {
        printf("NULL Tree");
        return;
    }

    queue<TreeNode*> myque;
    myque.emplace(root);

    while (!myque.empty())
    {
        int l = myque.size();
        for (int i = 0; i < l; ++i) {
            printf("%d ",myque.front()->val);
            if(myque.front()->left!=nullptr)myque.emplace(myque.front()->left);
            if(myque.front()->right!=nullptr)myque.emplace(myque.front()->right);
            myque.pop();
        }
        printf("\n");
    }
}

inline void printVector(vector<int> r)
{
    for_each(r.begin(), r.end(), [](int a) {
        printf("%d\n", a);
    });
}
