#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
#include<string>
using namespace std;

void printc() {
    cout << "Список команд:\n";
    cout << "0 - Очистить список\n1 - Печать списка\n2 - Вставка значения до заданного элемента \n3 - Вставка значения после заданного элемента \n";
    cout << "4 - Вставка значения в хвост списка\n5 - Удалить первый элемент\n6 - Удалить последний элемент\n7 - Удалить заданный элемент  \n";
    cout << "8 - Найти максимальный элемент списка и вывести его позицию, считая от начала списка\n9 - Построить список из(добавить в конец списка) n элементов со случайными значениями\n";
    cout << "10 - Выход\n";
    cout << "Введите команду: ";
}
string printl(list<int> l)
{
	string str="";
	char str2[30];
	list<int>::iterator it = l.begin();
	for (it = l.begin(); it != l.end(); it++)
    {
		itoa(*it,str2,10);
        (str+=str2)+=" ";
    }
    return str;
}
int max(list<int> l)
{
	int k=1;
	list<int>::iterator it = l.begin();
    while (it != max_element(l.begin(), l.end())){
        it++;
        k++;
    };
    return(k);
}
list<int> listwork( const char* input)
{
    freopen(input, "r", stdin);
	int x, k = 1, v, a;
    list <int> l;
    list<int>::iterator it = l.begin();
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < 5; i++)
    l.push_back(rand() % 99);
    printc();
    cin >> a;
    while (a != 10) {
        switch (a) {
            case 0:
                l.clear();
				break;
            case 1:
                cout<<printl(l);
                cout <<"\n";
                break;
            case 2:
                cout << "Введите значение вставляемого элемента: ";
                cin >> v;
                cout << "Введите значение заданного элемента: ";
                cin >> x;
                it=(find(l.begin(),l.end(),x));
                if (it == l.end()) cout << "В списке нет элемента с такой позицией\n";
                else
                    l.insert(it, v);
                break;
            case 3:
                cout << "Введите значение вставляемого элемента: ";
                cin >> v;
                cout << "Введите значение заданного элемента: ";
                cin >> x;
                it=(find(l.begin(),l.end(),x));
                if (it == l.end()) cout << "В списке нет элемента с такой позицией\n";
                else
                    {
                        it++;
                        l.insert(it, v);
                    }
                break;
            case 4:
                cout << "Введите значение вставляемого элемента: ";
                cin >> v;
                l.push_back(v);
                break;
            case 5:
                l.pop_front();
                break;
            case 6:
                l.pop_back();
                break;
            case 7:
                cout << "Введите позицию удаляемого элемента: ";
                cin >> x;
                while (k != x - 1){
                    it++;
                    k++;
                };
                if (it == l.end()) cout << "В списке нет элемента с такой позицией\n";
                else
                    l.erase(it);
                break;
            case 8:
                cout << "Максимальный элемент списка имеет позицию "<< max(l);
                cout <<"\n";
                break;
            case 9:
                cout << "Введите количество элементов: ";
                cin >> x;
                for (int i = 0; i < x; i++)
                    l.push_back(rand() % 99);
                break;
            default:
                cout << "Неверная команда\n";
                break;
        }
        k = 0;
        it = l.begin();
        cout << "Введите команду: ";
        cin >> a;
    }
    return l;
}
int main()
{
	list<int> list1;
	list1=listwork("CON");
}
