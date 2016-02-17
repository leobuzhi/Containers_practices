//函数签名
//initialize(1)
//explicit stack(const container_type& ctnr);
//move - initialize(2)
//explicit stack(container_type&& ctnr = container_type());
//allocator(3)
//template <class Alloc> explicit stack(const Alloc& alloc);
//init + allocator(4)
//template <class Alloc> stack(const container_type& ctnr, const Alloc& alloc);
//move - init + allocator(5)
//template <class Alloc> stack(container_type&& ctnr, const Alloc& alloc);
//copy + allocator(6)
//template <class Alloc> stack(const stack& x, const Alloc& alloc);
//move + allocator(7)
//template <class Alloc> stack(stack&& x, const Alloc& alloc);
//bool empty() const;
//size_type size() const;
//reference& top();
//const_reference& top() const;
//void push(const value_type& val);
//void push(value_type&& val);
//template <class... Args> void emplace(Args&&... args);
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int main()
{
	deque<int> my_deque(3, 100);
	vector<int> my_vector(2, 200);

	stack<int> first_stack;
	stack<int> second_stack(my_deque);
	stack<int, vector<int>> third_stack;
	stack<int,vector<int>> fourth_stack(my_vector);
	stack<string> fifth_stack;
	stack<string> six_stack;

	if (fourth_stack.empty())
		cout << "fourth_stack is empty ." << endl;
	else
		cout << "fourth_stack is not empty ." << endl;

	cout << "fourth_stack's size is " << fourth_stack.size() << endl;
	cout << "fourth_stack's top is " << fourth_stack.top() << endl;
	fourth_stack.push(50);
	fourth_stack.push(10);
	cout << "fourth_stack's top is " << fourth_stack.top() << endl;
	fifth_stack.push("abc");
	fifth_stack.swap(six_stack);
	cout << "six_stack's top is " << six_stack.top() << endl;
	return 0;
}
//输出：
//fourth_stack is not empty .
//fourth_stack's size is 2
//fourth_stack's top is 200
//fourth_stack's top is 10
//six_stack's top is abc
