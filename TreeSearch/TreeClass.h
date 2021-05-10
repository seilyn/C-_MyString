#pragma once
#include <string>
class Tree
{
	std::string data;
	Tree* left, *right;
public:
	Tree()
	{
		data = "";
		left = NULL;
		right = NULL;
	}
	void setData(char data) { this->data = data; }
	void setLeft(Tree* left) { this->left = left; }
	void setRight(Tree* right) { this->right = right; }

	void static preorder(Tree* root)
	{
		if (root)
		{
			std::cout << root->data;
			preorder(root->left);
			preorder(root->right);
		}
	}
	void static inorder(Tree* root)
	{
		if (root)
		{
			inorder(root->left);
			std::cout << root->data;
			inorder(root->right);
		}
	}
	void static postorder(Tree* root)
	{
		if (root)
		{
			postorder(root->left);
			postorder(root->right);
			std::cout << root->data;
		}
	}
};