#include <conio.h>
#include <iostream>
#include <ctime>

using T = std::string;

void mas_out();
void swap_symvol(int X, int Y, int P);
void swap_mestami();
void Pole(int X, int Y, int counter);
void find_range();
void delete_symvol(int start, int end, int layer, bool key);

const int maxX = 5, maxY = 5;
T mas[maxX][maxY];

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
// �������� ��������� �������
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
// ���� � ������������ ������
{
	if (counter == 2)
	{
		swap_mestami();
		counter = 0;
	}
	system("cls");
	swap_symvol(X, Y, 1);
	mas_out();
	find_range();
	swap_symvol(X, Y, 0);
	int choice = _getch();
	if (choice == 224)		// ����������� � �������  �������
		choice = _getch();
	if (choice == 80)
		if (X != maxX - 1)
		{
			X += 1;
			Pole(X, Y, counter);
		}
		else
		{
			X = 0;
			Pole(X, Y, counter);
		}
	if (choice == 72)
		if (X != 0)
		{
			X -= 1;
			Pole(X, Y, counter);
		}
		else
		{
			X = maxX - 1;
			Pole(X, Y, counter);
		}
	if (choice == 77)
		if (Y != maxY - 1)
		{
			Y += 1;
			Pole(X, Y, counter);
		}
		else
		{
			Y = 0;
			Pole(X, Y, counter);
		}
	if (choice == 75)
		if (Y != 0)
		{
			Y -= 1;
			Pole(X, Y, counter);
		}
		else
		{
			Y = maxY - 1;
			Pole(X, Y, counter);
		}
	if (choice == 13)		// ��������� ������� ��� ����������� ������������
	{
		swap_symvol(X, Y, 2);
		Pole(X, Y, ++counter);
	}
}

void swap_mestami()
// ������ ������� 2 ��������� (� ���������� �������) ��������
{
	T tmp1, tmp2;
	int t1, t2, t3, t4;
	for (int i = 0; i < maxX; i++)		// ������ 2-�� �������
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
	for (int i = 0; i < maxX; i++)		// ������ 1-�� �������
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
	T tmp3 = mas[t3][t4];			// ������ ������� 2 �������  
	mas[t3][t4] = mas[t1][t2];
	mas[t1][t2] = tmp3;
	swap_symvol(t1, t2, 3);			// ������� ���������� ������
	swap_symvol(t3, t4, 3);
}

void swap_symvol(int X, int Y, int P)
// ��� ������ �������� ��������� �����
{
	switch (P)
	{
	case(0):
		if (mas[X][Y] == "<%>") { mas[X][Y] = " % "; }
		else if (mas[X][Y] == "<#>") { mas[X][Y] = " # "; }
		else if (mas[X][Y] == "<$>") { mas[X][Y] = " $ "; }
		else if (mas[X][Y] == "<@>") { mas[X][Y] = " @ "; }
		else if (mas[X][Y] == "<~>") { mas[X][Y] = " ~ "; }
		break;
	case(1):
		if (mas[X][Y] == " % ") { mas[X][Y] = "<%>"; }
		else if (mas[X][Y] == " # ") { mas[X][Y] = "<#>"; }
		else if (mas[X][Y] == " $ ") { mas[X][Y] = "<$>"; }
		else if (mas[X][Y] == " @ ") { mas[X][Y] = "<@>"; }
		else if (mas[X][Y] == " ~ ") { mas[X][Y] = "<~>"; }
	case(2):
		if (mas[X][Y] == " % ") { mas[X][Y] = "[%]"; }
		else if (mas[X][Y] == " # ") { mas[X][Y] = "[#]"; }
		else if (mas[X][Y] == " $ ") { mas[X][Y] = "[$]"; }
		else if (mas[X][Y] == " @ ") { mas[X][Y] = "[@]"; }
		else if (mas[X][Y] == " ~ ") { mas[X][Y] = "[~]"; }
		break;
	case(3):
		if (mas[X][Y] == "[%]") { mas[X][Y] = " % "; }
		else if (mas[X][Y] == "[#]") { mas[X][Y] = " # "; }
		else if (mas[X][Y] == "[$]") { mas[X][Y] = " $ "; }
		else if (mas[X][Y] == "[@]") { mas[X][Y] = " @ "; }
		else if (mas[X][Y] == "[~]") { mas[X][Y] = " ~ "; }
		break;
	}
}

void mas_out()
// ����� ������� � �������
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

void find_range()
// ���������� ������������������ ��������
{
	for (int i = 0; i < maxX; i++)		//�������������� ������������������
	{
		int count = 1, start, end;
		for (int j = 0; j <= maxY - 1; j++)
		{
			if (count == 3)
			{
				count = 1;
				end = j;
				delete_symvol(start, end, i, 0);
			}
			if (mas[i][j] == mas[i][j + 1])
			{
				if (count == 1)
				{
					start = j;
				}
				count++;
			}
			else
			{
				count = 1;
			}
		}
	}
	for (int i = 0; i < maxX; i++)		//������������ ������������������
	{
		int count = 1, start, end;
		for (int j = 0; j <= maxY - 1; j++)
		{
			if (count == 3)
			{
				count = 1;
				end = j;
				delete_symvol(start, end, i, 1);
			}
			if (mas[j][i] == mas[j + 1][i])
			{
				if (count == 1)
				{
					start = j;
				}
				count++;
			}
			else
			{
				count = 1;
			}
		}
	}
}

void delete_symvol(int start, int end, int layer, bool key)
// �������� ����� � ������ ������������������ ��������
{
	switch (key)
	{
	case(0):		//�������������� ������������������
	{
		for (int i = layer; i != 0; i--)
		{
			for (int j = start; j <= end; j++)
			{
				T tmp = mas[i - 1][j];
				mas[i - 1][j] = mas[i][j];
				mas[i][j] = tmp;
			}
		}
		symvol sl;
		for (int i = start; i <= end; i++)
		{
			mas[0][i] = sl.get_random();
		}
		break;
	}
	case(1):		//������������ ������������������
	{
		symvol sl;
		for (int i = start; i <= end; i++)
		{
			for (int j = i; j > 0; j--)
			{
				T tmp = mas[j][layer];
				mas[j][layer] = mas[j - 1][layer];
				mas[j - 1][layer] = tmp;

			}
			mas[0][layer] = sl.get_random();
		}
		break;
	}
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