// queue with array

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_queue_.h"

// ------------ Queue ------------ //
// Initialize
struct Queue
{
    Data *arrQueue;
    Index pFont, pRear;
    int maxElements;
};
void Initialize(Queue &q)
{
    q.arrQueue = new Data[MAX];
    q.pFont = q.pRear = NULLINDEX;
    q.maxElements = MAX;
}
void Initialize(Queue &q, int n)
{
    q.arrQueue = new Data[n];
    q.pFont = q.pRear = NULLINDEX;
    q.maxElements = n;
}

// Queue Function
// Check
bool QueueIsEmpty(Queue q)
{
    return (q.pFont == NULLINDEX && q.pRear == NULLINDEX);
}
bool QueueIsFull(Queue q)
{
    return (q.pRear >= q.maxElements - 1);
}
int SizeQueue(Queue q)
{
    return (q.pRear + 1);
}

// Peek & enQueue & deQueue
Data FontQueue(Queue q)
{
    if (QueueIsEmpty(q))
    {
        // return false;
        return NULLDATA;
    }
    else
    {
        return q.arrQueue[q.pFont];
    }
}
bool EnQueue(Queue &q, Data p)
{
    if (QueueIsFull(q))
    {
        return false;
    }
    if (QueueIsEmpty(q))
    {
        q.pFont++;
        q.pRear++;
        q.arrQueue[q.pRear] = p;
    }
    else
    {
        q.pRear++;
        q.arrQueue[q.pRear] = p;
    }
    return true;
}
bool DeQueue(Queue &q)
{
    if (QueueIsEmpty(q))
    {
        return false;
    }
    for (int i = 1; i <= q.pRear; i++)
    {
        q.arrQueue[i - 1] = q.arrQueue[i];
    }
    q.pRear--;
    return true;
}

// Output
void OutputQueue(Queue q)
{
    int n = SizeQueue(q);
    for (int i = 0; i < n; i++)
    {
        cout << q.arrQueue[i] << " -> ";
    }
    cout << " NULL" << endl;
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