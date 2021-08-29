// doubly linked list

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
}
bool AddAfterNodeDataQ(LinkedList &l, Data q, Node *p)
{
    bool haveInsert = false;
    for (Node *k = l.pHead; k != NULL; k = k->pNext)
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
    }
    return haveInsert;
}
bool AddInIndex(LinkedList &l, int index, Node *p)
{
    int lengthList = LengthLinkedList(l);
    if (index >= lengthList || index < 0)
    {
        return false;
    }

    if (index == 0)
    {
        AddHead(l, p);
    }
    else if (index == lengthList - 1)
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
            delete p;
        }
        return true;
    }
    return false;
}
bool DeleteNodeData(LinkedList &l, Data data)
{
    bool haveDelete = false;

    // Xóa tất cả các Node có data phía đầu head
    while (l.pHead->data == data)
    {
        haveDelete = true;
        Data x;
        DeleteHead(l, x);
    }

    // Vòng lặp bắt đầu từ Node thứ 2
    for (Node *k = l.pHead; k != NULL; k = k->pNext)
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
    }

    return haveDelete;
}
bool DeleteNodeIndex(LinkedList &l, int index, Data &dataDelete)
{
    int lengthList = LengthLinkedList(l);
    if (index >= lengthList || index < 0)
    {
        return false;
    }

    if (index == 0)
    {
        DeleteHead(l, dataDelete);
    }
    else if (index == lengthList - 1)
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
    int length = LengthLinkedList(l);
    for (int i = 0; i < length; i++)
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
    SwapAddress(l.pHead, l.pTail);
    Node *tail = l.pHead;
    l.pHead = l.pTail;
    l.pTail = tail;

    Node *head = l.pHead->pNext;
    tail = l.pTail->pPrev;

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
void ReverseLinkedList_UseRecursion(LinkedList &l)
{
    if (l.pHead == NULL || l.pHead->pNext == NULL)
    {
        return;
    }

    // Chia nhỏ bài toán bằng cách gọi đệ quy
    LinkedList newList = Initialize(l.pHead->pNext, l.pTail);
    ReverseLinkedList_UseRecursion(newList);

    // Tách head ra & chèn head ra sau
    l.pHead->pNext = NULL;
    newList.pTail->pNext = l.pHead;
    l.pHead->pPrev = newList.pTail;

    // Cập nhật tail & head
    l.pTail = l.pHead;
    l.pHead = newList.pHead;
}

// Search
int SearchLinkedList(LinkedList l, Data dataSearch)
{
    int i = 0;
    for (Node *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data == dataSearch)
        {
            return i;
        }
        i++;
    }
    return NULLINDEX;
}
int SearchLinkedList_UseRecursion(LinkedList l, int &i, Data dataSearch)
{
    if (l.pHead == NULL)
    {
        return NULLINDEX;
    }
    else if (l.pHead->data == dataSearch)
    {
        return i;
    }

    return SearchLinkedList_UseRecursion(Initialize(l.pHead->pNext, l.pTail), ++i, dataSearch);
}

// Access
Node *AccessLinkedList(LinkedList l, int index)
{
    int length = LengthLinkedList(l);

    if (index >= length || index < 0)
    {
        return NULL;
    }

    int i = 0;
    Node *k = l.pHead;
    while (k != NULL && i != index)
    {
        i++;
        k = k->pNext;
    }

    return k;
}

// Length
int LengthLinkedList(LinkedList l)
{
    int length = 0;
    for (Node *k = l.pHead; k != NULL; k = k->pNext)
    {
        length++;
    }
    return length;
}
int LengthLinkedList_UseRecursion(LinkedList l)
{
    if (!l.pHead)
    {
        return 0;
    }
    else
    {
        return 1 + LengthLinkedList_UseRecursion(Initialize(l.pHead->pNext, l.pTail));
    }
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
    bool swapped;          // Check còn phần tử chưa đúng vị trí
    Node *k;               // Biến chạy
    Node *nodeDone = NULL; // Biến đánh dấu
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
    cout << "NULL <- ";
    for (; k != NULL; k = k->pNext)
    {
        cout << k->data;
        if (k != l.pTail)
        {
            cout << " <-> ";
        }
    }
    cout << " -> NULL" << endl;

    // // Reverse
    // cout << "NULL <- ";
    // for (k = l.pTail; k != NULL; k = k->pPrev) {
    //     cout << k->data;
    //     if (k != l.pHead) {
    //         cout << " <-> ";
    //     }
    // }
    // cout << " -> NULL" << endl;
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
    Menu(l);
    return 0;
}