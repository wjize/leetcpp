#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void test(vector<int>& nums){
        //nums.erase(unique(nums.begin(),nums.end()),nums.end());
        vector<int>::iterator ii = unique(nums.begin(),nums.end());
        std::cout << "ii: " << *ii << std::endl;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            std::cout << "size: " << nums.size() << std::endl;
            std::cout << "it: " << *it << std::endl;
        }
        
        //std::cout << s << std::endl;
}

int main() {
    vector<int> strs;
    strs.push_back(1);
    strs.push_back(1);
    strs.push_back(2);
    strs.push_back(2);
    strs.push_back(2);
    strs.push_back(3);
    // = ["flower","flow","flight"];
    test(strs);
    return 0;
}
