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

//��ת����
template <class T>
void SeqList<T>::Reverse(){
	for (int i = 0; i < n / 2; i++){    //ѭ��n/2��
		T tem;                          //�������м����
		tem = elements[i];
		elements[i] = elements[n - 1-i]; //���н���
		elements[n - 1-i] = tem;         //���н���
	}//end for
}//end Reverse

//����ɾ������
template <class T>
bool SeqList<T>::DeleteX(const T&x){
	bool IsExist = false;                //ɾ���ĺ����Ƿ����
	for (int i = 0; i < n; i++){   
		if (elements[i] == x){           //Ԫ����ͬʱ����ɾ������
			IsExist = true;
			Delete(i);                   //ɾ���±�Ϊi��Ԫ��
			i = i - 1;                   //��Ӧ��Ԫ���±��һ
		}//end if
		
	}//end for
	if (!IsExist){
		cout << "δ�鵽�������";
		return false;
	}//end if
	return true;
}//end DeleteX