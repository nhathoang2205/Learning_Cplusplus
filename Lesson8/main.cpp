
//  Lesson8 - Cấu trúc dữ liệu và giải thuật: Array
//  Created by Nhật Hoàng on 3/28/18.

#include <iostream>

#define MAX 20

using namespace std;

// Array
int arr[MAX], arrNum = 0;

void TraverseArr()
{
    for (int index = 0; index < arrNum; index++)
    {
        cout << "array["<<index<<"]= " << arr[index] << endl;
    }
}

bool AddElement2Arr(int addValue, int addLocation)
{
    if (addLocation > arrNum || addLocation >= MAX)
    {
        cout << "Out of size! " << endl;
        return false;
    }
    else
    {
        arrNum = arrNum + 1;
        for (int index = arrNum; index >= addLocation; index--)
        {
            arr[index + 1] = arr[index];
            arr[addLocation] = addValue;
            cout << "Add " << addValue << " at location: " << addLocation << endl;
        }
        return true;
    }
}

bool DeleteElementInArr(int delLocation)
{
    if (delLocation >= arrNum || delLocation >= MAX)
    {
        cout << "Out of size!. " << endl;
        return false;
    }
    else
    {
        cout << "Delete " << arr[delLocation] << " at location " << delLocation << endl;
        for (int index = delLocation + 1; index < arrNum; index++)
        {
            arr[index - 1] = arr[index];
            arrNum = arrNum - 1;
        }
        return true;
    }
}

int SearchValueInArr(int searchValue)
{
    int searchLocation = -1; // return "-1" if can't search the value in array, do not return "0"
    for (int index = 0; index < arrNum; index++)
    {
        if (arr[index] == searchValue)
        {
            searchLocation = index;
            break;
        }
    }
    if (searchLocation >= 0)
    {
        cout << "The first location is found value " << searchLocation << endl;
    }
    else
    {
        cout << "Is not found!" << endl;
    }
    return searchLocation;
}

bool UpdateValue(int upValue, int upLocation)
{
    if (upLocation >= arrNum || upLocation >= MAX)
    {
        cout << "Out of size!. " << endl;
        return false;
    }
    else
    {
        cout << "Update value: " << upValue << " at location " << upLocation << endl;
        arr[upLocation] = upValue;
    }
    return true;
}

int main()
{
    
   
    return 0;
}

















