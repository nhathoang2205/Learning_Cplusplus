
//  Lesson17 - Tính kế thừa (inheritance)
//  Created by Nhật Hoàng on 4/12/18.

#include <iostream>
#include <string.h>

using namespace std;

class Time;
class Human;
class Teacher;
class Student;

class Time
{
protected:
    
    int mDay, mMonth, mYear;
    
public:
    
    Time();
    ~Time();
    Time(int Day, int Month, int Year);
    void ImportTime();
    void ExportTime();
    friend int CheckDay(int Num);
    friend int CheckMonth(int Num);
    friend int CheckYear(int Num);
};

Time::Time()
{
    mDay = mMonth = mYear = 0;
}

Time::~Time()
{
    // NULL
}

Time::Time(int Day, int Month, int Year)
{
    mDay = Day;
    mMonth = Month;
    mYear = Year;
}

int CheckDay(int Num)
{
    int mCheckNum = 1;
    if ( (Num < 0) || (Num > 30) )
    {
        mCheckNum = 0;
    }
    return mCheckNum;
}

int CheckMonth(int Num)
{
    int mCheckNum = 1;
    if ( (Num < 0) || (Num > 12) )
    {
        mCheckNum = 0;
    }
    return mCheckNum;
}

int CheckYear(int Num)
{
    int mCheckNum = 1;
    if ( (Num < 0) )
    {
        mCheckNum = 0;
    }
    return mCheckNum;
}

void Time::ImportTime()
{
    while (1)
    {
        int mCheckNum = 1;
        
        do
        {
            mCheckNum = 1;
            cout << "Import day: ";
            cin >> mDay;
            mCheckNum = CheckDay(mDay);
            if (mCheckNum == 0)
            {
                cout << "Enter again. " << endl;
            }
        } while (mCheckNum == 0);
        
        do
        {
            mCheckNum = 1;
            cout << "Import month: ";
            cin >> mMonth;
            mCheckNum = CheckMonth(mMonth);
            if (mCheckNum == 0)
            {
                cout << "Enter again. " << endl;
            }
        } while (mCheckNum == 0);
        
        do
        {
            mCheckNum = 1;
            cout << "Import year: ";
            cin >> mYear;
            mCheckNum = CheckYear(mYear);
            if (mCheckNum == 0)
            {
                cout << "Enter again. " << endl;
            }
        } while (mCheckNum == 0);
    }
}

void Time::ExportTime()
{
    cout << mDay << "/" << mMonth << "/" << mYear << endl;
}

class Human
{
protected:
    
    string mName;
    Time mBirth;
    
public:
    
    Human();
    ~Human();
    void ImportHuman();
    void ExportHuman();
    friend int CheckString(string checkStr);
};

Human::Human()
{
    // NULL
}

Human::~Human()
{
    // NULL
}

int CheckString(string Str)
{
    int mCheckStr = 0;
    if ( ((Str[0] >= 'A') && (Str[0] <= 'Z')) || ( ((Str[0] >= 'a') && (Str[0] <= 'z')) || (Str[0] == '_') ) )
    {
        mCheckStr = 1;
    }
    else
    {
        mCheckStr = 0;
    }
    return mCheckStr;
}

void Human::ImportHuman()
{
    while (1)
    {
        int mCheckStr = 1;
        
        do
        {
            mCheckStr = 1;
            cout << "Import name: ";
            getline(cin, mName);
            mCheckStr = CheckString(mName);
            if (mCheckStr == 0)
            {
                cout << "Enter again. " << endl;
            }
            cout << "Import day of birth: " << endl;
            mBirth.ImportTime();
        } while (mCheckStr == 0);
    }
}

void Human::ExportHuman()
{
    cout << "Name: " << mName << endl;
    cout << "Birthday: ";
    mBirth.ExportTime();
}

class Teacher: public Human
{
protected:
    
    int mCodeTeacher;
    string mLevelTeacher;
    
public:
    
    Teacher();
    ~Teacher();
    void ImportTeacher();
    void ExportTeacher();
};

Teacher::Teacher()
{
    // NULL
}

Teacher::~Teacher()
{
    // NULL
}

void Teacher::ImportTeacher()
{
    cout << "Import teacher information: " << endl;
    Human::ImportHuman();
    cout << "Import teacher code: "; cin >> mCodeTeacher;
    cout << "Import teaching level: "; getline(cin, mLevelTeacher);
}

void Teacher::ExportTeacher()
{
    cout << "Teacher information: " << endl;
    Human::ExportHuman();
    cout << "Teacher code: " << mCodeTeacher << endl;
    cout << "Teaching level: " << mLevelTeacher << endl;
}

class Student: public Human
{
protected:
    
    int mCodeStudent;
    string mClass;
    
public:
    
    Student();
    ~Student();
    void ImportStudent();
    void ExportStudent();
};

Student::Student()
{
    // NULL
}

Student::~Student()
{
    // NULL
}

void Student::ImportStudent()
{
    cout << "Import student information: " << endl;
    Human::ImportHuman();
    cout << "Import student code: "; cin >> mCodeStudent;
    cout << "Import class: "; getline(cin, mClass);
}

void Student::ExportStudent()
{
    cout << "Export student information: " << endl;
    Human::ExportHuman();
    cout << "Student code: " << mCodeStudent << endl;
    cout << "Class: " << mClass << endl;
}

int main()
{
    while (1)
    {
        cout << "1. Import teacher information. " << endl;
        cout << "2. Import student information. " << endl;
        cout << "3. Export teacher ỉnformation. " << endl;
        cout << "4. Export student information. " << endl;
        cout << ">> Choose your option: ";
        int select1 = 0;
        cin >> select1;
        cin.ignore();
        
        Teacher tea;
        Student stu[10];
        
        switch (select1)
        {
            case 1:
            {
                tea.ImportTeacher();
                break;
            }
            case 2:
            {
                for (int index1 = 1; index1 <= 10; index1++)
                {
                    stu[0].ImportStudent();
                }
                break;
            }
                
            case 3:
            {
                tea.ExportTeacher();
                break;
            }
            case 4:
            {
                cout << "Select student: ";
                {
                    int select2 = 0;
                    cin >> select2;
                    cin.ignore();
                    
                    switch (select2)
                    {
                        case 1:
                        {
                            stu[1].ExportStudent();
                            break;
                        }
                        case 2:
                        {
                            stu[2].ExportStudent();
                            break;
                        }
                        case 3:
                        {
                            stu[3].ExportStudent();
                            break;
                        }
                        case 4:
                        {
                            stu[4].ExportStudent();
                            break;
                        }
                        case 5:
                        {
                            stu[5].ExportStudent();
                            break;
                        }
                        case 6:
                        {
                            stu[6].ExportStudent();
                            break;
                        }
                        case 7:
                        {
                            stu[7].ExportStudent();
                            break;
                        }
                        case 8:
                        {
                            stu[8].ExportStudent();
                            break;
                        }
                        case 9:
                        {
                            stu[9].ExportStudent();
                            break;
                        }
                        case 10:
                        {
                            stu[10].ExportStudent();
                            break;
                        }
                        default:
                        {
                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }
            default:
            {
                exit(EXIT_FAILURE);
            }
        }
    }
    
    return 0;
}















