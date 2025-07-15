//8. Перенести из созданного списка в новый список все элементы,
//находящиеся между вершиной и элементом с минимальным значением.

#include <iostream>
using namespace std;

struct Spis2 {
    int info;
    Spis2* next, * prev;
} *begin, * end, * t;

void Create_Spis2(Spis2** b, Spis2** e, int in) {
    t = new Spis2;
    t->info = in;
    t->next = t->prev = NULL;
    *b = *e = t;
}

void Add_Spis2(int kod, Spis2** b, Spis2** e, int in) {
    t = new Spis2;
    t->info = in;
    if (kod == 0) {
        t->prev = NULL;
        t->next = *b;
        (*b)->prev = t;
        *b = t;
    }
    else {
        t->next = NULL;
        t->prev = *e;
        (*e)->next = t;
        *e = t;
    }
}

void View_Spis2(int kod, Spis2* t) {
    while (t != NULL)
    {
        cout << t->info << endl;
        if (kod == 0) t = t->next;
        else  t = t->prev;
    }
}
void Del_All(Spis2** p)
{
    while (*p != NULL) {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}

Spis2* minElem(Spis2* b)
{
    Spis2* num = b;
    while (b->next != NULL)
    {
        b = b->next;
        if (num->info > b->info)
            num = b;
    }
    return num;
}
void newSpisCreate(Spis2* e, Spis2* b)
{
    Spis2* newbegin = NULL;
    Spis2* newend = NULL;
    Create_Spis2(&newbegin, &newend, e->prev->info);
    e = e->prev;
    while (e->prev != minElem(b))
    {
        e = e->prev;
        Add_Spis2(1, &newbegin, &newend, e->info);
    }
    Spis2* k = newbegin;
    View_Spis2(0, k);
    Del_All(&newbegin);
}
int main()
{
    setlocale(LC_ALL, "ru");
    int i, in, n, kod, kod1;
    char Str[2][10] = { "Begin ", "End " };
    Spis2* begin = NULL;
    Spis2* end = NULL;
    while (true) {
        cout << "\n\tCreat - 1\n\tAdd - 2\n\tView - 3\n\tDel - 4\n\tEXIT - 0  :  ";
        cin >> kod;
        switch (kod) {
        case 1:        if (begin != NULL) {
            cout << "Clear Memory!" << endl;
            break;
        }
              cout << "Begin Info = ";     cin >> in;
              Create_Spis2(&begin, &end, in);
              cout << "Creat Begin = " << begin->info << endl;
              break;
        case 2:
            cout << "Info = ";        cin >> in;
            cout << "Add Begin - 0, Add End - 1 :  ";      cin >> kod1;
            Add_Spis2(kod1, &begin, &end, in);
            if (kod1 == 0) t = begin;
            else t = end;
            cout << "Add to " << Str[kod1] << "  " << t->info << endl;
            break;
        case 3:   if (!begin) {
            cout << "Stack Pyst!" << endl;
            break;
        }
              cout << "View Begin-0,View End-1:";
              cin >> kod1;
              if (kod1 == 0) {
                  t = begin;
                  cout << "-- Begin --" << endl;
              }
              else {
                  t = end;
                  cout << "--- End --" << endl;
              }
              View_Spis2(kod1, t);
              break;
        case 4:
            Del_All(&begin);
            cout << "Memory Free!" << endl;
            break;
        case 5:
            newSpisCreate(end, begin);
            break;
        case 0:  if (begin != NULL)
            Del_All(&begin);
            return 0;
        }
    }
}
