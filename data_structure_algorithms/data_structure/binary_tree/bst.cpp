// binary search tree

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "_library_binary_tree_.h"

// ------------ Node ------------ //
struct Node
{
    Data data;
    Node *pLeft;
    Node *pRight;
};
Node *CreateNode(Data data) {
    Node *p = new Node;
    if (!p) {
        return NULL;
    }
    p->data = data;
    p->pRight = p->pLeft = NULL;
    return p;
}

// ------------ Tree ------------ //
void Initialize(Tree &t) {
    t = NULL;
}

// Function Tree
// Check & Count Tree
bool TreeIsEmpty(Tree t) {
    return (t == NULL);
} 
int HeightTree(Tree t) {
    if (t == NULL)
        return 0;
    return 1 + max(HeightTree(t->pLeft), HeightTree(t->pRight));
}
int HeightTree_UseQueue(Tree t) {
    if (t == NULL) {
        return 0;
    }

    queue<Node *> q;
    q.push(t);

    // Queue
    Node* front = NULL;
    int height = 0;
    while (!q.empty())
    {
        int size = q.size();
        
        while (size--)
        {
            front = q.front();
            q.pop();

            if (front->pLeft) {
                q.push(front->pLeft);
            }
 
            if (front->pRight) {
                q.push(front->pRight);
            }
        }
        height++;
    }
 
    return height;
}

// Max in Tree, diameter max in tree
int MaxInTree(Tree t) {
    if (t->pRight == NULL && t->pLeft == NULL) {
        return t->data;
    }

    int max = t->data;
    if (t->pRight != NULL) {
        int right = MaxInTree(t);
        if (right > max) {
            max = right;
        }
    }
    return max;
}
int Diameter(Tree t) {
    if (t == NULL) {
        return 0;
    }
 
    int leftHeight = HeightTree(t->pLeft);
    int rightHeight = HeightTree(t->pRight);
 
    int leftDiameter = Diameter(t->pLeft);
    int rightDiameter = Diameter(t->pRight);

    int diameter = max((leftHeight + rightHeight + 1), max(leftDiameter, rightDiameter));

    return diameter;
}

// Insert, Delete, Search
bool InsertTree(Tree &t, Data data) {
    if (t == NULL) {
        t = CreateNode(data);
    }
    else {
        if (t->data > data) {
            InsertTree(t->pLeft, data);
        }
        else if (t->data < data) {
            InsertTree(t->pRight, data);
        }
        else {
            return false;
        }
    }
    return true;
}
string SearchTree(Tree t, Data data) {
    if (t == NULL) {
        return NULLDATA;
    }
    else {
        string path = "";
        while (t != NULL)
        {
            if (data > t->data) {
                path += "R";
                t = t->pRight;
            }
            else if (data < t->data) {
                path += "L";
                t = t->pLeft;
            }
            else {
                return path;
            }
        }
    }
    return NULLDATA;
}
bool DeleteNodeTree(Tree &t, Data data) {
    // Tìm node
    Node *cur = t;
    Node *parent = nullptr;
    while (cur->data != data)
    {
        parent = cur;
        if (cur->data > data) {
            cur = cur->pLeft;
        }
        else {
            cur = cur->pRight;
        }

        if (cur == NULL) {
            return false;
        }
    }

    // Xóa
    // Xóa leafnode
    if (cur->pLeft == NULL && cur->pRight == NULL) {
        if (parent->pLeft == cur) {
            parent->pLeft = NULL;
        }
        else {
            parent->pRight = NULL;
        }
        cur = NULL; 
        delete cur;
    }
    // Xóa 1 con
    else if (cur->pLeft == NULL || cur->pRight == NULL) {
        Node *temp = NULL;
        if (cur->pLeft) {
            temp = cur->pLeft;
        }
        else {
            temp = cur->pRight;
        }

        if (parent->pLeft == cur) {
            parent->pLeft = temp;
        }
        else {
            parent->pRight = temp;
        }

        cur->pLeft = cur->pRight = NULL;
        delete cur;
    }
    // Xóa 2 con
    else {
        Node *temp = cur->pRight;
        Node *parentTemp = temp;
        while (temp->pLeft)
        {
            parentTemp = temp;
            temp = temp->pLeft;
        }
        cur->data = temp->data;
        
        if (parentTemp == temp) {
            cur->pRight = NULL;
        }

        temp = NULL;
        delete temp;
    }

    return true;
}

// Display output, default: N-L-R (Node left right)
void OutputRecursion(Tree t)
{
    if (t != NULL)
    {
        cout << t->data << "\t";
        OutputRecursion(t->pLeft);
        OutputRecursion(t->pRight);
    }
}
void OutputUseStack(Tree t) {
    stack<Node *> s;
    if (t != NULL) {
        s.push(t);
    }
    Node *p;
    while (!s.empty())
    {
        p = s.top();
        s.pop();
        cout << p->data << "\t";
        if (p->pRight != NULL) {
            s.push(p->pRight);
        }
        if (p->pLeft != NULL) {
            s.push(p->pLeft);
        }
    }
}   
void OutputUseQueue(Tree t) {
    queue<Node *> q;
    if (t != NULL)
    {
        q.push(t);
    }
    Node *p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->pRight)
        {
            q.push(p->pRight);
        }
        if (p->pLeft)
        {
            q.push(p->pLeft);
        }
        cout << p->data << "\t";
    }
}
void OutputNodeTwoChild(Tree t)
{
    // in node 2 con
    if (t != NULL)
    {
        if (t->pLeft && t->pRight) {
            cout << t->data << "\t";
        }
        OutputNodeTwoChild(t->pLeft);
        OutputNodeTwoChild(t->pRight);
    }
}
void OutputNodeOneChild(Tree t) {
    // in node 1 con
    if (t != NULL)
    {
        if ((t->pLeft && !t->pRight) || (!t->pLeft && t->pRight)) {
            cout << t->data << "\t";
        }
        OutputNodeOneChild(t->pLeft);
        OutputNodeOneChild(t->pRight);
    }
}
void OutputLeafNode(Tree t) {
    // in node lá
    if (t != NULL)
    {
        if ((!t->pLeft) && (!t->pRight))
        {
            cout << t->data << "\t";
        }
        OutputLeafNode(t->pLeft);
        OutputLeafNode(t->pRight);
    }
}

// Menu
void Menu(Tree t)
{
    while (true)
    {
        system("cls");
        cout << "=== BST ===\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Output\n";
        cout << "5. Diameter\n"; // Mức của cây
        cout << "6. Height\n";
        cout << "7. Max value\n";
        cout << "0. Exit\n\n";
        cout << "Your choose: ";
        char choose;
        cin >> choose;
        cin.ignore();
        system("cls");

        if (choose == '0') break;
        else if (choose == '1')
        {
            Data data;
            cout << "Enter value (unique): ";
            cin >> data;
            if (InsertTree(t, data)) {
                cout << "Insert successfully" << endl;
            } 
            else {
                cout << "Error! Value not unique!" << endl;
            }
        }
        else if (choose == '2')
        {
            Data data;
            cout << "Enter value: ";
            cin >> data;
            string path = SearchTree(t, data);
            if (path != NULLDATA) {
                cout << "Found x! Pos in: " << path << endl;
            }
            else {
                cout << "Not found x!\n";
            }
        }
        else if (choose == '3')
        {
            Data data;
            cout << "Enter value: ";
            cin >> data;
            if (DeleteNodeTree(t, data)) {
                cout << "Delete succeslly!\n";
            }
            else {
                cout << "Error! Not found x!\n";
            }
        }
        else if (choose == '4')
        {
            while (true)
            {
                system("cls");
                cout << "Format output: Node Left Right\n";
                cout << "1. Output all\n";
                cout << "2. Output node have two child\n";
                cout << "3. Output node have one child\n";
                cout << "4. Output node no have child\n";
                cout << "5. Display (Format Tree)\n";
                cout << "0. Exit\n\n";
                cout << "Your choose: ";
                char choose2;
                cin >> choose2;
                cin.ignore();
                system("cls");

                if (choose2 == '0')
                    break;
                else if (choose2 == '1')
                {
                    OutputRecursion(t);
                }
                else if (choose2 == '2')
                {
                    OutputNodeTwoChild(t);
                }
                else if (choose2 == '3')
                {
                    OutputNodeOneChild(t);
                }
                else if (choose2 == '4')
                {
                    OutputLeafNode(t);
                }
                else if (choose == '5') {
                    // DisplayTree(t);
                }
                else
                {
                    cout << "Invalid";
                }
                cout << endl;
                system("pause");
            }
        }
        else if (choose == '5') {
            // Mức của cây
            cout << "Diameter: " << Diameter(t) << endl;
        }
        else if (choose == '6') {
            cout << "Height: " << HeightTree(t) << endl;
        }
        else if (choose == '7') {
            cout << "Max value: " << MaxInTree(t) << endl;
        }
        else
        {
            cout << "Invalid\n";
        }
        system("pause");
    }
}

int main() {
    Tree t;
    Initialize(t);
    Menu(t);
    return 0;
}
