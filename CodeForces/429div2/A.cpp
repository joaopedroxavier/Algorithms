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

map<char, int> m;
string s;
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> k;
  cin >> s;
  for(char c : s) m[c]++;
  for(auto it : m) if(it.second > k){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
	return 0;
}

