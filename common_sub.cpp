//longest common subsequence using dynamic programing
#include<iostream>
using namespace std;
#include<string>
string max(string a, string b) {
  return (a.length() > b.length())? a : b;
}
string common_sub(string first,string sec){
  int n1 = first.length(),n2 = sec.length(),i=0,j=0;
  string k[n1+1][n2+1];
  for(i=0;i<=n1;i++)
    for(j=0;j<=n2;j++){
      if(i==0||j==0){
        k[i][j] = "";
      }
      else if(first[i-1]==sec[j-1]){
        k[i][j] = "";
        k[i][j] += k[i-1][j-1];
        k[i][j] += first[i-1];
      }
      else{
        k[i][j] = max(k[i-1][j] , k[i][j-1]);
      }
    }
  return k[n1][n2];
}
int main(){
  string first,sec,common;
  cout<<"Enter the value of first string : ";
  cin>>first;
  cout<<"Enter the value of second string : ";
  cin>>sec;
  common = common_sub(first,sec);
  cout<<endl<<"Longest common subsequence is : "<<common<<" and its length is : "<<common.length();
  return 0;
}
