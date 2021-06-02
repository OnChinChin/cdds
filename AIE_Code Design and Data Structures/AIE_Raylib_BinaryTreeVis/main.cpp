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
    // TODO
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

void NodeToInsert(Node*& root, Node* nodeToInsert)
{
    // TODO

    if (root == nullptr)
    {
        root = nodeToInsert;
    }
    if (nodeToInsert->value > root->value)
    {
        NodeToInsert(root->right, nodeToInsert);
    }
    if (nodeToInsert->value <= root->value)
    {
        NodeToInsert(root->left, nodeToInsert);
    }
}

void Remove(Node* root, Node* nodeToRemove)
{
    // TODO
    Node* parent = nullptr;
    
}

//int Height(Node* n)
//{
//    // TODO
//}
//
//int Depth(Node* root, Node* n)
//{
//    // TODO
//}
//
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

    Node root(6,
        new Node(4,
            new Node(2),
            new Node(5)),
        new Node(8,
            new Node(7),
            new Node(9)));

   // Node* test = NodeToInsert(&root, ;
    //NodeToInsert(&root,  new Node(10);
   
  


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