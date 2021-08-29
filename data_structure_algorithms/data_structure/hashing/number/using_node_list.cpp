// hash table number with list node

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "_library_hashing_number_.h"

// ------------ Node (for List Node) ------------ //
struct Node
{
	Data data;
	Node* pNext;
};
Node *CreateNode(Data data)
{
	Node* p = new Node;
	if (!p) {
		return NULL;
	}
	p->data = data;
	p->pNext = NULL;
	return p;
}

// ------------ List Node ------------ //
void Initialize(List &l) {
	l = NULL;
}
void AppendList(List &l, Data data)
{
	if (l == NULL)  {
		l = CreateNode(data);
	}
	else {
		Node *current = l;
		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = CreateNode(data);
	}
}
void DeleteNodeList(List &l, Data data) {
	Node *head = l;
	Node *prev = head;
	while (head != NULL) 
	{
		if (head->data == data) {
            if (head == l) {
				// delete head
				Node *p = l;
				l = l->pNext;
				p->pNext = NULL;
				delete p;
				head = l;
			}
            else {
                Node *g = head;
                Node *h = head->pNext;
                prev->pNext = h;
                g->pNext = NULL;
                delete g;
            }
        }
		prev = head;
		head = head->pNext;
	}
}
bool SearchNodeList(List l, Data data) {
	Node *head = l;
	while (head != NULL)
	{
		if (head->data == data) {
			return YES;
		}
		head = head->pNext;
	}
	return NO;
}
void OutputList(List l) {
	if (!l) {
		cout << "{NULLDATA}" << endl;
		return;
	}
	for (Node* head = l; head != NULL; head = head->pNext)
	{
		cout << head->data << " -> ";
	}
	cout << "NULL" << endl;
}

// ------------ Hash Table ------------ //
struct HashTable
{
	List *listHashTable;
	int size; // count all element exist
	int maxSize; // max Size
};
void Initialize(HashTable &ht)
{
	ht.listHashTable = new List[MAX];
	ht.maxSize = MAX;
	ht.size = 0;

	for (int i = 0; i < MAX; i++) {
		Initialize(ht.listHashTable[i]);
	}
}
void Initialize(HashTable &ht, int n)
{
	ht.listHashTable = new List[n];
	ht.maxSize = n;
	ht.size = 0;

	for (int i = 0; i < n; i++) {
		Initialize(ht.listHashTable[i]);
	}
}

// ------------ Hash Function ------------ //
// -- Hash function -- //
Index HashFunction_UseDivision(HashTable ht, Data data)
{
    Index hash;
    hash = data % ht.maxSize;
    return hash;
}
Index HashFunction_UseMidSquareNumber(HashTable ht, Data data) 
{
    // Data square = data * data;
    // Index maxSize = ht.maxSize;
    // Index digit = 0;
    // while (maxSize != 0)
    // {
    //     digit++;
    //     maxSize /= 10;
    // }


    
    // int a[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
    // int sqn = data * data, next_number = 0;
    // int t = (digit / 2);
    // sqn = sqn / a[t];

    // for (int i = 0; i < digit; i++) {
    //     next_number += (sqn % (a[t])) * (a[i]);
    //     sqn = sqn / 10;
    // }
    // return next_number;
}
Index HashFunction_UseFodingShift(HashTable ht, Data data) 
{
    Index i = 0;
    Index sub = 0;
    Data hash = 0;
    char *ptr = new char[MAX];
    itoa(data, ptr, 10);

    for (; *ptr; hash += sub)
    {
        for (i = 0, sub = 0; i < NSHIFT && *ptr; i++, ptr++)
        {
            sub = sub * 10 + *ptr;
        }
    }
    hash %= ht.maxSize;

    return hash;
}
Index HashFunction_UseMultiplicationGoldenRadio(HashTable ht, Data data)
{
    // Fibonaci hashing
    double hash = data * PHI - (Index)(data * PHI);
    hash *= ht.maxSize;

    return (Index)hash;
}
Index HashFunction_UseRotation(HashTable ht, Data data) 
{
    bool isNegative = data < 0;
    if (isNegative) {
        data = -data;
    }
    int digit = data % 10;
    data /= 10;
    while (digit < data) 
    {
        digit *= 10;
    }
    digit *= 10;
    data += digit;

    Index hash = isNegative ? -data : data;
    hash %= ht.maxSize;
    return hash;
}

// -- Hash check -- //
bool HashIsEmpty(HashTable ht) {
    Index size = ht.maxSize;
    for (Index i = 0; i < size; i++)
    {
        if (ht.listHashTable[i]) {
            return false;
        }
    }

    return true;
}
bool HashIsFull(HashTable ht) {
    return (ht.size >= ht.maxSize);
}

// -- Insert, search, delete & Collison -- //
// Direct chaining method - Using Linked List (Nối phần tử)
bool Insert_DirectChaining(HashTable &ht, Data data)
{
	// Check Full
    if (HashIsFull(ht)) {
		return false;
	}

	// Nối phần tử
	Index index = HashFunction_UseMultiplicationGoldenRadio(ht, data);
	AppendList(ht.listHashTable[index], data);
	ht.size++;
    return true;
}
bool Delete_DirectChaining(HashTable &ht, Data data) {
	// Check empty
    if (HashIsEmpty(ht)) {
		return false;
	}

	Index index = Search_DirectChaining(ht, data);
    if (index == NULLINDEX) {
        return false;
    }

	DeleteNodeList(ht.listHashTable[index], data);
	ht.size--;
	return true;
}
Index Search_DirectChaining(HashTable ht, Data data)
{
	// Check empty
    if (HashIsEmpty(ht)) {
        return NULLINDEX;
    }
	
	Index index;
	index = HashFunction_UseMultiplicationGoldenRadio(ht, data);
	
	if (SearchNodeList(ht.listHashTable[index], data)) {
		return index;
	}

	return NULLINDEX;
}

// -- Output -- //
void Output(HashTable ht) {
	Index size = ht.maxSize;
	for (int i = 0; i < size; i++)
	{
		cout << "List[" << i << "]: ";
		OutputList(ht.listHashTable[i]);
	}
}

// -- Menu -- //
void Menu(HashTable ht)
{
	while (true) {
        system("cls");
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Output\n";
        cout << "0. Exit\n\n";
		cout << "Your choose: ";
		char choose;
        cin >> choose;
        cin.ignore();
        system("cls");

		if (choose == '0') break;
        else if (choose == '1') {
            Data data;
            cout << "Enter value: ";
            cin >> data;
			if (Insert_DirectChaining(ht, data)) {
				cout << "Insert succesfully" << endl;
			}
			else {
				cout << "Hash table is full" << endl;
			}
		}
        else if (choose == '2') {
            Data data;
            cout << "Enter value: ";
            cin >> data;
            if (Delete_DirectChaining(ht, data)) {
                cout << "Delete successly!\n";
            }
            else {
                cout << "Erorr value!\n";
            }
        }
        else if (choose == '3') {
			Data data;
			cout << "Enter value: ";
			cin >> data;
            Index index = Search_DirectChaining(ht, data);
            if (index == NULLINDEX) {
                cout << "Not found x!" << endl;
            }
            else {
                cout << "Found x in list " << index << endl;
            }
		}
		else if (choose == '4') {
            cout << "Hash Table:\n";
            Output(ht);
		}
        else {
            cout << "Invalid\n";
        }
        system("pause");
    }
}

int main()
{
	HashTable ht;
	Initialize(ht, 10);
	Menu(ht);
	return 0;
}