#include <iostream>

using namespace std;

unsigned long long s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	unsigned long long num = 0;
	unsigned long long cnt = 0;
	while(true) {
		num++;
		s -= num;
		cnt++;
		if (s == 0) {
			cout << cnt << '\n';
			return 0;
		}
		else if (s <= num) {
			cout << cnt << '\n';
			return 0;
		} 
	}
}