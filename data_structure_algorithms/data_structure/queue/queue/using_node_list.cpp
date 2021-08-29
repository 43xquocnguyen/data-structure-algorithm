// queue with node list

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_queue_.h"

// ------------ Node ------------ //
struct Node
{
    Data data;
    Node *pNext;
};
Node *CreateNode(Data x)
{
    Node *p = new Node;
    if (p == NULL)
        return 0;
    p->data = x;
    p->pNext = NULL;
    return p;
}

// ------------ Queue ------------ //
// Initialize
struct Queue
{
    Node *pFront;
    Node *pRear;
    int numElements; // Đếm số pt có trong queue
    int maxElements; // Số lượng tối đa
};
void Initialize(Queue &q)
{
    q.pRear = q.pFront = NULL;
    q.numElements = 0;
    q.maxElements = MAX;
}
void Initialize(Queue &q, int n)
{
    q.pRear = q.pFront = NULL;
    q.numElements = 0;
    q.maxElements = n;
}

// Function Queue
// Check Queue
bool QueueIsEmpty(Queue q)
{
    return (q.pFront == NULL && q.pRear == NULL);
}
bool QueueIsFull(Queue q)
{
    return (q.numElements >= q.maxElements);
}
int SizeQueue(Queue q)
{
    return q.numElements;
}

// Font & enQueue & deQueue
Data FontQueue(Queue q)
{
    if (QueueIsEmpty(q))
    {
        return NULLDATA;
    }
    else
    {
        return q.pFront->data;
    }
}
bool EnQueue(Queue &q, Data data)
{
    Node *p = CreateNode(data);
    if (!p || QueueIsFull(q))
    {
        // Full phần tử hoặc p = NULL
        return false;
    }
    if (q.pRear == NULL)
    {
        // Rỗng
        q.pFront = q.pRear = p;
    }
    else
    {
        // Không rỗng
        q.pRear->pNext = p;
        q.pRear = p;
    }
    q.numElements++;
    return true;
}
bool DeQueue(Queue &q)
{
    if (QueueIsEmpty(q))
    {
        return false;
    }
    Node *p = q.pFront;
    q.pFront = q.pFront->pNext;
    p->pNext = NULL;
    delete p;
    q.numElements--;
    if (q.numElements == 0)
    {
        q.pFront = q.pRear = NULL;
    }
    return 1;
}

// Output
void OutputQueue(Queue q)
{
    for (Node *i = q.pFront; i != NULL; i = i->pNext)
    {
        cout << i->data << " -> ";
    }
    cout << "NULL";
}

// Menu
void Menu(Queue q)
{
    while (true)
    {
        system("cls");
        cout << "1. FoQueue\n";
        cout << "2. EnQueue\n";
        cout << "3. DeQueue\n";
        cout << "4. Output\n";
        cout << "5. DeQueue all\n";
        cout << "0. Exit\n\n";
        cout << "Your choose: ";
        char choose;
        cin >> choose;
        cin.ignore();
        system("cls");

        if (choose == '0')
            break;
        else if (choose == '1')
        {
            if (QueueIsEmpty(q))
            {
                cout << "Queue is empty!" << endl;
            }
            else
            {
                Data font = FontQueue(q);
                cout << "Font queue: " << font << endl;
            }
        }
        else if (choose == '2')
        {
            Data data;
            cout << "Enter value: ";
            cin >> data;
            EnQueue(q, data);
        }
        else if (choose == '3')
        {
            if (DeQueue(q))
            {
                cout << "DeQueue succesfully!\n";
            }
            else
            {
                cout << "Error! Queue is empty\n";
            }
        }
        else if (choose == '4')
        {
            cout << "Queue: ";
            OutputQueue(q);
        }
        else if (choose == '5')
        {
            int size = SizeQueue(q);
            if (QueueIsEmpty(q))
            {
                cout << "Error! Queue is empty!";
            }
            else
            {
                cout << "DeQueue all elements in queue: ";
            }
            for (int i = 0; i < size; i++)
            {
                Data font = FontQueue(q);
                cout << font << "  ";
                DeQueue(q);
            }
            cout << " End" << endl;
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
    Queue q;
    Initialize(q);
    Menu(q);
    return 0;
}