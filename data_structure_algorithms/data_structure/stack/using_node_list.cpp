// stack with node list

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "_library_stack_.h"

// ------------ Node ------------ //
struct Node {
    Data data;
    Node *pNext;
};
Node *CreateNode(Data data) {
    Node *p = new Node;
    if (p == NULL)
        return 0;
    p->data = data;
    p->pNext = NULL;
    return p;
}

// ------------ Stack ------------ //
// Initialize
struct Stack {
    Node *pTop;
    int numElements;
    int maxElements;
};
void Initialize(Stack &s) {
    s.pTop = NULL;
    s.numElements = 0;
    s.maxElements = MAX;
}
void Initialize(Stack &s, int n) {
    s.pTop = NULL;
    s.numElements = 0;
    s.maxElements = n;
}

// Function Stack
// Check stack
bool StackIsEmpty(Stack s) {
    return (s.pTop == NULL);
}
bool StackIsFull(Stack s) {
    return (s.numElements >= s.maxElements);
}
int SizeStack(Stack s) {
    return s.numElements;
}

// Peek & push & pop
Data PeekStack(Stack s) {
    if (StackIsEmpty(s)) {
        return NULLDATA;
    }
    else {
        return s.pTop->data;
    }
}
bool PushStack(Stack &s, Data data) {
    Node *p = CreateNode(data);
    if (!p || StackIsFull(s)) {
        return false;
    }
    if (!s.pTop) {
        s.pTop = p;
    }
    else {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    s.numElements++;
    return true;
}
bool PopStack(Stack &s) {
    if (StackIsEmpty(s)) {
        return false;
    }
    Node *p = s.pTop;
    s.pTop = s.pTop->pNext;
    s.numElements--;
    delete p;
    if (s.numElements == 0) {
        s.pTop = NULL;
    }
    return true;
}

// Output stack
void OutputStack(Stack s) {
    for (Node *k = s.pTop; k != NULL; k = k->pNext)
    {
        cout << k->data << " -> ";
    }
    cout << " NULL" << endl;
}

// Menu
void Menu(Stack s) {
    while (true) {
        system("cls");
        cout << "1. Peek\n";
        cout << "2. Push\n";
        cout << "3. Pop\n";
        cout << "4. Output\n";
        cout << "5. Pop all\n";
        cout << "0. Exit\n\n";
        cout << "Your choose: ";
        char choose;
        cin >> choose;
        cin.ignore();
        system("cls");

        if (choose == '0') ;
        else if (choose == '1') {
            if (StackIsEmpty(s)) {
                cout << "Stack is empty!" << endl;
            }
            else {
                Data top = PeekStack(s);
                cout << "Top stack: " << top << endl;
            }
        }
        else if (choose == '2') {
            Data data;
            cout << "Enter value: ";
            cin >> data;
            PushStack(s, data);
        }
        else if (choose == '3') {
            if (PopStack(s)) {
                cout << "Pop succesfully!\n";
            }
            else {
                cout << "Error! Stack is empty\n";
            }
        }
        else if (choose == '4') {
            cout << "Stack: ";
            OutputStack(s);
        }
        else if (choose == '5') {
            int size = SizeStack(s);
            if (StackIsEmpty(s)) {
                cout << "Error! Stack is empty!";
            }
            else {
                cout << "Pop all elements in stack: ";
            }
            for (int i = 0; i < size; i++)
            {
                Data top = PeekStack(s);
                cout << top << " -> ";
                PopStack(s);
            }
            cout << " End" << endl;
        }
        else {
            cout << "Invalid\n";
        }
        system("pause");
    }
}

int main() {
    Stack s;
    Initialize(s, 100);
    Menu(s);
    return 0;
}