#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;
 
int lis[maxn], lds[maxn];
int n, num[maxn];
 
int main() {
	while (scanf("%d", &n) != EOF && n) {
		memset(lis, 0, sizeof(lis));
		memset(lds, 0, sizeof(lds));
		for (int i = 1; i <= n; i++) 
			scanf("%d", &num[i]);
 
		for (int i = n; i >= 1; i--) {
			lis[i] = lds[i] = 1;
			for (int j = n; j > i; j--) {
				if (num[i] >= num[j])
					lds[i] = max(lds[i], lds[j] + 1);
				if (num[i] <= num[j]) 
					lis[i] = max(lis[i], lis[j] + 1);
			}
		}
 
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, max(lis[i], lds[i]));
			for (int j = i+1; j <= n; j++) {
				if (num[j] < num[i])
					ans = max(ans, lis[i] + lds[j]);
				else if (num[j] > num[i])
					ans = max(ans, lds[i] + lis[j]);
			}
		}
 
		printf("%d\n", ans);
	}
	return 0;
}
