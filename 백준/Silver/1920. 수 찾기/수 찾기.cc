#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	unordered_multiset<int> s;

	int n;
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.insert(tmp);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		
		if (s.find(tmp) == s.end()) {
			cout << "0" << ' ';
		}
		else {
			cout << "1" << ' ';
		}
	}
}