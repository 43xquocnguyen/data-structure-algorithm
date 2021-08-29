// #include <iostream>
// using namespace std;

// #define MAX 1000 // define 1000 phần tử
// typedef int Data;

// struct Node {
//     int data;
//     Node *pLeft;
//     Node *pRight;
// };
// Node *CreateNode(int x) {
//     Node *p = new Node;
//     if (p == NULL)
//         return 0;
//     p->data = x;
//     p->pLeft = p->pRight = NULL;
//     return p;
// }

// // Initialize
// typedef Node* Heap;
// void InitHeap(Heap &heap) {
//     heap = NULL;
// }
// void BuildHeap(Heap &heap) {

// }

// // Function Heap
// int SizeHeap(Heap heap) {
//     if (heap == NULL) {
//         return 0;
//     }
//     return 1 + SizeHeap(heap->pLeft) + SizeHeap(heap->pRight);
    
// }
// bool HeapIsFull(Heap heap) {
//     return (SizeHeap(heap) >= MAX);
// }
// bool HeapIsEmpty(Heap heap) {
//     return (heap == NULL);
// }
// bool Insert(Heap &heap, Node *p) {
//     if (!p || HeapIsFull(heap)) {
//         return false;
//     }
//     if (HeapIsEmpty(heap)) {
//         heap = p;
//     }
//     else {
//         if (SizeHeap(heap) == 1) {
//             if (heap->data < p->data) {
//                 p->pLeft = heap;
//                 heap = p;
//             }
//             else {
//                 heap->pLeft = p;
//             }
//         }
//         else {

//         }
//     }
//     return true;
// }
// bool Extract(Heap &heap) {
//     // remove root
//     if (HeapIsEmpty(heap)) {
//         return false;
//     }
//     return 1;
// }

// // Display format array
// void OutputAllUseRecursion(Heap heap)
// {
//     if (heap != NULL)
//     {
//         // node left right
//         cout << heap->data << "\t";
//         OutputAllUseRecursion(heap.);
//         OutputAllUseRecursion(heap->pRight);
//     }
// }

// void Menu(Heap &heap) {
//     while (true) {
//         system("cls");
//         cout << "1. Insert\n";
//         cout << "2. Root Heap\n";
//         cout << "3. Extract Root\n";
//         cout << "4. Extract All\n";
//         cout << "5. Exit\n\n";
//         cout << "Your choose: ";
//         char luachon;
//         cin >> luachon;
//         cin.ignore();
//         system("cls");

//         if (luachon == '5')
//             break;
//         else if (luachon == '1') {
//             int x, priority;
//             cout << "Enter value: ";
//             cin >> x;
//             Node *p = CreateNode(x);
//             Insert(heap, p);
//         }
//         else if (luachon == '2') {
//             Node *max = heap;
//             if (max) {
//                 cout << "Root: " << max->data << endl;
//             }
//             else {
//                 cout << "Error! Heap is empty!\n";
//             }
//         }
//         else if (luachon == '3') {
//             if (Extract(heap)) {
//                 cout << "Extract root heap succesfully!\n";
//             }
//             else {
//                 cout << "Error! Heap is empty\n";
//             }
//         }
//         else if (luachon == '4') {
//             int size = SizeHeap(heap);
//             if (HeapIsEmpty(heap)) {
//                 cout << "Error! Heap is empty!";
//             }
//             else {
//                 cout << "DeHeap all elements in Heap: ";
//             }
//             for (int i = 0; i < size; i++)
//             {
//                 Node *x = heap;
//                 cout << x->data << "  ";
//                 Extract(heap);
//             }
//             cout << endl;
//         }
//         else {
//             cout << "Invalid\n";
//         }
//         system("pause");
//     }
// }

// int main() {
//     Heap heap;
//     InitHeap(heap);
//     //Menu(heap);
//     Insert(heap, CreateNode(1));
//     Insert(heap, CreateNode(13));
//     return 0;
// }