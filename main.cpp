#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string>
#include <malloc.h>

using namespace std;

//						                 Блок ЧАВО                                                     \\
// Проект выполнен на языке С/С++ в среде Microsoft Visual Studio 2013 студентами групп 7301, 7305 и 7307.
//
// _getch() читает вводимый символ с клавиатуры без вывода его на экран консоли.
// Коды для _getch():
// 72 - стрелка вверх.
// 80 - стрелка вниз.
// 13 - Enter.
// 27 - Esc.
// Коды для остальных кнопок можно получить из интернета или простейшим присвоением _getch() переменной типа int, а затем выводом этой самой переменной.
// 
// Переменные, используемые мной в меню:
// index - счётчик-номер строки.
// tmp - временная переменная, хранящая в себе введённый символ.
// module - массивы с выводимыми строками (для каждой функции свой массив).
// prevIndex - счётчик-номер, который проверяет изменение индекса.
// 
// Сдвиг курсора (знака >) во всех функциях производится с помощью одинакового использования _getch() и работы с результатом функции.
// Алгоритм сам по себе элементарный: если номер _getch() равен коду кнопки стрелки вверх, то уменьшение индекса, аналогично для стрелки вниз.
// Также проводятся проверки, что индексы не выйдут за границы массивов module.
// 
// Выполнение программы строится по типу: функция, хранящая в себе функции, каждая из которых в себе хранит функции, которые, в свою очередь, также хранят в себе функции.
// 
// Каждая новая версия программы несёт в себе малые (и не малые) изменения, которые значительно влияют и улучшают (а также дополняют) саму программу.
// То есть каждая новая программа по факту является улучшенной и оптимизированной версией каждой предыдущей. 
// Первая цифра версии обозначает количество раз, сколько раз код был написан заново.
// Вторая цифра версии обозначает количество раз, когда уже в созданном коде были внесены значительные крупные изменения.
// Третья цифра версии обозначает количество раз, когда уже в созданном коде были внесены значительные малые изменения.
// Подробнее о каждой версии можно посмотреть в пункте меню I уровня под названием "Помощь".
//
// Список заданий можно увидеть по ссылке - http://pozdnkov.vm2-leti.spb.ru/ucebnye-gruppy-1/plany-lekcij/kollokvium-po-dm/kollokvium-po-dm-2
// Список распределений заданий по команде разработки - https://docs.google.com/spreadsheets/d/1X-aLv9Yl9oKm5RbzMNQT9eqwkyXjf6FtmMNYhdbeCRA/edit#gid=0
//
// По поводу уровней меню:
// I уровень - главное меню
// II уровень - модули
// III уровень - функции
//
// Количество скинутых и внесённых в код функций:
// Диана Щебет, группа 7307 - 5 функций (COM_NN_D, MUL_Nk_N, SUB_NN_N, DIV_NN_Dk, ADD_NN_N)
// Александр Трифонов, группа 7301 - 4 функции (POZ_Z_D, MUL_ZM_Z, ADD_ZZ_Z, SUB_ZZ_Z)
// Стас Смирнов, группа 7301 - 4 функции (ABS_Z_N, TRANS_N_Z, TRANS_Z_N, TRANS_Z_Q)
// Евгений Сысенко, группа 7307 - 3 функции (NZER_N_B, MUL_ND_N, SUB_NDN_N)
// Дмитрий Богряков группа 7307 - 2 функции (LED_P_Q, ADD_1N_N)
// Максим Кортель, группа 7301 - 2 функции (MUL_NN_N, MUL_ZZ_Z)
// Рустам Аминов, группа 7307 - 2 функции (TRANS_Q_Z, INT_Q_B)
// Анна Волкова, группа 7307 - 2 функции (MUL_QQ_Q, DIV_QQ_Q)
// Алина Белоусова, группа 7307 - 1 функция (DER_P_P)

int COM_NN_D(int n1, int n2, int *A1, int *A2)
// сравнение чисел 2- если первое больше второго, 1 - если первое меньше второго, 0 - если числа равны.
// Диана Щебет, группа 7307
{
	int D = 0, i;

	if (n1 > n2)
		D = 2;
	else if (n1 < n2)
		D = 1;
	else if (n1 == n2)
		for (i = 0; i < n1; i++)
			if (A1[i] > A2[i])
			{
				D = 2;
				break;
			}
			else if (A1[i] < A2[i])
			{
				D = 1;
				break;
			}

	return D;
}

void MUL_Nk_N(int n, int *A1, int k, int **A10, int *n10) 
///умножение числа на 10 в степени k
// Диана Щебет, группа 7307
{
	int i, m, *A2 = NULL;
	m = n + k;
	A2 = (int*)malloc(sizeof(int)*m);
	for (i = 0; i<n; i++) ///заполнение массива значащими цифрами данного массива
		A2[i] = A1[i];

	for (; n<m; n++) ///заполнение массива нулями после значащих цифр (собственно возведение в степень)
		A2[n] = 0;
	(*n10) = m;
	(*A10) = (int*)malloc(sizeof(int)*m);
	for (i = 0; i < m; i++) {
		(*A10)[i] = A2[i];
	}

	free(A2);
}

int *ABS_Z_N(int &b, int n, int *A)
// Стас Смирнов, группа 7301
{
	b = 0;
	return A;
}

int NZER_N_B(int n1, int * &A1)
//Евгений Сысенко, группа 7307
{
	int i, flag = 0, k = 0;
	for (i = 0; i<n1; i++)
	{
		if (A1[i] != 0)
		{
			flag = 1;
			break;
		}
	}

	return flag;
}

void MUL_ND_N(int n1, int dig, int *A1, int *n3, int **answer)
///Умножение натурального числа на цифру
// Евгений Сысенко, группа 7307
{
	int r = 0, p, q, i, k, z, *help_arr;
	help_arr = (int*)malloc((n1 + 1)*sizeof(int));
	for (i = n1 - 1; i >= 0; i--)
	{
		z = A1[i];
		q = z*dig + r;
		p = q % 10;
		help_arr[i + 1] = p;
		r = q / 10;
	}
	*n3 = n1;
	k = *n3;
	if (r != 0)
	{
		help_arr[0] = r;
		*n3 = n1 + 1;
		k = *n3;
	}
	else
	{
		for (i = 0; i<n1; i++)
		{
			help_arr[i] = help_arr[i + 1];
		}
	}

	(*answer) = (int*)malloc(sizeof(int)*(*n3));

	for (i = 0; i<k; i++)
	{
		(*answer)[i] = help_arr[i];
	}
	free(help_arr);

}

double LED_P_Q(int m, int *C)
// m – степень многочлена и массив C коэффициентов
// Старший коэффициент многочлена (Старший коэффициент - коэффициент при наибольшей степени неизвестного)
// Степенью многочлена  называют наибольшую из степеней входящих в него одночленов.
// Богряков Дмитрий, группа 7307
{
	printf("\nОтвет: %lf", C[0]);
	puts("");
	return C[0]; //функция должна возвращать это значение или просто его выписывать в консольку?
}

void TRANS_Q_Z(int b, int n, int *A, int n1, int *A1)
// Рустам Аминов, группа 7307
{
	int i;
	if ((n1 == 0) && (A1[0] == 1))    //Провека: является ли знаменатель единицей?
	{
		printf("Число переведено в целое: ");
		if (b == 1)               //Данная функция всего лишь выводит на экран числитель, как вы поняли :)
			printf("-");       //Если вы хотите дальше работать с этим числом как целым, просто не берите знаменатель
		for (i = n; i >= 0; i--)
			printf("%d", A[i]);
	}
	else
		printf("Невозможен перевод в целое так как знаменатель не равен 1");//Если знаменатель  - не единица
	printf("\n");
}

void SUB_NN_N(int n1, int n2, int *A1, int *A2, int D, int *n6, int **A6)
// Диана Щебет, группа 7307
///"Вычитание из первого большего натурального числа второго меньшего или равного"
{
	int i, j, *A4;
	A4 = (int*)malloc(n1 * sizeof(int));
	//int m=0;
	switch (D)
	{
		///первое число больше второго
	case 2:
	{
		for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (A1[i]<A2[j]) ///вычитание столбиком
			{
				A1[i] += 10;
				A1[i - 1] += -1;
			}
			A4[i] = A1[i] - A2[j];
			(*n6)++;
		}
		i = (*n6) + 1;

		for (i = 0; i<(n1 - n2); i++) ///запись в массив элементов, не вошедших в прошлый цикл, если числа разной длины
			A4[i] = A1[i];
		(*n6) += (i - 1);

		while (A4[0] == 0 && n1 > 0) ///перестановка элементов массива с целью убрать 0 перед полученным результатом
		{
			for (i = 0, (*n6) = 0; i<(n1 - 1); i++)
			{
				A4[i] = A4[i + 1];
				(*n6)++;

			}
			n1 += -1;
		}
		*n6 = *n6 + 1;

		(*A6) = (int*)malloc(sizeof(int)*(*n6));
		for (i = 0; i<(*n6); i++) ///заполнение массива данными
		{
			(*A6)[i] = A4[i];
		}
		break;
	}
	///числа равны
	case 0:
	{
		(*A6) = (int*)malloc(sizeof(int) * 1);
		(*A6)[0] = 0;

		break;
	}
	///первое меньше второго
	case 1:
	{
		printf("\nОшибка! Неправильный ввод!\n");
		(*n6) = -1;
		break;
	}

	}
	free(A4);

}

void SUB_NDN_N(int *answer, int *A1, int n1, int n4, int D, int **A5, int *n5) 
// Евгений Сысенко, группа 7307
///вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом.
{
	int *A6 = NULL, n6 = 1, i;
	if ((D == 2) || (D == 0))
	{
		SUB_NN_N(n1, n4, A1, answer, D, &n6, &A6);
		(*n5) = n6;
		(*A5) = (int*)malloc(sizeof(int)*(*n5));
		for (i = 0; i<n6; i++)
			(*A5)[i] = A6[i];
	}
	else
	{
		printf("Ошибка!");
		(*n5) = -1;
	}

	free(A6);
}

int POZ_Z_D(int sign, int sum, int *arr) {
// Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)
// sign - знак, sum = номер старшей позиции, arr - массив цифр числа
// Александр Трифонов, группа 7301
	if (sign == 1) {//если изначально аргумент знака равен единицы то число отрицательное - возвращаем 1(число отрицательное)
		return 1;
	}
	else {
		if (arr[0] == 0) {//если изначально аргумент знака не равен единицы то число отрицательное или равно 0, если первое число в массиве равно 0  - возвращаем 0(число равно 0)
			return 0;
		}
		else {			//если первое число в массиве не равно 0  - возвращаем 2(число положительное)
			return 2;
		}
	}
}

void MUL_ZM_Z(int *sign, int sum, int *arr) 
// Александр Трифонов, группа 7301
//в функцию передаються массив цифр числа через указатель, колличество цифр в числе минус 1, указател на знак числа(0 - положительное или ноль, 1 - отрицателное)
{
	if (*sign == 1) {//если изначально аргумент знака равен единицы то число отрицательное и при умножении получаем положительное число
		cout << "После умножения на (-1) числа получаем: ";
		for (int i = 0; i <= sum; i++) {
			cout << arr[i];
		}
		*sign = 0;
		cout << "\n";
	}
	else {
		if (arr[0] == 0) {//если изначально аргумент знака не равен единицы то число gложительное или равно 0, если первое число в массиве равно 0  - число равно 0 и при умножении на (-1) получаем 0
			cout << "После умножения на (-1) получаем: ";
			for (int i = 0; i < sum; i++) {
				cout << arr[i];
			}
			cout << "\n";
		}
		else {			//если первое число в массиве не равно 0  - число положительное и при умножении на (-1) получаем отрицательное число
			cout << "После умножения на (-1) получаем: -";
			for (int i = 0; i <= sum; i++) {
				cout << arr[i];
			}
			*sign = 1;
			cout << "\n";
		}
	}
}

int TRANS_N_Z(int b, int n, int *A){
//Стас Смирнов, группа 7301
	if ((b != 0) || (A[0] == 0)){
		return 2;
	}
	else return b;
}

int TRANS_Z_N(int b, int n, int *A){
	//Стас Смирнов, группа 7301
	if (b == 1)
		return -1;
	else if (A[0] == 0)
		return -2;
	else 
		return *A;
}

int ADD_1N_N(int m, int *A)
// Дмитрий Богряков, группа 7307
// возвращает номер старшей позиции (размер_массива-1)
// !эта функция может изменить размер массива (прибавить к размеру единицу)
{
	int i;
	for (i = m; i>0; i--) //для случая когда в числе есть хотя бы одна НЕ 9
	{
		if (A[i]<9)
		{
			A[i]++; //прибавление единицы
			i = -1;   //выход из цикла
		}
		else
		{
			A[i - 1]++;
			A[i] = 0;
		}
	}
	if (A[0] == 10) //случай, когда было введено значение, состоящее только из девяток
	{
		A = (int*)realloc(A, (m + 2) * sizeof(int));
		if (!A)  //проверка на выделение памяти
		{
			printf("Allocation error.");
			exit(1);
		}
		A[0] = 1; //первый элемент единица, остальные-нули
		for (i = 1; i<m + 2; i++) //заполнение остальных элементов нулями
		{
			A[i] = 0;
		}
		m++;
	}
	return m;
}

void DIV_NN_Dk(int n1, int n2, int *A1, int *A2, int D, int **A11, int *n11)
///"Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)"
// Диана Щебет, группа 7307
{
	int *A6 = NULL, n6 = 1, i, k = 0, m = 0, *A10 = NULL, n10 = 1, F, *A3 = NULL, n3 = 1;
	A3 = (int*)malloc(n1*sizeof(int));
	for (i = 0; i<n1; i++)
		A3[i] = A1[i];
	n3 = n1;
	if (D == 2)
	{
		F = COM_NN_D(n2, n2, A1, A2); ///сравнение цифр по длине 2 числа 

		if ((F == 2) || (F == 0)) ///поиск разряда цифры 
			k = n3 - n2;
		else
			k = n3 - n2 - 1;

		MUL_Nk_N(n2, A2, k, &A10, &n10); ///умножение цифры на 10^k 

		F = COM_NN_D(n3, n10, A3, A10);


		while (F != 1) ///цикл со счетчиком искомой цифры 
		{
			SUB_NN_N(n3, n10, A3, A10, F, &n6, &A6);
			m++;
			F = COM_NN_D(n6, n10, A6, A10);

			n3 = n6; ///необходимые перемещения массивов, чтобы функция вычитания работала в цикле 
			A3 = (int*)realloc(A3, n3*sizeof(int));
			for (i = 0; i<n3; i++)
				A3[i] = A6[i];
			n6 = 1;
			A6 = (int*)realloc(A6, n6*sizeof(int));
			A6[0] = 0;
		}
		(*n11) = 1;
		(*A11) = (int*)malloc(sizeof(int)*(*n11));
		(*A11)[0] = m;
	}
	else
	{
		printf("\nОшибка!");

	}
	free(A10);
	free(A6);
	free(A3);
}

void ADD_NN_N(int n1, int n2, int &resultN, int *first, int *second, int * &result)
// Диана Щебет, группа 7307
{
	int sum, i;
	bool extraNum = false; 

	if (n1 > n2)
		resultN = n1;
	else
		resultN = n2;

	n2--; // Так надо
	n1--;
	result = NULL;

	result = (int*)realloc(result, (resultN + 1) * sizeof(int));

	

	if (n1 > n2) // Заполнение нулями и остальными цифрами
	{
		for (int i = 0; i < (n1 - n2); i++)
			*(result + i) = *(first + i);

		for (int i = (n1 - n2); i <= n1; i++)
			*(result + i) = 0;
	}
	else
	{
		for (int i = 0; i < (n2 - n1); i++)
			*(result + i) = *(second + i);


		for (int i = (n2 - n1); i <= n2; i++)
			*(result + i) = 0;

	}

	if (n1 > n2) // Сам подсчёт
	{
		for (i = n1; i >= (n1 - n2); i--)
		{
			if (extraNum)
			{
				sum = 1;
				extraNum = false;
			}
			else
				sum = 0;

			sum += *(first + i) + *(second + i - (n1 - n2));
			if (sum > 9)
			{
				sum %= 10;
				extraNum = true;
			}

			*(result + i) = *(result + i) + sum;
		}
		if (extraNum && (i == -1))
		{
			for (int i = resultN; i >= 1; i--)
				*(result + i) = *(result + (i - 1));
			resultN++;
			*(result) = 1;
		}
		else if (extraNum)
		{
			*(result + i) = *(result + i) + 1;
		}
	}
	else
	{
		for (i = n2; i >= (n2 - n1); i--)
		{
			if (extraNum)
			{
				sum = 1;
				extraNum = false;
			}
			else
				sum = 0;

			sum += *(second + i) + *(first + i - (n2 - n1));
			if (sum > 9)
			{
				sum %= 10;
				extraNum = true;
			}

			*(result + i) = *(result + i) + sum;
		}
		if (extraNum && (i == -1))
		{
			for (int i = resultN; i >= 1; i--)
				*(result + i) = *(result + (i - 1));
			resultN++;
			*(result) = 1;
		}
		else if (extraNum)
		{
			*(result + i) = *(result + i) + 1;
		}
	}
}

int INT_Q_B(int b, int n, int *A, int n1, int *A1)
// Рустам Аминов, группа 7307
{
	int first = 0, second = 0;
	for (int i = 0; i <= n; i++)
	{
		first += *(A + i);
		first *= 10;
	}
	for (int i = 0; i <= n1; i++)
	{
		second += *(A1 + i);
		second *= 10;
	}

	if (first % second == 0)
		return 1;
	else
		return 0;
}

int TRANS_Z_Q(int b, int n, int *A, int n1, int *A1)
//Стас Смирнов, группа 7301
{
	A1[0] = 1;//знаменатель становится равным единице
	n1 = 1;
	return *A1;
}

void MUL_NN_N(int n0, int n1, int *A0, int *A1, int &nresult, int * &result)
//Максим Кортель, группа 7301
//Использование: MUL_NN_N(n0, n1, A0, A1, &nresult, &result)
//               n1 - количество цифр в первом числе
//               n2 - количество цифр во втором числе
//               A0 - массив цифр первого числа (где нулевой элемент - это высший разряд)
//               А1 - массив цифр второго числа (где нулевой элемент - это высший разряд)
//               nresult - сюда будет записано количество цифр числа-результата
//               result - это будет массив цифр числа-результата (где нулевой элемент - это высший разрдяд)
//Изначально значение nresult неважно, а result обязан иметь значение NULL или nullptr во избежание проблем с утечкой памяти.
{
	int i, j;
	int *tmp = NULL, ntmp = 0;
	int *add = NULL, nadd = 0;
	int ntemp = 1, *temp;
	int ntmpresult = 0, *tmpresult = NULL;

	temp = (int*)malloc(sizeof(int));
	temp[ntemp] = 0;

	for (i = 0; i<n1; i++)
	{
		MUL_ND_N(n0, A1[i], A0, &ntmp, &tmp);
		MUL_Nk_N(ntmp, tmp, n1 - i, &add, &nadd);
		ADD_NN_N(ntemp, nadd, ntmpresult, temp, add, tmpresult);
		ntemp = ntmpresult;
		temp = (int*)realloc(temp, (ntemp)*sizeof(int));
		for (j = 0; j<ntemp; j++)
			temp[j] = tmpresult[j];

		tmpresult = NULL; ntmpresult = 0;
		add = NULL; nadd = 0;
		ntmp = 0; tmp = NULL;
	}

	ntemp--;
	while ((*(temp) == 0) && (ntemp > 1))
	{
		*(temp) = *(temp + 1);
		ntemp--;
	}

	nresult = ntemp;
	result = (int*)malloc(sizeof(int)*(ntemp));
	for (i = 0; i < ntemp; i++)
		(result[i]) = temp[i];

	free(tmp);
	free(add);
	free(tmpresult);
}

void MUL_ZZ_Z(int sizeFirst, int sizeSecond, int *first, int *second, int markFirst, int markSecond, int &sizeResult, int * &result, int &markResult)
// Максим Кортель, группа 7301
{
	int isPositiveFirst, isPositiveSecond;
	markResult = 1;
	MUL_NN_N(sizeFirst, sizeSecond, first, second, sizeResult, result);

	isPositiveFirst = POZ_Z_D(markFirst, sizeFirst, first);
	isPositiveSecond = POZ_Z_D(markSecond, sizeSecond, second);

	if (isPositiveFirst == isPositiveSecond)
		ABS_Z_N(markResult, sizeResult, result);
}

void DER_PP_P(int m, int *C)
{
	int i, j = 0;
	for (i = 0; i <= 2 * m + 1; i = i + 2)
	{
		printf("Числитель: %d, знаменатель: %d", C[i] * j, C[i + 1]);
		j++;
	}
}

void ADD_ZZ_Z(int *sum1, int *arr1, int *sign1, int *sum2, int *arr2, int *sign2, int *sum3, int *&arr3, int *sign3) {
	int D = 2;
	if (*sign1 == *sign2) {//если знаки у чисел одинаковые - складываем модули чисел и задаем знак нашей суммы равным знакам слагаемых
		ADD_NN_N((*sum1), (*sum2), (*sum3), arr1, arr2, *&arr3);
		*sign3 = *sign1;
		*sum3 = *sum3;
	}
	else {
		if (POZ_Z_D(*sign1, *sum1, arr1) == 2 || POZ_Z_D(*sign1, *sum1, arr1) == 0) {//если знаки не равны, то мы определяем какое из чисел по модулю больше, отрицательное или положительное, если отрицательное больше то мы вычитаем из отрицательного положительное по модулю и присваеваем нашей сумме знак минус
			if (COM_NN_D((*sum1), (*sum2), arr1, arr2) == 2 || COM_NN_D(*sum1, *sum2, arr1, arr2) == 0) {//если положительное больше то вычитаем из положительного отрицательное и присваиваем нашей сцмме знак плюс
				*sign3 = 0;
				SUB_NN_N((*sum1), (*sum2), arr1, arr2, D, sum3, &arr3);

			}
			else {
				*sign3 = 1;
				SUB_NN_N((*sum2), (*sum1), arr2, arr1, D, sum3, &arr3);
			}

		}
		if (POZ_Z_D(*sign2, *sum2, arr2) == 2 || POZ_Z_D(*sign2, *sum2, arr2) == 0) {
			if (COM_NN_D((*sum2), (*sum1), arr2, arr1) == 2 || COM_NN_D(*sum2, *sum1, arr2, arr1) == 0) {
				*sign3 = 0;
				cout << "аранво";
				SUB_NN_N((*sum2), (*sum1), arr2, arr1, D, sum3, &arr3);

			}
			else {
				cout << "cducd";
				*sign3 = 1;
				SUB_NN_N((*sum1), (*sum2), arr1, arr2, D, sum3, &arr3);
			}

		}
	}
}

void SUB_ZZ_Z(int *sum1, int *arr1, int *sign1, int *sum2, int *arr2, int *sign2, int *sum3, int *&arr3, int *sign3) {
	int D = 2;
	//if (COM_NN_D(*sum1, *sum2, arr1, arr2) == 2 || COM_NN_D(*sum1, *sum2, arr1, arr2) == 0) {//выясняем какой размер массива нам нужен для суммы чисел и выбираем максимальнуюиз них
	//	*sum3 = *sum1;
	//}
	//else {
	//	*sum3 = *sum2;
	//}
	//int *arr3 = new int[*sum3 + 2];//создаем массив
	if (*sign1 != *sign2) {//если знаки у чисел разные - складываем модули чисел и задаем знак нашей суммы равным знаку первого
		if (*sign2 == 1) {
			ADD_NN_N((*sum1), (*sum2), (*sum3), arr1, arr2, *&arr3);
			*sign3 = 0;
		}
		else {
			ADD_NN_N((*sum1), (*sum2), (*sum3), arr1, arr2, *&arr3);
			*sign3 = 1;

		}
		//ADD_NN_N( (*sum1), (*sum2), (*sum3), arr1,  arr2, *&arr3);
		//*sign3 = *sign1;
	}
	else {
		if (POZ_Z_D(*sign1, *sum1, arr1) == 2 || POZ_Z_D(*sign1, *sum1, arr1) == 0) {//если знаки равны то определяем какого знака числа, далее выясняем какое из них по модулю больше 
			if (COM_NN_D((*sum1), (*sum2), arr1, arr2) == 2 || COM_NN_D((*sum1), (*sum2), arr1, arr2) == 0) {//и в зависимости от этого складываем или вычитаем модули чисел и задаем нужный знак
				*sign3 = 0;
				SUB_NN_N((*sum1), (*sum2), arr1, arr2, D, sum3, &arr3);
				//первое больше нуля или равно 0, второе больше нуля
			}													//первое больше - вычитаем из превого второе и задаем знак +
			else {												//и наоборот второе больше первого - вычитаем из второго первое и знак -
				*sign3 = 1;
				SUB_NN_N((*sum2), (*sum1), arr2, arr1, D, sum3, &arr3);
			}

		}
		if (POZ_Z_D(*sign2, *sum2, arr2) == 1) {
			if (COM_NN_D((*sum2), (*sum1), arr2, arr1) == 2 || COM_NN_D((*sum2), (*sum1), arr2, arr1) == 0) {
				*sign3 = 0;
				SUB_NN_N((*sum2), (*sum1), arr2, arr1, D, sum3, &arr3);
			}													//первое и второе меньше нуля
			else {												//первое больше - вычитаем из превого второе и задаем знак -
				*sign3 = 1;										//и наоборот второе больше первого - вычитаем из второго первое и знак +
				SUB_NN_N((*sum1), (*sum2), arr1, arr2, D, sum3, &arr3);
			}

		}
	}
}


/// Рустам Аминов, група 7307
/////////////////////////
struct FLOAT //Дробь в виде структуры
{
	int b; //Знак дроби
	int n, n1; //Количество цифр в числителе и знаменателе
	int *A, *A1; //Цифры числителя и знаменателя
};
//Xmax - Старший коэффициент; str3 - массив СТРУКТУР с коэффициентами многочлена; k - Число, на которе умножаем.
//b - знак; n, n1 - номера старших разрядов; А, А1 - цифры, входящие в числитель и знаменатель.
struct FLOAT *MUL_Pxk_P(int Xmax, struct FLOAT *str3, int k) ///Умножение многочлена на x^k
{
	int i;
	struct FLOAT *str4;
	str4 = (struct FLOAT*)malloc((Xmax + 1 + k)*sizeof(struct FLOAT)); //Создание массива результата на k больше исходного
	for (i = Xmax + k; i >= k; i--) //Копирование исходного массива в результирующий со сдвигом коэффициентов на k в сторону старшего
	{
		str4[i].A = (int*)malloc((sizeof(str3[i].A)));
		str4[i].A1 = (int*)malloc((sizeof(str3[i].A1)));
		str4[i] = str3[i - k];
	}
	for (i = k - 1; i >= 0; i--) //Инициализация нулями пустых ячеек массива
	{
		str4[i].b = 0;
		str4[i].n = 0;
		str4[i].n1 = 0;
		str4[i].A = (int*)malloc((sizeof(int)));
		str4[i].A[0] = 0;
		str4[i].A1 = (int*)malloc((sizeof(int)));
		str4[i].A1[0] = 1;
	}
	return str4; //Вывод указателя на результирующий массив
};
void scan_float(struct FLOAT *str2, int i)//Считывание с клавиатуры одной дроби (и запись в СТРУКТУРУ)
{
	int x, j;
	str2[i].b = 0; //Инициализация
	str2[i].n = -1;
	str2[i].n1 = -1;
	printf("Введите числитель коэффициента при х^%d: ", i);
	scanf_s("%d", &x);
	if (x<0)               //определение знака
	{
		str2[i].b = 1;
		x = -x;
	}
	str2[i].A = (int*)malloc((str2[i].n + 1)*sizeof(int));
	for (j = 0; x>0; j++)      //Запись числителя в массив
	{
		str2[i].n++;
		str2[i].A = (int*)realloc(str2[i].A, (str2[i].n + 1)*sizeof(int));
		str2[i].A[j] = x % 10;
		x = x / 10;
	}
	printf("Введите знаменатель коэффициента при х^%d: ", i);
	scanf_s("%d", &x);
	str2[i].A1 = (int*)malloc((str2[i].n1 + 1)*sizeof(int));
	for (j = 0; x>0; j++)     //Запись знаменателя в массив
	{
		str2[i].n1++;
		str2[i].A1 = (int*)realloc(str2[i].A1, (str2[i].n1 + 1)*sizeof(int));
		str2[i].A1[j] = x % 10;
		x = x / 10;
	}
}
void print_result(struct FLOAT *str4, int max) //Вывод результата на экран.
{
	int i, j;
	printf("Результат умножения:\n");
	for (i = max; i >= 0; i--)
	{
		if (str4[i].b == 1) //Вывод знака коэффициента
		{
			printf(" - ");
		}
		else
		{
			printf(" + ");
		}

		for (j = str4[i].n; j >= 0; j--) //Вывод числителя
		{
			printf("%d", str4[i].A[j]);
		}
		printf("/");
		for (j = str4[i].n1; j >= 0; j--) //Вывод знаменателя
		{
			printf("%d", str4[i].A1[j]);
		}
		printf(" x^%d", i);
	}
}
/* void p_4(void) //Ввод многочлена с клавиатуры
{
	int i, Xmax, k, Xmax1; //Xmax - старший член, Xmax1 - старший член после алгоритма
	printf("Введите старшую степень многочлена: ");
	scanf("%d", &Xmax);
	printf("Введите желаемую степень k, чтобы умножить многочлен на х^k : ");
	scanf("%d", &k);       //Степень k, на которую умножается многочлен

	struct FLOAT str1[Xmax + 1], *u; //Массив коэффициентов и указатель на результат

	for (i = Xmax; i >= 0; i--)
	{
		scan_float(str1, i);//Ввод с клавиатуры всех коэффициентов и запись их в массив
	}


	u = MUL_Pxk_P(Xmax, str1, k);//умножение многочлена на x^k (сама функция)
	Xmax1 = Xmax + k; //Изменение старшего коэффициента
	print_result(u, Xmax1); //вывод результата на экран


	for (i = Xmax; i >= 0; i--) //Очистка памяти
	{
		free(str1[i].A);
		free(str1[i].A1);
	}
	for (i = Xmax1; i >= 0; i--) //Очистка созданного нового массива
	{
		free(u[i].A);
		free(u[i].A1);
	}
	free(u);
} */
////////////////////////

void MUL_QQ_Q(int b, int n0, int n1, int *A0, int *A1, int b_1, int n0_1, int n1_1, int *A0_1, int *A1_1, int &b_result, int &n0_result, int &n1_result, int *&A0_result, int *&A1_result)
///выполнила Волкова Анна, гр.7307
//умножение дробей
// первая дробь: n0 -разряд числителя, n1 - разряд знаменателя, A0 - массив числителя, A1 - массив знаменателя;
//аналогично n0_1 и т.д. для второй дроби
//(_result) - аналогично - результат
{
	MUL_ZZ_Z(n0, n0_1, A0, A0_1, b, b_1, n0_result, A0_result, b_result);
	MUL_NN_N(n1, n1_1, A1, A1_1, n1_result, A1_result); //используем эту функцию, так как знаменатель - натуральное число
	//можно добавить функцию сокращения дроби
}

void DIV_QQ_Q(int b, int n0, int n1, int *A0, int *A1, int b_1, int n0_1, int n1_1, int *A0_1, int *A1_1, int &b0_result, int &b1_result, int &n0_result, int &n1_result, int * &A0_result, int * &A1_result)
///выполнила Волкова Анна, гр.7307
//умножение дробей
// первая дробь: n0 -разряд числителя, n1 - разряд знаменателя, A0 - массив числителя, A1 - массив знаменателя;
//аналогично n0_1 и т.д. для второй дроби
//(_result) - аналогично - результат
{
	MUL_ZZ_Z(n0, n1_1, A0, A1_1, b, 0, n0_result, A0_result, b0_result);
	MUL_ZZ_Z(n1, n0_1, A1, A0_1, 0, b_1, n1_result, A1_result, b1_result);//используем эту функцию, так как знаменатель - натуральное число
	//можно добавить функцию сокращения дроби
}

/* void DIV_ZZ_Z(int sizeFirst, int sizeSecond, int *first, int *second, int markFirst, int markSecond, int &sizeResult, int * &result, int &markResult)
// Максим Кортель, группа 7301
{
	int isPositiveFirst, isPositiveSecond;
	markResult = 1;
	DIV_NN_N(sizeFirst, sizeSecond, first, second, sizeResult, result);

	isPositiveFirst = POZ_Z_D(markFirst, sizeFirst, first);
	isPositiveSecond = POZ_Z_D(markSecond, sizeSecond, second);

	if (isPositiveFirst == isPositiveSecond)
		ABS_Z_N(markResult, sizeResult, result);
} */

void naturalNum() // Модуль, в котором идут операции с натуральными числами 
{
	string module[14] = {"1. Сравнение натуральных чисел ",
						 "2. Проверка на ноль", 
						 "3. Добавление 1",
						 "4. Сложение натуральных чисел", 
						 "5. Вычитание из первого большего натурального...",
						 "6. Умножение натурального числа на цифру",
						 "7. Умножение натурального числа на 10^k",
						 "8. Умножение натуральных чисел",
						 "9. Вычитание из натурального другого натурального...",
						 "10. Вычисление первой цифры деления большего...",
						 "11*. Частное от деления большего натурального числа...",
						 "12*. Остаток от деления большего натурального числа...",
						 "13*. НОД натуральных чисел",
						 "14*. НОК натуральных чисел"};

	// Переменные для выбора пункта
	int index = 0, tmp, prevIndex = -1;

	// Переменные для кейсов
	int n0, n1, n2, n4, n5, n6, n10, n11, k, D, dig, m, nresult,
		*A = NULL,
		*A0 = NULL, 
		*A1 = NULL,
		*A2 = NULL,
		*A3 = NULL,
		*A5 = NULL,
		*A6 = NULL,
		*A10 = NULL,
		*A11 = NULL, 
		*answer = NULL,
		*result = NULL, 
		n3 = 0;

	do
	{
		if (prevIndex != index)
		{
			prevIndex = index;
			system("cls");
			puts("Звёздочка, идущая после цифры, обозначает недоступность данной функции.");
			puts("Внимание! Троеточие означает, что полный текст задания не поместился.\n"
				"Для прочтения полного текста выберите соответствующий пункт меню.\n"
				"Выберите функцию, которую хотите запустить:\n");

			for (int i = 0; i < 14; i++)
			{
				if (i != index)
					cout << " " << module[i] << "\n";
				else
					cout << ">" << module[i] << "\n";
			}

			puts("\nДля возврата в прошлое меню нажмите Esc.");
		}

		tmp = _getch();
		switch (tmp)
		{
			case 72:
				if (index > 0)
					index--;
				break;

			case 80:
				if (index < 13)
					index++;
				break;

			case 13:
				prevIndex = -1;

				system("cls");
				switch (index)
				{
					case 0:
						// Диана Щебет, группа 7307
						//ввод количества цифр в числах
						puts("Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.\n");
						printf("Введите количество цифр в первом числе: ");
						scanf_s("%d", &n1);

						printf("Введите количество цифр во втором числе: ");
						scanf_s("%d", &n2);
						A1 = (int*)realloc(A1, (n1 + 1) * sizeof(int));
						A2 = (int*)realloc(A1, (n2 + 1) * sizeof(int));
						for (int i = 0; i<n1; i++)
						{
							printf("A1[%d] = ", i);
							scanf_s("%d", &A1[i]);
						}

						for (int i = 0; i<n2; i++)
						{
							printf("A2[%d] = ", i);
							scanf_s("%d", &A2[i]);
						}

						D = COM_NN_D(n1, n2, A1, A2);
						printf("\nРезультат сравнения = %d\n", D);
						system("pause");
						break;

					case 1:
						// Евгений Сысенко, группа 7307
						//ввод количества цифр в числах
						puts("Проверка на ноль: если число не равно нулю, то «да» иначе «нет»");
						printf("Введите количество цифр в числе: ");
						scanf_s("%d", &n1);

						A1 = (int*) realloc (A1, (n1 + 1) * sizeof(int));
						//ввод чисел через Enter
						for (int i = 0; i<n1; i++)
						{
							printf("a[%d] = ", i);
							scanf_s("%d", &A1[i]);
						}
						D = NZER_N_B(n1, A1);
						printf("Результат = %d", D);
						puts("");
						system("pause");
						break;

					case 2:
						// Дмитрий Богряков, группа 7301
						// m - номер старшей позиции (размер_массива)
						// *A - указатель на начало массива цифр
						// i -переменная для цикла
						puts("Добавление 1 к натуральному числу");
						printf("Введите номер старшей позиции (количество цифр): ");
						scanf_s("%d", &m);
						--m;
						A = (int*)malloc((m + 1) * sizeof(int));//выделение памяти под массив
						printf("Введите массив цифр:\n");
						for (int i = 0; i<m + 1; i++)
						{
							printf("A[%d] = ", i);
							scanf_s("%d", &A[i]);
							if ((A[i]>9) || (A[i]<0)) //проверка на юзверя
							{
								printf("%d- не цифра, это число. Введите значение повторно.\n", A[i]);
								i--;
							}
						}

						m = ADD_1N_N(m, A);

						printf("Полученное число: ");
						for (int i = 0; i<m + 1; i++)
						{
							printf("%d", A[i]);
						}
						printf("\n");

						free(A);
						puts("");
						system("pause");
						break;

					case 3:
						// Диана Щебет, группа 7307
						//ввод количества цифр в числах
						puts("Сложение натуральных чисел");
						n5 = 1;
						printf("Введите количество цифр в первом числе: ");
						scanf_s("%d", &n1);

						printf("Введите количество цифр во втором числе: ");
						scanf_s("%d", &n2);

						A1 = (int*)malloc(n1*sizeof(int));
						A2 = (int*)malloc(n2*sizeof(int));
						//ввод чисел через Enter
						for (int i = 0; i<n1; i++)
						{
							printf("A1[%d] = ", i);
							scanf_s("%d", &A1[i]);
						}

						for (int i = 0; i<n2; i++)
						{
							printf("A2[%d] = ", i);
							scanf_s("%d", &A2[i]);
						}
						// system ("cls");
						ADD_NN_N(n1, n2, n5, A1, A2, A5);
						printf("\nОтвет: ");
						for (int i = 0; i<n5; i++)
							printf("%d", A5[i]);

						free(A1);
						free(A2);
						free(A5);

						puts("");
						system("pause");
						break;

					case 4:
						// Диана Щебет, группа 7307
						// ввод количества цифр в числах
						n3 = 1;
						puts("Вычитание из первого большего натурального числа второго меньшего или равного");
						printf("Введите количество цифр в первом числе: ");
						scanf_s("%d", &n1);

						printf("Введите количество цифр во втором числе: ");
						scanf_s("%d", &n2);

						A1 = (int*)realloc(A1, (n1 + 1) * sizeof(int));
						A2 = (int*)realloc(A2, (n2 + 1) * sizeof(int));
						//ввод чисел через Enter
						for (int i = 0; i<n1; i++)
						{
							printf("A1[%d] = ", i);
							scanf_s("%d", &A1[i]);
						}

						for (int i = 0; i<n2; i++)
						{
							printf("A2[%d] = ", i);
							scanf_s("%d", &A2[i]);
						}

						D = COM_NN_D(n1, n2, A1, A2);
						//  printf("Comparison result= %d\n", D);
						SUB_NN_N(n1, n2, A1, A2, D, &n3, &A3);
						printf("\nОтвет: ");
						for(int i=0;i<n3;i++)
						{
							printf("%d",A3[i]);
							// printf("%d\n",n3);
						}
						puts("");
						free(A1);
						free(A2);
						free(A3);
						system("pause");
						break;

					case 5:
						// Евгений Сысенко, группа 7307
						//ввод количества цифр в числах
						puts("Умножение натурального числа на цифру");
						printf("Введите количество цифр в первом числе: ");
						scanf_s("%d", &n1);
						A1 = (int*)malloc(sizeof(int)*n1);
						//ввод чисел через Enter
						for (int i = 0; i<n1; i++)
						{
							printf("A1[%d] = ", i);
							scanf_s("%d", &A1[i]);
						}
						printf("Введите цифру: ");
						scanf_s("%d", &dig);
						MUL_ND_N(n1, dig, A1, &n3, &answer);
						printf("Ответ: ");
						for (int i = 0; i<n3; i++)
							printf("%d", answer[i]);
						puts("");
						free(A1);
						free(answer);
						system("pause");
						break;

					case 6:
						// Диана Щебет, группа 7307
						//ввод количества цифр в числах
						puts("Умножение натурального числа на 10^k");
						printf("Введите количество цифр в числе: ");
						scanf_s("%d", &n1);

						A1 = (int*)realloc(A1, (n1 + 1) * sizeof(int));
						//ввод чисел через Enter
						for (int i = 0; i<n1; i++)
						{
							printf("A1[%d] = ", i);
							scanf_s("%d", &A1[i]);
						}

						cout << "Введите степень k: ";
						cin >> k;
						n10 = 1;
						MUL_Nk_N(n1, A1, k, &A10, &n10);
						puts("");
						cout << "Ответ: ";
						for (int i = 0; i < n10; i++)
							cout << *(A10 + i);

						puts("");
						system("pause");
						break;

					case 7:
						// Максим кортель, группа 7301
						puts("Умножение натуральных чисел");
						cout << "Введите количество цифр в первом числе: ";
						cin >> n0;

						cout << "Введите количество цифр во втором числе: ";
						cin >> n1;

						A0 = (int*)realloc(A0, (n0 + 1) * sizeof(int)); 
						A1 = (int*)realloc(A1, (n1 + 1) * sizeof(int));

						for (int i = 0; i < n0; i++)
						{
							cout << "A0[" << i << "] = ";
							cin >> *(A0 + i);
						}

						for (int i = 0; i < n1; i++)
						{
							cout << "A1[" << i << "] = ";
							cin >> *(A1 + i);
						}

						MUL_NN_N(n0, n1, A0, A1, nresult, result);

						cout << "Ответ: ";
						for (int i = 0; i < nresult; i++)
							cout << *(result + i);

						puts("");
						system("pause");
						break;

					case 8:
						// Евгений Сысенко, группа 7307
						//ввод количества цифр в числах
						n3 = 1;
						n4 = 0;
						n5 = 1;
						puts("Вычитание из натурального другого натурального, умноженного на цифру для случая с	неотрицательным результатом");
						printf("Введите количество цифр в первом числе: ");
						scanf_s("%d", &n1);

						printf("Введите количество цифр во втором числе: ");
						scanf_s("%d", &n2);

						A1 = (int*)malloc(n1*sizeof(int));
						A2 = (int*)malloc(n2*sizeof(int));
						//ввод чисел через Enter
						for (int i = 0; i<n1; i++)
						{
							printf("A1[%d] = ", i);
							scanf_s("%d", &A1[i]);
						}

						for (int i = 0; i<n2; i++)
						{
							printf("A2[%d] = ", i);
							scanf_s("%d", &A2[i]);
						}
						printf("Введите цифру: ");
						scanf_s("%d", &dig);

						D = COM_NN_D(n1, n2, A1, A2);
						MUL_ND_N(n2, dig, A2, &n4, &answer);
						SUB_NDN_N(answer, A1, n1, n4, D, &A5, &n5);

						printf("Ответ: ");

						for (int i = 0; i<n5; i++)
						{
							printf("%d", A5[i]);
						}

						free(A1);
						free(A2);
						free(answer);
						free(A5);

						puts("");
						system("pause");
						break;

					case 9:
						// Диана Щебет, группа 7307
						n6 = 1; 
						n11 = 1;
						puts("Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10 ^ k, \n" 
							 "где k - номер позиции этой цифры(номер считается с нуля)");

						//ввод количества цифр в числах
						printf("Введите количество цифр в первом числе: ");
						scanf_s("%d", &n1);

						printf("Введите количество цифр во втором числе: ");
						scanf_s("%d", &n2);

						A1 = (int*)malloc(n1*sizeof(int));
						A2 = (int*)malloc(n2*sizeof(int));

						//ввод чисел через Enter
						for (int i = 0; i<n1; i++)
						{
							printf("A1[%d] = ", i);
							scanf_s("%d", &A1[i]);
						}

						for (int i = 0; i<n2; i++)
						{
							printf("A2[%d] = ", i);
							scanf_s("%d", &A2[i]);
						}

						D = COM_NN_D(n1, n2, A1, A2);

						DIV_NN_Dk(n1, n2, A1, A2, D, &A11, &n11);
						if (A11 != NULL)
						{
							printf("\nОтвет = ");
							printf("%d", A11[0]);
						}
						else
						{
							printf("Ошибка!");
						}

						free(A1);
						free(A2);
						free(A6);
						free(A11);

						puts("");
						system("pause");
						break;

					case 10:

						break;

					case 11:
						break;

					case 12:
						break;

					case 13:
						break;

				}
				break;
		}
	} while (tmp != 27);
}

void totalNum() // Модуль, в котором идёт работа с целыми числами
{
	string module[10] = {"1. Абсолютная величина числа",
						 "2. Определение положительности числа...",
						 "3. Умножение целого на (-1)",
						 "4. Преобразование натурального в целое",
						 "5. Преобразование целого неотрицательного в натуральное",
						 "6. Сложение целых чисел",
						 "7. Вычитание целых чисел",
						 "8. Умножение целых чисел",
						 "9*. Частное от деления большего целого числа на меньшее...",
						 "10*. Остаток от деления большего целого числа на меньшее..."};

	// Переменные для выбора пункта
	int index = 0, tmp, prevIndex = -1;

	// Переменные для кейсов
	int *A = NULL, *arr = NULL, *first = NULL, *second = NULL, *result = NULL, *sum1 = NULL, *sum2 = NULL, *sum3 = NULL, *arr1 = NULL, *arr2 = NULL, *arr3 = NULL, *sign1, *sign2, *sign3,
		b = 0, n = 0, 
		t, sign, sum, t1, sign11, tmpCase, sizeFirst, sizeSecond, markFisrt, markSecond, sizeResult, markResult;



	do
	{
		if (prevIndex != index)
		{
			prevIndex = index;
			system("cls");
			puts("Звёздочка, идущая после цифры, обозначает недоступность данной функции.");
			puts("Внимание! Троеточие означает, что полный текст задания не поместился.\n"
				"Для прочтения полного текста выберите соответствующий пункт меню.\n"
				"Выберите функцию, которую хотите запустить:\n");

			for (int i = 0; i < 10; i++)
			{
				if (i != index)
					cout << " " << module[i] << "\n";
				else
					cout << ">" << module[i] << "\n";
			}

			puts("\nДля возврата в прошлое меню нажмите Esc.");
		}
		tmp = _getch();
		switch (tmp)
		{
			case 72:
				if (index > 0)
					index--;
				break;

			case 80:
				if (index < 9)
					index++;
				break;

			case 13:
				prevIndex = -1;

				system("cls");
				switch (index)
				{
				case 0:
					// Стас Смирнов, группа 7301
					puts("Абсолютная величина числа, результат - натуральное");
					cout << "Введите знак b (1 - минус, 0 - плюс): ";
					cin >> b;
					cout << "Введите цифр в числе: ";
					cin >> n;
					A = (int*)realloc(A, (n + 1) * sizeof(int));
					for (int i = 0; i < n; i++)
					{
						cout << "a[" << i + 1 << "] = ";
						cin >> *(A + i);
					}
					cout << "Полученное число: " << ABS_Z_N(b, n, A);
					puts("");
					system("pause");
					break;

				case 1:
					// Алекандр Трифонов, группа 7301
					puts("Определение положительности числа (2 - положительное,	0 — равное нулю, 1 - отрицательное)");
					cout << "Введите целое число: ";
					cin >> t;
					sum = 0;
					if (t < 0) {
						sign = 1;
						t = -t;
					}
					else {
						sign = 0;
					}
					t1 = t;
					while (t1 > 0) {
						t1 = t1 / 10;
						sum++;
					}
					t1 = t;
					if (t != 0) {
						sum = sum;
					}
					else {
						sum = sum + 1;
					}
					arr = new int[sum];
					if (t != 0) {
						sum = sum - 1;
					}
					for (int i = sum; i >= 0; i--) {
						arr[i] = t1 % 10;
						t1 = t1 / 10;
					}
					sign11 = POZ_Z_D(sign, sum, arr);
					cout << "\n";
					cout << "Знак числа: " << sign11;

					free(arr);
					system("pause");
					break;

				case 2:
					// Александр Трифонов, группа 7301
					puts("Умножение целого на (-1)");
					cout << "Введите целое число: ";
					cin >> t;
					sum = 0;
					if (t < 0) {
						sign = 1;
						t = -t;
					}
					else {
						sign = 0;
					}
					t1 = t;
					while (t1 > 0) {
						t1 = t1 / 10;
						sum++;
					}
					t1 = t;
					if (t != 0) {
						sum = sum;
					}
					else {
						sum = sum + 1;
					}
					arr = new int[sum];
					if (t != 0) {
						sum = sum - 1;
					}
					for (int i = sum; i >= 0; i--) {
						arr[i] = t1 % 10;
						t1 = t1 / 10;
					}

					MUL_ZM_Z(&sign, sum, arr);

					free(arr);
					system("pause");
					break;

				case 3:
					// Стас Смирнов, группа 7301
					puts("Перевод из натурального числа в целое, результат - знак числа");
					cout << "Введите знак b (1 - минус, 0 - плюс): ";
					cin >> b;
					cout << "Введите количество цифр в числе: ";
					cin >> n;
					A = (int*)realloc(A, (n + 1) * sizeof(int));
					for (int i = 0; i < n; i++)
					{
						cout << "a[" << i << "] = ";
						cin >> *(A + i);
					}
					if (TRANS_N_Z(b, n, A) == 2)
						cout << "Число введено некорректно, т.к. оно должно быть натуральным";
					else
					{
						cout << "Результат - знак числа: " << TRANS_N_Z(b, n, A);
						puts(" ");
						cout << "Число: ";
						for (int i = 0; i < n; i++)
							cout << A[i];
						cout << endl;
					}

					puts("");
					free(A);
					system("pause");
					break;

				case 4:
					// Стас Смирнов, группа 7301
					puts("Перевод из целого неотрицательного числа в натуральное, результат - натуральное число");
					cout << "Введите знак b (1 - минус, 0 - плюс): ";
					cin >> b;
					cout << "Введите цифр в числе: ";
					cin >> n;
					A = (int*)realloc(A, (n + 1) * sizeof(int));
					for (int i = 0; i < n; i++)
					{
						cout << "a[" << i << "] = ";
						cin >> *(A + i);
					}
					tmpCase = TRANS_Z_N(b, n, A);
					if (tmpCase == -1)
						cout << "Число введено некорректно, т.к. оно должно быть натуральным";
					if (tmpCase == -2)
						cout << "Число введено некорректно, т.к. число 0 нельзя перевести в натуральное";
					if ((tmpCase != -1) && (tmpCase != -2))
					{
						cout << "Результат - массив с цифрами и старшая степень: ";
						for (int i = 0; i < n; i++)
							cout << A[i];
						cout << endl;
						cout << "Степень числа - " << n << endl;
					}

					free(A);
					puts("");
					system("pause");
					break;

				case 5:
					// Александр Трифонов, группа 7301
					sum1 = (int*)malloc(1 * sizeof(int));
					sum2 = (int*)malloc(sizeof(int) * 1);
					sum3 = (int*)malloc(sizeof(int) * 1);
					sign1 = (int*)malloc(sizeof(int) * 1);
					sign2 = (int*)malloc(sizeof(int) * 1);
					sign3 = (int*)malloc(sizeof(int) * 1);
					*sum1 = 0;
					*sum2 = 0;
					*sum3 = 0;

					puts("Сложение целых чисел");
					cout << "Введите количество цифр в первом числе: ";
					cin >> *sum1;
					cout << "Введите количество цифр во втором числе: ";
					cin >> *sum2;
					arr1 = (int*)malloc(sizeof(int) * (*sum1));
					arr2 = (int*)malloc(sizeof(int) * (*sum2));
					arr3 = NULL;

					for (int i = 0; i < *sum1; i++) {
						cout << "A0[" << i << "] = ";
						cin >> arr1[i];
					}
					for (int i = 0; i < *sum2; i++) {
						cout << "A1[" << i << "] = ";
						cin >> arr2[i];
					}
					cout << "Введите знак первого числа (1 - минус, 0 - плюс): ";
					cin >> *sign1;
					cout << "Введите знак второго числа (1 - минус, 0 - плюс): ";
					cin >> *sign2;
					ADD_ZZ_Z(sum1, arr1, sign1, sum2, arr2, sign2, sum3, arr3, sign3);
					cout << "Результат: ";

					if (*sign3 == 1) {
						cout << "-";
					}
					for (int i = 0; i < (*sum3); i++) {
						cout << arr3[i];
					}

					cout << "\n\n";
					system("pause");
					break;

				case 6:
					// Александр Трифонов, группа 7301
					sum1 = (int*)malloc(1 * sizeof(int));
					sum2 = (int*)malloc(sizeof(int) * 1);
					sum3 = (int*)malloc(sizeof(int) * 1);
					sign1 = (int*)malloc(sizeof(int) * 1);
					sign2 = (int*)malloc(sizeof(int) * 1);
					sign3 = (int*)malloc(sizeof(int) * 1);
					*sum1 = 0;
					*sum2 = 0;
					*sum3 = 0;

					puts("Вычитание целых чисел");
					cout << "Введите количество цифр в первом числе: ";
					cin >> *sum1;
					cout << "Введите количество цифр во втором числе: ";
					cin >> *sum2;
					arr1 = (int*)malloc(sizeof(int) * (*sum1));
					arr2 = (int*)malloc(sizeof(int) * (*sum2));
					arr3 = NULL;

					for (int i = 0; i < *sum1; i++) {
						cout << "A0[" << i << "] = ";
						cin >> arr1[i];
					}
					for (int i = 0; i < *sum2; i++) {
						cout << "A1[" << i << "] = ";
						cin >> arr2[i];
					}
					cout << "Введите знак первого числа (1 - минус, 0 - плюс): ";
					cin >> *sign1;
					cout << "Введите знак второго числа (1 - минус, 0 - плюс): ";
					cin >> *sign2;
					SUB_ZZ_Z(sum1, arr1, sign1, sum2, arr2, sign2, sum3, arr3, sign3);
					cout << "Результат: ";

					if (*sign3 == 1) {
						cout << "-";
					}
					for (int i = 0; i < (*sum3); i++) {
						cout << arr3[i];
					}

					cout << "\n\n";
					system("pause");
					break;

				case 7:
					// Максим Кортель, группа 7301
					puts("Умножение целых чисел");
					
					first = NULL;
					second = NULL;

					cout << "Введите знак первого числа (1 - минус, 0 - плюс): ";
					cin >> markFisrt;

					cout << "Введите знак второго числа (1 - минус, 0 - плюс): ";
					cin >> markSecond;

					cout << "Введите количество цифр в первом числе: ";
					cin >> sizeFirst;

					cout << "Введите количество цифр во втором числе: ";
					cin >> sizeSecond;

					first = (int*)realloc(first, (sizeFirst + 1) * sizeof(int));
					second = (int*)realloc(second, (sizeSecond + 1) * sizeof(int));

					for (int i = 0; i < sizeFirst; i++)
					{
						cout << "A0[" << i << "] = ";
						cin >> *(first + i);
					}

					for (int i = 0; i < sizeSecond; i++)
					{
						cout << "A1[" << i << "] = ";
						cin >> *(second + i);
					}

					sizeResult = 0;
					result = NULL;
					MUL_ZZ_Z(sizeFirst, sizeSecond, first, second, markFisrt, markSecond, sizeResult, result, markResult);

					cout << "Ответ: ";
					if (markResult)
						cout << "-";

					for (int i = 0; i < sizeResult; i++)
						cout << *(result + i);

					free(result);
					free(first);
					free(second);

					puts("");
					system("pause");
					break;

				case 8:
					// Максим Кортель, группа 7301
					puts("Частное от деления целых чисел");

					first = NULL;
					second = NULL;

					cout << "Введите знак первого числа (1 - минус, 0 - плюс): ";
					cin >> markFisrt;

					cout << "Введите знак второго числа (1 - минус, 0 - плюс): ";
					cin >> markSecond;

					cout << "Введите количество цифр в первом числе: ";
					cin >> sizeFirst;

					cout << "Введите количество цифр во втором числе: ";
					cin >> sizeSecond;

					first = (int*)realloc(first, (sizeFirst + 1) * sizeof(int));
					second = (int*)realloc(second, (sizeSecond + 1) * sizeof(int));

					for (int i = 0; i < sizeFirst; i++)
					{
						cout << "A0[" << i << "] = ";
						cin >> *(first + i);
					}

					for (int i = 0; i < sizeSecond; i++)
					{
						cout << "A1[" << i << "] = ";
						cin >> *(second + i);
					}

					sizeResult = 0;
					result = NULL;
					//DIV_ZZ_Z(sizeFirst, sizeSecond, first, second, markFisrt, markSecond, sizeResult, result, markResult);

					cout << "Ответ: ";
					if (markResult)
						cout << "-";

					for (int i = 0; i < sizeResult; i++)
						cout << *(result + i);

					free(result);
					free(first);
					free(second);

					puts("");
					system("pause");
					break;

				case 9:
					break;
				}
				break;
		}
	} while (tmp != 27);
}

void fractionNum() // Модуль, в котором идёт работа с дробями
{
	string module[8] = {"1*. Сокращение дроби",
						"2. Проверка на целое",
						"3. Преобразование целого в дробное",
						"4. Преобразование дробного в целое",
						"5*. Сложение дробей",
						"6*. Вычитание дробей",
						"7. Умножение дробей",
						"8. Деление дробей (делитель отличен от нуля)"};
	
	// Переменные для выбора пункта
	int index = 0, tmp, prevIndex = -1;

	// Переменные для кейсов
	int *A0_1, *A1_1, *A0_result, *A1_result, *A = NULL, *A0 = NULL, *A1 = NULL, **result = NULL,
		b = 0, b_1, n0, n0_1, n1_1, n0_result, n1_result, b_result, b0_result, b1_result, n = -1, n1 = -1,
		x;


	do
	{
		if (prevIndex != index)
		{
			prevIndex = index;
			system("cls");
			puts("Звёздочка, идущая после цифры, обозначает недоступность данной функции.");
			puts("Выберите функцию, которую хотите запустить:\n");

			for (int i = 0; i < 8; i++)
			{
				if (i != index)
					cout << " " << module[i] << "\n";
				else
					cout << ">" << module[i] << "\n";
			}

			puts("\nДля возврата в прошлое меню нажмите Esc.");
		}

		tmp = _getch();
		switch (tmp)
		{
			case 72:
				if (index > 0)
					index--;
				break;

			case 80:
				if (index < 7)
					index++;
				break;

			case 13:
				prevIndex = -1;

				system("cls");
				switch (index)
				{
				case 0:
					break;

				case 1:
					// Рустам Аминов, группа 7307	
					puts("Проверка на целое, если рациональное число является целым, то «да», иначе «нет»");
					printf("Пожалуйста, введите числитель: ");
					scanf_s("%d", &x);
					b = 0;
					n = -1;
					n1 = -1;
					if (x<0)               //определение знака
					{
						b = 1;
						x = -x;
					}
					A = (int*)malloc((n + 1)*sizeof(int));
					for (int i = 0; x>0; i++)      //Запись числителя в массив (извращение)
					{
						n++;
						A = (int*)realloc(A, (n + 1)*sizeof(int));
						A[i] = x % 10;
						x = x / 10;
					}

					do
					{
						printf("Пожалуйста, введите знаменатель: ");
						scanf_s("%d", &x);
						if (x == 0)
							puts("Введите знаменатель, отличный от нуля!");
					} while (x == 0);

					A1 = (int*)malloc((n1 + 1)*sizeof(int));
					for (int i = 0; x>0; i++)     //Запись знаменателя в массив
					{
						n1++;
						A1 = (int*)realloc(A1, (n1 + 1)*sizeof(int));
						A1[i] = x % 10;
						x = x / 10;
					}

					if (INT_Q_B(b, n, A, n1, A1) == 1)//То ради чего все это делалось
						puts("Да, число целое");
					else
						puts("Нет, число не целое");

					free(A); //Освобождение памяти
					free(A1);

					puts("");
					system("pause");
					break;

				case 2:
					// Стас Смирнов, группа 7301
					puts("Преобразование дробного в целое");
					cout << "Введите знак b (1 - минус, 0 - плюс): ";
					cin >> b;
					cout << "Введите количество цифр в числе: ";
					cin >> n;
					A = (int*)realloc(A, (n + 1) * sizeof(int));
					for (int i = 0; i < n; i++)
					{
						cout << "a[" << i << "] = ";
						cin >> *(A + i);
					}
					A1 = (int*)malloc((n + 1)*sizeof(int));

					cout << "Результат - число: " << endl;
					cout << "Числитель : ";
					if (b == 1) cout << "-";
					for (int i = 0; i < n; i++)
						cout << A[i];
					cout << endl;
					cout << "Знаменатель : ";
					cout << TRANS_Z_Q(b, n, A, n1, A1);
					free(A);
					free(A1);

					puts("\n");
					system("pause");
					break;

				case 3:
					// Рустам Аминов, группа 7307
					puts("Преобразование дробного в целое (если знаменатель равен 1)");
					printf("Пожалуйста, введите числитель: ");
					scanf_s("%d", &x);
					b = 0;
					n = -1;
					n1 = -1;
					if (x<0)   //определение знака
					{
						b = 1;
						x = -x;
					}
					A = (int*)malloc((n + 1)*sizeof(int));
					for (int i = 0; x>0; i++)   //Запись числителя в массив (извращение)
					{
						n++;
						A = (int*)realloc(A, (n + 1)*sizeof(int));
						A[i] = x % 10;
						x = x / 10;
					}
					printf("Пожалуйста, введите знаменатель: ");
					scanf_s("%d", &x);
					A1 = (int*)malloc((n + 1)*sizeof(int));
					for (int i = 0; x>0; i++)     //Запись знаменателя в массив
					{
						n1++;
						A1 = (int*)realloc(A1, (n1 + 1)*sizeof(int));
						A1[i] = x % 10;
						x = x / 10;
					}

					TRANS_Q_Z(b, n, A, n1, A1);//То ради чего все это делалось
					free(A); //Освобождение памяти
					free(A1);

					system("pause");
					break;

				case 4:
					break;

				case 5:
					break;

				case 6:
					// Анна Волкова, группа 7307
					puts("Умножение дробей");
					printf("Введите знак первого числа (0 - положительное, 1 - отрицательное): ");
					scanf_s("%d", &b);

					printf("Разряд числителя первого числа: ");
					scanf_s("%d", &n0);
					A0 = (int*)malloc(n0*sizeof(int)); 
					printf("Введите числитель первой дроби: \n");
					for (int i = 0; i < n0; i++)
					{
						cout << "A0[" << i << "] = ";
						scanf_s("%d", &A0[i]);
					}

					printf("\nЧислитель: ");
					for (int i = 0; i<n0; i++)
						printf("%d", A0[i]);

					printf("\nРазряд знаменателя первого числа: ");
					scanf_s("%d", &n1);
					A1 = (int*)malloc(n1*sizeof(int));
					printf("Введите знаменатель второго числа: \n");
					for (int i = 0; i < n1; i++)
					{
						cout << "A0[" << i << "] = ";
						scanf_s("%d", &A1[i]);
					}
					printf("\nЗнаменатель: ");

					for (int i = 0; i<n1; i++)
						printf("%d", A1[i]);


					printf("\nВведите знак второго числа (0 - положительное, 1 - отрицательное): ");
					scanf_s("%d", &b_1);

					printf("Разряд числителя второго числа: ");
					scanf_s("%d", &n0_1);
					A0_1 = (int*)malloc(n0_1*sizeof(int));
					printf("Введите числитель второй дроби: \n");
					for (int i = 0; i < n0_1; i++)
					{
						cout << "A1[" << i << "] = ";
						scanf_s("%d", &A0_1[i]);
					}
					printf("\nЧислитель: ");
					for (int i = 0; i<n0_1; i++)
						printf("%d", A0_1[i]);

					printf("\nРазряд знаменателя второго числа: ");
					scanf_s("%d", &n1_1);
					A1_1 = (int*)malloc(n1_1*sizeof(int));
					printf("Введите знаменатель второй дроби: \n");
					for (int i = 0; i < n1; i++)
					{
						cout << "A1[" << i << "] = ";
						scanf_s("%d", &A1_1[i]);
					}

					printf("\nЗнаменатель: ");
					for (int i = 0; i<n1; i++)
						printf("%d", A1_1[i]);

					MUL_QQ_Q(b, n0, n1, A0, A1, b_1, n0_1, n1_1, A0_1, A1_1, b_result, n0_result, n1_result, A0_result, A1_result); //умножение дробей

					printf("\nРезультат: ");
					for (int i = 0; i<n0_result; i++)
						printf("%d", A0_result[i]);
					printf("/");
					for (int i = 0; i<n1_result; i++)
						printf("%d", A1_result[i]);

					free(A0);
					free(A1);
					free(A0_result);
					free(A1_result);
					free(A1_1);
					free(A0_1);

					puts("");
					system("pause");
					break;

				case 7:

					// Анна Волкова, группа 7307
					puts("Деление дробей");
					printf("Введите знак первого числа (0 - положительное, 1 - отрицательное): ");
					scanf_s("%d", &b);

					printf("Разряд числителя первого числа: ");
					scanf_s("%d", &n0);
					A0 = (int*)malloc(n0*sizeof(int));
					printf("Введите числитель первой дроби: \n");
					for (int i = 0; i < n0; i++)
					{
						cout << "A0[" << i << "] = ";
						scanf_s("%d", &A0[i]);
					}

					printf("\nЧислитель: ");
					for (int i = 0; i<n0; i++)
						printf("%d", A0[i]);

					printf("\nРазряд знаменателя первого числа: ");
					scanf_s("%d", &n1);
					A1 = (int*)malloc(n1*sizeof(int));
					printf("Введите знаменатель второго числа: \n");
					for (int i = 0; i < n1; i++)
					{
						cout << "A0[" << i << "] = ";
						scanf_s("%d", &A1[i]);
					}
					printf("\nЗнаменатель: ");

					for (int i = 0; i<n1; i++)
						printf("%d", A1[i]);


					printf("\nВведите знак второго числа (0 - положительное, 1 - отрицательное): ");
					scanf_s("%d", &b_1);

					printf("Разряд числителя второго числа: ");
					scanf_s("%d", &n0_1);
					A0_1 = (int*)malloc(n0_1*sizeof(int));
					printf("Введите числитель второй дроби: \n");
					for (int i = 0; i < n0_1; i++)
					{
						cout << "A1[" << i << "] = ";
						scanf_s("%d", &A0_1[i]);
					}
					printf("\nЧислитель: ");
					for (int i = 0; i<n0_1; i++)
						printf("%d", A0_1[i]);

					printf("\nРазряд знаменателя второго числа: ");
					scanf_s("%d", &n1_1);
					A1_1 = (int*)malloc(n1_1*sizeof(int));
					printf("Введите знаменатель второй дроби: \n");
					for (int i = 0; i < n1; i++)
					{
						cout << "A1[" << i << "] = ";
						scanf_s("%d", &A1_1[i]);
					}

					printf("\nЗнаменатель: ");
					for (int i = 0; i<n1; i++)
						printf("%d", A1_1[i]);

					DIV_QQ_Q(b, n0, n1, A0, A1, b_1, n0_1, n1_1, A0_1, A1_1, b0_result, b1_result, n0_result, n1_result, A0_result, A1_result);  //Деление дробей

					printf("\nРезультат: ");
					if (b0_result != b1_result)
						printf("-");

					for (int i = 0; i<n0_result; i++)
						printf("%d", A0_result[i]);
					printf("/");
					for (int i = 0; i<n1_result; i++)
						printf("%d", A1_result[i]);

					free(A0);
					free(A1);
					free(A0_result);
					free(A1_result);
					free(A1_1);
					free(A0_1);

					puts("");
					system("pause");
					break;
				}
				break;
		}
	} while (tmp != 27);

}

void polyNum() // Модуль, в котором идёт работа с многочленами
{	
	string module[13] = {"1*. Сложение многочленов",
						 "2*. Вычитание многочленов", 
						 "3*. Умножение многочлена на рациональное число",
						 "4*. Умножение многочлена на x^k", 
						 "5. Старший коэффициент многочлена",
						 "6*. Степень многочлена",
						 "7*. Вынесение из многочлена НОК знаменателей...",
						 "8*. Умножение многочленов",
						 "9*. Частное от деления многочлена на многочлен...",
						 "10*. ВОстаток от деления многочлена на многочлен ...",
						 "11*. НОД многочленов",
						 "12. Производная многочлена",
						 "13*. Преобразование многочлена — кратные корни в простые"};

	// Переменные для выбора пункта
	int index = 0, tmp, prevIndex = -1;

	// Переменные для case
	int m, 
	    *C = NULL;
	do
	{
		if (prevIndex != index)
		{
			prevIndex = index;
			system("cls");
			puts("Звёздочка, идущая после цифры, обозначает недоступность данной функции.");
			puts("Внимание! Троеточие означает, что полный текст задания не поместился.\n"
				"Для прочтения полного текста выберите соответствующий пункт меню.\n"
				"Выберите функцию, которую хотите запустить:\n");

			for (int i = 0; i < 13; i++)
			{
				if (i != index)
					cout << " " << module[i] << "\n";
				else
					cout << ">" << module[i] << "\n";
			}

			puts("\nДля возврата в прошлое меню нажмите Esc.");
		}

		tmp = _getch();
		switch (tmp)
		{
			case 72:
				if (index > 0)
					index--;
				break;

			case 80:
				if (index < 12)
					index++;
				break;

			case 13:
				prevIndex = -1;

				system("cls");
				switch (index)
				{
				case 0:
					break;

				case 1:
					break;

				case 2:
					break;

				case 3:
					break;

				case 4:
					// Дмитрий Богряков, группа 7307
					puts("Старший коэффициент многочлена");
					cout << "Введите степень многочлена: ";
					cin >> m;
					cout << "Введите коэффициенты: \n";
					C = (int*)realloc(C, (m + 1) * sizeof(int));
					for (int i = 0; i<m; i++)
					{
						cout << "c[" << i + 1 << "] = ";
						cin >> *(C + i);
					}
					LED_P_Q(m, C);
					system("pause");
					break;

				case 5:
					break;

				case 6:
					break;

				case 7:
					break;

				case 8:
					break;

				case 9:
					break;

				case 10:
					break;

				case 11:
					// Алина Белоусова, группа 7307
					printf("Введите старшую степень многочлена: ");
					scanf_s("%d", &m);

					C = (int*)realloc(C, (2 * m + 2) * sizeof(int));

					printf("Введите коэффициенты многочлена:\n");

					for (int i = 2 * m + 1; i >= 0; i = i - 2) // Ввод числителей и знаменателей первого многочлена
					{
						printf("Числитель: %");
						scanf_s("%d", &C[i - 1]);
						printf("Знаменатель: ");
						scanf_s("%d", &C[i]);
					}
					DER_PP_P(m, C);

					puts("");
					system("pause");
					break;

				case 12:
					break;
				}
				break;
		}
	} while (tmp != 27);
}

void modulePick() // Выбор модуля
{
	string module[4] = {"1. Натуральные числа с нулем",
						"2. Целые числа",
						"3. Рациональная числа (дроби)",
						"4. Многочлен с рациональными коэффициентами"};
	
	// Переменные для выбора пункта
	int index = 0, tmp, prevIndex = -1;

	do
	{
		if (prevIndex != index)
		{
			prevIndex = index;
			system("cls");
			puts("Выберите модуль, в котором Вы хотите произвести вычисления:\n");

			for (int i = 0; i < 4; i++)
			{
				if (i != index)
					cout << " " << module[i] << "\n";
				else
					cout << ">" << module[i] << "\n";
			}

			puts("\nДля возврата в прошлое меню нажмите Esc.");
		}
		tmp = _getch();
		switch (tmp)
		{
			case 72:
				if (index > 0)
					index--;
				break;

			case 80:
				if (index < 3)
					index++;
				break;

			case 13:
				prevIndex = -1;

				switch (index)
				{
					case 0:
						naturalNum();
						break;

					case 1:
						totalNum();
						break;

					case 2:
						fractionNum();
						break;

					case 3:
						polyNum();
						break;

				}
				break;
		}
	} while (tmp != 27);
}

void devTeam() // Команда разработчиков
{
	system("cls");
	puts("Список людей, разрабатывавших этот проект:\n"
		 "Архитектор:                      Программисты:\n"
		 "Дмитрий Кезлинг, группа 7305     Диана Щебет, группа 7307\n"
		 "                                 Евгений Сысенко, группа 7307\n"
		 "                                 Дмитрий Богряков, группа 7307\n"
		 "                                 Рустам Аминов, группа 7307\n"
		 "Ответственный по качеству:       Анна Волкова, группа 7307\n"
		 "Никита Исаенко, группа 7305      Владислав Лагерев, группа 7307\n"
		 "                                 Алина Белоусова, группа 7307\n"
		 "                                 Алексаднр Трифонов, группа 7301\n"
		 "                                 Максим Кортель, группа 7301\n"
		 "                                 Станислав Смирнов, группа 7301\n\n"
		 "Для возврата в прошлое меню нажмите Esc.");
	do
	{ }
	while (_getch() != 27);
}

void fixJournal() // Журнал всех исправлений
{
	system("cls");
	puts("Версия 1.0 BETA - Список изменений: \n"
		 "1. Начало разработки проекта\n"
		 "2. Внесены данные о разработчиках\n"
		 "3. Введён лог обновлений программы\n"
		 "4. Введены функции:\n"
		 "I  уровня (меню) - выбор меню, команда разработчиков, журнал исправлений\n"
		 "II уровня (модули) - натуральные числа, целые числа, рациональные числа, многочлены \n"
		 "Отчёт обновлён 30.03.2018 в 15:15 \n\n" 

		 "Версия 1.0.1 - Список изменений: \n"
		 "1. Введена функция I уровня 'Помощь'\n"
		 "2. Исправление мелких ошибок\n"
		 "3. Оптимизация программы \n"
		 "4. Введены первые комментарии \n"
		 "5. Произведена оптимизация места для удобности чтения(убраны или добавлены пробелы) \n"
		 "Отчёт обновлён 30.03.2018 в 17:20 \n\n" 

		 "Версия 1.1.0 - Список изменений: \n"
		 "1. Добавлен блок ЧАВО, отвечающий на основные вопросы \n"
		 "2. Добавлена функция N - 1 (III уровень) \n"
		 "3. Добавлена функция N - 2 (III уровень) \n"
		 "4. Добавлена функция N - 7 (III уровень) \n"
		 "5. Добавлена функция Z - 1 (III уровень) \n"
		 "6. Добавлена функция Q - 4 (III уровень) \n"
		 "Отчёт обновлён 30.03.2018 в 23:30 \n\n" 

		 "Версия 1.2.0 - Список изменений: \n"
		 "1. Добавлено множество комментариев в блоке ЧАВО \n"
		 "2. Добавлены комментарии по всей программе"
		 "3. Добавлена функция N - 6 (III уровень) \n"
		 "4. Добавлена функция P - 5 (III уровень) \n"
		 "5. Значительная оптимизация всего кода \n"
		 "Отчёт обновлён 03.04.2018 в 00:30 \n\n" 

		 "Версия 1.2.1 - Список изменений: \n"
		 "1. Добавлена функция N - 5 (III уровень) \n"
		 "2. Исправление мелких ошибок \n"
		 "Отчёт обновлён 03.04.2018 в 13:30 \n\n" 

		 "Версия 1.2.2 - Список изменений: \n"
		 "1. Добавлена функция N - 9 (III уровень) \n"
		 "2. Уменьшение мерцания при выборе пункта меню \n"
		 "2.1 Обновление надписей на экране производится только при измении пунктов меню, поэтому мерцания меньше \n"
		 "3. Исправление мелких ошибок \n"
		 "Отчёт обновлён 03.04.2018 в 16:30 \n\n"

		 "Версия 1.2.3 - Список изменений: \n"
		 "1. Добавлена функция Z - 2 (III уровень) \n"
		 "2. Добавлена функция Z - 3 (III уровень) \n"
		 "3. Исправление мелких ошибок \n"
		 "Отчёт обновлён 04.04.2018 в 20:00 \n\n"

		 "Версия 1.2.4 - Список изменений: \n"
		 "1. Добавлена функция N - 3 (III уровень) \n"
		 "2. Добавлена функция Z - 4 (III уровень) \n"
		 "3. Добавлена функция Z - 5 (III уровень) \n"
		 "4. Исправление мелких ошибок \n"
		 "Отчёт обновлён 05.04.2018 в 12:30 \n\n"

		 "Версия 1.2.5 - Список изменений: \n"
		 "1. Обновлена функция N - 7 (III уровень) \n"
		 "2. Добавлена функция N - 10 (III уровень) \n"
		 "3. Исправление мелких ошибок \n"
		 "Отчёт обновлён 05.04.2018 в 20:30 \n\n"

		 "Версия 1.2.6 - Список изменений: \n"
		 "1. Добавлена функция N - 4 (III уровень) \n"
		 "2. Добавлена функция Q - 2 (III уровень) \n"
		 "3. Исправление мелких ошибок \n"
		 "Отчёт обновлён 06.04.2018 в 19:00 \n\n"

		 "Версия 1.2.7 - Список изменений: \n"
		 "1. Переписана функция N - 4 (III уровень) \n"
		 "2. Добавлена функция Q - 3 (III уровень) \n"
		 "3. Исправление мелких ошибок \n"
		 "Отчёт обновлён 08.04.2018 в 02:00 \n\n"

		 "Версия 1.2.8 - Список изменений: \n"
		 "1. Добавлена функция N - 8 (III уровень) \n"
		 "2. Переписана функция Z - 1 (III уровень) \n"
		 "3. Добавлена функция Z - 8 (III уровень) \n"
		 "4. Исправление мелких ошибок \n"
		 "Отчёт обновлён 08.04.2018 в 17:30 \n\n"

		 "Версия 1.2.9 RELEASE - Список изменений: \n"
		 "1. Обновлена функция N - 4 (III уровень) \n"
		 "2. Обновлена функция N - 10 (III уровень) \n"
		 "3. Добавлена функция P - 12 (III уровень) \n"
		 "4. Исправление мелких ошибок \n"
		 "Отчёт обновлён 10.04.2018 в 22:30 \n\n"

		 "(Актуальная) Версия 1.2.10 RELEASE - Список изменений: \n"
		 "1. Добавлена функция Z - 6 (III уровень) \n"
		 "2. Добавлена функция Z - 7 (III уровень) \n"
		 "3. Обновлена функция N - 5 (III уровень) \n"
		 "4. Добавлена функция Q - 7 (III уровень) \n"
		 "5. Добавлена функция Q - 8 (III уровень) \n"
		 "6. Исправление мелких ошибок \n"
		 "Отчёт обновлён 11.04.2018 в 17:00 \n\n"

		 "Список будущих нововведений (без хронологического порядка):\n"
		 "1. Заполнение всех функций во всех модулях (III уровень) \n"
		 "2. Оптимизация программы\n"
		 "3. Введение новых комментариев\n"
		 "4. (Возможное) Введение 'админ-панели', вызываемой по секретной кнопке\n"
		 "4.1 (Возможное) Введение возможности редактирования всех текстовых выводимых данных\n"
		 "5. (Возможное) Улучшение графического интерфейса программы \n"
		 "Отчёт обновлён 30.03.2018 в 16:30 \n\n" 

		 "Для возврата в прошлое меню нажмите Esc.");
	do
	{
	} while (_getch() != 27);
}

void help() // Помощь
{
	system("cls");
	puts("При возникновении вопросов, жалоб и предложений - обращаться на почту:\n"
		 "dimon@kezling.ru\n\n"
		 "Для возврата в прошлое меню нажмите Esc.");
	do
	{
	} while (_getch() != 27);
}

void menuPick() // Выбор меню
{
	string mainMenu[4] = {"1. Переход к основной части программы",
						  "2. Команда разработчиков",
						  "3. Журнал обновлений",
						  "4. Помощь"};

	// Переменные для выбора пункта
	int index = 0, tmp, prevIndex = -1;

	do
	{
		if (prevIndex != index)
		{
			prevIndex = index;
			system("cls");
			puts("Версия программы: 1.2.10 RELEASE \n\n"
				"Здравствуйте!\n"
				"Для управления программой используйте стрелки вверх/вниз на клавиатуре\n"
				"Для входа в пункт меню используйте Enter, для выхода - Esc.\n"
				"Приятного использования!\n");

			for (int i = 0; i < 4; i++)
			{
				if (i != index)
					cout << " " << mainMenu[i] << "\n";
				else
					cout << ">" << mainMenu[i] << "\n";
			}

			puts("\nДля выхода из программы нажмите Esc.");
		}

		tmp = _getch(); 
		switch (tmp)
		{
			case 72:
				if (index > 0)
					index--;
				break;

			case 80:
				if (index < 3)
					index++;
				break;
			
			case 13:
				prevIndex = -1;

				switch (index)
				{
					case 0:
						modulePick();
						break;

					case 1:
						devTeam();
						break;

					case 2:
						fixJournal();
						break;

					case 3:
						help();
						break;
				}
				break;
		}
	} while (tmp != 27);
}

int main() // Основная функция
{
	setlocale(LC_ALL, "RUS"); // Подключение русской локализации
	 
	menuPick();

	system("cls");
	puts("Команда разработчиков благодарит Вас за использование нашей программмы! \n"
		 "Надеемся увидеть вас снова! \n"
		 "До свидания!");
	system("pause");
	return 0;
}