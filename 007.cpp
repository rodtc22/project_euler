#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

template <typename A,typename B> ostream& operator <<(ostream& os, pair<A,B>& p) { return os << "(" << p.first << ", " << p.second << ")";}
template <typename T> ostream& operator <<(ostream& os, vector<T>& v) {    os << "[" ;    for(int i = 0 ;i < v.size(); i++){      if(i) os <<", ";      os <<v[i];    }    os << "]";return os;}
template <typename T> istream& operator >>(istream& is, vector<T>& v){ for(auto &x : v) is >> x; return is;}
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int,int> pii;
const int inf = 2e9;
const int mod = 1e9+7;
const int N = 1e6;

void printe(){}
template <typename H, typename ...T>
void printe(H x, T... y){
   cout << ", " << x;
   printe(y...);
}

#define err(args) { cout << "DBG: " << #args << " {"; printe(args); cout << "}\n";} 

bitset<N> is;
vector<int> prime;
void sieve(){
   is.set();
   is[0] = is[1] = 0;
   for(int i =2 ;i < N ;i++)
      if(is[i] == 1)
         for(int j = i+i ; j < N ;j+=i)
            is[j] = 0;

   for(int i = 0 ;i < N ; i++)
      if(is[i])
         prime.push_back(i);

   for(int i = 0 ;i < 10 ;i ++) cout<< prime[i] <<" \n"[i==9];
}

int main(){
   sieve();
   cout << prime[10000] << endl;
   return 0;
}