    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    vector<ll>subs,real_ans;
    vector<pair<ll,ll>>rem;
    int cnt=0;
    
void lis(vector<ll>&v){
 vector<ll>real_anss;
        
 for(auto num:v){
  auto it=lower_bound(subs.begin(),subs.end(),num);
  if(it==subs.end()){
   subs.push_back(num);
    cnt=0;
  }
  else{
  int i=it-subs.begin();
  rem.push_back({num,i});
  cnt++;
  *it=num;
  }
 }
 real_ans=real_anss;
}

void solve(){
 vector<ll>v{10,20,1,30,2,3,4};
 lis(v);
 cout<<subs.size()<<endl;

  while(cnt>0){
  auto [x,y]=rem.back();
  subs[y]=x;
  cnt--;
  rem.pop_back();
  }
  
  for(auto it:subs)
    cout<<it<<" ";
    cout<<endl;
  }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    // int tt;  cin>>tt;
    // while(tt--)
        solve();
    }
