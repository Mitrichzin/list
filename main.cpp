#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
#include<string>
using namespace std;

void printc() {
    cout << "������ ������:\n";
    cout << "0 - �������� ������\n1 - ������ ������\n2 - ������� �������� �� ��������� �������� \n3 - ������� �������� ����� ��������� �������� \n";
    cout << "4 - ������� �������� � ����� ������\n5 - ������� ������ �������\n6 - ������� ��������� �������\n7 - ������� �������� �������  \n";
    cout << "8 - ����� ������������ ������� ������ � ������� ��� �������, ������ �� ������ ������\n9 - ��������� ������ ��(�������� � ����� ������) n ��������� �� ���������� ����������\n";
    cout << "10 - �����\n";
    cout << "������� �������: ";
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
                cout << "������� �������� ������������ ��������: ";
                cin >> v;
                cout << "������� �������� ��������� ��������: ";
                cin >> x;
                it=(find(l.begin(),l.end(),x));
                if (it == l.end()) cout << "� ������ ��� �������� � ����� ��������\n";
                else
                    l.insert(it, v);
                break;
            case 3:
                cout << "������� �������� ������������ ��������: ";
                cin >> v;
                cout << "������� �������� ��������� ��������: ";
                cin >> x;
                it=(find(l.begin(),l.end(),x));
                if (it == l.end()) cout << "� ������ ��� �������� � ����� ��������\n";
                else
                    {
                        it++;
                        l.insert(it, v);
                    }
                break;
            case 4:
                cout << "������� �������� ������������ ��������: ";
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
                cout << "������� ������� ���������� ��������: ";
                cin >> x;
                while (k != x - 1){
                    it++;
                    k++;
                };
                if (it == l.end()) cout << "� ������ ��� �������� � ����� ��������\n";
                else
                    l.erase(it);
                break;
            case 8:
                cout << "������������ ������� ������ ����� ������� "<< max(l);
                cout <<"\n";
                break;
            case 9:
                cout << "������� ���������� ���������: ";
                cin >> x;
                for (int i = 0; i < x; i++)
                    l.push_back(rand() % 99);
                break;
            default:
                cout << "�������� �������\n";
                break;
        }
        k = 0;
        it = l.begin();
        cout << "������� �������: ";
        cin >> a;
    }
    return l;
}
int main()
{
	list<int> list1;
	list1=listwork("CON");
}
