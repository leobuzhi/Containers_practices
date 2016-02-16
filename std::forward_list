//函数签名
//default (1)
//explicit forward_list(const allocator_type& alloc = allocator_type());
//fill(2)
//explicit forward_list(size_type n);
//explicit forward_list(size_type n, const value_type& val,
//	const allocator_type& alloc = allocator_type());
//range(3)
//template <class InputIterator>
//forward_list(InputIterator first, InputIterator last,
//	const allocator_type& alloc = allocator_type());
//copy(4)
//forward_list(const forward_list& fwdlst);
//forward_list(const forward_list& fwdlst, const allocator_type& alloc);
//move(5)
//forward_list(forward_list&& fwdlst);
//forward_list(forward_list&& fwdlst, const allocator_type& alloc);
//initializer list(6)
//forward_list(initializer_list<value_type> il,
//	const allocator_type& alloc = allocator_type());
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int> first_fl;
	forward_list<int> second_sl(8, 11);
	forward_list<int> third_sl(second_sl.begin(), second_sl.end());
	forward_list<int> fourth_sl(third_sl);
	forward_list<int> fifth_sl(move(fourth_sl));	//将fourth_sl的元素移至fifth_sl
	forward_list<int> sixth_sl = { 0,8,11 };
	cout << "first_fl:"; for (const int &x : first_fl) cout << x << " "; cout << endl;
	cout << "second_sl:"; for (const int &x : second_sl) cout << x << " "; cout << endl;
	cout << "third_sl:"; for (const int &x : third_sl) cout << x << " "; cout << endl;
	cout << "fourth_sl:"; for (const int &x : fourth_sl) cout << x << " "; cout << endl;
	cout << "fifth_sl:"; for (const int &x : fifth_sl) cout << x << " "; cout << endl;
	cout << "sixth_sl:"; for (const int &x : sixth_sl) cout << x << " "; cout << endl;
	return 0;
}
//输出：
//first_fl :
//second_sl :11 11 11 11 11 11 11 11
//third_sl :11 11 11 11 11 11 11 11
//fourth_sl :
//fifth_sl :11 11 11 11 11 11 11 11
//sixth_sl :

//函数签名
//copy(1)
//forward_list& operator= (const forward_list& fwdlst);
//move(2)
//forward_list& operator= (forward_list&& fwdlst);
//initializer list(3)
//forward_list& operator= (initializer_list<value_type> il);
#include<iostream>
#include<forward_list>
using namespace std;
template<class T>
T by_two(const T& x)
{
	T temp(x);
	for (int& y : temp)
		y *= 2;
	return temp;
}
int main()
{
	forward_list<int> first_fl(4);
	forward_list<int> second_fl(3, 5);

	first_fl = second_fl;		//copy assignment function 被调用,这里second_fl是lvalue
	second_fl = by_two(first_fl);		//move assignment function 被调用,by_two返回的值为rvalue
	
	cout << "first_fl:"; for (const int& x : first_fl) cout << x << " "; cout << endl;
	cout << "second_fl:"; for (const int& x : second_fl) cout << x << " "; cout << endl;
	return 0;
}
//输出：
//first_fl :5 5 5
//second_fl :10 10 10

//函数签名
//iterator before_begin() noexcept;
//const_iterator before_begin() const noexcept;
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//iterator end() noexcept;
//const_iterator end() const noexcept;
//const_iterator cbefore_begin() const noexcept;
//const_iterator cbegin() const noexcept;
//const_iterator cend() const noexcept;
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int> first_sl = { 20,30,40,50 };
	first_sl.insert_after(first_sl.before_begin(), 10);   
	for (auto it = first_sl.begin(); it != first_sl.end(); it++)
		cout << *it << " ";
	cout << endl;

	//cbefore_begin返回一个迭代器，该迭代器指向一个常数，该迭代器本身可以移动（除非该迭代器本身为const）
	first_sl.insert_after(first_sl.cbefore_begin(), 0);    
	for (auto it = first_sl.cbegin(); it != first_sl.cend();it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//10 20 30 40 50
//0 10 20 30 40 50

//函数签名
//bool empty() const noexcept;
//size_type max_size () const noexcept;
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int> first_sl = { 0,8,11 };
	if (first_sl.empty())
		cout << "empty" << endl;
	else
		cout << "not empty" << endl;
	//max_size取决于系统以及库的实现
	cout << "first_sl max_size is :" << first_sl.max_size() << endl;
	return 0;
}
//输出：
//not empty
//first_sl max_size is :536870911

//函数签名 
//reference front();
//const_reference front() const;
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int> first_sl = { 0,8,11 };
	first_sl.front() = 99;
	for (const int& x : first_sl)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//99 8 11

//函数签名
//range(1)
//template <class InputIterator>
//void assign(InputIterator first, InputIterator last);
//fill(2)
//void assign(size_type n, const value_type& val);
//initializer list(3)
//void assign(initializer_list<value_type> il);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	//使用assign 取代当前的内容并且修改其大小
	forward_list<int> first_sl = { 0,8,11 };
	forward_list<int> second_sl;
	forward_list<int> third_sl;
	forward_list<int> fourth_sl ;

	second_sl.assign(first_sl.begin(), first_sl.end());
	third_sl.assign(3, 1);
	fourth_sl.assign({2,3,4});
	cout << "first_sl:"; for (const int& x : first_sl) cout << x << " "; cout << endl;
	cout << "second_sl:"; for (const int& x : second_sl) cout << x << " "; cout << endl;
	cout << "third_sl:"; for (const int& x : third_sl) cout << x << " "; cout << endl;
	cout << "fourth_sl:"; for (const int& x : fourth_sl) cout << x << " "; cout << endl;

	return 0;
}
//输出：
//first_sl : 0 8 11
//second_sl : 0 8 11
//third_sl :1 1 1
fourth_sl :2 3 4

//函数签名
//template <class... Args>
//void emplace_front(Args&&... args);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	//在forward_list的起始位置插入一个新值
	forward_list<pair<int,char> > first_sl;
	first_sl.emplace_front(1, 'a');
	first_sl.emplace_front(2, 'b');
	first_sl.emplace_front(3,'c');
	for (const auto& x : first_sl)
		cout << x.first << " " << x.second << endl;
	cout << endl;
	return 0;
}
//输出：
//3 c
//2 b
//1 a

//函数签名
//void push_front(const value_type& vakl);
//void push_front(value_type&& val);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	//在forward_list的起始位置插入一个新值,注意和emplace_front的区别（看函数签名）
	forward_list<pair<int, char> > first_sl;
	first_sl.push_front(make_pair(2, 'a'));
	first_sl.push_front(make_pair(4, 'b'));
	first_sl.push_front(make_pair(6, 'c'));
	for (const auto& x : first_sl)
		cout << x.first << " " << x.second << endl;
	cout << endl;
	return 0;
}
//输出：
//6 c
//4 b
//2 a

//函数签名
//void pop_front();
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	//在forward_list的起始位置插入一个新值,注意和emplace_front的区别（看函数签名）
	forward_list<int > first_sl = { 1,2,3 };
	while (!first_sl.empty())
	{
		cout << first_sl.front() << endl;
		first_sl.pop_front();
	}
	cout << endl;
	return 0;
}
//输出：
//1 
//2
//3

//函数签名
//template <class... Args>
//iterator emplace_after(const_iterator position, Args&&... args);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 2,4,6 };
	first_sl.emplace_after(first_sl.begin(), 3);
	first_sl.emplace_after(first_sl.begin(), 5);
	for (const int&x : first_sl)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//2 5 3 4 6

//函数签名
//(1)iterator insert_after(const_iterator position, const value_type& val);
//(2)iterator insert_after(const_iterator position, value_type&& val);
//(3)iterator insert_after(const_iterator position, size_type n, const value_type& val);
//(4)template <class InputIterator>
//iterator insert_after(const_iterator position, InputIterator first, InputIterator last);
//(5)iterator insert_after(const_iterator position, initializer_list<value_type> il);
#include<iostream>
#include<forward_list>
#include<array>
using namespace std;
int main()
{
	array<int, 3> first_array = {1,2,3};
	forward_list<int > first_sl = { 2,4,6 };
	forward_list<int>::iterator it;
	it = first_sl.insert_after(first_sl.begin(), 0);	//现在it指向0
	it = first_sl.insert_after(it, 2, 4);				//现在it指向第二个4
	it = first_sl.insert_after(it, first_array.begin(), first_array.end());   //现在it指向3
	first_sl.insert_after(first_sl.begin(), { 0,0,0 });
	for (const int&x : first_sl)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//2 0 0 0 0 4 4 1 2 3 4 6

//函数签名
//iterator erase_after(const_iterator position);
//iterator erase_after(const_iterator position, const_iterator last);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3,4,5 };
	auto it = first_sl.begin();
	it = first_sl.erase_after(it);	//删除2，现在it指向3
	first_sl.erase_after(it, first_sl.end());
	for (const int&x : first_sl)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//1 3

//函数签名
//void swap(forward_list& fwdlst);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3 };
	forward_list<int > second_sl = { 4,5,6 };
	first_sl.swap(second_sl);
	for (const int&x : first_sl)
		cout << x << " ";
	cout << endl;
	for (const int&x : second_sl)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//4 5 6
//1 2 3

//函数签名
//void resize(size_type n);
//void resize(size_type n, const value_type& val);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3,4,5 };
	first_sl.resize(3);//现在first_sl为 1 2 3
	first_sl.resize(5, 0);//现在first_sl为1 2 3 0 0
	for (const int&x : first_sl)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//1 2 3 0 0

//函数签名
//void clear() noexcept;
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3,4,5 };
	first_sl.clear();
	if (first_sl.empty())
		cout << "empty" << endl;
	else
		cout << "not empty" << endl;
	return 0;
}
//输出：
//empty

//函数签名
//entire list(1)
//void splice_after(const_iterator position, forward_list& fwdlst);
//void splice_after(const_iterator position, forward_list&& fwdlst);
//single element(2)
//void splice_after(const_iterator position, forward_list& fwdlst, const_iterator i);
//void splice_after(const_iterator position, forward_list&& fwdlst, const_iterator i);
//element range(3)
//void splice_after(const_iterator position, forward_list& fwdlst,
//	const_iterator first, const_iterator last);
//void splice_after(const_iterator position, forward_list&& fwdlst,
//	const_iterator first, const_iterator last);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3 };
	forward_list<int > second_sl = { 4,5,6 };
	auto it = first_sl.begin();
	//first_sl：4 5 6 1 2 3    second_sl：
	first_sl.splice_after(first_sl.before_begin(), second_sl);	
	//first_sl：4 1 2 3    second_sl：5 6 
	second_sl.splice_after(second_sl.before_begin(), first_sl, first_sl.begin(), it);
	//first_sl：6 4 1 2 3  second_sl：5
	first_sl.splice_after(first_sl.before_begin(), second_sl, second_sl.begin());

	for (const auto& x : first_sl)cout << x << " ";
	cout << endl;
	for (const auto& x : second_sl)cout << x << " ";
	cout << endl;

	return 0;
}
//输出：
//6 4 1 2 3 
//5

//函数签名
//void remove(const value_type& val);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3,4,5,5,4,3,2,1 };
	first_sl.remove(4);
	for each (auto var in first_sl)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//1 2 3 5 5 3 2 1

//函数签名
//template <class Predicate>
//void remove_if(Predicate pred);
#include<iostream>
#include<forward_list>
using namespace std;
bool single_digit(const int & value)
{
	return value < 10;
}
class is_old 
{
public:
	bool operator() (const int& value)
	{
		return (value % 2) == 1;
	}
};
int main()
{
	forward_list<int > first_sl = { 1,2,3,4,5,11,22,33,44,55 };
	first_sl.remove_if(single_digit);		//传一个方法
	first_sl.remove_if(is_old());		//传一个对象，该对象实现了()操作符
	for each (auto var in first_sl)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//22 44

//函数签名
//(1)void unique();
//(2)template <class BinaryPredicate>
//void unique(BinaryPredicate binary_pred);
#include<iostream>
#include<forward_list>
#include<algorithm>
using namespace std;

bool same_int(const double& a, const double &b)
{
	return (int)a == (int)b;
}
class is_near 
{
public:
	bool operator()(const double& a, const double & b)
	{
		return abs(a - b) < 3;
	}
};

int main()
{
	forward_list<double > first_sl = { 1.1,2.2,2.4,2.2,4,5,1.1,2.2,3.3,15.5,8.5 };
	//unique函数只会删除相邻相同的元素，如果该链表未排序，使用意义不大
	first_sl.sort();
	first_sl.unique();		//删除相同元素
	first_sl.unique(same_int);		//删除整数相同的元素
	first_sl.unique(is_near());		//删除插值小于3的元素
	for each (auto var in first_sl)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//1.1 5 8.5 15.5

//函数签名
//(1)void merge(forward_list& fwdlst);
//void merge(forward_list&& fwdlst);
//(2)template <class Compare>
//void merge(forward_list& fwdlst, Compare comp);
//template <class Compare>
//void merge(forward_list&& fwdlst, Compare comp);
#include<iostream>
#include<forward_list>
#include<functional>
using namespace std;
int main()
{
	forward_list<double > first_sl = { 1,3,5 };
	forward_list<double > second_sl = { 2,4,6 };
	forward_list<double > third_sl = { 6 ,8, 10};
	first_sl.merge(second_sl);		//合并两个forward_list,两个forward_list必须都是有序的，second_sl的元素被移至first_sl
	for each (auto var in first_sl)
	{
		cout << var << " ";
	}
	cout << endl;
	first_sl.sort(greater<double>());
	third_sl.sort(greater<double>());
	third_sl.merge(first_sl,greater<double>());			//传一个函数对象
	for each (auto var in third_sl)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//1 2 3 4 5 6
//10 8 6 6 5 4 3 2 1

//函数签名
//(1)void sort();
//(2)template <class Compare>
//void sort(Compare comp);
#include<iostream>
#include<forward_list>
#include<functional>
using namespace std;
int main()
{
	forward_list<double > first_sl = { 2,4,6,1,3,5 };
	first_sl.sort();
	for each (auto var in first_sl)
	{
		cout << var << " ";
	}
	cout << endl;
	first_sl.sort(greater<double>());
	for each (auto var in first_sl)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//1 2 3 4 5 6
//6 5 4 3 2 1

//函数签名
//void reverse() noexcept;
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3 };
	first_sl.reverse();		//逆置forward_list
	for each (auto var in first_sl)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//3 2 1

//函数签名
//(1)
//template <class T, class Alloc>
//bool operator== (const forward_list<T, Alloc>& lhs, const forward_list<T, Alloc>& rhs);
//(2)
//template <class T, class Alloc>
//bool operator!= (const forward_list<T, Alloc>& lhs, const forward_list<T, Alloc>& rhs);
//(3)
//template <class T, class Alloc>
//bool operator<  (const forward_list<T, Alloc>& lhs, const forward_list<T, Alloc>& rhs);
//(4)
//template <class T, class Alloc>
//bool operator<= (const forward_list<T, Alloc>& lhs, const forward_list<T, Alloc>& rhs);
//(5)
//template <class T, class Alloc>
//bool operator>  (const forward_list<T, Alloc>& lhs, const forward_list<T, Alloc>& rhs);
//(6)
//template <class T, class Alloc>
//bool operator>= (const forward_list<T, Alloc>& lhs, const forward_list<T, Alloc>& rhs);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3 };
	forward_list<int > second_sl = { 1,2,3 };
	forward_list<int > third_sl = { 1,1,4 };
	if (first_sl == second_sl)
		cout << "first_sl==second_sl" << endl;
	if (first_sl != second_sl)
		cout << "first_sl!=second_sl" << endl;
	if(second_sl>=third_sl)
		cout << "second_sl>=third_sl" << endl;
	if(second_sl <= third_sl)
		cout << "second_sl<=third_sl" << endl;
	return 0;
}
//输出：
//first_sl == second_sl
//second_sl >= third_sl

//函数签名
//template <class T, class Alloc>
//void swap(forward_list<T, Alloc>& x, forward_list<T, Alloc>& y);
#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
	forward_list<int > first_sl = { 1,2,3 };
	forward_list<int > second_sl = { 3,2,1 };
	swap(first_sl, second_sl);
	for (const auto& x : first_sl)
		cout << x << " ";
	cout << endl;
	for (const auto& x : second_sl)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//3 2 1
//1 2 3
