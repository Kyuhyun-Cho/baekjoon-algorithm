#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b;
	cin >> a >> b;

	unordered_set<int> unset;
	int num;
	for (int i = 0; i < a+b; i++) {
		cin >> num;
		unset.insert(num);
	}

	int answer = unset.size() - ( (a+b) - unset.size() );
	cout << answer << '\n';
}