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

int n, m, st;
int a[N];

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) scanf("%d", &a[i]);

  for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(a[j] < a[i]) st++;

  int par = st%2;
  scanf("%d", &m);

  for(int i=0; i<m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    int num = r-l+1;
    int qt = (num*(num-1))/2;
    if(qt&1) par ^= 1;
    printf("%s\n", par ? "odd" : "even");
  }

	return 0;
}

