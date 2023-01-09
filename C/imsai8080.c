#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clrscr(void) {
	printf( "\033[2J" );
	printf("\033[0;0f");
}

void dir(void) {
	printf("\nA: BYE     COM : CLS     COM : DIALER  COM: DIR     COM\n");
        printf("A: KERMIT  COM\n\n");
}

void sleep(int time) {
	int i=0;
	for (i=0; i < time; i++) {}

}

char *tolower(char *str1) {

	int i,len;
	len=strlen(str1);
	for (i=0; i<len;i++) {
		if (str1[i] >= 'A' && str1[i] <= 'Z') { 
			str1[i]=str1[i]|32;
		}
	}
	return str1;
}

void kermit(void) {

        char command[1];
        char schpass[1];
        char student[1];
        char grade[2];

        printf("\nKermit-80 v4.11 configured for Generic CP/M-80 with Generic (Dumb) CRT Terminal\ntype selected\n\n");
        printf("For help, type ? at any point in a command\n");
        sleep(10000);
        printf("Kermit-80   0I:>set port uc1\n");
        sleep(10000);
        while (strcmp(tolower(command), "quit")!=0) {
		printf("Kermit-80   0I:>");
        	scanf("%s",command);
	        if(strcmp(tolower(command),"?")==0) {
		        printf("\nCONNECT to host on selected port\n");
                	printf("\n");
	                sleep(10000);
	        } else if(strcmp(tolower(command),"connect")==0) {
		        printf("\nConnected to remote host.  Type Control-C to return\n");
                	printf("type Control-? for command list\n");
	                sleep(10000);
        	        printf("ATDT3115554855\n");
                	sleep(30000);
	                clrscr();
        	        printf("PDP 11/270 PRB TIP #45                                                TTY 34/984\n");
                	printf("WELCOME TO THE SEATTLE PUBLIC SCHOOL DISTRICT DATANET\n\n");
                
			while (strcmp(schpass, "pencil")!=0) {
				printf("PLEASE LOGON WITH USER PASSWORD: ");
        		        scanf("%s",schpass);
				if (strcmp(schpass, "pencil")!=0) printf("\nINVALID PASSWORD\n\n"); 
			}
                       
			while (strcmp(tolower(student),"exit")!=0) {
                        	
				printf("\nPLEASE ENTER STUDENT NAME: ");
				scanf("%s",student);
				
				if(strcmp(tolower(student),"lightman")==0) {
		               		printf("\n");
        		                printf("STUDENT RECORD: Lightman, David L.\n\n");
                        		printf("     CLASS #    COURSE TITLE         GRADE    TEACHER    PERIOD    ROOM\n");
                                	printf("   ______________________________________________________________________\n\n");
	        	                printf("      S-202     BIOLOGY 2              ");
        	        	        printf("F");
                	        	printf("      LIGGET       3       214\n");
                        	        printf("      E-314     ENGLISH 11B            D      TURMAN       5       172\n");
		                        printf("      H-221     WORLD HISTORY 11B      C      DWYMER       2       108\n");
        		                printf("      M-106     TRIG 2                 B      DICKERSON    4       315\n");
                		        printf("      PE-02     PHYSICAL EDUCATION     C      COMSTOCK     1       GYM\n");
                        		printf("      M-122     CALCULUS 1             B      LOGAN        6       240\n");
                                	printf("\n");
		                } else if(strcmp(tolower(student),"mack")==0) {
		                        printf("\n");
        		                printf("STUDENT RECORD: Mack, Jennifer K.\n\n");
                        		printf("     CLASS #    COURSE TITLE         GRADE    TEACHER    PERIOD    ROOM\n");
                             		printf("   ______________________________________________________________________\n\n");
       		                        printf("      S-202     BIOLOGY 2              ");
               		                printf("F");
                       		        printf("      LIGGET       3       214\n");
                               		printf("      E-325     ENGLISH 11B            A      ROBINSON     1       114\n");
		                        printf("      H-221     WORLD HISTORY 11B      B      DWYER        2       108\n");
        	       	                printf("      M-104     GEOMETRY 2             D      HALQUIST     4       307\n");
                	       	        printf("      B-107     ECONOMICS              D      MARKS        5       122\n");
                        	       	printf("      PE-02     PHYSICAL EDUCATION     C      COMSTOCK     6       GYM\n");
                                	printf("\n");
	       	                } else if (strcmp(tolower(student),"exit")!=0){
       	        	                printf("\nNO STUDENT RECORD FOUND\n\n");
                       		}

			}
	                printf("\n--DISCONNECTED--\n\n");
		}
        }
	return;
}


int main(void){
	
	char command[1];
	
	clrscr();
	sleep(10000);
	printf("64K CP/M VERS. 2.2 MCL030210-D-F8\n\n");
	
	while (1) {
		printf("A>");
		scanf("%s", command);
		if(strcmp(tolower(command),"cls")==0) {
			clrscr();
		} else if(strcmp(tolower(command),"bye")==0) {
			printf("INT disabled and HALT Op-Code reached at 0101\n");
			break;
		} else if(strcmp(tolower(command),"dir")==0) {
			dir();
		} else if(strcmp(tolower(command),"kermit")==0) {
			kermit();
		} else {
			printf("\n%s?\n\n", command);
		}
	}
	return 0;
}
