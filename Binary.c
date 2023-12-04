#define _CRT_SECURE_NO_WARNINGS
#include "Binary.h"
TreeNode* BuyTreeNode(int x)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	assert(node);
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
TreeNode* CreateNode()
{
	TreeNode* node1 = BuyTreeNode(1);
	TreeNode* node2 = BuyTreeNode(2);
	TreeNode* node3 = BuyTreeNode(3);
	TreeNode* node4 = BuyTreeNode(4);
	TreeNode* node5 = BuyTreeNode(5);
	TreeNode* node6 = BuyTreeNode(6);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}
void PrevOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PrevOrder(root->left);
	printf("%d ", root->data);
	PrevOrder(root->right);
}
void AdterOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PrevOrder(root->left);
	PrevOrder(root->right);
	printf("%d ", root->data);
}
int TreeSize(TreeNode* root)
{
	return root == NULL ? 0 : 1 + TreeSize(root->left) + TreeSize(root->right);
}
int TreeLeafSize(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (!root->left && !root->right)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int TreeHeight(TreeNode* root)//2ÖÖ·½·¨
{
	/*if (root == NULL)
	{
		return 0;
	}
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;*/

	if (root == NULL)
	{
		return 0;
	}
	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}
int TreeLeveLK(TreeNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
		return 1;
	return TreeLeveLK(root->left, k - 1) + TreeLeveLK(root->right, k - 1);
}