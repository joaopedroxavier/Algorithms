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

int n, k, x;
int a[N];

int main(){
  scanf("%d %d %d", &n, &k, &x);

  for(int i=0; i<n; i++) scanf("%d", &a[i]);

  int sum = 0;
  for(int i=0; i<n-k; i++) sum += a[i];
  for(int i=n-k; i<n; i++) sum += x;

  printf("%d\n", sum);
	return 0;
}

