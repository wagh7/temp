Casting

Storage modifiers
constant
mutable
volatile

mutable

class A
{
	public:
		mutable int a;
		void fun() const
		{
			a = 12;
		}
};
//case 1 - const member function
A obj;
obj.fun();

//case 2 - const object
const A obj;
obj.a=15; 

 
// Volatile
volatile int flag = true;

// constant

data members/member functions/objects can be const



class myClass
{
	int a;
	public:
		void read() const
		{}
		void write()
		{}
};
//
myClass obj;
const myclass objConst;
obj.read();  // Allowed, non-const object can call const/non-const member functions
obj.write(); // Allowed, non-const object can call const/non-const member functions
objConst.write();  // Not Allowed::data should not change of const object, and non-const member function may have some code which change object value.
objConst.read();  // Allowed::const object can only call const member functions.

Inspector - getter - const
Mutators - setter - Non-const

static data member can be constant?
	Yes, static data member can be const.

static function can be constant?
	No, fun makes const to not allowed to change the state of object.
	But, Static functions are not object specific.
	
object data members not allowed to use in static function.

Object can call static methods.

###########
Virtual
###########
virtual Inheritance
	Diamond problem

class Top
{
	int a;
};
class Left:virtual public Top
{
	int b;
};
class Right:virtual public Top
{
	int c;
};
class Bottom:public Left, public Right
{
	int d;
};


Virtual Method
==============
Dynamic Polymorphism
	Calling override function depends on type of object and not pointer. and resolved at run time.
Method overriding
	Base class and derrived class have function with same prototype.

Base class function need to declare as virtual.

If class have virtual function, At compile time virtual table has created for that class.
One virtual table for each class(having virtual function)
When constructor call then pointer to virtual table assign to the object.

e.g.
class A
{
	private:
		int a;
	public:
		virtual void print()
		{}
		virtual void fun1()
		{}
}; 
class B:public A
{
	private:
		int b;
	public:
		void  print()      
		{}
		virtual void fun2()
		{}
};

//virtual table A
	print
	fun1
//virtual table B
	print
	fun1::A
	fun2

####################
Smart Pointer
####################

Auto_ptr : depricated/removed
unique_ptr
	unique_ptr<int> uptr1 = new int(10);
	unique_ptr<int> uptr2 = uptr1;  // Not allowed
	unique_ptr<int> uptr2 = std::move(uptr1);
shared_ptr
	shared_ptr<int> sptr1 = new int(10);
	shared_ptr<int> sptr2 = make_shared<int>(10);
	shared_ptr<int> sptr3 = make_shared<Base>("name", 30);
weak_ptr
	shared_ptr<int> sptr1(new int(10));
	weak_ptr<int> wptr1 = sptr1;
	sptr1 = qptr1.lock();

template<typename T>
class MyUniquePtr
{
	private:
		T* ptr;
		MyUniquePtr(const MyUniquePtr& obj)=delete;
		MyUniquePtr& operator=(const MyUniquePtr& obj)=delete;
	public:
		MyUniquePtr(T* _ptr)
		{
			ptr = _ptr;
		}
		T* operator->()
		{
			return ptr;
		}
		T& operator*()
		{
			return *ptr;
		}
		~MyUniquePtr()
		{
			if(ptr != NULL)
				delete ptr;
			ptr = NULL;
		}
}

		
	
// Own Shared_ptr
####################

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>
using namespace std;


class Driver
{
public:
	string name;

public:
	Driver(string _name)
	{
		cout<<_name<<": Constructor"<<endl;	
		name = _name;
	}
	Driver()
	{
		cout<<"Constructor"<<endl;	
	}
	void print()
	{
		cout<<"Print fun called"<<endl;
	}
	~Driver()
	{
		cout<<this->name<<": Destructor"<<endl;
	}
};


template<typename T>
class MyUniquePtr
{
	private:
		T* ptr;
		
		
	public:
	    static int count;
		MyUniquePtr(const MyUniquePtr& obj)
		{
		    *this = obj;
		    count++;
		}
		MyUniquePtr& operator=(const MyUniquePtr& obj)
		{
		    *this = obj;
		    count++;
		}
		MyUniquePtr()
		{
		    ptr = NULL;
		}
		MyUniquePtr(T* _ptr)
		{
			ptr = _ptr;
			count++;
		}
		T* operator->()
		{
			return ptr;
		}
		T& operator*()
		{
			return *ptr;
		}
		~MyUniquePtr()
		{
			if(ptr != NULL && count==0)
			{
				delete ptr;
			    ptr = NULL;
			}
			else if(ptr != NULL && count!=0)
			{
			    count--;
			}
			
		}
};
template<typename T>
int MyUniquePtr<T>::count = 0;
int main()
{
	{
		MyUniquePtr<Driver> ptr1(new Driver("A"));
		ptr1->print();
		MyUniquePtr<Driver> ptr2;
		cout<<MyUniquePtr<Driver>::count<<endl;
		//ptr2 = ptr1;
	}

    
    
	//_getch();
	return 1; 
}

	
Others
######
		
Constructor and Destructor calling sequence

Base::Constructor
Der::Constructor
Der::Destructor
Base::Destructor

When new fails
Exception:bad_alloc

Anagram below string or not?
First String: “abcd”
Second String: “dabc”

//  
//
// map<char, int>

//set<char> s(str, str+len); 
// In loop check for the char from second string is available in to the set
auto it = s.find(str2[i]);




bool isAnagram(string str1, string str2)
{
	if(str1.length() != str2.length())
		return flase;
		
	int arr[256] = {0};
	int len = str1.length();
	
	for(int i=0; i<len ; i++)
	{
		arr[str1[i]] += 1; 
	}
	
	i=0;
	
	return
}

#######################################3
STL
#####
//vector
Insertion: O(n)
Deletion:  O(n)
Access:	   O(1)

vector<int> v1;
vector<int> v(v1);
vector<int> v(5);  // 5 elements with value zero
vector<int> v(5,1); // 5 elements with value 1
vector<int> v(Arr, Arr+5); // Initialise with Arra elements
v.reserved(10);
v.capacity();  // 10
v.srink_to_fit();
v.size(); // 0
v.push_back(10);
v.pop_back();
v.inser(v.begin(), 10);
v.erase(v.begin());

//list : O(n)
list<int> l;
list<int> l(v.begin(), v.begin()+5);

l.push_back(10);
l.push_front(10);
it = l.insert(l.begin(), 10);
it = l.erase(l.begin());
it = std::find(l.begin, l.end(), 10);


//set : O(log n)
//Implemented by balance binary search tree
//Duplicate not allowed
//In Ordered
//Not able to edit element value
set<int, std::greater<int>>set;

set<int> s;
set<int> s(v.begin(), v.end());
pair<iterator, bool> p = s.insert(10);
it = s.erase(s.begin());
it = s.find(10);


//map
//pair<>
map<int, int> m;
m.insert(pair<int,int>(1,2));
m[key];
m.erase(key);
m.find(key);

//multimap : self balance binary tree
//unordered_map : hash table














