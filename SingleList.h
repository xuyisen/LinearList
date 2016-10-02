
#include<iostream>
using namespace std;
template <class T> 
class SingleList;
template<class T>
class Node{
private:
	T element;
	Node<T> *link;
	friend class SingleList<T>;
};
  template<class T>
class SingleList{
public:
	SingleList(){ first = NULL; n = 0; }
	~SingleList();
	bool IsEmpty()const;
	int Length()const;
	bool Find(int i, T &x)const;
	int Search(T x)const;
	bool Insert(int i, T x);
	bool Delete(int i);
	bool Update(int i, T x);
	bool DeleteX(const T&x);
	void Reverse();
	void Output(ostream&out)const;
	int n;
private:
	Node<T>*first;
	
};
template<class T>
SingleList<T>::~SingleList(){
	Node<T>*p;
	while (first){
		
		p = first->link;
		delete first;
		first = p;
	}
}
template <class T>
int SingleList<T>::Length()const{
	return n;
}
template <class T>
bool SingleList<T>::IsEmpty()const{
	return n == 0;
}
template<class T>
bool SingleList<T>::Find(int i, T &x)const{
	if (i < 0 || i>n - 1){
		cout << "Out of Bounds";
		return false;
	}
	Node<T>*p = first;
	for (int j = 0; j < i; j++){
		p = p->link;
	}
	x = p->element;
	return true;
	
}
template <class T>
bool SingleList<T>::Insert(int i, T x){
	if (i < -1|| i>n - 1){
		cout << "Out Of Bounds";
		return false;
	}
	Node<T>*q = new Node<T>;
	Node<T>*p = first;
	q->element = x;
	for (int j = 0; j < i; j++){
		p = p->link;
	}
		if (i > -1){
			q->link = p->link;
			p->link = q;
		}
		else{
			q->link = first;
			first = q;
		}
		n++;
		return true;
}

 template<class T>
 int SingleList<T>::Search(T x)const{
	 Node<T>*p = first;
	 for (int j = 0; p&&p->element != x; j++){
		 p = p->link;
	 }
	 if (p){
		 return j;
	 }
	 return -1;
 }
 template<class T>
 bool SingleList<T>::Delete(int i){
	 if (!n){
		 cout << "UnderFlow" << endl;
		 return false;
	 }
	 if (i < 0 || i>n - 1){
		 cout << "Out Of Bounds" << endl;
		 return false;
	 }
	 Node<T>*p = first; 
	 Node<T>*q = first;

	 for (int j = 0; j < i; j++){
		 p = p->link;
	 }
	 if (i == 0){
		 first = first->link;
	 }
	 else{
		 q = p->link;
		 p->link = q->link;
	 }
	 delete q;
	 n--;
	 return true;
 }

 template<class T>
 bool SingleList<T>::Update(int i, T x){
	 if (i<0 || i>n - 1){
		 cout << "Out Of Bounds" << endl;
		 return false;
	 }
	 Node<T>*p = first;
	 for (int j = 0; j < i; j++){
		 p = p->link;
	 }
	 p->element = x;
	 return true;

 }
 template<class T>
 void SingleList<T>::Output(ostream&out)const{
	 Node<T>*p = first;
	 while (p){
		 out << p->element << "  ";
		 p = p->link;
	 }
	 out << endl;
 }
  
 //��ת����
 template<class T>
 void SingleList<T>::Reverse(){
	 int m = n;                                  //������m  whileѭ��ʹ�� ��ִ��m��
	 int i = -1;                                 //����ȡ�Ľڵ�Ϊͷָ��ʱ
	 Node<T>*p = first;
	 Node<T>*q = first;
	 while (m){
		 if (i > -1){
			 q = p->link;                         //q��Ϊp����һ��
			 p->link = first;                     //pָ��first,ժȡp
			 first = p;                           //first����ƶ�ָ��p
			 p = q;                               //p�ֱ��ԭ�������һ��Ԫ��
		 }//end if
		 else{ 
			 q = p->link;                         //q��Ϊp����һ��
			 p->link = NULL;                      //������ժȡ��һ��Ԫ�ص�ʱ����p����һ��ָ��NULL
			 first = p;                           //first���p    /ָ����з�ת
			 p = q;
		 }//end else
		 i++;
	     m--;                                     //ִ��m��
	 }//end while
	 
 }//end Reverse

 //����ɾ������
 template <class T>
 bool SingleList<T>::DeleteX(const T&x){
	 Node<T>*p = first;                        
	 bool IsExist = false;                          //�ж��Ƿ����ɾ����Ԫ��
	 for (int i = 0; i < n&&p!=NULL; i++){
		 if (p->element == x){                      //��Ԫ����ͬʱ����ɾ������
			 IsExist = true;
			 p = p->link;
			 Delete(i);                             //ɾ������ΪiԪ��
			 i--;                                   //��Ӧ��Ԫ�ص�����ǰ��һλ
		 }//end if
		 else{
			 p = p->link;
		 }//end else
	 }//end for
	 if (!IsExist){
		 cout << "δ�鵽�������";
		 return false;
	 }//end if
	 return true;
 }//end DeleteX