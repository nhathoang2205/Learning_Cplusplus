
//  Array.cpp
//  Created by Nhật Hoàng  on 3/9/18.


#include "Array.hpp"
#include <iostream>
#include <math.h>

using namespace std;

void ImportArray(int a[], int &n)
{
    cout << " Import number elements of array: " << n;
    for(int i = 0; i < n; i++)
    {
        cout << "Import elements of array: ";
        cin >> a[i];
    }
}

void SortArray()
{
    
}

void ExportArray(int a[], int &n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "a["<< i <<"] = " << a[i] << endl;
    }
}

int main()
{
    int a[10], n = 0;
   
    
    ImportArray(a,n);
    SortArray();
    ExportArray(a,n);
    
    
    
    
    system("pause");
    return 0;
}
