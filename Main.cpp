#include"SeqList.h"
#include"SingleList.h"

#include<iostream>

using namespace std;
int main(){
	cout << "1.˳���ʵ��" << endl;
	cout << "2.����ʵ��" << endl;
	int seleted;
	scanf("%d", &seleted);
	if (seleted == 1){
		int n = 10;              //��ʾ�����˳�����󳤶�Ϊ10
		SeqList<int> r(n);
		char c; int i, x;
		do{
			cout << "\n 0...�˳�";
			cout << "\n 1...����";
			cout << "\n 2...ɾ��";
			cout << "\n 3...���";
			cout << "\n 4...��ת";
			cout << "\n 5...ɾ���ض�Ԫ��\n";
			cin >> c;
			switch (c){
			case '1':
				cout << "λ��  Ԫ��ֵ:";
				cin >> i >> x;
				r.Insert(i, x);
				break;
			case '2':
				cout << "λ��:";
				cin >> i;
				r.Delete(i);
				break;
			case '3':
				cout << "\n";
				r.Output(cout);
				break;
			case'4':
				r.Reverse();
				break;
			case'5':
				cout << "������ɾ�������ݣ�";
				int num;
				scanf("%d", &num);
				r.DeleteX(num);
				break;
			};//end do
		} while (c != '0');
	}//end if
	else if (seleted == 2){
		SingleList<int>  L;

		char c; int i, x;
		do {
			cout << "\n 0...�˳�";
			cout << "\n 1...����";
			cout << "\n 2...ɾ��";
			cout << "\n 3...���";
			cout << "\n 4...��ת";
			cout << "\n 5...ɾ���ض�����\n";
			cin >> c;
			switch (c) {
			case '1':
				cout << "λ��  Ԫ��ֵ:";
				cin >> i >> x;
				L.Insert(i, x);  break;
			case '2':
				cout << "λ��:";
				cin >> i;
				L.Delete(i);  break;
			case '3':
				cout << "\n";  L.Output(cout);
				break;
			case '4':
				L.Reverse();
				break;
			case '5':
				cout << "������ɾ�������ݣ�";
				int num;
				scanf("%d", &num);
				L.DeleteX(num);
				break;
			};
		} while (c != '0');
	}//end if
	return 0;

}

/*template<class T>
void Union(SeqList<T> &LA, SeqList<T>&LB){
	T x;
	for (int i = 0; i < LA.Length(); i++){
		LA.Find(i, x);
		if (LB.Search(x) == -1){
			LB.Insert(LB.Length() - 1, x);
		}
	}

}*/