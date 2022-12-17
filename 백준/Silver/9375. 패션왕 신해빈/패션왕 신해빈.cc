#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int testCase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> testCase;
	
	for (int t = 0; t < testCase; t++) {
		int num;
		cin >> num;

		if (num == 0) {
			cout << 0 << '\n';
			continue;
		}
		
		map<string, int> clothes;
		vector<string> categories;
		
		for (int i = 0; i < num; i++) {
			string item, category;
			cin >> item >> category;
			if (!clothes.count(category)) {
				clothes[category] = 1;
				categories.emplace_back(category);
			}
			else {
				clothes[category] += 1;
			}
		}

		int answer = 1;

		for (int i = 0; i < categories.size(); i++) {
			answer *= clothes[categories[i]]+1;
		}
		cout << answer - 1 << '\n';
	}
}