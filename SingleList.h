
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
  
 //反转函数
 template<class T>
 void SingleList<T>::Reverse(){
	 int m = n;                                  //计数器m  while循环使用 共执行m次
	 int i = -1;                                 //当截取的节点为头指针时
	 Node<T>*p = first;
	 Node<T>*q = first;
	 while (m){
		 if (i > -1){
			 q = p->link;                         //q变为p的下一个
			 p->link = first;                     //p指向first,摘取p
			 first = p;                           //first向后移动指向p
			 p = q;                               //p又变成原链表的下一个元素
		 }//end if
		 else{ 
			 q = p->link;                         //q变为p的下一个
			 p->link = NULL;                      //当引入摘取第一个元素的时候设p的下一个指向NULL
			 first = p;                           //first变成p    /指针进行反转
			 p = q;
		 }//end else
		 i++;
	     m--;                                     //执行m次
	 }//end while
	 
 }//end Reverse

 //批量删除函数
 template <class T>
 bool SingleList<T>::DeleteX(const T&x){
	 Node<T>*p = first;                        
	 bool IsExist = false;                          //判断是否存在删除的元素
	 for (int i = 0; i < n&&p!=NULL; i++){
		 if (p->element == x){                      //当元素相同时进行删除工作
			 IsExist = true;
			 p = p->link;
			 Delete(i);                             //删除坐标为i元素
			 i--;                                   //相应的元素的坐标前移一位
		 }//end if
		 else{
			 p = p->link;
		 }//end else
	 }//end for
	 if (!IsExist){
		 cout << "未查到这个数据";
		 return false;
	 }//end if
	 return true;
 }//end DeleteX