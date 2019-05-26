//Quicksort
#include <iostream>
using namespace std;
#define Max 100
	void swap(int* a,int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
		}
	void display(int arr[],int n)
	{
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<arr[i]<<"\t";
		cout<<endl;
		}
	int partition(int arr[],int lo,int hi){
		int pivot = arr[hi];
		int i = (lo-1);
		for(int j =lo;j<=hi-1;j++){
			if(arr[j]<=pivot){
				i++;
				swap(&arr[i],&arr[j]);
			}
		}
		swap(&arr[i+1],&arr[hi]);
		return (i+1);
	}
	void quicksort(int arr[],int lo,int hi){
		if(lo<hi){
			int par = partition(arr,lo,hi);
			quicksort(arr,lo,par-1);
			quicksort(arr,par+1,hi);
		}
	}
	int main(){
		int arr[Max];
		cout<<"Enter the no. of elements: ";
		int n;
		cin>>n;
		cout<<"Enter the value of the elements:-\n";
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<"\n Before sorting the array is:-\n";
		display(arr,n);
		quicksort(arr, 0, n-1);
    	cout<<"\nAfter sorting array is:-\n";
    	display(arr, n);
    	return 0;
	}
