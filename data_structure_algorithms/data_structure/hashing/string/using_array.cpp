// hash table string with array

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "_library_hashing_string_.h"

// ------------ HashTable ------------ //
struct HashTable
{
    Data *arr;
    TypeCheck *sta; // true: có | false: chưa
    int size;
    int maxSize;
};
void Initialize(HashTable &ht) {
    ht.arr = new Data[MAX];
    ht.sta = new TypeCheck[MAX];
    ht.maxSize = MAX;
    ht.size = 0;

    for (int i = 0; i < MAX; i++)
    {
        ht.arr[i] = NULLDATA;
        ht.sta[i] = NO;
    }
}
void Initialize(HashTable &ht, int n) {
    ht.arr = new Data[n];
    ht.sta = new TypeCheck[n];
    ht.maxSize = n;
    ht.size = 0;

    for (int i = 0; i < n; i++)
    {
        ht.arr[i] = NULLDATA;
        ht.sta[i] = NO;
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
        if (ht.sta[i]) {
            return false;
        }
    }

    return true;
}
bool HashIsFull(HashTable ht) {
    return (ht.size >= ht.maxSize);
}

// -- Insert, search, delete & Collison -- //
// Linear probing method (Dò tuyến tính)
bool Insert_LinearProbing(HashTable &ht, Data data) {
    // Check Full
    if (HashIsFull(ht)) {
        return false;
    }

    Index index = HashFunction_String(ht, data);
    while (ht.sta[index] != NO)
    {
        // Dò tuyến tính
        index = (index + 1) % ht.maxSize;
    }
    ht.arr[index] = data;
    ht.sta[index] = YES;
    ht.size++;
    return true;
}
bool Delete_LinearProbing(HashTable &ht, Data data) {
    // Check empty
    if (HashIsEmpty(ht)) {
        return false;
    }

    Index index = HashFunction_String(ht, data);
    if (index == NULLINDEX) {
        return false;
    }
    ht.arr[index] = NULLDATA;
    ht.sta[index] = NO;
    ht.size--;
    return true;
}
Index Search_LinearProbing(HashTable ht, Data dataSearch) {
    // Check empty
    if (HashIsEmpty(ht)) {
        return NULLINDEX;
    }

    Index index = HashFunction_String(ht, dataSearch);
    Index i = (index + 1) % ht.maxSize;

    while (ht.arr[index] != dataSearch && i != index)
    {
        // Dò tuyến tính
        i = (i + 1) % ht.maxSize;
    }

    if (ht.arr[i] == dataSearch) {
        return i;
    }
    return NULLINDEX;
}

// Quadratic probing method (Dò tuyến tính bậc 2)
bool Insert_QuadraticProbing(HashTable &ht, Data data) {
    // Check Full
    if (HashIsFull(ht)) {
        return false;
    }

    int k = 1;
    Index index = HashFunction_String(ht, data);
    while (ht.sta[index] != NO)
    {
        // Dò bậc 2 tuyến tính
        index = (index + k * k) % ht.maxSize;
        k++;
    }
    ht.arr[index] = data;
    ht.sta[index] = YES;
    ht.size++;
    return true;
}
bool Delete_QuadraticProbing(HashTable &ht, Data data) {
    // Check empty
    if (HashIsEmpty(ht)) {
        return false;
    }

    Index index = HashFunction_String(ht, data);
    if (index == NULLINDEX) {
        return false;
    }
    ht.arr[index] = NULLDATA;
    ht.sta[index] = NO;
    ht.size--;
    return true;
}
Index Search_QuadraticProbing(HashTable ht, Data dataSearch) {
    // Check empty
    if (HashIsEmpty(ht)) {
        return NULLINDEX;
    }

    int k = 1;
    Index index = HashFunction_String(ht, dataSearch);
    Index i = (index + k * k) % ht.maxSize;
    while (ht.arr[index] != dataSearch && i != index)
    {
        // Dò tuyến tính
        i = (i + k * k) % ht.maxSize;
    }

    if (ht.arr[i] == dataSearch) {
        return i;
    }
    return NULLINDEX;
}

// -- Output -- //
void Output(HashTable ht) {
    Index size = ht.maxSize;
    for (Index i = 0; i < size; i++)
    {
        cout << "S[" << i << "]: ";
        if (ht.sta[i]) {
            cout << ht.arr[i];
        }
        else {
            cout << "{NULLDATA}";
        }
        cout << endl;
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
            if (Insert_QuadraticProbing(ht, data)) {
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
            if (Delete_QuadraticProbing(ht, data)) {
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
            Index index = Search_QuadraticProbing(ht, data);
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