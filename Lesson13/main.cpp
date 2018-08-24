
//  Lesson13: Lập trình hướng đối tượng
//  Created by Nhật Hoàng on 4/2/18.

#include <iostream>
#include <string.h>

using namespace std;

class Student
{
private:
    char *nameSt;
    float mark1, mark2, mark3;
public:
    float averageScore;
    Student(): nameSt(NULL), mark1(0)
    {
        mark2 = 0;
        mark3 = 0;
    };
    Student(char nameStCon[], float mark1, float mark2, float mark3);
    Student (Student &copySt)
    {
        ImportStName(copySt.nameSt);
        ImportStScore(copySt.mark1, copySt.mark2, copySt.mark3);
    }
    ~Student();
    void ImportStName(char []);
    void ImportStScore(float mark1, float mark2, float mark3);
    void ExportStInfo();
};

Student::Student(char nameStCon[], float mark1Con, float mark2Con, float mark3Con): nameSt(NULL), mark1(mark1Con), mark2(mark2Con), mark3(mark3Con)
{
    ImportStName(nameStCon);
}

Student::~Student()
{
    if (nameSt)
    {
        delete[] nameSt;
        nameSt = NULL;
    }
}

void Student::ImportStName(char nameStImport[])
{
    if (!this->nameSt)
    {
        this->nameSt = new char[30];
        strcpy(this->nameSt, nameStImport);
    }
}

void Student::ImportStScore(float mark1, float mark2, float mark3)
{
    this->mark1 = mark1;
    this->mark2 = mark2;
    this->mark3 = mark3;
}

void Student::ExportStInfo()
{
    cout << "Information: Student " << nameSt << " has mark: " << mark1 << ", " << mark2 << ", " << mark3 << endl;
}

int main()
{
    Student St[5], *pointer, NhatHoang;
    
    NhatHoang.ImportStName("Nhật Hoàng");
    NhatHoang.ImportStScore(9, 9, 9);
    NhatHoang.ExportStInfo();
    
    pointer = new Student("Nhật Minh", 8, 9, 10);
    pointer->ExportStInfo();
    delete pointer;
    
    return 0;
}





















