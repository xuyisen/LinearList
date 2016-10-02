#include"SeqList.h"
#include"SingleList.h"

#include<iostream>

using namespace std;
int main(){
	cout << "1.顺序表实现" << endl;
	cout << "2.链表实现" << endl;
	int seleted;
	scanf("%d", &seleted);
	if (seleted == 1){
		int n = 10;              //演示程序的顺序表最大长度为10
		SeqList<int> r(n);
		char c; int i, x;
		do{
			cout << "\n 0...退出";
			cout << "\n 1...插入";
			cout << "\n 2...删除";
			cout << "\n 3...输出";
			cout << "\n 4...反转";
			cout << "\n 5...删除特定元素\n";
			cin >> c;
			switch (c){
			case '1':
				cout << "位置  元素值:";
				cin >> i >> x;
				r.Insert(i, x);
				break;
			case '2':
				cout << "位置:";
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
				cout << "请输入删除的数据：";
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
			cout << "\n 0...退出";
			cout << "\n 1...插入";
			cout << "\n 2...删除";
			cout << "\n 3...输出";
			cout << "\n 4...反转";
			cout << "\n 5...删除特定数据\n";
			cin >> c;
			switch (c) {
			case '1':
				cout << "位置  元素值:";
				cin >> i >> x;
				L.Insert(i, x);  break;
			case '2':
				cout << "位置:";
				cin >> i;
				L.Delete(i);  break;
			case '3':
				cout << "\n";  L.Output(cout);
				break;
			case '4':
				L.Reverse();
				break;
			case '5':
				cout << "请输入删除的数据：";
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