// priority queue with array heap

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_queue_.h"

// ------------ Priority Queue ------------ //
// Initialize
struct Queue
{
    Data *arrQueue;
    PriorityType *arrPriority;
    Index pFont, pRear;
    int maxElements;
};
typedef Queue PriorityQueue;
void Initialize(PriorityQueue &q)
{
    q.arrQueue = new Data[MAX];
    q.arrPriority = new PriorityType[MAX];
    q.pFont = q.pRear = NULLINDEX;
    q.maxElements = MAX;
}
void Initialize(PriorityQueue &q, int n)
{
    q.arrQueue = new Data[n];
    q.arrPriority = new PriorityType[n];
    q.pFont = q.pRear = NULLINDEX;
    q.maxElements = n;
}

// Sử dụng Max Heap để biểu diễn Priority Queue
void MaxHeapfity(PriorityQueue &q, Index i)
{
    int size = SizeQueue(q);
    Index max = i;
    Index childL = 2 * i + 1;
    Index childR = 2 * i + 2;

    if (childL < size && q.arrPriority[childL] > q.arrPriority[max])
    {
        max = childL;
    }
    if (childR < size && q.arrPriority[childR] > q.arrPriority[max])
    {
        max = childR;
    }

    if (max != i)
    {
        Swap(q.arrQueue[i], q.arrQueue[max]);
        Swap(q.arrPriority[i], q.arrPriority[max]);
        MaxHeapfity(q, max);
    }
}
void BuildHeap(PriorityQueue &q)
{
    int size = SizeQueue(q);
    // i = size / 2 - 1 // Duyệt từ những node trong
    for (Index i = size / 2 - 1; i >= 0; i--)
    {
        MaxHeapfity(q, i);
    }
}

// Priority Queue Function
// Check
bool QueueIsEmpty(PriorityQueue q)
{
    return (q.pFont == NULLINDEX && q.pRear == NULLINDEX);
}
bool QueueIsFull(PriorityQueue q)
{
    return (q.pRear >= q.maxElements - 1);
}
int SizeQueue(PriorityQueue q)
{
    return (q.pRear + 1);
}

// Peek & enQueue & deQueue (Priority)
Data FontQueue(PriorityQueue q)
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
bool EnQueue(PriorityQueue &q, Data data, PriorityType prio)
{
    if (QueueIsFull(q))
    {
        return false;
    }
    if (QueueIsEmpty(q))
    {
        q.pFont++;
        q.pRear++;
        q.arrQueue[0] = data;
        q.arrPriority[0] = prio;
    }
    else
    {
        q.pRear++;
        q.arrQueue[q.pRear] = data;
        q.arrPriority[q.pRear] = prio;
        BuildHeap(q);
    }
    return true;
}
bool DeQueue(PriorityQueue &q)
{
    if (QueueIsEmpty(q))
    {
        return false;
    }
    Swap(q.arrQueue[0], q.arrQueue[q.pRear]);
    q.pRear--;
    BuildHeap(q);
    return true;
}

// Output
void OutputQueue(PriorityQueue q)
{
    int n = SizeQueue(q);
    for (int i = 0; i < n; i++)
    {
        cout << q.arrQueue[i] << " -> ";
    }
    cout << " NULL" << endl;
}

// Menu
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
            PriorityType prio;
            cout << "Enter value (priority is value): ";
            cin >> data;
            cout << "Enter priority: ";
            cin >> prio;
            EnQueue(q, data, prio);
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
    PriorityQueue q;
    Initialize(q);
    Menu(q);
    return 0;
}