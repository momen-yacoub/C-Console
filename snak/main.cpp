#include <cstdlib>
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
struct coor
       {
       int X;
       int Y;
       };


int main()
{
ss: system("color B");
ifstream AMR;
bool pool=0;
AMR.open("continue.txt");
if (AMR.good()){pool=1;}

string G;
int F;
         if (pool==0)
                    { cout<<"ENTER YOU NAME :"; cin>>G;
                      cout<<"1- hard \n2- normal \n3- easy \nput ur level please : ";
                     cin>>F;
                    }
         else {AMR>>G>>F;}

if (F==1) {F=15;} else if (F==2) {F=25;} else if(F==3) {F=35;}

int S=4;
if (pool==1) {AMR>>S;}
vector <coor> v(S);

string s[24];
if (pool==0) {
             for (int i=0;i<24;i++) {for (int x=0;x<79;x++) {if (i==0||i==23||x==0||x==78) {s[i]+="*";} else {s[i]+=" ";} } }
             }
else {bool k=0;
     for (int i=0;i<24;i++) {string l;
                            if (k==0) {k=1; i=-1; getline(AMR,l); continue;}
                            getline(AMR,s[i]);

                            }/// mt7awelsh tfhm el7ta deeeh 3shan 5ne2a fokak :D :P AMR
     }
if (pool==0)
            {
            s[3][5]='x'; s[3][6]='O'; s[3][7]='O'; s[3][8]='X';

v[0].X=3; v[0].Y=5;
v[1].X=3; v[1].Y=6;
v[2].X=3; v[2].Y=7;
v[3].X=3; v[3].Y=8;
           }
else if (pool==1)
                {
                for (int i=0;i<S;i++) {
                                       AMR>>v[i].X; AMR>>v[i].Y;
                                      }
                }
AMR.close();
int x1=v[S-1].X,y1=v[S-1].Y;
if (pool==0) {s[8][7]='0';}

char x=77;
for (int o=0; ;o++) {bool Q=0;




 for (int i=0;i<24;i++) {cout<<s[i]<<endl;}
 if (kbhit()) {char T=x;
                 x=getch(); if (x==32) {
                                       system("cls"); cout<<"1_continue \n 2- Exit\n 3-Save changs\n choose : "; int y; cin>>y;
                                       if (y==1) {continue ;}
                                       else if (y==2) {cout<<"YOUR SCORE : "<<S-4<<endl<<"YOUR NAME : "<<G; remove( "continue.txt" ); Sleep (600);   return 0;

                                                      }
                                       else {cout<<"YOUR SCORE : "<<S-4<<endl<<"YOUR NAME : "<<G;
                                            ofstream continu;
                                            continu.open("continue.txt");
                                                                   continu<<G<<endl;
                                                                   continu<<F<<endl;
                                                                   continu<<S<<endl;
                                                                 for (int i=0;i<24;i++) {continu<<s[i]<<endl;}
                                            for (int i=0;i<S;i++) {continu<<v[i].X<<"  "<<v[i].Y<<endl;}
                                            continu.close();
                                            Sleep (600);
                                            return 0;

                                            }
                                        }
                 if (x!=80&&x!=72&&x!=75&&x!=77)  {x=T;}
                }
 Sleep(F);
 if ((int)x==72)
                { int y=-1;
                for (int p=0;p<24;p++) {y= s[p].find ('X'); if (y!=-1) {if (s[p-1][y]==s[v[2].X][v[2].Y]){x=80; continue;}

                s[p][y]='O'; s[p-1][y]='X';
                v.push_back(coor());
                v[S].X=p-1;  v[S].Y=y;
                Q=1;

                                                                                                                       break; }}
                          }//lfooo2
 else if ((int)x==75)
               {int y=-1;
                for (int p=0;p<24;p++) {y=s[p].find('X'); if (y!=-1) { if (s[p][y-1]==s[v[2].X][v[2].Y]){x=77; continue;}

                s[p][y-1]='X';  s[p][y]='O';
                v.push_back(coor());
                v[S].X=p;  v[S].Y=y-1;
                Q=1;

                                                                                                                       break;}}

               }//shmal
 else if ((int)x==77)
               {int y=-1;
                for (int p=0;p<24;p++) {y=s[p].find('X'); if (y!=-1) { if (s[p][y+1]==s[v[2].X][v[2].Y]){x=75; continue;}

                s[p][y+1]='X';  s[p][y]='O';
                v.push_back(coor());
                v[S].X=p;  v[S].Y=y+1;
                Q=1;
                                                                                                                        break;}}
               }//ymeen
 else if ((int)x==80)
                     {int y=-1;
                     for (int p=0;p<24;p++) {
                                             y=s[p].find('X');
                                           if (y!=-1) { if (s[p+1][y]==s[v[2].X][v[2].Y]){x=72; continue;}

                                               s[p][y]='O'; s[p+1][y]='X';
                                               v.push_back(coor());
                                               v[S].X=p+1;  v[S].Y=y;
                                               Q=1;
                                                                                                    break;}

                                            }


                     }//t7t


if (Q==1)
        {bool j=0;
        for (int i=0;i<24;i++) {if (s[i].find('0')!=-1) {j=1;}   }

        if (j==1)
                  {
                  int x=v[0].X, y=v[0].Y;
                  s[x][y]=' ';
                  x=v[1].X, y=v[1].Y;
                  s[x][y]='x';
                  v.erase (v.begin());
                     }
        else {

              s[(rand()%22)+1][(rand()%76)+1]='0';
               S++;}
        }
int B=1;
 for (int z=0;z<24;z++) {if (s[z].find('X')<79) {int _l=s[z].find('X');
                                                          if (z==0||z==23||_l==0||_l==78) {B=0;}
                                                             }}




if (B==0 ) {system("CLS"); cout<<"\n\n\n\n\n \t \t\t\t GAME OVER "<<endl;  remove( "continue.txt" );  Sleep(500); system("CLS");
           cout<<"1.PLAY AGAIN\n2.EXIT\nCHOOSE WHAT U WANT :";
           int t;
           cin>>t;
           system("cls");
           if (t==1) {goto ss; }
           else if (t==2) {cout<<"\tGOODBYE :D"; Sleep(5000); return 0; }

           }
system("cls");


          }

    return EXIT_SUCCESS;
}
