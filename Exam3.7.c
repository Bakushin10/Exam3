/*

In the function result putItBack, putItBack2 mihgt have math issues.

+ sorting for display

Shin


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define flush fflush(stdin)
#define cls system ("cls")
#define pause system ("pause")
#define SIZE 12

typedef struct{
	int teams;
	double win;
	double lose;
	double PCT;
	int total;
	int RunsScore;
	int RunsAgainst;
	int counter;

} major;//end of struct 


//function protytype
int mainMenu();
void game(major *team, major *temp,int *score,int *Pteam,int *flag);
void game2(major *team, major *temp,int *score2,int *Pteam2,int score, int Pteam, int *flag);
void result(major *team,major *temp,int score,int score2,int Pteam,int Pteam2);
void putItBack(major *team,major *temp,int Pteam,int score);
void putItBack2(major *team,major *temp,int Pteam2,int score);
void display(major *team,int flag,char teamName[12][20]);
void reset(major *team,major *temp,int *flag);

FILE *fp;

main(){
	int read =0;
	int choice=0, flag=0;
	int score=0,score2=0,Pteam=0,Pteam2=0;
	int i=0;
	char teamName[12][20]={"Atlanta","Baltimore","Boston","NY Yankees","St.Louis","Los Angeles","Chicago","NY Mets","San Francisco",
		"Miami","Philadelphia","Detroit"};

	major team[SIZE];           major temp[SIZE];

	for(i=0;i<12;i++){ //access to all 12 teams
		team[i].teams=0;           temp[i].teams=0; //0
		team[i].win=0.0;           temp[i].win=0.0;
		team[i].lose=0.0;          temp[i].lose=0.0;
		team[i].PCT=0.0;           temp[i].PCT=0.0;
		team[i].total=0;           temp[i].total=0;
		team[i].RunsScore=0;       temp[i].RunsScore=0;
		team[i].RunsAgainst=0;     temp[i].RunsAgainst=0;
		team[i].counter=0;         temp[i].counter=0;
	}//end of for 

	fp = fopen("MLB.bin", "ab+");
	fread(&read, sizeof(int), 1, fp);
	fclose(fp);
	
	flag = read;
	if(flag > 0){
		fp = fopen("MLB.bin", "rb");
		fseek(fp, sizeof(int), SEEK_SET);
		fread(&team,sizeof(major), SIZE, fp);
		fclose(fp);
	}
	

	do{
		cls;
		choice = mainMenu();
		switch(choice){
		case 1:
			game(team,temp,&score,&Pteam,&flag);
			game2(team,temp,&score2,&Pteam2,score,Pteam,&flag);
			result(team,temp,score,score2,Pteam,Pteam2);
			putItBack(team,temp,Pteam,score);
			putItBack2(team,temp,Pteam2,score2);
			fp = fopen("MLB.bin", "wb");
			fwrite(&flag, sizeof(int), 1, fp);
			fwrite(&team,sizeof(major), SIZE, fp);
			fclose(fp);
			pause;
			break;
		case 2:
			display(team,flag,teamName);
			pause;
			break;
		case 3:
			reset(team,temp,&flag);
			break;
		case 4:
			printf("See you\n\n");
			pause;

		}//End of switch
	}while(choice!=4);

}//end of main

int mainMenu(){
	int i=0;
	printf("1) Enter the result of a game\n");
	printf("2) Display the league standings \n");
	printf("3) Restart the entire season \n");
	printf("4) Quit the program\n");
	scanf("%i",&i);
	flush;
	return i;
}//end of mainmenu

void game(major *team, major *temp,int *score,int *Pteam,int *flag){

	*flag= *flag + 1;
	cls;
	printf("\t1\t Atlanta Braves\n");
	printf("\t2\t Baltimore Orioles\n");
	printf("\t3\t Boston Red Sox\n");
	printf("\t4\t New York Yankees\n");
	printf("\t5\t St.Louis Cardinals\n");
	printf("\t6\t Los Angeles Dogers\n");
	printf("\t7\t Chicago White Sox\n");
	printf("\t8\t New  York Mets\n");
	printf("\t9\t San Francisco Giants\n");
	printf("\t10\t Miami Marlins\n");
	printf("\t11\t Philadelphia Phillies\n");
	printf("\t12\t Detroit Tigers\n\n");

	printf("Game %i pick team 1:", *flag);
	scanf("%i",Pteam);
	if(*Pteam>=13){
		do{
			printf("Selected team is invalid\n");
			printf("Game 1 pick team 1:");
			scanf("%i",Pteam);
		}while(*Pteam >= 13);// end of do while loop
	}// end of if

	printf("\nScore?");
	scanf("%i",score);
	//*(team + someNum).member ....
	(temp+*Pteam - 1)->win = (team + *Pteam - 1)->win; 
	(temp+*Pteam - 1)->lose = (team + *Pteam - 1)->lose;
	(temp+*Pteam - 1)->PCT = (team + *Pteam - 1)->PCT;
	(temp+*Pteam - 1)->RunsAgainst = (team + *Pteam - 1)->RunsAgainst;
	(temp+*Pteam - 1)->RunsScore = (team + *Pteam - 1)->total;
	(temp+*Pteam - 1)->counter = (team + *Pteam - 1)->counter;

}///end of game 


void game2(major *team, major *temp,int *score2,int *Pteam2,int score, int Pteam, int *flag){
	cls;
	printf("\t1\t Atlanta Braves\n");
	printf("\t2\t Baltimore Orioles\n");
	printf("\t3\t Boston Red Sox\n");
	printf("\t4\t New York Yankees\n");
	printf("\t5\t St.Louis Cardinals\n");
	printf("\t6\t Los Angeles Dogers\n");
	printf("\t7\t Chicago White Sox\n");
	printf("\t8\t New  York Mets\n");
	printf("\t9\t San Francisco Giants\n");
	printf("\t10\t Miami Marlins\n");
	printf("\t11\t Philadelphia Phillies\n");
	printf("\t12\t Detroit Tigers\n\n");

	printf("Game %i pick team 2:", *flag);
	scanf("%i",Pteam2);
	if(*Pteam2>=13 || Pteam == *Pteam2){
		do{
			printf("Selected team is invalid\n");
			printf("Game 1 pick team 1:");
			scanf("%i",Pteam2);
		}while(*Pteam2 >= 13|| Pteam == *Pteam2);// end of do while loop
	}// end of if

	printf("\nScore?");
	scanf("%i",score2);

	if(score==*score2){
		do{
			printf("There Is No Tie Game In MLB");
			printf("\nScore?");
			scanf("%i",score2);
		}while(score==*score2);// end of do while loop
	}//end of if

	//*(team + someNum).member ....
	(temp+*Pteam2 - 1)->win = (team + *Pteam2 - 1)->win; 
	(temp+*Pteam2 - 1)->lose = (team + *Pteam2 - 1)->lose;
	(temp+*Pteam2 - 1)->PCT = (team + *Pteam2 - 1)->PCT;
	(temp+*Pteam2 - 1)->RunsAgainst = (team + *Pteam2 - 1)->RunsAgainst;
	(temp+*Pteam2 - 1)->RunsScore =  (team + *Pteam2 - 1)->total;
	(temp+*Pteam2 - 1)->counter =  (team + *Pteam2 - 1)->counter;

}//end of game2

void result(major *team,major *temp,int score,int score2,int Pteam,int Pteam2){

	if(score>score2){
		(temp+Pteam - 1)->counter=(temp+Pteam - 1)->counter+1;
		(temp+Pteam2 - 1)->counter=(temp+Pteam2 - 1)->counter+1;
		(temp+Pteam - 1)->win=(temp+Pteam - 1)->win+1;
		(temp+Pteam2 - 1)->lose=(temp+Pteam2 - 1)->lose+1;
		(temp+Pteam - 1)->PCT=(temp+Pteam - 1)->win/(temp+Pteam - 1)->counter;
		(temp+Pteam2 - 1)->PCT=    (temp+Pteam2 - 1)->win/ (temp+Pteam2 - 1)->counter;
		(temp+Pteam - 1)->RunsScore =(temp+Pteam - 1)->RunsScore +score;
		(temp+Pteam2 - 1)->RunsScore=(temp+Pteam2 - 1)->RunsScore+score2;
		(temp+Pteam2 - 1)->RunsAgainst =(temp+Pteam2 - 1)->RunsAgainst +score;
		(temp+Pteam - 1)->RunsAgainst=(temp+Pteam - 1)->RunsAgainst+score2;
	}// end of if
	else{
		(temp+Pteam - 1)->counter=(temp+Pteam - 1)->counter+1;
		(temp+Pteam2 - 1)->counter=(temp+Pteam2 - 1)->counter+1;
		(temp+Pteam2 - 1)->win=(temp+Pteam2 - 1)->win+1;
		(temp+Pteam - 1)->lose=(temp+Pteam - 1)->lose+1;
		(temp+Pteam - 1)->PCT=(temp+Pteam - 1)->win/(temp+Pteam - 1)->counter;
		(temp+Pteam2 - 1)->PCT=(temp+Pteam2 - 1)->win/ (temp+Pteam2 - 1)->counter;
		(temp+Pteam - 1)->RunsScore =(temp+Pteam - 1)->RunsScore +score;
		(temp+Pteam2 - 1)->RunsScore=(temp+Pteam2 - 1)->RunsScore+score2;
		(temp+Pteam2 - 1)->RunsAgainst =(temp+Pteam2 - 1)->RunsAgainst +score;
		(temp+Pteam - 1)->RunsAgainst=(temp+Pteam - 1)->RunsAgainst+score2;
	}//end of else

}//end of result

void putItBack(major *team,major *temp,int Pteam,int score){

	(team + Pteam - 1)->win=(temp+Pteam - 1)->win; 
	(team + Pteam - 1)->lose=(temp+Pteam - 1)->lose;
	(team + Pteam - 1)->PCT=(temp+Pteam - 1)->PCT;
	(team + Pteam - 1)->total =(temp+Pteam - 1)->RunsScore;    
	(team + Pteam - 1)->RunsAgainst=(temp+Pteam - 1)->RunsAgainst;
	(team + Pteam - 1)->counter=(temp+Pteam - 1)->counter;

}//end of putItBack

void putItBack2(major *team, major *temp,int Pteam2,int score){

	(team + Pteam2 - 1)->win=(temp+Pteam2 - 1)->win; 
	(team + Pteam2 - 1)->lose=(temp+Pteam2 - 1)->lose;
	(team + Pteam2 - 1)->PCT=(temp+Pteam2 - 1)->PCT;
	(team + Pteam2 - 1)->total =(temp+Pteam2 - 1)->RunsScore ;  
	(team + Pteam2 - 1)->RunsAgainst=(temp+Pteam2 - 1)->RunsAgainst;
	(team + Pteam2 - 1)->counter=(temp+Pteam2 - 1)->counter;

}//end of putItBack2

void display(major *team,int flag,char teamName[12][20]){
	major teamSorted[SIZE];							major temp;
	char teamNameS[SIZE][20];
	char tempName[20];
	int i = 0, a = 0, b=0;
	int length=0;
	cls;
	for(i=0;i<SIZE;i++){
		teamSorted[i].win = (team + i)->win;
		teamSorted[i].lose = (team + i)->lose;
		teamSorted[i].PCT = (team + i)->PCT;
		teamSorted[i].total =(team + i)->total;
		teamSorted[i].RunsAgainst = (team + i)->RunsAgainst;
		strcpy(teamNameS[i], teamName[i]);
	}//end of for loop
	for(a = 0; a < SIZE; a++){
		for(b = 0; b < SIZE-1; b++){
			if(teamSorted[b].total < teamSorted[b+1].total){
				temp.total = teamSorted[b].total;
				teamSorted[b].total = teamSorted[b+1].total;
				teamSorted[b+1].total = temp.total;

				strcpy(tempName, teamNameS[b]);
				strcpy(teamNameS[b], teamNameS[b+1]);
				strcpy(teamNameS[b+1], tempName);

				temp.PCT = teamSorted[b].PCT;
				teamSorted[b].PCT = teamSorted[b+1].PCT;
				teamSorted[b+1].PCT = temp.PCT;

				temp.win = teamSorted[b].win;
				teamSorted[b].win = teamSorted[b+1].win;
				teamSorted[b+1].win = temp.win;

				temp.lose = teamSorted[b].lose;
				teamSorted[b].lose = teamSorted[b+1].lose;
				teamSorted[b+1].lose = temp.lose;

				temp.RunsAgainst = teamSorted[b].RunsAgainst;
				teamSorted[b].RunsAgainst = teamSorted[b+1].RunsAgainst;
				teamSorted[b+1].RunsAgainst = temp.RunsAgainst;
			}// end of if
		}// end of inner for loop
	}// end of outer for loop

	for(a = 0; a < SIZE; a++){
		for(b = 0; b < SIZE-1; b++){
			if(teamSorted[b].PCT < teamSorted[b+1].PCT){
					temp.PCT = teamSorted[b].PCT;
					teamSorted[b].PCT = teamSorted[b+1].PCT;
					teamSorted[b+1].PCT = temp.PCT;

					strcpy(tempName, teamNameS[b]);
					strcpy(teamNameS[b], teamNameS[b+1]);
					strcpy(teamNameS[b+1], tempName);

					temp.win = teamSorted[b].win;
					teamSorted[b].win = teamSorted[b+1].win;
					teamSorted[b+1].win = temp.win;

					temp.lose = teamSorted[b].lose;
					teamSorted[b].lose = teamSorted[b+1].lose;
					teamSorted[b+1].lose = temp.lose;

					temp.total = teamSorted[b].total;
					teamSorted[b].total = teamSorted[b+1].total;
					teamSorted[b+1].total = temp.total;

					temp.RunsAgainst = teamSorted[b].RunsAgainst;
					teamSorted[b].RunsAgainst = teamSorted[b+1].RunsAgainst;
					teamSorted[b+1].RunsAgainst = temp.RunsAgainst;
				}// end of if
			}// end of inner for loop
		}// end of outer for loop 
	
	if(flag > 0){
		printf("Team\t\tWin\t\tLoses\tPCT\tRunscore\tRun Against\n");
		printf("----\t\t---\t\t-----\t---\t-------\t\t-----------\n");
		for(i=0; i<SIZE; i ++){
			printf("%s\t",teamNameS[i]);
			length=strlen(teamNameS[i]);// if the letter is more than 8 remove \t
			if(length>=8){
				printf("%.0lf\t\t%.0lf\t%.3lf\t%i\t\t%i\n",teamSorted[i].win,teamSorted[i].lose,teamSorted[i].PCT,teamSorted[i].total,teamSorted[i].RunsAgainst);
			}//end of if

			else
				printf("\t%.0lf\t\t%.0lf\t%.3lf\t%i\t\t%i\n",teamSorted[i].win,teamSorted[i].lose,teamSorted[i].PCT,teamSorted[i].total,teamSorted[i].RunsAgainst);
		}// end of for
	}//end of if 

	else{
		printf("\n\tXXX No games have played in the League for this Season XXX\n\n\n");
		printf("\t1\t Atlanta Braves\n");
		printf("\t2\t Baltimore Orioles\n");
		printf("\t3\t Boston Red Sox\n");
		printf("\t4\t New York Yankees\n");
		printf("\t5\t St.Louis Cardinals\n");
		printf("\t6\t Los Angeles Dogers\n");
		printf("\t7\t Chicago White Sox\n");
		printf("\t8\t New  York Mets\n");
		printf("\t9\t San Francisco Giants\n");
		printf("\t10\t Miami Marlins\n");
		printf("\t11\t Philadelphia Phillies\n");
		printf("\t12\t Detroit Tigers\n\n");
	}//end of else
}//end of display

void reset(major *team,major *temp,int *flag){
	int i;
		for(i=0;i<12;i++){ //access to all 12 teams
		team[i].teams=0;           temp[i].teams=0; //0
		team[i].win=0.0;           temp[i].win=0.0;
		team[i].lose=0.0;          temp[i].lose=0.0;
		team[i].PCT=0.0;           temp[i].PCT=0.0;
		team[i].total=0;           temp[i].total=0;
		team[i].RunsScore=0;       temp[i].RunsScore=0;
		team[i].RunsAgainst=0;     temp[i].RunsAgainst=0;
		team[i].counter=0;         temp[i].counter=0;
	}//end of for 
	*flag=0;
	fp = fopen("MLB.bin","wb");
	fclose(fp);
	cls;
	printf("This is a new season\n\n");
	pause;
}// end of reset
