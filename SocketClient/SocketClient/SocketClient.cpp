// SocketClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <iostream>
using namespace std;

#define LENGTH 100

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"Starting..."<<endl;
	//������Socket�汾Ϊ1.1����ʼ��Ϊ��ͬ�汾
	WORD wVersionRequested = MAKEWORD(1,1);
	WSADATA wsaData;
	if(WSAStartup(wVersionRequested,&wsaData)!=0)
	{
		return 1;
	}

	//��ʼ��������ͷ������汾����
	if(LOBYTE(wsaData.wVersion)!=1 ||HIBYTE(wsaData.wVersion)!=1)
	{
		return 1;
	}


	SOCKET sockClient = socket(AF_INET,SOCK_DGRAM,0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;//����Э��
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//127.0.0.1Ϊ������ַ��4�ֽڴ洢���ַ���ת��Ϊlong���͡�
	addrSrv.sin_port = htons(6000);//�ɷ���������
	int len = sizeof(SOCKADDR);


	char recvBuf[LENGTH];
	char sendBuf[LENGTH];
	char tempBuf[LENGTH*2];

	do
	{
		cout<<"Please input data:"<<ends;
		gets_s(sendBuf);
		sendto(sockClient,sendBuf,strlen(sendBuf)+1,0,reinterpret_cast<SOCKADDR*>(&addrSrv),len);

		recvfrom(sockClient,recvBuf,LENGTH,0,reinterpret_cast<SOCKADDR*>(&addrSrv),&len);

		if (recvBuf[0]=='q')
		{
			sendto(sockClient,"q",strlen("q")+1,0,reinterpret_cast<SOCKADDR*>(&addrSrv),len);
			cout<<"�����Ự"<<endl;
			break;
		}

		sprintf_s(tempBuf,"%s says:%s",inet_ntoa(addrSrv.sin_addr),recvBuf);
		cout<<tempBuf<<endl;
	} while (true);
	
	closesocket(sockClient);

	WSACleanup();

	return 0;
}

