#include<iostream>
#include<cstring>
#include<vector>
#include <functional>
#include<list>

struct Node
{
	int value;
	Node* left = nullptr;
	Node* right = nullptr;

	// Constructor
	Node() {};

	// Overloaded Constructor
	Node(int value) : value(value) {}

	// Overloaded Constructor
	Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

void ForEachPreOrder(Node* n, std::function<void(Node*)> fn)
{
	if (n == nullptr)
		return;

	// Invoke the fn for each node
	fn(n);

	ForEachPreOrder(n->left, fn);
	ForEachPreOrder(n->right, fn);
}

void ForEachDfs(Node* root, std::function<void(Node*)> fn)
{
	// Create the stack
	std::list<Node*> stack;

	// add first node to the stack
	stack.push_back(root);

	// while stack is not empty
	while (stack.empty() == false)
	{
		// remove the next node
		Node* n = stack.back();
		stack.pop_back();

		// process the node
		fn(n);

		// add children to the stack
		if (n->right) stack.push_back(n->right);
		if (n->left) stack.push_back(n->left);
	}
}

Node* Find(Node* n, int value)
{
	if (n == nullptr || n->value == value)
	{
		return n;
	}

	if (n->value < value)
	{
		return Find(n->right, value);
	}
	return Find(n->left, value);
}

Node* newNode(int data)
{
	Node* n = new Node;

	n->value = data;

	n->left = nullptr;
	n->right = nullptr;

	return n;
}

void NodeToInsert(Node*& n, Node* nti)
{

	/*if (n == nullptr)
		n = nti;
	else if (nti->value > n->value)
		NodeToInsert(n->right, nti);
	else if (nti->value < n->value)
		NodeToInsert(n->left, nti);*/

	if (n == nullptr)
	{
		n = nti;
		
	}
	else if (nti->value < n->value)
	{
		NodeToInsert(n->left, nti);
		
	}
	else if (nti->value > n->value)
	{
		NodeToInsert(n->right, nti);
		
	}
}

//Node* NodeToInsert(Node* root, Node* nodeToInsert)
//{
//   
//
//    if (root == nullptr)
//    {
//        root = nodeToInsert;
//        return nodeToInsert;
//    }
//    if (nodeToInsert->value > root->value)
//    {
//        NodeToInsert(root->right, nodeToInsert);
//        return nodeToInsert;
//    }
//    if (nodeToInsert->value <= root->value)
//    {
//        NodeToInsert(root->left, nodeToInsert);
//        return nodeToInsert;
//    }
//    
//    return nodeToInsert;
//}

Node* minValueNode(Node* node)
{
	Node* currentNode = node;
	while (currentNode && currentNode->left != nullptr)
	{
		currentNode = currentNode->left;
	}
	return currentNode;
}

Node* Remove(Node* root, Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->value < root->value)
	{
		root->left = Remove(root->left, node);
	}

	else if (node->value > root->value)
	{
		root->right = Remove(root->right, node);
	}

	else
	{
		if (root->left == nullptr)
		{
			Node* temp = root->right;
			return temp;
		}
		else if (root->right == nullptr)
		{
			Node* temp = root->left;
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->value = temp->value;
		root->right = Remove(root->right, temp);
	}
	return root;
}



//void Remove(Node*& root, int val)
//{
//    Node* parent = nullptr;
//    Node* nodeToRemove = Find(root, val);
//
//    if (nodeToRemove == nullptr)
//    {
//        return;
//    }
//
//    if (parent == nullptr)
//    {
//        root == nullptr;
//    }
//    else if (parent->left == nodeToRemove)
//    {
//        parent->left = nullptr;
//    }
//    else if (parent->right == nodeToRemove)
//    {
//        parent->right = nullptr;
//    }
//
//    NodeToInsert(root, nodeToRemove->left);
//    NodeToInsert(root, nodeToRemove->right);
//
//    delete nodeToRemove;
//}

int Height(Node* n)
{
	//if we failed to input a number value return null;
	if (n == nullptr)
	{
		return 0;
	}

	//calculate the height left and right
	int heightLeft = Height(n->left);
	int heightRight = Height(n->right);

	//return values for left and right
	if (heightLeft > heightRight)
	{
		return heightLeft + 1;
	}
	else
	{
		return heightRight + 1;
	}
}

int Depth(Node* root, Node* n)
{
	int depth = 0;

	if (n == nullptr && root == nullptr)
	{
		return 0;
	}

	if (root->value > n->value)
	{
		Depth(root->right, n);
		return depth;
	}

	if (root->value < n->value)
	{
		Depth(root->left, n);
		return depth;
	}
}

void PrintNode(Node* n)
{
	std::cout << n->value << ", ";
}

int main(int argc, char** argv)
{

	// our tree
	/***********************
					6
				   / \
				  /   \
				 /     \
				4       8
			   / \     / \
			  2   5   7   9
	***********************/

	//Node* root = nullptr;

	Node root(6,
		new Node(4,
			new Node(2),
			new Node(5)),
		new Node(8,
			new Node(7),
			new Node(9)));




	// Node* test = Find(&root, 8);

	// inserts new Nodes

	/*NodeToInsert(root, new Node(10));
	NodeToInsert(root, new Node(5));
	NodeToInsert(root, new Node(2));
	NodeToInsert(root, new Node(100));
	NodeToInsert(root, new Node(63));
	NodeToInsert(root, new Node(7));
	NodeToInsert(root, new Node(42));
	NodeToInsert(root, new Node(11));*/

	std::cout << Height(&Node(9)) << std::endl;

	// Call our ForEach Method defined above,
	// Pass it the "PrintNode" method
	ForEachPreOrder(&root, PrintNode);

	// We can also pass in a lambda function
	// directly as a parameter
   /* ForEachDfs(&root, [](Node* n) {
		std::cout << n->value << ", ";
		});*/

	return 0;

}