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

void file_position_pointer();

void getline_example1();

void getline_example2();

void getline_example3();

void count_records_fields_from_file();

void main_FileProcessing() {
    //write_to_file();
    //read_from_file();
    //getline_example1();
    //getline_example2();
    getline_example3();

    //file_position_pointer();
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

void file_position_pointer() {
    // Create and open a file
    ofstream outFile("example.txt");
    outFile << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    outFile.close();

    // Open the file in read and write mode
    fstream file("example.txt", ios::in | ios::out);

    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    // tellg to get the current get (read) position
    streampos getPosition = file.tellg();
    cout << "Initial get position: " << getPosition << endl;

    // tellp to get the current put (write) position
    streampos putPosition = file.tellp();
    cout << "Initial put position: " << putPosition << endl;

    // Move the get position to the 7th character (index 6)
    file.seekg(6, ios::beg);
    getPosition = file.tellg();
    cout << "Get position after seekg(6): " << getPosition << endl;

    // Move the put position to the 7th character (index 6)
    file.seekp(6, ios::beg);
    putPosition = file.tellp();
    cout << "Put position after seekp(6): " << putPosition << endl;

    // Read from the new get position
    char ch;
    file.get(ch);
    cout << "Character at new get position: " << ch << endl;

    // Write a character at the new put position
    file.put('X');
    cout << "Wrote 'X' at the new put position." << endl;

    // Reset positions to the start and display the file contents
    file.seekg(0, ios::beg);
    string content;
    getline(file, content);
    cout << "Updated file content: " << content << endl;
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    cout << "###############################################" << endl;
    // Reset positions to the 'M' position
    file.seekg(12);
    // Move the get pointer n bytes forward from the current position (ios::cur)
    file.seekg(5, ios::cur);
    streampos position1 = file.tellg();
    cout << "Position after seekg(5, ios::cur): " << position1 << endl;

    cout << "Character at new get position: " << (file.get(ch), ch) << endl;

    // Move the get pointer n bytes back from the end of the file (ios::end)
    file.seekg(-5, ios::end);
    streampos position2 = file.tellg();
    cout << "Position after seekg(-5, ios::end): " << position2 << endl;

    cout << "Character at new get position: " << (file.get(ch), ch) << endl;

    // Move the get pointer to the end of the file (ios::end)
    file.seekg(0, ios::end);
    streampos position3 = file.tellg();
    cout << "Position after seekg(0, ios::end): " << position3 << endl;

    // Read the character at the current position
    file.seekg(-1, ios::cur); // Move back one position from the end to read the last character
    file.get(ch);
    cout << "Character at the end of the file: " << ch << endl;

    // Close the file
    file.close();

}

void count_records_fields_from_file() {
    ifstream infile("records.txt"); // Open input file
    vector<string> words; // Vector to store words
    int numRecords = 0; // Number of records
    string line; // String to store each line from file

    while (getline(infile, line)) { // Read line by line
        ++numRecords; // Increment number of records
        string word; // String to store each word from line
        for (char c: line) { // Iterate through each character of the line
            if (c == ' ' || c == '\t') { // Word separator found
                if (!word.empty()) { // Add non-empty word to vector
                    words.push_back(word);
                    word.clear();
                }
            } else { // Add character to current word
                word += c;
            }
        }
        if (!word.empty()) { // Add last word to vector
            words.push_back(word);
        }
    }

    infile.close(); // Close input file

    cout << "Number of words: " << words.size() << endl;
    cout << "Number of records: " << numRecords << endl;

}


