
//  Lesson12 - Cấu trúc dữ liệu hàng đợi: Queue
//  Created by Nhật Hoàng on 3/30/18.

#include <iostream>
#include <string.h>

#define QUEUE_SIZE 30

using namespace std;

struct Car
{
    char kindCar[30];
    char LiesenceCar[10];
};

Car queue[QUEUE_SIZE];
int front = 0, behind = -1;

bool IsFullArr()
{
    // behind ở vị trí cuối cùng
    return behind == (QUEUE_SIZE - 1);
}

bool IsEmptyArr()
{
    return front > behind;
}

void InsertElementInQueueArr(const char kindCarIns[], const char liesenceCarIns[])
{
    // Tăng behind lên 1 giá trị -> Copy giá trị vào vị trí behind
    if (!IsFullArr())
    {
        behind++;
        strcpy(queue[behind].kindCar, kindCarIns);
        strcpy(queue[behind].LiesenceCar, liesenceCarIns);
    }
}

Car DeleteElementInQueueArr()
{
    // Lấy giá trị trước vào một biến tạm
    // Xoá front khỏi hàng đợi
    // Trả về giá trị
    Car temp = queue[front];
    front++;
    return temp;
}

Car PeekArr()
{
    return queue[front];
}

#define SIZE_MATCH 5

int amount = 0;

bool IsFullMatch()
{
    return amount == SIZE_MATCH;
}
bool IsEmpty()
{
    return !amount; // If amount == 0 return true
}

void InsertQueue(const char kindCarIns[], const char liesenceCarIns[])
{
    if(!IsFullMatch())
    {
        amount++;
        behind++;
        if (behind == SIZE_MATCH)
        {
            behind = 0;
        }
        strcpy(queue[behind].kindCar, kindCarIns);
        strcpy(queue[behind].LiesenceCar, liesenceCarIns);
    }
}

Car DeleteQueue()
{
    Car temp = queue[front];
    amount--;
    front++;
    
    if(front == SIZE_MATCH)
    {
        front = 0;
    }
    return temp;
}

Car PeekQueue()
{
    return queue[front];
}

int main()
{
    
    
    return 0;
}


















