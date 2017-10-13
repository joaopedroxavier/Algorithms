#include <bits/stdc++.h>

using namespace std;


#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=2e1+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll n, l;
ll p[N][N];

int countbits(int x){
  int ans = 0;
  x /= 2;
  while(x){
    ans += x % 2; x /= 2;
  }
  return ans;
}

int main(){
  scanf("%lld %lld", &n, &l);
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%lld", &p[i][j]);

  if(n == 2) return printf("%s\n", p[1][2] + p[2][1] == l ? "possible" : "impossible"), 0;

  for(int q=4;q<(1<<(n+1));q = q+4){

    if(countbits(q) == n/2){  

      vector<int> v1, v2;
      set<ll> has;

      //printf("%d %d\n", q, countbits(q));
      for(int i=2;i<=n;i++){
        if (q & (1<<i))v1.pb(i);
        else v2.pb(i);
      }

      do{
        int s = v2.size(); ll sum = 0;
        //printf("%d ", v2[0]);
        for(int i=1;i<s;i++){
        //  printf("%d ", v2[i]);
          sum += p[v2[i-1]][v2[i]];
        }
        //printf(": %lld \n", sum);
        has.emplace(sum + p[v2[s-1]][1]);
      } while(next_permutation(v2.begin(), v2.end()));

      do{
        int s = v1.size(); ll sum = 0;
        for(int i=1;i<s;i++) sum += p[v1[i-1]][v1[i]];
        for(int j : v2) if(has.count(l - sum - p[1][v1[0]] - p[v1[s-1]][j])) return printf("possible\n"), 0;
      } while(next_permutation(v1.begin(), v1.end()));

    }

  }
  printf("impossible\n");
  return 0;
}

