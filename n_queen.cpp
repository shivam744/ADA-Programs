#include<iostream>
using namespace std;
#define max 16
int count=0;
bool is_safe(int i,int j,int b,int board[][max]){
    int k,l;
    for(k=0;k<b;k++)
        if((board[i][k] == 1) || (board[k][j] == 1))
            return false;
    for(k=0;k<b;k++)
        for(l=0;l<b;l++)
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
                if(board[k][l] == 1)
                    return false;
    return true;
}
void n_queen(int board[][max],int r,int b){
	if (r == b){
		count++;
		cout<<"Sol. no "<<count<<endl;
		for (int i = 0; i < b; i++){
			for (int j = 0; j < b; j++)
				cout << board[i][j] <<"\t";
			cout << endl;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < b; i++){
		if (is_safe(r,i,b,board)){
			board[r][i] = 1;
			n_queen(board,r + 1,b);
			board[r][i] = 0;
		}
	}
}
int main(){
  cout<<"Enter the no of Queens : ";
  int n,board[max][max],i=0,j=0;
  cin>>n;
  for(i;i<n;i++){
    for(j=0;j<n;j++){
      board[i][j]=0;
    }
  }
  cout<<"possible solution for "<<n<<" queen problem is :\n\n";
  n_queen(board,0,n);
  return 0;
}
