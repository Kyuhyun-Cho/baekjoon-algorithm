#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	for(int t = 0; t < n; t++) {
		int num;
		cin >> num;

		string word;
		cin >> word;

		for (int i = 0; i < word.length(); i++) {
			for (int j = 0; j < num; j++) {
				cout << word[i];
			}
		}
		cout << '\n';
	}
}