#include <string>
#include <iostream>

using namespace std;

int main()
{
    int ix1 = 20;
    int ix2;
    int ix3();
    int ix4 = int{};
    //assignment happen
    ix2 = ix4;
    //value of ix2 is ix4
    //the value is 0
    string ss1(4, '*');
    string ss2{3, '&'};
    string ss3{'h', 't', 'm'};
    string ss4 = "x." + ss3;
    string ss5;
    //Are there errors in the statement? Identify and correct them.
    string ss6 = string("x.") + "png";
    //assignment happen
    ss1 = ss2 = ss4;
    //value of ss2 is ss4 then 
    //value of ss1 is ss2
    //the value is "x.htm"
}
/* 
What objects/variables are created in the statement? 
= ix1, ix2, ix4, ss1, ss2, ss3, ss5, ss6

What are their types and values? 
= ix1, ix2, ix4 are "int"
ss1, ss2, ss3, ss5, ss6 are "std::string"

Count the number of them.
= 8

What operations are they created?
-Default initialization 
    = ix2, ss5
-Value initialization
    = ix1, ss2, ss3
-Copy initialization
    = ix4, ss4, ss6
-Other types of initializations 
    = ss1
    
Are there errors in the statement? Identify and correct them. (at the code)

At which statements does the copy assignment happen? 
Which objects are assigned? 
By what value?
(at the code)

*/