//
//
//
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

int n;
int visa[N], visb[N];
int a[N], b[N];
int p1[N], p2[N], exca, exb, cont, cont1a, cont1b, cont2a, cont2b, missa;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=1;i<=n;++i) cin >> a[i];
  for(int i=1;i<=n;++i) cin >> b[i];
  for(int i=1;i<=n;++i) visa[a[i]]++, visb[b[i]]++;
  for(int i=1;i<=n;++i){
    if(visa[i] > 1) exca = i;
    if(!visa[i]) missa = i;
  }
  for(int i=1;i<=n;++i){
    p1[i] = p2[i] = a[i];
    if(a[i] == exca and cont==0) p1[i] = missa, cont++;
    else if(a[i] == exca and cont==1) p2[i] = missa;
  }
  for(int i=1;i<=n;++i){
    if(p1[i] != a[i]) cont1a++;
    if(p1[i] != b[i]) cont1b++;
    if(p2[i] != a[i]) cont2a++;
    if(p2[i] != b[i]) cont2b++;
  }

  for(int i=1;i<=n;++i) cout << ((cont1a == 1 and cont1b == 1) ? p1[i] : p2[i]) << ' ';
  cout << endl;
	return 0;
}

