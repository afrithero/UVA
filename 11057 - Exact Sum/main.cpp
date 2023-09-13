#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#define LOCAL
using namespace std;

int main() {
	#ifdef LOCAL
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	int num;
	while (scanf("%d", &num) != EOF) {
		vector<int> book;
		for (int i=0; i<num; i++) {
			int price;
			cin >> price;
			book.push_back(price);
		}

		int sum;
		cin >> sum;
		sort(book.begin(), book.end());

		int price_i, price_j, diff = INT_MAX;

		for (int i=0; i<num; i++) {
			for (int j=i+1; j<num; j++) {
				if (book[i] + book[j] == sum && book[j] - book[i] < diff) {
					price_i = book[i];
					price_j = book[j];
					diff = book[j] - book[i];
				}
			}
		}
		
		printf("Peter should buy books whose prices are %d and %d.\n\n", price_i, price_j);

	}

	return 0;
}