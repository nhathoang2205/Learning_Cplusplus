
//  Lesson7 - Struct
//  Created by Nhật Hoàng on 3/26/18.

#include <iostream>

using namespace std;

struct complexNum
{
    float realNum;
    float vitualNum;
};

struct inforStudent
{
    char nameStudent[30];
    int ageStudent;
    
    inforStudent *nextStudent;
};

void ImportNum(complexNum &inNum)
{
    cout << "Import interger numbers: ";
    cin >> inNum.realNum >> inNum.vitualNum;
}

void ExportNum(const complexNum &inNum)
{
    cout << inNum.realNum << " + " << inNum.vitualNum << "i" << endl;
}

complexNum Sum2Num(complexNum num1, complexNum num2)
{
    complexNum numSum;
    numSum.realNum = num1.realNum + num2.realNum;
    numSum.vitualNum = num1.vitualNum + num2.vitualNum;
    return numSum;
}

complexNum Sub2Num(complexNum *num1, complexNum *num2)
{
    complexNum numSub;
    numSub.realNum = num1->realNum - num2->realNum;
    numSub.vitualNum = (*num1).vitualNum - (*num2).vitualNum;
    return numSub;
}

complexNum *Mul2Num(complexNum num1, complexNum num2)
{
    complexNum *numMul = new complexNum;
    numMul->realNum = num1.realNum * num2.realNum - num1.vitualNum * num2.vitualNum;
    numMul->vitualNum = num1.realNum * num2.vitualNum + num1.vitualNum * num2.realNum;
    return numMul;
}

complexNum Div2Num(complexNum num2, complexNum num1)
{
    complexNum numDiv;
    float sumPow = num2.realNum * num2.realNum + num2.vitualNum + num2.vitualNum;
    numDiv.realNum = (num1.realNum * num2.realNum + num1.vitualNum * num2.vitualNum)/sumPow;
    numDiv.vitualNum = (num2.realNum * num1.vitualNum - num2.vitualNum * num1.realNum)/sumPow;
    return numDiv;

}

inforStudent *head = 0;

void importStudent(int numStudent)
{
    int isFirst = 1;
    inforStudent* currentStudent = nullptr;
    
    for (int index = 0; index < numStudent; index++)
    {
        inforStudent *importStudent = new inforStudent();
        cin.getline(importStudent->nameStudent, 30);
        cin >> importStudent->ageStudent;
        importStudent->nextStudent = 0;
        
        if (isFirst)
        {
            head = importStudent;
            isFirst = 0;
            currentStudent = importStudent;
        }
        else
        {
            currentStudent->nextStudent = importStudent;
            currentStudent = importStudent;
        }
    }
}

int main()
{
//    complexNum num1, num2;
//
//    ImportNum(num1);
//    ExportNum(num1);
//    ImportNum(num2);
//    ExportNum(num2);
    
//    complexNum numSum, numSub, *numMul, numDiv;
    
//    numSum = Sum2Num(num1, num2);
//    cout << "Summation 2 interger numbers = ";
//    ExportNum(numSum);
//
//    numSub = Sub2Num(&num1, &num2);
//    cout << "Subtraction 2 interger numbers = ";
//    ExportNum(numSub);
//
//    numMul = Mul2Num(num1, num2);
//    cout << "Multiplication 2 interger numbers = ";
//    ExportNum(*numMul);
//    delete numMul;
//    numMul = NULL;
//
//    numDiv = Div2Num(num1, num2);
//    cout << "Division 2 interger numbers = ";
//    ExportNum(numDiv);
    
//    complexNum comNum{1.0, 2.0}, comArr[10];
//
//    ImportNum(comArr[0]);
//    ExportNum(comArr[0]);
//
//    ImportNum(*(comArr + 1));
//    ExportNum(*(comArr + 1));
//    // & lấy giá trị của biến
//    // * là lấy giá trị của con trỏ hay lấy giá trị của một vùng nhớ
  

    return 0;
}

























