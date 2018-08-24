
//  Lesson4: String.
//  Created by Nhật Hoàng on 3/12/18.

#include<iostream>
#include<string.h>
#include<cstdlib>

using namespace std;

//void printString1()
//{
//    char mainEquation[50], checkChar = 0;
//    cin.getline(mainEquation, 50);
//    unsigned long stringLength = strlen(mainEquation);
//    //    cout << stringLength;
//
//    int letter1 = 0, letter2 = 0, index;
//
//    for (index = 0; index <= stringLength; index++)
//    {
//        if((mainEquation[index] >= 48) && (mainEquation[index] <= 57)) // 0 -> 9
//        {
//            if (checkChar == 0)
//            {
//                letter1 *= 10;
//                letter1 += mainEquation[index] - 48;
//            }
//            else
//            {
//                letter2 *= 10;
//                letter2 += mainEquation[index] - 48;
//            }
//        }
//        else if(checkChar == 0)
//        {
//            checkChar = mainEquation[index];
//        }
//    }
//    cout << letter1 << checkChar << letter2;
//}

void prinString2()
{
    char mainEquation[50], mainCalculate = 0;
    cin.getline(mainEquation, 50);
    int letter1 = 0, letter2 = 0, index = 0;
    while (mainEquation[index] != '\0')
    {
        if (mainEquation[index] >= '0' && mainEquation[index] <= '9')
        {
            if (!mainCalculate)
            {
                letter1 *= 10;
                letter1 += mainEquation[index] - 48;
            }
            else
            {
                letter2 *= 10;
                letter2 += mainEquation[index] - 48;
            }
        }
        else if (mainEquation[index] != ' ') mainCalculate = mainEquation[index];
        {
            index++;
        }
    }

    cout << letter1 << mainCalculate << letter2 << '=';
    switch (mainCalculate)
    {
        case '+': cout<<letter1+letter2; break;
        case '-': cout<<letter1-letter2; break;
        case '*': cout<<letter1*letter2; break;
        case '/': cout<<letter1/letter2; break;
    }
}

void importInformation()
{
    int index = 0, importBirth[31], importDay;
    for (index = 0; index < 31; index++)
    {
        importBirth[index]=0;
    }
    for (index = 0; index < 999; index++)
    {
        importDay = rand() % 31 + 1;
        importBirth[importDay - 1] ++;
    }
    for (index = 0; index < 31; index++)
    {
        cout << endl;
        cout << " Date" << index + 1 << " have " << importBirth[index];
    }
}

int main()
{
    system("pause");
    return 0;
}

// Nhập họ tên. In ra họ của bạn là, tên của bạn là.
// Đọc các lệnh strlen, strcmp, strcat, strups, strlwr.
