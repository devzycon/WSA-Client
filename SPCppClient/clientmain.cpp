#include "stdafx.h"
#include<winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include<tchar.h>



int main() {
	SOCKET clientSocket = INVALID_SOCKET;
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 2);

	int wsaErr;
	const int port = 55555; // server port to connect to

	wsaErr = WSAStartup(wVersionRequested, &wsaData);

	if (wsaErr != 0) {
		std::cout << "Failure to init WinSock" << std::endl;
		return 0;
	}
	else {
		std::cout << "Successfully init'd WinSock" << std::endl;
		std::cout << "Status: " << wsaData.szSystemStatus << std::endl;
	}

	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		std::cout << "Failed to create SOCKET instance: " << WSAGetLastError() << std::endl;
		WSACleanup();
		return 0;
	}
	else {
		std::cout << "Successfully created SOCKET instance" << std::endl;
	}
	

	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);

	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
		std::cout << "Failure to connect to server: " << WSAGetLastError() << std::endl;
		WSACleanup();
		return 0;

	}

	else {
		std::cout << "Client: Successfully connected to server at port: " << port << std::endl;
		std::cout << "Client: Ready to send & recieve data from server" << std::endl;
	}
	

	// sending information to server

	
	char buffer[200]; 

	std::cout << "Enter a message: " << std::endl;
	std::cin.getline(buffer, 200);

	int byteCount = send(clientSocket, buffer, 200, 0);
	
	if (byteCount > 0)
		std::cout << "CLIENT: " << buffer << std::endl;
	else{
		std::cout << "Failure to send to server, terminating WSA " << std::endl;
		WSACleanup();
		return 0;
	}


	// receiving from server

	byteCount = recv(clientSocket, buffer, 200, 0);

	if (byteCount > 0)
		std::cout << "msg received: " << buffer << std::endl;
	else
		WSACleanup();
	
	
		



}