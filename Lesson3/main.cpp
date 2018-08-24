
// Lesson 3: Thuật toán tìm kiếm nhị phân - Binary search.
//  Created by Nhật Hoàng on 3/12/18.

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int arr[100];
    int index1, index2;
    int numberToFind;
    int midArray;
    int beginArray = 0, endArray = 100;
    int numberLocation = - 1;
    
    // Import elements to array
    for (index1 = 0; index1 < 100; index1++)
    {
        arr[index1] = rand() % 1000;
        cout << " " << arr[index1];
    }
    
    // Sort array form low to high
    for (index1 = 0; index1 < 100; index1++)
    {
        for (index2 = index1 + 1; index2 < 100; index2++)
        {
            if(arr[index1] > arr[index2])
            {
                arr[index1] = arr[index1] + arr[index2];
                arr[index2] = arr[index1] - arr[index2];
                arr[index1] = arr[index1] - arr[index2];
            }
        }
    }
    cout << "After sort \n";
    for (index1 = 0; index1 < 100; index1++)
    {
        cout << " " << arr[index1];
    }
    cout << endl;
    
    cout << "Number have to find = ";
    cin >> numberToFind;
    
    while ((beginArray != endArray) && (endArray - beginArray > 1))
    {
        midArray = (beginArray + endArray) / 2;
        cout << beginArray << " " << midArray << " " << endArray << "\n";
        if(numberToFind == arr[midArray])
        {
            numberLocation = midArray;
            break;
        }
        else if (numberToFind > arr[midArray])
        {
            beginArray = midArray;
        }
        else
        {
            endArray = midArray;
        }
    }
    
    if (numberLocation != - 1)
    {
        cout << "Location: " << numberLocation;
    }
    else if (numberToFind == arr[endArray])
    {
        cout << endArray;
    }
    else
    {
        cout << "Doesn't exist! ";
    }
    
    system("pause");
    return 0;
}


