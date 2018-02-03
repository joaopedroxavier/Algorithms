#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, k, cont;
int v[N];

void process(int l, int r) {
  if(cont == k) { 
    return; 
  }

  if(r <= l+1) return;

  int m = (l+r)/2;
  cont+=2;
  swap(v[m-1], v[m]);
  process(l, m);
  process(m, r);
}

int main(){
  scanf("%d %d", &n, &k);

  for(int i=1; i<=n; i++) v[i] = i;

  if(k%2 == 0 or k >= 2*n) return printf("-1\n"), 0;

  cont = 1;
  process(1, n+1);

  for(int i=1; i<=n; i++) printf("%d ", v[i]);
  printf("\n");

	return 0;
}

