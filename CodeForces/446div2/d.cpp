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

int n;
int a[N], b[N], ord[N];

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]), ord[i] = i;

  sort(ord, ord+n, [](int i, int j){ return a[i] < a[j]; });

  for(int i=0; i<n; i++) b[ord[i]] = a[ord[(i+1)%n]];

  for(int i=0; i<n; i++) printf("%d ", b[i]);
  printf("\n");
}

