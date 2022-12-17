#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> myMap;
	
	string address, pw;	
	for (int i = 0; i < n; i++) {
		cin >> address >> pw;
		myMap.insert({address, pw});
	}

	for (int i = 0; i < m; i++) {
		string pw_looked_for;
		cin >> pw_looked_for;

		cout << myMap.at(pw_looked_for) << '\n';
	}
	return 0;
}