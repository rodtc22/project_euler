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

//learning variadic functions :D
void print(){cout  <<"}"<<  endl;}
template <typename T, typename... Types>
void print(T x,Types ...args){
   cout << " " << x;
   print(args...);
}
#define error(args...) {cout <<"DBG: "<< #args << " = {";print(args);}

int lcm(int a, int b) {return a * __gcd(a,b) * b;}
int f(int n) {return n * (n+1) >> 1;}


/*ir hasta sqrt(x), por que solo hay divisores hasta alli*/

bitset<N> is;
vector<int> prime;
void sieve(){
   is.set(); //ponwer en unos
   is[0] = is[1] = 0;
   for(int i = 2 ;i < N ;i++){
      if(!is[i]) continue;
      prime.push_back(i);
      for(int j = i+i ;j < N ;j +=i) is[j] = 0;
   }
}

ll find_largest_prime_factor(ll x){ //sqrt(x)
   ll div = x;
   for(auto p : prime){
      if(1ll*p*p <= x ){
         if(x%p == 0)
            div = p;
      }else{
         break;
      }
   }
         
   return div; //ese mismo numero es primo
}

int main(){
   ll x = 600851475143;
   sieve();
   cout << find_largest_prime_factor(x) << endl;
   return 0;
}