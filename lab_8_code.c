#define _CRT_SECURE_NO_WARNINGS
#define pi 3.14159265358979323846
#include <stdio.h>
#include <locale.h>
#include <math.h>

int task1_sum(int a, int b);
double task1A(double x);
double f(double x);
double task3(double x);
int fact(int x);

int main()
{
	setlocale(LC_ALL, "RUS");
	puts("\tЗадание 0");
	int kol;
	char simv1, simv2;
	printf("Введите количество печатаемых символов, первый и второй символ:\n");
	scanf("%d %c %c", &kol, &simv1, &simv2);
	putchar('+');
	for (int s = 1; s <= kol; s++)
	{
		if (s <= kol / 2)
		{
			printf("%c\!", simv1);
		}
		else printf("%c\!", simv2);
	}
	putchar('+\n');

	puts("\tЗадание 1");
	int n, m;
	printf("Введите число n и m (m > n):\n"); //m > n
	scanf("%d %d", &n, &m);
	printf("Сумма чисел от %d до %d равна %d\n", m, n, task1_sum(n, m));

	puts("\tЗадание 1A");
	int K = 1024;
	printf("Введите степень n:\n");
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		printf("2 ^ %d = %10.3lfK\n", i, task1A(i) / 1024);
	}

	printf("\tЗадание 2\ny = x - 3cos ^ 2(1, 04x)  [0.15; 2.1]\nВведите шаг табуляции:\n"); //Вариант 7   
	double shag;
	scanf("%lf", &shag);
	if (shag <= 0) printf("Неправильный шаг!");
	else
	{

		puts("\n_____ x _______ f(x) ___");
		for (double start = 0.15; start <= 2.1; start += shag)
		{
			printf("| %lf | %lf |\n", start, f(start));
		}
	}

	puts("\tЗадание 3\n"); //Вариант 7
	double a;
	printf("Введите значение a:\n");
	scanf("%lf", &a);
	printf("При a = %.1lf выражение равно %lf", a, task3(a));
	return 0;
}

task1_sum(int a, int b)
{
	int s = 0;
	int k = 0;
	for (int i = b; i >= a; i--)
	{
		s = s + i;
		k = k + 1;
		printf("Выполнено %d раз(а)\n", k);
	}
	return s;
}

double task1A(double x)
{
		return pow(2, x);	
}

double f(double x)
{
	return x - 3 * pow(cos(1.04 * x * pi / 180), 2);
}

double task3(double x)
{
	return x - (pow(x, 3) / fact(3)) + (pow(x, 5) / fact(5)) - (pow(x, 7) / fact(7)) + (pow(x, 9) / fact(9)) - (pow(x, 11) / fact(11)) + (pow(x, 13) / fact(13));
}

int fact(int x)
{
	if (x < 0) return 111;
	else
	{
		int res = 1;
		for (int i = 1; i <= x; i++)
		{
			res = res * i;
		}
		return res;
	}
}