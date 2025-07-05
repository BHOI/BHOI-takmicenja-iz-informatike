/// 786

#include <iostream>
using namespace std;

typedef long long llx;

struct frac {
	llx a, b;

	frac () : b (1) {} ;
	frac (llx _a, llx _b) : a (_a), b (_b) {} ;
};

int n;

llx gcd (llx a, llx b)
{
	return (b ? gcd (b, a % b) : a);
}

llx lcm (llx a, llx b)
{
	a = abs (a); b = abs (b);
	return (max (a, b) / gcd (a, b)) * min (a, b);
}

void skrati (frac &x)
{
	llx g = gcd (abs (x.a), x.b);
	x.a /= g;
	x.b /= g;
}

frac pomnozi (frac a, frac b)
{
	frac n;
	llx q = gcd (abs (a.a), b.b);
	a.a /= q; b.b /= q;
	llx p = gcd (a.b, abs (b.a));
	a.b /= p; b.a /= p;
	n.a = a.a * b.a;
	n.b = a.b * b.b;
//	skrati (n);
	return n;
}

void podijeli (frac *a, frac x)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = pomnozi (a[i], frac (x.b, abs (x.a)));
		a[i].a *= (x.a < 0 ? -1 : 1);
	}
}

frac saberi (frac x, frac y)
{
	frac n;
	llx l = lcm (x.b, y.b); // FIX?
	n.b = l;
	n.a = (x.a * (l/x.b) + y.a * (l/y.b));
	skrati (n);
	return n;
}

// res += x * src
void dodaj (frac *res, frac *src, frac x)
{
	for (int i = 0; i < n; i++)
		res[i] = saberi (res[i], pomnozi (src[i], x));
}

int main (void)
{
	frac t;
//	freopen("sjo\\invertor1.in","r",stdin);

	int a; cin >> n;

	frac **matrica = new frac*[n];
	frac **jedinicna = new frac*[n];
	for (int i = 0; i < n; i++)
	{
		matrica[i] = new frac[n];
		jedinicna[i] = new frac[n];
		for (int j = 0; j < n; j++) {
			jedinicna[i][j].a = (i == j ? 1 : 0);
			cin >> matrica[i][j].a;
		}
	}

	for (int i = 0; i < n; i++)
	{
		// trazi nenull
		int e;
		for (e = 0; e < n && matrica[i][e].a == 0; e++) ;
		if (e == n)
		{
			printf ("?\n");
			return 0;
		}

		t = matrica[i][e];
		podijeli (matrica[i], t);
		podijeli (jedinicna[i], t);

		for (int j = 0; j < n; j++) if (i != j && matrica[j][e].a != 0)
		{
			t = frac (-matrica[j][e].a, matrica[j][e].b);
			dodaj (matrica[j], matrica[i], t);
			dodaj (jedinicna[j], jedinicna[i], t);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (matrica[i][i].a != 1) for (int j = i + 1; j < n; j++) if (matrica[j][i].a == 1)
		{
			swap (matrica[i], matrica[j]);
			swap (jedinicna[i], jedinicna[j]);
			break;
		}
	}

	cout << "{";
	for (int i = 0; i < n; i++) {
		cout << "{";
		for (int j = 0; j < n; j++) {
			if (jedinicna[i][j].b != 1)
				cout << jedinicna[i][j].a << "/" << jedinicna[i][j].b;
			else cout << jedinicna[i][j].a;
			if (j != n - 1) cout << ",";
		}
		cout << "}";
		if (i != n - 1) cout << ",";
	}
	cout << "}" << flush;

	return 0;
}
