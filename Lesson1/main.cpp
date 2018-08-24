
//  Lesson1: Function - Variables - Operators - Condition - Loop.
//  Created by Nhật Hoàng on 03/03/2018.

#include <iostream>
#include <math.h>

using namespace std;

void SolveQuadraticEquation(float a, float b, float c) // QuadraticEquation = Phương trình bậc hai
{
    cout << "The quadratic equation : ax + by + c = 0" << endl;
    cout << "Import coefficient a, b, c: " << endl; // coefficient = hệ số
    cin >> a >> b >> c;
    
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Equation has infinity root"; // root = nghiệm
            }
            else
            {
                cout << "Equation has no root";
            }
        }
        else
        {
            cout << "Equation has 1 root: X = " << (- (c / b));
        }
    }
    else
    {
        float delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            cout << "Equation has no root";
        }
        if (delta == 0)
        {
            cout << "Equation has 1 root: X = " << (-(b / (2 * a)));
        }
        if (delta > 0)
        {
            cout << "Equation has 2 different roots: " << endl;
            cout << "X1 = " << ((- b) + sqrt(delta))/ (2 * a) << endl;
            cout << "X2 = " << ((- b) - sqrt(delta))/ (2 * a) << endl;
        }
    }
}

void UseForLoopDraw(int n)
{
    /* Form:    * * * * * * *
                * * * - * * *           y = x + 3
                * * - - - * *           x + y = 11
                * - - - - - *           y = x - 3
                * * - - - * *           x + y = 5
                * * * - * * *           1 -> 7
                * * * * * * *

     Rows = Column = 7
     */

    int m = (n - 1)/2; // Trung điểm của hình

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((-i + j >= m) || ((j - i) >= (m + n - 1)) || (-j + i >= m) || (i + j < m + 1))
            {
                cout << "* ";
            }
            else
            {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

void ImportDays(int InputMonth, int InputDay)
{
    cout << "Import month: " << InputMonth << endl;
    cout << "Import day: " << InputDay << endl;
    
    int SumDays = InputDay; // Tổng số ngày
    int MonthPass = InputMonth - 1; //MonthPass = số tháng đã qua
    
    switch (MonthPass) // Calculate number of days that pass
    {
        case 11:
        {
            SumDays += 30;
        }
        case 10:
        {
            SumDays += 31;
        }
        case 9:
        {
            SumDays += 30;
        }
        case 8:
        {
            SumDays += 31;
        }
        case 7:
        {
            SumDays += 31;
        }
            
        case 6:
        {
            SumDays += 30;
        }
        case 5:
        {
            SumDays += 31;
        }
        case 4:
        {
            SumDays += 30;
        }
        case 3:
        {
            SumDays += 31;
        }
        case 2:
        {
            SumDays += 28;
        }
        case 1:
        {
            SumDays += 31;
        }
    }
    
    cout << "Number of day that pass = " << SumDays << endl;
    int Date = SumDays % 7; // Date = thứ
    
    switch (Date) // Export date
    {
        case 1:
        {
            cout << "Monday";
            break;
        }
        case 2:
        {
            cout << "Tuesday";
            break;
        }
        case 3:
        {
            cout << "Wednesday";
            break;
        }
        case 4:
        {
            cout << "Thursday";
            break;
        }
        case 5:
        {
            cout << "Friday";
            break;
        }
        case 6:
        {
            cout << "Saturday";
            break;
        }
        case 0:
        {
            cout << "Sunday";
            break;
        }
    }
}



int main()
{

//    SolveQuadraticEquation(1, 2, 1);
    
    UseForLoopDraw(7);
    
//    ImportDays(5, 22);
    
    system("pause");
    return 0;
}




