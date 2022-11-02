#include <iostream>

using namespace std;

int main() {
    int data[8];
    int flag = -1;

    for (int i = 0; i < 8; i++) {
        cin >> data[i];
    }
    
    for (int i = 0; i < 7; i++) {
        if (data[i] - data[i+1] == 1) {
            flag = 0;
        }
        else {
            flag = -1;
            break;
        }
    }
    
    if (flag == -1) {
        for (int i = 0; i < 7; i++) {
            if (data[i] - data[i+1] == -1) {
                flag = 1;
            }
            else {
                flag = -1;
                break;
            }
        }
    }

    if (flag == 0) {cout << "descending" << '\n';}
    else if (flag == 1) {cout << "ascending" << '\n';}
    else if (flag == -1) {cout << "mixed" << '\n';}
}