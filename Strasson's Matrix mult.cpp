//Strassen's Matrix Multiplication
#include <iostream>
#define max 20
#include <cmath>
using namespace std;
class matrice{
  public:
    int n;
    int arr[max][max];
    matrice(){
	}
    matrice(int no){
      n = no;
    }
    void get_value(){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          cin>>arr[i][j];
        }
      }
    }
    void display(){
      int i,j;
      cout<<endl;
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
      }cout<<endl;
    }
    void split_matrice(matrice part[]){
        int num=4;
        int i=0,j=0,p=0,q=0,k=0,z,x;
        while(k!=num){
          if((k==1)||(k==3))
            z=n/2;
          if((k==0)||(k==2))
          	z=0;
          if((k==2)||(k==3))
            x=n/2;
          else 
          	x=0;
          part[k].n = n/2;
          for(p=0,i=x;p<n/2;p++,i++)
            for(q=0,j=z;q<n/2;q++,j++){
              part[k].arr[p][q]= arr[i][j];
          }
        k++;
        }
    }
    void join_mat(matrice part[]){
      int num=4;
      n = 2 * part[0].n;
      int i=0,j=0,p,q,x,z,k=1;
      while(k!=num+1){
        if(k==2||k==4){
        	z=part[0].n;
		}
        else{
			z=0;
		}
        if(k==3||k==4){
        	x=part[0].n;
		}
        else{
			x=0;	
		}
        for(p=0,i=x;p<n/2;p++,i++)
          for(q=0,j=z;q<n/2;q++,j++){
            arr[i][j]=part[k-1].arr[p][q];
        }
              k++;
      }
    }
    matrice operator+(matrice &B){
      matrice C(B.n);
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          C.arr[i][j] = arr[i][j] + B.arr[i][j];
        }
      }
      return C;
    }
    matrice operator-(matrice &B){
      matrice C(B.n);
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          C.arr[i][j] = arr[i][j] - B.arr[i][j];
        }
      }
      return C;
    }
};
matrice convert(int p[]){
	  matrice C(2);
      C.arr[0][0] = p[1] + p[2] - p[5] - p[6];
      C.arr[0][1] = p[3]+p[5];
      C.arr[1][0] = p[4] + p[6];
      C.arr[1][1] = p[0] - p[2] - p[3] - p[4];
      return C;
    }
void strassenz(matrice A,matrice B,matrice &C){
  if(B.n == 1){
    C.arr[0][0] = A.arr[0][0]*B.arr[0][0];
  }
  else if(B.n == 2){
    int p[]={0,0,0,0,0,0,0};
    p[0]= (A.arr[0][0] + A.arr[1][0])*(B.arr[0][0] + B.arr[0][1]);
    p[1]= (A.arr[0][1] + A.arr[1][1])* (B.arr[1][0] + B.arr[1][1]);
    p[2]= (A.arr[0][0] - A.arr[1][1])*(B.arr[0][0]+ B.arr[1][1]);
    p[3]= A.arr[0][0] * (B.arr[0][1]-B.arr[1][1]);
    p[4]=(A.arr[1][0] + A.arr[1][1])*B.arr[0][0];
    p[5]=(A.arr[0][1]+A.arr[0][0])*B.arr[1][1];
    p[6]=A.arr[1][1] * (B.arr[1][0]-B.arr[0][0]);
    C = convert(p);
  }
  else{
      matrice p1[4];
      matrice p2[4];
      matrice p3[4];
      A.split_matrice(p1);
      B.split_matrice(p2);
      int num=0;
      matrice p[7];
      strassenz((p1[0] + p1[2]),(p2[0] + p2 [1]),p[0]);
      strassenz((p1[1] + p1[3]),(p2[2] + p2[3]),p[1]);
      strassenz((p1[0] - p1[3]),(p2[0]+ p2[3]),p[2]);
      strassenz(p1[0],(p2[1] - p2[3]),p[3]);
      strassenz((p1[2] + p1[3]),p2[0],p[4]);
      strassenz((p1[0] + p1[1]),p2[3],p[5]);
      strassenz(p1[3],(p2[2] - p2[0]),p[6]);
      p3[0] = p[1] + p[2] - p[5] - p[6];
      p3[1] = p[3] + p[5];
      p3[2] = p[4] + p[6];
      p3[3] = p[0] - p[2] - p[3] - p[4];
      C.join_mat(p3);
    }
}
int main(){
  cout<<"Enter the size of square matrix as in the power of 2 (max = 2) :- ";
  int n;
  cin>>n;
  n = pow(2,n);
  matrice first(n);
  matrice sec(n);
  matrice final(n);
  cout<<"Enter the elements of first matrix : "<<endl;
  first.get_value();
  cout<<"Enter the elements of second matrix : "<<endl;
  sec.get_value();
  cout<<"Matrix 1 :- \n\n";
  first.display();
  cout<<"Matrix 2 :- \n\n";
  sec.display();
  strassenz(first,sec,final);
  cout<<"Matrix 3 :- \n\n";
  final.display();
  return 0;
}
