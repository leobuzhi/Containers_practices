Iterators

//函数签名：
// iterator begin() noexcept;
// iterator end() noexcept;
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 5> my_array = { 2,4,8,7,11 };
    for (auto it = my_array.begin(); it != my_array.end(); it++)
        cout << *it << " ";
    return 0;
}
//输出： 
//2 4 8 7 11 
//PS:如果array为空，begin()返回值与end()一样

//函数签名：
//reverse_iterator rbegin() noexcept;
//reverse_iterator rend() noexcept;
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 5> my_array = { 2,4,8,7,11 };
    for (auto it = my_array.rbegin(); it != my_array.rend(); it++)
        cout << *it << " ";
    return 0;
}
//输出： 
//11 7 8 4 2

//函数签名:
//const_iterator cbegin() const noexcept;
//const_iterator cend() const noexcpet;
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 5> my_array = { 2,4,8,7,11 };
    for (auto it = my_array.cbegin(); it != my_array.cend(); it++)
        cout << *it << " ";
    return 0;
}
//输出： 
//2 4 8 7 11

//函数签名:
//const_iterator crbegin() const noexcept;
//const_iterator crend() const noexcept;
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 5> my_array = { 2,4,8,7,11 };
    for (auto it = my_array.crbegin(); it != my_array.crend(); it++)
        cout << *it << " ";
    return 0;
}
//输出： 
//11 7 8 4 2

Capacity

//函数签名
//constexpr size_type size() noexcept;
#include<iostream>
#include<array>
using namespace std;
int main()
{
array<int, 5> my_ints;
array<char, 5> my_chars;
cout << my_ints.size() << endl;
cout << sizeof(my_ints) << endl;
cout << my_chars.size() << endl;
cout << sizeof(my_chars) << endl;
  return 0;
}
//输出： 
//5 
//20 5*4（int的字节大小） 
//5 
//5 5*1（char的字节大小） 
//PS:size() 总是等于第二个用来实例化模板的参数

//函数签名
//constexpr size_type max_size() noexcept;
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 5> my_ints;
    cout << my_ints.size() << endl;
    cout << my_ints.max_size() << endl;
  return 0;
}
//输出： 
//5 
//5

//函数签名
//constexpr bool empty() noexcept;
#include<iostream>
#include<array>
using namespace std;
int main()
{
array<int, 0> first_array;
array<int, 10> second_array;
cout << first_array.empty() << endl;
cout << second_array.empty() << endl;
return 0;
}
//输出： 
//1 
//0

Element access

//函数签名
//reference operator[] (size_type n);
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 10> my_array;
    for (unsigned int i = 0; i != 10; i++)
        my_array[i] = i;
    for (unsigned int i = 0; i != 10; i++)
        cout << my_array[i]<<" ";
    cout << endl;
    return 0;
}
//输出： 
//0 1 2 3 4 5 6 7 8 9

//函数签名
//reference at ( size_type n );
#include<iostream>
#include<array>
using namespace std;
int main()
{
array<int, 10> my_array;
for (unsigned int i = 0; i != 10; i++)
my_array[i] = i+1;
for (unsigned int i = 0; i != 10; i++)
cout << my_array.at(i) << " ";
cout << endl;
return 0;
}
//输出： 
//1 2 3 4 5 6 7 8 9 10

//函数签名
//reference front();
//reference back();
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 3> my_array = { 0,8,11 };
    cout << my_array.front() << endl;
    cout << my_array.back() << endl;
    return 0;
}
//输出： 
//0 
//11 
//PS：对空的array调用front()或者back()会造成未定义行为

//函数签名
// value_type* data() noexcept;
#include<cstring>
#include<iostream>
#include<array>
using namespace std;
int main()
{
    const char* str = "my string";
    // 注意这里是10 不是 9
    array<char, 10> char_array;
    memcpy(char_array.data(), str, 10);
    cout << char_array.data() << endl;
    return 0;
}
//输出： 
//my string

Modifiers

//函数签名
// void fill (const value_type& val);
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 8> my_array;
    my_array.fill(8);
    // 注意这里是10 不是 9
    for (int i = 0; i != my_array.size(); i++)
        cout << my_array[0] << " ";
    return 0;
}
//输出： 
//8 8 8 8 8 8 8 8

//函数签名
// void swap (array& x) noexcept(noexcept(swap(declval<value_type&>(),declval<value_type&>())));
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 3> my_array1 = { 1,2,3 };
    array<int, 3> my_array2 = { 3,2,1 };
    for (int i = 0; i != my_array1.size(); i++)
        cout << my_array1[i] << " ";
    cout << endl;
    for (int i = 0; i != my_array2.size(); i++)
        cout << my_array2[i] << " ";
    cout << endl;
    my_array1.swap(my_array2);
    for (int i = 0; i != my_array1.size(); i++)
        cout << my_array1[i] << " ";
    cout << endl;
    for (int i = 0; i != my_array2.size(); i++)
        cout << my_array2[i] << " ";
    cout << endl;
    return 0;
}
//输出： 
//1 2 3 
//3 2 1 
//3 2 1 
//1 2 3 
//PS：交换的两个array必须包含相同的类型和大小，与其他容器的swap()不同，array的swap()只需要线性时间

//函数签名
//template <size_t I, class T, size_t N> T& get(array<T, N>& arr) noexcept;
//template <size_t I, class T, size_t N> T&& get(array<T, N>&& arr) noexcept;
//template <size_t I, class T, size_t N> const T& get(const array<T, N>& arr) noexcept;
#include<iostream>
#include<array>
#include<tuple>
using namespace std;
int main()
{
    array<int, 3> my_array = { 1,2,3 };
    tuple<int, int, int> my_tuple(1, 2, 3);

    tuple_element<0, decltype(my_array)>::type my_element;

    my_element = get<2>(my_array);
    get<2>(my_array) = get<0>(my_array);
    get<0>(my_array) = my_element;

    cout << get<0>(my_array) << endl;
    cout << get<0>(my_tuple) << endl;

    return 0;
}
//输出： 
//3 
//1 
//PS：get()重载了tuple的同名函数

//函数签名
//(1)
//template <class T, size_T N>
//bool operator== (const array<T, N>& lhs, const array<T, N>& rhs);
//(2)
//template <class T, size_T N>
//bool operator!= (const array<T, N>& lhs, const array<T, N>& rhs);
//(3)
//template <class T, size_T N>
//bool operator<  (const array<T, N>& lhs, const array<T, N>& rhs);
//(4)
//template <class T, size_T N>
//bool operator<= (const array<T, N>& lhs, const array<T, N>& rhs);
//(5)
//template <class T, size_T N>
//bool operator>  (const array<T, N>& lhs, const array<T, N>& rhs);
//(6)
//template <class T, size_T N>
//bool operator>= (const array<T, N>& lhs, const array<T, N>& rhs);
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int, 3> a_array = { 1,2,3 };
    array<int, 3> b_array = { 1,2,3 };
    array<int, 3> c_array = { 3,2,1 };
    if (a_array == b_array)
        cout << "a_array and b_array are equal" << endl;
    if (b_array != c_array)
        cout << "a_array and b_array are not equal" << endl;
    if (b_array < c_array)
        cout << "b_array is less than c_array" << endl;
    if (c_array > b_array)
        cout << "c_array is greater than b_array" << endl;
    if (a_array <= b_array)
        cout << "a_array is less than or equal to b_array" << endl;
    if (a_array >= b_array)
        cout << "a_array is greater than or equal to b_array" << endl;
    return 0;
}
//输出： 
//a_array and b_array are equal 
//a_array and b_array are not equal 
//b_array is less than c_array 
//c_array is greater than b_array 
//a_array is less than or equal to b_array 
//a_array is greater than or equal to b_array 
//PS：array重载了关系操作运算符
