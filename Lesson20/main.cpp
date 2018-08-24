
//  Lesson20: Bộ nhớ động - Chuỗi - Template trong C++.
//  Created by Nhật Hoàng on 5/10/18.

#include <iostream>

using namespace std;

//  * Toán tử new *
// Dùng để cấp phát bộ nhớ động cho bất kỳ kiểu dữ liệu nào trong C++
// Kiểm tra có bộ nhớ để cấp phát cho con trỏ không?

// Example:
//  double* testPointer = NULL;
//  if( !( testPointer = new double ) )
//  {
//      cout << "Error! Out of memory!" << endl;
//      exit(1);
//  }

// ****************************************************************************************

//  * Toán tử delete *
// Giải phóng bộ nhớ của một biến đã được cấp phát bộ nhớ động không cần thiết nữa

// Example:
//  delete testPointer;
//  testPointer = NULL;

// ****************************************************************************************

//  * Cấp phát mảng trong C++ *

// Example:
//  char* testPointer = NULL;
//  testPointer = new char[ 20 ];
//  delete [ ] testPointer;

// ****************************************************************************************

//  * Cấp phát mảng đa chiều *

// Example:
//  double** testPointer = NULL;
//  testPointer = new double  [ 3 ][ 4 ];
//  delete [ ] testPointer;

// ****************************************************************************************

//  * Cấp phát mảng đối tượng *

// Example:
//  class Employees
//  {
//  public:
//      Employees( );
//      ~Employees( );
//  };
//  int main( )
//  {
//      Employees* arrEmployees = new Employees[ 5 ];
//      delete [ ] arrEmployees;
//      return 0;
//  }

// ****************************************************************************************

//  * Namespace trong C++ *

//  * Chuỗi trong C *

// Example:
//  #include <string>
//
//  int main( )
//  {
//      string firstString = "Hello", secondString = "Wordl";
//      string testString;
//      unsigned long stringLength;
//
//      testString = firstString; // copy data form firstString to testString
//      testString = firstString + secondString;  // link firstString with secondString
//      stringLength = testString.size( ); // length of testString
//
//      return 0;
//  }

// ****************************************************************************************

//  * Xử lý ngoại lệ - Exeption handing
// 1. Exception là một vấn đề xuấy hiện trong khi thực thi một chương trình, là một phản hồi về một tình huống ngoại lệ mà xuất hiện
// trong khi một chương trình đang chạy.
// 2. Exception cung cấp một cách để truyền điều khiển từ một phần của một chương trình tới phần khác.
// 3. Exception được xây dựng trên 3 từ khoá:

//      - throw: ném exception khi một vấn đề xuất hiện, có thể dùng bất cứ đâu trong C++.

//      - try: bắt một exception.
//      - catch: có thể được bắt bởi một số lượng cụ thể exception, được theo sau bởi một hoặc nhiều khối catch.
//      - Một phương thức bắt exception sử dụng kết hợp các từ khoá try & catch. Có thể liệt kê nhiều lệnh catch để bắt các kiểu
//        exception khác nhau trong trường hợp khối try của bạn xuất hiện nhiều hơn một exception trong các tình huống khác nhau.
//  try
//  {
//      // Protected code
//  } catch( Exception e1 )
//  {
//      // Catch block
//  } catch( Exception e2 )
//  {
//      // Catch block
//  } catch ( Exception eN)
//  {
//      // Catch block
//  }

// Example:
//    double Division( int mFirstNum, int mSecondNum )
//    {
//        if( 0 == mSecondNum )
//        {
//            throw "Note: You are dividing by zero!";
//        }
//        return( mFirstNum / mSecondNum );
//    }
//    int main( )
//    {
//        int firstNum = 15, secondNum = 0;
//        double thirdNum = 0;
//
//        try
//        {
//            thirdNum = Division( firstNum, secondNum );
//            cout << thirdNum << endl;
//        } catch ( const char* msg )
//        {
//            cerr << msg << endl;
//        }
//
//        return 0;
//    }

// ****************************************************************************************

//  * Template trong C++ *
// Template là từ khoá thông báo cho trình biên dịch rằng đoạn mã sau đây định nghĩa cho nhiều kiểu dữ liệu và mã nguồn
// của nó sẽ được biên dịch sinh ra tương ứng cho từng kiểu dữ liệu trong quá tình biên dịch.

// 1. Function template: khuôn mẫu hàm, định nghĩa các hàm tổng quát thao tác cho nhiều kiểu dữ liệu.
//    template <class KiểuDữLiệu> KiểuThamChiếu TênHàm( DanhSáchThamSố ) { }

//  template < typename T >
//  T const& Max( T const& a, T const& b)
//  {
//      return a < b ? b:a;
//  }
//  int main( )
//  {
//      int fisrtNum = 22, secondNum = 5;
//      cout << "Greater in (fisrtNum, secondNum) is: " << Max( fisrtNum, secondNum ) << endl;
//  }

// 2. Class template: khuôn mẫu lớp, định nghĩa các lớp tổng quát cho nhiều kiểu dữ liệu.
//    template <class KiểuDữLiệu> class TênLớp { };

#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#define MAX 20
template < class T >
class Stack
{
private:
    T element[ MAX ];
    int size;
public:
    Stack( ): size( 0 ){ };
    void push( T const& );
    void pop( );
    T top( ) const;
    bool empty( ) const;
};

template < class T >
void Stack< T >::push( T const& mElement)
{
    if( size == MAX )
    {
        throw out_of_range( "Stack<>push( ): stack have been full!" );
    }
    element[ size ] = mElement;
    size++;
}

template < class T >
void Stack< T >::pop( )
{
    if( 0 == size )
    {
        throw out_of_range( "Stack<>::pop( ): stack have been free!" );
    }
    size--;
}

template < class T >
T Stack< T >::top( ) const
{
    if( 0 == size )
    {
        throw out_of_range( "Stack<>::top( ): stack have been free!" );
    }
    return element[ size - 1 ];
}

int main( )
{
    try
    {
        Stack< int > stackInteger;
        Stack< string > stackString;
        
        stackInteger.push( 10 );
        cout << stackInteger.top( ) << endl;
        
        stackString.push( "Hello World!" );
        cout << stackString.top( ) << endl;
        stackString.pop( );
        stackString.pop( );
    }
    catch( exception const& ex)
    {
        cerr << "Exception: " << ex.what( ) << endl;
        return -1;
    }
    
    return 0;
}













