#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,m; std::cin>>n>>m;
  long a,b; std::cin>>a>>b;
  long p,w; int h; std::cin>>p>>h>>w;

  std::vector<std::pair<long,int>> as;
  for(int i=0;i<n;++i){
    long pi; int hi; cin>>pi>>hi;
    as.emplace_back(pi,hi);
  }

  std::vector<long> bs;
  for(int i=0;i<m;++i){
    long wi; std::cin>>wi;
    bs.push_back(wi);
  }
  std::sort(bs.begin(),bs.end(),std::greater<long>());

	// dp: (#A used, sum h_i) -> sum p_i
  vector<vector<long>> dp(n+1,vector<long>(h+1,-1));

	dp[0][0]=0;
  for(int ai=0;ai<n;++ai){ // current potion to add
    for(int i=ai;i>=0;--i){ // potion tuple sizes to look at (can max be the amoutn of potions added so far)
      for(int j=0;j<h+1;++j){ // amount of h that was computed
        if(dp[i][j]!=-1){
          int k=min(h,j+as[ai].second);
          dp[i+1][k]=max(dp[i+1][k],dp[i][j]+as[ai].first);
        } 
      }
    }
  }

  int numb=0; long sumw=0; //sumw is ammount of wit we get from b-s afforded to us by given ammount of power
  while(sumw<w){
    sumw+=bs[numb++];
    p+=b;
  }
  while(numb<=m){
    long imax;
    if(a==0) imax=min((sumw-w),(long)n);
    else imax=min((sumw-w)/a,(long)n);
		
    for(long i=0;i<=imax;++i){
      //cout<<"almost "<<i<<" "<<dp[i][h]<<" "<<p<<"\n";
      if(dp[i][h]>=p){
        std::cout<<i+numb<<"\n";
        return;
      }
    }
    sumw+=bs[numb++];
    p+=b;
    if(a==0) break;
  }
  
  std::cout<<-1<<"\n";
  return;
}

int main(){
  int cases; std::cin>>cases;
  while(cases--){
    solve();
  }
  return 0;
}