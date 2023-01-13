#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

int n;
vector<int> graph[MAX];
bool visited[MAX];
int answer[MAX];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }    
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < graph[parent].size(); i++) {
            int tmp = graph[parent][i];
            if(!visited[tmp]) {
                q.push(tmp);
                visited[tmp] = true;
                answer[tmp] = parent;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << answer[i] << '\n';
    }
}