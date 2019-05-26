//knapsack problem with Greedy meathod and Dynamic programing
#include<iostream>
using namespace std;
#define max2 100
struct items {
  int w;
  float val,prop;
};
int max(int a, int b) { return (a > b)? a : b; }
void swap(float *xp, float *yp)
{
  float temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void swap(int *xp, int *yp)
{
  float temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void sort(items item[],int n,int ch) {
  int i,j;
  if(ch == 0){
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (item[j].val > item[j+1].val){
              swap(&item[j].w,&item[j+1].w);
              swap(&item[j].prop,&item[j+1].prop);
              swap(&item[j].val,&item[j+1].val);
            }
    }
   else{
     for (i = 0; i < n-1; i++)
         for (j = 0; j < n-i-1; j++)
             if (item[j].prop > item[j+1].prop){
               swap(&item[j].w,&item[j+1].w);
               swap(&item[j].prop,&item[j+1].prop);
               swap(&item[j].val,&item[j+1].val);
             }
   }
}
float knapsack_greedy_nonfrac(items item[],int n,int w){
  //for non fractional:
    if (n == 0 || w == 0)
       return 0;
    else if(w < item[n-1].w){
      return knapsack_greedy_nonfrac(item,n-1,w);
    }
    else{
    return max( item[n-1].val + knapsack_greedy_nonfrac(item,n-1,w-item[n-1].w),
                    knapsack_greedy_nonfrac(item,n-1,w)
                  );
    }
}
float knapsack_greedy_frac(items item[],int n,int w){
  //for fractional:
    if (n == 0 || w == 0)
       return 0;
    else if(w < item[n-1].w){
      return (item[n-1].prop*w);
    }
    else{
    return (item[n-1].val + knapsack_greedy_frac(item,n-1,w-item[n-1].w));
    }
}
float knapsack_dyanmic_nonfrac(items item[],int n,int w){
  //for dynamic prog nonfractional
  int i,j;
  float K[n+1][w+1]; //bottom up manner
  for (i = 0; i <= n; i++){
      for (j = 0; j <= w; j++){
          if (i==0 || j==0)
              K[i][j] = 0;
          else if (item[i-1].w <= j)
                K[i][j] = max(item[i-1].val + K[i-1][j-item[i-1].w],  K[i-1][j]);
          else
                K[i][j] = K[i-1][j];
      }
  }
  return K[n][w];
}
float knapsack_dyanmic_frac(items item[],int n,int w){
  //for dynamic prog fractional
  int i,j;
  float K[n+1][w+1]; //bottom up manner
  for (i = 0; i <= n; i++){
      for (j = 0; j <= w; j++){
          if (i==0 || j==0)
              K[i][j] = 0;
          else if (item[i-1].w <= j)
                K[i][j] = item[i-1].val + K[i-1][j-item[i-1].w];
          else
                K[i][j] = item[i-1].prop*j;
      }
  }
  return K[n][w];
}
int main() {
  cout<<"Enter the no of items max(100) :- ";
  int n,i=0,w;
  float result;
  cin>>n;
  items item[max2];
  cout<<"\nEnter the weight of bag :- ";
  cin>>w;
  while(i!=n){
    cout<<"\nEnter the weight and value of item "<<i+1<<endl;
    cin>>item[i].w>>item[i].val;
    item[i].prop = item[i].val/item[i].w;
    i++;
  }
  //cout<<"\nUsing greedy meathod and non fraction approach result is: ";
//  sort(item,n,0);
  //result = knapsack_greedy_nonfrac(item,n,w);
  //cout<<result;
  sort(item,n,1);
  cout<<"\nUsing greedy meathod approach result is: ";
  result = knapsack_greedy_frac(item,n,w);
  cout<<result;
  sort(item,n,0);
  cout<<"\nUsing dynamic programing0 result is: ";
  result = knapsack_dyanmic_nonfrac(item,n,w);
  cout<<result;
  //sort(item,n,1);
//  cout<<"\nUsing dynamic programing and fraction approach result is: ";
  //result = knapsack_dyanmic_frac(item,n,w);
  //cout<<result;
  return 0;
}
