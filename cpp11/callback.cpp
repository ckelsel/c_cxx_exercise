// Exercise.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <functional>
#include <string>
#include <iostream>
#include <memory>

// �������������ݺ󣬲�ͬ�Ĳ���
//1��������� ���� ���ݺͼ������
//
//2�����Ʒ�ת ���� ������ߺͽ�����
//
//3���ص��հ� ���� ����ǩ�����滻�����νṹ
//
//4�����ͱ�� ���� �������滻�����νṹ
//
//5��������� ���� Derived - Base - Derived


//----------------------------------------------
//1��������� ���� ���ݺͼ������
void Print2(std::string &str)
{
	std::cout << str.c_str() << std::endl;
}

// �������ݺ���Ҫ��ӡ
void DownloadAsyncAndPrint()
{
	std::string result = "abc";// ����
	Print2(result);//������ͬһ��������
}

void WriteDB(std::string &str)
{
	std::cout << "DB " << str.c_str() << std::endl;
}

// �������ݺ���Ҫд�����ݿ�
void DownloadAsyncAndWriteDB()
{
	std::string result = "abc";
	WriteDB(result);
}

//----------------------------------------------


//
//2�����Ʒ�ת ���� ������ߺͽ�����
//Ϊ�˽��������⣬��Ҫ���� ���Ʒ�ת(IoC)���� ��������� ���ӽǿ���
//
//һ�����ݣ�result
//
//������ɫ�������ߣ�DownloadAsyncImpl���� �����ߣ�Print / WriteToDB��
//
//һ��Ŀ�ģ�����(decouple) �����ߺͽ�����
//
//һ��ѹ����߼�����Ϊ ���(framework)�������������ַ���ʵ�֣��ο������Ʒ�ת ���� �������չ�ԣ���

// ����1(ģ�巽��)������DownloadAsync�ʹ���Handle��װΪһ��Downloader�࣬Ȼ��̳и���ʵ�ֲ�ͬ�ķ�ʽ
class Downloader {
public:
	virtual ~Downloader() = default;

	void DownloadAsync() {
		std::string result = "abc";// ����

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

// ����2(����ģʽ����ϣ����������װΪһ��������Handler��Ȼ��PrintHandler�̳и���ʵ�ֲ�ͬ�Ĵ���

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
	std::string result = "abc";// ����

	handler->Handle(result);
}

//--> ����1(ģ�巽�����ͷ���2(����ģʽ����ϣ����������ڣ������˻���


//----------------------------------------------

//3�� �ص��հ� ���� ����ǩ�����滻�����νṹ
//��ʵ������ʹ�� �ص��հ�(callback closure) ʵ�ֵ�Ч�� ����ע��(DI) ���ܣ�

// ���ڷ���2(����ģʽ����ϣ����޸ģ�
//Handler�����Ϊcallback closure
// ������ȥ����class

using OnDoneCallable = std::function<void(std::string &)>;

void DownloadAsync(OnDoneCallable callback)
{
	std::string result = "abc";
	callback(result);
}

//----------------------------------------------

//4) ���ͱ�� ���� �������滻�����νṹ
//ʵ���ϣ�Ҳ����ʹ�� ���ͱ��(generic programming) ��һ������
//ʹ��ģ����ʵ��

template <typename onDone>
void DownloadAsnyc(onDone callback) {
	std::string result = "abc";
	callback(result);
}

// DownloadAnsyc(std::bind(Print, std::placeholder::_1);
//----------------------------------------------
