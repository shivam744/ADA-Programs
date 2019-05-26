// Recursive and non recurcive both 
#include <iostream>
using namespace std;
int n = 200;
int Bsearch(int Array[],int n){
		int key;
		cout<<"Enter the value of key to be found"<<endl;
		cin>>key;
		int l = 0;
		int g = n;
		int i = (l+g)/2;
		while(l<g){
			if(key == Array[i]){
				cout<<"key found and its index is equal to "<<i<<endl;
				return i;
			}
			else if(key>Array[i]){
				l = i+1;
				i = (l+g)/2;
			}
			else if(key<Array[i]){
				g = i-1;
				i = (l+g)/2;
			}
		}
		cout<<"key not found";
		return -1;
	}
	int recBsearch(int Array[],int l,int g,int key){
		int i = (l+g)/2;
		while(l<g){
			if(key == Array[i]){
				cout<<"key found and its index is equal to "<<i<<endl;
				return i;
			}
			else if(key>Array[i]){
				l = i+1;
				i = (l+g)/2;
			}
			else if(key<Array[i]){
				g = i-1;
				i = (l+g)/2;
			}
		}
		cout<<"key not found";
		return -1;
	}
int main(){
	int A[10];
	int i,n =10;
	for(i=0;i<10;i++)
	A[i] = 2*i;
	cout<<"Choose recursive(R) or non-recursive(N) meathod: "<<endl;
	char ch;
	cin>>ch;
	peace : switch(ch){
		case'R':{
			int key;
			cout<<"Enter the value of key to be found"<<endl;
			cin>>key;
			int l = 0;
			int g = n;
			i = recBsearch(A,l,g,key);
			break;
		}
		case'N':{
			i = Bsearch(A,n);
			break;
		}
		default:{
			cout<<"Please choose between R and N"<<endl;
			goto peace;
		}
	}
	
}
