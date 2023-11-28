#include <iostream>
#include <vector>

std::vector<std::pair<char*,char*>> create_pairs_cstyle(const char* arr){
    std::vector<std::pair<char*, char*>> pairs;
    int i = 0;
    while (arr[i] != '\0') {
        int j = i;
        while (arr[j] != ' ' && arr[j] != '\0') {
            j++;
        }
        int len1 = j - i;
        char* str1 = new char[len1 + 1];
        for (int k = 0; k < len1; k++) {
            str1[k] = arr[i + k];
        }
        str1[len1] = '\0';
        i = j + 1;
        j = i;
        while (arr[j] != ' ' && arr[j] != '\0') {
            j++;
        }
        int len2 = j - i;
        char* str2 = new char[len2 + 1];
        for (int k = 0; k < len2; k++) {
            str2[k] = arr[i + k];
        }
        str2[len2] = '\0';
        i = j + 1;
        if (len1 == 0 || len2 == 0) break;
        pairs.push_back({str1, str2});
    }
    return pairs;
}

int main(){
    char data2[] = "1.2 2.3 5 2 1.1 3 7";
    auto pairs2 = create_pairs_cstyle(data2);
    for (auto p : pairs2){
        std::cout << p.first << ", " << p.second << std::endl;
    }

    return 0;
}