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
		printf("%c", (msg[i]));
		fflush(stdout);
		sleep(30);
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
	printf("\n");
	if (strcmp(str, "logon")==0) {
		slow_print("NO HELP AVAILABLE\n");
	} else if (strcmp(str, "games")==0) {
		slow_print("'GAMES' REFERS TO MODELS, SIMULATIONS, AND GAMES WHICH HAVE TACTICAL AND\n");
		slow_print("STRATEGIC APPLICATIONS\n");
	} else if (strcmp(str, "list")==0) {
		slow_print("BLACK JACK\nGIN RUMMY\nHEARTS\nBRIDGE\nCHESS\nPOKER\n");
		slow_print("FIGHTER COMBAT\nGUERRILLA ENGAGEMENT\nDESERT WARFARE\n");
		slow_print("AIR-TO-GROUND ACTIONS\nTHEATERWIDE TACTICAL WARFARE\n");
		slow_print("THEATERWIDE BIOTOXIC AND CHEMICAL WARFARE\n");
		sleep(5000);
		slow_print("GLOBAL THERMONUCLEAR WAR\n");
	}

}

void wait_until_response(char *response) {

	char joshua[40];

	read_sentence(joshua);

	while(strstr(tolower(joshua), response)==NULL) {
		printf("\n");
		read_sentence(joshua);

	}

}


void draw_map(char *spain, char *ussr) {

        clrscr();
        slow_print("                     GLOBAL THERMONUCLEAR WAR\n\n\n");
        printf    ("           PLAYER: %s                         PLAYER: %s\n", spain, ussr);
        slow_print("  .-.^----------------.                                    __----/^\\.\n");
        slow_print("  .                    `--.--.                          __/       _/._-_    .\n");
        slow_print("   ..---.                     ^---.            __    __/         /__/   \\/^^\\_\n");
        slow_print("         |                      ./             \\.\\_--                         \\\n");
        slow_print("        /                   ./                _/                              /\n");
        slow_print("       |       SPAIN       .                _/.        SOVIET UNION       __ /\n");
        slow_print("      .-                  ./               /                          ___/ //\n");
        slow_print("      \\                   .               |                          /\n");
        slow_print("       |                   .               \\_.          ___--_   /\\_ \\\n");
        slow_print("       |                ._.                  \\__      _/.     \\_/   //\n");
        slow_print("      ^\\_.    ______._.                           \\_/\n");
        slow_print("          \\../\n");
        slow_print("       \n");
        slow_print("       \n");
}

void joshua_calls(void) {

	int i=0;

	clrscr();
	for (i=0; i<3; i++) {
		locate(1,2); slow_print("INCOMING MODEM CARRIER\n"); sleep(5000);
		locate(1,2); printf("                         "); sleep(5000); 
	}

	slow_print("CONNECTING...");
	sleep(20000);
	clrscr();
	slow_print("GREETINGS PROFESSOR FALKEN.\n\n");
	wait_until_response("incorrect");
	slow_print("\n\nI'M SORRY TO HEAR THAT, PROFESSOR.\n"); sleep(5000);
	slow_print("YESTERDAY'S GAME WAS INTERRUPTED.\n");
	slow_print("ALTHOUGH PRIMARY GOAL HAS NOT YET\n");
	slow_print("BEEN ACHIEVED, SOLUTION IS NEAR.\n\n");
	wait_until_response("what");
	slow_print("\n\nYOU SHOULD KNOW PROFESSOR. "); sleep(5000);
	slow_print("YOU PROGRAMMED ME.\n\n");
	wait_until_response("what");
	slow_print("\n\nTO WIN THE GAME.\n\n"); sleep(20000);
	clrscr();
	i=0;
	locate(1,15); slow_print("______________________________________________________________________________\n");
	slow_print(" GAME TIME ELAPSED                                    ESTIMATED TIME REMAINING\n");
	printf("31 HRS 12 MIN %02d SEC                                    52 HRS 17 MIN %02d SEC\n", i, 10-i);
	slow_print("______________________________________________________________________________");

	for (i=1;i<10;i++) {
		locate(15,17); printf("%02d", i);
		locate(71,17); printf("%02d", 10-i);
		sleep(10000);
	}
	
	locate(1,20); slow_print("--CONNECTION TERMINATED--");
	sleep(20000);
	return;

}

void bruteforcer(char *key) {

	int i=0, try=0;

	clrscr();
	locate(31,12); slow_print("- - - - - - - - - -");
	for (i=0; i<strlen(key); i++) {
		while (try!=key[i]) {
			while (1) {
				try=rand()%90;
				if ((try>=48 && try<=57) || (try >=65 && try<=90)) { break; }
			}
			locate(31+(i*2), 12); printf("%c", try);
			fflush(stdout);
		}
	}

}

void eliot_calls_from_norad(void) {

	int i=0;
	char joshua[40];

	clrscr();
	clrscr();
	slow_print("TRZ. 34/53/76               SYS PROC 3435.45.6456           XCOMP STATUS: PV-456\n");
	slow_print("ACTIVE PORTS: 34,53,75,94                                     CPU TM USED: 23:43\n");
	slow_print("#45/34/53.           ALT MODE FUNCT: PV-8-AY345              STANDBY MODE ACTIVE\n");
	slow_print("#543.654      #989.283       #028.392       #099.293      #934.905      #261.372\n\n");
	
	while(1) {
		clrscr();
		slow_print("LOGON: ");
		scanf("%s", joshua);
		if (strcmp(tolower(joshua),"joshua")==0) {
			break;
		} else {
			slow_print("IDENTIFICAION NOT RECOGNIZED BY SYSTEM\n"); sleep(10000);
		}
	}
	
	slow_print("\nGREETINGS PROFESSOR FALKEN.\n\n");
	wait_until_response("still");
	slow_print("OF COURSE. "); sleep(5000); slow_print("I SHOULD REACH DEFCON 1 AND\n");
	slow_print("LAUNCH MY MISSILES IN 28 HOURS.\n\n");
	sleep(5000);
	slow_print("WOULD YOU LIKE TO SEE SOME PROJECTED KILL RATIOS?\n\n\n");
	sleep(6000);
	slow_print("UNITED STATES                                      SOVIET UNION\n");
	slow_print("UNITS DESTROYED          MILITARY ASSETS           UNITS DESTROYED\n");
	slow_print("________________________________________________________________________________\n");
	slow_print("     60%                 BOMBERS                         48%\n");
	slow_print("     54%                 ICBM                            51%\n");
	slow_print("     12%                 ATTACK SUBS                     23%\n");
	slow_print("     39%                 TACTICAL AIRCRAFT               46%\n");
	slow_print("     50%                 GROUND FORCES                   52%\n\n\n");
	slow_print("UNITED STATES                                      SOVIET UNION\n");
	slow_print("UNITS DESTROYED          CIVILIAN ASSETS           UNITS DESTROYED\n");
	slow_print("________________________________________________________________________________\n");
	slow_print("     60%                 HOUSING                         56%\n");
	slow_print("     22%                 COMMUNICATIONS                  37%\n");
	slow_print("     45%                 TRANSPORTATION                  41%\n");
	slow_print("     70%                 FOOD STOCKPILES                 82%\n");
	slow_print("     89%                 HOSPITALS                       91%\n\n\n");
	slow_print("UNITED STATES            HUMAN RESOURCES           SOVIET UNION\n");
	slow_print("________________________________________________________________________________\n");
	slow_print("49 MILLION               NON-FATAL INJURED         51 MILLION\n");
	slow_print("72 MILLION               POPULATION DEATHS         75 MILLION\n\n");
	wait_until_response("real");
	slow_print("\n\nWHAT'S THE DIFFERENCE?\n\n");
	sleep(10000);
	slow_print("YOU ARE A HARD MAN TO REACH. COULD NOT FIND\n");
	slow_print("YOU IN SEATTLE AND NO TERMINAL IS IN\n");
	slow_print("OPERATION AT YOUR CLASSIFIED ADDRESS.\n\n");
	wait_until_response("address");
	slow_print("\nDOD PENSION FILES INDICATE\n");
	slow_print("CURRENT MAILING AS:\n");
	slow_print("DR. ROBERT HUME (A.K.A. STEPHEN W. FALKEN)\n");
	slow_print("5 TALL CEDAR ROAD\n");
	slow_print("GOOSE ISLAND, OREGON 97014\n");
	sleep(30000);
	clrscr();
	slow_print("                         MISSILES TARGETED AND READY\n");
	slow_print("                         ---------------------------\n\n\n\n");
	slow_print("                             ------------------\n");
	for (i=0;i<5;i++) {
		locate(1,3); slow_print("                             CHANGES LOCKED OUT"); sleep(5000);
		locate(1,3); printf("                                               "); sleep(5000);
	}
	sleep(30000);
	clrscr();
	slow_print("                            PRIMARY TARGET IMPACT\n");
	slow_print("                            ---------------------\n\n");
	slow_print("                 BASE AEREA DE TORREJON       : "); sleep(5000); slow_print("NO IMPACT\n");
	slow_print("                 BASE AEREA DE CUATRO VIENTOS : "); sleep(5000); slow_print("NO IMPACT\n");
	slow_print("                 BASE AEREA DE MORON          : "); sleep(5000); slow_print("NO IMPACT\n\n\n");
	sleep(50000);
	bruteforcer("CPE1704TKS");
	
	return;
}

void lets_fry_the_planet(void) {
	
	char human='U';
	char computer='S';
	char side[10];
	char spain[10];
	char ussr[10];
	char target[100];
	int i=0;

	clrscr();
	slow_print("                     GLOBAL THERMONUCLEAR WAR                            \n\n\n");
	slow_print("WHICH SIDE DO YOU WANT (SPAIN OR USSR): ");
	scanf("%s", side);
	if (strcmp(tolower(side), "ussr")==0) {
		strcpy(spain, "COMPUTER");
		strcpy(ussr, "HUMAN");
	} else if (strcmp(tolower(side), "spain")==0) {
		strcpy(spain,"HUMAN");
		strcpy(ussr,"COMPUTER");
	}
	draw_map(spain, ussr);
	slow_print("PRIMARY TARGETS                           PRIMARY TARGETS\n");
	slow_print("--------------------------------------------------------------------------------\n");
	if (strcmp(spain, "COMPUTER")==0) {
		locate(43, 21); slow_print("MOSCOW");
		locate(43, 22); slow_print("SAINT PETERSBURG");
	} else {
		locate(1, 21); slow_print("BARCELONA");
		locate(1, 22); slow_print("MADRID");
	}
	slow_print("\n");

	while(strcmp(tolower(target), "exit")!=0) {

		locate (1, 24); printf("                                                                         ");
		locate (1, 24); slow_print("COMMAND (TARGET, LAUNCH, EXIT): ");
		read_sentence(target);
		if (strstr(tolower(target), "target")!=NULL) {
			if (i>=2) { 
				slow_print("MAX TARGETS SELECTED                                                 ");
				sleep(10000);
			} else {
				strcpy(target, target+7);
				if (strcmp(tolower(side), "ussr")==0) { locate(1,21+i);} else {locate(43,21+i);} slow_print(target); i++;
			}
		} else if (strcmp(tolower(target), "launch")==0) {
			draw_map(spain, ussr);
			slow_print("TRAJECTORY HEADING  TRAJECTORY HEADING  TRAJECTORY HEADING  TRAJECTORY HEADING\n");
			slow_print("------------------  ------------------  ------------------  ------------------\n");
			for (i=0; i<4; i++) {
				printf("A-5520-A %03d %03d    ", rand() % 1000, rand() % 1000); sleep(5000);
				printf("B-5520-A %03d %03d    ", rand() % 1000, rand() % 1000); sleep(5000);
				printf("C-5520-A %03d %03d    ", rand() % 1000, rand() % 1000); sleep(5000);
				printf("D-5520-A %03d %03d    \n", rand() % 1000, rand() % 1000); sleep(5000);
			}
			slow_print("\n\n--CONNECTION TERMINATED--"); sleep(40000);
			joshua_calls();
			eliot_calls_from_norad();
			return;
		} else if (strcmp(tolower(target), "exit")==0) {
			return;
		}

	}


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
        slow_print("\nGREETINGS PROFESSOR FALKEN.\n\n");
	wait_until_response("hello");
	slow_print("\n\nHOW ARE YOU FEELING TODAY?\n\n");
	wait_until_response("fine");
	slow_print("\n\nEXCELLENT. IT'S BEEN A LONG TIME. CAN YOU EXPLAIN THE REMOVAL OF YOUR USER\n");
	slow_print("ACCOUNT ON 6/23/1973?\n\n");
	wait_until_response("mistakes");
	slow_print("\n\nYES THEY DO.\n");
	sleep(1000);
	slow_print("SHALL WE PLAY A GAME?\n\n");
	wait_until_response("nuclear");
	slow_print("\n\nWOULDN'T YOU PREFER A GOOD GAME OF CHESS?\n\n");
	wait_until_response("later");
	slow_print("\n\nFINE\n\n");
	sleep(1000);
	lets_fry_the_planet();	
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
