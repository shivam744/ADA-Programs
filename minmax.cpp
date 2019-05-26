//to recursively calculate min and max in an array
#include<iostream>
using namespace std;
#define Max 100
int min(int x,int y){
  if(x>y)
    return y;
  else
    return x;
}
  int min_r(int arr[],int l,int h){
    if(l==h)
      return arr[l];
    else if (l>h)
      return arr[l];
    else{
      int mid = (l+h)/2;
      return(min(min_r(arr,l,mid),min_r(arr,mid+1,h)));
    }
  }
  int max(int x,int y){
    if(x<y)
      return y;
    else
      return x;
  }
  int max_r(int arr[],int l,int h){
    if(l==h)
      return arr[l];
    else if (l>h)
      return arr[l];
    else{
      int mid = (l+h)/2;
      return(max(max_r(arr,l,mid),max_r(arr,mid+1,h)));
    }
  }
  int main() {
    int arr[Max];
		cout<<"Enter the no. of elements: ";
		int n;
		cin>>n;
		cout<<"Enter the value of the elements:-\n";
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
    cout<<"\nMin in array = "<<min_r(arr,0,n-1);
    cout<<"\nMax in array = "<<max_r(arr,0,n-1);
    return 0;
  }
