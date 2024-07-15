#include <iostream>
#include <conio.h>
using namespace std;
void CoutMatToScreen(char X[][200], int rstart, int rend, int cstart, int cend)
{
	system("cls");
	for (int r = rstart; r < rend; r++)
	{
		for (int c = cstart; c < cend; c++)
		{
			cout << X[r][c];
		}
	}
}
void scrolling(int rHero, int cHero, int& rstart, int& rend, int& cstart, int& cend)
{
	if (rHero + 12 < 50 || rHero - 12 > 50)
	{
		rstart = rHero - 12;
		rend = rHero + 12;
	}

	if (rHero + 12 > 50)
	{
		rstart = 50 - 24;
		rend = 50;
	}
	if (rHero - 12 < 0)
	{
		rstart = 0;
		rend = 24;
	}
	if (cHero + 40 < 200 || cHero - 40 > 0)
	{
		cstart = cHero - 40;
		cend = cHero + 40;
	}
	if (cHero + 40 > 200)
	{
		cstart = 200 - 80;
		cend = 200;
	}
	if (cHero - 40 < 0)
	{
		cstart = 0;
		cend = 80;
	}
}
void ClearAndDrawFixedObject(char X[][200])
{
	int r, c;
	for (r = 0; r < 50; r++)
	{
		for (c = 0; c < 200; c++)
		{
			X[r][c] = ' ';
		}
	}
	for (r = 1; r < 49; r++)
	{
		X[r][0] = 186;
	}
	for (r = 1; r < 49; r++)
	{
		X[r][199] = 186;
	}
	for (c = 1; c < 199; c++)
	{
		X[0][c] = 205;
	}
	for (c = 1; c < 199; c++)
	{
		X[49][c] = 205;
	}
	for (c = 36; c < 57; c++)
	{
		X[35][c] = 205;
	}
	for (c = 2; c < 14; c++)
	{
		X[35][c] = 205;
	}
	for (c = 8; c < 135; c++)
	{
		X[23][c] = 205;
	}
	//lazer dispancer
	X[33][120] = 92;
	X[33][121] = 219;
	X[33][122] = '/';
	//ladder1
	X[35][50] = 202;
	X[34][50] = 201;
	X[34][51] = 205;
	X[34][52] = 205;
	X[34][53] = 188;
	X[33][50+3] = 201;
	X[33][51 + 3] = 205;
	X[33][52+3] = 205;
	X[33][53+3] = 188;
	X[32][53 + 3] = 201;
	X[32][54 + 3] = 205;
	X[32][55 + 3] = 205;
	//ladder2
	for (r = 34; r >22 ; r--)
	{
		X[r][7] = '|';
	}
	for (r = 34; r > 22; r--)
	{
		X[r][12] = '|';
	}
	for (r = 34; r >22 ; r--)
	{
		for (c = 11; c > 7; c--)
		{
			X[r][c] = '-';
		}
	}
	for (c = 59; c < 200; c++)
	{
		X[32][c] = 205;
	}
	//ladder3
	X[23][120] = 202;
	X[23-1][120] = 201;
	X[23-1][121] = 205;
	X[23-1][122] = 205;
	X[23-1][123] = 188;
	X[23-2][120 + 3] = 201;
	X[23-2][121 + 3] = 205;
	X[23-2][122 + 3] = 205;
	X[23-2][123 + 3] = 188;
	X[23-3][123 + 3] = 201;
	X[23-3][124 + 3] = 205;
	X[23-3][125 + 3] = 205;
	for (c = 128; c < 200; c++)
	{
		X[20][c] = 205;
	}
	//tele1
	for (r = 48; r > 44; r--) 
	{
		X[r][160] = 179;
	}
	X[49][160] = 202;
	X[44][160] = 201;
	for (c = 161; c < 169; c++)
	{
		X[44][c] = 196;
	}
	X[44][169] = 187;
	for (r = 48; r > 44; r--)
	{
		X[r][169] = 179;
	}
	X[49][169] = 202;
	for (c = 161; c < 169; c++)
	{
		for (r = 48; r > 44; r--)
		{
			X[r][c] = 176;
		}
	}
	//teleportal 2
	for (r = 31; r > 27; r--) 
	{
		X[r][150] = 179;
	}
	X[32][150] = 202;
	X[27][150] = 201;
	for (c = 151; c < 160; c++)
	{
		X[27][c] = 196;
	}
	X[27][160] = 187;
	for (r = 31; r > 27; r--)
	{
		X[r][160] = 179;
	}
	X[32][160] = 202;
	for (c = 151; c < 160; c++)
	{
		for (r = 31; r > 27; r--)
		{
			X[r][c] = 176;
		}
	}
	//endportal
	for (r = 19; r > 15; r--)
	{
		X[r][150] = 179;
	}
	X[20][150] = 202;
	X[15][150] = 201;
	for (c = 151; c < 160; c++)
	{
		X[15][c] = 196;
	}
	X[15][160] = 187;
	for (r = 19; r > 15; r--)
	{
		X[r][160] = 179;
	}
	X[20][160] = 202;
}
void drawlazer(char X[][200],int ct)
{
	if (ct < 5)
	{
		for (int r = 34; r < 49; r++)
		{
			X[r][121] = 232;
		}
	}
	else
	{
		for (int r = 34; r < 49; r++)
		{
			X[r][121] = ' ';
		}
	}

}
void damageEnemy1(int& rHero, int& cHero,  int& lives, int rstart, int rend, int cstart, int cend, int cenemy)
{
	if (rHero == 28 && (cHero + 1 == cenemy || cHero == cenemy))
	{
		lives--;
		cHero = 40;
		rHero = 28;
		scrolling(rHero, cHero, rstart, rend, cstart, cend);
	}
}
void DrawEnemy1(char x[][200], int renemy, int cenemy)
{
	x[renemy][cenemy] = 196;
	x[renemy+2][cenemy ] = '0';
	x[renemy + 1][cenemy - 1] = '(';
	x[renemy + 1][cenemy + 1] = ')';
	x[renemy+1][cenemy-2]=92;
	x[renemy + 2][cenemy - 3] = 196;
	x[renemy + 2][cenemy + 3] = 196;
	x[renemy + 2][cenemy - 1] = '(';
	x[renemy + 2][cenemy + 1] = ')';
	x[renemy + 1][cenemy +2] = '/';
}
void MoveEnemy1(int& renemy, int& cenemy, int rHero, int cHero)
{
	if (((cHero - cenemy) <= 35 && (cHero - cenemy) > 0) && rHero == renemy)
	{
		cenemy++;
	}
	if (((cenemy - cHero) <= 35 && (cenemy - cHero) > 0) && rHero == renemy)
	{
		cenemy--;
	}
}
void KillEnemy(char X[][200], int& rEnemy, int& cEnemy, int& isdead)
{
	if ((unsigned char)X[rEnemy+2][cEnemy-4]==241|| (unsigned char)X[rEnemy + 2][cEnemy - 5] == 241|| (unsigned char)X[rEnemy + 2][cEnemy - 6] == 241)
	{
		isdead++;
	}
	if ((unsigned char)X[rEnemy+2][cEnemy-4]==247|| (unsigned char)X[rEnemy + 2][cEnemy - 5] == 247|| (unsigned char)X[rEnemy + 2][cEnemy - 6] == 247)
	{
		isdead+=2;
	}
}
void MoveEnemy2(int& renemy, int& cenemy, int rHero, int cHero,int &flag)
{
	if (((cHero - cenemy) <= 45 && (cHero - cenemy) > 0) && rHero == 19)
	{
		cenemy++;
		//flag = 1;
	}
	if (((cenemy - cHero) <= 45 && (cenemy - cHero) > 0) && rHero == 19)
	{
		cenemy--;
		//flag = 1;
	}
}
void DrawBulletEnemy(int flag,int& rbullet,int& cbullet,char x[][200],int move,int c,int r)
{
	if (move==1)
	{
		rbullet++;
		x[rbullet][cbullet] = 233;
		if (x[rbullet +3][cbullet] != ' ' && rbullet>= 23 )
		{
			
			move = 0;
			x[rbullet][cbullet] = ' ';
			cbullet = c - 4;
			rbullet = r + 2;
		}
	}
}
void BulletEnemy(int c,int r,int & cBullet,int & rBullet, int f,int & move )
{
	if ( move == 0)
	{
		move = 1;
		cBullet = c - 4;
		rBullet = r + 2;
	}
}
void DrawEnemy2(int rWhitch, int cWhitch, char X[][200])
{
	X[rWhitch][cWhitch] = '/';
	X[rWhitch][cWhitch + 1] = '\\';
	X[rWhitch][cWhitch - 1] = '_';
	X[rWhitch][cWhitch + 2] = '_';
	X[rWhitch + 1][cWhitch + 3] = '\\';
	X[rWhitch + 1][cWhitch + 4] = '\\';
	X[rWhitch + 1][cWhitch + 5] = '\\';
	X[rWhitch + 1][cWhitch - 2] = '/';
	X[rWhitch + 1][cWhitch - 3] = '/';
	X[rWhitch + 1][cWhitch - 1] = '`';
	X[rWhitch + 1][cWhitch + 1] = '`';
	X[rWhitch + 1][cWhitch] = '<';
	X[rWhitch + 1][cWhitch + 2] = '.';
	X[rWhitch + 2][cWhitch - 4] = '-';
	X[rWhitch + 2][cWhitch - 3] = '-';
	X[rWhitch + 2][cWhitch - 2] = '-';
	X[rWhitch + 2][cWhitch - 1] = '(';
	X[rWhitch + 2][cWhitch] = '_';
	X[rWhitch + 2][cWhitch + 1] = '_';
	X[rWhitch + 2][cWhitch + 2] = '_';
	X[rWhitch + 2][cWhitch + 3] = ')';
	X[rWhitch + 2][cWhitch + 4] = '-';
	X[rWhitch + 2][cWhitch + 5] = '-';
	X[rWhitch + 2][cWhitch + 6] = '<';
	X[rWhitch + 3][cWhitch + 1] = 'J';
	X[rWhitch + 3][cWhitch + 2] = 'J';
}
void KillEnemy2(char X[][200], int rEnemy, int cEnemy, int & isdead,int rBullet,int cBullet)
{
	if (rEnemy +4 == rBullet)
	{
		if (cEnemy + 3 == cBullet || cEnemy + 2 == cBullet || cEnemy + 4 == cBullet||cEnemy - 3 == cBullet || cEnemy - 2 == cBullet || cEnemy - 4 == cBullet||cEnemy == cBullet || cEnemy + 5 == cBullet || cEnemy - 5 == cBullet||cEnemy - 3 == cBullet || cEnemy - 2 == cBullet || cEnemy - 1 == cBullet)
		{
			isdead++;
		}
	}
}
void key(char X[][200],int r,int c,int & k)
{
	if (k == 0)
	{
		X[30][190] = 128;
	}
	if (r == 28 && c == 190||c==189||c==191)
	{
		X[30][190] = ' ';
		k = 1;
	}
}
void Teleport1(int& c, int& r, int& flag)
{
	if (c > 161 && c < 169)
	{
		if (r == 45)
		{
			c = 153;
			r = 28;
			flag = 1;
		}
	}
}
void teleport2(int& c, int& r,int d)
{
	if (d == 'o')
	{
		if (c > 151 && c < 159)
		{
			if (r == 28)
			{
				c = 167;
				r = 45;
			}
		}
	}
	if (d == 'p')
	{
		if (c > 151 && c < 159)
		{
			if (r == 28)
			{
				c = 10;
				r = 31;
			}
		}
	}
}
void shootsingle(int& cBullet, int& rBullet, int dirHero, char X[][200], int cHero, int rHero, int& move)
{
	if (dirHero == -1)
	{
		cBullet = cHero - 4;
		rBullet = rHero + 2;
	}
	if (dirHero == 1)
	{
		cBullet = cHero + 4;
		rBullet = rHero + 2;
	}
}
void DrawBulletside(int& cbullet, int& rbullet, char x[][200], int dir,int& move)
{
		if (dir == -1)
		{
			cbullet -= 2;
		}
		else
		{
			cbullet += 2;
		}
		x[rbullet][cbullet] = 241;
		if (x[rbullet][cbullet + 2] != ' '|| x[rbullet][cbullet - 2] != ' ')
		{
			x[rbullet][cbullet] = ' ';
			move = 0;
			
		}
		if (cbullet <= 0 || cbullet >= 200)
		{
			x[rbullet][cbullet] = ' ';
			move = 0;
		}
		
	
}
void DrawbulletUp(int& cbullet, int& rbullet, char x[][200], int dir,int &move)
{
		rbullet --;
		x[rbullet][cbullet] = 241;
		if (x[rbullet-1][cbullet] != ' '|| rbullet <= 0)
		{
			x[rbullet][cbullet] = ' ';
			move = 0;
		}
}
void drawMB(int c[], int r[], char x[][200], int a, int& zoed, int& move)
{
	move = 1;
	for (int i = 0; i < a; i++)
	{
		if (x[r[0]][c[i]] != ' ' && x[r[1]][c[i]] != ' ')
		{
			move = 0;
			for (int j = 0; j < a; j++)
			{
				x[r[0]][c[j]] = ' ';
				x[r[1]][c[j]] = ' ';
			}
			break;
		}
	}
	if (move == 1)
	{
		for (int i = 0; i < a; i++)
		{
			x[r[0]][c[i]] = 247;
			x[r[1]][c[i]] = 247;
		}
	}
}
void shootMB(int dirHero, int cHero, int rHero, char x[][200], int c[], int r[], int& a)
{
	a = 0;
	if (dirHero == -1)
	{
		for (int i = cHero - 4; x[rHero + 2][i] == ' ' && i > 0; i -= 2)
		{
			c[a] = i;
			a++;
		}
		r[0] = rHero +1;
		r[1] = rHero+2 ;
	}
	if (dirHero == 1)
	{
		for (int i = cHero + 4; x[rHero + 2][i] == ' ' && i < 199; i += 2)
		{
			c[a] = i;
			a++;
		}
		r[0] = rHero + 1;
		r[1] = rHero+2;
	}
}
void MoveHero(int& rHero, int& cHero, char UserDes, char X[][200], int& dirHero)
{
	if (UserDes == 's')
	{
			if (X[rHero + 4][cHero] == '-')
			{
				rHero++;
			}	
	}
	if (UserDes == 'a')
	{
		if ((unsigned char)(X[rHero][cHero - 2]) != 186 && (X[rHero + 1][cHero - 2]) != 186 && (X[rHero + 2][cHero - 2]) != 186 && (X[rHero + 3][cHero - 2]) != 186)
		{
			cHero -= 2;
		}
		dirHero = -1;
	}
	if (UserDes == 'd')
	{
		if ((unsigned char)(X[rHero][cHero + 2]) != 186 && (X[rHero + 1][cHero + 2]) != 186 && (X[rHero + 2][cHero + 2]) != 186 && (X[rHero + 3][cHero + 2]) != 186)
		{
			cHero += 2;
		}
		dirHero = 1;

	}
}
void DrawHero(int rHero, int cHero, char X[][200])
{
	X[rHero][cHero] = 196;
	X[rHero][cHero+1] = 196;
	X[rHero][cHero-1] = 196;
	X[rHero+3][cHero] = 196;
	X[rHero+3][cHero + 1] = 196;
	X[rHero+3][cHero - 1] = 196;
	X[rHero][cHero+2] = 191;
	X[rHero][cHero-2] = 218;
	X[rHero + 1][cHero - 2] = 177;
	X[rHero + 1][cHero + 2] = 179;
	X[rHero + 2][cHero + 2] = 179;
	X[rHero + 1][cHero - 2] = 179;
	X[rHero + 2][cHero - 2] = 179;
	X[rHero + 3][cHero - 2] = 192;
	X[rHero + 3][cHero +2] = 217;
	X[rHero + 1][cHero + 1] = 233;
	X[rHero + 1][cHero - 1] = 233;
	X[rHero + 2][cHero] = 167;
	X[rHero + 2][cHero - 3] = '/';
	X[rHero + 2][cHero + 3] = '\\';
	X[rHero + 3][cHero - 1] = 220;
	X[rHero + 3][cHero + 1] = 220;
}
void DrawElevator(int relevator,int celevator, char X[][200],int flag)
{
		X[relevator][celevator] = 196;
		X[relevator][celevator+1] = 196;
		X[relevator ][celevator + 2] = 196;
		X[relevator ][celevator + 3] = 196;
		X[relevator][celevator-1] = 218;
		X[relevator][celevator+4] = 191;
		X[relevator + 1][celevator] = 196;
		X[relevator + 1][celevator+1] = 196;
		X[relevator + 1][celevator+2] = 196;
		X[relevator + 1][celevator + 3] = 196;
		X[relevator + 1][celevator-1] = 192;
		X[relevator + 1][celevator+4] = 217;
}
void MoveElevatorup(int& relevator, int& rHero, int& cHero,int & celevator,int&flag,int & move,int&down)
{	
	if (flag == 0)
	{
		if ((cHero == 15 || cHero == 16 || cHero == 17 || cHero == 18) && relevator > 35)
		{
			relevator--;
			rHero--;
			move = 1;
		}
		if (relevator == 35 && cHero < 35&&cHero>13)
		{
			celevator++;
			cHero++;
			move = 1;
		}
		if (cHero == 35)
		{
			move = 0;
		}
		if (cHero >= 35 && rHero == 32)
		{
			flag = 1;
		}
	}
}
void MoveElevatorDown( int& relev, int &celevator,int &c,int&flag)
{
	if (celevator == 32 && relev == 35 )
	{
		if (c>=37)
		{
			relev = 48;
			celevator = 15;
			flag = 0;
		}
	}
}
void Gravity(char x[][200], int& rhero, int chero)
{
	if (x[rhero + 4][chero] == ' ')
	{
		rhero++;
		
	}
}
void jump(int& rHero, int& cHero, char UserDes,int dirHero, char X[][200],int& ct)
{
		if (UserDes == 'w')
		{
			rHero -= 3;
		}
		if (UserDes == 'e')
		{
			if ((unsigned char)(X[rHero][cHero + 3]) != 186 && (X[rHero + 1][cHero + 3]) != 186 && (X[rHero + 2][cHero + 3]) != 186 && (X[rHero + 3][cHero + 3]) != 186)
			{
				//if (ctjump == 4)
				//{
				cHero += 3;
				rHero -= 3;
				dirHero = 1;
			}
		}
		if (cHero >200)
		{
			cHero = 197;
		}
		if (UserDes == 'q')
		{

			if ((unsigned char)(X[rHero][cHero - 3]) != 186 && (X[rHero + 1][cHero - 3]) != 186 && (X[rHero + 2][cHero - 3]) != 186 && (X[rHero + 3][cHero - 3]) != 186)
			{
				
				cHero -= 3;
				rHero -= 3;
				dirHero = -1;
				
			}
		}
		if (cHero < 0)
		{
			cHero = 3;
		}
}
void MainMenu(char X[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			X[r][c] = ' ';
		}
	}
	//wellcome
	int c = 30;
	X[3][c] = 'C';
	X[3][++c] = 'A';
	X[3][++c] = 'N';
	X[3][++c] = ' ';
	X[3][++c] = 'Y';
	X[3][++c] = 'O';
	X[3][++c] = 'U';
	X[3][++c] = ' ';
	X[3][++c] = 'H';
	X[3][++c] = 'E';
	X[3][++c] = 'L';
	X[3][++c] = 'P';
	X[3][++c] = ' ';
	X[3][++c] = 'B';
	X[3][++c] = 'L';
	X[3][++c] = 'O';
	X[3][++c] = 'B';
	X[3][++c] = '!';
	X[3][++c] = '?';
	//press s to start
	c = 32;
	X[20][c] = 'p';
	X[20][++c] = 'r';
	X[20][++c] = 'e';
	X[20][++c] = 's';
	X[20][++c] = 's';
	X[20][++c] = ' ';
	X[20][++c] = 's';
	X[20][++c] = 'p';
	X[20][++c] = 'a';
	X[20][++c] = 'c';
	X[20][++c] = 'e';
	X[20][++c] = ' ';
	X[20][++c] = 't';
	X[20][++c] = 'o';
	X[20][++c] = ' ';
	X[20][++c] = 't';
	X[20][++c] = 'r';
	X[20][++c] = 'y';
	//charcter 1
	int rHero = 10, cHero = 40;
	X[rHero][cHero] = 196;
	X[rHero][cHero + 1] = 196;
	X[rHero][cHero - 1] = 196;
	X[rHero + 3][cHero] = 196;
	X[rHero + 3][cHero + 1] = 196;
	X[rHero + 3][cHero - 1] = 196;
	X[rHero][cHero + 2] = 191;
	X[rHero][cHero - 2] = 218;
	X[rHero + 1][cHero - 2] = 177;
	X[rHero + 1][cHero + 2] = 179;
	X[rHero + 2][cHero + 2] = 179;
	X[rHero + 1][cHero - 2] = 179;
	X[rHero + 2][cHero - 2] = 179;
	X[rHero + 3][cHero - 2] = 192;
	X[rHero + 3][cHero + 2] = 217;
	X[rHero + 1][cHero + 1] = 233;
	X[rHero + 1][cHero - 1] = 233;
	X[rHero + 2][cHero] = 167;
	X[rHero + 2][cHero - 3] = '/';
	X[rHero + 2][cHero + 3] = '\\';
	X[rHero + 3][cHero - 1] = 220;
	X[rHero + 3][cHero + 1] = 220;
}
void CoutMenuToScreen(char X[][80])
{
	system("cls");
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			cout << X[r][c];
		}
	}
}
void GameOverwin(char y[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			y[r][c] = ' ';
		}
	}
	y[12][36] = 'Y';
	y[12][37] = 'o';
	y[12][38] = 'u';
	y[12][39] = ' ';
	y[12][41] = 'W';
	y[12][42] = 'o';
	y[12][43] = 'n';
	y[12][44] = ' ';
	y[12][45] = '!';
	y[14][40] = 'G';
	y[14][41] = 'G';
}
void coutgameover(char y[][80])
{
	system("cls");
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			cout << y[r][c];
		}
	}
}
void GameOver(char y[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			y[r][c] = ' ';
		}
	}
	y[12][36] = 'G';
	y[12][37] = 'a';
	y[12][38] = 'm';
	y[12][39] = 'e';
	y[12][40] = ' ';
	y[12][41] = 'O';
	y[12][42] = 'v';
	y[12][43] = 'e';
	y[12][44] = 'r';
	y[12][45] = '!';
	y[14][40] = 'G';
	y[14][41] = 'G';
}
void detectwin(int rHero, int cHero, int& win)
{
	if (cHero == 151 || cHero == 152 || cHero == 153 || cHero == 154 || cHero == 155 || cHero == 166 || cHero == 157 || cHero == 158|| cHero == 159)
	{
		if (rHero == 16)
		{
			win = 1;
		}
	}
}
void detectlose(char x[][200],int &rhero,int &chero,int & lives,int rbullet,int cbullet)
{
	if (rhero - 1 == rbullet)
	{
		if (chero == cbullet || chero + 1 == cbullet || chero + 2 == cbullet || chero + 3 == cbullet || chero - 1 == cbullet || chero - 2 == cbullet || chero - 3 == cbullet)
		{
			lives --;
			chero = 10;
			rhero = 31;
		}
	}
	if ((unsigned char)x[rhero - 1][chero] == 232 || (unsigned char)x[rhero - 1][chero + 1] == 232 || (unsigned char)x[rhero - 1][chero + 1] == 232)
	{
		lives = 0;
	}
}
void main()
{
	char Map[50][200];
	char menu[24][80];
	int lazer[15];
	int cMultipleB[200];
	int rMultipleB[2];
	int lastpos = 0;
	char uMove=NULL;
	int ctdouble = 0;
	int rHero, cHero,dirHero;
	int rstart, rend, cstart, cend,flagjump,move;
	int cBullet, rBullet, fb,win,fdir,relevator,celevator,fk,dead=0;
	int ele = 0;
	int d = 0;
	int no_move = 0;
	int lives, renemy, cenemy, enemy1dead, rlazer, clazer, t, fMB = 0;
	rlazer = 10;
	clazer = 50;
	char telespecial;
	int m = 0;
	int w=0;
	char End[24][80];
	int more = 1;
	int  dirb;
	int isdead = 0;
	int rWhich, cWhich;
	rWhich = 10;
	cWhich = 65;
	enemy1dead = 0;
	renemy = 28;
	cenemy = 120;
	dirHero = 1;
	fk = 0;
	fdir = -1;
	flagjump = 0;
	cstart = 0;
	cend = 80;
	rstart = 26;
	rend = 50;
	rHero = 43; cHero = 45;
	relevator = 48;
	celevator = 15;
	lives = 3;
	int ct = 0;
	int e = 0;
	int moB = 0;
	int rbEnemy = 0;
	int cbEnemy = 0;
	int kill = 0;
	cBullet = 0;
	rBullet = 0;
	for (;;ct++)
	{
		MainMenu(menu);
		CoutMenuToScreen(menu);
		uMove = _getch();
			if (uMove == ' ')
			{
				break;
			}
	}
	for (;;ct++)
	{
		for (; !_kbhit();)
		{
			ClearAndDrawFixedObject(Map);
			DrawElevator(relevator,celevator, Map,ele);
			MoveElevatorup(relevator, rHero, cHero, celevator, ele, no_move, d);
			MoveElevatorDown( relevator, celevator,cHero,ele);
			if (isdead < 2)
			{
				
				DrawEnemy2(rWhich, cWhich, Map);
				MoveEnemy2(rWhich, cWhich, rHero, cHero,e);
				KillEnemy2(Map, rWhich, cWhich,isdead,rBullet,cBullet);
				if (rHero == 19)
				{
					DrawBulletEnemy(e, rbEnemy, cbEnemy, Map, moB,cWhich,rWhich);
					BulletEnemy(cWhich, rWhich, cbEnemy, rbEnemy, e, moB);
				}
			}
			else
			{
				kill = 1;
			}
			drawlazer(Map,ct);
			if (ct == 8)
			{
				ct = 0;
			}
			if (dead == 1)
			{
				key(Map, rHero, cHero, fk);
			}
			if (fMB == 1)
			{
				drawMB(cMultipleB, rMultipleB, Map, lastpos, more, fMB);
			}
			DrawHero(rHero, cHero, Map);
			if (fdir == 0 && m==1)
			{
				DrawBulletside(cBullet, rBullet, Map, dirHero,m);
			}
			if (fdir ==1 && m==1)
			{
				DrawbulletUp(cBullet, rBullet, Map, dirHero,m);
			}
			if (enemy1dead <2)
			{
				DrawEnemy1(Map, renemy, cenemy);
				damageEnemy1(rHero, cHero, lives, rstart, rend, cstart, cend, cenemy);
				MoveEnemy1(renemy, cenemy, rHero, cHero);
			}
			else
			{
				dead = 1;
			}
			detectlose(Map, rHero, cHero, lives, rbEnemy, cbEnemy);
			KillEnemy(Map, renemy, cenemy, enemy1dead);
			Gravity(Map, rHero, cHero);
			scrolling(rHero, cHero, rstart, rend, cstart, cend);
			detectwin(rHero, cHero, w);
			CoutMatToScreen(Map,rstart,rend,cstart,cend);
		}
		uMove = _getch();
		if ( no_move!= 1)
		{
			MoveHero(rHero, cHero, uMove, Map, dirHero);
		}
		DrawHero(rHero, cHero, Map);
		MoveElevatorDown(relevator, celevator, cHero, ele);
		if (cHero > 35 && rHero == 35)
		{
			ele = 1;
		}
		Gravity(Map, rHero, cHero);
		if (uMove == 'f')
		{
			shootsingle(cBullet, rBullet, dirHero, Map, cHero, rHero, fb);
			fdir = 0;
			m = 1;
		}
		if (uMove == 'b')
		{
			shootsingle(cBullet, rBullet, dirHero, Map, cHero, rHero, fb);
			fdir = 1;
			m = 1;
		}
		if (Map[rHero + 4][cHero] != ' '&&no_move!=1)
		{
			jump(rHero, cHero, uMove, dirHero, Map, ctdouble);
		}
		scrolling(rHero, cHero, rstart, rend, cstart, cend);
		if (uMove == 't')
		{
			t = 0;
			Teleport1(cHero, rHero, t);
			if (t == 0)
			{
				telespecial = _getch();
				teleport2(cHero, rHero,telespecial);
			}
		}
		if (uMove == 'x')
		{
				shootMB(dirHero, cHero, rHero, Map, cMultipleB, rMultipleB, lastpos);
				fMB = 1;
		}
		detectwin(rHero, cHero, w);
		detectlose(Map, rHero, cHero, lives,rbEnemy,cbEnemy);
		if (fk == 1 && w == 1 && kill==1)
		{
			win = 1;
			break;
		}
		if (lives == 0)
		{
			win = 0;
			break;
		}
	}
	
	if (win == 0)
	{
		for (;;)
		{
			GameOver(End);
			coutgameover(End);
		}
	}
	if (win == 1)
	{
		for (;;)
		{
			GameOverwin(End);
			coutgameover(End);
		}
	}
}