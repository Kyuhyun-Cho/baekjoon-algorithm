#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer; cin >> answer;
    while(true) {
        string str; cin >> str;
        int num; cin >> num;
        if (str == "+") {
            answer += num;   
        }
        else if (str == "-") {
            answer -= num;
        }
        else if (str == "*") {
            answer *= num;
        }
        else if (str == "/") {
            answer /= num;
        }
        else {
            cout << answer << '\n';
            break;
        }
    }
    return 0;
}