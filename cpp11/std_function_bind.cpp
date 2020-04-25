// Exercise.cpp : 定义控制台应用程序的入口点。
//

#include <functional>
#include <string>
#include <iostream>
#include <memory>

void Print(std::string &str)
{
	std::cout << str.c_str() << std::endl;
}


void OverridePrint()
{
	std::cout <<"OverridePrint" << std::endl;
}

void OverridePrint(std::string &str)
{
	std::cout << "OverridePrint: " << str.c_str() << std::endl;
}

class A
{
public:
	// 成员函数
	void f()
	{
		std::cout << "f \n";
	}

	void f2()
	{
		std::cout << "f \n";
	}

	// 成员函数重载f
	void f2(std::string &str)
	{

	}

	// 静态成员函数
	static void s()
	{
		std::cout << "s \n";
	}
};

void test_std_function()
{
	// lamba
	auto l = [](int a) {
		printf("%d\n", a);
	};

	// 绑定lamba
	std::function<void(int)> f3 = l;
	l(1);

	// 绑定普通函数
	std::function<void(std::string)> f2 = Print;
	f2(std::string("f2"));

	// 1）绑定普通重载函数
	// 必须显示声明函数类型：(void (*)())
	std::function<void()> f5 = (void (*)())&OverridePrint;
	f5();

	// 2）绑定普通重载函数
	std::function<void(std::string)> f4 = (void (*)(std::string &))&OverridePrint;
	f4(std::string("f4"));

	A a;
	// std::function无法绑定成员函数
#if 0
	std::function<void()> f = A::f;
#else
	std::function<void()> f = std::bind(&A::f, &a);
	f();
#endif

	// 绑定类的静态函数
	std::function<void()> s = A::s;
	s();
}

void test_bind()
{
	// 普通函数
	auto f = std::bind(Print, std::placeholders::_1);
	f(std::string("bind"));

	// 1）绑定普通重载函数
	auto f1 = std::bind((void(*)())&OverridePrint);
	f1();

	// 2）绑定普通重载函数,
	// 强制转换函数类型：(void(*)(std::string&))
	// std::function不需要_1
	// std::bind，有参数，基本必有std::placeholders搭配
	auto f2 = std::bind((void(*)(std::string&))&OverridePrint, std::placeholders::_1);
	f2(std::string("bind"));

	// lamba
	auto f3 = std::bind([](std::string &str) {
		std::cout << str.c_str() << "f \n";
	}, std::placeholders::_1);
	f3(std::string("bind"));

	// 类的静态函数
	auto f4 = std::bind(&A::s);
	f4();

	// 类的成员函数
	// 必须传入this指针
	auto a = std::make_shared<A>();
	auto f5 = std::bind(&A::f, a);
	f5();

	// 1）类的重载成员函数
	// 强制转换函数类型，需要多一个A::
	auto f6 = std::bind((void (A::*)())&A::f2, a);
	f6();

	// 2）类的重载成员函数
	auto f7 = std::bind((void (A::*)(std::string &))&A::f2, a, std::placeholders::_1);
	f7(std::string("bind"));
}



