#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define ScreenPos_x 180	/* X : Y = 2 : 1 */
#define ScreenPos_y 2
#define ScreenSize_x 180
#define ScreenSize_y 45

void SETTING();
	void SETTING_color();
	void SETTING_size();
	void SETTING_cursor();
	void SETTING_scrollbar();
	void SETTING_fullscreen();
void gotoxy(int x,int y);
void TEST_CMD_1();
	void T1();
	void T2();
	void T3();
	void T4();
	void T5();
		void P1(int i, int j);
		void P2(int i, int j, int cl);
		__inline void P3(int i, int cl);

void TEST_CMD_COLOR();

int main(void) {
	
	SETTING();
	
	TEST_CMD_1();
	
}

void SETTING(){	// Included all setting function
	SETTING_size();
	SETTING_cursor();
	SETTING_scrollbar();
	SETTING_CMD_POS();
}
	void SETTING_size(){
		system("mode con cols=80 lines=25"); 
	}
	void SETTING_cursor(){
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;                     // Cursor_think (1 ~ 100)
		cursorInfo.bVisible = FALSE;               // Cursor Visible TRUE or FALSE(Hide)
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	}
	void SETTING_scrollbar(){
		CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo; 
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);
  		COORD new_screen_buffer_size;
  		new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
    	new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;
  		SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);
	}
	void SETTING_CMD_POS(){
		HWND hWnd = GetConsoleWindow();
	    MoveWindow(hWnd,470,10,800,800,TRUE);
	}
	void SETTING_fullscreen(){
		HWND hWnd = GetConsoleWindow();
	    MoveWindow(hWnd,-6,0,1550,830,TRUE);
	}
void gotoxy(int x,int y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}


void TEST_CMD_1(){
	int getnum;
	int mainloop = 1;
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);

	while(mainloop){
		printf("= TEST_CMD_1 =\n");
		printf("0 : TEST_CMD_COLOR : \"test color-\"\n");
		printf("1 : T1             : \"Check Pattern\"\n");
		printf("2 : T2             : \"Rainbow Pattern\"\n");
		printf("3 : T3             : \"Rainbow Diamond Pattern\"\n");
		printf("4 : T4             : \"Rainbow Diamond Illusion\"\n");
		printf("5 : T5             : \"TV Setting Screen\"\n");
		printf("\n\nwhat chip?\n");
		
		scanf("%d", &getnum);
		system("cls");
		
		switch(getnum){
			case 0: TEST_CMD_COLOR();	break;
			case 1:	T1();	break;
			case 2: T2();	break;
			case 3: T3();	break;
			case 4: T4();	break;
			case 5: T5();	break;
			case 9: 
				system("cls");	
				mainloop--;
				break;
			default: exit(1);
		}
		SetConsoleTextAttribute(hC, 7);	
	}
} 
	void TEST_CMD_COLOR(){
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);
		printf("Default : %d\n", csbi.wAttributes);
		COLORREF a;
		int i;
		
		printf("\n\t= Literal =\n\n");
		printf("BACKGROUND_BLUE : %d\n", BACKGROUND_BLUE);
		printf("FOREGROUND_BLUE : %d\n", FOREGROUND_BLUE);
		printf("BACKGROUND_GREEN : %d\n", BACKGROUND_GREEN);
		printf("FOREGROUND_GREEN : %d\n", FOREGROUND_GREEN);
		printf("BACKGROUND_RED : %d\n", BACKGROUND_RED);
		printf("FOREGROUND_RED : %d\n", FOREGROUND_RED);
		printf("BACKGROUND_INTENSITY : %d\n", BACKGROUND_INTENSITY);
		printf("FOREGROUND_INTENSITY : %d\n", FOREGROUND_INTENSITY);	
		
		printf("\n      = Text Color =\n\n");
		for(i=0; i<16; i++){
			SetConsoleTextAttribute(hC, i);
			printf("\t%-3d\t", i);
			SetConsoleTextAttribute(hC, 7);
			printf("%d\n", i);
			
			//SetConsoleTextAttribute(hC, i|FOREGROUND_INTENSITY);
			//printf("\t%-3d\t", i);
			//SetConsoleTextAttribute(hC, 7);
			//printf("%d Intensity\n", i);
		}
		
		printf("\n   = Background Color =\n\n");
		for(i=0; i<256; i+=16){
			SetConsoleTextAttribute(hC, i);
			printf("\t%-3d\t", i);
			SetConsoleTextAttribute(hC, 7);
			printf("%d\n", i);
			
			//SetConsoleTextAttribute(hC, i|FOREGROUND_INTENSITY);
			//printf("\t%-3d\t", i);
			//SetConsoleTextAttribute(hC, 7);
			//printf("%d Intensity\n", i);
		}
	}
	void T1(){
		int i, j;
		int div = 0;
		int c1 = 0;
		int c2 = 240;
		
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);
		COLORREF a;
		
		// check pattern
		for(i=0; i<10; i++){
			if(div != 1)	div++;
			else 			div--;
			for(j=0; j<5; j++){
				if(div != 1){
					SetConsoleTextAttribute(hC, c1);
					printf("    ");
					SetConsoleTextAttribute(hC, c2);
					printf("    ");
				}else {
					SetConsoleTextAttribute(hC, c2);
					printf("    ");
					SetConsoleTextAttribute(hC, c1);
					printf("    ");
				}
			}
			SetConsoleTextAttribute(hC, 7);	
			printf("\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	void T2(){
		int i, j, a = 0, b = 16;
		int div = 0;
		
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);
		
		for(i=0; i<16; i++){
			for(j=0; j<256; j+=16){
				a = j;
				a += (i * 16);
				if(a > 256){
					a -= 256;
				}
				SetConsoleTextAttribute(hC, a);
				printf("  ");
			}
			printf("\n");
		}	
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	void T3(){
		int i, j, a = 0, b = 16;
		int div = 0;
		
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);
		
		for(i=0; i<16; i++){
			for(j=0; j<256; j+=16)	P1(i, j);
			for(j=256; j>=0; j-=16)	P1(i, j);
			SetConsoleTextAttribute(hC, 7);	
			printf("\n");
		}
		for(i=16; i>=0; i--){
			for(j=0; j<256; j+=16)	P1(i, j);
			for(j=256; j>=0; j-=16)	P1(i, j);
			SetConsoleTextAttribute(hC, 7);	
			printf("\n");
		}
		printf("\n\n");
	}
	void T4(){
		int i, j, a = 0, b = 16;
		int div = 0;
		int mainloop = 3;
		int cl;
		
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);
		
		system("cls");
		
		while(mainloop){
			for(cl=0; cl<256; cl+=16){
				gotoxy(0, 0);
				for(i=0; i<16; i++)		P3(i, cl);
				for(i=16; i>=0; i--)	P3(i, cl);
				Sleep(20);
			}
			mainloop--;
		}
		printf("\n\n");
	}
	void T5(){
		int i, j;
		int frame_pos_v = 4;
		int frame_pos_h = 6 * 2;
		int frame_v = 40;
		int frame_h = 83 * 2;
		int line;
		int line_h = 7;
		
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);
		
		system("cls");
		SETTING_fullscreen();
		
		line = (frame_v / 5) * 3;
		
		gotoxy(frame_pos_h, frame_pos_v);
		SetConsoleTextAttribute(hC, 240);	
		for(i=0; i<frame_h; i+=2){
			gotoxy(frame_pos_h + i, frame_pos_v);
			printf("  ");
			gotoxy(frame_pos_h + i, frame_pos_v + frame_v);
			printf("  ");
		}
		for(i=0; i<=frame_v; i++){
			gotoxy(frame_pos_h, frame_pos_v + i);
			printf("  ");
			gotoxy(frame_pos_h + frame_h, frame_pos_v + i);
			printf("  ");
		}
		SetConsoleTextAttribute(hC, 7);
		
		P4(240, line, frame_pos_h+line_h+(22*0), frame_pos_v+3);
		P4(224, line, frame_pos_h+line_h+(22*1), frame_pos_v+3);
		P4(176, line, frame_pos_h+line_h+(22*2), frame_pos_v+3);
		P4(160, line, frame_pos_h+line_h+(22*3), frame_pos_v+3);
		P4(208, line, frame_pos_h+line_h+(22*4), frame_pos_v+3);
		P4(64 , line, frame_pos_h+line_h+(22*5), frame_pos_v+3);
		P4(16 , line, frame_pos_h+line_h+(22*6), frame_pos_v+3);
		P5(16 , line/5, frame_pos_h+line_h+(22*0), frame_pos_v+line+3);
		P5(208, line/5, frame_pos_h+line_h+(22*2), frame_pos_v+line+3);
		P5(176, line/5, frame_pos_h+line_h+(22*4), frame_pos_v+line+3);
		P5(240, line/5, frame_pos_h+line_h+(22*6), frame_pos_v+line+3);
		SetConsoleTextAttribute(hC, 7);
		
		Sleep(3000);
		system("cls");
		gotoxy(0,0);
		SETTING();
	}	
		void P1(int i, int j){
			HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(hC, &csbi);
			int a = (i * 16) + j;
			if(a > 256)	a -= 256;
			SetConsoleTextAttribute(hC, a);
			printf("  ");
		}
		void P2(int i, int j, int cl){
			HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(hC, &csbi);
			int a = (i * 16) + j;
			if(a > 256)	a -= 256;
			SetConsoleTextAttribute(hC, a + cl);
			printf("  ");
		}
		__inline void P3(int i, int cl){
			// https://modoocode.com/99
  			HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(hC, &csbi);
			int a, j;
			
			for(j=0; j<256; j+=16){
				a = (i * 16) + j;
				if(a > 256)	a -= 256;
				SetConsoleTextAttribute(hC, a + cl);
				printf(" ");
			}
			for(j=256; j>=0; j-=16){
				a = (i * 16) + j;
				if(a > 256)	a -= 256;
				SetConsoleTextAttribute(hC, a + cl);
				printf("  ");
			}
			SetConsoleTextAttribute(hC, 7);	
			printf("\n");
		}
		__inline void P4(int cl, int line, int x, int y){
			int i;
			HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(hC, &csbi);
			SetConsoleTextAttribute(hC, cl);
			for(i=0; i<line; i++){
				gotoxy(x, y+i);
				printf("                      ");
			}
		}
		__inline void P5(int cl, int line, int x, int y){
			int i;
			HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(hC, &csbi);
			SetConsoleTextAttribute(hC, cl);
			for(i=0; i<line; i++){
				gotoxy(x, y+i);
				printf("                      ");
			}
		}

		
	


	

	
	
