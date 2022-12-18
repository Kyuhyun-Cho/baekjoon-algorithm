#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> name_num;
	map<string, string> num_name;
	string name;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		name_num.insert({name, to_string(i)});
		num_name.insert({to_string(i), name});
	}

	string quiz;
	for (int i = 0; i < m; i++) {
		cin >> quiz;
		if(name_num.find(quiz) != name_num.end()) {
			cout << name_num[quiz] << '\n';
		}
		else{
			cout << num_name[quiz] << '\n';
		}
	}
}