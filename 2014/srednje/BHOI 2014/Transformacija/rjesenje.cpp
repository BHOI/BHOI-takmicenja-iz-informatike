int TransformisiNiz(int n, int a[], int m, int b[], int t[]) {
	int j = 0, i = 0, r = 0, k = 0;
	while(j < m && i < n) {
		if (a[i] != b[j]) {
			if (i > k) { k = i; }
			while (k < n && a[k] < b[j]) { ++k; }
			if (k >= n || a[k] != b[j]) {
				t[r++] = -1;
				++j;
			} else {
				t[r++] = a[i++];
			}
		} else {
			t[r++] = 0;
			++j;
			++i;
		}
	}
	for (int k = i; k < n; k++) {
		t[r++] = a[k];
	}
	for (int k = j; k < m; k++) {
		t[r++] = -1;
	}
	return r;
}
