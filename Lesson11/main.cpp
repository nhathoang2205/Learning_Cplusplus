
//  Lesson11: Cấu trúc dữ liệu - Stack
//  Created by Nhật Hoàng on 3/30/18.

#include <iostream>
#include <string.h>

#define STACK_SIZE 10

using namespace std;

struct StudentGr
{
    char nameSt[30];
    float scoreSt;
    
    StudentGr *next;
};

StudentGr stack[STACK_SIZE];
int topStackArr = -1;

void PushArr(const char namePushSt[], float scorePushSt)
{
    // Tăng top lên 1 và gán giá trị vào
    topStackArr++;
    strcpy(stack[topStackArr].nameSt, namePushSt);
    stack[topStackArr].scoreSt = scorePushSt;

}

StudentGr PopArr()
{
    // Lấy giá trị tại top -> giảm top -> trả về
    StudentGr temp = stack[topStackArr];
    topStackArr--;
    return temp;
}

bool IsFullArr()
{
    // Kiểm tra có ở vị trí cuối cùng của mảng hay không
    return (topStackArr == STACK_SIZE - 1);
}

bool IsEmptyArr()
{
    return (topStackArr < 0);
}

StudentGr PeekArr()
{
    return stack[topStackArr];
}

//

StudentGr *topStackSLL = NULL; // SLL = Simple Liked list

bool IsFullSLL()
{
    return false;
}
bool IsEmptySLL()
{
    return !topStackSLL;
}

void PushSLL(const char namePushSt[], float scorePushSt)
{
    StudentGr *newSt = new StudentGr();
    
    strcpy(newSt->nameSt, namePushSt);
    newSt->scoreSt = scorePushSt;
    newSt->next = topStackSLL;
    topStackSLL = newSt;
}

StudentGr PopSLL()
{
    // Tạo ra biến tạm rồi lưu dữ liệu top vào, sau đó xoá top và trả về dữ liệu biến tạm
    StudentGr temp = *topStackSLL; // Gán giá trị nơi top trỏ đến cho temp
    StudentGr *pointer = topStackSLL; // Tạo con trỏ để lưu vị trí của top
    
    topStackSLL = topStackSLL->next; // Trỏ top đến vị trí tiếp theo
    delete pointer;
    return temp;
    
}

StudentGr Peek()
{
    return *topStackSLL;
}

int main()
{
    
    
    return 0;
}














