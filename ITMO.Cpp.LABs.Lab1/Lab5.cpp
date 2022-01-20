#include "Header.h"
#include <iostream>
#include <string>

namespace Lab5
{
	//
	// ���������� 1
	//
	int ex1()
	{
		const int n = 10;
		int mas[n];
		for (int i = 0; i < n; i++)
		{
			std::cout << "mas[" << i << "]=";
			std::cin >> mas[i];
		}
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			s += mas[i];
		}
		std::cout << s;
		return 0;
	}

	//
	// ���������� 2
	//
	int ex2()
	{
		const int N = 10;
		int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
		int min = 0; // ��� ������ ������������ ��������
		int buf = 0; // ��� ������ ����������
		for (int i = 0; i < N; i++)
		{
			min = i; // ����� ������� ������, ��� ������ � ����������� ���������
			// � ����� ������ �������� ����� ������ � ����������� ���������
			for (int j = i + 1; j < N; j++)
				min = (a[j] < a[min]) ? j : min;
			// ������������ ����� ��������, ������� ��� ������� � �������
			if (i != min)
			{
				buf = a[i];
				a[i] = a[min];
				a[min] = buf;
			}
		}
		for (int i : a)
			std::cout << i << '\t';
		return 0;
	}

	//
	// ���������� 3
	//
	void show_array(const int Arr[], const int N);
	void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b));
	bool from_min(const int a, const int b);
	bool from_max(const int a, const int b);
	int ex3()
	{
		bool (*from_f[2])(int, int) = { from_min,from_max };
		const int N = 10;
		int my_choose = 0;
		int A[N] = { 9,8,7,6,1,2,3,5,4,9 };
		std::cout << "1. ����������� �� �����������\n";
		std::cout << "2. ����������� �� ��������\n";
		std::cin >> my_choose;
		std::cout << "�������� ������: ";
		show_array(A, N);
		bubble_sort(A, N, (from_f[my_choose - 1]));
		/*switch (my_choose)
		{
		case 1: 
			bubble_sort(A, N, from_min); 
			break;
		case 2: 
			bubble_sort(A, N, from_max); 
			break;
		default: 
			std::cout << "\r����������� �������� ";
		}*/
		show_array(A, N);
		return 0;
	}
	void show_array(const int Arr[], const int N)
	{
		for (int i = 0; i < N; i++)
			std::cout << Arr[i] << " ";
		std::cout << "\n";
	}
	bool from_min(const int a, const int b)
	{
		return a > b;
	}
	bool from_max(const int a, const int b)
	{
		return a < b;
	}
	void swap(int& x, int& y)
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b))
	{
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if ((*compare)(Arr[j], Arr[j + 1])) 
					swap(Arr[j], Arr[j + 1]);
			}
		}
	}

	//
	// ���������� 4
	//
	int ex4()
	{
		int n;
		std::cout << "������� ���������� ���������:\n";
		std::cin >> n;
		int* myArray = new int[n]; // ������ � ����

		for (size_t i = 0; i < n; i++) // ������ � ���������� �������� � ������
		{			
			std::cout << "������� ������� " << i + 1 << " : " << std::endl;
			std::cin >> myArray[i];			
		}
		delete[] myArray;
		return 0;
	}

	//
	// ���������� 5
	//
	int ex5()
	{		
		return 0;
	}
	
	//
	// ����������� ������� 1
	//
	void fillArray(int Arr[], const int N);
	void fillRandomArray(int Arr[], const int N);
	std::string arrayToString(const int Arr[], const int N);
	int sumArray(int Arr[], const int N);
	int negSumArray(int Arr[], const int N);
	int posSumArray(int Arr[], const int N);
	int oddElemSumArray(int Arr[], const int N);
	int evenElemSumArray(int Arr[], const int N);
	int maxElemIndex(int Arr[], const int N);
	int minElemIndex(int Arr[], const int N);
	int multMaxMinArray(int Arr[], const int N);

	int controlEx1()
	{
		int n,
			myChoose1 = 0;
		void (*typeOfFillArray[2])(int Arr[], int) = { fillArray,fillRandomArray };
		int (*methodsArray[8])(int Arr[], int) = 
		{ 
			sumArray,
			negSumArray,
			posSumArray,
			oddElemSumArray,
			evenElemSumArray,
			maxElemIndex,
			minElemIndex,
			multMaxMinArray
		};
		std::cout << "������� ���������� ���������:\n";
		std::cin >> n;
		int* myArray = new int[n]; // ������ � ����
		std::cout << "1. ��������� ������ �������\n";
		std::cout << "2. ��������� ������ ���������� �������\n" << std::endl;
		std::cin >> myChoose1;
		typeOfFillArray[myChoose1 - 1](myArray, n);
		std::string sArr = arrayToString(myArray, n);		
		int flag = 0;
		while (true)
		{
			std::cout << "�������� ������:\n";
			std::cout << sArr << std::endl;
			std::cout << "1. ������ ����� ���������\n"
				<< "2. ������ ����� ������������� ���������\n"
				<< "3. ������ ����� ������������� ���������\n"
				<< "4. ������ ����� ��������� � ��������� ���������\n"
				<< "5. ������ ����� ��������� � ������� ���������\n"
				<< "6. ����� ������������ ������� ������� � ������� ��� ������\n"
				<< "7. ����� ����������� ������� ������� � ������� ��� ������\n"
				<< "8. ������ ������������ ��������� �������, ������������� ����� ������������ � ����������� ����������\n"
				<< "9. �����"
				<< std::endl;
			std::cin >> flag;
			if (flag == 9)
				break;
			else
				std::cout << methodsArray[flag-1](myArray, n) << std::endl;
		}
		
		delete[] myArray;
		return 0;
	}
	// ���������� ������� �������
	void fillArray(int Arr[], const int N)
	{
		for (size_t i = 0; i < N; i++) // ������ � ���������� �������� � ������
		{
			std::cout << "������� ������� " << i + 1 << " : " << std::endl;
			std::cin >> Arr[i];
		}
	}
	// ���������� ������� ���������� �������
	void fillRandomArray(int Arr[], const int N)
	{
		srand(time(NULL));
		for (size_t i = 0; i < N; i++)
		{			
			Arr[i] = rand() % 100 - 50;
		}
	}
	// �������������� ������� � ������
	std::string arrayToString (const int Arr[], const int N)
	{
		std::string result = "[ ";
		for (int i = 0; (i < N - 1); i++)
		{
			std::string temp = std::to_string(Arr[i]) + ", ";
			result += temp;
		}
		result += std::to_string(Arr[N-1]) + " ]";
		return result;
	}
	// ������ ����� ��������� �������
	int sumArray(int Arr[], const int N)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += Arr[i];
		}		
		return sum;
	}
	// ������ ����� ������������� ���������
	int negSumArray(int Arr[], const int N)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (Arr[i] < 0)
				sum += Arr[i];
			else
				continue;
		}
		return sum;
	}
	// ������ ����� ������������� ���������
	int posSumArray(int Arr[], const int N)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (Arr[i] > 0)
				sum += Arr[i];
			else
				continue;
		}
		return sum;
	}
	// ������ ����� ��������� � ��������� ���������
	int oddElemSumArray(int Arr[], const int N)
	{
		int sum = 0;
		for (int i = 1; i < N; i += 2)
			sum += Arr[i];		
		return sum;
	}
	// ������ ����� ��������� � ������� ���������
	int evenElemSumArray(int Arr[], const int N)
	{
		int sum = 0;
		for (int i = 0; i < N; i += 2)
			sum += Arr[i];	
		return sum;
	}
	// ���������� ������� ������������� �������� �������
	int maxElemIndex(int Arr[], const int N)
	{
		int max = Arr[0];
		int maxIndex = 0;
		for (int i = 1; i < N; i++)
		{
			if (Arr[i] > max)
			{
				max = Arr[i];
				maxIndex = i;
			}
		}
		return maxIndex;
	}
	// ���������� ������� ������������ �������� �������
	int minElemIndex(int Arr[], const int N)
	{
		int min = Arr[0];
		int minIndex = 0;
		for (int i = 1; i < N; i++)
		{
			if (Arr[i] < min)
			{
				min = Arr[i];
				minIndex = i;
			}
		}
		return minIndex;
	}
	// ������������ ��������� �������, ������������� ����� ������������ � ����������� ����������
	int multMaxMinArray(int Arr[], const int N)
	{
		int mult = 1;
		int max = maxElemIndex(Arr, N);
		int min = minElemIndex(Arr, N);
		int start = (max < min) ? max : min;
		int end = (max > min) ? max : min;
		for (int i = start; i <= end; i++)
			mult *= Arr[i];
		return mult;
	}

	//
	// ����������� ������� 2
	//
	int* max_vect(int kc, int a[], int b[]);
	int controlEx2()
	{
		int a[] = { 1,2,3,4,5,6,7,2 };
		int b[] = { 7,6,5,4,3,2,1,3 };
		int kc = sizeof(a) / sizeof(a[0]); //���������� ��������� �������
		int* c; //��������� �� �������������� ������
		c = max_vect(kc, a, b); //����� ������� ��� �������� �������
		for (int i = 0; i < kc; i++) //����� ����������.
			std::cout << c[i] << " ";
		std::cout << std::endl;
		delete[]c; //������� ������.
		return 0;
	}
	int* max_vect(int kc, int a[], int b[])
	{
		int* c = new int[kc];
		for (size_t i = 0; i < kc; i++)
			c[i] = (a[i] > b[i]) ? a[i] : b[i];
		return c;
	}
}