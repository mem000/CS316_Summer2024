//
// Created by mem on 13-Aug-24.
//

#include <iostream>
#include <string>
#include <fstream> // contains file stream processing types

using namespace std;


void writing_text_and_binary()
{
    int x = 42;    //integer takes 4 bytes
    char c = 'M';   // char takes 1 byte
    //string s = "Mahmoud Esmat";
    char s [] = "MEM";

    ofstream outFile1("test1.txt");
    outFile1 << x << c << s << "Z";
    outFile1.close();

    ofstream outFile2("test2.dat", ios::out | ios::binary);
    outFile2.write( reinterpret_cast < const char * >( &x ), sizeof( x ) );
    outFile2.write( reinterpret_cast < const char * >( &c ), sizeof( c ) );
    outFile2.write( reinterpret_cast < const char * >( &s ), sizeof( s ) );
    cout << sizeof(s) << " bytes" << endl;
    //outFile.write( reinterpret_cast< const char * >( &s ), sizeof( s ) );
    outFile2.close();
}
void writing_reading_string() {
    string s = "ADSDADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAWWWWWWWWWWWWWWWWWWCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDVVVVVVVVVVVVVVVV";
    string out;
    fstream outFile3("test_str.dat", ios::out | ios::binary);
    outFile3.write( reinterpret_cast < const char * >( &s ), sizeof( s ) );
    outFile3.close();
    fstream outFile4("test_str.dat", ios::in | ios::binary);
    outFile4.read( reinterpret_cast < char * >( &out ), sizeof( s ) );
    cout << string(out) << endl;
    cout << "done" <<  endl;
    outFile4.close();
}