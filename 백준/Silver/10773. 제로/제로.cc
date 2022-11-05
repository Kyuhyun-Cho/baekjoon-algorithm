#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    int tmp;
    vector<int> v;
    for (int i = 0; i < k; i++) {
        cin >> tmp;
        if (!v.empty() && tmp == 0) {
            v.pop_back();
        }
        else {
			
            v.push_back(tmp);
        }
    }

    int answer = 0;

	if (!v.empty()) {
	    for (int i = 0; i < v.size(); i++) {
	        answer += v[i];
	    }
	}
	
    cout << answer << '\n';

	return 0;
}