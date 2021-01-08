// win平台查询端口与进程工具.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;

void logPrint() {
	system("cls");
	cout << string(" ____         __                                           \n")
		+ string("/\\  _`\\      /\\ \\__         __                             \n")
		+ string("\\ \\ \\L\\_\\____\\ \\ ,_\\  __  _/\\_\\  ____    __  __     __     \n")
		+ string(" \\ \\  _\\/',__\\\\ \\ \\/ /\\ \\/'\\/\\ \\/\\_ ,`\\ /\\ \\/\\ \\  /'__`\\   \n")
		+ string("  \\ \\ \\/\\__, `\\\\ \\ \\_\\/>  </\\ \\ \\/_/  /_\\ \\ \\_\\ \\/\\ \\L\\.\\_ \n")
		+ string("   \\ \\_\\/\\____/ \\ \\__\\/\\_/\\_\\\\ \\_\\/\\____\\\\/`____ \\ \\__/.\\_\\\n")
		+ string("    \\/_/\\/___/   \\/__/\\//\\/_/ \\/_/\\/____/ `/___/> \\/__/\\/_/\n")
		+ string("                                             /\\___/        \n")
		+ string("                                             \\/__/         \n");
	cout << "\t\t\t\t\t\tfxycode.top\n\n";
}

/*
端口查找
*/
void portSearch(string port) {
	logPrint();

	cout << "查询的端口是:\t" << port << endl;

	cout << "如果没有匹配值可能显示为空行\n" << endl;

	/**
	 * 转换constchar netstat -ano | findstr "8080"
	 */

	 //忘记""如何转换了,只能用复杂点的方式
	std::string l_tmp;
	std::string r_tmp;

	l_tmp = R"+*(")+*" + port;
	r_tmp = R"+*(")+*";
	string searchport = string(" netstat -ano | findstr ") + l_tmp + r_tmp;
	char* c;
	const int len = searchport.length();
	c = new char[len + 1];
	strcpy(c, searchport.c_str());

	system(c);
	system("pause");
}
/*
进程查找
*/
void processSearch(string  porcess) {
	logPrint();
	/**
	 * 转换constchar tasklist | findstr "8080"
	 */
	cout << "查询的进程是\t" << porcess << endl;

	std::string l_tmp;
	std::string r_tmp;

	l_tmp = R"+*(")+*" + porcess;
	r_tmp = R"+*(")+*";
	string searchprocess = string("tasklist | findstr ") + l_tmp + r_tmp;
	char* c;
	const int len = searchprocess.length();
	c = new char[len + 1];
	strcpy(c, searchprocess.c_str());

	system(c);
	system("pause");
};
/*
* 杀进程
*/
void KillForPid(string pid) {
	logPrint();

	cout << "要中止的进程是\t" << pid << endl;
	std::string l_tmp;
	std::string r_tmp;

	l_tmp = R"+*(")+*" + pid;
	r_tmp = R"+*(")+*";
	string searchprocess = string("taskkill /pid ") + l_tmp + r_tmp + string(" /F");
	char* c;
	const int len = searchprocess.length();
	c = new char[len + 1];
	strcpy(c, searchprocess.c_str());

	cout << "确定要kill进程吗?\t  0或false取消,其他都为确定\n";
	bool result = false;
	cin >> result;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "输入错误，请重新输入\n" << endl;
		cin >> result;
	}
	if (result)
	{
		system(c);
		system("pause");
	}
	cout << "取消kill,返回主界面\n" << endl;
	return;
};

int main()
{
	logPrint();
	while (1) {
	A:	cout << "输入需要执行的操作\n";
		cout << "1 ===>\t 查询端口\n";
		cout << "2 ===>\t 查询进程\n";
		cout << "3 ===>\t 杀死进程(根据PID)\n";
		cout << "5 ===>\t 退出窗口\n";
		cin.clear();
		int choice = 0;
		cin >> choice;

		/*
		字符清除方案,接收变量是数字,如果注入字符cin进入fail状态,清除状态重新输入
		*/
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入错误，请重新输入\n" << endl;
			cin >> choice;
		}
		cin.get();
		string port;
		string pid;
		string  porcess;
		cin.clear();
		switch (choice)
		{
		case 1:
			cout << "输入要查询的端口\n";
			getline(cin, port);
			cout << "查询的端口信息 ============\n";
			portSearch(port);
			break;

		case 2:
			cout << "输入要查询的进程关键字\n";
			getline(cin, porcess);
			cout << "查询的进程信息 ============\n";
			processSearch(porcess);
			break;

		case 3:
			cout << "输入要Kill的进程PID\n";
			getline(cin, pid);
			cout << "查询的进程信息 ============\n";
			KillForPid(pid);
			break;

		case 5:
			cout << "山高路远,有缘再见!!\n" << endl;
			system("pause");
			exit(0);
		default:
			cout << "输入错误\n" << endl;
			break;
		}
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件