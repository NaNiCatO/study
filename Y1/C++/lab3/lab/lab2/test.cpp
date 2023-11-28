#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    std::string comma = "'" ;
    string sample = "Some sample text";
    cout<< comma+comma;
    
    char ch = 't';
    // Check if string contains the character or not
    if (sample.find(ch) != string::npos )
    {
        cout<<"Yes, string contains the character - "<< ch << endl;
    }
    else
    {
        cout<<"No, string do not contains the character - "<< ch << endl;
    }
    return 0;
}