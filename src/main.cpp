#include <iostream>
#include <cstdlib>
#include "vector.hpp"

using namespace std;

int main() {

	Vector vector;

	int N;
	cout << "N> ";
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cout << "\tItem " << i << "> ";
		int x;
		cin >> x;
		vector.insert(x);
	}

	vector.print();

	while (true) {
		cout << "Remove> ";
		int i;
		cin >> i;
		vector.remove(i);
		vector.print();
	}

	return 0;
}
