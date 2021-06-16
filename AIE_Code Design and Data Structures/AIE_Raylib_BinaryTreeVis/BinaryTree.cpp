

#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* node = new TreeNode(a_nValue);

	NodeToInsert(m_pRoot, node);
}

void BinaryTree::NodeToInsert(TreeNode*& n, TreeNode* nti)
{
	if (n == nullptr)
	{
		n = nti;
	}
	else if (nti->GetData() < n->GetData())
	{
		NodeToInsert(n->GetLeft(), nti);
	}
	else if (nti->GetData() > n->GetData())
	{
		NodeToInsert(n->GetRight(), nti);
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	ToFind(m_pRoot, a_nValue);

	return ToFind(m_pRoot, a_nValue);
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	return false;
}

TreeNode* BinaryTree::ToFind(TreeNode* n, int value)
{
	if (n == nullptr || n->GetData() == value)
	{
		return n;
	}

	if (n->GetData() < value)
	{
		return ToFind(n->GetRight(), value);
	}
	return ToFind(n->GetLeft(), value);
}


void BinaryTree::Remove(int a_nValue)
{
	if (m_pRoot->GetData() == a_nValue)
	{
		if (m_pRoot->GetLeft() == nullptr)
			m_pRoot = m_pRoot->GetRight();
		else if (m_pRoot->GetRight() == nullptr)
			m_pRoot = m_pRoot->GetLeft();
		else if (m_pRoot->GetLeft() == nullptr && m_pRoot->GetRight() == nullptr)
			m_pRoot = nullptr;
	}

	ToRemove(m_pRoot, Find(a_nValue));
}

TreeNode* BinaryTree::minValueNode(TreeNode* Treenode)
{
	TreeNode* currentNode = Treenode;
	while (currentNode && currentNode->GetLeft() != nullptr)
	{
		currentNode = currentNode->GetLeft();
	}
	return currentNode;
}

TreeNode* BinaryTree::ToRemove(TreeNode* root, TreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->GetData() < root->GetData())
	{
		root->SetLeft(ToRemove(root->GetLeft(), node));
	}

	else if (node->GetData() > root->GetData())
	{
		root->SetRight(ToRemove(root->GetRight(), node));
	}

	else
	{
		if (root->GetLeft() == nullptr)
		{
			TreeNode* temp = root->GetRight();
			return temp;
			//TreeNode* temp = root->GetRight();
			//return temp;
		}
		else if (root->GetRight() == nullptr)
		{
			TreeNode* temp = root->GetLeft();
			return temp;
		}
		TreeNode* temp = minValueNode(root->GetRight());
		root->SetData(temp->GetData());
		root->SetRight(ToRemove(root->GetRight(), temp));
	}
	return root;
}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}