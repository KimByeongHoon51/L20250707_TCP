#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")

using namespace std;

int main()
{
	WSAData wsaData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in ServerAddr;
	memset(&ServerAddr, 0, sizeof(ServerAddr));
	ServerAddr.sin_family = PF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(30303);

	Result = connect(ServerSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

	const char Message[1024] = "Hello 20250707";
	send(ServerSocket, Message, strlen(Message), 0);

	char Buffer[1024] = { 0 };
	recv(ServerSocket, Buffer, 1024, 0);
	cout << Buffer << endl;

	closesocket(ServerSocket);
	WSACleanup();

	return 0;
}