#include <iostream>
#include <string>
//#include <unordered_map>
#include <map>
using namespace std;

void test(string s){
        //unordered_map<char,int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        map<char,int> mp;
        mp.insert(make_pair<char,int>('I',1));
        mp.insert(make_pair<char,int>('V',5));
        mp.insert(make_pair<char,int>('X',10));
        mp.insert(make_pair<char,int>('L',50));
        mp.insert(make_pair<char,int>('C',100));
        mp.insert(make_pair<char,int>('D',500));
        mp.insert(make_pair<char,int>('M',1000));
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] >= mp[s[i+1]]) 
                sum += mp[s[i]];
            else
                sum -= mp[s[i]];
        }
        //MCMXCIV
        std::cout << sum << std::endl;
}

int main() {
    test("MCMXCIV");
    return 0;
}
