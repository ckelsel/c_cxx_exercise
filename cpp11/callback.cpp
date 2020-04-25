// Exercise.cpp : 定义控制台应用程序的入口点。
//

#include <functional>
#include <string>
#include <iostream>
#include <memory>

// 场景：下载数据后，不同的操作
//1）朴素设计 —— 数据和计算耦合
//
//2）控制反转 —— 解耦发送者和接收者
//
//3）回调闭包 —— 函数签名“替换”类层次结构
//
//4）泛型编程 —— 抽象概念“替换”类层次结构
//
//5）错误设计 —— Derived - Base - Derived


//----------------------------------------------
//1）朴素设计 —— 数据和计算耦合
void Print2(std::string &str)
{
	std::cout << str.c_str() << std::endl;
}

// 下载数据后，需要打印
void DownloadAsyncAndPrint()
{
	std::string result = "abc";// 数据
	Print2(result);//计算在同一个函数内
}

void WriteDB(std::string &str)
{
	std::cout << "DB " << str.c_str() << std::endl;
}

// 下载数据后，需要写入数据库
void DownloadAsyncAndWriteDB()
{
	std::string result = "abc";
	WriteDB(result);
}

//----------------------------------------------


//
//2）控制反转 —— 解耦发送者和接收者
//为了解决这个问题，需要引入 控制反转(IoC)。从 纯面向对象 的视角看：
//
//一个数据：result
//
//两个角色：发送者（DownloadAsyncImpl）和 接收者（Print / WriteToDB）
//
//一个目的：解耦(decouple) 发送者和接收者
//
//一般把公共逻辑抽象为 框架(framework)，再用以下两种方法实现（参考：控制反转 —— 计算可扩展性）。

// 方案1(模板方法)：下载DownloadAsync和处理Handle封装为一个Downloader类，然后继承该类实现不同的方式
class Downloader {
public:
	virtual ~Downloader() = default;

	void DownloadAsync() {
		std::string result = "abc";// 数据

		Handle(result);
	}

protected:
	virtual void Handle(std::string &) = 0;
};

class PrintDownloader : public Downloader {
protected:
	void Handle(std::string &str) override {
		Print2(str);
	}
};

// 方案2(策略模式，组合）：将处理封装为一个纯虚类Handler，然后PrintHandler继承该类实现不同的处理

class Handler {
public:
	virtual ~Handler() = default;
	virtual void Handle(std::string &) = 0;
};

class PrintHandler : public Handler {
public:
	void Handle(std::string &str) override {
		Print2(str);
	}
};

void DownloadSync(std::unique_ptr<Handler> handler) {
	std::string result = "abc";// 数据

	handler->Handle(result);
}

//--> 方案1(模板方法）和方案2(策略模式，组合）的问题在于：引入了基类


//----------------------------------------------

//3） 回调闭包 —— 函数签名“替换”类层次结构
//其实，可以使用 回调闭包(callback closure) 实现等效的 依赖注入(DI) 功能：

// 基于方案2(策略模式，组合）来修改：
//Handler基类改为callback closure
// 这样就去掉了class

using OnDoneCallable = std::function<void(std::string &)>;

void DownloadAsync(OnDoneCallable callback)
{
	std::string result = "abc";
	callback(result);
}

//----------------------------------------------

//4) 泛型编程 —— 抽象概念“替换”类层次结构
//实际上，也可以使用 泛型编程(generic programming) 进一步化简：
//使用模板来实现

template <typename onDone>
void DownloadAsnyc(onDone callback) {
	std::string result = "abc";
	callback(result);
}

// DownloadAnsyc(std::bind(Print, std::placeholder::_1);
//----------------------------------------------
