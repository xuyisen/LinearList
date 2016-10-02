#include"LinearList.h"
#include<iostream>
using namespace std;
template<class T>
class SeqList :public LinearList<T>{
public:
	SeqList(int mSize);
	~SeqList(){
		delete[] elements;
	}
	bool IsEmpty()const;
	int Length()const;
	bool Find(int i, T&x)const;
	int Search(T x)const;
	bool Insert(int i, T x);
	bool Delete(int i);
	bool Update(int i, T x);
	void Reverse();
	bool DeleteX(const T&x);
	void Output(ostream &out)const;
private:
	int maxLength;
	T *elements;
};
template<class T>
SeqList<T>::SeqList(int mSize){
	maxLength = mSize;
	elements = new T[maxLength];
	n = 0;
}
template <class T>
bool SeqList<T>::IsEmpty()const{
	return n == 0;
}
template <class T>
int SeqList<T>::Length()const{
	return n;
}
template <class T>
bool SeqList<T>::Find(int i, T &x)const{
	if (i<0 || i>n - 1){
		cout << "Out of Bounds" << endl;
		return false;
	}
	x = elements[i];
	return true;
}
template<class T>
int SeqList<T>::Search(T x)const{
	for (int i = 0; i < n; i++){
		if (x == elements[i]){
			return i;
		}
	}
	return -1;
}
template <class T>
bool SeqList<T>::Insert(int i, T x){
	if (i<-1 || i>n - 1){
		cout << "Out Of Bounds" << endl;
		return false;
	}
	if (n == maxLength){
		cout << "OverFlow" << endl;
		return false;
	}
	for (int j = n - 1; j > i; j--){
		elements[j + 1] = elements[j];
	}
	elements[i + 1] = x;
	n++;
	return true;
}
template<class T>
bool SeqList<T>::Delete(int i){
	if (!n){
		cout << "UnderFlow" << endl;
		return false;
	}
	if (i < 0 || i>n - 1){
		cout << "Out Of Bounds" << endl;
		return false;
	}
	for (int j = i + 1; j < n; j++){
		elements[j - 1] = elements[j];
	}
	n--;
	return true;

}
template<class T>
bool SeqList<T>::Update(int i, T x){
	if (i<0 || i>n - 1){
		cout << "Out Of Bounds" << endl;
		return false;
	}
	elements[i] = x;
	return true;
}
template<class T>
void SeqList<T>::Output(ostream&out)const{
	for (int i = 0; i < n; i++){
		out << elements[i] << "  ";
		
	}
	out << endl;
}

template<class T>
void Union(SeqList<T> &LA, SeqList<T>&LB){
	T x;
	for (int i = 0; i < LA.Length(); i++){
		LA.Find(i, x);
		if (LB.Search(x) == -1){
			LB.Insert(LB.Length() - 1, x);
		}
	}

}

//反转函数
template <class T>
void SeqList<T>::Reverse(){
	for (int i = 0; i < n / 2; i++){    //循环n/2次
		T tem;                          //交换的中间变量
		tem = elements[i];
		elements[i] = elements[n - 1-i]; //进行交换
		elements[n - 1-i] = tem;         //进行交换
	}//end for
}//end Reverse

//批量删除函数
template <class T>
bool SeqList<T>::DeleteX(const T&x){
	bool IsExist = false;                //删除的函数是否存在
	for (int i = 0; i < n; i++){   
		if (elements[i] == x){           //元素相同时进行删除操作
			IsExist = true;
			Delete(i);                   //删除下标为i的元素
			i = i - 1;                   //相应的元素下标减一
		}//end if
		
	}//end for
	if (!IsExist){
		cout << "未查到这个数据";
		return false;
	}//end if
	return true;
}//end DeleteX