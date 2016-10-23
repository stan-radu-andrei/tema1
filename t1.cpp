#include "stdafx.h"
#include "t1.h"
#include <iostream>



static bool isPalindrom(unsigned long long number)
{
	int dos = 0, copie = number;

	while (number > 0)
	{
		dos = dos * 10 + number % 10;
		number /= 10;
	}
	return (dos == copie);
}

static unsigned char sumBinaryFigure(unsigned long long number)
{
	int car=0;
	while (number)
	{
		car += number % 2;
		number /= 2;
	}
	return (int) car ;
}

static bool isLeapYear(unsigned short year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

static unsigned char dayOfTheWeek(unsigned short year,
	unsigned char month,
	unsigned char day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year--;
	}
	//return (int) ((day + (13 * (month + 1)) / 5 + year % 100 + (year % 100) / 4 + (year / 100) / 4 + 5 * (year / 100))%7);
	int h = ((day + (13 * (month + 1)) / 5 + year + year / 4 - year / 100 + year / 400 ) % 7 );
	return ((h + 5) % 7) + 1;
}

static unsigned int fibonnaci(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	return fibonnaci(index - 1) + fibonnaci(index - 2);
}

static unsigned long perfectNumbers(unsigned int number)
{
	int ok = 0, i, sum = 0, sol = 0;
	while (ok < 2)
	{
		sum = 1;
		number--;
		for (i = 2; i*i < number; i++)
			if (number%i == 0)
				sum = sum + i + number/i;

		if (i*i == number)sum += i;
		if (number == sum)
		{
			ok++;
			sol += number;
		}
	}
	return sol;
}
static bool ePrim(unsigned int x)
{
	int k;
	int ok = 1;
	for (k = 2; k <= x / 2; k++)
	{
		if (x%k == 0)ok = 0;
	}
	return (ok == 1);
}
static unsigned short primeDivisors(unsigned int left, unsigned int right)
{
	int i, j, k, maxim = 0, ok, lg = 0;
	char uz[1000000] = { 0 };
	for (i = left; i <= right; i++)
	{
		for (j = 2; j <= i/2; j++)
		{
			if (i%j == 0)
			{
				if(ePrim(j)==1)
				{
					//std::cout << "yra";
					uz[i]++;
					if (uz[i] == maxim)
						lg++;
					if (uz[i] > maxim)
					{
						maxim = uz[i];
						lg = 1;
					}

				}
			}

		}
	}
	return lg;
}

static matrix primeTwins(unsigned int count, unsigned int lowerBound)
{
	struct matrix m;
	m.lines = count;
	m.columns = 2;
	int i = 0;
	if (lowerBound % 2 == 0) lowerBound++;
	else lowerBound += 2;
	while (count > i)
	{
		if (ePrim(lowerBound) && ePrim(lowerBound + 2))
		{
			m.values[i][0] = lowerBound;
			m.values[i][1] = lowerBound + 2;
			i++;
		}
		lowerBound+=2;
	}
	return m;
}

static bool areOrderedFibonnaci(vector vec)
{
	int i;
	int fib[100] = { 0 };
	fib[0] = 0;
	fib[1] = 1;
	if (vec.values[0] != 0 || vec.values[1] != 1) return false;
	for (i = 2; i < vec.length; i++)
	{
		fib[i] = fib[i-2] + fib[i - 1];
		//std::cout << fib[i] << " ";
		if (vec.values[i] != fib[i])
		{
			return false;
		}
	}
	return true;
}

static unsigned char checkVectorInclude(vector vecOne, vector vecTwo)
{
	int i, ok1 = 1, ok2 = 0;
	bool b1[10000] = { 0 }, b2[10000] = { 0 };
	for (i = 0; i < vecOne.length; i++)
	{
		b1[vecOne.values[i]] = 1;
	}
	for (i = 0; i < vecTwo.length; i++)
	{
		b2[vecOne.values[i]] = 1;
	}
	for (i = 0; i < vecOne.length; i++)
	{
		if (b2[vecOne.values[i]] != 0)
			ok1 = 0;
	}
	for (i = 0; i < vecTwo.length; i++)
	{
		if (b1[vecTwo.values[i]] != 0)
			ok2 = 0;
	}
	if (ok1 == 1 && ok2 == 1)
	{
		return (int) 0;
	}
	if (ok1 == 1)
	{
		return (int)1;
	}
	if (ok2 == 1)
	{
		return (int)2;
	}
	return (int)3;
}