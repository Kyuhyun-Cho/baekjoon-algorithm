#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;
	vector<int> trash;
	
	for (int i = 1; i <= n; i++) {
		q.push(i); 		
	}

	while(q.size() != 1) {
		trash.emplace_back(q.front());
		q.pop();
		
		q.push(q.front());
		q.pop();
	}

	for (int i = 0; i < trash.size(); i++) {
		cout << trash[i] << " ";
	}
	cout << q.front() << '\n';
		
	return 0;
}