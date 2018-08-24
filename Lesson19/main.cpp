//  Lesson19: Đọc/ghi file.
//  Created by Nhật Hoàng on 5/4/18.

// *** Thư viện ***
// 1. ofstream: biểu diễn Output File Stream và được sử dụng để tẹo file và ghi thông tin tới các file đó.
// 2. ifstream: biểu diễn Input File Stream và được sử dụng để đọc thông tin từ các file.
// 3. fstream: biểu diễn File Stream, và có các khả năng của cả ofstream lẫn ifstream - có thể tạo file, ghi thông tin với file và đọc thông tin từ file

#include <iostream>
#include <fstream> // include thư viện xử lý file

using namespace std;

void OpenFileToWriteAndRead()
{
    // * Mở một file trong C++
    // void open( const char *tenFile, ios::mode);
    // 1. <ios::app>    Chế độ append. Tất cả output tới file đó được phụ thêm vào cuối file.
    // 2. <ios::ate>    Mở một file cho output và chi chuyển điều khiển read/write tới cuối file.
    // 3. <ios::in>     Mở một file để đọc.
    // 4. <ios::out>    Mở một file để ghi.
    // 5. <ios::trunc>  Nếu file này đã tồn tại, nội dung của nó sẽ được cắt (truncate) trước khi mở file.
    
    // * Đóng một file trong C++
    // void close();
    
    char dataFile[100];
    
    ofstream outFile; // Open file in write mode.
    outFile.open( "msita.dat" );
    cout << "\t\t\t* Write data to file! *" << endl;
    cout << "Import name: ";
    cin.getline( dataFile, 100 ); // Write imported data to file.
    outFile << dataFile;
    cout << "Import age: ";
    cin >> dataFile;
    cin.ignore( );
    outFile << dataFile;
    outFile.close();
    
    ifstream inFile; // Open file in read mode.
    inFile.open( "msita.dat" );
    cout << "\t\t\t* Read data in file! *" << endl;
    cout << "Data: ";
    inFile.getline( dataFile, 100 ); // Export data in file and display it.
    cout << dataFile;
    inFile >> dataFile; // Read & display data.
    inFile.close( );
}

// * Homework *
// 1. Viết chương trình đọc nội dung file. Có kiểm tra End of file.
void ReadFileAndCheckEOF()
{
    ofstream outFile;
    outFile.open( "input.txt", ios::in );
    
    string dataWrite;
    
    string lineDataFile;
    
    while( !outFile.eof( ) )
    {
        cin.getline( outFile, lineDataFile );
        dataWrite += lineDataFile;
    }
    
    outFile.close( );
    cout << dataWrite;
}

// 2. Viết chương trình mở một file có tên "two.txt", ghi nội dung vào file và sau đó chuyển nội dung thành chữ hoa.
void OpenFileToWriteAnd()
{
    ofstream outFile;
    outFile.open( "two.txt", ios::out );
    
    string dataWrite = " Nhật Hoàng ";
    outFile << dataWrite;
    outFile.close( );
}

void yeah()
{
    // * Con trở vị trí file trong C++ *
    // seekg cho istream & seekp cho ostream: long int
    // 1. <ios::beg> Xác định vị trí liên quan tới phần bắt đầu của một stream.
    // 2. <ios::cur> Xác định vị trí liên quan tới vị trí hiện tại trong một stream.
    // 3. <ios::end> Xác định vị trí liên quan tới phần kết thúc của một stream.
}

int main( )
{
    cout << endl;
    return 0;
}





















