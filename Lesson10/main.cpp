
//  Lesson10 - Danh sách liên kết đôi: Doubly Liked list
//  Created by Nhật Hoàng on 3/30/18.

// Doubly Linked list: Tương tự Simple Linked list nhưng theo 2 chiều, trước và sau

#include <iostream>
#include <string.h>

using namespace std;

struct StudentGr
{
    char nameSt[30];
    float scoreSt;
    
    StudentGr *next;
    StudentGr *prev;
};

StudentGr *first = NULL, *last = NULL;

void TraverseLastGr()
{
    cout << "Traverse last! " << endl;
    StudentGr *pointer = last;
    
    while (pointer)
    {
        cout << "Name: " << pointer->nameSt << " - Score: " << pointer->scoreSt << endl;
        pointer = pointer->prev;
    }
}

void InsertStAtFirst(char nameInsSt[], float scoreInsSt)
{
    StudentGr *newSt = new StudentGr;
    
    strcpy(newSt->nameSt, nameInsSt);
    newSt->scoreSt = scoreInsSt;
    newSt->next = NULL;
    newSt->prev = NULL;
    
    cout << "Insert student at first: ";
    cout << "Name: " << newSt->nameSt << " - Score: " << newSt->scoreSt << endl;
    if (!last)
    {
        last = newSt;
    }
    if(first)
    {
        first = newSt;
    }
    else
    {
        newSt->next = first;
        first->prev = newSt;
        first = newSt;
    }
}

void InsertStAtLast(char nameInsSt[], float scoreInsSt)
{
    StudentGr *newSt = new StudentGr;
    
    strcpy(newSt->nameSt, nameInsSt);
    newSt->scoreSt = scoreInsSt;
    newSt->next = NULL;
    newSt->prev = NULL;
    
    cout << "Insert student at last: ";
    cout << "Name: " << newSt->nameSt << " - Score: " << newSt->scoreSt << endl;
    
    if(!first)
    {
        first = newSt;
    }
    if(!last)
    {
        last = newSt;
    }
    else
    {
        newSt->prev = last;
        last->next = newSt;
        last = newSt;
    }
}

void InsertAndOrderDescendingStByPoint(char nameInsSt[], float scoreInsSt)
{
    StudentGr *newSt = new StudentGr;
    
    strcpy(newSt->nameSt, nameInsSt);
    newSt->scoreSt = scoreInsSt;
    newSt->next = NULL;
    newSt->prev = NULL;
    
    cout << "Insert descending student: ";
    cout << "Name: " << newSt->nameSt << "- Score: " << newSt->scoreSt << endl;
    
    if (!first && !last)
    {
        first = newSt;
        last  = newSt;
    }
    else
    {
        StudentGr *pointer = first;
        while ((pointer) && (pointer->scoreSt > scoreInsSt))
        {
            pointer = pointer->next;
        }
        if ((first == pointer) && (first->scoreSt) <= newSt->scoreSt)
        {
            newSt->next = first;
            first->prev = newSt;
            first = newSt;
        }
        else if(((last == pointer) && (last->scoreSt >= newSt->scoreSt)) || !pointer)
        {
            newSt->prev = last;
            last->next = newSt;
            last = newSt;
        }
        else
        {
            newSt->next = pointer;
            pointer->prev->next = newSt;
            newSt->prev = pointer->prev;
            pointer->prev = newSt;
        }
    }
}

float SearchStFromFirst(char nameSearchSt[])
{
    StudentGr *pointer = first;
    
    while (pointer && (strcmp(pointer->nameSt, nameSearchSt) != 0))
    {
        pointer = pointer->next;
    }
    if(pointer)
    {
        cout << "Search: ";
        cout << "Name: " << nameSearchSt << " - Score: " << pointer->scoreSt << endl;
        return pointer->scoreSt;
    }
    else
    {
        cout << "Not found! ";
        return -1;
    }
}

float SearchStFormLast(char nameSearchSt[])
{
    StudentGr *pointer = last;
    
    while (pointer && (strcmp(pointer->nameSt, nameSearchSt) != 0))
    {
        pointer = pointer->prev;
    }
    if(pointer)
    {
        cout << "Search: ";
        cout << "Name: " << nameSearchSt << " - Score: " << pointer->scoreSt << endl;
        return pointer->scoreSt;
    }
    else
    {
        cout << "Not found! ";
        return -1;
    }
}

int main()
{
    return 0;
}
















