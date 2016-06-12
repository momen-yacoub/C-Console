#include<iostream>
#include<windows.h>
using namespace std;
void print(char a[3][3]){
	int m=0,n=0;
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			if(i%2 != 0 && j%2 != 0){
				cout<<a[n][m];
				m++;
				if(m==3){
					m=0;	n++;
				}
			}			
			else cout<<":";
			}
		cout<<endl;
	}
}
int main(){
	system("color 5");
	char a[3][3]={'1','2','3','4','5','6','7','8','9'};
	print(a);
	int z=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int b=1;
			char n,m;
			if(i==0 && j==0){
				cout<<"ENTER THE SHAPE of p1 (X or O): ";
				cin>>m;
				m=toupper(m);
			}
			cout<<"ENTER THE NUMBER: ";
			cin>>n;		
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if(n==a[k][l])
						a[k][l]=m;
					else b++;
				}
			}
			if(b==10){
				j--;
				continue;
			}
			system("cls");
			print(a);	z++;
			if(m=='O')	m='X';
			else m='O';
			if((a[0][0]==a[1][1] && a[0][0]==a[2][2]) || (a[0][2]==a[1][1] && a[0][2]==a[2][0])){
				cout<<"p"<<z<<" is win";
				return 0;
			}	
			else {
				for(int x=0;x<3;x++){
					if(a[x][0]==a[x][1] && a[x][0]==a[x][2]){
						cout<<"p"<<z<<" is win";
						return 0;
					}
				}
				for(int x=0;x<3;x++){
					if(a[0][x]==a[1][x] && a[0][x]==a[2][x]){
						cout<<"p"<<z<<" is win";
						return 0;
					}
				}
			}
			if(z==2)	z=0;
		}
	}
	system("pause");
	return 0;
}
