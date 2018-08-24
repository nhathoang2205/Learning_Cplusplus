
//  Lesson9 - Cấu trúc dữ liệu và giải thuật: Simple Liked list
//  Created by Nhật Hoàng on 3/30/18.

// Simple Liked list: Only traverse elements forward

#include <iostream>
#include <string.h>

using namespace std;

struct StudentGr
{
    char nameSt[30];
    float scoreSt;
    // Cờ trỏ dến phần tử tiếp theo
    StudentGr *next;
};
// Biến này sẽ nằm đầu danh sách
StudentGr *head = NULL;

void TraverseGr()
{
    cout << "Traverse student group: " << endl;
    StudentGr *pointer = head;
    while (pointer)
    {
        cout << "Name: " << pointer->nameSt << " - Score: " << pointer->scoreSt << endl;
        pointer = pointer->next;
    }
}

void InsertStAtFirst(char nameInsSt[], float scoreAddSt)
{
    StudentGr *newSt = new StudentGr;
    
    // Gán giá trị cho cần thêm vào
    strcpy(newSt->nameSt, nameInsSt);
    newSt->scoreSt = scoreAddSt;
    newSt->next = NULL;
    
    cout << "Insert student at first of the group: ";
    cout << "Name: " << newSt->nameSt << " - Score: " << newSt->scoreSt << endl;
    
    // Kiểm tra xem mảng có giá trị nào hay chưa, nếu chưa có thì gán giá trị cần thêm vào vị trí đó
    if (!head)
    {
        head = newSt;
    }
    // Nếu mảng đã có giá tị, thì gán cờ next của giá trị mới vào head rồi gán head vào biến mới
    // => Phần tử mới thành biến đầu tiên
    else
    {
        newSt->next = head;
        head = newSt;
    }
}
    
void InsertAndOrderDescendingStByPoint(char nameInsSt[], float scoreAddSt)
{
    StudentGr *newSt = new StudentGr;
    
    strcpy(newSt->nameSt, nameInsSt);
    newSt->scoreSt = scoreAddSt;
    newSt->next = NULL;
    
    cout << "Insert descending: ";
    cout << "Name: " << newSt->nameSt << " - Score: " << newSt->scoreSt << endl;
    
    if (!head)
    {
        head = newSt;
    }
    else
    {
        // Tạo một con trỏ *p rồi gắn cho head
        StudentGr *pointer = head;
        // Chạy vòng lặp kiểm tra (có phần tử tiếp theo không) &&
        // (điểm của phần tử tiếp theo có lớn hơn điểm của phần tử cần thêm vào hay không)
        while ((pointer->next) && (pointer->next->scoreSt > scoreAddSt))
        {
            pointer = pointer->next;
        }
        // Nếu (con trỏ đang ở vị trí đầu) && (điểm vị trí đó thấp hơn điểm phần tử cần thêm vào)
        if((head == pointer) && (head->scoreSt < newSt->scoreSt))
        {
            newSt->next = head;
            head = newSt;
        }
        else
        {
            newSt->next = pointer->next;
            pointer->next = newSt;
        }
    }
    
}

void DeleteSt(char nameDelSt[])
{
    StudentGr *pointer = head, *before = NULL;
    
    // Kiểm tra xem con trỏ có đứng đầu dãy hay không &&
    // So sánh tên ở vị trí con trỏ đang trỏ đến với tên của phần tử cần xoá có giống nhau hay không
    while (pointer && (strcmp(pointer->nameSt, nameDelSt) != 0))
    {
        before = pointer;
        pointer = pointer->next;
    }
    if (pointer)
    {
        if (before)
        {
            before->next = pointer->next;
            pointer->next = NULL;
        }
        else
        {
            head = pointer->next;
            pointer->next = NULL;
            cout << "Delete student: ";
            cout << "Name: " << pointer->nameSt << " - Score: " << pointer->scoreSt << endl;
            delete pointer;
            pointer = NULL;
        }
    }
    else
    {
        cout << "Not found! ";
    }
}

float SearchByName(char nameSearchSt[])
{
    StudentGr *pointer = head;
    
    while (pointer && (strcmp(pointer->nameSt, nameSearchSt) != 0))
    {
        pointer = pointer->next;
    }
    if (pointer)
    {
        cout << "Search by name: " << nameSearchSt << " - Score: " << pointer->scoreSt << endl;
        return pointer->scoreSt;
    }
    else
    {
        cout << "Not found! ";
        return -1;
    }
}

bool UpdateSt(char nameUpdateSt[], float scoreUpdateSt)
{
    StudentGr *pointer = head;
    
    while (pointer && (strcmp(pointer->nameSt, nameUpdateSt) != 0))
    {
        pointer = pointer->next;
    }
    if (pointer)
    {
        cout << "Update student score: " << nameUpdateSt << " from: " << pointer->scoreSt << " to " << pointer << endl;
        return true;
    }
    else
    {
        cout << "Not found! ";
        return false;
    }
}

int main()
{
    
    
    return 0;
}




















