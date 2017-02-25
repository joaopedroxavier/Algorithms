#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct Node{
  ll id, father, sum, size;
  bool is_valid;
  Node(ll a, ll b, ll c): id(a), father(b), sum(c), size(1), is_valid(false) {}
};

vector<Node> nodes;

void unify(ll a, ll b);
ll root(ll a);

int main (){
  ll n ;
  vector<ll> num, seq, sum;
  ll highest = 0;
  cin >> n;
  nodes.push_back(Node(0,0,0));
  for (ll i = 0 ; i < n; ++i){
    ll aux;
    cin >> aux;
    num.push_back(aux);
    nodes.push_back(Node(i+1,i+1,aux));
  }
  nodes.push_back(Node(n+1,n+1,0));
  for (ll i = 0 ; i < n ; ++i){
    ll aux;
    cin >> aux;
    seq.push_back(aux);
  }
  sum.push_back(0);
  for (ll i = n-1; i > 0 ; --i){
    ll id = seq[i];
    ll now = 0;
    nodes[id].is_valid = true;
    if (nodes[id-1].is_valid) 
      unify(id, id-1);
    if (nodes[id+1].is_valid)
      unify(id, id+1);
    now = nodes[root(id)].sum;
    if (now > highest) highest = now;
    sum.push_back(highest);
  }
  for (ll i = sum.size()-1 ; i >= 0 ; --i){
    cout << sum[i] << endl;
  }
  return 0;
}

ll root(ll a){
  return nodes[a].father == nodes[a].id ? nodes[a].id : root(nodes[a].father);
}

void unify(ll a, ll b){
  ll a1 = root(a);
  ll b1 = root(b);
  if (nodes[a1].size > nodes[b1].size){
    nodes[b1].father = a1;
    nodes[a1].size += nodes[b1].size;
    nodes[a1].sum += nodes[b1].sum;
  } else {
    nodes[a1].father = b1;
    nodes[b1].size += nodes[a1].size;
    nodes[b1].sum += nodes[a1].sum;
  }
}

