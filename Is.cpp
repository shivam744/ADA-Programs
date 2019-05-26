//Insertion Sort
#include <iostream>
#define MAX 100
using namespace std;
	void insertsort(int arr[],int size,int lo){
		int temp=new int(arr[lo]);
        int j = lo-1;

        while((temp<arr[j])&&(j>=0))
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=temp;
				delete temp;
        if(lo<size-1)
        	insertsort(arr,size,lo+1);
	}
	int main(){
    int i,n,arr[MAX];
    cout<<"Enter the number of elements (not more than 100):";
    cin>>n;
    cout<<"\nEnter the values of elements :-\n";
 	for(i=0;i<n;i++)
        cin>>arr[i];
    insertsort(arr,n,1);
    cout<<"\nAfter Sorting:-\n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
	}
