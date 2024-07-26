#include <iostream>
#include <stack>
using namespace std;

//Stack(LIFO: last in first out)
//push: đẩy 1 phần tử vào trong ngăn xếp
//pop: lấy 1 phần tử ra khỏi ngăn xếp
//top: lấy ra 1 tử ở đỉnh của ngăn xếp
//size
//empty

/*
Cho chuỗi S (ví dụ S=”ABCD”), hãy in ra màn hình chuỗi đảo ngược của chuỗi S (”DCBA”) bằng cách sử dụng cấu trúc ngăn xếp (stack). Hãy:
a) Định nghĩa cấu trúc dữ liệu biểu diễn ngăn xếp theo yêu cầu
b) Viết hàm in ra chuỗi đảo ngược của chuỗi S và các hàm khác có liên quan, sử dụng cấu trúc dữ liệu
*/

//a
struct Stack{
    int top;
    unsigned capacity; //Dung lượng tối đa của ngăn xếp
    string array;
};
//b
//Hàm tạo ngăn xếp mới có dung lượng capacity
Stack createStack(int capacity)
{
    Stack stack;
    stack.top = -1;
    stack.capacity = capacity;
    stack.array.resize(capacity);
    return stack;
}
//Kiểm tra ngăn xếp có đầy không
bool isFull(Stack &stack)
{
    return stack.top == stack.capacity - 1;
}
//Kiểm tra ngăn xếp có rỗng không
bool isEmpty(Stack & stack)
{
    return stack.top == -1;
}
//Thêm phần tử vào ngăn xếp
void push(Stack &stack, char c)
{
    if (isFull(stack)){
        return;
    }
    stack.array[++stack.top] = c;
}
//Lấy và xóa phần tử trên cùng của ngăn xếp
char pop(Stack &stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack.array[stack.top--];
}
//Hàm in ra chuỗi đảo ngược của chuỗi S
void printReverseString(const string &s)
{
    Stack stack = createStack(s.size());
    for (size_t i = 0; i < s.size(); i++)
    {
        push(stack, s[i]);
    }
    for (int i = stack.top; i >= 0; i--)
    {
        char c = pop(stack);
        cout << c;
    }
}