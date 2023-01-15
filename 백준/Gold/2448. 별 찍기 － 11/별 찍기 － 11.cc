#include <iostream>

using namespace std;

char arr[10000][10000];

void star(int row, int col) {
    arr[row][col] = '*';
    
    arr[row+1][col-1] = '*';
    arr[row+1][col+1] = '*';
    
    for(int i = 0; i < 5; i++) {
        arr[row+2][col-2+i] = '*';
	}
}

void triangle(int len, int row, int col) {
    if (len == 3) {
        star(row, col);
        return;
    }
        
    triangle(len/2, row, col);  
    triangle(len/2, row+len/2, col-len/2);  
    triangle(len/2, row+len/2, col+len/2); 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	int n; cin >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2*n; j++) {
            arr[i][j] = ' ';
        }
    }
    
    triangle(n, 0, n-1);  
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}