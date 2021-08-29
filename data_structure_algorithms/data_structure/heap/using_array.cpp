// // heap with array

// //  _       ____    __   _            _ __  
// // (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
// //  /(                 .-/     .-/          
// // (_)                (_/     (_/

// #include "_library_heap_.h"

// // ------------ Heap ------------ //
// // Initialize
// struct Heap
// {
//     Data *arrHeap;
//     bool *inserted;
//     int heightHeap; // height heap tree
//     int numElements;
//     int maxElements;
//     bool maxOrMin; // check heap max or min
// };
// void Initialize(Heap &heap) {
//     int maxElements = pow(2, (MAX + 1)) - 1; // number node in tree
//     heap.maxElements = maxElements;

//     heap.arrHeap = new Data[maxElements];
//     heap.inserted = new bool[maxElements];

//     for (int i = 0; i < maxElements; i++) {
//         heap.arrHeap[i] = INT_MAX;
//         heap.inserted[i] = false;
//     }

//     heap.heightHeap = MAX;
//     heap.numElements = 0;
//     heap.maxOrMin = true; // auto max heap
// }
// void Initialize(Heap &heap, int height, bool maxOrMin) {
//     int maxElements = pow(2, (height + 1)) - 1; // number node in tree
//     heap.maxElements = maxElements;

//     heap.arrHeap = new Data[maxElements];
//     heap.inserted = new bool[maxElements];

//     for (int i = 0; i < maxElements; i++) {
//         heap.arrHeap[i] = INT_MAX;
//         heap.inserted[i] = false;
//     }

//     heap.heightHeap = height;
//     heap.numElements = 0;
//     heap.maxOrMin = maxOrMin; // auto max heap
// }

// // Buil max heap
// void MaxHeapfity(Heap &heap, Index i)
// {
//     int size = SizeHeap(heap);
//     Index max = i;
//     Index childL = 2 * i + 1;
//     Index childR = 2 * i + 2;

//     if (childL < size && heap.arrHeap[childL] > heap.arrHeap[max])
//     {
//         max = childL;
//     }
//     if (childR < size && heap.arrHeap[childR] > heap.arrHeap[max])
//     {
//         max = childR;
//     }

//     if (max != i)
//     {
//         Swap(heap.arrHeap[i], heap.arrHeap[max]);
//         MaxHeapfity(heap, max);
//     }
// }
// void BuildHeap(Heap &heap)
// {
//     int size = SizeHeap(heap);
//     // i = size / 2 - 1 // Duyệt từ những node trong
//     for (Index i = size / 2 - 1; i >= 0; i--)
//     {
//         MaxHeapfity(heap, i);
//     }
// }

// // Function Heap
// // Check & Count In Heap
// bool HeapIsEmpty(Heap heap) {
//     return (heap.numElements == 0);
// }
// bool HeapIsFull(Heap heap) {
//     return (heap.numElements >= heap.maxElements);
// }
// int HeightHeap(Heap heap) {
//     return heap.heightHeap;
// }
// int SizeHeap(Heap heap) {
//     return heap.numElements;
// }

// // Insert, Extract, Delete
// bool Insert(Heap &heap, Data data) {
//     if (heap.numElements == heap.maxElements) {
//         return false;
//     }
//     heap.numElements++;
//     int i = heap.numElements - 1;
//     heap.data[i] = data;

//     while (i != 0 &&
//     ((heap.data[i] > heap.data[(i - 1) / 2]) && heap.maxOrMin == true) // điều kiện max heap
//     || 
//     ((heap.data[i] < heap.data[(i - 1) / 2]) && heap.maxOrMin == false) // điều kiện min heap
//     )
//     {
//         swap(heap.data[i], heap.data[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }
//     return true;
// }
// bool Extract(Heap &heap, Data &dataHeap) {
//     if (heap.numElements <= 0) {
//         dataHeap = INT_MAX;
//         return false;
//     }
//     else if (heap.numElements == 1) {
//         heap.numElements--;
//         dataHeap = heap.data[0];
//     }
//     else {
//         dataHeap = heap.data[0];
//         heap.data[0] = heap.data[heap.numElements - 1];
//         heap.numElements--;
//         Heapfity(heap, 0);

//         if 
//         (heap.data[1] > heap.data[0] && heap.maxOrMin == true // max heap
//         ||  heap.data[1] < heap.data[0] && heap.maxOrMin == false // min heap
//         ) 
//         {
//             swap(heap.data[1], heap.data[0]);
//         }
//     }
//     return true;
// }
// bool DeleteKey(Heap &heap, Data data) {
//     int i = SearchHeap(heap, data);
//     if (i == -1) {
//         return false;
//     }

//     heap.data[i] = (heap.maxOrMin == true) ? INT_MAX : INT_MIN;

//     while (i != 0 &&
//     ((heap.data[i] > heap.data[(i - 1) / 2]) && heap.maxOrMin == true) // điều kiện max heap
//     || 
//     ((heap.data[i] < heap.data[(i - 1) / 2]) && heap.maxOrMin == false) // điều kiện min heap
//     )
//     {
//         swap(heap.data[i], heap.data[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }

//     Extract(heap, i);

//     if 
//     (heap.data[1] > heap.data[0] && heap.maxOrMin == true // max heap
//     ||  heap.data[1] < heap.data[0] && heap.maxOrMin == false // min heap
//     ) 
//     {
//         swap(heap.data[1], heap.data[0]);
//     }

//     return true;
// }
// Index SearchTree(Heap heap, Data data) {
//     if (HeapIsEmpty(heap)) {
//         return NULLINDEX;
//     }
//     else {
//         int index = 0;
//         int height = 0;
//         int heightTree = heap.heightHeap;

//         while (height < heightTree)
//         {
//             if (data > heap.arrHeap[index]) {
//                 index = (index + 1) * 2;
//             }
//             else if (data < heap.arrHeap[index]) {
//                 index = (index + 1) * 2 - 1;
//             }
//             else if (heap.arrHeap[index] == data) {
//                 // found
//                 return index;
//             }
//             height++;
//         }

//     }
//     return NULLINDEX;
// }

// void Menu(Heap &heap)
// {
//     while (true)
//     {
//         system("cls");
//         cout << "1. Insert\n";
//         cout << "2. Extract\n";
//         cout << "3. Delete\n";
//         cout << "4. Print\n";
//         cout << "5. Exit\n\n";
//         cout << "Your choose: ";
//         char luachon;
//         cin >> luachon;
//         cin.ignore();
//         system("cls");

//         if (luachon == '5')
//             break;
//         else if (luachon == '1')
//         {
//             Data x;
//             cout << "Enter value: ";
//             cin >> x;
//             InsertHeap(heap, x);
//         }
//         else if (luachon == '2')
//         {
//             Data max;
//             if (Extract(heap, max)) {
//                 cout << "Extract: " << max << " success" << endl;
//             }
//             else {
//                 cout << "Heap is empty\n";
//             }
//         }
//         else if (luachon == '3')
//         {
//             int x;
//             cout << "Enter value: ";
//             cin >> x;
//             if (DeleteKey(heap, x)) {
//                 cout << "Delete succes\n";
//             }
//             else {
//                 cout << "Not found x or heap is empty\n";
//             }
//         }
//         else if (luachon == '4')
//         {
//             PrintHeap(heap);
//         }
//         else
//         {
//             cout << "Invalid\n";
//         }
//         system("pause");
//     }
// }

// int main() {
//     Heap heap;
//     Initialize(heap, 10, false);
//     Menu(heap);
//     return 0;
// }