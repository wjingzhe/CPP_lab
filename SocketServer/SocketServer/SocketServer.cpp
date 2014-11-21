// SocketServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")



#define LENGTH 100

extern "C"
{
	
	int _tmain(int argc, _TCHAR* argv[])
	{
		/*typedef char A,*B;
		cout<<sizeof(A)<<endl;
		cout<<sizeof(B)<<endl;
		cout<<sizeof(unsigned short)<<endl;
		cout<<sizeof(ULONG_PTR)<<endl;
		cout<<sizeof(unsigned long)<<endl;*/
		WORD wVersionRequested;

		WSADATA  wsaData;

		int err;

		//�汾����1.1
		wVersionRequested = MAKEWORD(1,1);

		err = WSAStartup(wVersionRequested,&wsaData);

		if (err!=0)
		{
			return 1;
		}

		//�汾��⣬�Ƿ�socket�汾Ϊ1.1
		if (LOBYTE(wsaData.wVersion)!=1 || HIBYTE(wsaData.wVersion)!=1)
		{
			WSACleanup();
			return 1;
		}

		//����socket,V4���ֽ���
		SOCKET sockSrv = socket(AF_INET,SOCK_DGRAM,0);

		/*
		*
		typedef struct sockaddr_in 
		{
			
			#if(_WIN32_WINNT < 0x0600)
				short   sin_family;
			#else //(_WIN32_WINNT < 0x0600)
				ADDRESS_FAMILY sin_family;
			#endif //(_WIN32_WINNT < 0x0600)

				USHORT sin_port;
				IN_ADDR sin_addr;
				CHAR sin_zero[8];
		} SOCKADDR_IN, *PSOCKADDR_IN;
		*/

		SOCKADDR_IN addrSrv;

		addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //�����������ַת��Ϊ�����ֽ�����Ϊ�ߵ�λ�Ķ�ȡ�ڲ�ͬ�Ļ����ǲ�һ���ģ�socket�� api��֤�����ݶ�ȡ��Ϊ��һ���ԡ�
		addrSrv.sin_family = AF_INET;//Э�����ΪIPv4������Э��
		addrSrv.sin_port = htons(6000);
		//��Ȼ������SOCKADDR_IN�����ݽṹ������֪��ǰ��2+4+8 �ֽ� ת��Ϊchar[14],sin_zero[8]��Ԥ��λ��Ϊ�������°洫��Э�顣
		//cout<<sizeof(addrSrv.sin_addr)<<endl;

		//��Socket����ַ�Ͷ˿ں�
		err = bind(sockSrv,reinterpret_cast<SOCKADDR*>(&addrSrv),sizeof(SOCKADDR));
		if (err==-1)
		{
			cerr<<"bind:"<<endl;
			return -1;
		}
		//����
	//	err = listen(sockSrv,20);
		if (err==-1)
		{
			cerr<<"listen"<<endl;
			return -1;
		}

		char recvBuf[LENGTH];
		char sendBuf[LENGTH];
		char tempBuf[LENGTH*2];

		SOCKADDR_IN addrClient;
		int len = sizeof(SOCKADDR);

		cout<<"server is runing...."<<endl;

		do
		{
			//����UDPЭ��
			if(recvfrom(sockSrv,recvBuf,LENGTH,0,(SOCKADDR*)(&addrClient),&len)==-1)
			{
				cerr<<"recvfrom"<<endl;
				return -1;
			};

			cout<<addrClient.sin_family<<"\t"<<addrClient.sin_port<<"\t"<<inet_ntoa(addrClient.sin_addr)<<endl;

			if('q' == recvBuf[0])
			{
				sendto(sockSrv,"q",strlen("q")+1,0,reinterpret_cast<SOCKADDR*>(&addrClient),len);
				cout<<"Chat endl"<<endl;
				break;
			}

			sprintf_s(tempBuf,"%s say : %s",inet_ntoa(addrClient.sin_addr),recvBuf);

			cout<<tempBuf<<endl;
			cout<<"Please input data:"<<ends;
			gets_s(sendBuf);
			sendto(sockSrv,sendBuf,strlen(sendBuf)+1,0,reinterpret_cast<SOCKADDR*>(&addrClient),len);

		} while (true);

		closesocket(sockSrv);
		WSACleanup();

		return 0;
	}


}