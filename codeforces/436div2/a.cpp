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

map<int, int> m;
int n;

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    int v;
    scanf("%d", &v);
    m[v]++;
  }

  if(m.size() != 2) return printf("NO\n"), 0;
  if((m.begin()) -> second != (m.rbegin()) -> second) return printf("NO\n"), 0;

  printf("YES\n");
  for(auto v : m) printf("%d ", v.first);
  printf("\n");

	return 0;
}

