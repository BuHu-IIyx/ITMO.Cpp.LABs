#include <iostream>
#include <string>
#include <tuple>
#include "Header.h"
#include <vector>
using std::endl;
using std::cout;
using std::cin;
using std::string;

namespace Lab14
{
	//
	// Упражнение 1
	//
	template<class T>
	void sorting(T arr[], int size) 
	{
		int j = 0;
		for (int i = 0; i < size; i++) {
			T x = arr[i];
			for (j = i - 1; j >= 0 && x < arr[j]; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = x;
		}
	}
	template<class T>
	void printArray (T arr[], int size)
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << ";";
		cout << endl;
	}
	int ex1()
	{
		int arr[] = { 9,3,17,6,5,4,31,2,12 };
		double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
		char arrc[] = "Hello, word";
		int k1 = sizeof(arr) / sizeof(arr[0]);
		int k2 = sizeof(arrd) / sizeof(arrd[0]);
		int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;
		sorting(arr, k1);		
		sorting(arrd, k2);		
		sorting(arrc, k3);
		printArray(arr, k1);
		printArray(arrd, k2);
		printArray(arrc, k3);
		
		return 0;
	}
	//
	// Упражнение 2
	//
	template<class Tuple>
	void printTupleOfThree(Tuple t)
	{
		cout << "("
			<< std::get<0>(t) << ", "
			<< std::get<1>(t) << ", "
			<< std::get<2>(t) << ")" << endl;
	}
	int ex2()
	{
		std::vector<string> v1{ "one", "two", "three", "four", "five", "six" };
		std::vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
		std::vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
		auto t3 = std::make_tuple(v1[0], v1[1], v3[2]);
		printTupleOfThree(t3);
		return 0;
	}
	//
	// Упражнение 3
	//
	template<class Tuple, std::size_t N>
	struct TuplePrinter {
		static void print(const Tuple& t)
		{
			TuplePrinter<Tuple, N - 1>::print(t);
			cout << ", " << std::get<N - 1>(t);
		}
	};
	template<class Tuple>
	struct TuplePrinter<Tuple, 1> {
		static void print(const Tuple& t)
		{
			cout << std::get<0>(t);
		}
	};
	template<class... Args>
	void printTuple(const std::tuple<Args...>& t)
	{
		cout << "(";
		TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
		cout << ")" << endl;
	}
	int ex3()
	{
		std::vector<string> v1{ "one", "two", "three", "four", "five", "six" };
		std::vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
		std::vector<float> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
		auto t1 = std::make_tuple(v1[0], v1[1], v3[0]);
		auto t2 = std::make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);
		printTuple(t1);
		printTuple(t2);
		return 0;
	}


	//
	// Контрольное задание 1
	//
	template<typename T>
	double midArray(T arr[], int size)
	{
		T sum = 0;
		for (int i = 0; i < size; i++)
			sum += arr[i];
		return (double)sum / size;
	}
	int controlEx1()
	{
		int arr[] = { 9,3,17,6,5,4,31,2,12 };
		long arrl[] = { 9,3,17,6,5,4,31,2,12 };
		double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
		char arrc[] = "Hello, word";
		int k1 = sizeof(arr) / sizeof(arr[0]);
		int k2 = sizeof(arrl) / sizeof(arrl[0]);
		int k3 = sizeof(arrd) / sizeof(arrd[0]);
		int k4 = sizeof(arrc) / sizeof(arrc[0]) - 1;
		cout << midArray(arr, k1) << endl;
		cout << midArray(arrl, k2) << endl;
		cout << midArray(arrd, k3) << endl;
		cout << midArray(arrc, k4) << endl;
		return 0;
	}
}