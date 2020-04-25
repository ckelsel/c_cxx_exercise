// Exercise.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// ��Ա����
	void f()
	{
		std::cout << "f \n";
	}

	void f2()
	{
		std::cout << "f \n";
	}

	// ��Ա��������f
	void f2(std::string &str)
	{

	}

	// ��̬��Ա����
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

	// ��lamba
	std::function<void(int)> f3 = l;
	l(1);

	// ����ͨ����
	std::function<void(std::string)> f2 = Print;
	f2(std::string("f2"));

	// 1������ͨ���غ���
	// ������ʾ�����������ͣ�(void (*)())
	std::function<void()> f5 = (void (*)())&OverridePrint;
	f5();

	// 2������ͨ���غ���
	std::function<void(std::string)> f4 = (void (*)(std::string &))&OverridePrint;
	f4(std::string("f4"));

	A a;
	// std::function�޷��󶨳�Ա����
#if 0
	std::function<void()> f = A::f;
#else
	std::function<void()> f = std::bind(&A::f, &a);
	f();
#endif

	// ����ľ�̬����
	std::function<void()> s = A::s;
	s();
}

void test_bind()
{
	// ��ͨ����
	auto f = std::bind(Print, std::placeholders::_1);
	f(std::string("bind"));

	// 1������ͨ���غ���
	auto f1 = std::bind((void(*)())&OverridePrint);
	f1();

	// 2������ͨ���غ���,
	// ǿ��ת���������ͣ�(void(*)(std::string&))
	// std::function����Ҫ_1
	// std::bind���в�������������std::placeholders����
	auto f2 = std::bind((void(*)(std::string&))&OverridePrint, std::placeholders::_1);
	f2(std::string("bind"));

	// lamba
	auto f3 = std::bind([](std::string &str) {
		std::cout << str.c_str() << "f \n";
	}, std::placeholders::_1);
	f3(std::string("bind"));

	// ��ľ�̬����
	auto f4 = std::bind(&A::s);
	f4();

	// ��ĳ�Ա����
	// ���봫��thisָ��
	auto a = std::make_shared<A>();
	auto f5 = std::bind(&A::f, a);
	f5();

	// 1��������س�Ա����
	// ǿ��ת���������ͣ���Ҫ��һ��A::
	auto f6 = std::bind((void (A::*)())&A::f2, a);
	f6();

	// 2��������س�Ա����
	auto f7 = std::bind((void (A::*)(std::string &))&A::f2, a, std::placeholders::_1);
	f7(std::string("bind"));
}



