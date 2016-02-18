//函数签名
//default (1)
//explicit vector(const allocator_type& alloc = allocator_type());
//fill(2)
//vector(size_type n, const value_type& val,
//	const allocator_type& alloc = allocator_type());
//range(3)
//template <class InputIterator>
//vector(InputIterator first, InputIterator last,
//	const allocator_type& alloc = allocator_type());
//copy(4)
//vector(const vector& x);
//vector(const vector& x, const allocator_type& alloc);
//move(5)
//vector(vector&& x);
//vector(vector&& x, const allocator_type& alloc);
//initializer list(6)
//vector(initializer_list<value_type> il,
//	const allocator_type& alloc = allocator_type());
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> first_vector;
	vector<int> second_vector(4, 100);
	vector<int> third_vector(second_vector.begin(), second_vector.end());
	vector<int> fourth_vector(third_vector);

	int array[] = { 0,8,11 };
	vector<int> my_vector(array, array + sizeof(array) / sizeof(int));

	for each (auto var in my_vector)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//0 8 11

//函数签名  
//copy(1)  
//vector& operator= (const vector& x);  
//move(2)  
//vector& operator= (vector&& x);  
//initializer list(3)  
//vector& operator= (initializer_list<value_type> il);  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> first_vector(8, 0);
	vector<int> second_vector(11, 0);

	second_vector = first_vector;
	first_vector = vector<int>();

	cout << first_vector.size() << endl;
	cout << second_vector.size() << endl;
	return 0;
}
//输出：
//0
//8

//函数签名  
//iterator begin() noexcept;  
//const_iterator begin() const noexcept;  
//iterator end() noexcept;  
//const_iterator end() const noexcept;  
//reverse_iterator rbegin();  
//const_reverse_iterator rbegin() const;  
//const_iterator cbegin() const noexcept;  
//const_iterator cend() const noexcept;  
//const_reverse_iterator crbegin() const noexcept;  
//const_reverse_iterator crend() const noexcept;  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> my_vector = { 0,8,11 };

	for (vector<int>::iterator it = my_vector.begin(); it != my_vector.end(); it++)
		cout << *it << " ";
	cout << endl;

	for (vector<int>::reverse_iterator it = my_vector.rbegin(); it != my_vector.rend(); it++)
		cout << *it << " ";
	cout << endl;

	for (vector<int>::const_iterator it = my_vector.cbegin(); it != my_vector.cend(); it++)
		cout << *it << " ";
	cout << endl;

	for (vector<int>::const_reverse_iterator it = my_vector.crbegin(); it != my_vector.crend(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}
//输出：
//0 8 11
//11 8 0
//0 8 11
//11 8 0

//函数签名  
//size_type size() const;  
//size_type max_size() const;  
//size_type capacity() const;  
//void resize(size_type n, value_type val = value_type());  
//bool empty() const;  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> my_vector;

	for (int i = 1; i <= 100; i++)
		my_vector.push_back(i);

	cout << my_vector.size() << endl;
	//vector增长方式取决去STL的实现，绝大多数STL实现都是以成倍的方式增长，但标准并没规定  
	cout << my_vector.capacity() << endl;
	//max_size取决于STL的实现  
	cout << my_vector.max_size() << endl;

	//多余的直接抛弃  
	my_vector.resize(3);
	for each (auto var in my_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	//不够的直接用第二个参数补齐  
	my_vector.resize(5, 1);
	for each (auto var in my_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	//若不够并且没有第二个参数，则用0补齐  
	my_vector.resize(7);
	for each (auto var in my_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	if (my_vector.empty())
		cout << "empty vector" << endl;
	else
		cout << "not empty vector" << endl;

	return 0;
}
//输出：
//100
//141
//1073741834
//1 2 3
//1 2 3 1 1
//1 2 3 1 1 0 0
//not empty vector

//函数签名  
//void reserve (size_type n);  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	//我使用的是VS2015   
	//vector增长方式是：1 2 3 4 6 9 13 19 28 42 63 94 141（与绝大多数以2的指数增长实现不一样）  
	vector<int> first_vector;
	for (int i = 0; i != 100; i++)
		first_vector.push_back(i);
	cout << first_vector.capacity() << endl;

	//如果事先知道vector要放多少个元素，则可以使用reserve()节省空间  
	vector<int> second_vector;
	second_vector.reserve(100);
	for (int i = 0; i != 100; i++)
		second_vector.push_back(i);
	cout << second_vector.capacity() << endl;
	return 0;
}
//输出：
//141
//100

//函数签名  
//void shrink_to_fit();  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> my_vector;
	for (int i = 0; i != 6; i++)
		my_vector.push_back(i);
	cout << my_vector.size() << endl;
	cout << my_vector.capacity() << endl;

	my_vector.resize(4);
	cout << my_vector.size() << endl;
	cout << my_vector.capacity() << endl;

	//注意使用resize()并没有释放空间，必须使用  
	my_vector.shrink_to_fit();
	cout << my_vector.size() << endl;
	cout << my_vector.capacity() << endl;
	return 0;
}
//输出：
//6
//6
//4
//6
//4
//4

//函数签名  
//reference operator[] (size_type n);  
//const_reference operator[] (size_type n) const;  
//reference at(size_type n);  
//const_reference at(size_type n) const;  
//reference front();  
//const_reference front() const;  
//reference back();  
//const_reference back() const;  
//value_type* data() noexcept;  
//const value_type* data() const noexcept;  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> my_vector(10);
	for (int i = 0; i != 10; i++)
		my_vector[i] = i;

	for (int i = 0; i != 10; i++)
		cout << my_vector.at(i) << " ";
	cout << endl;

	cout << my_vector.front() << endl;
	cout << my_vector.back() << endl;
	return 0;
}
//输出：
//0 1 2 3 4 5 6 7 8 9
//0
//9

//函数签名  
//value_type* data() noexcept;  
//const value_type* data() const noexcept;  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> my_vector(5);
	//返回一个指向数据的指针，类似一个指向数组的指针  
	int *p = my_vector.data();

	*p = 1;
	p++;
	*p = 2;
	//相当于p现在指向的位置+2  
	p[2] = 3;
	for (int i = 0; i != 5; i++)
		cout << my_vector[i] << " ";
	cout << endl;
	return 0;
}
//输出：
//1 2 0 3 0

//函数签名  
//range(1)  
//template <class InputIterator>  
//void assign(InputIterator first, InputIterator last);  
//fill(2)  
//void assign(size_type n, const value_type& val);  
//initializer list(3)  
//void assign(initializer_list<value_type> il);  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> first_vector;
	vector<int> second_vector;
	vector<int> third_vector;

	//5个100  
	first_vector.assign(5, 100);
	auto it = first_vector.begin() + 1;

	second_vector.assign(it, first_vector.end() - 1);

	int ints[] = { 0,8,11 };
	third_vector.assign(ints, ints + 3);

	for each (auto var in first_vector)
	{
		cout << var << " ";
	}
	cout << endl;
	for each (auto var in second_vector)
	{
		cout << var << " ";
	}
	cout << endl;
	for each (auto var in third_vector)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//100 100 100 100 100
//100 100 100
//0 8 11

//函数签名  
//void push_back(const value_type& val);  
//void push_back(value_type&& val);  
//void pop_back();  
//single element(1)  
//iterator insert(const_iterator position, const value_type& val);  
//fill(2)  
//iterator insert(const_iterator position, size_type n, const value_type& val);  
//range(3)  
//template <class InputIterator>  
//iterator insert(const_iterator position, InputIterator first, InputIterator last);  
//move(4)  
//iterator insert(const_iterator position, value_type&& val);  
//initializer list(5)  
//iterator insert(const_iterator position, initializer_list<value_type> il);  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> first_vector;
	first_vector.push_back(1);
	first_vector.push_back(2);
	auto it = first_vector.begin() + 1;
	first_vector.insert(it, 3);

	for each (auto var in first_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	vector<int> second_vector(3, 100);
	//注意这里要重新让迭代器指向一个位置，因为插入之后会使迭代器失效  
	it = second_vector.begin() + 2;
	second_vector.insert(it, first_vector.begin() + 1, first_vector.end());

	for each (auto var in second_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	int myints[] = { 6,6,6 };
	second_vector.insert(second_vector.begin(), myints, myints + 3);
	for each (auto var in second_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	second_vector.pop_back();
	for each (auto var in second_vector)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//1 3 2
//100 100 3 2 100
//6 6 6 100 100 3 2 100
//6 6 6 100 100 3 2 

//函数签名  
//iterator erase(const_iterator position);  
//iterator erase(const_iterator first, const_iterator last);  
//void swap(vector& x);  
//template <class... Args>  
//iterator emplace(const_iterator position, Args&&... args);  
//template <class... Args>  
//void emplace_back(Args&&... args);  
//template <class... Args>  
//void emplace_back(Args&&... args);  
//void clear() noexcept;  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> first_vector;
	vector<int> second_vector;
	for (int i = 1; i <= 10; i++)
		first_vector.push_back(i);
	//删除第四个元素  
	first_vector.erase(first_vector.begin() + 3);

	//删除第5到第七个元素  
	first_vector.erase(first_vector.begin() + 4, first_vector.begin() + 6);

	for each (auto var in first_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	first_vector.swap(second_vector);
	cout << second_vector.size();
	cout << endl;

	//在起始位置插入一个100  
	second_vector.emplace(second_vector.begin(), 100);
	for each (auto var in second_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	//在末尾插入一个200  
	second_vector.emplace_back(200);
	for each (auto var in second_vector)
	{
		cout << var << " ";
	}
	cout << endl;

	second_vector.clear();
	cout << second_vector.size();
	cout << endl;
	return 0;
}
//输出：
//1 2 3 5 8 9 10
//7
//100 1 2 3 5 8 9 10
//100 1 2 3 5 8 9 10 200
//0

//函数签名  
//allocator_type get_allocator() const noexcept;  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> my_vector;
	int *p;
	unsigned int i;
	//用vector的allocator分配五个int的空间  
	p = my_vector.get_allocator().allocate(5);

	for (i = 0; i != 5; i++)
		my_vector.get_allocator().construct(&p[i], i);

	for (int i = 0; i != 5; i++)
		cout << p[i] << " ";
	cout << endl;

	for (i = 0; i != 5; i++)
		my_vector.get_allocator().destroy(&p[i]);
	my_vector.get_allocator().deallocate(p, 5);

	return 0;
}
//输出：
//0 1 2 3 4

//函数签名  
//(1)  
//template <class T, class Alloc>  
//bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);  
//(2)  
//template <class T, class Alloc>  
//bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);  
//(3)  
//template <class T, class Alloc>  
//bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);  
//(4)  
//template <class T, class Alloc>  
//bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);  
//(5)  
//template <class T, class Alloc>  
//bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);  
//(6)  
//template <class T, class Alloc>  
//bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	vector<int> first_vector = { 1,2,3 };
	vector<int> second_vector = { 3,2,1 };

	if (first_vector == second_vector)
		cout << "first_vector and second_vector are equal\n";
	if (first_vector != second_vector)
		cout << "first_vector and second_vector are not equal\n";
	if (first_vector< second_vector)
		cout << "first_vector is less than second_vector\n";
	if (first_vector> second_vector)
		cout << "first_vector is greater than second_vector\n";
	if (first_vector <= second_vector)
		cout << "first_vector is less than or equal to second_vector\n";
	if (first_vector >= second_vector)
		cout << "first_vector is greater than or equal to second_vector\n";
	return 0;
}
//输出：
//first_vector and second_vector are not equal
//first_vector is less than second_vector
//first_vector is less than or equal to second_vector

//函数签名  
//template <class T, class Alloc>  
//void swap(vector<T, Alloc>& x, vector<T, Alloc>& y);  
#include<iostream>  
#include<vector>  
using namespace std;
int main()
{
	//非成员函数的swap()效率小于等于成员函数的swap(),所以建议用成员函数版的  
	vector<int> first_vector = { 1,2,3 };
	vector<int> second_vector = { 3,2,1 };

	swap(first_vector, second_vector);
	for each (auto var in first_vector)
	{
		cout << var << " ";
	}
	cout << endl;
	for each (auto var in second_vector)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//3 2 1
//1 2 3
