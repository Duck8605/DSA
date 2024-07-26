#include <iostream>
using namespace std;

//Khởi tạo List
struct Node
{
    int data;
    Node* next;
};
struct list
{
    Node* head;
    Node* tail;
};

//Thêm phần tử vào đầu và cuối List
bool isEmpty(list &l)
{
    return l.head == NULL;
}
Node *createNode(int data)
{
    Node* newNode = new Node(); 
    newNode->data = data;
}
void addHead(int data, list &l){
    if (isEmpty(l)){
        l.head = l.tail = createNode(data);
    }
    else {
        Node* tmp = createNode(data);
        tmp->next = l.head;
        l.head = tmp;
    }
}
void addTail(int data, list &l){
    if (isEmpty(l)){
        l.head = l.tail = createNode(data);
    }
    else {
        Node* tmp = createNode(data);
        l.tail->next = tmp;
        l.tail = tmp;
    }
}

//Xoá phần tử ở đầu và cuối List
void deleteHead(list &l){
    if (isEmpty(l)){
        return;
    }
    if (l.head == l.tail){
        delete l.head;
        l.head = l.tail = NULL;
    }
    else {
        Node* tmp = l.head;
        l.head = l.head->next;
        delete tmp;
    }
}
void deleteTail(list &l){
    if (isEmpty(l)){
        return;
    }
    if (l.head == l.tail){
        delete l.head;
        l.head = l.tail = NULL;
    }
    else {
        Node* tmp = l.head;
        while (tmp->next != l.tail){
            tmp = tmp->next;
        }
        delete l.tail;
        l.tail = tmp;
        l.tail->next = NULL;
    }
}

//Tìm kiếm dữ liệu trong List
Node* searchNode(int data, list l){
    Node* tmp = l.head;
    while (tmp != NULL){
        if (tmp->data == data){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

//Sắp xếp các phần tử trong List
void selectionSort(list &l){
    Node* tmp = l.head;
    while (tmp != NULL){
        Node *min = tmp;
        Node *r = tmp->next;
        while (r != NULL){
            if (r->data < min->data){
                min = r;
            }
            r = r->next;
        }
        swap(tmp->data, min->data);
        tmp = tmp->next;
    }
}