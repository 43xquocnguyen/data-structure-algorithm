// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/  

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int global_length;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int _get_height(Node *sr)
{
	if (!sr)
        return -1;
	return 1 + max(_get_height(sr->left), _get_height(sr->right));
}
void _display_subtree(Node *q, vector<string> & output, int left, int top, int width)
{
	string str = to_string(q->data);

	int left_begin_shift = 1 - (str.length()-1)/2;
	for (size_t i = 0; i < str.length() && left + width/2 + i < output[top].length(); i++)
		output[top][left + width/2 + left_begin_shift + i] = str[i];

	int branch_off_set = (width+3)/pow(2, 3);
	int mid = left + width/2;
	int left_mid = left + (width/2 - 1)/2;
	int right_mid = left + width/2 + 2 + (width/2 - 1)/2;

	if (q->left)
	{
		int branch_position = mid - branch_off_set + 1;
		for (int pos = mid + left_begin_shift - 2; pos > branch_position; pos--)
			output[top][pos] = '_';
		output[top+1][branch_position] = '/';
		for (int pos = branch_position-1; pos > left_mid + 2; pos--)
			output[top+1][pos] = '_';
		_display_subtree(q->left, output, left, top+2, width/2 - 1);
	}

	if (q->right)
	{
		int branch_position = mid + branch_off_set + 1;
		for (int pos = mid + left_begin_shift + str.length() + 1; pos < branch_position; pos++)
			output[top][pos] = '_';
		output[top+1][branch_position] = '\\';
		for (int pos = branch_position+1; pos < right_mid; pos++)
			output[top+1][pos] = '_';
		_display_subtree(q->right, output, left + width/2 + 2, top+2, width/2 - 1);
	}
}
void _display_tree(Node *root)
{
	if (!root) return;

	int height = _get_height(root);
    int width_display = 4 * pow(2, height) - 3;
    int height_display = 2 * height + 1;

    vector<string> output(height_display);
    for (size_t i = 0; i < output.size(); i++)
        output[i] = string(width_display + 4, ' ');

    _display_subtree(root, output, 0, 0, width_display);

	for (int row = 0; row < height_display; row++)
		cout << output[row] << endl;
}

// Solve 1 
void _insert(Node *&root, int data) {
    if (root == NULL) {
        Node *p = new Node;
        p->data = data;
        p->left = p->right = NULL;
        root = p;
    }
    else {
        if (data < root->data) {
            _insert(root->left, data);
        }
        else {
            _insert(root->right, data);
        }
    }
}
// Solve 1 

// Solve 2 
void _search(Node *root, int dataSearch, Node *&parent, Node *&x, bool &found) {
    if (!root) {
        found = false;
        return;
    }
    if (dataSearch == root->data) {
        x = root;
        found = true;
        return;
    }
    else if (dataSearch > root->data) {
        parent = root;
        _search(root->right,  dataSearch, parent, x, found);
    }
    else {
        parent = root;
        _search(root->left,  dataSearch, parent, x, found);
    }
}
// Solve 2

// Solve 3 
void _deleteNode2(Node *&nodeDelete, Node *&y) {
    if (y->left != NULL) {
        _deleteNode2(nodeDelete, y->left);
    }
    else {
        nodeDelete->data = y->data;
        nodeDelete = y;
        y = y->right;
    }
}
void _delete(Node *&root, int data) {
    if (!root) return;
    else {
        if (root->data > data) {
            _delete(root->left, data);
        }
        else if (root->data < data) {
            _delete(root->right, data);
        }
        else {
            Node *nodeDelete = root;
            if (root->left == NULL) {
                root = root->right;
            }
            else if (root->right == NULL) {
                root = root->left;
            }   
            else {
                Node *y = root->right;
                _deleteNode2(nodeDelete, y);
            }
            delete nodeDelete;
        }
    }
}
// Solve 3 

int main()
{
    // Solve 1
    Node *root = NULL;
    _insert(root, 5);
    _insert(root, 2);
    _insert(root, 6);
    _insert(root, 6);
    _insert(root, 7);
    _insert(root, 1);
    _insert(root, 4);
    cout << "After solve 1: ";
    _display_tree(root);
    // Solve 1
    
    // Solve 2
    bool found;
    Node *parent, *x;
    _display_tree(root);

    parent = x = NULL;
    _search(root, 13, parent, x, found);
    // Tìm kiếm Node có giá trị là 13
    // parent: parent Node của Node có giá trị là 13
    // x: Node có giá trị là 13
    // found: true nếu tìm thấy, false nếu tìm không thấy
    cout << "Result of the first query:" << endl;
    if (found)
    {
        if (parent)
            cout << "Data of Node which is parent of query Node: " << parent->data << endl;
        _display_tree(x);
    }
    else
        cout << "Not found" << endl;

    
    parent = x = NULL;
    _search(root, 18, parent, x, found);
    // Tìm kiếm Node có giá trị là 18
    // parent: parent Node của Node có giá trị là 18
    // x: Node có giá trị là 18
    // found: true nếu tìm thấy, false nếu tìm không thấy
    cout << "Result of the second query:" << endl;
    if (found)
        _display_tree(x);
    else
        cout << "Not found" << endl;

    // Solve 2

    // Solve 3
    cout << "Before delete:" << endl;
    _display_tree(root);

    _delete(root, 11);
    cout << "After delete Node 11:" << endl;
    _display_tree(root);

    _delete(root, 15);
    cout << "After delete Node 15:" << endl;
    _display_tree(root);

    _delete(root, 8);
    cout << "After delete Node 8:" << endl;
    _display_tree(root);

    _delete(root, 10);
    cout << "After delete Node 10:" << endl;
    _display_tree(root);
    // Solve 3

    return 0;
}