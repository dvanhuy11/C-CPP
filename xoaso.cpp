#include <stdio.h>

int main() {
	int a[100], n, s = 0, z = -1, x = -1, b = 0;
	printf("nhap mang ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("a[%d]", i);
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	if (s % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0)
				z++;
			if (a[i] % 2 != 0)
				x++;
		}
		printf("tong so cach la %d", z + x);
	}
	else {
		for (int i = 0; i < n; i++)
			for (int c = i; c < n; c++)
				if ((a[i] + a[c]) % 2 != 0)
					b++;
		printf("so cach xoa la %d", b);
	}
	
	return 0;
}
