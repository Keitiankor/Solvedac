#include <algorithm>
#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int* numbers = new int[10001];
	std::fill_n(numbers, 10001, 0);
	for(int i = 0; i < n; i++) {
		int s;
		scanf("%d", &s);
		numbers[s]++;
	}
	for(int i = 0; i < 10001; i++)
		for(int j = 0; j < numbers[i]; j++) printf("%d\n", i);

	return 0;
}