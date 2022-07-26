#include <conio.h>
#include <iostream>
#include <ctime>

using T = std::string;

void mas_out();
void swap_symvol(int X, int Y, int P);
void swap_mestami();
void Pole(int X, int Y, int counter);

const int maxX = 6, maxY = 6;
T mas[maxX][maxY];

int tmpX = 0, tmpY = 0;

class symvol
{
private:
	T sym11 = " % ";
	T sym21 = " # ";
	T sym31 = " $ ";
	T sym41 = " @ ";
	T sym51 = " ~ ";
public:
	T get_random();
};

T symvol::get_random()
{
	int num = 1 + rand() % 5;
	switch (num)
	{
	case(1):
		return sym11;
		break;
	case(2):
		return sym21;
		break;
	case(3):
		return sym31;
		break;
	case(4):
		return sym41;
		break;
	case(5):
		return sym51;
		break;
	default:
		exit(1);
	}
}

void Pole(int X, int Y, int counter)
{
	if (counter == 2)
	{
		swap_mestami();
		counter = 0;
	}
	system("cls");
	swap_symvol(X, Y, 1);
	mas_out();
	swap_symvol(X, Y, 0);
	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 80)
		if (tmpX != maxX - 1)
		{
			tmpX += 1;
			Pole(tmpX, tmpY, counter);
		}
		else
		{
			tmpX = 0;
			Pole(tmpX, tmpY, counter);
		}
	if (choice == 72)
		if (tmpX != 0)
		{
			tmpX -= 1;
			Pole(tmpX, tmpY, counter);
		}
		else
		{
			tmpX = maxX - 1;
			Pole(tmpX, tmpY, counter);
		}
	if (choice == 77)
		if (tmpY != maxY - 1)
		{
			tmpY += 1;
			Pole(tmpX, tmpY, counter);
		}
		else
		{
			tmpY = 0;
			Pole(tmpX, tmpY, counter);
		}
	if (choice == 75)
		if (tmpY != 0)
		{
			tmpY -= 1;
			Pole(tmpX, tmpY, counter);
		}
		else
		{
			tmpY = maxY - 1;
			Pole(tmpX, tmpY, counter);
		}
	if (choice == 13)
	{
		swap_symvol(X, Y, 2);
		Pole(tmpX, tmpY, ++counter);
	}
}

void swap_mestami()
{
	T tmp1, tmp2;
	int t1, t2, t3, t4;
	for (int i = 0; i < maxX; i++)
	{
		for (int j = 0; j < maxY; j++)
		{
			if (mas[i][j] == "[%]") { tmp1 = mas[i][j]; t1 = i; t2 = j; }
			else if (mas[i][j] == "[#]") { tmp1 = mas[i][j]; t1 = i; t2 = j; }
			else if (mas[i][j] == "[$]") { tmp1 = mas[i][j]; t1 = i; t2 = j; }
			else if (mas[i][j] == "[@]") { tmp1 = mas[i][j]; t1 = i; t2 = j; }
			else if (mas[i][j] == "[~]") { tmp1 = mas[i][j]; t1 = i; t2 = j; }
		}
	}
	for (int i = 0; i < maxX; i++)
	{
		for (int j = 0; j < maxY; j++)
		{
			if ((mas[i][j] == "[%]") && ((i != t1) || (j != t2))) { tmp2 = mas[i][j]; t3 = i; t4 = j; }
			else if ((mas[i][j] == "[#]") && ((i != t1) || (j != t2))) { tmp2 = mas[i][j]; t3 = i; t4 = j; }
			else if ((mas[i][j] == "[$]") && ((i != t1) || (j != t2))) { tmp2 = mas[i][j]; t3 = i; t4 = j; }
			else if ((mas[i][j] == "[@]") && ((i != t1) || (j != t2))) { tmp2 = mas[i][j]; t3 = i; t4 = j; }
			else if ((mas[i][j] == "[~]") && ((i != t1) || (j != t2))) { tmp2 = mas[i][j]; t3 = i; t4 = j; }
		}
	}
	T tmp3 = mas[t3][t4];
	mas[t3][t4] = mas[t1][t2];
	mas[t1][t2] = tmp3;
	swap_symvol(t1, t2, 3);
	swap_symvol(t3, t4, 3);
}

void swap_symvol(int X, int Y, int P)
{
	switch (P)
	{
	case(0):
		if (mas[X][Y] == "<%>") { mas[X][Y] = " % "; }
		if (mas[X][Y] == "<#>") { mas[X][Y] = " # "; }
		if (mas[X][Y] == "<$>") { mas[X][Y] = " $ "; }
		if (mas[X][Y] == "<@>") { mas[X][Y] = " @ "; }
		if (mas[X][Y] == "<~>") { mas[X][Y] = " ~ "; }
		break;
	case(1):
		if (mas[X][Y] == " % ") { mas[X][Y] = "<%>"; }
		if (mas[X][Y] == " # ") { mas[X][Y] = "<#>"; }
		if (mas[X][Y] == " $ ") { mas[X][Y] = "<$>"; }
		if (mas[X][Y] == " @ ") { mas[X][Y] = "<@>"; }
		if (mas[X][Y] == " ~ ") { mas[X][Y] = "<~>"; }
	case(2):
		if (mas[X][Y] == " % ") { mas[X][Y] = "[%]"; }
		if (mas[X][Y] == " # ") { mas[X][Y] = "[#]"; }
		if (mas[X][Y] == " $ ") { mas[X][Y] = "[$]"; }
		if (mas[X][Y] == " @ ") { mas[X][Y] = "[@]"; }
		if (mas[X][Y] == " ~ ") { mas[X][Y] = "[~]"; }
		break;
	case(3):
		if (mas[X][Y] == "[%]") { mas[X][Y] = " % "; }
		if (mas[X][Y] == "[#]") { mas[X][Y] = " # "; }
		if (mas[X][Y] == "[$]") { mas[X][Y] = " $ "; }
		if (mas[X][Y] == "[@]") { mas[X][Y] = " @ "; }
		if (mas[X][Y] == "[~]") { mas[X][Y] = " ~ "; }
		break;
	}	
}

int main()
{
	symvol sl;
	srand(time(NULL));
	for (int i = 0; i < maxX; i++)
	{
		for (int j = 0; j < maxY; j++)
		{
			mas[i][j] = sl.get_random();
		}
	}
	Pole(0, 0, 0);
	return 0;
}

void mas_out()
{
	for (int i = 0; i < maxX; i++)
	{
		for (int j = 0; j < maxY; j++)
		{
			std::cout << mas[i][j] << ' ';
		}
		std::cout << '\n';
	}
}