// circu linked list

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "_library_linked_list_.h"

// ------------ Node ------------ //
struct Node
{
    Data data;
    Node *pNext;
    Node *pPrev;
};
Node *CreateNode(Data x)
{
    Node *p = new Node;
    if (!p)
    {
        cout << "Not enough memory to allocate\n";
        return 0;
    }
    p->data = x;
    p->pNext = p->pPrev = NULL;
    return p;
}
void SwapData(Node *ele1, Node *ele2)
{
    Data temp = ele1->data;
    ele1->data = ele2->data;
    ele2->data = temp;
}
void SwapAddress(Node *ele1, Node *ele2)
{
    if (ele1 == ele2)
    {
        return;
    }

    // Biến tạm
    Node *prev1 = ele1->pPrev;
    Node *next1 = ele1->pNext;
    Node *prev2 = ele2->pPrev;
    Node *next2 = ele2->pNext;

    // Đổi chỗ
    ele1->pNext = next2;
    if (next2)
        next2->pPrev = ele1;
    ele1->pPrev = prev2;
    if (prev2)
        prev2->pNext = ele1;

    ele2->pNext = next1;
    if (next1)
        next1->pPrev = ele2;
    ele2->pPrev = prev1;
    if (prev1)
        prev1->pNext = ele2;

    // prev1 = prev2 = next1 = next2 = NULL;
    // delete prev1;
    // delete prev2;
    // delete next1;
    // delete next2;
}

// ------------ Linked List ------------ //
struct LinkedList
{
    Node *pHead;
    Node *pTail;
};
void Initialize(LinkedList &l)
{
    l.pHead = l.pTail = NULL;
}
LinkedList Initialize(Node *pHead, Node *pTail)
{
    LinkedList l;
    Initialize(l);
    l.pHead = pHead;
    l.pTail = pTail;
    l.pTail->pNext = l.pHead;
    l.pHead->pPrev = l.pTail;
    return l;
}

// Add
void AddHead(LinkedList &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
    l.pHead->pPrev = l.pTail;
    l.pTail->pNext = l.pHead;
}
void AddTail(LinkedList &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
    l.pHead->pPrev = l.pTail;
    l.pTail->pNext = l.pHead;
}
bool AddAfterNodeDataQ(LinkedList &l, Data q, Node *p)
{
    bool haveInsert = false;
    Node *k = l.pHead;
    do
    {
        if (k->data == q)
        {
            haveInsert = true;
            if (k == l.pTail)
            {
                // Insert sau tail
                AddTail(l, p);
            }
            else
            {
                Node *h = CreateNode(p->data);
                Node *g = k->pNext;
                h->pNext = g;
                g->pPrev = h;
                k->pNext = h;
                h->pPrev = k;
            }
        }
        k = k->pNext;
    } while (k != l.pHead);

    return haveInsert;
}
bool AddInIndex(LinkedList &l, int index, Node *p)
{
    int length = LengthLinkedList(l);
    if (index >= length || index < 0)
    {
        return false;
    }

    if (index == 0)
    {
        AddHead(l, p);
    }
    else if (index == length - 1)
    {
        AddTail(l, p);
    }
    else
    {
        Node *k = l.pHead;
        for (int i = 0; i < index - 1; i++)
        {
            k = k->pNext;
        }
        Node *j = k->pNext;
        p->pNext = j;
        j->pPrev = p;
        k->pNext = p;
        p->pPrev = k;
    }

    return true;
}

// Delete
bool DeleteHead(LinkedList &l, Data &dataHead)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        dataHead = p->data;
        l.pHead = l.pHead->pNext;
        p->pNext = p->pPrev = NULL;
        delete p;
        if (l.pHead == NULL)
        {
            l.pTail = NULL;
        }
        l.pHead->pPrev = l.pTail;
        l.pTail->pNext = l.pHead;
        return true;
    }
    return false;
}
bool DeleteTail(LinkedList &l, Data &dataTail)
{
    if (l.pHead != NULL)
    {
        if (l.pHead == l.pTail)
        {
            DeleteHead(l, dataTail);
        }
        else
        {
            Node *p = l.pTail;
            dataTail = p->data;
            l.pTail = l.pTail->pPrev;
            l.pTail->pNext = NULL;
            p->pPrev = NULL;
            l.pHead->pPrev = l.pTail;
            l.pTail->pNext = l.pHead;
            delete p;
        }
        return true;
    }
    return false;
}
bool DeleteNodeData(LinkedList &l, Data data)
{
    bool haveDelete = false;
    Node *k = l.pHead;

    // Xóa tất cả các Node có data phía đầu head
    while (k->data == data)
    {
        haveDelete = true;
        Data x;
        DeleteHead(l, x);
    }

    // Xóa tiếp các phần tử sau head
    k = l.pHead;
    do
    {
        if (k->data == data)
        {
            haveDelete = true;
            if (k == l.pHead)
            {
                Data x;
                DeleteHead(l, x);
                k = l.pHead;
            }
            else if (k == l.pTail)
            {
                Data x;
                DeleteTail(l, x);
                k = l.pTail;
            }
            else
            {
                k = k->pPrev;
                Node *g = k->pNext;
                Node *h = g->pNext;
                k->pNext = h;
                h->pPrev = k;
                g->pNext = g->pPrev = NULL;
                delete g;
            }
        }
        k = k->pNext;
    } while (k != l.pHead);

    return haveDelete;
}
bool DeleteNodeIndex(LinkedList &l, int index, Data &dataDelete)
{
    int length = LengthLinkedList(l);
    if (index >= length || index < 0)
    {
        return false;
    }

    if (index == 0)
    {
        DeleteHead(l, dataDelete);
    }
    else if (index == length - 1)
    {
        DeleteTail(l, dataDelete);
    }
    else
    {
        int i = 0;
        Node *k = l.pHead;
        while (i != index - 1)
        {
            k = k->pNext;
            i++;
        }
        Node *q = k->pNext;
        Node *h = q->pNext;
        dataDelete = q->data;
        k->pNext = h;
        h->pPrev = k;
        q->pNext = q->pPrev = NULL;
        delete q;
    }
    return true;
}
void ClearList(LinkedList &l)
{
    int lenght = LengthLinkedList(l);
    for (int i = 0; i < lenght; i++)
    {
        Data x;
        DeleteHead(l, x);
    }
    l.pTail = NULL;
}

// Reverse
void ReverseLinkedList(LinkedList &l)
{
    // Swap head và tail
    SwapData(l.pHead, l.pTail);

    Node *head = l.pHead->pNext;
    Node *tail = l.pTail->pPrev;

    // Lặp các phần tử còn lại
    while (head != tail || head->pNext == tail)
    {
        Node *headNext = head->pNext;
        Node *tailPrev = tail->pPrev;
        SwapAddress(head, tail);
        head = headNext;
        tail = tailPrev;
    }
}

// Search
int SearchLinkedList(LinkedList l, Data dataSearch)
{
    if (l.pHead->data == dataSearch)
    {
        return 0;
    }

    int i = 1;
    for (Node *k = l.pHead->pNext; k != l.pHead; k = k->pNext)
    {
        if (k->data == dataSearch)
        {
            return i;
        }
        i++;
    }
    return NULLINDEX;
}

// Access
Node *AccessLinkedList(LinkedList l, int index)
{
    int length = LengthLinkedList(l);

    if (index >= length || index < 0)
    {
        return NULL;
    }

    if (index == 0)
    {
        return l.pHead;
    }

    int i = 1;
    Node *k = l.pHead->pNext;
    while (k != l.pHead && i != index)
    {
        i++;
        k = k->pNext;
    }

    return k;
}

// Length
int LengthLinkedList(LinkedList l)
{
    if (l.pHead == NULL)
    {
        return 0;
    }
    int length = 0;
    Node *k = l.pHead;
    do
    {
        length++;
        k = k->pNext;
    } while (k != l.pHead);
    return length;
}

// Sort Linked List
void SortLinkedList(LinkedList &l)
{
    // Check empty list
    if (l.pHead == NULL)
    {
        return;
    }

    // Bubble Sort
    bool swapped;             // Check còn phần tử chưa đúng vị trí
    Node *k;                  // Biến chạy
    Node *nodeDone = l.pHead; // Biến đánh dấu
    do
    {
        k = l.pHead;
        swapped = false;
        // Lặp đến khi gặp phần tử đã đúng vị trí
        while (k->pNext != nodeDone)
        {
            if (k->data > k->pNext->data)
            {
                swapped = true;
                SwapData(k, k->pNext);
            }
            k = k->pNext;
        }
        nodeDone = k;
    } while (swapped);
}

// Display
void OutputLinkedList(LinkedList l)
{
    Node *k = l.pHead;
    if (!k)
    {
        cout << "NaN" << endl;
        return;
    }

    // Lượt đi
    cout << "pTail <- ";
    cout << k->data << " <-> ";
    k = k->pNext;
    for (; k != l.pHead; k = k->pNext)
    {
        cout << k->data;
        if (k != l.pTail)
        {
            cout << " <-> ";
        }
    }
    cout << " -> pHead" << endl;

    // Reverse
    cout << "pHead <- ";
    k = l.pTail;
    cout << k->data << " <-> ";
    k = k->pPrev;
    for (; k != l.pTail; k = k->pPrev)
    {
        cout << k->data;
        if (k != l.pHead)
        {
            cout << " <-> ";
        }
    }
    cout << " -> pTail" << endl;
}

// Menu
void Menu(LinkedList &l)
{
    while (true)
    {
        system("cls");
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Reverse\n";
        cout << "4. Search\n";
        cout << "5. Access\n";
        cout << "6. Length\n";
        cout << "7. Sort\n";
        cout << "8. Display\n";
        cout << "0. Exit\n\n";
        cout << "Your choose: ";
        char choose;
        cin >> choose;
        cin.ignore();
        system("cls");

        if (choose == '8')
            break;
        else if (choose == '1')
        {
            while (true)
            {
                system("cls");
                cout << "1. Add head \n";
                cout << "2. Add tail\n";
                cout << "3. Add after node Q have {data}\n";
                cout << "4. Add in index\n";
                cout << "0. Exit\n\n";
                cout << "Your choose: ";
                char choose2;
                cin >> choose2;
                cin.ignore();
                system("cls");

                Data data;
                cout << "Enter value: ";
                cin >> data;
                Node *p = CreateNode(data);

                if (choose2 == '0')
                    break;
                else if (choose2 == '1')
                {
                    AddHead(l, p);
                }
                else if (choose2 == '2')
                {
                    AddTail(l, p);
                }
                else if (choose2 == '3')
                {
                    int index;
                    cout << "Enter index: ";
                    cin >> index;
                    if (!AddInIndex(l, index, p))
                    {
                        cout << "Error! Index invalid!\n";
                        delete p;
                    }
                }
                else if (choose2 == '4')
                {
                    Data q;
                    cout << "Enter data node Q: ";
                    cin >> q;
                    if (!AddAfterNodeDataQ(l, q, p))
                    {
                        cout << "Error! Data node q invalid!\n";
                        delete p;
                    }
                }
                else
                {
                    cout << "Invalid\n";
                }
                system("pause");
            }
        }
        else if (choose == '2')
        {
            while (true)
            {
                system("cls");
                cout << "1. Delete head \n";
                cout << "2. Delete tail\n";
                cout << "3. Delete node have data\n";
                cout << "4. Delete node have index\n";
                cout << "5. Clear List\n";
                cout << "0. Exit\n\n";
                cout << "Your choose: ";
                char choose2;
                cin >> choose2;
                cin.ignore();
                system("cls");

                string txtSuccess;
                Data dataDelete;
                bool success = true;

                if (choose2 == '0')
                    break;
                else if (choose2 == '1')
                {
                    txtSuccess = "head";
                    success = DeleteHead(l, dataDelete);
                }
                else if (choose2 == '2')
                {
                    txtSuccess = "tail";
                    success = DeleteTail(l, dataDelete);
                }
                else if (choose2 == '3')
                {
                    Data data;
                    cout << "Enter value delete: ";
                    cin >> data;
                    txtSuccess = "after node have data q";
                    success = DeleteNodeData(l, data);
                    dataDelete = data;
                }
                else if (choose2 == '4')
                {
                    int index;
                    cout << "Enter index: ";
                    cin >> index;
                    txtSuccess = "node index " + to_string(index);
                    success = DeleteNodeIndex(l, index, dataDelete);
                }
                else if (choose2 == '5')
                {
                    ClearList(l);
                    txtSuccess = "list";
                    success = true;
                    dataDelete = 0;
                }
                else
                {
                    cout << "Invalid\n";
                }

                if (success)
                {
                    cout << "Delete " << txtSuccess << " successly!"
                         << " Data delete: " << dataDelete << endl;
                }
                else
                {
                    cout << "Error! Invalid" << endl;
                }

                system("pause");
            }
        }
        else if (choose == '3')
        {
            ReverseLinkedList(l);
            cout << "Reverse succees!" << endl;
        }
        else if (choose == '4')
        {
            Data dataSearch;
            cout << "Enter value to search: ";
            cin >> dataSearch;
            int index = SearchLinkedList(l, dataSearch);
            if (index != NULLINDEX)
            {
                cout << "Found " << dataSearch << " ! Index: " << index << endl;
            }
            else
            {
                cout << "Not found " << dataSearch << endl;
            }
        }
        else if (choose == '5')
        {
            int index;
            cout << "Enter index to access: ";
            cin >> index;
            Node *node = AccessLinkedList(l, index);
            if (node == NULL)
            {
                cout << "Index invalid\n";
            }
            else
            {
                cout << "List[" << index << "] = " << node->data << endl;
            }
        }
        else if (choose == '6')
        {
            cout << "Length singly linked list: " << LengthLinkedList(l) << endl;
        }
        else if (choose == '7')
        {
            SortLinkedList(l);
            cout << "Sort successly!" << endl;
        }
        else if (choose == '8')
        {
            cout << "Linked list: ";
            OutputLinkedList(l);
        }
        else
        {
            cout << "Invalid\n";
        }
        system("pause");
    }
}

int main()
{
    LinkedList l;
    Initialize(l);
    // Menu(l);
    AddTail(l, CreateNode(1));
    AddTail(l, CreateNode(2));
    AddTail(l, CreateNode(3));
    AddTail(l, CreateNode(3));
    AddTail(l, CreateNode(5));
    AddTail(l, CreateNode(2));
    AddTail(l, CreateNode(1));

    SortLinkedList(l);

    OutputLinkedList(l);

    return 0;
}