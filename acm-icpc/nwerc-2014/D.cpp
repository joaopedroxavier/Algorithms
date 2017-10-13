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
const int N=5e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int l[N], r[N];
ll ans[N], inc[N],  n, m;
char s[N];

int main(){
  scanf("%lld %lld", &n, &m);
  for(int i=1;i<=m;i++){
    scanf(" %c %d %d", &s[i], &l[i], &r[i]);
    inc[l[i]]++, inc[r[i]]++;
  }

  queue<int> q;
  for(int i=1;i<=m;i++) if(!inc[i]) q.push(i);

  ans[1] = n;
  while(!q.empty()){
    int u = q.front(); q.pop();
    //printf("%d\n", u);
    
    ans[l[u]] += ans[u]/2;
    ans[r[u]] += ans[u]/2;

    if(ans[u] % 2){
      if(s[u] == 'L') ans[l[u]]++, s[u] = 'R';
      else ans[r[u]]++, s[u] = 'L';
    }

    if(l[u]){
      if(--inc[l[u]] == 0) q.push(l[u]);
    }
    if(r[u]){
      if(--inc[r[u]] == 0) q.push(r[u]);
    }

  }

  for(int i=1;i<=m;i++) printf("%c", s[i]);
  printf("\n");

	return 0;
}

