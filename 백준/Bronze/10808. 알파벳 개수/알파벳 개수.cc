#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int cnt[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	string str; cin >> str;
	for (int i = 0; i < str.size(); i++) {
		cnt[str[i] - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << ' ';
	}
}