#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


int main()
{
    map<string, vector<double>> x_map;
    
    x_map["exp"] = vector<double>{1.1, 2.2, 3.3};

    vector<double> vv1 = x_map["exp"];
    vector<double> vv2 = x_map["xpr"];
    //assignment happen
    vv1 = x_map["xxpr"];
    //value of vv2 is x_map["exp"]
    //the value is None

    //assignment happen
    vv2 = x_map["exp"];
    //value of vv2 is x_map["exp"]
    //the value is {1.1, 2.2, 3.3}
}

/* 
What objects/variables are created in the statement? 
= x_map, vv1, vv2

What are their types and values? 
= x_map is "map<string, vector<double>>"
vv1, vv2 is "vector of double"


Count the number of them.
= 3

What operations are they created?
-Default initialization 
    = x_map
-Value initialization
    = x_map
-Copy initialization
    = vv1, vv2
-Other types of initializations 
    = 
    
Are there errors in the statement? Identify and correct them. 
= No

At which statements does the copy assignment happen? 
Which objects are assigned? 
By what value?
(at the code)

*/