#include <iostream>
#define LOCAL
using namespace std;

int main() {

	#ifdef LOCAL
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	// 測資關係，Fib數開到第39項就夠了
	int Fib[40] = {0, 1};
	for (int i=2; i<40; i++){
		Fib[i] = Fib[i-1] + Fib[i-2];
	}

	int t, num;
	cin >> t;
	while(t--) {
		cin >> num;
		cout << num << " = "; 
		int flag = 0;
/* 		為了不要有連續的項，要從後面的找，因為每一個數都是由前兩項加總而成，
		如果用掉了當前的項，也就表示此數會減掉當前的項，因此前兩項就一定不會再用到 */
		for (int i=39; i>1; i--) {
			if (num >= Fib[i]) {
				num = num - Fib[i];
				flag = 1;
				cout << "1";
			} else if (flag) {
				cout << "0";
			}
		}
		cout << " (fib)" << endl;
	}
	
	return 0;
}