// priority queue with node list heap

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_queue_.h"

// ------------ Node ------------ //
struct Node
{
    Data data;
    int priority;
    Node *pNext;
};
Node *CreateNode(Data data, PriorityType priority)
{
    Node *p = new Node;
    if (p == NULL)
        return 0;
    p->data = data;
    p->priority = priority;
    p->pNext = NULL;
    return p;
}

// ------------ Queue ------------ //
// Initialize
struct Queue
{
    Node *pFront;
    Node *pRear;
    int numElements;
    int maxElements;
};
typedef Queue PriorityQueue;
void Initialize(PriorityQueue &q)
{
    q.pRear = q.pFront = NULL;
    q.numElements = 0;
    q.maxElements = MAX;
}
void Initialize(PriorityQueue &q, int n)
{
    q.pRear = q.pFront = NULL;
    q.numElements = 0;
    q.maxElements = n;
}

// Function Queue
// Check Queue
bool QueueIsEmpty(PriorityQueue q)
{
    return (q.pFront == NULL);
}
bool QueueIsFull(PriorityQueue q)
{
    return (q.numElements >= MAX);
}
int SizeQueue(PriorityQueue q)
{
    return q.numElements;
}

// Font & enQueue & deQueue
Data FontQueue(PriorityQueue q)
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
bool EnQueue(PriorityQueue &q, Data data, PriorityType priority)
{
    Node *p = CreateNode(data, priority);
    if (!p || QueueIsFull(q))
    {
        return false;
    }
    // rong
    if (QueueIsEmpty(q))
    {
        q.pFront = q.pRear = p;
    }
    else if (p->priority < q.pFront->priority)
    {
        // Thêm vào trước front, theo độ ưu tiên
        p->pNext = q.pFront;
        q.pFront = p;
    }
    else
    {
        Node *k = q.pFront;
        Node *prevK;
        while (k != NULL)
        {
            if (p->priority <= k->priority)
            {
                break;
            }
            prevK = k;
            k = k->pNext;
        }
        if (k == q.pFront)
        {
            p->pNext = q.pFront;
            q.pFront = p;
        }
        else
        {
            p->pNext = k;
            prevK->pNext = p;
            k = NULL;
            prevK = NULL;
            delete k;
            delete prevK;
        }
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
    q.numElements--;
    if (q.numElements == 0)
    {
        q.pFront = q.pRear = NULL;
    }
    delete p;
    return 1;
}

// Output
void OutputQueue(Queue q)
{
    for (Node *i = q.pFront; i != NULL; i = i->pNext)
    {
        cout << i->data << " -> ";
    }
    cout << "NULL" << endl;
}

void Menu(PriorityQueue q)
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
            int priority;
            cout << "Enter priority: ";
            cin >> priority;
            EnQueue(q, data, priority);
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
                Data data = FontQueue(q);
                cout << data << "  ";
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
    PriorityQueue q;
    Initialize(q);
    Menu(q);
    return 0;
}