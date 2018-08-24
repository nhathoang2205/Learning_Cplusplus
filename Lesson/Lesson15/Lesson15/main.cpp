
//  Lesson15
//  Created by Nhật Hoàng on 4/5/18.

#include <iostream>
#include <time.h>

#define LENGHT 5

using namespace std;

int rangeVM;
class Vector;
class Matrix;

class Matrix
{
private:
    
    int matrix[LENGHT][LENGHT];
    
public:
    
    Matrix()
    {
        for (int index1 = 0; index1 <= rangeVM; index1++)
        {
            for (int index2 = 0; index2 <= rangeVM; index2++)
            {
                matrix[index1][index2] = 0;
            }
        }
    }
    
    void ImportMatrix()
    {
        srand((unsigned)time(NULL));
        
        for (int index1 = 0; index1 < rangeVM; index1++)
        {
            for (int index2 = 0; index2 < rangeVM; index2++)
            {
                matrix[index1][index2] = rand()%10;
            }
        }
    }
    
    void ExportMatrix()
    {
        for (int index1 = 0; index1 < rangeVM; index1++)
        {
            for (int index2 = 0; index2 < rangeVM; index2++)
            {
                cout << matrix[index1][index2] << "\t";
            }
            cout << endl;
        }
    }
    friend Vector MulMatVec(const Matrix matrix, const Vector vector);
};

class Vector
{
private:
    
    int vector[LENGHT];
    
public:
    
    Vector()
    {
        for (int index1 = 0; index1 < rangeVM; index1++)
        {
            vector[index1] = 0;
        }
    }
    
    void ImportVector()
    {
        srand((unsigned)time(NULL));
        for (int index1 = 0; index1 < rangeVM; index1++)
        {
            vector[index1] = rand()%10;
        }
    }
    
    void ExportVector()
    {
        for (int index1 = 0; index1 < rangeVM; index1++)
        {
            cout << vector[index1] << "\t";
        }
        cout << endl;
    }
    
    friend Vector MulMatVec(const Matrix matrix, const Vector vector)
    {
        Vector mulMatVec;

        for (int index1 = 0; index1 < rangeVM; index1++)
        {
            mulMatVec.vector[index1] = 0;
            for (int index2 = 0; index2 < rangeVM; index2++)
            {
                mulMatVec.vector[index1] += matrix.matrix[index1][index2] * vector.vector[index2];
            }
        }
        return mulMatVec;
    }
};

int main()
{
    cout << "Import level of matrix & vector: ";
    cin >> rangeVM;
    
    Vector vector;
    vector.ImportVector();
    cout << "Export vector: " << endl;
    vector.ExportVector();
    
    Matrix matrix;
    matrix.ImportMatrix();
    cout << "Export matrix: " << endl;
    matrix.ExportMatrix();
    
    Vector mulMatVec;
    cout << "Multipalication of matrix and vector with the same level: " << endl;
    mulMatVec = MulMatVec(matrix, vector);
    mulMatVec.ExportVector();

    return 0;
}


















