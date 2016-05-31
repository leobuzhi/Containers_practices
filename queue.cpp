//函数签名
//initialize(1)
//explicit queue(const container_type& ctnr);
//move - initialize(2)
//explicit queue(container_type&& ctnr = container_type());
//allocator(3)
//template <class Alloc> explicit queue(const Alloc& alloc);
//init + allocator(4)
//template <class Alloc> queue(const container_type& ctnr, const Alloc& alloc);
//move - init + allocator(5)
//template <class Alloc> queue(container_type&& ctnr, const Alloc& alloc);
//copy + allocator(6)
//template <class Alloc> queue(const queue& x, const Alloc& alloc);
//move + allocator(7)
//template <class Alloc> queue(queue&& x, const Alloc& alloc);
#include<iostream>
#include<deque>
#include<queue>
#include<list>
using namespace std;
int main()
{
	deque<int> my_deque(3, 100);
	deque<int> my_list(2, 100);

	queue<int> first_queue;
	queue<int> second_queue(my_deque);
	queue<int,deque<int>> third_queue;
	queue<int,deque<int>> fourth_queue(my_list);

	cout << "size of first_queue: " << first_queue.size() << endl;
	cout << "size of second_queue: " << second_queue.size() << endl;
	cout << "size of third_queue: " << third_queue.size() << endl;
	cout << "size of fourth_queue: " << fourth_queue.size() << endl;

	return 0;
}
//输出
//size of first_queue :0
//size of second_queue :3
//size of third_queue :0
//size of fourth_queue :2

//bool empty() const;
//size_type size() const;
//void push(const value_type& val);
//void push(value_type&& val);
//reference& front();
//const_reference& front() const;
//reference& back();
//const_reference& back() const;
//template <class... Args> void emplace(Args&&... args);
//void swap(queue& x) noexcept(/*see below*/);
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
	queue<int> first_queue;
	if (first_queue.empty())
		cout << "first_queue is empty" << endl;
	for (int i = 1; i <= 5; i++)
		first_queue.push(i);
	cout << "first_queue's front :" << first_queue.front() << endl;
	cout << "first_queue's back :" << first_queue.back()<< endl;
	cout << "first_queue's size :" << first_queue.size() << endl;

	queue<string> second_queue;
	//emplace与push不同之处在于前者是构造然后插入，后者是插入
	second_queue.emplace("first_string");
	second_queue.emplace("second_string");
	while (!second_queue.empty())
	{
		std::cout << second_queue.front() << endl;
		second_queue.pop();
	}
	queue<int> third_queue;
	first_queue.swap(third_queue);
	cout << "third_queue's size :" << third_queue.size() << endl;
	return 0;
}
//输出：
//first_queue is empty
//first_queue's front :1
//first_queue's back :5
//first_queue's size :5
//first_string
//second_string
//third_queue's size :5

//initialize(1)
//priority_queue(const Compare& comp, const Container& ctnr);
//range(2)
//template <class InputIterator>
//priority_queue(InputIterator first, InputIterator last,
//	const Compare& comp, const Container& ctnr);
//move - initialize(3)
//explicit priority_queue(const Compare& comp = Compare(),
//	Container&& ctnr = Container());
//move - range(4)
//template <class InputIterator>
//priority_queue(InputIterator first, InputIterator last,
//	const Compare& comp, Container&& ctnr = Container());
//allocator versions(5)
//template <class Alloc> explicit priority_queue(const Alloc& alloc);
//template <class Alloc> priority_queue(const Compare& comp, const Alloc& alloc);
//template <class Alloc> priority_queue(const Compare& comp, const Container& ctnr,
//	const Alloc& alloc);
//template <class Alloc> priority_queue(const Compare& comp, Container&& ctnr,
//	const Alloc& alloc);
//template <class Alloc> priority_queue(const priority_queue& x, const Alloc& alloc);
//template <class Alloc> priority_queue(priority_queue&& x, const Alloc& alloc);
//bool empty() const;
//size_type size() const;
//const_reference top() const;
//void push(const value_type& val);
//void push(value_type&& val);
//template <class... Args> void emplace(Args&&... args);
//void swap(priority_queue& x) noexcept (/*see below*/);
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<string>
using namespace std;
class comparsion {
private:	bool reverse;
public:
	comparsion(const bool& revparam=false)
	{
		reverse = revparam;
	}
	bool operator()(const int& lhs,const int& rhs)const
	{
		if (reverse)
			return lhs > rhs;
		return lhs < rhs;
	}
};
int main()
{
	int ints []= { 10,30,20,40 };
	priority_queue<int> first_pq;
	priority_queue<int> second_pq(ints,ints+4);
	priority_queue<int, vector<int>, greater<int>> third_pq(ints, ints + 4);
	priority_queue<int, vector<int>, comparsion> fourth_pq(ints, ints + 4);
	priority_queue<int, vector<int>, comparsion> fifth_pq(comparsion(true));
	priority_queue<string> string_pq;
	string_pq.push("b");
	string_pq.push("a");
	string_pq.push("c");
	cout << "first_pq's size is " << first_pq.size() << endl;
	cout << "second_pq's size is " << second_pq.size() << endl;
	for (int i = 0; i != 4; i++)
		fifth_pq.push(ints[i]);
	while (!second_pq.empty())
	{
		cout << second_pq.top()<<" ";
		second_pq.pop();
	}
	cout << endl;
	while (!third_pq.empty())
	{
		cout << third_pq.top() << " ";
		third_pq.pop();
	}
	cout << endl;
	while (!fourth_pq.empty())
	{
		cout << fourth_pq.top() << " ";
		fourth_pq.pop();
	}
	cout << endl;
	while (!fifth_pq.empty())
	{
		cout << fifth_pq.top() << " ";
		fifth_pq.pop();
	}
	cout << endl;
	while (!string_pq.empty())
	{
		cout << string_pq.top() << " ";
		string_pq.pop();
	}
	cout << endl;
	return 0;
}
//输出：
//first_pq's size is 0
//first_pq's size is 4
//40 30 20 10
//10 20 30 40
//40 30 20 10
//10 20 30 40
//c b a
