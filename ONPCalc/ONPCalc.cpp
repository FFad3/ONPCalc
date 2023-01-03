// ONPCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <stack>

#define STACK_SIZE 1000
using namespace std;
//Upoœledzony stos
class Stack
{
private:
	int top;
public:
	Stack() { top = -1; };
	int a[STACK_SIZE];

	bool push(int x)
	{
		if (top >= (STACK_SIZE - 1))
		{
			return false;
		}
		else
		{
			a[++top] = x;
			return true;
		}
	};
	int pop()
	{
		if (top < 0)
		{
			return 0;
		}
		else
		{
			int result = a[top--];
			return result;
		}
	};
	int peek()
	{
		if (top < 0)
		{
			return 0;
		}
		else
		{
			int result = a[top];
			return result;
		}
	};
	//bool isValidOperation()
	//{
	//	if (top >= 1 && top % 2 == 1)
	//	{
	//		return true;
	//	}
	//	/*std::cout << "Operation is invalid not enouught numbers";*/
	//	return false;
	//}
	bool isEmpty()
	{
		if (top < 0)
		{
			return true;
		}
		return false;
	};
};
bool checkInteger(std::string input)
{
	bool isNeg = false;
	int itr = 0;
	if (input.size() == 0)
		return false;
	if (input[0] == '-')
	{
		isNeg = true;
		itr = 1;
	}
	if (input.size() == 1 && isNeg)
		return false;

	for (int i = itr;i < input.size();i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}
class Stack stos {};
string notacja{ "4 5 6 - * 5 2 2 + - -" };
string zapis{ "(4*(5-6))-(5-(2*2))" };
string operatory{ "*/+-" };
string wynik{};
stack<char> stos2{};
int main()
{
	//Konwersja na ONP
	cout << "Wprowadz wyrazenie infiksowe:\n";
	cin >> zapis;
	system("CLS");

	for (auto x : zapis)
	{
		if (x >= '0' && x <= '9')
			wynik += x;
		else if (x == '(')
			stos2.push(x);
		else if (operatory.find(x) != string::npos)
		{
			if (!stos2.size() == 0 && operatory.find(stos2.top()) != string::npos)
			{
				if (operatory.find(x) < operatory.find(stos2.top()))
				{
					wynik += stos2.top();
					stos2.pop();
					stos2.push(x);
				}
				else
				{
					stos2.push(x);
				}
			}
			else
			{
				stos2.push(x);
			}
		}
		else if (x == ')')
		{
			while (stos2.top() != '(')
			{
				wynik += stos2.top();
				stos2.pop();
			}
			stos2.pop();
		}
	}
	while (!stos2.empty())
	{
		wynik += stos2.top();
		stos2.pop();
	}
	cout << "Konwersja na ONP zakonczona\n";
	cout << zapis << " => " << wynik << "\n";

	/*notacja.erase(remove(notacja.begin(), notacja.end(), ' '), notacja.end());*/

	cout << "Notacj ONP przygotowana do obliczen\n";
	cout << wynik << "\n\n";

	for (auto x : wynik)
	{
		int wartosc_a{}, wartosc_b{};
		if (x >= '0' && x <= '9')
		{
			stos.push(x - 48); //ASCII TO Int
		}
		else
		{
			wartosc_b = stos.pop();
			wartosc_a = stos.pop();

			switch (x)
			{
			case '+':
				stos.push(wartosc_a + wartosc_b);
				break;
			case '-':
				stos.push(wartosc_a - wartosc_b);
				break;
			case '*':
				stos.push(wartosc_a * wartosc_b);
				break;
			case '/':
				stos.push(wartosc_a / wartosc_b);
				break;
			default:
				break;
			}
		}
	}
	while (stos.isEmpty())
	{
		stos.pop();
	}
	cout << "Wynik " << stos.peek() << "\n\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file