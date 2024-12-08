#include<bits/stdc++.h>
using namespace std;

double fractionalKnapsack(int w,vector<pair<int,int>>&item);
bool compare(pair<int,int>a,pair<int,int>b);

int main()
{
    int lim_w,num_of_product;
    cin>>lim_w>>num_of_product;

    vector<pair<int,int>>item(num_of_product);

    for(int i=0;i<num_of_product;i++)
    {
       cin>>item[i].first>>item[i].second;
    }

    double maxVal=fractionalKnapsack(lim_w,item);

    cout<<maxVal<<endl;


}

bool compare(pair<int,int>a,pair<int,int>b)
{
  double ratio1=a.first/a.second;
  double ratio2=b.first/b.second;

  return ratio1>ratio2;
}

double fractionalKnapsack(int w,vector<pair<int,int>>&item)
{
    sort(item.begin(),item.end(),compare);

    double maxVal=0;
    double currentWeight=0;

    for(auto& a:item)
    {
        if(currentWeight+a.second<=w)
        {
            currentWeight+=a.second;
            maxVal+=a.first;
        }
        else 
        {
            double remaining_w=w-currentWeight;
            maxVal+=remaining_w/a.second*a.first;
            break;
        }
    }

    return maxVal;
}