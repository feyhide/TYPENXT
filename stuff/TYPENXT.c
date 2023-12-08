#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[38;5;208m"
#define TEAL "\033[38;5;37m"
#define CORAL "\033[38;5;203m"
#define INDIGO "\033[38;5;93m"
#define VIOLET "\033[38;5;163m"
#define GOLD "\033[38;5;220m"
#define NAVY "\033[38;5;18m"
#define RESET "\033[0m"
#define MAX_LINES 500
#define MAX_LENGTH 500 

int c=0;
int timeselect;
char gameT[100];
char gameM[100];


typedef struct user
{
	char name[100];
	char rollno[100];
}user;
user player;


void MainMenuDisplay(int selectedOption);
void gameModeDisplay(int selectedOption);
void gameTypeDisplay(int selectedOption);
void gameQTypeDisplay(int selectedOption);
char str[500],strC[500];
void paragraphSELECTOR();
void sentenceSELECTOR();
void quickieScrabbledSelector();
void quickieSelector();
void gameType();
void gameQType();
int setTime();
void gotoxy(int x, int y);
void gameMode();
void etsybitsy();
void mrcorrector();
void dropper();
void quickie();
void game(char str[],char strC[]);
float score=0.0;
int counting(char strC[],char entered[],int length);
int scoring(int count,int length);
void leaderboardEdit(float *wps);
void leaderboard();

int maker=0;
char** creator;

COORD coord = {0, 0};

void gotoxy(int x, int y) // function to set the cursor position
{
    coord.X = (SHORT)x;
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void usernamerollno(){
	gotoxy(19,3);printf("%s",player.name);
	gotoxy(91,3);printf("%s",player.rollno);
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
void boxipoxi(){
    gotoxy(0,4);printf("**********************************************************************************************************************");
    
	gotoxy(0,24);printf("**********************************************************************************************************************");
}
int preintro(){
    Sleep(800);gotoxy(29+15,12);printf("THIS");Sleep(800);printf(" GAME");Sleep(800);printf(" IS");Sleep(800);printf(" BROUGHT");Sleep(800);printf(" T0");Sleep(800);printf(" YOU");Sleep(800);printf(" BY");
    Sleep(2000);gotoxy(29+19,14);printf("B Y T E B U S T E R S");
    Sleep(4200);gotoxy(29+26,16);printf("2");gotoxy(29+16,16);printf("2");gotoxy(29+36,16);printf("2");
    Sleep(200);gotoxy(29+27,16);printf("3");gotoxy(29+17,16);printf("3");gotoxy(29+37,16);printf("3");
    Sleep(200);gotoxy(29+28,16);printf("K");gotoxy(29+18,16);printf("K");gotoxy(29+38,16);printf("K");
    Sleep(200);gotoxy(29+29,16);printf("-");gotoxy(29+19,16);printf("-");gotoxy(29+39,16);printf("-");
    Sleep(200);gotoxy(29+30,16);printf("1");gotoxy(29+20,16);printf("1");gotoxy(29+40,16);printf("1");
    Sleep(200);gotoxy(29+31,16);printf("2");gotoxy(29+21,16);printf("2");gotoxy(29+41,16);printf("2");
    Sleep(200);gotoxy(29+32,16);printf("3");gotoxy(29+22,16);printf("3");gotoxy(29+42,16);printf("3");
    Sleep(200);gotoxy(29+33,16);printf("4");gotoxy(29+23,16);printf("4");gotoxy(29+43,16);printf("4");
    gotoxy(29+16,17);printf("HAMZA H.");gotoxy(29+36,17);printf("HAMZA M.");gotoxy(29+26,17);printf("M.FAHAD");
    return 0;
}
int intro(){
    Sleep(150);gotoxy(29+26,14);printf("T");gotoxy(29+1,5);printf("TYPENXT");gotoxy(29+1,8);printf("TYPENXT");gotoxy(29+1,11);printf("TYPENXT");gotoxy(29+1,17);printf("TYPENXT");gotoxy(29+1,20);printf("TYPENXT");gotoxy(29+1,23);printf("TYPENXT");
    Sleep(150);gotoxy(29+27,14);printf("Y");gotoxy(29+12,5);printf("TYPENXT");gotoxy(29+12,8);printf("TYPENXT");gotoxy(29+12,11);printf("TYPENXT");gotoxy(29+12,17);printf("TYPENXT");gotoxy(29+12,20);printf("TYPENXT");gotoxy(29+12,23);printf("TYPENXT");
    Sleep(150);gotoxy(29+28,14);printf("P");gotoxy(29+22,5);printf("TYPENXT");gotoxy(29+22,8);printf("TYPENXT");gotoxy(29+22,11);printf("TYPENXT");gotoxy(29+22,17);printf("TYPENXT");gotoxy(29+22,20);printf("TYPENXT");gotoxy(29+22,23);printf("TYPENXT");
    Sleep(150);gotoxy(29+29,14);printf("E");gotoxy(29+32,5);printf("TYPENXT");gotoxy(29+32,8);printf("TYPENXT");gotoxy(29+32,11);printf("TYPENXT");gotoxy(29+32,17);printf("TYPENXT");gotoxy(29+32,20);printf("TYPENXT");gotoxy(29+32,23);printf("TYPENXT");
    Sleep(150);gotoxy(29+30,14);printf("N");gotoxy(29+42,5);printf("TYPENXT");gotoxy(29+42,8);printf("TYPENXT");gotoxy(29+42,11);printf("TYPENXT");gotoxy(29+42,17);printf("TYPENXT");gotoxy(29+42,20);printf("TYPENXT");gotoxy(29+42,23);printf("TYPENXT");
    Sleep(150);gotoxy(29+31,14);printf("X");gotoxy(29+52,5);printf("TYPENXT");gotoxy(29+52,8);printf("TYPENXT");gotoxy(29+52,11);printf("TYPENXT");gotoxy(29+52,17);printf("TYPENXT");gotoxy(29+52,20);printf("TYPENXT");gotoxy(29+52,23);printf("TYPENXT");
    Sleep(150);gotoxy(29+32,14);printf("T");gotoxy(29+1,5);printf("       ");gotoxy(29+12,5);printf("       ");gotoxy(29+22,5);printf("       ");gotoxy(29+32,5);printf("       ");gotoxy(29+42,5);printf("       ");gotoxy(29+52,5);printf("       ");
                                            gotoxy(29+1,8);printf("       ");gotoxy(29+12,8);printf("       ");gotoxy(29+22,8);printf("       ");gotoxy(29+32,8);printf("       ");gotoxy(29+42,8);printf("       ");gotoxy(29+52,8);printf("       ");
                                            gotoxy(29+1,11);printf("       ");gotoxy(29+12,11);printf("       ");gotoxy(29+22,11);printf("       ");gotoxy(29+32,11);printf("       ");gotoxy(29+42,11);printf("       ");gotoxy(29+52,11);printf("       ");
                                            gotoxy(29+1,23);printf("       ");gotoxy(29+12,23);printf("       ");gotoxy(29+22,23);printf("       ");gotoxy(29+32,23);printf("       ");gotoxy(29+42,23);printf("       ");gotoxy(29+52,23);printf("       ");                            
                                            gotoxy(29+1,20);printf("       ");gotoxy(29+12,20);printf("       ");gotoxy(29+22,20);printf("       ");gotoxy(29+32,20);printf("       ");gotoxy(29+42,20);printf("       ");gotoxy(29+52,20);printf("       ");
                                            gotoxy(29+1,17);printf("       ");gotoxy(29+12,17);printf("       ");gotoxy(29+22,17);printf("       ");gotoxy(29+32,17);printf("       ");gotoxy(29+42,17);printf("       ");gotoxy(29+52,17);printf("       ");                               
}
int outro(){
    Sleep(150);gotoxy(29+26,14);printf("G");gotoxy(29+1,5);printf("GOODBYE");gotoxy(29+1,8);printf("GOODBYE");gotoxy(29+1,11);printf("GOODBYE");gotoxy(29+1,17);printf("GOODBYE");gotoxy(29+1,20);printf("GOODBYE");gotoxy(29+1,23);printf("GOODBYE");
    Sleep(150);gotoxy(29+27,14);printf("O");gotoxy(29+12,5);printf("GOODBYE");gotoxy(29+12,8);printf("GOODBYE");gotoxy(29+12,11);printf("GOODBYE");gotoxy(29+12,17);printf("GOODBYE");gotoxy(29+12,20);printf("GOODBYE");gotoxy(29+12,23);printf("GOODBYE");
    Sleep(150);gotoxy(29+28,14);printf("O");gotoxy(29+22,5);printf("GOODBYE");gotoxy(29+22,8);printf("GOODBYE");gotoxy(29+22,11);printf("GOODBYE");gotoxy(29+22,17);printf("GOODBYE");gotoxy(29+22,20);printf("GOODBYE");gotoxy(29+22,23);printf("GOODBYE");
    Sleep(150);gotoxy(29+29,14);printf("D");gotoxy(29+32,5);printf("GOODBYE");gotoxy(29+32,8);printf("GOODBYE");gotoxy(29+32,11);printf("GOODBYE");gotoxy(29+32,17);printf("GOODBYE");gotoxy(29+32,20);printf("GOODBYE");gotoxy(29+32,23);printf("GOODBYE");
    Sleep(150);gotoxy(29+30,14);printf("B");gotoxy(29+42,5);printf("GOODBYE");gotoxy(29+42,8);printf("GOODBYE");gotoxy(29+42,11);printf("GOODBYE");gotoxy(29+42,17);printf("GOODBYE");gotoxy(29+42,20);printf("GOODBYE");gotoxy(29+42,23);printf("GOODBYE");
    Sleep(150);gotoxy(29+31,14);printf("Y");gotoxy(29+52,5);printf("GOODBYE");gotoxy(29+52,8);printf("GOODBYE");gotoxy(29+52,11);printf("GOODBYE");gotoxy(29+52,17);printf("GOODBYE");gotoxy(29+52,20);printf("GOODBYE");gotoxy(29+52,23);printf("GOODBYE");
    Sleep(150);gotoxy(29+32,14);printf("E");gotoxy(29+1,5);printf("       ");gotoxy(29+12,5);printf("       ");gotoxy(29+22,5);printf("       ");gotoxy(29+32,5);printf("       ");gotoxy(29+42,5);printf("       ");gotoxy(29+52,5);printf("       ");
                                            gotoxy(29+1,8);printf("       ");gotoxy(29+12,8);printf("       ");gotoxy(29+22,8);printf("       ");gotoxy(29+32,8);printf("       ");gotoxy(29+42,8);printf("       ");gotoxy(29+52,8);printf("       ");
                                            gotoxy(29+1,11);printf("       ");gotoxy(29+12,11);printf("       ");gotoxy(29+22,11);printf("       ");gotoxy(29+32,11);printf("       ");gotoxy(29+42,11);printf("       ");gotoxy(29+52,11);printf("       ");
                                            gotoxy(29+1,23);printf("       ");gotoxy(29+12,23);printf("       ");gotoxy(29+22,23);printf("       ");gotoxy(29+32,23);printf("       ");gotoxy(29+42,23);printf("       ");gotoxy(29+52,23);printf("       ");                            
                                            gotoxy(29+1,20);printf("       ");gotoxy(29+12,20);printf("       ");gotoxy(29+22,20);printf("       ");gotoxy(29+32,20);printf("       ");gotoxy(29+42,20);printf("       ");gotoxy(29+52,20);printf("       ");
                                            gotoxy(29+1,17);printf("       ");gotoxy(29+12,17);printf("       ");gotoxy(29+22,17);printf("       ");gotoxy(29+32,17);printf("       ");gotoxy(29+42,17);printf("       ");gotoxy(29+52,17);printf("       ");                               
system("cls");
}
void introname(){
	int i;
	char** creator=(char**)malloc(3*sizeof(char*));
	for(i=0;i<3;i++){
		creator[i]=(char*)malloc(10*sizeof(char));
	}
	strcpy(creator[0], "M.FAHAD");strcpy(creator[1], "HAMZA M.");strcpy(creator[2], "HAMZA H.");	
    Sleep(150);gotoxy(29+26,14);printf("%c",creator[maker][0]);gotoxy(29+1,5);printf("%s",creator[maker]);gotoxy(29+1,8);printf("%s",creator[maker]);gotoxy(29+1,11);printf("%s",creator[maker]);gotoxy(29+1,17);printf("%s",creator[maker]);gotoxy(29+1,20);printf("%s",creator[maker]);gotoxy(29+1,23);printf("%s",creator[maker]);
    Sleep(150);gotoxy(29+27,14);printf("%c",creator[maker][1]);gotoxy(29+12,5);printf("%s",creator[maker]);gotoxy(29+12,8);printf("%s",creator[maker]);gotoxy(29+12,11);printf("%s",creator[maker]);gotoxy(29+12,17);printf("%s",creator[maker]);gotoxy(29+12,20);printf("%s",creator[maker]);gotoxy(29+12,23);printf("%s",creator[maker]);
    Sleep(150);gotoxy(29+28,14);printf("%c",creator[maker][2]);gotoxy(29+22,5);printf("%s",creator[maker]);gotoxy(29+22,8);printf("%s",creator[maker]);gotoxy(29+22,11);printf("%s",creator[maker]);gotoxy(29+22,17);printf("%s",creator[maker]);gotoxy(29+22,20);printf("%s",creator[maker]);gotoxy(29+22,23);printf("%s",creator[maker]);
    Sleep(150);gotoxy(29+29,14);printf("%c",creator[maker][3]);gotoxy(29+32,5);printf("%s",creator[maker]);gotoxy(29+32,8);printf("%s",creator[maker]);gotoxy(29+32,11);printf("%s",creator[maker]);gotoxy(29+32,17);printf("%s",creator[maker]);gotoxy(29+32,20);printf("%s",creator[maker]);gotoxy(29+32,23);printf("%s",creator[maker]);
    Sleep(150);gotoxy(29+30,14);printf("%c",creator[maker][4]);gotoxy(29+42,5);printf("%s",creator[maker]);gotoxy(29+42,8);printf("%s",creator[maker]);gotoxy(29+42,11);printf("%s",creator[maker]);gotoxy(29+42,17);printf("%s",creator[maker]);gotoxy(29+42,20);printf("%s",creator[maker]);gotoxy(29+42,23);printf("%s",creator[maker]);
    Sleep(150);gotoxy(29+31,14);printf("%c",creator[maker][5]);gotoxy(29+52,5);printf("%s",creator[maker]);gotoxy(29+52,8);printf("%s",creator[maker]);gotoxy(29+52,11);printf("%s",creator[maker]);gotoxy(29+52,17);printf("%s",creator[maker]);gotoxy(29+52,20);printf("%s",creator[maker]);gotoxy(29+52,23);printf("%s",creator[maker]);
    Sleep(150);gotoxy(29+32,14);printf("%c",creator[maker][6]);gotoxy(29+1,5);printf("        ");gotoxy(29+12,5);printf("        ");gotoxy(29+22,5);printf("        ");gotoxy(29+32,5);printf("        ");gotoxy(29+42,5);printf("        ");gotoxy(29+52,5);printf("        ");
                                            gotoxy(29+1,8);printf("        ");gotoxy(29+12,8);printf("        ");gotoxy(29+22,8);printf("        ");gotoxy(29+32,8);printf("        ");gotoxy(29+42,8);printf("        ");gotoxy(29+52,8);printf("        ");
                                            gotoxy(29+1,11);printf("        ");gotoxy(29+12,11);printf("        ");gotoxy(29+22,11);printf("        ");gotoxy(29+32,11);printf("        ");gotoxy(29+42,11);printf("        ");gotoxy(29+52,11);printf("        ");
                                            gotoxy(29+1,23);printf("        ");gotoxy(29+12,23);printf("        ");gotoxy(29+22,23);printf("        ");gotoxy(29+32,23);printf("        ");gotoxy(29+42,23);printf("        ");gotoxy(29+52,23);printf("        ");                            
                                            gotoxy(29+1,20);printf("        ");gotoxy(29+12,20);printf("        ");gotoxy(29+22,20);printf("        ");gotoxy(29+32,20);printf("        ");gotoxy(29+42,20);printf("        ");gotoxy(29+52,20);printf("        ");
                                            gotoxy(29+1,17);printf("        ");gotoxy(29+12,17);printf("        ");gotoxy(29+22,17);printf("        ");gotoxy(29+32,17);printf("        ");gotoxy(29+42,17);printf("        ");gotoxy(29+52,17);printf("        ");                               
	maker++;
}

int main() {
	int i;  
	int opt2;
	char opt1,temp[100];
	// INTRO PAGE
	system("cls");	
	if(c==0){
		PlaySoundA("C:\\Users\\Fahad\\Desktop\\TYPENXT PROJECT\\stuff\\n95.wav", NULL, SND_FILENAME | SND_ASYNC);

    	//max x = 119 y = 29
	    //middle x = 59 y = 14
	    boximoxi();
	    preintro();
	    Sleep(1300);
	    system("cls");
	    boximoxi();
	    for(i=0;i<3;i++){
	   		introname();
	    	Sleep(400);
		   	system("cls");
	       	boximoxi();
		}
	    system("cls");
		for(i=0;i<7;i++){
			system("cls");
	    	boximoxi();
			intro();
		}
		gotoxy(29+21,12);printf("W E L C O M E  T O");                                                                    
	    gotoxy(29+8,16);printf("P R E S S  A N Y  K E Y  T O  C O N T I N U E"); 
	    getch();
		do{
			system("cls");
			fflush(stdin);
			boximoxi();
		
			gotoxy(19+26,9);printf("E N T E R  Y O U R"GOLD"  N A M E"RESET);
			gotoxy(19+36,10);fgets(temp,sizeof(temp),stdin);
			strcpy(player.name,temp);
			gotoxy(19+7,5);printf("E N T E R  Y O U R  R O L L  N O  C O R R E C T L Y  EX(23K-1234)");
			int correctrollno=1;
			while(correctrollno==1){
				gotoxy(19+24,12);printf("E N T E R  Y O U R  "GOLD"R O L L  N O"RESET);
				gotoxy(19+35,13);fgets(temp,sizeof(temp),stdin);
				int rollnoL=strlen(temp);
				if(temp[2]=='K'&&rollnoL==9){
					strcpy(player.rollno,temp);
					correctrollno=0;
					fflush(stdin);	
				}else{
					gotoxy(19+35,13);printf("                               ");
					fflush(stdin);
				}
			}
			
			gotoxy(19+18,15);printf("Y O U R"GOLD"  N A M E "RESET" A N D  "GOLD"R O L L  N O  "RESET"A R E");
			gotoxy(19+28,16);printf("%s",player.name);gotoxy(19+45,16);printf("%s",player.rollno);
			gotoxy(19+10,18);printf("P R E S S"RED"  C  "RESET"T O  "RED"C O N T I N U E  "RESET"O R  "BLUE"R "RESET" T O  "BLUE"R E N A M E"RESET);
			gotoxy(19+39,19);scanf(" %c",&opt1);
			system("cls");
			if(opt1 == 'C' || opt1 == 'c'){
				c=1;
				break;
			}
		}
	 	while (opt1 != 'C' || opt1 != 'c');
	}
	
	//MainMenu		   
	int selectedOption = 1;
    char key;

    do {
        MainMenuDisplay(selectedOption);

        key = getch();
        switch (key) {
            case 72: 
                if (selectedOption > 1) {
                    selectedOption--;
                }
                break;
            case 80: 
                if (selectedOption < 3) {
                    selectedOption++;
                }
                break;
        }
    } while (key != 13);

	system("cls");				
	
	switch(selectedOption)
	{       
		case 1: gameMode();
		break;
		case 2: leaderboard();
		break;
		case 3: system("cls");
				boximoxi();
				PlaySoundA("C:\\Users\\Fahad\\Desktop\\TYPENXT PROJECT\\stuff\\hamood.wav", NULL, SND_FILENAME | SND_ASYNC);
				for(int i=0;i<7;i++){
					outro();
				}
				Sleep(2000);
				return 0;
		default: main();
	}
    return 0;
}
//end of int main

int Input(int min, int max) {              //Using recursion to get user input within a specified range
    int input;

    gotoxy(19+39,18);scanf("%d",&input);
   
    if (input < min || input > max) {
        gotoxy(19+27,19);printf(RED"I N V A L I D  O P T I O N.\n");printf(RESET);
        
        return Input(min, max);
    }

    return input;
}

void MainMenuDisplay(int selectedOption) {
    system("cls"); 

	usernamerollno();
    boximoxi();	
    gotoxy(19+32,11);printf(CORAL"M A I N  M E N U\n"RESET);
    int i;
    
    for (i = 1; i <= 3; ++i) {
    
        if (i == selectedOption) {
            
            printf(GOLD);
        } else {
            printf("   ");
        }
        

        switch (i) {
            case 1:
                gotoxy(19+24,13);printf("1. S E L E C T  G A M E  M O D E");
                break;
            case 2:
                gotoxy(19+28,14);printf("2. L E A D E R B O A R D");
                break;
            case 3:
                gotoxy(19+35,15);printf("3. E X I T");
                break;
        }

        printf(RESET);
    }
}
void gameModeDisplay(int selectedOption) {
    system("cls"); 

    boximoxi();
	usernamerollno();	
    gotoxy(19+21,10);printf(CORAL"S E L E C T  Y O U R  G A M E  M O D E\n"RESET);
    int i;
    
    for (i = 1; i <= 4; ++i) {
    
        if (i == selectedOption) {
            
            printf(GOLD);
        } else {
            printf("   ");
        }
        

        switch (i) {
            case 1:
                gotoxy(19+30,12);printf("1. E T S Y B I T S Y\n");
                break;
            case 2:
                gotoxy(19+27,13);printf("2. M R . C O R R E C T O R\n");
                break;
            case 3:
                gotoxy(19+32,14);printf("3. Q U I C K I E\n");
                break;
            case 4:
                gotoxy(19+32,15);printf("4. D R O P P E R\n");
                break;
        }

        printf(RESET);
    }
}

void gameTypeDisplay(int selectedOption) {
    system("cls"); 

	gotoxy(19+35,5);printf("%s",gameM);
    boximoxi();
	usernamerollno();	
    gotoxy(19+21,12);printf(CORAL"S E L E C T  Y O U R  G A M E  T Y P E\n"RESET);
    int i;
    
    for (i = 1; i <= 2; ++i) {
    
        if (i == selectedOption) {
            
            printf(GOLD);
        } else {
            printf("   ");
        }
        

        switch (i) {
            case 1:
                gotoxy(19+30,14);printf("1. P A R A G R A P H\n");
                break;
            case 2:
                gotoxy(19+30,15);printf("2. S E N T E N C E\n");
                break;
                
        }

        printf(RESET);
    }
}

void gameQTypeDisplay(int selectedOption) {
    system("cls"); 

	gotoxy(19+36,5);printf("%s",gameM);
    boximoxi();
    usernamerollno();
    gotoxy(19+21,12);printf(CORAL"S E L E C T  Y O U R  G A M E  T Y P E\n"RESET);
    int i;
    
    for (i = 1; i <= 2; ++i) {
    
        if (i == selectedOption) {
            
            printf(GOLD);
        } else {
            printf("   ");
        }
        

        switch (i) {
            case 1:
                gotoxy(19+26,14);printf("1. N O R M A L  W O R D S\n");
                break;
            case 2:
                gotoxy(19+23,15);printf("2. S C R A B B L E D  W O R D S\n");
                break;
        }

        printf(RESET);
    }
}

int setTime()
{
	int optcase=0;
	char opt;
	int set=0;
	if(strcmp(gameT,"PARAGRAPH")==0){
		while (set==0)
		{
			system("cls");
			
			usernamerollno();
			boximoxi();
			gotoxy(19+36,5);printf("%s",gameM);
			gotoxy(19+26,11);printf("S E L E C T  T H E  T I M E");
			gotoxy(19+20,13);printf("P R E S S  1  F O R  30  S E C O N D S");
			gotoxy(19+20,14);printf("P R E S S  2  F O R  60  S E C O N D S");
			gotoxy(19+20,15);printf("P R E S S  3  F O R  90  S E C O N D S");
			optcase=Input(1,3);
			fflush(stdin);
			float output=(double)optcase/2.00;
			system("cls");
			
			usernamerollno();
			boximoxi();
			gotoxy(19+36,5);printf("%s",gameM);
			gotoxy(19+19,13);printf("Y O U  S E L E C T E D  %.2f  M I N U T E",output);
			gotoxy(19+10,15);printf("P R E S S"RED"  C  "RESET"T O  "RED"C O N T I N U E  "RESET"O R  "BLUE"R "RESET" T O  "BLUE"C H A N G E"RESET);
			gotoxy(19+39,17);scanf(" %c", &opt);
			fflush(stdin);
			if(opt == 'C' || opt == 'c'){
				set=1;
			}
		}	
	
		system("cls");
	
		switch(optcase)
		{
			case 1: return 30;break;
			case 2: return 60;break;
			case 3: return 90;break;
			default: main();
		}	
	}else{
		while (set==0)
		{
			system("cls");
			
			usernamerollno();
			boximoxi();
			
			gotoxy(19+36,5);printf("%s",gameM);
			gotoxy(19+26,11);printf("S E L E C T  T H E  T I M E");
			gotoxy(19+20,13);printf("P R E S S  1  F O R  2 0  S E C O N D S");
			gotoxy(19+20,14);printf("P R E S S  2  F O R  4 0  S E C O N D S");
			gotoxy(19+20,15);printf("P R E S S  3  F O R  6 0  S E C O N D S");
			optcase=Input(1,3);
			fflush(stdin);
			system("cls");
			usernamerollno();
			boximoxi();
			gotoxy(19+36,5);printf("%s",gameM);
			float output=(double)optcase*20.00;
			gotoxy(19+19,13);printf("Y O U  S E L E C T E D  %.2f  S E C O N D S",output);
			gotoxy(19+10,15);printf("P R E S S"RED"  C  "RESET"T O  "RED"C O N T I N U E  "RESET"O R  "BLUE"R "RESET" T O  "BLUE"C H A N G E"RESET);
			gotoxy(19+39,17);scanf(" %c", &opt);
			fflush(stdin);
			if(opt == 'C' || opt == 'c'){
				set=1;
			}
		}	
	
		system("cls");
	
		switch(optcase)
		{
			case 1: return 20;break;
			case 2: return 40;break;
			case 3: return 60;break;
			default: main();
		}	
	}
}

void gameMode() {
	int selectedOption = 1;
    char key;

    do {
        gameModeDisplay(selectedOption);

        key = getch();
        switch (key) {
            case 72: 
                if (selectedOption > 1) {
                    selectedOption--;
                }
                break;
            case 80: 
                if (selectedOption < 4) {
                    selectedOption++;
                }
                break;
        }
    } while (key != 13);

	system("cls");				
	
	switch(selectedOption)
	{	
		case 1: etsybitsy();
			break;
		case 2:	mrcorrector();
			break;
		case 3: quickie();
			break;
		case 4: dropper();
			break;
		default: gotoxy(19+27,14);printf("I N V A L I D  O P T I O N");
				 system("cls");
				 gameMode();
	}
}

void gameType(){
	int selectedOption = 1;
    char key;

    do {
        gameTypeDisplay(selectedOption);

        key = getch();
        switch (key) {
            case 72: 
                if (selectedOption > 1) {
                    selectedOption--;
                }
                break;
            case 80: 
                if (selectedOption < 2) {
                    selectedOption++;
                }
                break;
        }
    } while (key != 13);

	system("cls");				
	
	switch(selectedOption)
	{
		
		case 1: strcpy(gameT,"PARAGRAPH");
			break;
		case 2:	strcpy(gameT,"SENTENCE");
			break;
		default: usernamerollno();boximoxi();
				 gotoxy(19+27,14);printf("I N V A L I D  O P T I O N");
			     system("cls");
				 gameType();
	}
}

void gameQType(){
	int selectedOption = 1;
    char key;

    do {
        gameQTypeDisplay(selectedOption);

        key = getch();
        switch (key) {
            case 72: 
                if (selectedOption > 1) {
                    selectedOption--;
                }
                break;
            case 80: 
                if (selectedOption < 2) {
                    selectedOption++;
                }
                break;
        }
    } while (key != 13);

	system("cls");				
	
	switch(selectedOption)
	{	
		case 1: strcpy(gameT,"NORMAL");
			break;
		case 2:	strcpy(gameT,"SCRABBLED");
			break;
		default: usernamerollno();boximoxi();
				 gotoxy(19+27,14);printf("I N V A L I D  O P T I O N");
			     system("cls");
				 gameType();
	}
}

int counting(char strC[],char entered[],int length){
	int count=0;
	for (int i = 0; i < length; i++)
	{
		if(strC[i]==entered[i]){
			count++;
		}
		if(strC[i]=='\0'){
			break;
		}
	}
	return count;
}
int scoring(int count,int length){
	return ((float)count/(float)length)*100;
}
void etsybitsy(){
	PlaySoundA("C:\\Users\\Fahad\\Desktop\\TYPENXT PROJECT\\stuff\\ob.wav", NULL, SND_FILENAME | SND_ASYNC);
	strcpy(gameM,"ETSYBITSY");
	gameType();
	if(strcmp(gameT,"PARAGRAPH")==0){
		paragraphSELECTOR();
		game(strC,strC);
	}else{
		sentenceSELECTOR();
		game(strC,strC);
	}
}

void mrcorrector(){
	PlaySoundA("C:\\Users\\Fahad\\Desktop\\TYPENXT PROJECT\\stuff\\killa.wav", NULL, SND_FILENAME | SND_ASYNC);
	strcpy(gameM,"MR.CORRECTOR");
	gameType();
	if(strcmp(gameT,"PARAGRAPH")==0){
		paragraphSELECTOR();
		game(str,strC);
	}else{
		sentenceSELECTOR();
		game(str,strC);
	}
}

void quickie(){
	PlaySoundA("C:\\Users\\Fahad\\Desktop\\TYPENXT PROJECT\\stuff\\agency.wav", NULL, SND_FILENAME | SND_ASYNC);
	strcpy(gameM,"QUICKIE");
	system("cls");
	gameQType();
	char entered[500];
	char help[500]="IN THIS GAME YOU HAVE TO WRITE GIVEN WORD CORRECTLY IN 5 SECOND ATLEAST LENGTH SHOULD BE EQUAL IF YOU SUCCEED YOU'LL GET YOUR SCORE BASED ON YOUR ACCURACY";
	int helpL = strlen(help);
	timeselect = 5;
	int timeSpent=0;
	int end = 0;
	float wps = 0;
	boximoxi();
	gotoxy(19+36,5);printf("%s",gameM);
	usernamerollno();
				 
	gotoxy(19+23,11);printf("W E L C O M E  T O  Q U I C K I E");	
	int x = 20,y = 13;
	gotoxy(x,y);
	for (int i = 0; i < helpL; i++)
	{
		if(i==79){
			gotoxy(x,y+1);
			printf("%c",help[i]);
		}else{
			printf("%c",help[i]);
		}
	}
	gotoxy(19+20,16);printf("P R E S S  A N Y  K E Y  T O  S T A R T");
	getch();
	fflush(stdin);
	system("cls");
	while(end==0)
	{	
		fflush(stdin);
		score=0;
		while(1){
			if(strcmp(gameT,"NORMAL")==0){
				quickieSelector();
			}else{
				quickieScrabbledSelector();
			}	
			int reqL=strlen(strC);
			int	timeSpent=0;
			int a = 19 + rand() % 70;
			int b = 7 + rand() % 14;
			clock_t begin = clock();
			
			usernamerollno();
			boximoxi();
			gotoxy(19+35,5);printf("%s",gameM);
			gotoxy(20,5);printf("SCORE: %0.2f",score);
			gotoxy(a,b);printf("%s",str);
			gotoxy(a,b+1);fgets(entered,sizeof(entered),stdin);
			int L=strlen(entered);
			int count = counting(strC,entered,reqL);
			timeSpent=(int)(clock()-begin)/CLOCKS_PER_SEC;
			if(timeSpent<5){
				if(strcmp(strC,entered)==0){
					score+=10;
				}else if(L>=reqL){	
					score += scoring(count,reqL)/10;
				}else if(L<reqL){
					system("cls");
					boximoxi();
					usernamerollno();
					gotoxy(19+35,5);printf("%s",gameM);
					gotoxy(19+23,13);printf("Y O U  F A I L E D  T O  W R I T E");
					gotoxy(19+22,15);printf("T I M E  S P E N T : %d S E C O N D",timeSpent);
					Sleep(4000);
					break;	
				}
			}else{
				system("cls");
				boximoxi();
				usernamerollno();
				gotoxy(19+35,5);printf("%s",gameM);
				gotoxy(19+3,13);printf("Y O U  F A I L E D  T I M E  S P E N T  M O R E  T H A N  5  S E C O N D S");
				gotoxy(19+22,15);printf("T I M E  S P E N T : %d S E C O N D",timeSpent);
				Sleep(4000);
				break;
			}
			system("cls");
		}
		system("cls");
		boximoxi();
		usernamerollno();
		gotoxy(19+35,5);printf("%s",gameM);
		gotoxy(19+29,13);printf("S C O R E  I S  %0.2f ",score);
		gotoxy(19+9,15);printf("P R E S S  0  T O  R E P L A Y  O R  1  T O  S H O W  M E N U ");
		gotoxy(19+39,16);scanf("%d",&end);
		system("cls");
	}
	leaderboardEdit(&wps);
	int opt;
	
	boximoxi();
	usernamerollno();
	gotoxy(19+35,5);printf("%s",gameM);
	gotoxy(19+36,11);printf("M E N U");
	gotoxy(19+4,13);printf("P R E S S  1  T O  R E S E L E C T  G A M E  T Y P E  O F  Q U I C K I E");
	gotoxy(19+13,14);printf("P R E S S  2  T O  R E S E L E C T  G A M E  M O D E");
	gotoxy(19+17,15);printf("P R E S S  3  T O  G O  T O  M A I N  M E N U ");
	gotoxy(19+39,16);scanf("%d",&opt);
	switch (opt)
	{
	case 1: quickie();
		break;
	case 2: gameMode();
		break;
	default: main();
		break;
	}
}

void dropper(){
	PlaySoundA("C:\\Users\\Fahad\\Desktop\\TYPENXT PROJECT\\stuff\\indus.wav", NULL, SND_FILENAME | SND_ASYNC);
	strcpy(gameM,"DROPPER");
    score=0;
    int end = 0,failed=0;
    int timeSpent = 0;
    char drop,entered;
    float wps=0;
    
    system("cls");
	boximoxi();
	usernamerollno();
	gotoxy(19+23,11);printf("W E L C O M E  T O  D R O P P E R");
	char help[500]="IN THIS GAME YOU HAVE TO WRITE THE DROPPING LETTER CORRECTLY BEFORE IT TOUCHES THE BASE ELSE YOU WILL LOSE, THE SPEED OF THE DROPPING LETTERS INCREASES AS TIME PASS BY";
	int helpL = strlen(help);
	int x = 20,y = 13,letters=0;
	gotoxy(x,y);
	for (int i = 0; i < helpL; i++)
	{
		letters++;
		if(letters==79){
			letters=0;
			y++;	
			gotoxy(x,y);
			printf("%c",help[i]);
		}else{
			printf("%c",help[i]);
		}
	}
	gotoxy(19+20,17);printf("P R E S S  A N Y  K E Y  T O  S T A R T");
	getch();
	fflush(stdin);
	system("cls");    
	while(failed==0&&end==0){
		
	    system("cls");
		boximoxi();
		score=0;
	    usernamerollno();
	    gotoxy(20,5);printf("SCORE: %0.2f",score);
	    gotoxy(19+35,5);printf("%s",gameM);
	    clock_t begin = clock();
		while(failed==0){
	    	fflush(stdin);
			gotoxy(20,5);printf("SCORE: %0.2f",score);
	        drop = 'a'+rand()%26;
	        x=20+rand()%79;
	        y=7;
	        while(1)
	        {
	        	timeSpent=(int)(clock()-begin)/CLOCKS_PER_SEC;
				if(timeSpent<=5){
					Sleep(130);
				}else if(timeSpent<=10){
					Sleep(80);
				}else{
					Sleep(40);
				}
				if(y!=5){
					gotoxy(x,y-1);printf(" ");
				}
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
		boximoxi();
		usernamerollno();
		gotoxy(19+35,5);printf("%s",gameM);
		gotoxy(19+29,13);printf("S C O R E  I S  %0.2f ",score);
		gotoxy(19+9,15);printf("P R E S S  0  T O  R E P L A Y  O R  1  T O  S H O W  M E N U ");
		gotoxy(19+39,16);scanf("%d",&end);
		failed=0;
		system("cls");
	}
    leaderboardEdit(&wps);
	int opt;
	
	boximoxi();
	usernamerollno();
	gotoxy(19+35,5);printf("%s",gameM);
	gotoxy(19+36,12);printf("M E N U");
	gotoxy(19+13,14);printf("P R E S S  1  T O  R E S E L E C T  G A M E  M O D E");
	gotoxy(19+17,15);printf("P R E S S  2  T O  G O  T O  M A I N  M E N U ");
	gotoxy(19+39,16);scanf("%d",&opt);
	switch (opt)
	{
	case 1: gameMode();
		break;
	default: main();
		break;
	}

}


void game(char str[],char strC[]){
	char entered[500];
	int end=0;
	while (end==0)
	{	
		int count=0;
		timeselect = setTime();
		score=0;
		float wps=0;
		clock_t begin = clock();
		int reqL=strlen(strC);
		usernamerollno();
		if(strcmp(gameT,"PARAGRAPH")==0){
			boxipoxi();
			int x = 0,y = 10,limit=0;
			gotoxy(x,y);
			for (int i = 0; i < reqL; i++)
			{
				limit++;
				if(limit==119){
					y++;
					limit=0;
					gotoxy(x,y);
					printf("%c",str[i]);
				}else{
					printf("%c",str[i]);
				}
			}
		}else{
			boximoxi();
			int x = 20,y = 10,limit=0;
			gotoxy(x,y);
			for (int i = 0; i < reqL; i++)
			{
				limit++;
				if(limit==79){
					y++;
					limit=0;
					gotoxy(x,y);
					printf("%c",str[i]);
				}else{
					printf("%c",str[i]);
				}
			}
		}
		gotoxy(19+35,5);printf("%s",gameM);
		gotoxy(19+6,7);printf("Y O U  H A V E  T O  W R I T E  T H E  W O R D I N G S  B E L O W");
		gotoxy(19+19,8);printf("C O R R E C T L Y  I N  %d  S E C O N D S",timeselect);
		
		if(strcmp(gameT,"PARAGRAPH")==0){
			gotoxy(0,16);fgets(entered,sizeof(entered),stdin);
			
		}else{
			gotoxy(20,16);fgets(entered,sizeof(entered),stdin);
		}
		int L=strlen(entered);
		
		int timeSpent=(int)(clock()-begin)/CLOCKS_PER_SEC;
		
		if(timeSpent>timeselect){
			system("cls");
			gotoxy(19+35,5);printf("%s",gameM);
			boximoxi();
			usernamerollno();
			gotoxy(19+21,11);printf("Y O U  F A I L E D  T I M E  O V E R ");
		}else if(strcmp(strC,entered)==0&&timeSpent<=timeselect){
			system("cls");
			gotoxy(19+35,5);printf("%s",gameM);
			boximoxi();
			usernamerollno();
			gotoxy(19+23,11);printf("! ! Y O U  A C E D  M Y  B O Y ! !");
			score+=100;
			gotoxy(19+34,12);printf("SCORE : %.2f",score);
		}else if(L==reqL&&timeSpent<=timeselect){
			count = counting(strC,entered,reqL);
			if((strcmp(gameT,"PARAGRAPH")==0&&count >= 80)||(strcmp(gameT,"SENTENCE")==0&&count >= 20)){
				system("cls");
				gotoxy(19+35,5);printf("%s",gameM);	
				boximoxi();
				usernamerollno();
				gotoxy(19+23,11);printf("! ! Y O U  A L M O S T  A C E D ! !");
				score += scoring(count,reqL);
				gotoxy(19+34,12);printf("SCORE : %.2f",score);

			}else if((strcmp(gameT,"PARAGRAPH")==0&&count >= 55)||(strcmp(gameT,"SENTENCE")==0&&count >= 10)){
				system("cls");	
				gotoxy(19+35,5);printf("%s",gameM);
				boximoxi();
				usernamerollno();
				gotoxy(19+23,11);printf("! ! Y O U  A R E  A N  A V E R A G E ! !");
			    score += scoring(count,reqL);
				gotoxy(19+34,12);printf("SCORE : %.2f",score);
			}else {
				system("cls");
				gotoxy(19+35,5);printf("%s",gameM);
				boximoxi();
				usernamerollno();
				gotoxy(19+14,11);printf("! ! Y O U  W R O T E  L I K E  A N  I N F A N T ! !");		
				score += scoring(count,reqL);
				gotoxy(19+34,12);printf("SCORE : %.2f",score);
			}
		}else if(L<reqL){
			system("cls");
			gotoxy(19+35,5);printf("%s",gameM);
			boximoxi();
			usernamerollno();
			gotoxy(19+4,11);printf("! ! Y O U  D I D N ' T  W R O T E  T H E  W H O L E  S E N T E N C E ! !");
			count = counting(strC,entered,reqL);
			score += scoring(count,reqL);
			gotoxy(19+34,12);printf("SCORE : %.2f",score);
		}else if(L>reqL){
			system("cls");
			gotoxy(19+35,5);printf("%s",gameM);
			boximoxi();
			usernamerollno();
			gotoxy(19+15,10);printf("! ! D O N ' T  A C T  O V E R L Y  M Y  B O Y ! !");
			count = counting(strC,entered,reqL);
			printf("\n%d\n",count);
			if(count == L){
				gotoxy(19+29,11);printf("! ! Y O U  A C E D ! !");
				score+=100;
				gotoxy(19+34,12);printf("SCORE : %.2f",score);
			}else if((strcmp(gameT,"PARAGRAPH")==0&&count >= 80)||(strcmp(gameT,"SENTENCE")==0&&count >= 20)){
				gotoxy(19+27,11);printf("! ! Y O U  A L M O S T  A C E D ! !");
				score += scoring(count,reqL);
				gotoxy(19+34,12);printf("SCORE : %.2f",score);

			}else if((strcmp(gameT,"PARAGRAPH")==0&&count >= 55)||(strcmp(gameT,"SENTENCE")==0&&count >= 10)){
				gotoxy(19+20,11);printf("! ! Y O U  A R E  A N  A V E R A G E ! !");
			    score += scoring(count,reqL);
				gotoxy(19+34,12);printf("SCORE : %.2f",score);
			}else {
				gotoxy(19+14,11);printf("! ! Y O U  W R O T E  L I K E  A N  I N F A N T ! !");		
				score += scoring(count,reqL);
				gotoxy(19+34,12);printf("SCORE : %.2f",score);
			}
			Sleep(4000);
		}
		wps = (float)count/(float)timeSpent;
		leaderboardEdit(&wps);
		fflush(stdin);
		gotoxy(19+22,13);printf("W O R D S  P E R  S E C O N D : %.2f",wps);
		gotoxy(19+28,14);printf("T I M E  S P E N T : %d",timeSpent);
		gotoxy(19+25,15);printf("T I M E  S E L E C T E D : %d",timeselect);
		gotoxy(19+24,16);printf("W A N T  T O  P L A Y  A G A I N");
		gotoxy(19+24,17);printf("P R E S S  0  T O  R E P L A Y ");
		gotoxy(19+22,18);printf("P R E S S  1  T O  S H O W  M E N U ");
		
		gotoxy(19+39,19);scanf("%d",&end);
		system("cls");
		if(end==0){
			if(strcmp(gameT,"ETSYBITSY")==0){
				if(strcmp(gameT,"PARAGRAPH")==0){
					paragraphSELECTOR();
					game(strC,strC);
				}else{
					sentenceSELECTOR();
					game(strC,strC);
				}			
			}else{
				if(strcmp(gameT,"PARAGRAPH")==0){
					paragraphSELECTOR();
					game(str,strC);
				}else{
					sentenceSELECTOR();
					game(str,strC);
				}
			}
		}
	}
	int opt;
	boximoxi();
	usernamerollno();
	gotoxy(19+36,12);printf("M E N U");
	gotoxy(19+13,14);printf("P R E S S  1  T O  R E S E L E C T  G A M E  M O D E");
	gotoxy(19+17,15);printf("P R E S S  2  T O  G O  T O  M A I N  M E N U");
	gotoxy(19+39,16);scanf("%d",&opt);
	switch (opt)
	{
	case 1: gameMode();
		break;
	default:
			main();
		break;
	}
}

void paragraphSELECTOR(){
	FILE *fp;
    char lines[MAX_LINES][MAX_LENGTH];
	char lines1[MAX_LINES][MAX_LENGTH];
    int i, randomL;

    fp = fopen("paragraphs.txt", "r");
    srand(time(NULL));
	randomL = rand()%10;
    rewind(fp);
    for (i = 0; i < 10; i++) {
        fgets(lines[i], MAX_LENGTH, fp);
    }
	strcpy(strC, lines[randomL]);
    fclose(fp);

    fp = fopen("scrabbledparagraphs.txt", "r");
    rewind(fp);
    for (i = 0; i < 10; i++) {
        fgets(lines1[i], MAX_LENGTH, fp);
    }
    strcpy(str, lines1[randomL]);
    fclose(fp);
}
void sentenceSELECTOR(){
	FILE *fp;
    char lines[MAX_LINES][MAX_LENGTH];
	char lines1[MAX_LINES][MAX_LENGTH];
    int i, randomL;

    fp = fopen("sentences.txt", "r");
    srand(time(NULL));
	randomL = rand()%11;
    rewind(fp);
    for (i = 0; i < 10; i++) {
        fgets(lines[i], MAX_LENGTH, fp);
    }
	strcpy(strC, lines[randomL]);
    fclose(fp);

    fp = fopen("scrabbledsentences.txt", "r");
    rewind(fp);
    for (i = 0; i < 10; i++) {
        fgets(lines1[i], MAX_LENGTH, fp);
    }
	strcpy(str, lines1[randomL]);
    fclose(fp);
}
void quickieSelector(){
	FILE *fp;
    char lines[MAX_LINES][MAX_LENGTH];
    char lines1[MAX_LINES][MAX_LENGTH];
    int i, randomL;

    fp = fopen("quickie.txt", "r");
    srand(time(NULL));
	randomL = rand()%171;
    rewind(fp);
    for (i = 0; i < 171; i++) {
        fgets(lines[i], MAX_LENGTH, fp);
    }
	strcpy(strC, lines[randomL]);
    fclose(fp);

    fp = fopen("quickie.txt", "r");
    rewind(fp);
    for (i = 0; i < 171; i++) {
        fgets(lines1[i], MAX_LENGTH, fp);
    }
    strcpy(str, lines1[randomL]);
    fclose(fp);
}
void quickieScrabbledSelector(){
	FILE *fp;
    char lines[MAX_LINES][MAX_LENGTH];
    char lines1[MAX_LINES][MAX_LENGTH];
    int i, randomL;

    fp = fopen("quickie.txt", "r");
    srand(time(NULL));
	randomL = rand()%171;
    rewind(fp);
    for (i = 0; i < 171; i++) {
        fgets(lines[i], MAX_LENGTH, fp);
    }
	strcpy(strC, lines[randomL]);
    fclose(fp);

    fp = fopen("scrabbledquickie.txt", "r");
    rewind(fp);
    for (i = 0; i < 171; i++) {
        fgets(lines1[i], MAX_LENGTH, fp);
    }
    strcpy(str, lines1[randomL]);
    fclose(fp);
}
void leaderboardEdit(float *wps){
	FILE *fp;
	fp=fopen("Leaderboard.txt","a");
	if(fp==NULL){
		printf("ERROR WHILE OPENING FILE");
	}
	fprintf(fp,"\nNAME:%s\tROLLNO: %s\tGAME MODE: %s\tGAME TYPE: %s\tSCORE: %0.2f\tWPS: %0.2f",player.name,player.rollno,gameM,gameT,score,*wps);
	fclose(fp);
}
void leaderboard(){
    int ch;
	FILE *fp;
	system("cls");
	gotoxy(19+29,0);printf("L E A D E R B O A R D");
	gotoxy(19+7,2);printf("P R E S S  A N Y  K E Y  T O  G O  B A C K  T O  M A I N  M E N U");
	fp=fopen("Leaderboard.txt","r");
	gotoxy(19+3,3);
	while((ch=fgetc(fp))!=EOF)
	{	
		printf("%c",ch);
	}
	getch();
	main();
}





