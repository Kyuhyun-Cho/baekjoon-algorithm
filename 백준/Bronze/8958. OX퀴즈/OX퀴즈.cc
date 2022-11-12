#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	string ox[n];
	for (int i = 0; i < n; i++) {
		string ox;
		cin >> ox;

		int cnt = 0;
		int answer = 0;
		for (int j = 0; j < ox.size(); j++) {
			if (ox[j] == 'O') {
				cnt++;
				answer += cnt;
			}
			else {
				cnt = 0;
			}
		}
		cout << answer << '\n';
	}
}