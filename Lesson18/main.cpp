
//  Lesson18: Nạp chồng toán tứ (Overloading) - Đa hình.
//  Created by Nhật Hoàng on 4/23/18.

#include <iostream>

using namespace std;

class Fraction;

class Fraction
{
private:
    
    float mNumerator, mDenomiator;
    
public:
    
    Fraction( float mNum = 0, float mDen = 0 ): mNumerator( mNum ), mDenomiator( mDen )
    {
        //
    }
    
    void ImportFraction( )
    {
        cout << "\n\t\t\t* Import fraction: ";
        cout << "\nNumerator: "; cin >> mNumerator;
        cout << "\nDenomirayor: "; cin >> mDenomiator;
    }
    
    void ExportFraction( )
    {
        cout << "\n\t\t\t* Export fraction: ";
        cout << mNumerator << " + " << mDenomiator << "i";
    }
    
    friend Fraction operator -( Fraction mFra1)
    {
        Fraction SubFra;
        SubFra.mNumerator = -mFra1.mNumerator;
        SubFra.mDenomiator = -mFra1.mDenomiator;
        return SubFra;
    }
    
    friend Fraction operator -( Fraction mFra1, Fraction mFra2 )
    {
        Fraction SubFra;
        SubFra.mNumerator = mFra1.mNumerator + mFra2.mNumerator;
        SubFra.mDenomiator = mFra2.mDenomiator + mFra2.mDenomiator;
        return SubFra;
    }
    
    friend Fraction operator -( Fraction mFra1, float mNum1)
    {
        Fraction SubFra;
        SubFra.mNumerator =  mFra1.mNumerator - mNum1;
        return SubFra;
    }
    
    Fraction operator +( Fraction mFra1 )
    {
        Fraction SumFra;
        SumFra.mNumerator = this->mNumerator + mFra1.mNumerator;
        SumFra.mDenomiator = this->mDenomiator = mFra1.mDenomiator;
        return SumFra;
    }
    
    Fraction operator +( float mNum1)
    {
        Fraction SumFra;
        SumFra.mNumerator = this->mNumerator + mNum1;
        return SumFra;
    }
    
    bool operator <( Fraction mFra1, Fraction mFra2 )
    {
        
    }
    
};

//class Animal;
//class Dog;
//class Cat;
//
//class Animal
//{
//public:
//
//    virtual ~Animal();
//
//    virtual void Say() = 0;
//    virtual void Eat() = 0;
//    virtual void Hate() = 0;
//};
//
//class Dog: public Animal
//{
//    void Say()
//    {
//        cout << "\n\tDog screams: WOOF WOOF WOOF!";
//    }
//    void Eat()
//    {
//        cout << "\n\t\tDog eats bones.";
//    }
//    void Hate()
//    {
//        cout << "\n\t\t\tDog hates cat.";
//    }
//};
//
//class Cat: public Animal
//{
//    void Say()
//    {
//        cout << "\n\tCat screams: MEOWWWWWWWWWW!";
//    }
//    void Eat()
//    {
//        cout << "\n\t\tCat eats fish";
//    }
//    void Hate()
//    {
//        cout << "\n\t\t\tCat hates EVEYTHING.";
//    }
//};
//
//int main()
//{
//    Animal *resultAni;
//    int indexAnimal;
//    cout << "\nChoose the animal: "; cin >> indexAnimal;
//    if(indexAnimal)
//    {
//        resultAni = new Dog();
//    }
//    else
//    {
//          resultAni = new Cat();
//    }
//
//    resultAni->Say();
//    resultAni->Eat();
//    resultAni->Hate();
//
//    delete resultAni;
//    resultAni = NULL;
//
//
//    cout << endl;
//    return 0;
//}
