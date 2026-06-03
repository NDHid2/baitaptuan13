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

int main()
{
    int a[] = {2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004};

    int n = sizeof(a) / sizeof(a[0]);

    Node* BST = Initial_BST();

    for(int i = 0; i < n; i++) {add_node(BST, a[i]);}

    int namsinh;

    cout << "Nhap nam sinh can tim: ";
    cin >> namsinh;

    Node* p = search_BST(BST, namsinh);

    if(p == NULL)
        cout << "\n Khong tim thay sinh vien co nam sinh " << namsinh;
    else
        cout << "\n Tim thay sinh vien co nam sinh " << namsinh;

    return 0;
}


