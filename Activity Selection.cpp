//Activity Selection Problem
#include <iostream>
using namespace std;
#define max 100
struct task {
  int ser;
  int start;
  int finish;
};
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void sort_fin(task act[],int n) {
int i, j;
 for (i = 0; i < n-1; i++)
     for (j = 0; j < n-i-1; j++)
         if (act[j].finish > act[j+1].finish){
            swap(act[j].finish,act[j+1].finish);
            swap(act[j].ser,act[j+1].ser);
            swap(act[j].start,act[j+1].start);
         }
}
void print_actv(task act[],int n){
  if(n==0){
    return;
  }
  if(n!=1)
    sort_fin(act,n);
  int i,j;
  cout<<"The following activities will be performed in this order:-\n";
  cout<<act[0].ser<<" ";
  if(n==1)
    return;
  i = 0;
  j = 1;
  for(j=1;j<n;j++){
    if(act[j].start>=act[i].finish){
      cout<<"-->"<<act[j].ser<<" ";
      i = j;
    }
  }
}
int main(){
  cout<<"Enter the no. of activities :- ";
  int n;
  cin>>n;
  task act[max];
  int i =0;
  cout<<endl;
  while(i!=n){
    cout<<"\n Enter the start and finish time of task("<<i+1<<"):- \n";
    act[i].ser = i+1;
    cin>>act[i].start;
    cin>>act[i].finish;
    if(act[i].finish<act[i].start){
      cout<<"error!!!\n\t please re-enter start and finish time of this task\n";
      cin>>act[i].start;
      cin>>act[i].finish;
    }
    i++;
  }
  print_actv(act,n);
  return 0;
}
