// hash table string with list node

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "_library_hashing_string_.h"

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
		cout << "'" << head->data << "'" << " -> ";
	}
	cout << "NULL" << endl;
}

// ------------ Hash Table ------------ //
struct HashTable
{
	List *listHashTable;
	int size; // count all element exist
	int maxSize; // max size
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

// ------------ Hash Function (for String) ------------ //
// -- Hash function -- //
Index HashFunction_String(HashTable ht, Data data) {
    Index length = data.length();
    Index hash = 0;
    for (Index i = 0; i < length; i++)
    {
        hash += data[i];
    }
    hash %= ht.maxSize;
    return hash;
}
Index HashFunction_UseFolding(HashTable ht, Data data) {
    Index hash = 0, mul = 1;
    for (int i = 0; i < data.length(); i++)
    {
        mul = (i % 4 == 0) ? 1 : mul * 256;
        hash += data.at(i) * mul;
    }

    // int intLength = data.length() / 4;
    // long hash = 0;

    // for (int j = 0; j < intLength; j++)
    // {
    //     string c = data.substr(j * 4, (j * 4) + 4);
    //     long mult = 1;
    //     for (int k = 0; k < c.length(); k++)
    //     {
    //         hash += c[k] * mult;
    //         mult *= 256;
    //     }
    // }

    // string c = data.substr(intLength * 4);
    // long mult = 1;
    // for (int k = 0; k < c.length(); k++)
    // {
    //     hash += c[k] * mult;
    //     mult *= 256;
    // }

    return ((Index)(hash)) % ht.maxSize;
}
Index HashFunction_UsePolynomialRolling(HashTable ht, Data data) {
    // P and M
    int p = 31;
    int m = 1e9 + 9;
    Index power_p = 1;
    Index hash = 0;
 
    for (Index i = 0; i < data.length(); i++) {
        hash = (hash + (data[i] - 'a' + 1) * power_p) % m;
        power_p = (power_p * p) % m;
    }
    return hash;
}
Index HashFunction_UsePrime31(HashTable ht, Data data) {
    Index hash = 0;
    Index length = data.length();
    for (Index i = 0; i < length; i++)
    {
        // '31' is best choice (is prime, no large, no small)
        // Tỉ lệ đụng độ thấp
        // Phân bố đều
        hash = hash * 31 + (lli)data[i];
    }

    hash %= ht.maxSize;
    if (hash < 0) {
        hash += ht.maxSize;
    }

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
	Index index = HashFunction_UsePrime31(ht, data);
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
	index = HashFunction_UsePrime31(ht, data);
	
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
            getline(cin, data);
            if (Insert_DirectChaining(ht, data)) {
                cout << "Insert successfully" << endl;
            }
            else {
                cout << "Hash table is full" << endl;
            }
		}
        else if (choose == '2') {
            Data data;
            cout << "Enter value: ";
            getline(cin, data);
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
            getline(cin, data);
            Index index = Search_DirectChaining(ht, data);
            if (index == NULLINDEX) {
                cout << "Not found x!" << endl;
            }
            else {
                cout << "Found x in " << index << endl;
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

int main() {
    HashTable ht;
    Initialize(ht, 10);
    Menu(ht);
    return 0;
}