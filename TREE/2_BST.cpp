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

node *insertIntoBST(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
        root->right = insertIntoBST(root->right, d);
    else if (d < root->data)
        root->left = insertIntoBST(root->left, d);
}

void inputData(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

//------------------------------------------------------------------------------------------
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
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
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

void inOrderTraversal(node *root) // Inorder of BST is always sorted..........
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

//******************************* Search in BST *****************************************
bool searchRecursiveWay(node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    if (root->data > x)
        searchRecursiveWay(root->left, x);
    else if (root->data < x)
        searchRecursiveWay(root->right, x);
}

bool searchIterativeWay(node *root, int x)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
            return true;
        else if (temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

int maximumInBST(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
        temp = temp->right;

    return temp->data;
}
int minimumInBST(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;

    return temp->data;
}
//***************************************Delete from BST**********************************
node *deleteFromBST(node *root, int val)
{
    if (root == NULL)
        return root;
    if (root->data == val)
    {
        // when leaf node############################
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // when only 1 child#########################
        ////left child---
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        ////right child---
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // when both the children are present#########
        /*we have two options-jis  node ko delete karna hai uske right subtree ki minimum value se node->data ko replace kar do
                             -jis  node ko delete karna hai uske left subtree ki mamimum value se node->data ko replace kar do*/
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minimumInBST(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else if (root->data < val)
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
int main()
{
    node *root = NULL;
    int value;

    // to take input
    cout << "Enter the data : "; // 25 20 36 10 22 30 40 5 12 28 38 48 -1
    inputData(root);

    cout << endl
         << "Level Order Traversal is : " << endl;
    levelOrderTraversal(root);

    cout << endl
         << "InOrder Traversal is : ";
    inOrderTraversal(root);

    // cout << endl
    //      << "Search in BST--------" << endl;
    // cout << "Enter a value to search : ";
    // cin >> value;
    // cout << endl
    //      << "Result is : " << searchRecursiveWay(root, value);

    // cout << endl
    //      << "Maximum Number is : " << maximumInBST(root);
    // cout << endl
    //      << "Minimum Number is : " << minimumInBST(root);
    int val;
    cout << endl
         << "Enter a value to delete : ";
    cin >> val;
    root = deleteFromBST(root, val);

    cout << endl
         << "InOrder Traversal is : ";
    inOrderTraversal(root);

    return 0;
}
