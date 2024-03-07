#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void test(vector<string>& strs){
        string s = "";
        if (strs.empty()) {
            std::cout << s << std::endl;
        }
        // for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
        // {
        //     /* code */
        //     int i = 0;
        //     if ((it[i] == it[i+1]) && (it[i] == it[i+2]))
        //     {
        //         s += it[i];
        //     }
        //     i++;
        // }
        int i = 0;
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            for (vector<string>::iterator it2 = it + 1; it2 != strs.end(); ++it2) {
                if (i >= it->size() || i >= it2->size() || (*it)[i] != (*it2)[i]) {
                    std::cout << s << std::endl;
                }
            }
            s += (*it)[i];
            ++i;
        }
        std::cout << s << std::endl;
}

int main() {
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    // = ["flower","flow","flight"];
    test(strs);
    return 0;
}
