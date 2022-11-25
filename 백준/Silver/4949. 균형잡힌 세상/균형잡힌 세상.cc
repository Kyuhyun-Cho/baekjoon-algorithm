#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    while(true) {
        string str;
        getline(cin, str);

        if (str == ".") {
            break;
        }
      
        vector<char> vec;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']') {
                vec.emplace_back(str[i]);
                if (vec.size() > 1) {
                    if ((vec[vec.size()-2] == '(' && vec[vec.size()-1] == ')') || (vec[vec.size()-2] == '[' && vec[vec.size()-1] == ']')) {
                        vec.pop_back();
                        vec.pop_back();
                    }
                }
            }
        }
    
        if (vec.size() == 0) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}