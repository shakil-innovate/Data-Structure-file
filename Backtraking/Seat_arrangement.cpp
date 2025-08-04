//tutorial:https://www.youtube.com/watch?v=DKCbsiDBN6c&t=389s

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

void backtracking(vector<string>&person,vector<vector<string>>&ans,vector<string>&current,vector<bool>&used){

    if(current.size()==person.size())
    {
        ans.push_back(current);
        return;
    }

    for(int i=0; i<person.size(); i++)
    {
        if(!used[i])
        {
            used[i]=1;
            current.push_back(person[i]);

            backtracking(person,ans,current,used);

            current.pop_back();
            used[i]=false;
        }
    }

}


int main() {
 
    vector<string>person={"boy1","boy2","girl"};

    vector<vector<string>>ans;
    vector<bool>used(person.size(),0);
    vector<string>current;

    backtracking(person,ans,current,used);

    cout<<ans.size()<<endl;

    for(int i=0 ;i <ans.size() ; i++)
    {
        for(auto it:ans[i]) cout<<it<<" ";
        cout<<endl;
    }

     
}
