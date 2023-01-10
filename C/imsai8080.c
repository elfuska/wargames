#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void sleep(int time) {
        int i=0;
        for (i=0; i < time; i++) {}
}

void clrscr(void) {
	printf("\033[2J");
	printf("\033[0;0f");
}

void locate(int x, int y) {
	printf("\033[%d;%df", y, x);
}

char get_char(void)
{
        char c;
        fflush(stdout);
        c=getchar();
        if (c!='\r')    while(getchar()!='\r');
        return c;
}

void slow_print(char *msg) {

	int i;

	for(i=0;i<strlen(msg);i++) {
		fflush(stdout);
		printf("%c", (msg[i]));
		sleep(60);
	}

}

void dir(void) {
	slow_print("\nA: BYE     COM : CLS     COM : DIALER  COM: DIR     COM\n");
        slow_print("A: KERMIT  COM\n\n");
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

        slow_print("\nKermit-80 v4.11 configured for Generic CP/M-80 with Generic (Dumb) CRT Terminal\ntype selected\n\n");
        slow_print("For help, type ? at any point in a command\n");
        sleep(10000);
        slow_print("Kermit-80   0I:>set port uc1\n");
        sleep(10000);
        while (strcmp(tolower(command), "quit")!=0) {
		slow_print("Kermit-80   0I:>");
        	scanf("%s",command);
	        if(strcmp(tolower(command),"?")==0) {
		        slow_print("\nCONNECT to host on selected port\n\n");
	                sleep(10000);
	        } else if(strcmp(tolower(command),"connect")==0) {
		        slow_print("\nConnected to remote host.  Type Control-C to return\n");
                	slow_print("type Control-? for command list\n");
	                sleep(10000);
        	        slow_print("ATDT3115554855\n");
                	sleep(20000);
	                clrscr();
        	        slow_print("PDP 11/270 PRB TIP #45                                                TTY 34/984\n");
                	slow_print("WELCOME TO THE SEATTLE PUBLIC SCHOOL DISTRICT DATANET\n\n");
                
			while (strcmp(schpass, "pencil")!=0) {
				slow_print("PLEASE LOGON WITH USER PASSWORD: ");
        		        scanf("%s",schpass);
				if (strcmp(schpass, "pencil")!=0) slow_print("\nINVALID PASSWORD\n\n"); 
			}
                       
			while (strcmp(tolower(student),"exit")!=0) {
                        	
				slow_print("\nPLEASE ENTER STUDENT NAME: ");
				scanf("%s",student);
				
				if(strcmp(tolower(student),"lightman")==0) {
        		                slow_print("\nSTUDENT RECORD: Lightman, David L.\n\n");
                        		slow_print("     CLASS #    COURSE TITLE         GRADE    TEACHER    PERIOD    ROOM\n");
                                	slow_print("   ______________________________________________________________________\n\n");
	        	                slow_print("      S-202     BIOLOGY 2              ");
        	        	        slow_print("F");
                	        	slow_print("      LIGGET       3       214\n");
                        	        slow_print("      E-314     ENGLISH 11B            D      TURMAN       5       172\n");
		                        slow_print("      H-221     WORLD HISTORY 11B      C      DWYMER       2       108\n");
        		                slow_print("      M-106     TRIG 2                 B      DICKERSON    4       315\n");
                		        slow_print("      PE-02     PHYSICAL EDUCATION     C      COMSTOCK     1       GYM\n");
                        		slow_print("      M-122     CALCULUS 1             B      LOGAN        6       240\n\n");
		                } else if(strcmp(tolower(student),"mack")==0) {
        		                slow_print("\nSTUDENT RECORD: Mack, Jennifer K.\n\n");
                        		slow_print("     CLASS #    COURSE TITLE         GRADE    TEACHER    PERIOD    ROOM\n");
                             		slow_print("   ______________________________________________________________________\n\n");
       		                        slow_print("      S-202     BIOLOGY 2              ");
               		                slow_print("F");
                       		        slow_print("      LIGGET       3       214\n");
                               		slow_print("      E-325     ENGLISH 11B            A      ROBINSON     1       114\n");
		                        slow_print("      H-221     WORLD HISTORY 11B      B      DWYER        2       108\n");
        	       	                slow_print("      M-104     GEOMETRY 2             D      HALQUIST     4       307\n");
                	       	        slow_print("      B-107     ECONOMICS              D      MARKS        5       122\n");
                        	       	slow_print("      PE-02     PHYSICAL EDUCATION     C      COMSTOCK     6       GYM\n\n");
	       	                } else if (strcmp(tolower(student),"exit")!=0){
       	        	                slow_print("\nNO STUDENT RECORD FOUND\n\n");
                       		}

			}
	                slow_print("\n--DISCONNECTED--\n\n");
		}
        }
	return;
}

void scanner(void) {

        int hits=0;
        int pfs[4] = {399, 437, 767, 936};
	
	int nd=10000, i=0;

	clrscr();
	
	while (nd>9999) {
		slow_print("HOW MANY NUMBERS FOR EACH PREFIX TO DIAL: ");
		scanf("%d", &nd);
		if (nd>9999) slow_print("\nMAXIMUM IS 9999\n");
	}
	
	for (i=0;i<nd;i++) {
		if (i==0) {
			clrscr();
			slow_print("\n                    TO SCAN FOR CARRIER TONES, PLEASE LIST\n");
			slow_print("                         DESIRED AREA CODES AND PREFIXES\n\n");
			slow_print("AREA                AREA                AREA                AREA\n");
			slow_print("CODE PRFX NUMBER    CODE PRFX NUMBER    CODE PRFX NUMBER    CODE PRFX NUMBER\n");
			slow_print("________________________________________________________________________________\n");
			printf    ("(311) %d           (311) %d           (311) %d           (311) %d\n", pfs[0], pfs[1], pfs[2], pfs[3]);
			while (1) {
				locate(1, 9);slow_print("(311) "); scanf("%d", &pfs[0]);
				locate(21,9);slow_print("(311) "); scanf("%d", &pfs[1]);
				locate(41,9);slow_print("(311) "); scanf("%d", &pfs[2]);
				locate(61,9);slow_print("(311) "); scanf("%d", &pfs[3]);
				if (pfs[0]>0 && pfs[0]<999 && pfs[1]>0 && pfs[1]<999 && pfs[2]>0 && pfs[2]<999 && pfs[3]>0 && pfs[3]<999) break;  
				slow_print("INVALID PREFIXES ENTERED\n");
			}
		} else {
			locate( 1, 9+i);slow_print("(311) "); printf("%03d %04d", pfs[0], i); 
			locate(21, 9+i);slow_print("(311) "); printf("%03d %04d", pfs[1], i);
			locate(41, 9+i);slow_print("(311) "); printf("%03d %04d", pfs[2], i);
			locate(61, 9+i);slow_print("(311) "); printf("%03d %04d", pfs[3], i);
		}

	}

	return;
}

void read_sentence(char *str) {

        char joshua[40];
        char tmp='a';
        int i=0;

        fflush(stdin);
        while(tmp!='\r' && tmp!='\n'){
                tmp = getc(stdin);
                joshua[i]=tmp;
                i++;
        }
        joshua[i-1]='\0';
        fflush(stdin);
        strcpy(str, joshua);
}


void joshua_help(char *str) {
	slow_print("HELP\n");
}

void wait_until_response(char *str, char *response) {

	char joshua[40];

	while(strstr(response, tolower(joshua))!=0) {
		read_sentence(joshua);
	}
	printf("Leido ok: %s\n", joshua);

}

void do_joshua(void) {

	char joshua[40];

        clrscr();
        slow_print("145          11456          11889          11893\n");
        slow_print("PRT CON. 3.4.5. SECTRAN 9.4.3.          PORT STAT: SB-345\n"); sleep(1000); clrscr();
        slow_print("(311) 655-7385\n"); sleep(1000); slow_print("\n"); sleep(1000); clrscr();
        slow_print("\n"); sleep(1000); slow_print("\n"); clrscr();
        slow_print("\n\n"); sleep(1000); clrscr();
        slow_print("(311) 767-8739\n"); sleep(1000);
        slow_print("(311) 936-2364\n"); sleep(1000); clrscr();
        slow_print("PRT. STAT.                   CRT. DEF.\n"); sleep(1000);
        slow_print("================================================\n");
        slow_print("FSKJJSJ: SUSJKJ: SUFJSL:          DKSJL: SKFJJ: SDKFJLJ\n"); sleep(1000);
        slow_print("SYSPROC FUNCT READY          ALT NET READY\n"); sleep(1000);
        slow_print("CPU AUTH RY-345-AX3     SYSCOMP STATUS: ALL PORTS ACTIVE\n"); sleep(1000);
        slow_print("22/34534.90/3289               CVB-3904-39490\n"); sleep(1000);
        slow_print("(311) 936-2384\n"); sleep(1000);
        slow_print("(311) 936-3582\n"); sleep(1000);
        slow_print("22/34534.3209                  CVB-3904-39490\n"); sleep(1000);
        slow_print("12934-AD-43KJ: CENTR PAK\n"); sleep(1000);
        slow_print("(311) 767-1083\n"); sleep(1000); clrscr();
        slow_print("FLD CRS: 33.34.543     HPBS: 34/56/67/83     STATUS FLT  034/304\n"); sleep(1000);
        slow_print("1105-45-F6-B456          NOPR STATUS: TRAK OFF     PRON ACTIVE\n"); sleep(1000);
        slow_print("(45:45:45  WER: 45/29/01 XCOMP: 43239582 YCOMP: 3492930D ZCOMP: 343906834\n"); sleep(1000);
        slow_print("                                          SRON: 65=65/74/84/65/89\n"); sleep(1000); clrscr();
        slow_print("-           PRT. STAT.                        CRY. DEF.\n"); sleep(1000);
        slow_print("(311) 936-1582==============================================\n"); sleep(1000);
        slow_print("                  3453                3594\n"); sleep(1000); clrscr();
        slow_print("FLJ42   TK01   BM90   R601   6J82   FP03   ZWO::   JW89\n"); sleep(1000);
        slow_print("DEF TRPCON: 43.45342.349\n"); sleep(10000); sleep(1000);
        slow_print("SYSPROC FUNCT READY                            ALT NET READY\n"); sleep(1000);
        slow_print("\n"); sleep(1000);
        slow_print("CPU AUTH RY-345-AX3     SYSCOMP STATUS: ALL PORTS ACTIVE\n"); sleep(1000);
        slow_print("(311) 936-2364\n"); sleep(1000);
        slow_print("**********************************************************************\n"); sleep(1000);
        slow_print("1105-45-F6-B456                 NOPR STATUS: TRAK OFF   PRON ACTIVE\n"); clrscr(); sleep(1000);
        clrscr();
        slow_print("GREETINGS PROFESSOR FALKEN.\n");
        read_sentence(joshua);
	wait_until_response(joshua, "hello");
	return;

}

void wopr(void) {

	char joshua[40];

	clrscr();

	slow_print("DIALING\n");
	slow_print("CONNECTING\n"); sleep(10000);
	clrscr();
	slow_print("                         #\n"); sleep(1000); clrscr();
	slow_print("\n                                           #\n"); sleep(1000); clrscr();
	slow_print("\n\n                                                          #\n"); sleep(1000); clrscr();
	slow_print("\n\n\n");
	
	while(1) {
		slow_print("\nLOGON: ");
		read_sentence(joshua);
		
		if (strcmp(tolower(joshua), "joshua")==0) {
			do_joshua();
			break;
		} else if (strcmp(tolower(joshua), "help")==0) {
			joshua_help("help");
		} else if (strcmp(tolower(joshua), "help logon")==0) {
                        joshua_help("logon");
                } else if (strcmp(tolower(joshua), "help games")==0) {
                        joshua_help("games");
                } else if (strcmp(tolower(joshua), "list games")==0) {
                        joshua_help("list");
                } else if (strcmp(tolower(joshua), "list games")==0) {
			break;
		}
	}

	return;
}

void line_busy(void) {
	clrscr();
	sleep(10000);
	slow_print("DIALING\n");
	sleep(10000);
	slow_print("ERROR 676   LINE BUSY\n");
	sleep(10000);
	return;
}

void view_systems(void) {

	int pfx[9][2] = {
                {437, 1083},
                {936, 1493},
                {399, 2364},
                {437, 2977},
                {767, 3395},
                {399, 3582},
                {936, 3923},
                {767, 7305},
                {437, 8739}
        };
	char system[1];

	int i=0;

	clrscr();
	slow_print("                  NUMBERS FOR WHICH CARRIER TONES WERE DETECTED:\n\n");
	for (i=0;i<9;i++) {
		printf("                               (%c)   (311) %d   %d\n", 'A'+i, pfx[i][0], pfx[i][1]);
	}

	slow_print("\n\n\n                        PRESS ENTER KEY TO RETURN TO MENU\n");
	slow_print("                        OR SELECT SYSTEM: ");
	scanf("%s", system);

	if (strcmp(tolower(system), "a")==0) {
		line_busy();
	} else if (strcmp(tolower(system), "b")==0) {
		line_busy();
        } else if (strcmp(tolower(system), "c")==0) {
		//union marine bank
        } else if (strcmp(tolower(system), "d")==0) {
		line_busy();
        } else if (strcmp(tolower(system), "e")==0) {
		line_busy();
        } else if (strcmp(tolower(system), "f")==0) {
		//pan am
        } else if (strcmp(tolower(system), "g")==0) {
		line_busy();
        } else if (strcmp(tolower(system), "h")==0) {
		line_busy();
        } else if (strcmp(tolower(system), "i")==0) {
		wopr();
        } else {
		return;
        } 
}


void dialer(void) {

	char command[1];

	clrscr();
	printf("\n\nDIALER\n");
	while (strcmp(tolower(command), "exit")!=0 && strcmp(tolower(command), "x")!=0) {
		slow_print("\nMENU - (S)CAN, (V)IEW OR E(X)IT: ");
		scanf("%s", command);
		if (strcmp(tolower(command), "scan")==0 || strcmp(tolower(command), "s")==0) {
			scanner();
		} else if (strcmp(tolower(command), "view")==0 || strcmp(tolower(command), "v")==0) {	
			view_systems();
		}
	}
	return;
}

int main(void){
	
	char command[1];
	
	clrscr();
	
	sleep(10000);
	slow_print("64K CP/M VERS. 2.2 MCL030210-D-F8\n\n");
	
	while (1) {
		slow_print("A>");
		scanf("%s", command);
		if(strcmp(tolower(command),"cls")==0) {
			clrscr();
		} else if(strcmp(tolower(command),"bye")==0) {
			slow_print("System powered off, bye.\n");
			break;
		} else if(strcmp(tolower(command),"dir")==0) {
			dir();
		} else if(strcmp(tolower(command),"kermit")==0) {
			kermit();
		} else if (strcmp(tolower(command),"dialer")==0) {
			dialer();	
		} else {
			printf("\n%s?\n\n", command);
		}
	}
	return 0;
}
