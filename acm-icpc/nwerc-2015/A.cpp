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
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, ans, l[N], r[N];
queue<int> fr;

int main(){
  scanf("%d %d", &n, &m);

  for(int i=0;i<n;i++){
    int u, v;
    scanf("%d %d", &u, &v);
    l[i] = u, r[i] = u+v;
  }

  sort(l, l+n);
  sort(r, r+n);
  int p1=0, p2=0;

  while(p1 < n){
    if(r[p2] <= l[p1]) fr.push(r[p2]), p2++;
    else{
      while(!fr.empty() and fr.front() < l[p1] - m) fr.pop();
      if(fr.empty()) ans++;
      else fr.pop();
      p1++;
    }
  }

  printf("%d\n", n-ans);
	return 0;
}

