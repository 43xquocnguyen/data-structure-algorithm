// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/  

#include <iostream>
using namespace std;   

struct Node
{
    int data;
    struct Node *link;
};

void _display(Node *q)
{
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}

// --- Solve 1 --- //
void _append(Node **p, int data)
{
    if (*p == NULL)
    {
        // *p = head
        *p = new Node;
        (*p)->data = data;
        (*p)->link = NULL;
    }
    else
    {
        Node *q = *p;
        while (q->link != NULL)
        {
            q = q->link;
        }
        Node *t = new Node;
        t->data = data;
        t->link = NULL;
        q->link = t;
    }
}
// --- Solve 1 --- //

// --- Solve 2 --- //
void _addatbeg(Node **p, int data)
{
    if (*p == NULL)
    {
        *p = new Node;
        (*p)->data = data;
        (*p)->link = NULL;
    }
    else
    {
        Node *t = new Node;
        t->link = *p;
        t->data = data;
        *p = t;
    }
}
// --- Solve 2 --- //

// --- Solve 3 --- //
void _addafter(Node *p, int i, int data)
{
    Node *t = new Node;
    t = p;
    while (i--)
    {
        if (t->link)
            t = t->link;
    }
    Node *pNew = new Node;
    pNew->data = data;
    pNew->link = NULL;
    if (t->link)
        pNew->link = t->link;
    t->link = pNew;
}
// --- Solve 3 --- //

// --- Solve 4 --- //
int _count(Node *p)
{
    int t = 0;
    while (p != NULL)
    {
        p = p->link;
        t++;
    }
    return t;
}
// --- Solve 4 --- //

// --- Solve 5 --- //
void _delete(Node **p, int d)
{
    Node *t = new Node;
    t = *p;
    while (t->link)
    {
        if (t->link->data == d)
        {
            Node *pDel = new Node;
            pDel = t->link;
            t->link = t->link->link;
            delete pDel;
        }
        else
        {
            t = t->link;
        }
    }
}
// --- Solve 5 --- //


// --- Solve 6 --- //
// my quick sort
Node *_get_tail(Node *q)
{
    while (q != NULL && q->link != NULL)
        q = q->link;
    return q;
}
Node *_quick_sort(Node *&head, Node *tail)
{
    if (head == tail) return head;
    Node *head1; // nho hon head
    Node *head2; // lon hon head
    Node *tag;
    head1 = head2 = NULL; // khoi tao
    tag = head;
    head = head->link; // tach head ra
    tag->link = NULL;

    while (head != NULL)
    {
        Node *p = head;
        head = head->link;
        p->link = NULL;

        if (p->data <= tag->data)
        {
            _addatbeg(&head1, p->data);
        }
        else _addatbeg(&head2, p->data);
    }

    head1 = _quick_sort(head1, _get_tail(head1));
    head2 = _quick_sort(head2, _get_tail(head2));

    if (head1) {
        head = head1;
        Node *k = _get_tail(head1);
        k->link = tag;
    }
    else {
        head = tag;
    }
    tag->link = head2;
    if (head2) {
        tail = _get_tail(head2);
    }
    else {
        tail = tag;
    }
    return head;
}
// example quick sort
Node *partition(Node *head, Node *tail, Node **newHead, Node **newTail)
{
    Node *pivot = tail;
    Node *prev = NULL, *cur = head, *end = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->link;
        }
        else
        {
            if (prev)
                prev->link = cur->link;

            Node *tmp = cur->link;
            cur->link = NULL;
            end->link = cur;
            end = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newTail) = end;

    return pivot;
}
Node *_quick_sort2(Node *head, Node *tail)
{
    if (!head || head == tail)
        return head;

    Node *newHead = NULL, *newTail = NULL;

    Node *pivot = partition(head, tail, &newHead, &newTail);

    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->link != pivot)
            tmp = tmp->link;

        tmp->link = NULL;

        newHead = _quick_sort2(newHead, tmp);

        tmp = _get_tail(newHead);
        tmp->link = pivot;
    }
    pivot->link = _quick_sort2(pivot->link, newTail);

    return newHead;
}
// teacher's quick sort
void _append(Node *&h, Node *&t, int data)
{
    Node *temp;
    temp = new Node;
    temp->data = data;
	temp->link = NULL;
    
	if (h == NULL && t == NULL)
	{
		h = temp;
		t = temp;
	}
	else
	{
		t->link = temp;
		t = temp;
	}
}
pair<Node*, Node*> _sort(Node *head, Node *tail)
{
	// Kiểm tra bài toán cơ sở của chia để trị
	if(head == tail)
		return make_pair(head, tail);

	// Tiến hành chia bài toán con ban đầu thành hai bài toán con nhỏ hơn: left và right
	int pivot_value = head->data;
	Node *left_head, *left_tail, *pivot_head, *pivot_tail, *right_head, *right_tail;
	left_head = left_tail = pivot_head = pivot_tail = right_head = right_tail = NULL;
	
	Node *p = head;

	// Chia bài toán con ban đầu thành left và right, và giữ lại các Node có data bằng pivot
	while(p != NULL)
	{
		if(p->data < pivot_value)
		{
			_append(left_head, left_tail, p->data);
		}
		else if (p->data == pivot_value)
		{
			_append(pivot_head, pivot_tail, p->data);
		}
		else if (p->data > pivot_value)
		{
			_append(right_head, right_tail, p->data);
		}

		Node* t = p;
		p = p->link;
		delete t;
	}

	// Giải các bài toán con
	pair<Node*, Node*> left_sorted = _sort(left_head, left_tail);
	pair<Node*, Node*> right_sorted = _sort(right_head, right_tail);

	// Tổng hợp bài toán con
	Node *head_sorted = pivot_head, *tail_sorted = pivot_tail;
	if(left_sorted.first != NULL)
	{
		head_sorted = left_sorted.first;
		left_sorted.second->link = pivot_head;
		tail_sorted = pivot_tail;
	}

	if(right_sorted.first != NULL)
	{
		tail_sorted->link = right_sorted.first;
		tail_sorted = right_sorted.second;
	}

	return make_pair(head_sorted, tail_sorted);
}
Node* _quick_sort3(Node *head, Node *tail)
{
	pair<Node*, Node*> result = _sort(head, tail);
	return result.first;
}
// --- Solve 6 --- //

// --- Solve 7 --- //
void _split(Node *head, Node **h1, Node **h2) {
    Node *p = head->link;
    Node *k = head;

    while (p)
    {
        p = p->link;
        if (p) {
            k = k->link;
            p = p->link;
        }
    }

    *h1 = head;
    *h2 = k->link;
    k->link = NULL;
}
Node *_merge(Node *h1, Node *h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    Node *res = NULL;

    if (h1->data <= h2->data) {
        res = h1;
        res->link = _merge(h1->link, h2);
    }
    else {
        res = h2;
        res->link = _merge(h1, h2->link);
    }
    return res;
}
void _merge_sort(Node **head)
{
    if ((*head) == NULL || (*head)->link == NULL) return;

    Node *newHead = (*head);
    Node *h1;
    Node *h2;

    _split(newHead, &h1, &h2);

    _merge_sort(&h1);
    _merge_sort(&h2);

    *head = _merge(h1, h2);
}
// --- Solve 7 --- //

int main()
{
    Node *head = NULL;

    // Solve 1
    _append(&head, 8);
    _append(&head, 1);
    _append(&head, -1);
    _append(&head, -8);
    _append(&head, 9);
    _append(&head, 3);
    _append(&head, 6);
    _append(&head, 2);
    cout << "After solve 1: ";
    _display(head);

    // Solve 2
    _addatbeg(&head, 10);
    _addatbeg(&head, 2);
    cout << "After solve 2: ";
    _display(head);

    // Solve 3
    _addafter(head, 5, 15);
    _addafter(head, 8, -10);
    cout << "After solve 3: ";
    _display(head);

    // Solve 4
    cout << "Solve 4, num element: " << _count(head);
    // Solve 4

    // Solve 5
    _delete(&head, 5);
    _delete(&head, 10);
    _delete(&head, 3);
    cout << "After solve 5: ";
    _display(head);
    // Solve 5

    // Solve 6 
    Node *tail = _get_tail(head);
    head = _quick_sort(head, tail);
    cout << "After solve 6: ";
    _display(head);

    _quick_sort2(head, tail);
    cout << "After solve 6 (quick sort 2): ";
    _display(head);

    _quick_sort3(head, tail);
    cout << "After solve 6 (quick sort 3): ";
    _display(head);
    // Solve 6 

    // Solve 7
    _merge_sort(&head);
    cout << "After solve 7: ";
    _display(head);
    // Solve 7

    return 0;
}
