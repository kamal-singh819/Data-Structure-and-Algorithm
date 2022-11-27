#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildBinaryTree(node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    root = new node(data);

    if (data == -1) // I'm assuming that if data is -1, node will be null
        return NULL;

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildBinaryTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}
//--------------Level Order Traversal--------------------------------------------------------
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level traverse ho chuka hai, isiliye temp NULL ho gya hai..
            cout << endl; // ek level traverse hone ke baad new line

            if (!q.empty()) // queue still has some child nodes
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

//--------------------Inorder Traversal------------------------------------

void inOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

//-------------------PreOrder Traversal------------------------------------

void preOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//--------------------Post Order Traversal---------------------------------

void postOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

//------------------------build a binary tree from its level order
/*  this is given--
                1
           2           3
        4    5      6    7
     -1 -1 -1 -1 -1 -1 -1 -1
*/

void buildFromLevelOreder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root : " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;

    // creating a Binary Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // buildFromLevelOreder(root);
    // levelOrderTraversal(root);

    root = buildBinaryTree(root);

    cout << endl
         << "Display Tree in level order : " << endl;
    levelOrderTraversal(root);

    cout << endl
         << "InOrder Traversal : ";
    inOrderTraversal(root);

    cout << endl
         << "PreOrder Traversal : ";
    preOrderTraversal(root);

    cout << endl
         << "PostOrder Traversal : ";
    postOrderTraversal(root);

    return 0;
}