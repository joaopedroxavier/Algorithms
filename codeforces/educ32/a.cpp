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

int main(){
  int n;
  scanf("%d", &n);

  vector<int> v(n);
  for(int i=0; i<n; i++) scanf("%d", &v[i]);

  int ans=0;
  for(int i=1; i<n-1; i++) {
    ans += ((v[i] > v[i-1] and v[i] > v[i+1]) or (v[i] < v[i-1] and v[i] < v[i+1]));
  }

  printf("%d\n", ans);
	return 0;
}

