
//  Lesson6
//  Created by Nhật Hoàng  on 3/20/18.

#include <iostream>
#include <cstdlib>

using namespace std;

int sumFunc1 (int num1, float num2)
{
    return num1 + num2;
}

float sumFunc2 (float num1, float num2)
{
    return num1 + num2;
}

double sumFunc3 (double num1, double num2)
{
    return num1 + num2;
}

int sumFuncArr(int arr[], int arrNum)
{
    int sumArr = 0;
    for (int index = 0; index < arrNum; index++)
    {
        sumArr += arr[index];
    }
    return sumArr;
}

int sumFuncPointer (const int *pointer1, int pointerNum)
{
    int sumPointer = 0;
    for (int index = 0; index < pointerNum; index++)
    {
        sumPointer += *(pointer1 + index);
    }
    return sumPointer;
}

int sumFuncArr2Way (int arr2Way[][3], int arrNum1, int arrNum2)
{
    int sumArr2Way = 0;
    for (int index1 = 0; index1 < arrNum1; index1++)
    {
        for (int index2 = 0; index2 < arrNum2;index2++)
        {
            sumArr2Way += arr2Way[index1][index2];
        }
    }
    return sumArr2Way;
}

int sumFuncPointer2Way (int (*pointer2Way)[3], int arrNum1, int arrNum2)
{
    int sumArr2Way = 0;
    for (int index1 = 0; index1 < arrNum1; index1++)
    {
        for (int index2 = 0; index2 < arrNum2;index2++)
        {
            sumArr2Way += pointer2Way[index1][index2];
        }
    }
    return sumArr2Way;
}


int sumFuncPointer2Way2 (const int *pointer1, int arrNum1, int arrNum2)
{
    int sumArr2Way = 0;
    for (int index1 = 0; index1 < arrNum1; index1++)
    {
        for (int index2 = 0; index2 < arrNum2;index2++)
        {
            int k = index1 * arrNum2 + index2;
            sumArr2Way += *(pointer1 + k);
        }
    }
    return sumArr2Way;
}

int *ImportElements(int numElements)
{
//    int arr[numElements];
    int *arr = new int[numElements]; // Cấp phát bộ nhớ động
    for (int index = 0; index < numElements; index++)
    {
        arr[index] = rand() % 10;
        cout << arr[index] << " ";
        cout << endl;
    }
    
    return arr;
}

int fibonaciFunc(int fiboNum)
{
    if (fiboNum == 1 || fiboNum == 2)
    {
        return 1;
    }
    else
    {
        int fn_2 = 1, fn_1 = 1, fn = 0, index = 2;
        while (index < fiboNum)
        {
            fn = fn_2 + fn_1;
            index++;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
}

void movePlate(char sourcePile, char endPile, char midPile, int numPile)
{
    if (numPile == 1)
    {
        cout << "Move plate 1 from " << sourcePile << " to " << endPile << endl;
    }
    else
    {
        movePlate(sourcePile, midPile, endPile, numPile - 1);
        cout << "Move plate" << numPile << " from " << sourcePile << " to " << endPile << endl;
        movePlate(midPile, endPile, sourcePile, numPile - 1);
    }
}

int main()
{
//    cout << "Sum 1 = " << sumFunc1 (2, 3) << endl;
//    cout << "Sum 2 = " << sumFunc2 (2.2f, 2.3f) << endl;
//
//    int arr[] = {1, 2, 3, 5, 8};
//    cout << "Sum array 1 = " << sumFuncArr (arr, 5) << endl;
//    cout << "Sum pointer 1 = " << sumFuncPointer (arr, 5) << endl;
//
//    int arr2Way[2][3] = {{1, 2, 3}, {5, 8, 3}};
//    cout << "Sum array 2 = " << sumFuncArr2Way (arr2Way, 2, 3) << endl;
//    cout << "Sum pointer 2 = " << sumFuncPointer2Way (arr2Way, 2, 3) << endl;
//    cout << "Sum pointer 2.1 = " << sumFuncPointer2Way2 ((int*)arr2Way, 2, 3) << endl;
    
//    int n, *p;
//    cout << "Import n: ";
//    cin >> n;
//    p = ImportElements(n);
//    for (int index = 0; index < n; index++)
//    {
//        cout << *(p + index) << endl;
//    }
//    delete[]p;
//    p = NULL;
    
//    int fiboNum;
//    cout << "Import fibonaci number: ";
//    cin >> fiboNum;
//    cout << "Fibonaci = " << fibonaciFunc(fiboNum);
    
//    movePlate('A', 'B', 'C', 2);
    
    
    
    return 0;
}

