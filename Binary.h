#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;

TreeNode* BuyTreeNode(int x);
TreeNode* CreateNode();
void PrevOrder(TreeNode* root);
void InOrder(TreeNode* root);
void AdterOrder(TreeNode* root);
int TreeSize(TreeNode* root);
int TreeLeafSize(TreeNode* root);
int TreeHeight(TreeNode* root);
int TreeLeveLK(TreeNode* root, int k);