//函数签名
//empty (1)	
//map();
//explicit map (const key_compare& comp,
//              const allocator_type& alloc = allocator_type());
//explicit map (const allocator_type& alloc);
//range (2)	
//template <class InputIterator>
//  map (InputIterator first, InputIterator last,
//       const key_compare& comp = key_compare(),
//       const allocator_type& = allocator_type());
//template <class InputIterator>
//  map (InputIterator first, InputIterator last,
//       const allocator_type& = allocator_type());
//copy (3)	
//map (const map& x);
//map (const map& x, const allocator_type& alloc);
//move (4)	
//map (map&& x);
//map (map&& x, const allocator_type& alloc);
//initializer list (5)	
//map (initializer_list<value_type> il,
//     const key_compare& comp = key_compare(),
//     const allocator_type& alloc = allocator_type());
//map (initializer_list<value_type> il,
//     const allocator_type& alloc = allocator_type());
#include<iostream>
#include<map>
using namespace std;
bool funCmp(char lhs, char rhs)
{
	return lhs < rhs;
}
struct classCmp{
	bool operator ()(const char& lhs, const char &rhs)const
	{
		return lhs < rhs;
	}
};
int main()
{
	map<char, int> first_map;
	first_map['a'] = 1;
	first_map['b'] = 3;
	first_map['c'] = 5;
	first_map['d'] = 7;

	map<char, int> second_map(first_map.begin(), first_map.end());
	map<char, int> third_map(second_map);
	map<char, int,classCmp> fourth_map;
	bool(*funP)(char, char) = funCmp;
	map<char, int, bool(*)(char, char)> fifth_map(funP);

	return 0;
}

//函数签名
//copy(1)
//map& operator= (const map& x);
//move(2)
//map& operator= (map&& x);
//initializer list(3)
//map& operator= (initializer_list<value_type> il);
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<char, int> first_map;
	first_map['a'] = 1;
	first_map['b'] = 2;
	first_map['c'] = 3;
	map<char, int> second_map;
	second_map = first_map;
	first_map = map<char, int>();
	cout << "Size of first_map:" << first_map.size() << endl;
	cout << "Size of second_map:" << second_map.size() << endl;
	return 0;
}
//输出：
//Size of first_map :0
//Size of first_map :3

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
#include<map>
using namespace std;
int main()
{
	map<char, int> first_map;
	first_map['b'] = 1;
	first_map['a'] = 2;
	first_map['c'] = 3;
	for (auto it = first_map.begin(); it != first_map.end(); it++)
		cout << it->first << "," << it->second << " ";
	cout << endl;
	for (auto it = first_map.cbegin(); it != first_map.cend(); it++)
		cout << it->first << "," << it->second << " ";
	cout << endl;
	for (auto it = first_map.rbegin(); it != first_map.rend(); it++)
		cout << it->first << "," << it->second << " ";
	cout << endl;
	for (auto it = first_map.crbegin(); it != first_map.crend(); it++)
		cout << it->first << "," << it->second << " ";
	cout << endl;
	return 0;
}
//输出：
//a,2 b,1 c,3
//a,2 b,1 c,3
//c,3 b,1 a,2
//c,3 b,1 a,2

//函数签名
//bool empty() const noexcept;
//size_type size() const noexcept;
//size_type max_size() const noexcept;
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<char, int> first_map;
	first_map['a'] = 1;
	first_map['b'] = 2;
	first_map['c'] = 3;
	if (first_map.empty())
		cout << "first_map is empty " << endl;
	else 
		cout << "first_map is not empty " << endl;
	cout << first_map.size() << endl;
	cout << first_map.max_size() << endl;		//取决于机器
	return 0;
}
//输出：
//first_map is not empty
//3
//178956970

//函数签名
//mapped_type& operator[] (const key_type& k);
//mapped_type& operator[] (key_type&& k);
//mapped_type& at (const key_type& k);
//const mapped_type& at (const key_type& k) const;
#include<iostream>
#include<string>
#include<map>
#include<assert.h>
using namespace std;
int main()
{
	map<char, int> first_map;
	first_map['a'] = 1;
	first_map['b'] = 2;
	first_map['c'] = 3;
	cout << "Size of first_map:" << first_map.size() << endl;
	cout << first_map['a'] << endl;
	cout << first_map['b'] << endl;
	cout << first_map['c'] << endl;
	cout << first_map['d'] << endl;		//注意这里对map加了一项，详见Effective STL
	cout << "Size of first_map:" << first_map.size() << endl;

	map<string, int> second_map = {
		{"a",0},{"b",0},{"c",0} };
	second_map.at("a") = 1;		//at和[]不同之处在于如果访问一个不存在的键，不会生成一个项，而是抛出一个out_of_range 异常
	second_map.at("b") = 2;
	second_map.at("c") = 3;
	for (auto it = second_map.begin(); it != second_map.end(); it++)
		cout << it->first << "," << it->second<<" ";
	cout << endl;
	
	return 0;
}
//输出：
//Size of first_map :0
//1
//2
//3
//0
//Size of first_map :3
//a,1 b,2 c,3

//函数签名
//single element(1)
//pair<iterator, bool> insert(const value_type& val);
//template <class P> pair<iterator, bool> insert(P&& val);
//with hint(2)
//iterator insert(const_iterator position, const value_type& val);
//template <class P> iterator insert(const_iterator position, P&& val);
//range(3)
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last);
//initializer list(4)
//void insert(initializer_list<value_type> il);
//(1)
//iterator  erase(const_iterator position);
//(2)
//size_type erase(const key_type& k);
//(3)
//iterator  erase(const_iterator first, const_iterator last);
//void swap(map& x);
//void clear() noexcept;
//template <class... Args>
//pair<iterator, bool> emplace(Args&&... args);
//template <class... Args>
//iterator emplace_hint(const_iterator position, Args&&... args);
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<char, int> first_map;
	//single parameter
	first_map.insert(pair<char, int>('a', 100));
	first_map.insert(pair<char, int>('e', 200));

	pair<map<char, int>::iterator, bool> ret;
	ret = first_map.insert(pair<char, int>('e', 300));
	if (ret.second == false)
	{
		cout << "Element b alreadly existed" << endl;
		cout << "With a value of " << ret.first->second << endl;
	}

	//hint position
	map<char, int>::iterator it = first_map.begin();
	first_map.insert(it, pair<char, int>('b', 300));
	first_map.insert(it, pair<char, int>('c', 400));

	//range insertion
	map<char, int> second_map;
	second_map.insert(first_map.begin(), first_map.find('c'));

	cout << "first_map:" << endl;
	for (it = first_map.begin(); it != first_map.end(); it++)
	{
		cout << "first:" << it->first << " second:" << it->second << endl;
	}
	cout << "second_map:" << endl;
	for (it = second_map.begin(); it != second_map.end(); it++)
	{
		cout << "first:" << it->first << " second:" << it->second << endl;
	}

	//erasing by iterator
	it = first_map.find('b');
	first_map.erase(it);

	//erasing by key
	first_map.erase('c');

	//erasing by range

	first_map.erase(first_map.begin(), first_map.end());
	cout << "Size of first_map :" << first_map.size() << endl;

	first_map.swap(second_map);
	cout << "Size of first_map :" << first_map.size() << endl;
	cout << "Size of second_map :" << second_map.size() << endl;

	first_map.clear();
	cout << "Size of first_map :" << first_map.size() << endl;

	first_map.emplace('a', 100);
	first_map.emplace('b', 100);
	it = first_map.end();
	it = first_map.emplace_hint(it, 'c', 10);
	first_map.emplace_hint(it, 'e', 20);
	first_map.emplace_hint(first_map.end(), 'd', 14);

	for (auto x : first_map)
		cout << x.first << ":" << x.second << endl;
	cout << endl;
	return 0;
}
//输出：
//Element b alreadly existed
//With a value of 200
//first_map:
//first:a second:100
//first:b second:300
//first:c second:400
//first:e second:200
//second_map
//first:a second:100
//first:b second:300
//Size of first_map :0
//Size of first_map :2
//Size of second_map :0
//Size of first_map :0
//a:100
//b:100
//c:10
//d:14
//e:20

//函数签名
//key_compare key_comp() const;
//value_compare value_comp() const;
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<char, int> first_map;
	map<char, int>::key_compare first_comp = first_map.key_comp();

	first_map['a'] = 100;
	first_map['b'] = 200;
	first_map['c'] = 300;

	cout << "first_map contain:" << endl;

	char highest = first_map.rbegin()->first;

	map<char, int>::iterator it1 = first_map.begin();
	do {
		cout << it1->first << "->" << it1->second << endl;
	} while (first_comp((*it1++).first, highest));

	map<char, int> second_map;
	second_map['a'] = 101;
	second_map['b'] = 102;
	second_map['c'] = 103;
	cout << "second_map contain:" << endl;
	pair<char, int> high = *second_map.rbegin();
	map<char, int>::iterator it2 = second_map.begin();
	do {
		cout << it2->first << "->" << it2->second << endl;
	} while (second_map.value_comp()(*it2++, high));
	return 0;
}
//输出：
//first_map contain:
//a->100
//b->200
//c->300
//second_map contain:
//a->101
//b->102
//c->103

//函数签名
//iterator find(const key_type& k);
//const_iterator find(const key_type& k) const;
//size_type count (const key_type& k) const;
//iterator lower_bound (const key_type& k);
//const_iterator lower_bound (const key_type& k) const;
//iterator upper_bound (const key_type& k);
//const_iterator upper_bound (const key_type& k) const;
//pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
//pair<iterator,iterator>             equal_range (const key_type& k);
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<char, int> first_map;
	first_map['a'] = 1;
	first_map['b'] = 2;
	first_map['c'] = 3;
	first_map['d'] = 4;
	auto it = first_map.find('b');
	if (it != first_map.end())
		first_map.erase(it);
	for (auto c = 'a'; c <= 'e'; c++)
		if (first_map.count(c))
			cout << c << " is an element of first_map." << endl;

	map<char, int> second_map;
	second_map['a'] = 1;
	second_map['b'] = 2;
	second_map['c'] = 3;
	second_map['d'] = 4;
	second_map['e'] = 5;
	auto itLow = second_map.lower_bound('b');		//指向b
	auto itUp = second_map.upper_bound('d');		//指向e

	second_map.erase(itLow, itUp);					//删除 [itLow,itUp)
	for (auto x : second_map)
		cout << x.first << "->" << x.second << endl;

	map<char, int>	third_map;
	third_map['a'] = 1;
	third_map['b'] = 2;
	third_map['c'] = 3;

	pair<map<char, int>::iterator, map<char, int>::iterator> ret;
	ret = third_map.equal_range('b');
	cout << "lower bound points to:" << endl;
	cout << ret.first->first << "->" << ret.first->second << endl;
	cout << "uper bound points to:" << endl;
	cout << ret.second->first << "->" << ret.second->second << endl;
	return 0;
}
//输出：
//a is an element of first_map.
//c is an element of first_map.
//d is an element of first_map.
//a->1
//e->5
//lower bound points to:
//b->2
//uper bound points to :
//c->3

//函数签名
//allocator_type get_allocator() const noexcept;
#include<map>
#include<iostream>
using namespace std;
int main()
{
	map<char, int> first_map;
	pair<const char, int> *p;

	p = first_map.get_allocator().allocate(5);

	int psize = sizeof(map<char, int>::value_type) * 5;

	cout << "The allocated array has a size of " << psize << " bytes" << endl;

	first_map.get_allocator().deallocate(p, 5);
	return 0;
}
//输出：
//The allocated array has a size of 40 bytes

//函数签名
//empty(1)
//multimap();
//explicit multimap(const key_compare& comp,
//	const allocator_type& alloc = allocator_type());
//explicit multimap(const allocator_type& alloc);
//range(2)
//template <class InputIterator>
//multimap(InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type& = allocator_type());
//template <class InputIterator>
//multimap(InputIterator first, InputIterator last,
//	const allocator_type& = allocator_type());
//copy(3)
//multimap(const multimap& x);
//multimap(const multimap& x, const allocator_type& alloc);
//move(4)
//multimap(multimap&& x);
//multimap(multimap&& x, const allocator_type& alloc);
//initializer list(5)
//multimap(initializer_list<value_type> il,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());
//multimap(initializer_list<value_type> il,
//	const allocator_type& alloc = allocator_type());
//copy (1)	
//multimap& operator= (const multimap& x);
//move (2)	
//multimap& operator= (multimap&& x);
//initializer list (3)	
//multimap& operator= (initializer_list<value_type> il);
#include<iostream>
#include<map>
bool funcmp(char &lhs, char &rhs) 
{
	return lhs < rhs;
}
struct classCmp {
	bool operator()(const char& lhs, const char& rhs)const
	{
		return lhs < rhs;
	}
};
using namespace std;
int main()
{
	multimap<char, int> first_mm;
	first_mm.insert(pair<char, int>('a', 1));
	first_mm.insert(pair<char, int>('b', 2));
	first_mm.insert(pair<char, int>('b', 3));
	first_mm.insert(pair<char, int>('c', 4));

	multimap<char, int> second_mm(first_mm.begin(),first_mm.end());
	multimap<char, int> third_mm(second_mm);
	multimap<char, int, classCmp> fourth_mm;
	bool(*fptr)(char, int);
	multimap<char, int, bool(*)(char, int)> fifth_mm(fptr);

	second_mm.clear();
	second_mm = first_mm;
	cout << "Size of second_mm:" << second_mm.size() << endl;

	return 0;
}
//输出：
//Size of second_mm :4

//函数签名
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//iterator end() noexcept;
//const_iterator end() const noexcept;
//reverse_iterator rbegin() nothrow;
//const_reverse_iterator rbegin() const nothrow;
//reverse_iterator rend() nothrow;
//const_reverse_iterator rend() const nothrow;
//const_iterator cbegin() const noexcept;
//const_iterator cend() const noexcept;
//const_reverse_iterator crbegin() const noexcept;
//const_reverse_iterator crend() const noexcept;
#include<iostream>
#include<map>
using namespace std;
int main()
{
	multimap<char, int> first_map;
	first_map.insert(pair<char, int>('a', 1));
	first_map.insert(pair<char, int>('b', 2));
	first_map.insert(pair<char, int>('b', 3));
	for (multimap<char, int>::iterator it = first_map.begin(); it != first_map.end(); it++)
		cout << it->first << "->" << it->second << endl;
	for (auto it = first_map.rbegin(); it != first_map.rend();it++)
		cout << it->first << "->" << it->second << endl;
	for (auto it = first_map.cbegin(); it != first_map.cend();it++)
		cout << it->first << "->" << it->second << endl;
	for (auto it = first_map.crbegin(); it != first_map.crend(); it++)
		cout << it->first << "->" << it->second << endl;
	return 0;
}
//输出：
//a->1
//b->2
//b->3
//b->3
//b->2
//a->1
//a->1
//b->2
//b->3
//b->3
//b->2
//a->1

//函数签名
//bool empty() const noexcept;
//size_type size() const noexcept;
//size_type max_size() const noexcept;
#include<iostream>
#include<map>
using namespace std;
int main()
{
	multimap<char, int> first_map;
	first_map.insert(make_pair('a', 1));
	first_map.insert(make_pair('b', 2));
	first_map.insert(make_pair('b', 3));
	if (first_map.empty())
		cout << "first_map is empty ." << endl;
	else 
		cout << "first_map is not empty ." << endl;
	cout << "Size of first_map : " << first_map.size() << endl;
	cout << "Maxsize of first_map: " << first_map.max_size() << endl;
	return 0;
}
//输出：
//first_map is not empty .
//Size of first_map :3
//Maxsize of first_map :178956970

//函数签名
//single element(1)
//iterator insert(const value_type& val);
//template <class P> iterator insert(P&& val);
//with hint(2)
//iterator insert(const_iterator position, const value_type& val);
//template <class P> iterator insert(const_iterator position, P&& val);
//range(3)
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last);
//initializer list(4)
//void insert(initializer_list<value_type> il);
//(1)
//iterator  erase(const_iterator position);
//(2)
//size_type erase(const key_type& k);
//(3)
//iterator  erase(const_iterator first, const_iterator last);
//void swap(multimap& x);
//void clear() noexcept;
//template <class... Args>
//iterator emplace(Args&&... args);
//template <class... Args>
//iterator emplace_hint(const_iterator position, Args&&... args);
#include<iostream>
#include<map>
using namespace std;
int main()
{
	multimap<char, int> first_map;
	//single parameter
	first_map.insert(pair<char, int>('a', 1));
	first_map.insert(pair<char, int>('b', 2));
	auto it = first_map.insert(pair<char, int>('c', 3));
	//with hint position
	first_map.insert(it, pair<char, int>('d', 4));
	first_map.insert(it, pair<char, int>('g', 5));

	multimap<char, int> second_map;
	second_map.insert(first_map.begin(), first_map.find('d'));
	for (auto x : second_map)
		cout << x.first << "->" << x.second << endl;

	it = first_map.find('b');
	first_map.insert(make_pair('c', 4));
	first_map.erase(it);
	first_map.erase('c');		//删除2个元素
	it = first_map.find('d');
	first_map.erase(it, first_map.end());
	for (auto x : first_map)
		cout << x.first << "->" << x.second << endl;

	first_map.swap(second_map);
	first_map.clear();

	first_map.emplace('a', 1);
	first_map.emplace('b', 2);
	it = first_map.end();
	it = first_map.emplace_hint(it, 'a', 3);
	first_map.emplace_hint(it, 'b', 4);
	first_map.emplace_hint(first_map.end(), 'c', 1);
	for (auto x : first_map)
		cout << x.first << "->" << x.second << endl;
	return 0;
}
//输出：
//a->1
//b->2
//c->3
//a->1
//a->1
//a->3
//b->4
//b->2
//c->1

//函数签名
//key_compare key_comp() const;
//value_compare value_comp() const;
#include<iostream>
#include<map>
using namespace std;
int main()
{
	multimap<char, int> first_map;
	first_map.insert(make_pair('a', 1));
	first_map.insert(make_pair('b', 2));
	first_map.insert(make_pair('c', 3));

	multimap<char, int>::key_compare mycmp = first_map.key_comp();
	char highest = first_map.rbegin()->first;
	auto it = first_map.begin();
	do {
		cout << it->first << "->" << it->second << endl;
	} while (mycmp((*it++).first, highest));

	multimap<char, int> second_map;
	second_map.insert(make_pair('a', 1));
	second_map.insert(make_pair('b', 2));
	second_map.insert(make_pair('c', 3));
	pair<char, int> highPair = *second_map.rbegin();
	it = second_map.begin();
	do {
		cout << it->first << "->" << it->second << endl;
	} while (second_map.value_comp()(*it++, highPair));

	return 0;
}
//输出：
//a->1
//b->2
//c->3
//a->1
//b->2
//c->3

//函数签名
//iterator find(const key_type& k);
//const_iterator find(const key_type& k) const;
//size_type count(const key_type& k) const;
//iterator lower_bound(const key_type& k);
//const_iterator lower_bound(const key_type& k) const;
//iterator upper_bound(const key_type& k);
//const_iterator upper_bound(const key_type& k) const;
//pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
//pair<iterator, iterator>             equal_range(const key_type& k);
#include<iostream>
#include<map>
using namespace std;
int main()
{
	multimap<char, int> first_map;
	first_map.insert(make_pair('a', 1));
	first_map.insert(make_pair('a', 2));
	first_map.insert(make_pair('b', 2));
	first_map.insert(make_pair('b', 4));
	first_map.insert(make_pair('c', 3));
	first_map.insert(make_pair('c', 3));
	first_map.insert(make_pair('d', 3));
	auto it = first_map.find('b');
	cout << it->second << endl;
	cout << first_map.count('c') << endl;

	auto itLow = first_map.lower_bound('b');
	auto itUp = first_map.upper_bound('d');
	for (it = itLow; it != itUp; it++)
		cout << it->first << "->" << it->second << endl;

	for (char ch = 'a'; ch <= 'd'; ch++)
	{
		pair<multimap<char,int>::iterator,multimap<char,int>::iterator> ret = first_map.equal_range(ch);
		cout << ch << "->";
		for (multimap<char, int>::iterator it = ret.first; it != ret.second; it++)
			cout << it->second <<" ";
		cout << endl;
	}
	return 0;
}
//输出：
//2
//2
//b->2
//b->4
//c->3
//c->3
//d->3
//a->1 2
//b->2 4
//c->3 3
//d->3

//函数签名
//allocator_type get_allocator() const noexcept;
#include<iostream>
#include<map>
using namespace std;
int main()
{
	multimap<char, int> first_map;
	pair<const char, int>* p;

	p = first_map.get_allocator().allocate(5);
	int psize = sizeof(multimap<char, int>::value_type) * 5;

	cout << "The allocated array has a size of " << psize << " bytes." << endl;
	return 0;
}
//输出：
//The allocated array has a size of 40 bytes.
