#include <iostream>
using namespace std;

struct Node
{
    int cha;
    Node* contrai;
    Node* conphai;
};

// dung cay np tim kiem BST
Node* Initial_BST()
{
    return NULL;
}

// them nut vao BST
void add_node(Node*& root, int a)
{
    if(root == NULL)
    {
        root = new Node;
        root->cha = a;
        root->contrai = NULL;
        root->conphai = NULL;
        return;
    }

    if(a <= root->cha)
        add_node(root->contrai, a);
    else
        add_node(root->conphai, a);
}

// tim kiem tren BST
Node* search_BST(Node* root, int a)
{
	if(root->cha == a)
        return root;
    if(root == NULL)
        return NULL;
    if(a <= root->cha)
        return search_BST(root->contrai, a);
    else
        return search_BST(root->conphai, a);
}

