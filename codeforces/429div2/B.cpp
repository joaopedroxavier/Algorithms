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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll v[N];
ll sum, n;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;i++) cin >> v[i];
  for(int i=0;i<n;i++) if(v[i]%2){
    cout << "First" << endl;
    return 0;
  }
  cout << "Second" << endl;
	return 0;
}

