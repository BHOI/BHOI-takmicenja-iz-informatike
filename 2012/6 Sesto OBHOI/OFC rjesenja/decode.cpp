#include <cstdio>
using namespace std;

#define NULL_POINTER 0

struct NODE{
	char val;
	NODE * left;
	NODE * right;
	NODE(){ left = right = NULL_POINTER; val = 0; }
} root;

inline void Insert( char sign )
{
	NODE * node = &root;
	char cc;
	while ((cc = getchar()) != '0' && cc != '1');
	while (cc == '1' || cc == '0'){
		if (cc == '0'){
			if (node->left == NULL_POINTER) node->left = new NODE;
			node = node->left;
		}
		else {
			if (node->right == NULL_POINTER) node->right = new NODE;
			node = node->right;
		}
		cc = getchar();
	}
	node->val = sign;
}

int main()
{
	freopen("decode7.in", "r", stdin);
	freopen("decode7.out", "w", stdout);
	int n;
	char cc;
	scanf("%d\n", &n);
	for (int i=0; i<n; i++){
		scanf("%c", &cc);
		Insert(cc);
	}
	NODE * node = &root;
	while ((cc = getchar()) != '0' && cc != '1');
	while (cc == '0' || cc == '1'){
		if (cc == '0'){
			node = node->left;
			cc = getchar();
		}
		else {
			node = node->right;
			cc = getchar();
		}
		if (node->val) {
			putchar(node->val);
			node = &root;
		}
	}
	printf("\n");
	return 0;
}
