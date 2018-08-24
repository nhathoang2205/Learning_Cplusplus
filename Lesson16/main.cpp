
//  Lesson16
//  Created by Nhật Hoàng on 4/6/18.

// Định nghĩa toán tử nhân một ma trận với 1 véc tơ.
// Định nghĩa các toán tử +, -, * hai ma trận
// Định nghĩa các toán tử -, >>, << một ma trận.

#include <iostream>
#include <time.h>

#define MAX_LEVEL 5

using namespace std;

int matLevel;

class Matrix;
class Vector;

class Matrix
{
private:
    
    int matrix[MAX_LEVEL][MAX_LEVEL];
    
public:
    
    Matrix()
    {
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            for(int index2 = 0; index2 < matLevel; index2++)
            {
                matrix[index1][index2] = 0;
            }
        }
    }
    
    friend istream& operator >> (istream& is, Matrix &mat)
    {
        srand((unsigned)time(NULL));
        
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            for (int index2 = 0; index2 < matLevel; index2++)
            {
                mat.matrix[index1][index2] = rand() % 10;
            }
        }
        return is;
    }
    
    friend ostream& operator << (ostream& os, Matrix mat)
    {
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            for (int index2 = 0; index2 < matLevel; index2++)
            {
                os << mat.matrix[index1][index2] << "\t";
            }
            cout << endl;
        }
        return os;
    }
    
    friend Matrix operator + (Matrix mat1, Matrix mat2)
    {
        Matrix matSum;
        
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            for (int index2 = 0; index2 < matLevel; index2++)
            {
                matSum.matrix[index1][index2] += mat1.matrix[index1][index2] + mat2.matrix[index1][index2];
            }
        }
        return matSum;
    }
    
    friend Matrix operator - (Matrix mat1, Matrix mat2)
    {
        Matrix matSub;
        
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            for (int index2 = 0; index2 < matLevel; index2++)
            {
                matSub.matrix[index1][index2] += mat1.matrix[index1][index2] - mat2.matrix[index1][index2];
            }
        }
        return matSub;
    }
    
    
    friend Matrix operator * (Matrix mat1, Matrix mat2)
    {
        Matrix matMul;
        
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            for (int index2 = 0; index2 < matLevel; index2++)
            {
                matMul.matrix[index1][index2] += mat1.matrix[index1][index2] * mat2.matrix[index1][index2];
            }
        }
        return matMul;
    }
    
    friend Matrix operator - (Matrix mat)
    {
        Matrix matInv;
        
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            for (int index2 = 0; index2 < matLevel; index2++)
            {
                matInv.matrix[index1][index2] = - mat.matrix[index1][index2];
            }
        }
        return matInv;
    }
    
    friend Vector operator * (const Matrix mat, const Vector vec);
};

class Vector
{
private:
    
    int vector[MAX_LEVEL];
    
public:
    
    Vector()
    {
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            vector[index1] = 0;
        }
    }
    
    void ImportVector()
    {
        srand((unsigned)time(NULL));
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            vector[index1] = rand() % 10;
        }
    }
    
    void ExportVector()
    {
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            cout << vector[index1] << "\t";
        }
        cout << endl;
    }
    
    friend Vector operator * (const Matrix mat, const Vector vec)
    {
        Vector mulMatVec;
        
        for (int index1 = 0; index1 < matLevel; index1++)
        {
            mulMatVec.vector[index1] = 0;
            for (int index2 = 0; index2 < matLevel; index2++)
            {
                mulMatVec.vector[index1] += mat.matrix[index1][index2] * vec.vector[index2];
            }
        }
        return mulMatVec;
    }
};


int main()
{
    Vector vec;
    Vector mulVecMat;
    
    Matrix mat1, mat2;
    Matrix matSum, matSub, matMul, matInv;
    
    cout << "Import matrix & vector level: ";
    cin >> matLevel;
    
    vec.ImportVector();
    cout << "Vector has been imported by random: ";
    vec.ExportVector();
    
    cin >> mat1;
    cout << "Matrix 1: " << endl << mat1;
    cin >> mat2;
    cout << "Matrix 2: " << endl << mat2;
    
    cout << "Multiplication of vector & matrix 1: " << endl;
    mulVecMat = mat1 * vec;
    mulVecMat.ExportVector();
    
    cout << "Summation of matrix 1 & 2: " << endl;
    matSum = mat1 + mat2;
    cout << matSum;
    
    cout << "Subtraction of matrix 1 & 2: " << endl;
    matSub = mat1 - mat2;
    cout << matSub;
    
    cout << "Multiplication of matrix 1 & 2: " << endl;
    matMul = mat1 * mat2;
    cout << matMul;
    
    cout << "Inverse of matrix 1: " << endl;
    matInv = - mat1;
    cout << matInv;
    
    return 0;
}































