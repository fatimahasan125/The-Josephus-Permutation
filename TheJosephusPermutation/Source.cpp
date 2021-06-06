//The Josephus Permutation!
//By Fatima Hasan
#include <iostream>
#include <Windows.h>
#include <ctime>


using namespace std;

void setColour(int text, int color)
{
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, color);
	//cout << text << endl;

	FlushConsoleInputBuffer(hstdin);
	cout << text;

	SetConsoleTextAttribute(hstdout, csbi.wAttributes);

}

int* killPerson(int* A, int &k, int pos)
{
	//removing a person from position pos from the array
	int* temp = new int[k - 1];
	for (int i = 0; i < pos; i++)
		temp[i] = A[i];

	for (int i = pos + 1; i < k; i++)
		temp[i - 1] = A[i];

	k--;
	delete[]A;
	return temp;
}

int* expandArray(int* A, int j, int& k, int m, int& n)
{
	//adding m people to the array starting from position j
	int* temp = new int[k + m];
	int a = 1;

	for (int i = 0; i < j; i++)
		temp[i] = A[i];

	for (int i = j; i < j + m; i++)
	{
		temp[i] = n + a;
		a++;
	}

	int l = 0;
	for (int i = j; i < k; i++)
	{
		temp[j + m + l] = A[i];
		l++;
	}

	k = k + m;
	n = n + m;
	delete[]A;
	return temp;
}

void printRectangle(int* A, int size, int length, int width, int current, int color = 0)
/*
color represents red, blue or white.
1 represents blue. 2 represents red.
0 represents white
*/
{

	int i = 0;

	for (i = 0; i < length; i++)
	{
		if (A[i] != current || color == 0)
			cout << A[i] << "\t";
		else if (color == 1)
		{
			setColour(A[i], FOREGROUND_BLUE);
			cout << "\t";
		}
		else
		{
			setColour(A[i], FOREGROUND_RED);
			cout << "\t";
		}
	}
	cout << endl << endl;

	if (size % 2 != 0)
		cout << " ";
	else
	{
		if (A[size - 1] != current || color == 0)
			cout << A[size - 1];
		else if (color == 1)
			setColour(A[size - 1], FOREGROUND_BLUE);
		else
			setColour(A[size - 1], FOREGROUND_RED);
	}

	for (int space = 0; space < length - 1; space++)
		cout << "\t";

	if (A[i] != current || color == 0)
		cout << A[i] << "\t";
	else if (color == 1)
	{
		setColour(A[i], FOREGROUND_BLUE);
		cout << "\t";
	}
	else
	{
		setColour(A[i], FOREGROUND_RED);
		cout << "\t";
	}

	cout << endl << endl;

	int j = 1, k = 2;
	i++;
	for (int a = 1; a < width; a++)
	{
		if (size % 2 != 0)
		{
			if (A[size - j] != current || color == 0)
				cout << A[size - j];
			else if (color == 1)
				setColour(A[size - j], FOREGROUND_BLUE);
			else
				setColour(A[size - j], FOREGROUND_RED);

			j++;
		}
		else
		{
			if (A[size - k] != current || color == 0)
				cout << A[size - k];
			else if (color == 1)
				setColour(A[size - k], FOREGROUND_BLUE);
			else
				setColour(A[size - k], FOREGROUND_RED);
			k++;
		}

		for (int space = 0; space < length - 1; space++)
			cout << "\t";


		if (A[i] != current || color == 0)
			cout << A[i];
		else if (color == 1)
			setColour(A[i], FOREGROUND_BLUE);
		else
			setColour(A[i], FOREGROUND_RED);
		i++;

		cout << endl << endl;
	}



	int x = size - width - 1;
	int y = size - width;
	for (int b = 0; b < length; b++)
	{
		if (size % 2 == 0)
		{
			if (A[x] != current || color == 0)
				cout << A[x] << "\t";
			else if (color == 1)
			{
				setColour(A[x], FOREGROUND_BLUE);
				cout << "\t";
			}
			else
			{
				setColour(A[x], FOREGROUND_RED);
				cout << "\t";
			}
			x--;
		}
		else
		{
			if (A[y] != current || color == 0)
				cout << A[y] << "\t";
			else if (color == 1)
			{
				setColour(A[y], FOREGROUND_BLUE);
				cout << "\t";
			}
			else
			{
				setColour(A[y], FOREGROUND_RED);
				cout << "\t";
			}
			y--;
		}
	}
	cout << endl << endl;
}

void printsmall(int*A, int size, int current, int color = 0)
//for printing rectangles smaller than size 4
{
	if (size == 4 || size == 2)
	{
		for (int i = 0; i <= 1; i++)
		{
			if (A[i] != current || color == 0)
				cout << A[i] << "\t";
			else if (color == 1)
			{
				setColour(A[i], FOREGROUND_BLUE);
				cout << "\t";
			}
			else
			{
				setColour(A[i], FOREGROUND_RED);
				cout << "\t";
			}
		}
		cout << endl << endl;
		if (size == 4)
		{
			for (int i = 3; i >= 2; i--)
			{
				if (A[i] != current || color == 0)
					cout << A[i] << "\t";
				else if (color == 1)
				{
					setColour(A[i], FOREGROUND_BLUE);
					cout << "\t";
				}
				else
				{
					setColour(A[i], FOREGROUND_RED);
					cout << "\t";
				}
			}
		}
	}
	else if (size == 3)
	{
		for (int i = 0; i <= 1; i++)
		{
			if (A[i] != current || color == 0)
				cout << A[i] << "\t";
			else if (color == 1)
			{
				setColour(A[i], FOREGROUND_BLUE);
				cout << "\t";
			}
			else
			{
				setColour(A[i], FOREGROUND_RED);
				cout << "\t";
			}
		}
		cout << endl << endl;

		if (A[2] != current || color == 0)
			cout << A[2] << endl;
		else if (color == 1)
			setColour(A[2], FOREGROUND_BLUE);
		else
			setColour(A[2], FOREGROUND_RED);

		cout << endl;

	}
	else
		setColour(A[0], FOREGROUND_BLUE);
}

int main()
{
	srand((unsigned)time(0));
	int n, k;
	cout << "Enter the number of people: ";
	cin >> n;
	if (n < 0)
	{
		while (n < 0)
		{
			cout << "Error. Enter positive number" << endl;
			cin >> n;
		}
	}
	k = n;
	int r = rand() % 4 + 5;
	int p = rand() % k + k;
	int *A = new int[k];
	for (int i = 0; i < k; i++)
		A[i] = i + 1;

	int iteration = 0;
	int start = rand() % k + 1;
	int index = start;

	int deadpeople = 0;
	int length = 0, width = 0;
	while (k > 1)
	{
		if (k % 4 == 0)
			length = width = k / 4;
		else if ((k + 1) % 4 == 0)
			length = width = (k + 1) / 4;
		else if (k % 2 != 0)
		{
			length = ((k + 1) / 4) + 1;
			width = (k + 1) / 4;
		}
		else
		{
			length = (k / 4) + 1;
			width = k / 4;
		}
		if (iteration != r)
		{
			if (index >= k)
				index = 0;

			if (k > 4)
				printRectangle(A, k, length, width, A[index++], 1);
			else
				printsmall(A, k, A[index++], 1);


			Sleep(500);
			system("CLS");

		}
		else if (iteration == r)
		{
			if (index >= k)
				index = 0;

			if (k > 4)
				printRectangle(A, k, length, width, A[index], 2);
			else
				printsmall(A, k, A[index], 2);


			Sleep(500);
			A = killPerson(A, k, index);
			deadpeople++;
			r = (rand() % 4 + 5) + iteration;

			system("CLS");
		}

		if (iteration == p && deadpeople<10)
		{
			int m = rand() % 5 + 1;
			int j = rand() % k;

			A = expandArray(A, j, k, m, n);
			cout << m << " new people added starting from position " << j << endl << endl << endl;
			Sleep(1000);

			if (k > 4)
				printRectangle(A, k, length, width, A[index]);
			else
				printsmall(A, k, A[index]);

			Sleep(500);
			system("CLS");
			p += iteration;
		}


		iteration++;


		cout << endl << endl << endl;
	}

	cout << A[k - 1] << " is the winner!" << endl;

	return 0;
}