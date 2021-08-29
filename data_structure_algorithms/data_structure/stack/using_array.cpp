// stack with array

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "_library_stack_.h"

// ------------ Stack ------------ //
// Initialize
struct Stack
{
    Data *arrStack;
    Index pTop;
    int maxElements;
};
void Initialize(Stack &s) {
    s.arrStack = new Data[MAX];
    s.pTop = -1;
    s.maxElements = MAX;
}
void Initialize(Stack &s, int n) {
    s.arrStack = new Data[n];
    s.pTop = -1;
    s.maxElements = n;
}

// Function Stack
// Check stack
bool StackIsEmpty(Stack s) {
    return (s.pTop <= -1);
}
bool StackIsFull(Stack s) {
    return (s.pTop >= s.maxElements - 1);
}
int SizeStack(Stack s) {
    return (s.pTop + 1);
}

// Peek & push & pop
Data PeekStack(Stack s) {
    if (StackIsEmpty(s)) {
        // return false;
        return NULLDATA;
    }
    else {
        return s.arrStack[s.pTop];
    }
}
bool PushStack(Stack &s, Data data) {
    if (StackIsFull(s)) {
        return false;
    }
    s.pTop++;
    s.arrStack[s.pTop] = data;
    return true;
}
bool PopStack(Stack &s) {
    if (StackIsEmpty(s)) {
        return false;
    }
    s.pTop--;
    return true;
}

// Output stack
void OutputStack(Stack s) {
    int n = SizeStack(s);
    for (int i = n - 1; i >= 0; i--)
    {
        cout << s.arrStack[i] << " -> ";
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

        if (choose == '0') break;
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
    Initialize(s);
    Menu(s);
    return 0;
}