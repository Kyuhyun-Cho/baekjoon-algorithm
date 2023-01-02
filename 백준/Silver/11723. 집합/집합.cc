#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n; cin >> n;

	vector<int> all;
	for (int i = 1; i <= 20; i++) {
		all.emplace_back(i);
	}
    vector<int> set;
    string command;
    for (int t = 0; t < n; t++) {
        cin >> command;
	    
		if (command == "add") {
            int x; cin >> x;
		    if (find(set.begin(), set.end(), x) == set.end()) {
				set.emplace_back(x);
			}       
		}
        if (command == "remove") {
            int x; cin >> x;
            if (find(set.begin(), set.end(), x) != set.end()) {
				set.erase(find(set.begin(), set.end(), x));
			}
        }
        if (command == "check") {
            int x; cin >> x;
            if (find(set.begin(), set.end(), x) != set.end()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
        }
        if (command == "toggle") {
            int x; cin >> x;
            if (find(set.begin(), set.end(), x) != set.end()) {
				set.erase(find(set.begin(), set.end(), x));
			}
			else {
				set.emplace_back(x);
			}
        }
        if (command == "all") {
            set = all;
        }
        if (command == "empty") {
            set = {};
        }
    }
}