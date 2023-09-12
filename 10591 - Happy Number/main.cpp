#include <iostream>
#include <vector>
#include <set>
#define LOCAL
using namespace std;


int calculateSquareSum(int n) {
	int sum {};
	while (n > 0) {
		int digit = n % 10;
		sum += digit * digit;
		n /= 10;
	}
	return sum;
}

int isHappy(int n) {
	set<int> s;
	while (n != 1 && s.find(n) == s.end()){
		s.insert(n);
		n = calculateSquareSum(n);
	}
	return n == 1;
}

int main() {
	#ifdef LOCAL
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	int num;
	int n;
	cin >> num;
	for (int i=0; i < num; i++) {
		cin >> n;
		if (isHappy(n)) {
			cout << "Case #" << i+1 << ": " << n << " is a Happy number." << endl;
		} else {
			cout << "Case #" << i+1 << ": " << n << " is an Unhappy number." << endl;
		}
	}

	return 0;
}