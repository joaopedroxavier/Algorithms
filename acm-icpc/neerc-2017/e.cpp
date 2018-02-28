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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, a[N], f[N];
bool isgreat[N], sieve[N];
vector<int> great, low;
set<int> numbers;

int main(){
  freopen("equal.in", "r", stdin);
  freopen("equal.out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
    f[a[i]]++;
    numbers.insert(a[i]);
  }

  for(int i=0; i<N; i++) if(f[i]) {
    isgreat[i] = true;
    for(int j=2*i; j<N; j+=i) if(f[j]) isgreat[i] = false;

    great.push_back(f[i]);
    if(!isgreat[i]) low.push_back(f[i]);
  }

  sort(great.begin(), great.end());
  sort(low.begin(), low.end());

  for(int i=1; i < (int) great.size(); i++) great[i] += great[i-1];
  for(int i=1; i < (int) low.size(); i++) low[i] += low[i-1];

  for(int i=0; i<=n; i++) {
    int g = upper_bound(great.begin(), great.end(), i) - great.begin();
    int l = upper_bound(low.begin(), low.end(), i) - low.begin();

    printf("%d ", (int) great.size() - max(g-1, l));
  }
  printf("\n");

	return 0;
}

