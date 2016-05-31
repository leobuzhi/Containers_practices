//函数签名(构造函数)：
//default (1)
//explicit deque(const allocator_type& alloc = allocator_type());
//fill(2)
//explicit deque(size_type n);
//deque(size_type n, const value_type& val,
//	const allocator_type& alloc = allocator_type());
//range(3)
//template <class InputIterator>
//deque(InputIterator first, InputIterator last,
//	const allocator_type& alloc = allocator_type());
//copy(4)
//deque(const deque& x);
//deque(const deque& x, const allocator_type& alloc);
//move(5)
//deque(deque&& x);
//deque(deque&& x, const allocator_type& alloc);
//initializer list(6)
//deque(initializer_list<value_type> il,
//	const allocator_type& alloc = allocator_type());
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	//使用构造函数
	deque<int> first_deque;	 // 空deque
	deque<int> second_deque(4, 100);							//4个100
	deque<int> third_deque(second_deque.begin(), second_deque.end());		//和second_deque一样
	deque<int> fourth_deque(third_deque);						//和third_deque一样

																//使用迭代器构造函数复制数组
	int my_ints[] = { 0,8,11 };
	deque<int> fifth_deque(my_ints, my_ints + sizeof(my_ints) / sizeof(int));
	for (auto it = fifth_deque.begin(); it != fifth_deque.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//0 8 11

//函数签名(构造函数)：
//copy(1)
//deque& operator= (const deque& x);
//move(2)
//deque& operator= (deque&& x);
//initializer list(3)
//deque& operator= (initializer_list<value_type> il);
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> first_deque(8);			//8个0
	deque<int> second_deque(11);			//11个0

	second_deque = first_deque;
	first_deque = deque<int>();
	cout << "Size of first_deque  is " << int(first_deque.size()) << endl;
	cout << "Size of second_deque is " << int(second_deque.size()) << endl;

	return 0;
}
//输出：
//Size of first_deque  is 8
//Size of first_deque  is 11

//函数签名
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int	main()
{
	deque<int> my_deque;
	for (int i = 0; i != 5; i++)
		my_deque.push_back(i + 1);
	auto it = my_deque.begin();
	while (it != my_deque.end())
	{
		cout << *it++ << " ";
	}
	return 0;
}
//输出：
//1 2 3 4 5

//函数签名
//iterator end() noexcept;
//const_iterator end() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque;
	for (int i = 1; i <= 5; i++)
		my_deque.insert(my_deque.end(), i);				//注意这里是每次都插入末尾

	for (auto it = my_deque.begin(); it != my_deque.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//1 2 3 4 5

//函数签名
//reverse_iterator rbegin() noexcept;
//const_reverse_iterator rbegin() const noexcept;
//reverse_iterator rend() noexcept;
//const_reverse_iterator rend() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque(5);
	int i = 0;
	//注： it 类型为 deque<int>::reverse_iterator
	for (auto it = my_deque.rbegin(); it != my_deque.rend(); it++)
		*it = ++i;
	for (auto it = my_deque.begin(); it != my_deque.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//5 4 3 2 1

//函数签名
//const_iterator cbegin() const noexcept;
//const_iterator cend() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque = { 1,2,3,4,5 };
	//注： 常量迭代器设置迭代器指向的内容为常量，但是迭代器可以移动（除非迭代器也为const）
	for (auto it = my_deque.cbegin(); it != my_deque.cend(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//1 2 3 4 5

//函数签名
//const_reverse_iterator crbegin() const noexcept;
//const_reverse_iterator crend() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque = { 1,2,3,4,5 };
	int i = 0;
	for (auto it = my_deque.crbegin(); it != my_deque.crend(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//5 4 3 2 1

//函数签名
//size_type size() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque;
	cout << "Size of my_deque is " << my_deque.size() << endl;

	for (int i = 0; i != 5; i++)
		my_deque.push_back(i);
	cout << "Size of my_deque is " << my_deque.size() << endl;

	my_deque.insert(my_deque.begin(), 5, 100);
	//此时my_deque 里的值为100 100 100 100 100 0 1 2 3 4
	cout << "Size of my_deque is " << my_deque.size() << endl;

	my_deque.pop_back();
	cout << "Size of my_deque is " << my_deque.size() << endl;
	return 0;
}
//输出：
//Size of my_deque is 0
//Size of my_deque is 5
//Size of my_deque is 10
//Size of my_deque is 9

//函数签名
//size_type max_size() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	//注：max_size()取决于不同STL的实现
	deque<int> my_deque;
	int i;
	cin >> i;
	if (i < my_deque.max_size())
	{
		my_deque.resize(i);
		cout << "Size of my_deque is " << i << endl;
	}
	else
		cout << "Size exceeds the limit" << endl;
	return 0;
}
//输入：3
//输出：Size of my_deque is 3
//输入：999999999999999
//输出：Size exceeds the limit

//函数签名
//void resize(size_type n);
//void resize(size_type n, const value_type& val);
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque;
	for (int i = 1; i <= 10; i++)
		my_deque.push_back(i);

	//若参数小于当前的size,则使deque的大小减小到参数大小
	//deque多余的内容被移除
	my_deque.resize(5);
	for (auto it = my_deque.begin(); it != my_deque.end(); it++)
		cout << *it << " ";
	cout << endl;
	//若参数大于当前的size,则使deque的大小增加到到第一个参数大小
	//给了第二个参数时，填充的值为第二个参数
	my_deque.resize(8, 10);
	for (auto it = my_deque.begin(); it != my_deque.end(); it++)
		cout << *it << " ";
	cout << endl;
	//若参数大于当前的size,则使deque的大小增加到到第一个参数大小
	//没给第二个参数时，填充的值0
	my_deque.resize(12);
	for (auto it = my_deque.begin(); it != my_deque.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}
//输出：
//1 2 3 4 5
//1 2 3 4 5 10 10 10
//1 2 3 4 5 10 10 10 0 0 0 0 

//函数签名
//bool empty() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque;
	int sum = 0;
	for (int i = 1; i <= 10; i++)
		my_deque.push_back(i);
	//注：判空是用empty函数而不是判断size()==0，前者效率大于等于后者，取决于STL的实现
	while (!my_deque.empty())
	{
		sum += my_deque.front();
		my_deque.pop_front();
	}
	cout << sum << endl;
	return 0;
}
//输出：
//55

//函数签名
//void shrink_to_fit();
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque(10, 10);
	cout << "size of my_deque is " << my_deque.size() << endl;

	my_deque.resize(5);		//注：现在大小为5，但是并未释放内存
	cout << "size of my_deque is " << my_deque.size() << endl;
	my_deque.shrink_to_fit();		//现在释放内存了，此函数有点类似于vector的reserve()
	return 0;
}
//输出：
//size of my_deque is 10
//size of my_deque is 5

//函数签名
//reference operator[] (size_type n);
//const_reference operator[] (size_type n) const;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque(10);
	deque<int>::size_type sz = my_deque.size();
	for (unsigned i = 0; i != sz; i++)
		my_deque[i] = i;
	//使用[]逆置deque
	for (unsigned i = 0; i != sz / 2; i++)
	{
		int tmp = my_deque[i];
		my_deque[i] = my_deque[sz - i - 1];
		my_deque[sz - i - 1] = tmp;
	}

	for (auto i = 0; i != sz; i++)
		cout << my_deque[i] << " ";
	cout << endl;
	return 0;
}
//输出：
//9 8 7 6 5 4 3 2 1 0

//函数签名
//reference at(size_type n);
//const_reference at(size_type n) const;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque(10);
	for (unsigned i = 0; i != my_deque.size(); i++)
		my_deque[i] = i;

	for (auto i = 0; i != my_deque.size(); i++)
		cout << my_deque.at(i) << " ";
	cout << endl;
	return 0;
}
//输出：
//0 1 2 3 4 5 6 7 8 9

//函数签名
//reference front();
//const_reference front() const;
//reference back();
//const_reference back() const;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque;
	my_deque.push_front(11);
	my_deque.push_back(8);

	my_deque.front() -= my_deque.back();

	cout << my_deque.front() << endl;
	return 0;
}
//输出：
//3

//函数签名
//range(1)
//template <class InputIterator>
//void assign(InputIterator first, InputIterator last);
//fill(2)
//void assign(size_type n, const value_type& val);
//initializer list(3)
//void assign(initializer_list<value_type> il);
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> first_deque;
	deque<int> second_deque;
	deque<int> third_deque;

	first_deque.assign(7, 100);

	deque<int>::iterator it = first_deque.begin() + 1;

	second_deque.assign(it, first_deque.end());

	int my_ints[] = { 0, 8, 11 };
	third_deque.assign(my_ints, my_ints + 3);

	for (unsigned i = 0; i != first_deque.size(); i++)
		cout << first_deque[i] << " ";
	cout << endl;

	for (unsigned i = 0; i != second_deque.size(); i++)
		cout << second_deque[i] << " ";
	cout << endl;

	for (unsigned i = 0; i != third_deque.size(); i++)
		cout << third_deque[i] << " ";
	cout << endl;
	return 0;
}
//输出：
//100 100 100 100 100 100 100
//100 100 100 100 100 100 
//0 8 11

//函数签名
//void push_back(const value_type& val);
//void push_back(value_type&& val);
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque;
	my_deque.push_back(1);
	cout << my_deque.back() << endl;

	my_deque.push_front(2);
	cout << my_deque.front() << endl;

	my_deque.pop_back();
	cout << my_deque.front() << endl;

	my_deque.pop_front();
	cout << my_deque.size() << endl;
	return 0;
}
//输出：
//1
//2
//2
//0

//函数签名
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
#include<deque>
#include<vector>
using namespace std;
int main()
{
	deque<int> my_deque = { 1,2,3,4,5 };

	auto it = my_deque.begin() + 1;

	it = my_deque.insert(it, 10);	// 1 10 2 3 4 5 ,把返回的迭代器指回it,否则迭代器失效,现在it指向10

	my_deque.insert(it, 2, 5);	//1 5 5 10 2 3 4 5,注意现在it已经失效，不再指向任何值

	vector<int> vi(2, 3);
	it = my_deque.begin() + 2;
	my_deque.insert(it, vi.begin(), vi.end());	//1 5 3 3 5 10 2 3 4 5

	for (const auto& x : my_deque)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//1 5 3 3 5 10 2 3 4 5

//函数签名
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
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque = { 1,2,3,4,5 };

	my_deque.erase(my_deque.begin() + 3);		//擦除第4个

	my_deque.erase(my_deque.begin(), my_deque.begin() + 2);		//擦除第1，2个

	for each (auto var in my_deque)
	{
		cout << var << " ";
	}
	cout << endl;
	return 0;
}
//输出：
//3 5

//函数签名
//void swap(deque& x);
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> first_deque = { 1,2,3,4,5 };
	deque<int> second_deque = { 3,2,1 };

	first_deque.swap(second_deque);

	for each (auto var in first_deque)
	{
		cout << var << " ";
	}
	cout << endl;
	for each (auto var in second_deque)
	{
		cout << var << " ";
	}

	return 0;
}
//输出：
//3 2 1 
//1 2 3 4 5

//函数签名
//void clear() noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque = { 1,2,3,4,5 };

	my_deque.clear();
	cout << my_deque.size() << endl;

	my_deque.push_back(1);
	my_deque.push_back(3);
	for each (auto var in my_deque)
	{
		cout << var << " ";
	}

	return 0;
}
//输出：
//0 
//1 3 

//函数签名
//template <class... Args>
//iterator emplace(const_iterator position, Args&&... args);
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque = { 1,2,3 };

	auto it = my_deque.emplace(my_deque.begin() + 1, 10);
	my_deque.emplace(it, 20);
	my_deque.emplace(my_deque.end(), 30);
	for each (auto var in my_deque)
	{
		cout << var << " ";
	}

	return 0;
}
//输出：
//1 20 10 2 3 30

//函数签名
//template <class... Args>
//void emplace_front(Args&&... args);
//template <class... Args>
//void emplace_back(Args&&... args);
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque = { 1,2,3 };

	my_deque.emplace_front(8);
	my_deque.emplace_back(11);
	for each (auto var in my_deque)
	{
		cout << var << " ";
	}

	return 0;
}
//输出：
//8 1 2 3 11

//函数签名
//allocator_type get_allocator() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> my_deque;
	int *p;
	unsigned int i;

	p = my_deque.get_allocator().allocate(5);
	for (i = 0; i != 5; i++)
		my_deque.get_allocator().construct(&p[i], i);

	for (i = 0; i != 5; i++)
		cout << p[i] << " ";
	cout << endl;

	for (i = 0; i != 5; i++)
		my_deque.get_allocator().destroy(&p[i]);
	my_deque.get_allocator().deallocate(p, 5);

	return 0;
}
//输出：
//0 1 2 3 4

//函数签名
//(1)
//template <class T, class Alloc>
//bool operator== (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
//(2)
//template <class T, class Alloc>
//bool operator!= (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
//(3)
//template <class T, class Alloc>
//bool operator<  (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
//(4)
//template <class T, class Alloc>
//bool operator<= (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
//(5)
//template <class T, class Alloc>
//bool operator>  (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
//(6)
//template <class T, class Alloc>
//bool operator>= (const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> first_deque = { 1,2,3 };
	deque<int> second_deque = { 2,2,2 };
	if (first_deque == second_deque)
		cout << "first_deque and second_deque are equal" << endl;
	if (first_deque != second_deque)
		cout << "first_deque and second_deque are not equal" << endl;
	if (first_deque < second_deque)
		cout << "first_deque is less than second_deque" << endl;
	if (first_deque > second_deque)
		cout << "first_deque greater than second_deque" << endl;
	if (first_deque <= second_deque)
		cout << "first_deque is less than or equal to second_deque" << endl;
	if (first_deque >= second_deque)
		cout << "first_deque is greater than or equal to second_deque" << endl;
	return 0;
}
//输出：
//first_deque and second_deque are not equal
//first_deque is less than second_deque
//first_deque is less than or equal to second_deque

//函数签名
//allocator_type get_allocator() const noexcept;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> first_deque = { 1,2,3 };
	deque<int> second_deque = { 1,2,3,4,5 };

	//注：虽然非成员函数swap()也能交换两个队列，但是还是建议使用成员函数
	swap(first_deque, second_deque);
	for each (auto var in first_deque)
	{
		cout << var << " ";
	}
	cout << endl;
	for each (auto var in second_deque)
	{
		cout << var << " ";
	}
	return 0;
}
//输出：
//1 2 3 4 5
//1 2 3
