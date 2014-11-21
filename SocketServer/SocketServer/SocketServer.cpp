// SocketServer.cpp : 定义控制台应用程序的入口点。
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

		//版本定义1.1
		wVersionRequested = MAKEWORD(1,1);

		err = WSAStartup(wVersionRequested,&wsaData);

		if (err!=0)
		{
			return 1;
		}

		//版本检测，是否socket版本为1.1
		if (LOBYTE(wsaData.wVersion)!=1 || HIBYTE(wsaData.wVersion)!=1)
		{
			WSACleanup();
			return 1;
		}

		//建立socket,V4，字节流
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

		addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //二进制网络地址转换为网络字节序，因为高低位的读取在不同的机器是不一样的，socket的 api保证了数据读取行为的一致性。
		addrSrv.sin_family = AF_INET;//协议家族为IPv4互联网协议
		addrSrv.sin_port = htons(6000);
		//虽然看不懂SOCKADDR_IN的数据结构，但是知道前面2+4+8 字节 转化为char[14],sin_zero[8]是预留位，为向后兼容新版传送协议。
		//cout<<sizeof(addrSrv.sin_addr)<<endl;

		//绑定Socket、地址和端口号
		err = bind(sockSrv,reinterpret_cast<SOCKADDR*>(&addrSrv),sizeof(SOCKADDR));
		if (err==-1)
		{
			cerr<<"bind:"<<endl;
			return -1;
		}
		//监听
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
			//用于UDP协议
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