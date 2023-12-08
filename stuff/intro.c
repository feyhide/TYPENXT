#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
COORD coord = {0, 0};

int maker=0;
char creator[3][9]={"M.FAHAD","HAMZA M.","HAMZA H."};
void gotoxy(int x, int y) // function to set the cursor position
{
    coord.X = (SHORT)x;
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void boximoxi(){
    gotoxy(19,4);printf("********************************************************************************");
    gotoxy(99,4);printf("*");gotoxy(99,5);printf("*");gotoxy(99,6);printf("*");gotoxy(99,7);printf("*");gotoxy(99,8);printf("*");gotoxy(99,9);printf("*");gotoxy(99,10);printf("*");
    gotoxy(99,11);printf("*");gotoxy(99,12);printf("*");gotoxy(99,13);printf("*");gotoxy(99,14);printf("*");gotoxy(99,15);printf("*");gotoxy(99,16);printf("*");gotoxy(99,17);printf("*");
    gotoxy(99,18);printf("*");gotoxy(99,19);printf("*");gotoxy(99,20);printf("*");gotoxy(99,21);printf("*");gotoxy(99,22);printf("*");gotoxy(99,23);printf("*");gotoxy(99,24);printf("*");
    
    gotoxy(19,4);printf("*");gotoxy(19,5);printf("*");gotoxy(19,6);printf("*");gotoxy(19,7);printf("*");gotoxy(19,8);printf("*");gotoxy(19,9);printf("*");gotoxy(19,10);printf("*");
    gotoxy(19,11);printf("*");gotoxy(19,12);printf("*");gotoxy(19,13);printf("*");gotoxy(19,14);printf("*");gotoxy(19,15);printf("*");gotoxy(19,16);printf("*");gotoxy(19,17);printf("*");
    gotoxy(19,18);printf("*");gotoxy(19,19);printf("*");gotoxy(19,20);printf("*");gotoxy(19,21);printf("*");gotoxy(19,22);printf("*");gotoxy(19,23);printf("*");gotoxy(19,24);printf("*");
    gotoxy(19,24);printf("********************************************************************************");
}
int main(){
	int i;
    int score=0;
    int x,y,failed=0;
    char drop,entered;
    boximoxi();
    while(failed==0){
        drop = 'a'+rand()%26;
        x=19+rand()%80;
        y=5;
        while(1)
        {
            Sleep(130);
            
            gotoxy(x,y-1);printf(" ");
            gotoxy(x,y);printf("%c",drop);
            y++;
            if (_kbhit()) {
                entered = getch();
                if(y!=5){
                    gotoxy(x,y-1);printf(" ");
                }
                if(entered!=drop){
                    failed=1;
                    break;
                }else{
                    score++;
                    break;
                }
            }

            if(y==24){
                failed = 1;
                break;
            }
        }
    }
    system("cls");
    printf("S C O R E : %d ",score);   
    getch();
    return 0;
}
