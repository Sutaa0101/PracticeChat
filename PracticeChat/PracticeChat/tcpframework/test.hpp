#pragma once
#include <WinSock2.h>
#include <memory>
#include <string>

namespace tcpframework {
	
	//API�������N���X
	class TcpManager {
		WSADATA m_wsa_data;
		TcpManager() = default;
		static TcpManager* instance;
	public:
		
		//API����������
		static bool Init() {
			if (instance != nullptr)return false;
			instance = new TcpManager();
			
			int error=WSAStartup(MAKEWORD(2, 0), &instance->m_wsa_data);
			if (error != 0)return false;
			return true;
		}

		//API�I������
		static void End() {
			
			WSACleanup();
			delete instance;
		}
	};


	//���M�p�\�P�b�g�N���X
	class SendSocket {
		SOCKET m_sock;
		sockaddr_in m_addr;
	public:
		SendSocket(const SOCKET& sock,const sockaddr_in& addr):
			m_sock(sock),m_addr(addr)
		{}

		//���M
		int Send(const std::string& str) {
			return send(m_sock, str.c_str(), str.size(), 0);

		}
	};

	//�T�[�o�Ŏg���\�P�b�g�N���X
	class ServerSocket {
		SOCKET m_sock;
		sockaddr_in m_addr;
		const int m_max_connect;
	public:
		ServerSocket(u_short port,int max_connect)
			:m_sock(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)),
			m_max_connect(max_connect)
		{	
			m_addr.sin_family = AF_INET;
			m_addr.sin_port = htons(port);
			m_addr.sin_addr.S_un.S_addr = INADDR_ANY;
		}

		//�\�P�b�g�ɏ���R�Â�
		bool Bind() {
			return bind(m_sock, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr))==0;
		}

		//�\�P�b�g���ڑ��ҋ@�ł���悤�ɂ���
		bool Listen() {
			return listen(m_sock, m_max_connect) == 0;
		}

		//�ڑ���ҋ@����
		std::unique_ptr<SendSocket> Accept() {
			sockaddr_in client;
			int len = sizeof(client);
			SOCKET socket= accept(m_sock, reinterpret_cast<sockaddr *>(&client), &len);
			if (socket == INVALID_SOCKET)
				return nullptr;
			return std::make_unique<SendSocket>(socket, client);
		}
	};


}