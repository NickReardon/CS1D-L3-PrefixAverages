/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Lab #3       	: Prefix Averages
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 01 / 27 / 20
 *****************************************************************************/
#include "main.h"

using std::cout; using std::endl;


int main()
{

	/*
	 * HEADER OUTPUT
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/
	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;

	long double duration;
	int size = 0;

	for (int i = 0; i < 5; i++)
	{
		size += 6000;
		t1 = std::chrono::high_resolution_clock::now();
		prefixAverages1(size);
		t2 = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

		cout << "Time: " << duration << "ms" << endl;
		cout << "Size: " << size << endl << endl;
	}
	cout << "\n----------------------------\n";
	size = 0;

	for (int i = 0; i < 5; i++)
	{
		size += 6000;
		t1 = std::chrono::high_resolution_clock::now();
		prefixAverages2(size);
		t2 = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

		cout << "Time: " << duration << "ms" << endl;
		cout << "Size: " << size << endl << endl;
	}


	system("pause");
	return 0;
}


void prefixAverages1(int size)
{
	int* x;
	x = new int[size];

	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		x[i] = rand() % 1000 + 10;
	}

	int *arr;
	arr = new int[size];
	int a;

	for (int i = 0; i < size; i++)
	{
		a = 0;
		for(int j = 0; j <= i; j++)
		{
			a = a + x[j];
		}
		arr[i] = a / (i + 1);
	}

}
void prefixAverages2(int size)
{
	int* x;
	x = new int[size];

	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		x[i] = rand() % 1000 + 10;
	}

	int* arr;
	arr = new int[size];
	int a = 0;
	for (int i = 0; i < size; i++)
	{
		a = a + x[i];
		arr[i] = a / (i + 1);
	}
}

