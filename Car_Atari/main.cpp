#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <ctime>
using namespace std;
char square[10] = {' ','1','2','3','4','5','6','7','8','9'};
void XO_game(string x, int &n,int &m ,int level);
int checkwin();
void board(string y,int &com,int &pla);
void comp_move();
void comp_move_esay();
void car_game();
void XO_all_game();
void snake();
struct coor
       {
       int X;
       int Y;
       };
void GOTOw ( COORD r ){
     SetConsoleCursorPosition(GetStdHandle ( STD_OUTPUT_HANDLE), r);
     }

int main()
{
    int choice = 0;
    while(true){
    cout<<"\t\tWelcome To Our Game Center"<<endl<<endl;
    cout<<"Choose A Game"<<endl;
    cout<<"1- Car Game"<<endl;
    cout<<"2- Tic Tac Toe"<<endl;
    cout<<"3- Snake"<<endl;
    cout<<"4- Exit"<<endl;
    cout<<"Your Choice : ";
    cin>>choice;
    if(cin.fail()){
        cout<<"Error the game will close"<<endl;
                        getch();
                        break;
    }
    system("CLS");
    if(choice == 1){
        car_game();
    }
    else if(choice == 2){
        XO_all_game();
    }
    else if(choice == 3){
       snake();
    }
    else if(choice == 4){
        cout<<"\tGoodBye"<<endl;
        return 0;
    }


    system("CLS");
  }
  return 0;
}
void car_game()
{
    string arr[10];
    arr[0]="************************      ***";
    arr[1]="****************      ***********";
    arr[2]="*****      **********************";
    arr[3]="***********      ****************";
    arr[4]="**************      *************";
    arr[5]="***      ************************";
    arr[6]="******      *********************";
    arr[7]="***************      ************";
    arr[8]="**      *************************";
    arr[9]="****************      ***********";
    cout<<"Enter the player name : ";
    string name_car;
    cin>>name_car;
    COORD r;
    string charr;
for (int i = 0 ; i < 26 ; i++)  cout<<"*                               *"<<endl;
do{
        bool e = 0;
string s = "*              !-!              *";
//cout<<s<<endl;

for(int k = 0; k < 10; k++){
    if(e)
        break;
for (int i = 0 ; i < 27 ; i++){
    if(e)
        break;
    Sleep(100);
    r.X = 0;
    r.Y = i-1;
    GOTOw(r);
       cout<<"*                               *"<<endl;
       r.Y= i;
       GOTOw(r);
       cout<<arr[k]<<endl;
       char x;
     while ( kbhit() )
                    {
       x=getch();
       if (x==75) {
                  int z=s.find("!-!");
                  s[z-1]='!';
                  s[z]='-';
                  s[z+1]='!';
                  s[z+2]=' ';
                  }
       else if (x==77)
                      {
                      int z=s.find("!-!");
                      s[z]=' ';
                      s[z+1]='!';
                      s[z+2]='-';
                      s[z+3]='!';
                      }
                    }
       r.Y=26;
       GOTOw(r);
       if(i==26){
        int ca= s.find("!");
        int mtab = arr[k].find(" ");
        if(!(ca>= mtab && ca <= mtab+3)){
            system("cls");
            cout << "              GAME OVER !-!" << endl;
            e=1;
            getch();
            break;
          }
       }
       cout<<s<<endl;
       int n = count(s.begin(),s.end(),'*');
       if(n!=2) {
            cout << "              GAME OVER !-!" << endl;
            getch();
            e=1;
            break;
            }
       }
}

            system("cls");
            if(!e)
            cout << "            You Win !-!" << endl;

            cout<<"wanna try again Press 'y'"<<endl;
            cin>>charr;
    }while(charr == "y");
}

void XO_game(string x,int &n,int &m , int level){

int player = 1 , i , choice;
    char mark;
        system("cls");
        do
        {
                board(x,n,m);
                if(player%2!=0){
            player=1;
            cout  << x << ", enter a number:  ";
            cin >> choice;
                if(cin.fail()){
                        cout<<"Error the game will close"<<endl;
                        getch();
                        return ;
                }
            mark='X';
            if (choice == 1 && square[1] == '1')
                        square[1] = mark;
                else if (choice == 2 && square[2] == '2')
                        square[2] = mark;
                else if (choice == 3 && square[3] == '3')
                        square[3] = mark;
                else if (choice == 4 && square[4] == '4')
                        square[4] = mark;
                else if (choice == 5 && square[5] == '5')
                        square[5] = mark;
                else if (choice == 6 && square[6] == '6')
                        square[6] = mark;
                else if (choice == 7 && square[7] == '7')
                        square[7] = mark;
                else if (choice == 8 && square[8] == '8')
                        square[8] = mark;
                else if (choice == 9 && square[9] == '9')
                        square[9] = mark;
                else
                {
                        cout<<"Invalid move ";
                        player--;
                getch();

                }
                }
                else {
                if(level == 2)
                    comp_move();
                else
                    comp_move_esay();
                }

                i=checkwin();
                player++;
        }while(i==2);

        if(i==1){

                if(--player==2){
            n++;
                board(x,n,m);
            cout<<"==>\aYou lose "<<endl;
                }
        else {
            m++;
            board(x,n,m);
            cout<<"==>\aYou win "<<endl;


        }

        }
        else
        cout<<"==>\aGame draw" <<endl;

        getch();

}

void comp_move()
{
     if(((square[2] == 'O' && square[3] == 'O') || (square[7] == 'O' && square[4] == 'O' ) || (square[9] =='O' && square[5] == 'O' ))&& square[1] == '1')
        square[1]='O';

    else if(((square[1] == 'O' && square[3] == 'O') || (square[5] == 'O' && square[8] == 'O' )) && square[2] == '2')
        square[2]='O';

    else if(((square[1] == 'O' && square[2] == 'O') || (square[6] == 'O' && square[9] == 'O') || (square[7] == 'O' && square[5] == 'O')) && square[3]== '3')
        square[3]='O';

    else if(((square[1] == 'O' && square[7] == 'O') || (square[5] == 'O' && square[6] == 'O')) && square[4] == '4')
        square[4]='O';

    else if(((square[4] == 'O' && square[6] == 'O') || (square[2] =='O' && square[8] == 'O')) && square[5] == '5')
        square[5]='O';

    else if(((square[4] =='O' && square[5] == 'O' ) || (square[3] == 'O' && square[9] =='O' ) || (square[3] =='O' && square[7] == 'O'))&& square[6] == '6')
        square[6]='O';

    else if(((square[1] == 'O' && square[4] == 'O') || (square[8] =='O' && square[9] == 'O') || (square[3] == 'O' && square[5] == 'O') )&& square[7] == '7')
        square[7]='O';

    else if(((square[2] == 'O' && square[5] == 'O') || (square[7] == 'O' && square[9] == 'O'))&& square[8] == '8')
        square[8]='O';

    else if(((square[3] == 'O' && square[6] == 'O') || (square[1] == 'O' && square[5] == 'O') || (square[7] == 'O' && square[8] == 'O')) && square[9] == '9')
        square[9]='O';

    else if((square[2] == square[3] || square[7] == square[4] || square[9] == square[5] )&& square[1] == '1')
        square[1]='O';

    else if((square[1] == square[3] || square[5] == square[8] )&& square[2] == '2')
        square[2]='O';

    else if((square[1] == square[2] || square[6] == square[9] || square[7] == square[5]) && square[3]== '3')
        square[3]='O';

    else if((square[1] == square[7] || square[5] == square[6]) && square[4] == '4')
        square[4]='O';

    else if((square[4] == square[6] || square[2] == square[8]) && square[5] == '5')
        square[5]='O';

    else if((square[4] == square[5] || square[3] == square[9] || square[3] == square[7]) && square[6] == '6')
        square[6]='O';

    else if((square[1] == square[4] || square[8] == square[9] || square[3] == square[5]) && square[7] == '7')
        square[7]='O';

    else if((square[2] == square[5] || square[7] == square[9]) && square[8] == '8')
        square[8]='O';

    else if((square[3] == square[6] || square[1] == square[5] || square[7] == square[8]) && square[9] == '9')
        square[9]='O';

    else if(square[5] == '5')
        square[5]='O';

    else if(square[1] == 'X' && square [9] == 'X' && square[2] == '2')
        square [2] = 'O';

    else if(square[1] == 'X' && square [9] == 'X' && square[4] == '4')
        square [4] = 'O';

    else if(square[1] == 'X' && square [9] == 'X' && square[6] == '6')
        square [6] = 'O';

    else if(square[1] == 'X' && square [9] == 'X' && square[8] == '8')
        square [8] = 'O';

    else if(((square[6] == 'X' && square[7] == 'X') || (square[8] == 'X' && square[3] == 'X') || (square[6] == 'X' && square[8] == 'X')) && square[9]=='9')
        square[9]= 'O';

    else{
        for(int i=1;i<=9;i++){
            if(square[i]!='O' && square[i]!='X'){
                square[i] = 'O';
                break;
            }
        }
    }

}
void comp_move_esay()
{
    srand (time(NULL));
    for(int i = 0 ;  ; i++){
        int n = rand()%9 + 1 ;
        if(square[n] != 'O' && square[n] != 'X'){
            square[n] = 'O';
            return;
            }
    }
}
int checkwin()
{
        if (square[1] == square[2] && square[2] == square[3])
                return 1;
        else if (square[4] == square[5] && square[5] == square[6])
                return 1;
        else if (square[7] == square[8] && square[8] == square[9])
                return 1;
        else if (square[1] == square[4] && square[4] == square[7])
                return 1;
        else if (square[2] == square[5] && square[5] == square[8])
                return 1;
        else if (square[3] == square[6] && square[6] == square[9])
                return 1;
        else if (square[1] == square[5] && square[5] == square[9])
                return 1;
        else if (square[3] == square[5] && square[5] == square[7])
                return 1;
        else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4'
 && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
                return 0;
        else
                return 2;
}

void board(string y ,int &com, int &pla)
{
        system("cls");
        cout << "\n\n\tX  O  game\n\n";
        cout << y <<" (X)  -  Computer (O)" << endl << endl;
        cout<<"Score :"<<pla<<"   "<<com<<endl;
        cout << endl;
        cout << " ---------------- " << endl;
        cout << "     |     |     |  " << endl;
        cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] <<"  |  "<< endl;
        cout << "_____|_____|_____|" << endl;
        cout << "     |     |     |" << endl;
        cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] <<"  |  "<< endl;
        cout << "_____|_____|_____|" << endl;
        cout << "     |     |     |" << endl;
        cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] <<"  |  "<< endl;
        cout << "     |     |     |  " << endl;
        cout << " ---------------- " << endl;
}

void XO_all_game()
{
    vector <string> names;
    vector <int> scores_P;
    vector<int> scores_C;
    ifstream xo;
    xo.open("DATA.txt");
    while(xo.good()){
        string name ;
        int score_P=0 , score_C=0;
        xo>>name>>score_P>>score_C;
        if (score_P==0&&score_C==0) {}
        else {
        names.push_back(name);
        scores_P.push_back(score_P);
        scores_C.push_back(score_C);
        }
    }
    xo.close();
 ///////////////////////////////////////////////////////////////////////////

    char choice_xo;
    int level = 0;
    string player_name;
    int c1 = 0 , c2 = 0;
    cout<<"Your Name : ";
    cin>>player_name;
    while(true){
        system("cls");
    cout<<"Enter your level"<<endl;
    cout<<"1.Easy"<<endl;
    cout<<"2.Hard"<<endl;
    cin>>level;
    if(cin.fail()){
        cout<<"Error the game will close"<<endl;
                        getch();
                        return;
    }
    if(level == 1 || level == 2)
        break;
    }
    for (int i = 0 ; i < names.size() ; i++){
        if (player_name==names[i]) {
            c1=scores_P[i];
            c2=scores_C[i];
        }
    }
    if (c1==0&&c2==0) {
            names.push_back(player_name);
            scores_P.push_back(c1);
            scores_C.push_back(c2);
    }
    do{
        square[1]= '1';
        square[2]= '2';
        square[3]= '3';
        square[4]= '4';
        square[5]= '5';
        square[6]= '6';
        square[7]= '7';
        square[8]= '8';
        square[9]= '9';

        XO_game(player_name , c1 , c2 ,level);
        cout<<"Press 'y' to try again or 'e' to exit "<<endl;
        cin>>choice_xo;
    }while (choice_xo=='y');

    for (int  i = 0 ; i < names.size() ; i++){
    if (player_name==names[i]){
        scores_P[i]=c1;
        scores_C[i]=c2;
    }
}
    ofstream out;
    out.open("DATA.txt");
    for (int i = 0; i<names.size() ; i++ ) {
        out<<names[i]<<" "<<scores_P[i]<<" "<<scores_C[i]<<endl;
    }
    out.close();
}

void snake()
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
for (int o=0; ;o++) {
        bool Q=0;
 for (int i=0;i<24;i++) {cout<<s[i]<<endl;}
 if (kbhit()) {char T=x;
                 x=getch(); if (x==32) {
                                       system("cls"); cout<<"1_continue \n2- Exit\n3-Save changs\n   choose : "; int y; cin>>y;
                                       if (y==1) {continue ;}
                                       else if (y==2) {cout<<"YOUR SCORE : "<<S-4<<endl<<"YOUR NAME : "<<G; remove( "continue.txt" ); Sleep (600);   return ;

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
                                            return ;

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




if (B==0 ) {system("CLS"); cout<<"YOUR SCORE : "<<S-4<<endl<<"YOUR NAME : "<<G;
           Sleep(900);
           system("CLS");
            cout<<"\n\n\n\n\n \t \t\t\t GAME OVER "<<endl;
            remove( "continue.txt" );
            Sleep(500);

            system("CLS");
           cout<<"1.PLAY AGAIN\n2.EXIT\nCHOOSE WHAT U WANT :";
           int t;
           cin>>t;
           system("cls");
           if (t==1) {goto ss; }
           else if (t==2) {cout<<"\tGOODBYE :D"; Sleep(1000); return ; }

           }
system("cls");


          }
}
