#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> createRaggedArray(string input) {
    // Check if input starts and ends with square brackets
    if (input.front() != '[' || input.back() != ']') {
        throw invalid_argument("Invalid input format");
    }

    // Remove square brackets
    input = input.substr(1, input.length() - 2);

    // Split input into rows
    vector<string> rows;
    stringstream ss(input);
    string row;
    while (getline(ss, row, ';')) {
        rows.push_back(row);
    }

    // Parse rows into vectors of integers
    vector<vector<int>> raggedArray;
    for (auto row : rows) {
        stringstream row_ss(row);
        string cell;
        vector<int> raggedRow;
        while (getline(row_ss, cell, ',')) {
            raggedRow.push_back(stoi(cell));
        }
        raggedArray.push_back(raggedRow);
    }

    return raggedArray;
}

int main() {
    string input = "[1, 2, 3; 4, 5; 6, 7, 8, 9]";
    vector<vector<int>> raggedArray = createRaggedArray(input);
    for (auto row : raggedArray) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}