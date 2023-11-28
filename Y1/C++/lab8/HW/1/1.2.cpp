#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
        double num_array[6];
        string s(3, '*');
        vector<string> vs1(5, s);
        vector<string> vs2(4);
        vector<string> vs3 = vs1;
        vector<string> vs4{};
        //assignment happen
        vs1 = vs2 = vs3;
        //value of vs2 is vs3 then
        //value of vs1 is vs2
        //the value is {"***", "***", "***", "***", "***"}
        vector<double> vv1{3, 2.5};
        vector<double> vv2(2);
        vector<double> vv3();
        //assignment happen
        vv2 = vv1;
        //value of vv2 is vv1
        //the value is {3, 2.5}
}

/* 
What objects/variables are created in the statement? 
= num_array, s, vs1, vs2, vs3, vs4, vv1, vv2

What are their types and values? 
= num_array is "array of double"
s is "std::string"
vs1, vs2, vs3, vs4 is "vector of string"
vv1, vv2 is "vector of double"


Count the number of them.
= 8

What operations are they created?
-Default initialization 
    = num_array, vs4
-Value initialization
    = vv1
-Copy initialization
    = vs3
-Other types of initializations 
    = s, vs1, vs2, vv2
    
Are there errors in the statement? Identify and correct them. 
= No

At which statements does the copy assignment happen? 
Which objects are assigned? 
By what value?
(at the code)

*/