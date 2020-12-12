/*#include <stdio.h>
#include <string.h>

int str_len(char str[]) {
	int i = 0, count = 0;

	while (str[i] != '\0') {
		count++;
	}

	return count;
}

void str_shift(char str[], int index) {
	int len, i;

	len = str_len(str);
	for (i = index; i < len; i++) {
		str[i] = str[i + 1];
	}
}

void del_char(char str[], char del_c) {
	int i, j = 0;
	int len;

	len = str_len(str);
	for (i = 0; i <= len; i++) {
		if (str[i] == del_c) {
			str_shift(str, i);
			i--;
		}
	}

	new_str[j] = '\0';
}

void copy_str(char str[], char new_str[]) {
	int i, len;

	len = str_len(str);
	for (i = 0; i <= len + 1; i++) {
		new_str[i] = str[i];
	}
}

void main() {
	char str[20] = "hello, world";
	char new_str[20];

	gets_s(str);
	del_char(str, 'e');
	printf("%s", str);
}*/

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define SIZE 4
#define SIZE_TAB 20
#define SIZE_TABLE 4
#define SIZE_STR 30


double power(double x, int m) {
	/*возводит x^m*/
	int ans = 1;

	for (int i = 1; i <= m; i++) {
		ans *= x;
	}

	return ans;
}

int factorial(int m) {
	/*считает факториал*/
	int ans = 1;

	for (int i = 1; i <= m; i++) {
		ans *= i;
	}

	return ans;
}

double exp_not_optimal(double x, int n) {
	double ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += power(x, i) / factorial(i);
	}

	return ans;
}

double my_exp(double x, int n) {
	/*вычисляет экспоненту*/
	double ans = 1;
	double exp = 1;

	for (int i = 1; i < n; i++) {
		exp = exp * x / i;
		ans += exp;
	}

	return ans;
}

void comparison_exp() {
	/*сравнение exp от a до b с шагом h*/
}

double my_sin(double x, int n) {
	/*вычисляет синунс*/
	double temp = x;
	double ans = x;

	/*привести значение x к диапазону[0,2*pi]*/
	while (x < 0 || x > 2 * M_PI) {
		if (x > 0) {
			x -= 2 * M_PI;
		}else{
			x += 2 * M_PI;
		}
	}

	temp = x; 
	ans = x;

	for (int i = 1; i < n; i++) {
		temp *= -1 * x * x / (2 * i * (2 * i + 1));
		ans += temp;
	}

	return ans;
}

double my_cos(double x, int n) {
	double ans, temp;

	while (x < 0 || x > 2 * M_PI) {
		if (x > 0) {
			x -= 2 * M_PI;
		} else {
			x += 2 * M_PI;
		}
	}

	ans = 1;
	temp = 1;

	for (int i = 0; i < n; i++) {
		temp *= -1 * x * x / ((2 * i + 1) * (2 * i + 2));
		ans += temp;
	}

	return ans;
}

double my_log_limited(double x, int n) {
	x = x - 1;
	double ans = x;
	double denom = x;

	for (int i = 2; i <= n; i++) {
		denom *= -1 * x;
		ans += denom / i;
	}

	return ans;
}

double my_log(double x, int n) {
	x = (x - 1) / (x + 1);

	double ans = x;
	double denom = x;

	for (int i = 1; i < n; i++) {
		denom *= x * x;
		ans += denom / (2 * i + 1);
	}

	return 2 * ans;
}

void number_to_str(char *str ,double number) {
	int len;

	snprintf(str, SIZE_STR, "%lf", number);

	len = strlen(str);
	for (int i = len; i < SIZE_STR - 1; i++) {
		str[i] = ' ';
	}

	str[SIZE_STR - 1] = '\0';
}

void table_title(char *tab) {
	char title_tab[SIZE_STR];
	char arr[SIZE_TABLE][20] = { "x", "f(x)", "my_f(x)", "error" };
	int len;

	for (int i = 0; i < SIZE_TABLE; i++) {
		printf("%s", arr[i]);

		len = strlen(arr[i]);
		title_tab;
		for (int j = 0; j < SIZE_STR - len - 1; j++) {
			title_tab[j] = ' ';
		}

		title_tab[SIZE_STR - len - 1] = '\0';

		printf("%s", title_tab);
	}

	printf("\n");
}

void table(double a, double b, double h, int accur, double (*foo)(double), double (*my_foo)(double, int)) {
	char tab[SIZE_TAB] = "   ";
	char str[30];
	double true_value, my_value, error;
	
	table_title(tab);

	for (double i = a; i < b + h - 0.000001; i += h) {
		true_value = foo(i);
		my_value = my_foo(i, accur);
		error = fabs(true_value - my_value);

		number_to_str(str, i);
		printf("%s", str);

		number_to_str(str, true_value);
		printf("%s", str);

		number_to_str(str, my_value);
		printf("%s", str);

		number_to_str(str, error);
		printf("%s\n", str);
	}
}

void menu() {
	char arr_title[SIZE][30] = { "1.Exp\n", "2.Sin\n", "3.Cos\n", "4.Log\n" };

	system("cls");
	for (int i = 0; i < SIZE; i++) {
		printf("%s", arr_title[i]);
	}
}

void main() {
	int choice;
	double start, end, step;
	double true_value;
	int accur;
	double (*foo)(double) = NULL;
	double (*my_foo)(double, int) = NULL;

	setlocale(LC_ALL, "Russian");

	menu();
	scanf_s("%i", &choice);

	switch (choice){
		case 1:
			my_foo = my_exp;
			foo = exp;
			break;
		case 2:
			my_foo = my_sin;
			foo = sin;
			break;
		case 3:
			my_foo = my_cos;
			foo = cos;
			break;
		case 4:
			my_foo = my_log;
			foo = log;
			break;
	}

	printf("Введите через проблел диапазон и шаг: ");
	scanf_s("%lf %lf %lf", &start, &end, &step);

	printf("Введите точность: ");
	scanf_s("%i", &accur);

	table(start, end, step, accur, foo, my_foo);
}