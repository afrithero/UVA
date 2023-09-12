#include <iostream>
#include <vector>
#include <string>
#define LOCAL
using namespace std;

const int MAXN = 120;
int t, m, n, q;
int direct[4][2] = {{0,1},{1,0},{0,-1}, {-1,0}};
string graph[MAXN];

int is_valid(int x, int y) {
	if (x>=0 && x<m && y>=0 && y<n) return 1;
	return 0;
}

int find_square(int x, int y) {
	int d = 1; //繞圓心一圈的邊長
	char root_char = graph[x][y]; //圓心的字元
	int flag = 1; // 判斷這圈是否可以成功繞圓心一圈， 1 表示可以，0 表示不行

	while (flag) {
		d += 2; // 邊長增加兩個單位
		int nowX = x - (d/2), nowY = y - (d/2); // 原點 == 終點，所以原點是否合法會在抵達終點時檢核一次
		
		for (int i=0; i<4; i++){
			for (int j=0; j<d-1; j++){
				nowX += direct[i][0];
				nowY += direct[i][1];

				if (!is_valid(nowX, nowY) || graph[nowX][nowY] != root_char) {
					flag = 0;
					break; // 跳出內層 for loop
				} 

				if (flag == 0) break; // 跳出外層 for loop
			}
		}
	}

	return d-2; //因為要 flag=0 才會跳出迴圈，所以最大的正方形邊長會是 d-2

}

int main() {
	// 如果用這種方式就不會印出 output 到 console
	#ifdef LOCAL
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	cin >> t;
	
	while (t--){
		cin >> m >> n >> q;
		cout << m << " " << n << " " << q << endl;
		for (int i=0; i < m; i++) cin >> graph[i];
		
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << find_square(x, y) << endl;
		}
	}

	return 0;
}
