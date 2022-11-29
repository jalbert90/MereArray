#include <iostream>
#include <algorithm>

using namespace std;

bool isNonDec(const int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}

int gcd(int a, int b) {
	int r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

void solve() {
	int n;
	cin >> n;

	int* a = new int[n];
	int* b = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	int min = *min_element(a, a + n);
	sort(b, b + n);

	bool ok = true;

	for (int i = 0; i < n; i++) {
		if (a[i] != b[i] && gcd(a[i], min) != min) {
			ok = false;
			break;
		}
	}

	cout << (ok ? "YES\n" : "NO\n");

	delete[] a, b;
}

int main() {
	int t;
	cin >> t;

	for (;t--;) {
		solve();
	}
}