/* Đề bài:
Yêu cầu đề bài:

===============================================================
200000 |                          |||  |||                  |
       |                          |||  |||                  |
       |                          |||  |||                  |
150000 |                          |||  |||                  |
       |                     |||  |||  |||                  |
       |                     |||  |||  |||                  |
100000 |                |||  |||  |||  |||  |||  |||        | 
       |                |||  |||  |||  |||  |||  |||        |
       |                |||  |||  |||  |||  |||  |||        |
 50000 |      |||  |||  |||  |||  |||  |||  |||  |||        |
       |      |||  |||  |||  |||  |||  |||  |||  |||        |
       | |||  |||  |||  |||  |||  |||  |||  |||  |||   |||  |
     0 | |||  |||  |||  |||  |||  |||  |||  |||  |||   |||	|                          
       |  1    2    3    4    5    6    7    8    9    10   |
===============================================================
 ===================== Dữ liệu thống kê =====================

Chúng ta sẽ có nhiệm vụ sắp xếp danh sách liên kết đơn, đặc điểm về mặt dữ liệu trong các
node sẽ là một con số thể hiện điểm thi trung bình trong kỳ thi đại học nào đó (có thể 
xem hình minh họa ở bên trên để nắm thông tin toàn cảnh về dữ liệu). Như vậy đối với bài
toán này, chúng ta sẽ thực hiện nhiệm vụ sắp xếp như trong Problem 27 và Problem 28. 
Câu hỏi ở đây là chúng ta sẽ sử dụng thuật toán nào, Quick Sort, Merge Sort hay một 
thuật toán nào khác để giải quyết dữ liệu có tính chất như bài tập này. Như vậy, trong 
bài tập này, các bạn được lựa chọn tự do thuật toán sắp xếp bất kỳ để giải quyết.

Tuy nhiên kích cỡ của dữ liệu điểm thi này lên đến 1 triệu phần tử,như vậy khi chúng ta
xuất kết quả sắp xếp ra màn hình sẽ vượt quá dung lượng cho phép của hệ thống WeCode.
Thay vào đó trong bài tập này, các bạn đã được cung cấp sẵn hàm in ra màn hình (_display),
cụ thể hàm này sẽ duyệt danh sách liên kết từ trái sang phải và tiến hành đếm số lượng
các giá trị điểm thi và xuất ra màn hình như mẫu bên dưới.

Lưu ý: Miền giá trị dữ liệu trong các node thuộc kiểu nguyên dương không vượt quá 10.

Nhắc lại: Bài tập này nhằm giúp các bạn sẽ có một số phân tích khác về hai thuật toán
sắp xếp Merge Sort và Quick Sort.

Đầu vào mẫu của chương trình như sau:

10
10 1 6 7 2 1 3 4 2 6

Đầu ra mẫu của chương trình như sau:

1 : 2
2 : 2
3 : 1
4 : 1
6 : 2
7 : 1
10 : 1
*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/     

#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

void _addatbeg(node **q, int num)
{
    node *temp;
    temp = new node;
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

void _display(node *q)
{
    int current_data = q->data;
    int current_data_freq = 0;
    while(q != NULL)
    {
        if(q->data == current_data)
            current_data_freq++;
        else
        {
            cout << current_data << " : " << current_data_freq << endl;
            current_data = q->data;
            current_data_freq = 1;
        }

        q = q->link;
    }

    cout << current_data << " : " << current_data_freq << endl;
}

struct DemDiem
{
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int eight = 0;
    int nine = 0;
    int ten = 0;

    int Set(int viTri, int value) {
        switch (viTri)
        {
            case 1: {
                return one += value;
            }
            case 2: {
                return two += value;
            }
            case 3: {
                return three += value;
            }
            case 4: {
                return four += value;
            }
            case 5: {
                return five += value;
            }
            case 6: {
                return six += value;
            }
            case 7: {
                return seven += value;
            }
            case 8: {
                return eight += value;
            }
            case 9: {
                return nine += value;
            }
            case 10: {
                return ten += value;
            }
        }
    }
};

node *_sort(node *head) {
    DemDiem dem;
    node *temp = head;
    while (temp)
    {
        dem.Set(temp->data, 1);
        temp = temp->link;
    }

    temp = head;
    
    while (dem.one--) {
        temp->data = 1;
        temp = temp->link;
    }   
    while (dem.two--) {
        temp->data = 2;
        temp = temp->link;
    }
    while (dem.three--) {
        temp->data = 3;
        temp = temp->link;
    }
    while (dem.four--) {
        temp->data = 4;
        temp = temp->link;
    }
    while (dem.five--) {
        temp->data = 5;
        temp = temp->link;
    }
    while (dem.six--) {
        temp->data = 6;
        temp = temp->link;
    }
    while (dem.seven--) {
        temp->data = 7;
        temp = temp->link;
    }
    while (dem.eight--) {
        temp->data = 8;
        temp = temp->link;
    }
    while (dem.nine--) {
        temp->data = 9;
        temp = temp->link;
    }
    while (dem.ten--) {
        temp->data = 10;
        temp = temp->link;
    }

    return head;
}

int main()
{
    node *head;

    head = NULL;

    int n, temp_val;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp_val;
        _addatbeg(&head, temp_val);
    }

    head = _sort(head);

    _display(head);

    return 0;
}