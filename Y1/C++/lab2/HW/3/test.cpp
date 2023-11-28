#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;
 
int main()
{
    fstream file;
    file.open("cout.txt", ios::out);
    string line;
 
    file.ignore(260);
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
    
    // Redirect cout to file
    cout.rdbuf(stream_buffer_file);

    cout << "This line written to file" << endl;

    file.close();
    return 0;
}