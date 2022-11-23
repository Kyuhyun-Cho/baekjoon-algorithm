#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int main() {
//     vector<string> vec;
//     vec.emplace_back(")");
//     vec.emplace_back(")");
//     vec.emplace_back("(");
//     cout << vec.back();
// }

int main() {
    int n;
    cin >> n;

    string tmp;
    string arr[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }

    for (int i = 0; i < n; i++) {   
        vector<char> vec;
        for (int j = 0; j < arr[i].size(); j++) {
            vec.emplace_back(arr[i][j]);
            if (vec.size() > 1) {
                if (vec[vec.size()-1] == ')' && vec[vec.size()-2] == '(') {
                    vec.pop_back();
                    vec.pop_back();
                }
            }
        }
    
        if (vec.size() == 0){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}