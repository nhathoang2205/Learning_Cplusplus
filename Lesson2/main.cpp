
//  Lesson2: Array.
//  Created by Nhật Hoàng  on 3/10/18.


#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void ImportArray(int arr[], int &arrSize)
{
    // Nhập vào một số nguyên n, dùng hàm random() trong thư viện <cstdlib>
    // để nhập giá trị cho n phần tử trong mảng.
    cout << "Import number of array elements: " ;
    cin >> arrSize;
    srand((unsigned)time(NULL)); // Initialize random number generator
    
    for (int index = 0; index < arrSize; index++)
    {
        arr[index] =  rand( ); // random number in a - > b range.
    }
}

void SortArray(int arr[], int arrSize)
{
    // Sắp xếp mảng đó từ nhỏ đến lớn.
    for (int index1 = 0; index1 < arrSize - 1; index1++)
        for (int index2 = index1 + 1; index2 < arrSize; index2++)
        {
            if (arr[index1] < arr[index2])
            {
                int temp = arr[index1];
                arr[index1] = arr[index2];
                arr[index2] = temp;
            }
        }
}

void ExportArray(int arr[], int arrSize)
{
    // Xuất ra mảng sau khi sắp xếp.
    cout << "Random array after sort: ";
    for (int index = 0; index < arrSize; index++)
    {
        cout << "a[" << index << "] = " << arr[index] << " ";
    }
}

void FindElement(int arr[], int arrSize, int &numberToFind)
{
    // Nhập vào 1 số m, in ra vị trí điểm m trong mảng đó nếu có.
    cout << endl << "Import number need to be found: ";
    cin >> numberToFind;
    int numberLocation = - 1;
    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] == numberToFind)
        {
            cout << " Found number in array, position of " << numberToFind << " in array is: " << index;
            numberLocation = index;
        }
    }
    if (numberLocation == - 1)
    {
        cout << "Doesn't exist! ";
    }
}

int findFibonacciNumber(int inputNumber)
{
    if (inputNumber == 1 || inputNumber == 2)
    {
        return 1;
    }
    return (findFibonacciNumber(inputNumber - 2) + findFibonacciNumber(inputNumber - 1));
}

int main()
{
    int arr[100];
    int arrSize = 0; // number of array elements
    
    ImportArray(arr, arrSize);
    SortArray(arr, arrSize);
    ExportArray(arr, arrSize);
    
    int numberToFind = 0; // the element have to find in array
    FindElement(arr, arrSize, numberToFind);
    
    int inputNumber = 0;
    cout << endl << " Import fibonaci number: ";
    cin >> inputNumber;

    cout << "Fibonaci number: " << findFibonacciNumber(inputNumber);
    
    system("pause");
    return 0;
}
