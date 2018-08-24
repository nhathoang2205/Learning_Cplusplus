
//  Lesson14 - Lớp số phưcS
//  Created by Nhật Hoàng on 4/5/18.

#include <iostream>

using namespace std;

class ComplexNumber
{
private:
    
    float comReal,  comIma; // imaginary: phần ảo\
    
public:
    
//    ComplexNumber();
//    ~ComplexNumber();
    
    friend istream& operator >> (istream& is, ComplexNumber &num)
    {
        cout << "Import complex number: ";
        is >> num.comReal >> num.comIma;
        return is;
    }

    friend ostream& operator << (ostream& os, const ComplexNumber num)
    {
        os << "Complex number = " << num.comReal << " + " << num.comIma << "i" << endl;
        return os;
    }
    
//    istream& operator >> (istream& is)
//    {
//        cout << "Import complex number: ";
//        is >> this->comReal >> this->comIma;
//        return is;
//    }
//
//   ostream& operator << (ostream& os)
//    {
//        os << "Complex number = " << this->comReal << " + " << this->comIma << "i" << endl;
//        return os;
//    }
    
//    void SetComNum(float real, float imaginary)
//    {
//        comReal = real;
//        comIma = imaginary;
//    }
//    void ImportComNum()
//    {
//        cout << "Import complex number: ";
//        cin >> comReal >> comIma;
//    }
//    void ExportComNum()
//    {
//        cout << "Complex number = " << comReal << " + " << comIma << "i" << endl;
//    }
    
    friend ComplexNumber operator + (ComplexNumber num1, ComplexNumber num2)
    {
        ComplexNumber comSum;
        comSum.comReal = num1.comReal + num2.comReal;
        comSum.comIma = num1.comIma + num2.comIma;
        return comSum;
    }
    friend ComplexNumber operator - (ComplexNumber num1, ComplexNumber num2)
    {
        ComplexNumber comSub;
        comSub.comReal = num1.comReal - num2.comIma;
        comSub.comIma = num1.comIma - num2.comReal;
        return comSub;
    }
    friend ComplexNumber operator * (ComplexNumber num1, ComplexNumber num2)
    {
        ComplexNumber comMul;
        comMul.comReal = num1.comReal * num2.comReal - num1.comIma * num2.comIma;
        comMul.comIma = num1.comReal * num2.comIma - num1.comIma * num2.comReal;
        return comMul;
    }
    friend ComplexNumber operator / (ComplexNumber num1, ComplexNumber num2)
    {
        ComplexNumber comDiv;
        comDiv.comReal = (num1.comReal * num2.comReal + num1.comIma * num2.comIma) / (num1.comReal * num2.comReal + num1.comIma * num2.comIma);
        comDiv.comIma = (num1.comIma * num2.comReal - num1.comReal * num2.comIma) / (num1.comReal * num2.comReal + num1.comIma * num2.comIma);
        return comDiv;
    }
};

int main()
{
    ComplexNumber num1, num2;
    ComplexNumber comSum, comSub, comMul, comDiv;
    
//    num1.ImportComNum();
//    num2.ImportComNum();
//    num1.ExportComNum();
//    num2.ExportComNum();

//    cin >> num1 >> num2;
//    cout << num1 << num2;
    
    num2 >> (num1 >> cin);
    num2 << (num1 << cout);
    
    comSum = num1 + num2;
//    cout << "Summation of 2 complex number: " << comSum;
    comSum << cout;
//    comSum.ExportComNum();
    
    comSub = num1 - num2;
//    cout << "Subtraction of 2 complex number: " << comSub;
//    comSub.ExportComNum();
    
    comMul = num1 * num2;
//    cout << "Multiplication of 2 complex number: " << comMul;
//    comMul.ExportComNum();
    
    comDiv = num1 / num2;
//    cout << "Division of 2 complex number: " << comDiv;
//    comDiv.ExportComNum();
    
    return 0;
}
















