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

set<int> s;
int ans;

int main(){
  int n, x;
  scanf("%d %d", &n, &x);
  for(int i=0, j; i<n; i++) scanf("%d", &j), s.insert(j);

  for(int i=0; i<x; i++) if(!s.count(i)) ans++;
  printf("%d\n", ans + (int) s.count(x));

	return 0;
}

