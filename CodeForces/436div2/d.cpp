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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

set<int> s;
int qt[N], v[N], used[N], n, ans;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &v[i]), qt[v[i]]++;

  for(int i=1; i<=n; i++) {
    if(!qt[i]) s.insert(i);
   else ans += qt[i] - 1;
  }

  for(int i=0; i<n; i++) {
    if(qt[v[i]] == 1 and !used[v[i]]) used[v[i]] = 1;
    else {
      qt[v[i]]--;
      if(!used[v[i]] and v[i] < *s.begin()) used[v[i]] = 1;
      else v[i] = *s.begin(), s.erase(s.begin()); 
    }
  }

  printf("%d\n", ans);
  for(int i=0; i<n; i++) printf("%d%c", v[i], i == n-1 ? '\n' : ' ');
  return 0;
}

