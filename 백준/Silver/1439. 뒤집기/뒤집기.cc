#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt = 0;	
	for (int i = 0; i < str.length()-1; i++) {
		if (str[i] != str[i+1]) cnt++;
	}
	if (cnt == 1) cout << cnt << '\n';
	else if (cnt % 2 == 1) cout << cnt/2+1 << '\n';
	else cout << cnt/2 << '\n';
}