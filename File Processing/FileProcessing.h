//
// Created by mem on 07-Aug-24.
//



#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // for istringstream
#include <vector>
using namespace std;

void write_to_file();
void read_from_file();
void getline_example1();
void getline_example2();
void getline_example3();
void vector_2D();  //vector of vectors
void count_records_fields_from_file();

void main_FileProcessing() {
    //write_to_file();
    read_from_file();
    //getline_example3();
    //vector_2D();


    //count_records_fields_from_file();

}
void write_to_file() {
    ofstream outFile("courses.txt", ios::out);
    // exit program if unable to create file
    if (!outFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    } // end if
    cout << "Enter the CID and Course Name.\n?";

    int CID;
    string name;

    // read CID, and course name cin, then place in file
    while (cin >> CID >> name) {
        outFile << CID << ' ' << name << endl;
        cout << "?";
    } // end while4
    outFile.close(); // Always close a file as soon as it’s no longer needed in a program
}

void read_from_file() {
    ifstream inClientFile("courses.txt", ios::in);

    // exit program if ifstream could not open file
    if (!inClientFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    } // end if
    int CID;
    string name;

    // read CID, and course name cin, then place in file
    while (inClientFile >> CID >> name) {
        cout << "Course ID: " << CID << ", Course Name: " << name << endl;
    } // end while
    inClientFile.close(); // Always close a file as soon as it’s no longer needed in a program
}

void getline_example1() {
    /*
    In C++, the getline() function is used to read a string from input,
        and it allows you to specify a delimiter character to stop reading. */
    string myInput;
    cout << "Enter a string: ";
    getline(cin, myInput);
    cout << "You entered: " << myInput << endl;
    /*
    In this example, the getline() function is used to read
    a line of text from the standard input (which is usually
    the keyboard) into the input variable.The delimiter character
    is not specified, so getline() will read until it reaches the end of the line.
    */
}

void getline_example2() {
    string myInput;
    cout << "Enter a string: ";
    getline(cin, myInput, ','); // Read until a comma is encountered
    cout << "You entered: " << myInput << endl;
    /*
    In this example, getline() will read input until it encounters a comma.
    The comma will be included in the input string, unless the end of the line
    is reached before a comma is encountered.
    */
}
void getline_example3() {
    ifstream data_file("data_file.txt");
    ofstream index_file("index_file.txt");
    string str;
    int n_records = 0;
    char record_delimiter = ';';
    char field_delimiter = ' ';
    string record_id;
    int record_byte_offset;
    while (true) {
        record_byte_offset = data_file.tellg();
        if (!getline(data_file, str, record_delimiter)) break;
        record_id = str.substr(0, str.find(field_delimiter));
        index_file << record_id << ' ' << record_byte_offset << '\n';
    }
    /*int record_byte_offset = data_file.tellg();
    while (getline(data_file, str, record_delimiter)) {
        record_id = str.substr(0, str.find(field_delimiter));
        index_file << record_id << ' ' << record_byte_offset << '\n';

        record_byte_offset = data_file.tellg();
    }*/

    /*int record_byte_offset = data_file.tellg();;
    string field;
    while (getline(data_file, str, record_delimiter)) {
        istringstream record(str); // Create istringstream from string
        while (getline(record, field, field_delimiter)) {
            cout << field  << endl;
        }
        //record_id = str.substr(0, str.find(field_delimiter));
        //index_file << record_id << ' ' << record_byte_offset << '\n';
    }*/
    cout << "\nDone ..." << endl;
    data_file.close();
    index_file.close();
}
void vector_2D() {
    //vector of vectors of integers:
    vector<vector<int>> vector_2d;

    // To add a new vector, you can use the push_back() method:
    vector<int> myVector1 = { 1, 2, 3 };
    vector<int> myVector2 = { 11, 22, 33 };
    vector<int> myVector3 = { 10, 20, 30 };
    vector_2d.push_back(myVector1);
    vector_2d.push_back(myVector2);
    vector_2d.push_back(myVector3);
    /*
    To access an element of the vector of vectors, you can use
    the[] operator twice, once to access the vector and again
    to access the element of that vector :
    */
    cout << "vector_2d[0][1] = " << vector_2d[0][1] << endl;

    // iterate through all the elements
    for (vector<int>& vec : vector_2d) {
        for (int& element : vec) {
            cout << element << ' ';
        }
        cout << endl;
    }
}

void count_records_fields_from_file() {
    std::ifstream infile("records.txt"); // Open input file
    std::vector<std::string> words; // Vector to store words
    int numRecords = 0; // Number of records
    std::string line; // String to store each line from file

    while (std::getline(infile, line)) { // Read line by line
        ++numRecords; // Increment number of records
        std::string word; // String to store each word from line
        for (char c : line) { // Iterate through each character of the line
            if (c == ' ' || c == '\t') { // Word separator found
                if (!word.empty()) { // Add non-empty word to vector
                    words.push_back(word);
                    word.clear();
                }
            }
            else { // Add character to current word
                word += c;
            }
        }
        if (!word.empty()) { // Add last word to vector
            words.push_back(word);
        }
    }

    infile.close(); // Close input file

    std::cout << "Number of words: " << words.size() << std::endl;
    std::cout << "Number of records: " << numRecords << std::endl;

}


