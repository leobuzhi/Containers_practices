//函数签名
//empty(1)
//set();
//explicit set(const key_compare& comp,
//	const allocator_type& alloc = allocator_type());
//explicit set(const allocator_type& alloc);
//range(2)
//template <class InputIterator>
//set(InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type& = allocator_type());
//template <class InputIterator>
//set(InputIterator first, InputIterator last,
//	const allocator_type& = allocator_type());
//copy(3)
//set(const set& x);
//set(const set& x, const allocator_type& alloc);
//move(4)
//set(set&& x);
//set(set&& x, const allocator_type& alloc);
//initializer list(5)
//set(initializer_list<value_type> il,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());
//set(initializer_list<value_type> il,
//	const allocator_type& alloc = allocator_type());
//copy(1)
//set& operator= (const set& x);
//move(2)
//set& operator= (set&& x);
//initializer list(3)
//set& operator= (initializer_list<value_type> il);
#include<iostream>
#include<set>
using namespace std;
bool funCmp(const int lhs, const int rhs)
{
	return lhs < rhs;
}
struct myCmp {
	bool operator()(const int lhs, const int rhs)const 
	{
		return lhs < rhs;
	}
};
int main()
{
	set<int> first_set;
	int ints[] = { 1,2,3,4,5 };

	set<int> second_set(ints, ints + 5);

	set<int> third_set(second_set);

	set<int> fourth_set(third_set.begin(), third_set.end());

	set<int,myCmp> fifth_set;

	bool(*ptr)(const int, const int);
	set<int, bool(*)(const int, const int)> six_set(ptr);

	first_set = second_set;
	second_set = set<int>();
	cout << "Size of first_set :" << first_set.size() << endl;
	cout << "Size of second_set :" << second_set.size() << endl;
	return 0;
}
//输出：
//Size of first_set :5
//Size of first_set :0

//函数签名
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//iterator end() noexcept;
//const_iterator end() const noexcept;
//reverse_iterator rbegin() noexcept;
//const_reverse_iterator rbegin() const noexcept;
//reverse_iterator rend() noexcept;
//const_reverse_iterator rend() const noexcept;
//const_iterator cbegin() const noexcept;
//const_iterator cend() const noexcept;
//const_reverse_iterator crbegin() const noexcept;
//const_reverse_iterator crend() const noexcept;
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> first_set = { 2,5,4,1,3 };
	for (auto it = first_set.begin(); it != first_set.end(); it++)
		cout << *it << " ";
	cout << endl;
	for (auto it = first_set.rbegin(); it != first_set.rend(); it++)
		cout << *it << " ";
	cout << endl;
	for (auto it = first_set.cbegin(); it != first_set.cend(); it++)
		cout << *it << " ";
	cout << endl;
	for (auto it = first_set.crbegin(); it != first_set.crend(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//1 2 3 4 5
//5 4 3 2 1
//1 2 3 4 5
//5 4 3 2 1

//函数签名
//bool empty() const noexcept;
//size_type size() const noexcept;
//size_type max_size() const noexcept;
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> first_set = { 3,2,4,1,5 };
	if (first_set.empty())
		cout << "first_set is empty." << endl;
	else 
		cout << "first_set is not empty." << endl;

	cout << "first_set's size : " << first_set.size() << endl;
	cout << "first_set's maxsize : " << first_set.max_size() << endl;
	return 0;
}
//输出：
//first_set is not empty.
//first_set's size : 5
//first_set's maxsize : 214748364

//函数签名
//single element(1)
//pair<iterator, bool> insert(const value_type& val);
//pair<iterator, bool> insert(value_type&& val);
//with hint(2)
//iterator insert(const_iterator position, const value_type& val);
//iterator insert(const_iterator position, value_type&& val);
//range(3)
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last);
//initializer list(4)
//void insert(initializer_list<value_type> il);
//(1)
//iterator  erase(const_iterator position);
//(2)
//size_type erase(const value_type& val);
//(3)
//iterator  erase(const_iterator first, const_iterator last);
//void swap(set& x);
//void clear() noexcept;
//template <class... Args>
//pair<iterator, bool> emplace(Args&&... args);
//template <class... Args>
//iterator emplace_hint(const_iterator position, Args&&... args);
#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	set<int> first_set = { 10,20,30,40,50 };
	pair<set<int>::iterator, bool> ret;
	set<int>::iterator it;
	ret = first_set.insert(20);
	if (ret.second == false)
		it = ret.first;		//"it" now points to element 20
	first_set.insert(23);
	first_set.insert(25);
	first_set.insert(22);
	int ints[] = { 5,10,20 };
	first_set.insert(ints, ints + 3);
	for (auto x : first_set)
		cout << x << " ";
	cout << endl;
	it = first_set.begin();
	advance(it, 3);
	first_set.erase(it);
	cout << first_set.erase(23) << endl;
	cout << first_set.erase(24) << endl;

	it = first_set.find(25);
	first_set.erase(it, first_set.end());
	for (auto x : first_set)
		cout << x << " ";
	cout << endl;

	set<int> second_set;
	first_set.swap(second_set);
	second_set.clear();

	set<string> third_set;
	third_set.emplace("abc");
	third_set.emplace("xyz");
	auto r = third_set.emplace("abc");
	if (!r.second)
		cout << "abc already exists in third_set." << endl;

	auto strIt = third_set.begin();
	strIt = third_set.emplace_hint(strIt, "ok");
	strIt = third_set.emplace_hint(strIt, "no");
	third_set.emplace_hint(third_set.end(), "zzz");
	for (auto x : third_set)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//5 10 20 22 23 25 30 40 50
//1
//0
//5 10 20
//abc already exists in third_set.
//abc no ok xyz zzz

//函数签名
//key_compare key_comp() const;
//value_compare value_comp() const;
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> first_set = { 1,2,3,4,5 };
	int highest;
	set<int>::key_compare key_cmp = first_set.key_comp();

	highest = *first_set.rbegin();
	auto it = first_set.begin();
	do {
		cout << *it << " ";
	} while (key_cmp(*(++it), highest));
	cout << endl;

	set<int>::value_compare value_cmp = first_set.value_comp();
	it = first_set.begin();
	do {
		cout << *it << " ";
	} while (value_cmp(*(++it), highest));
	cout << endl;
	return 0;
}
//输出：
//1 2 3 4
//1 2 3 4

//函数签名
//const_iterator find(const value_type& val) const;
//iterator       find(const value_type& val);
//size_type count(const value_type& val) const;
//iterator lower_bound(const value_type& val);
//const_iterator lower_bound(const value_type& val) const;
//iterator upper_bound(const value_type& val);
//const_iterator upper_bound(const value_type& val) const;
//pair<const_iterator, const_iterator> equal_range(const value_type& val) const;
//pair<iterator, iterator>             equal_range(const value_type& val);
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> first_set = { 1,2,3,4,5,6,7,8,9,10 };
	auto it = first_set.find(3);
	first_set.erase(it);
	cout << first_set.count(3) << endl;

	auto lowIt = first_set.lower_bound(4);
	auto upIt = first_set.lower_bound(8);
	first_set.erase(lowIt, upIt);
	for (auto x : first_set)
		cout << x << " ";
	cout << endl;

	pair<set<int>::iterator, set<int>::iterator> ps;
	ps = first_set.equal_range(2);
	cout << *ps.first << " " << *ps.second << endl;
	return 0;
}
//输出：
//0
//1 2 8 9 10
//2 8

//函数签名
//allocator_type get_allocator() const noexcept;
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> first_set;
	int *p;
	p = first_set.get_allocator().allocate(5);
	for (int i = 0; i != 5; i++)
		p[i] = i + 1;
	for (int i = 0; i != 5; i++)
		cout << p[i] << " ";
	cout << endl;
	first_set.get_allocator().deallocate(p, 5);
	return 0;
}
//输出：
//1 2 3 4 5

//函数签名
//empty(1)
//mutiset();
//explicit multiset(const key_compare& comp,
//	const allocator_type& alloc = allocator_type());
//explicit multiset(const allocator_type& alloc);
//range(2)
//template <class InputIterator>
//multiset(InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type& = allocator_type());
//template <class InputIterator>
//multiset(InputIterator first, InputIterator last,
//	const allocator_type& = allocator_type());
//copy(3)
//multiset(const multiset& x);
//multiset(const multiset& x, const allocator_type& alloc);
//move(4)
//multiset(multiset&& x);
//multiset(multiset&& x, const allocator_type& alloc);
//initializer list(5)
//multiset(initializer_list<value_type> il,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());
//multiset(initializer_list<value_type> il,
//	const allocator_type& alloc = allocator_type());
//copy(1)
//multiset& operator= (const multiset& x);
//move(2)
//multiset& operator= (multiset&& x);
//initializer list(3)
//multiset& operator= (initializer_list<value_type> il);
#include<iostream>
#include<set>
bool funCmp(const int lhs, const int rhs)
{
	return lhs < rhs;
}
struct myCmp {
	bool operator()(const int& lhs, const int& rhs)const 
	{
		return lhs < rhs;
	}
};
using namespace std;
int main()
{
	int ints[] = { 1,2,3,2,4,2 };
	multiset<int> first_multiset;
	multiset<int> second_multiset(ints, ints + 6);
	multiset<int> third_multiset(second_multiset);
	multiset<int> fourth_multiset(second_multiset.begin(),second_multiset.end());
	multiset<int, myCmp> fifth_multiset;
	bool(*ptr)(const int, const int);
	multiset<int, bool(*)(const int, const int)> sixth_multiset(ptr);

	first_multiset = second_multiset;
	for (auto x : first_multiset)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//1 2 2 2 3 4

//函数签名
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//iterator end() noexcept;
//const_iterator end() const noexcept;
//reverse_iterator rbegin() noexcept;
//const_reverse_iterator rbegin() const noexcept;
//const_iterator cbegin() const noexcept;
//const_iterator cend() const noexcept;
//const_reverse_iterator crbegin() const noexcept;
//const_reverse_iterator crend() const noexcept;
#include<iostream>
#include<set>
using namespace std;
int main()
{
	multiset<int> first_multiset = { 1,3,2,4,3 };
	for (auto it = first_multiset.begin(); it != first_multiset.end(); it++)
		cout << *it << " ";
	cout << endl;
	for (auto it = first_multiset.rbegin(); it != first_multiset.rend(); it++)
		cout << *it << " ";
	cout << endl;
	for (auto it = first_multiset.cbegin(); it != first_multiset.cend(); it++)
		cout << *it << " ";
	cout << endl;
	for (auto it = first_multiset.crbegin(); it != first_multiset.crend(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//1 2 3 3 4
//4 3 3 2 1
//1 2 3 3 4
//4 3 3 2 1

//函数签名
//bool empty() const noexcept;
//size_type size() const noexcept;
//size_type max_size() const noexcept;
#include<iostream>
#include<set>
using namespace std;
int main()
{
	multiset<int> first_multiset = { 1,3,2,4,3 };
	if (!first_multiset.empty())
		cout << "first_multiset is not empty." << endl;
	cout << "Size of first_set : " << first_multiset.size() << endl;
	cout << "Maxsize of first_set : " << first_multiset.max_size() << endl;
	return 0;
}
//输出：
//first_multiset is not empty.
//Size of first_set :5
//Maxsize of first_set :214748364

//函数签名
//single element(1)
//iterator insert(const value_type& val);
//iterator insert(value_type&& val);
//with hint(2)
//iterator insert(const_iterator position, const value_type& val);
//iterator insert(const_iterator position, value_type&& val);
//range(3)
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last);
//initializer list(4)
//void insert(initializer_list<value_type> il);
//(1)
//iterator  erase(const_iterator position);
//(2)
//size_type erase(const value_type& val);
//(3)
//iterator  erase(const_iterator first, const_iterator last);
//void swap(multiset& x);
//void clear() noexcept;
//template <class... Args>
//iterator emplace(Args&&... args);
//template <class... Args>
//iterator emplace_hint(const_iterator position, Args&&... args);
#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	multiset<int> first_multiset = { 10,30,50,10 };
	auto it = first_multiset.insert(20);

	it = first_multiset.insert(it, 25);
	int ints[] = { 10,15,25 };
	first_multiset.insert(ints, ints + 3);
	for (auto x : first_multiset)
		cout << x << " ";
	cout << endl;
	it = first_multiset.begin();
	advance(it, 5);
	it = first_multiset.erase(it);
	first_multiset.erase(it, first_multiset.end());
	first_multiset.erase(10);
	for (auto x : first_multiset)
		cout << x << " ";
	cout << endl;

	multiset<int> second_set;
	first_multiset.swap(second_set);
	second_set.clear();

	multiset<string> third_multiset;
	third_multiset.emplace("ab");
	third_multiset.emplace("bc");
	third_multiset.emplace("ab");
	for (auto x : third_multiset)
		cout << x << " ";
	cout << endl;

	auto strIt = third_multiset.find("bc");
	third_multiset.emplace_hint(strIt, "xy");
	for (auto x : third_multiset)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//10 10 10 15 20 25 25 30 50
//15 20
//ab ab bc
//ab ab bc xy

//函数签名
//key_compare key_comp() const;
//value_compare value_comp() const;
#include<iostream>
#include<set>
using namespace std;
int main()
{
	multiset<int> first_multiset = { 1,3,2,4,3 };
	multiset<int>::key_compare first_cmp = first_multiset.key_comp();
	int highest = *first_multiset.rbegin();
	auto it = first_multiset.begin();
	do {
		cout << *it << " ";
	} while (first_cmp(*it++, highest));
	cout << endl;

	multiset<int>::value_compare second_cmp = first_multiset.value_comp();
	it = first_multiset.begin();
	do {
		cout << *it << " ";
	} while (second_cmp(*it++, highest));
	cout << endl;
	return 0;
}
//输出：
//1 2 3 3 4
//1 2 3 3 4

//函数签名
//const_iterator find(const value_type& val) const;
//iterator       find(const value_type& val);
//size_type count(const value_type& val) const;
//const_iterator lower_bound(const value_type& val) const;
//iterator lower_bound(const value_type& val);
//const_iterator upper_bound(const value_type& val) const;
//iterator upper_bound(const value_type& val);
//pair<const_iterator, const_iterator> equal_range(const value_type& val) const;
//pair<iterator, iterator>             equal_range(const value_type& val);
#include<iostream>
#include<set>
using namespace std;
int main()
{
	multiset<int> first_multiset = { 1,3,2,4,3,3 };
	auto it = first_multiset.find(3);
	first_multiset.erase(it);
	cout << "3 appear " << first_multiset.count(3) << " times." << endl;
	auto lowIt = first_multiset.lower_bound(3);
	auto upIt = first_multiset.upper_bound(4);
	first_multiset.erase(lowIt, upIt);
	for (auto x : first_multiset)
		cout << x << " ";
	cout << endl;
	first_multiset = { 1,2,3,4,5 };
	pair<multiset<int>::iterator, multiset<int>::iterator> pm;
	pm = first_multiset.equal_range(3);
	cout << *pm.first << " " << *pm.second << endl;
	return 0;
}
//输出：
//3 appear 2 times.
//1 2
//3 4

//函数签名
//allocator_type get_allocator() const noexcept;
#include<iostream>
#include<set>
using namespace std;
int main()
{
	multiset<int> first_multiset = { 1,3,2,4,3 };
	int *p = first_multiset.get_allocator().allocate(5);
	for (int i = 0; i != 5; i++)
		p[i] = i + 1;
	for (int i = 0; i != 5; i++)
		cout << p[i] << " ";
	cout << endl;
	first_multiset.get_allocator().deallocate(p, 5);
	return 0;
}
//输出：
//1 2 3 4 5
