// hash table number with array

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "_library_hashing_number_.h"

// ------------ HashTable ------------ //
struct HashTable
{
    Data *arr;
    TypeCheck *sta; // true: có | false: chưa
    int size;
    int maxSize;
};
void Initialize(HashTable &ht)
{
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
void Initialize(HashTable &ht, int n)
{
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

// ------------ Hash Function ------------ //
// -- Data hash function -- //
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
bool HashIsEmpty(HashTable ht)
{
    Index size = ht.maxSize;
    for (Index i = 0; i < size; i++)
    {
        if (ht.sta[i])
        {
            return false;
        }
    }

    return true;
}
bool HashIsFull(HashTable ht)
{
    return (ht.size >= ht.maxSize);
}

// -- Insert, search, delete & Hande collison -- //
// Linear probing method (Dò tuyến tính)
bool Insert_LinearProbing(HashTable &ht, Data data)
{
    // Check Full
    if (HashIsFull(ht))
    {
        return false;
    }

    Index index = HashFunction_UseMultiplicationGoldenRadio(ht, data);
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
bool Delete_LinearProbing(HashTable &ht, Data data)
{
    // Check empty
    if (HashIsEmpty(ht))
    {
        return false;
    }

    Index index = Search_LinearProbing(ht, data);
    if (index == NULLINDEX)
    {
        return false;
    }

    ht.arr[index] = NULLDATA;
    ht.sta[index] = NO;
    ht.size--;
    return true;
}
Index Search_LinearProbing(HashTable ht, Data dataSearch)
{
    // Check empty
    if (HashIsEmpty(ht))
    {
        return NULLINDEX;
    }

    Index index = HashFunction_UseMultiplicationGoldenRadio(ht, dataSearch);
    Index i = (index + 1) % ht.maxSize;

    while (ht.arr[index] != dataSearch && i != index)
    {
        // Dò tuyến tính
        i = (i + 1) % ht.maxSize;
    }

    if (ht.arr[i] == dataSearch)
    {
        return i;
    }
    return NULLINDEX;
}

// Quadratic probing method (Dò tuyến tính bậc 2)
bool Insert_QuadraticProbing(HashTable &ht, Data data)
{
    // Check Full
    if (HashIsFull(ht))
    {
        return false;
    }

    Index index = HashFunction_UseMultiplicationGoldenRadio(ht, data);
    int k = 1;
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
bool Delete_QuadraticProbing(HashTable &ht, Data data)
{
    // Check empty
    if (HashIsEmpty(ht))
    {
        return false;
    }

    Index index = Search_LinearProbing(ht, data);
    if (index == NULLINDEX)
    {
        return false;
    }

    ht.arr[index] = NULLDATA;
    ht.sta[index] = NO;
    ht.size--;
    return true;
}
Index Search_QuadraticProbing(HashTable ht, Data dataSearch)
{
    // Check empty
    if (HashIsEmpty(ht))
    {
        return NULLINDEX;
    }

    int k = 1;
    Index index = HashFunction_UseMultiplicationGoldenRadio(ht, dataSearch);
    Index i = (index + k * k) % ht.maxSize;
    while (ht.arr[index] != dataSearch && i != index)
    {
        // Dò tuyến tính bậc 2
        i = (i + k * k) % ht.maxSize;
    }

    if (ht.arr[i] == dataSearch)
    {
        return i;
    }
    return NULLINDEX;
}

// -- Output -- //
void Output(HashTable ht)
{
    Index size = ht.maxSize;
    for (Index i = 0; i < size; i++)
    {
        cout << "A[" << i << "]: ";
        if (ht.sta[i])
        {
            cout << ht.arr[i];
        }
        else
        {
            cout << "{NULLDATA}";
        }
        cout << endl;
    }
}

// -- Menu -- //
void Menu(HashTable ht)
{
    while (true)
    {
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

        if (choose == '0')
            break;
        else if (choose == '1')
        {
            Data data;
            cout << "Enter value: ";
            cin >> data;
            if (Insert_LinearProbing(ht, data)) {
                cout << "Insert succesfully" << endl;
            } 
            else {
                cout << "Hash table is full" << endl;
            }
        }
        else if (choose == '2')
        {
            Data data;
            cout << "Enter value: ";
            cin >> data;
            if (Delete_LinearProbing(ht, data))
            {
                cout << "Delete successly!\n";
            }
            else
            {
                cout << "Erorr value!\n";
            }
        }
        else if (choose == '3')
        {
            Data data;
            cout << "Enter value: ";
            cin >> data;
            Index index = Search_LinearProbing(ht, data);
            if (index == NULLINDEX)
            {
                cout << "Not found x!" << endl;
            }
            else
            {
                cout << "Found x in " << index << endl;
            }
        }
        else if (choose == '4')
        {
            cout << "Hash Table:\n";
            Output(ht);
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
    HashTable ht;
    Initialize(ht, 10);
    //Menu(ht);
    cout << HashFunction_UseFodingShift(ht, 123456) << endl;
    return 0;
}