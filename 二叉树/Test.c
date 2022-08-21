#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "Queue.h"

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	node->data = x;
	node->left = node->right = NULL;
	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyBTNode(1);
	BTNode* node2 = BuyBTNode(2);
	BTNode* node3 = BuyBTNode(3);
	BTNode* node4 = BuyBTNode(4);
	BTNode* node5 = BuyBTNode(5);
	BTNode* node6 = BuyBTNode(6);
	BTNode* node7 = BuyBTNode(7);
	BTNode* node8 = BuyBTNode(8);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node2->right = node7;
	node4->left = node5;
	node4->right = node6;

	node6->right = node8;

	return node1;
}

void PrevOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

// 后序 -- 自己实现，自己画图感受一下

// 多次调用会有问题，没办法每次初始化为0
//int BTreeSize(BTNode* root)
//{
//	static int count = 0;
//	if (root == NULL)
//		return count;
//
//	++count;
//	BTreeSize(root->left);
//	BTreeSize(root->right);
//
//	return count;
//}

// 线程安全的问题，这个以后linux学了大家就知道了
//int count = 0;
//void BTreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return;
//
//	++count;
//	BTreeSize(root->left);
//	BTreeSize(root->right);
//}

// 思想：遍历+计数
//void BTreeSize(BTNode* root, int* pCount)
//{
//	if (root == NULL)
//		return;
//
//	++(*pCount);
//	BTreeSize(root->left, pCount);
//	BTreeSize(root->right, pCount);
//}

int BTreeSize(BTNode* root) {
	return root == NULL ? 0 :
		BTreeSize(root->left)
		+ BTreeSize(root->right) + 1;
}

int BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}

// 第k层的节点的个数，k >= 1
int BTreeKLevelSize(BTNode* root, int k)
{
	assert(k >= 1);

	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTreeKLevelSize(root->left, k - 1)
		+ BTreeKLevelSize(root->right, k - 1);
}

int BTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = BTreeDepth(root->left);
	int rightDepth = BTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

// 二叉树查找值为x的结点
BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = BTreeFind(root->left, x);
	if (ret1)
		return ret1;

	//return BTreeFind(root->right, x);
	BTNode* ret2 = BTreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

// 二叉树销毁
void BTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BTreeDestory(root->left);
	BTreeDestory(root->right);
	free(root);
}

// 层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%d ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");
	QueueDestory(&q);
}

// 判断二叉树是否是完全二叉树
bool BTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		// 空后面出到非空，那么说明不是完全二叉树
		if (front)
		{
			QueueDestory(&q);
			return false;
		}
	}

	QueueDestory(&q);
	return true;
}

int main()
{
	BTNode* tree = CreatBinaryTree();
	PrevOrder(tree);
	printf("\n");

	InOrder(tree);
	printf("\n");


	/*printf("size:%d\n", BTreeSize(tree));
	printf("size:%d\n", BTreeSize(tree));
	printf("size:%d\n", BTreeSize(tree));*/

	//count = 0;
	//BTreeSize(tree);
	//printf("size:%d\n", count);

	//count = 0;
	//BTreeSize(tree);
	//printf("size:%d\n", count);

	//count = 0;
	//BTreeSize(tree);
	//printf("size:%d\n", count);

	/*int count1 = 0;
	BTreeSize(tree, &count1);
	printf("size:%d\n", count1);

	int count2 = 0;
	BTreeSize(tree, &count2);
	printf("size:%d\n", count2);*/

	printf("size:%d\n", BTreeSize(tree));
	printf("size:%d\n", BTreeSize(tree));
	printf("size:%d\n", BTreeSize(tree));

	printf("Leaf size:%d\n", BTreeLeafSize(tree));

	printf("Depth size:%d\n", BTreeDepth(tree));

	for (int i = 1; i <= 7; ++i)
	{
		printf("Find:%d,%p\n", i, BTreeFind(tree, i));
	}

	BTNode* ret = BTreeFind(tree, 5);
	if (ret)
	{
		ret->data = 50;
	}
	PrevOrder(tree);
	printf("\n");

	LevelOrder(tree);
	printf("完全二叉树:%d\n", BTreeComplete(tree));


	BTreeDestory(tree);
	tree = NULL;

	return 0;
}