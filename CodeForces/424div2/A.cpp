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

bool isUnimodal(vector<int> sample){
  int mx=0;
  for(int u : sample) mx = max(mx, u);

  auto p1 = sample.begin(), p2 = sample.end()-1;

  int cur = 0;
  while(*p1 != mx){
    if(*p1 <= cur) return false;
    cur = *p1;
    p1++;
  }
  cur = 0;
  while(*p2 != mx){
    if(*p2 <= cur) return false;
    cur = *p2;
    p2--;
  }
  while(p1 <= p2){
    if(*p1 != *p2) return false;
    p1++;
  }
  return true;
}

int main(){
	ios_base::sync_with_stdio(false);
  int n;
  vector<int> v;

  cin >> n;
  for(int i=0;i<n;++i){
    int u;
    cin >> u;
    v.push_back(u);
  }

  cout << ((isUnimodal(v)) ? "YES" : "NO") << endl;
  return 0;
}

