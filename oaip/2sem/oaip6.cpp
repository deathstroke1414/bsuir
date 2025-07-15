//Разработать проект для работы с деревом поиска, содержащий следующие обработчики, которые должны :
//– ввести информацию из компоненты StringGrid в массив. Каждый элемент массива должен содержать 
// строку текста и целочисленный ключ(например, Ф.И.О.и номер паспорта);
//– внести информацию из массива в дерево поиска;
//– сбалансировать дерево поиска;
//– добавить в дерево поиска новую запись;
//– по заданному ключу найти информацию и отобразить ее;
//– удалить из дерева поиска информацию с заданным ключом;
//– распечатать информацию прямым, обратным обходом и в порядке возрастания ключа;
//8. Определить число листьев на каждом уровне дерева.

#include <iostream>
using namespace std;

struct Tree
{
	int info = 0;
	Tree* left = NULL, * right = NULL;
} *root;

Tree* List(int i)
{
	Tree* t = new Tree;
	t->info = i;
	//t->name = name;
	t->left = t->right = NULL;
	return t;
}

Tree* Create(Tree* root, int &count ) {
	Tree* Prev = root, * t;
	int b, find;
	//char name[20];
	if (!root)
	{
		cout << "Введите номер корня :  ";
		cin >> b;
		/*cout << "Введите имя корня :  ";
		cin >> name;*/
		count++;
		root = List(b);
		Prev = root;
	}
	while (true)
	{
		cout << "Введите номер узла :  ";
		cin >> b;
		/*cout << "Введите имя узла :  ";
		cin >> name;*/
		if (b < 0) break;
		t = root;
		find = 0;
		while (t && !find)
		{
			Prev = t;
			if (b == t->info)
				find = 1;
			else
				if (b < t->info) t = t->left;
				else   t = t->right;
		}
		if (!find)
		{
			count++;
			t = List(b);
			if (Prev)
			if ( b < Prev->info)
				Prev->left = t;
			else    Prev->right = t;
		}
	}
	return root;
}

void Add_List(Tree* root, int key, int &count)
{
	Tree* prev = root, * t;
	bool find = true;
	t = root;
	while (t && find) {
		prev = t;
		if (key == t->info) {
			find = false;	
			cout << "Такой уже есть !" << endl;
		}
		else
		{
			if (key < t->info) t = t->left;
			else
				t = t->right;
		}
	}
	if (find) 
	{
		t = List(key);
		count++;
		if(prev)
		if (key < prev->info && prev)
			prev->left = t;
		else
			prev->right = t;
	}
}

Tree* Del(Tree* root, int key,int &count)
{
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = root;
	Prev_Del = NULL;
	while (Del != NULL && Del->info != key) {
		Prev_Del = Del;
		if (Del->info > key)  Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) 
	{ 
		cout << "\nУзла с таким номером нет!" << endl;
		return root;
	}
	// --------- Поиск элемента R для замены ---------
	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del)
				R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == root) root = R;
	else
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R;
		else
			Prev_Del->right = R;
	cout << " Delete " << Del->info << endl;
	delete  Del;
	count--;
	return root;
}

void StraightView(Tree* t, int level) 
{
	if (t) 
	{
		StraightView(t->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "    ";
		cout << t->info << endl;
		StraightView(t->left, level + 1);
	}
}

void Del_All(Tree* t) {
	if (t != NULL) {
		Del_All(t->left);
		Del_All(t->right);
		delete t;
	}
}

void kolvo(Tree* root, int key, int& count, int& kod)
{
	if (!root)
		return;
	while (root->info != key && kod == 0 && root)
	{
		if (key > root->info)root = root->right;
		else root = root->left;
	}
	kod = 1;
	if (kod == 1 && root)
	{
		if (root->right == NULL && root->left == NULL)
			count++;
		else
		{
			kolvo(root->left, key, count, kod);
			kolvo(root->right, key, count, kod);
		}
	}
}

void View_One(Tree* t, int key)
{
	if (t != NULL)
	{
		View_One(t->right, key);
		View_One(t->left, key);

	}
	else
		return;
	if (t->info == key)
	{
		cout << t->info << endl;
		return;
	}
}

void ReverseView(Tree* root) {
	if (root != NULL)
	{
		ReverseView(root->left); 
		ReverseView(root->right); 
		cout << root->info << " "; 
	}
}

void Make_Blns(Tree** p, int n, int k, int* a)
{
	if (n == k) 
	{
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->info = a[m];
		Make_Blns(&(*p)->left, n, m, a);
		Make_Blns(&(*p)->right, m + 1, k, a);
	}
}

void Zapoln(Tree* root, int* a, int &i, int n )
{
	if (n > i)
	if (root != NULL)
	{
		Zapoln(root->left, a, i, n);
		Zapoln(root->right, a, i, n);
		a[i++] = root->info;
	}
}

void Sort(int* arr, int n)
{
	int buf = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
			{
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
			}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int count=0, kod = 0, key = 1, num = 0;
	Tree* root = NULL;
	root = Create(root, num);
	system("cls");
	cout << "Прямой вывод дерева:" << endl;
	StraightView(root, 0);
	cout << "Если хотите добавить узел нажмите 1:";
	int j;
	cin >> j;
	if (j == 1)
	{
		cout << "Введите ключ:";
		cin >> key;
		Add_List(root, key, num);
		cout << "Прямой вывод дерева:" << endl;
		StraightView(root, 0);
		system("pause");
	}
	cout << "Если хотите удалить узел нажмите 2:";
	cin >> j;
	if (j == 2)
	{
		cout << "Введите ключ:";
		cin >> key;
		Del(root, key, num);
	}
	system("cls");
	cout << "Прямой вывод дерева:" << endl;
	StraightView(root, 0);
	system("pause");
	cout << "Ключ для поиска листьев:";
	cin >> key;
	while (key >= 0)
	{
		kolvo(root, key, count, kod);
		cout << "Leaves count:" << count << endl;
		count = 0;
		kod = 0;
		cout << "Ключ для поиска листьев:";
		cin >> key;
	}
	cout << "Ключ для вывода информации: ";
	cin >> key;
	View_One(root, key);
	system("pause");
	cout << "Обратный вывод дерева:" << endl;
	ReverseView(root);
	cout << endl;
	system("pause");
	int* a = new int[num];
	int i = 0;
	Zapoln(root, a, i, num);
	Sort(a, num);
	Del_All(root);
	Make_Blns(&root, 0, num, a);
	cout << "Сбалансированное дерево:" << endl;
	StraightView(root, 0);
	Del_All(root);
	delete[]a;
}