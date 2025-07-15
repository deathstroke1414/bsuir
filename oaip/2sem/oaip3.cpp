/*8. Перенести из созданного списка в новый список все элементы, находящиеся между вершиной и элементом с минимальным значением.*/
#include <iostream>
#include <ctime>

using namespace std;

struct Stack {
	int info;
	Stack* next;
} *begin, * newbegin;

Stack* InStack(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

void View(Stack* p)
{
	Stack* t = p;
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
}

void Del_All(Stack** p) {
	Stack* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

Stack* min(Stack* a, Stack* b)
{
	if (a->info >= b->info)
		return b;
	else
		return a;
}

Stack* minStack(Stack* p)
{
	Stack* t = p;
	Stack* minElem = t;
	while (t != NULL) {
		minElem = min(minElem, t);
		t = t->next;
	}
	return minElem;
}

void Sort_info(Stack* p) {
	Stack* t = NULL, * t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}


Stack* func(Stack* p, Stack* newbegin)
{
	int count = 0;
	Stack* t = p->next;
	while (t != NULL && t != minStack(p))
	{
		count = t->info;
		newbegin = InStack(newbegin, count);
		t = t->next;
	}
	return newbegin;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int i, in, n, kod;
	Stack* begin = NULL;
	Stack* newbegin = NULL;
	srand(static_cast<unsigned int>(time(NULL)));
	while (true) {
		cout << "1.Создать стек 2.Добавить элементы в стек 3.Показать стек\n 4.Удалить стек 5.Выполнить основное задание 6.Вывести информацию о новом стеке" << endl;
		cin >> kod;
		switch (kod) {
		case 1: case 2:
			if (kod == 1 && begin != NULL) {
				cout << "Очистите память!" << endl;
				break;
			}
			cout << "Количесвто элементов стека:";         cin >> n;
			for (i = 1; i <= n; i++) {
				in = rand() % 50;
				begin = InStack(begin, in);
			}
			if (kod == 1) cout << "Создан стек на следующее количество элементов: " << n << endl;
			else cout << "Добавлено элементов:  " << n << endl;
			break;
		case 3:         if (!begin) {
			cout << "Стек пуст!" << endl;
			break;
		}
			  cout << "--- Стек ---" << endl;
			  View(begin);
			  cout << endl;
			  break;
		case 4:
			Del_All(&begin);
			Del_All(&newbegin);
			cout << "Память очищена!" << endl;
			break;
		case 5:
			newbegin = func(begin, newbegin);
			break;
		case 6:
			if (!newbegin)
			{
				cout << "Новый стек пуст!" << endl;
			}
			cout << endl << "Получившийся стек:" << endl;
			View(newbegin);
			Sort_info(newbegin);
			cout << "Отсортированный:" << endl;
			View(newbegin);
			break;
		default:
			if (begin != NULL)
			{
				Del_All(&begin);
				Del_All(&newbegin);
			}
			return 0;
		}
	}
}

