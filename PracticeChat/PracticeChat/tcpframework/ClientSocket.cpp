#include "ClientSocket.hpp"
#include <WinSock2.h>
#include <ws2tcpip.h>


namespace tcpframework {
	class ClientSocket::ClientSocket_impl {
		SOCKET m_sock;
		sockaddr_in m_serverData;
		const u_short m_port;

		//�z�X�g�����o�C�i��ip�ɕϊ�����
		static IN_ADDR serverNameToIp(const std::string& serverName) {
			in_addr hoge;
			//ip�������ip�l�b�g���[�N�o�C�g�I�[�_�[�ɕϊ�����
			if(inet_pton(AF_INET,serverName.c_str(),&hoge)!=1){
				struct addrinfo hints, *res;
				memset(&hints, 0, sizeof(hints));
				hints.ai_socktype = SOCK_STREAM;
				hints.ai_family = AF_INET;
				//�z�X�g���̎��A�z�X�g������hostent�\���̎擾
				if (getaddrinfo(serverName.c_str(),nullptr,&hints,&res))
					throw std::string("�z�X�g����IP�ɕϊ����s");

				hoge.S_un = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.S_un;
				freeaddrinfo(res);
				return hoge;
			}
			return hoge;
		}
	public:
		ClientSocket_impl(u_short port,const std::string& serverName)
			:
			m_port(port),
			m_sock(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))
		{
			if(m_sock==INVALID_SOCKET)
				throw std::string("�\�P�b�g�쐬���s");
			//�ڑ���T�[�o�[�̐ݒ�

			//�A�h���X�t�@�~���ݒ�
			m_serverData.sin_family = AF_INET;
			//�T�[�o�[ip�̐ݒ�
			m_serverData.sin_addr.s_addr = serverNameToIp(serverName).S_un.S_addr;
			m_serverData.sin_port = htons(port);//�|�[�g�ԍ����r�b�O�G���f�B�A���ɕϊ�
		
		}

		bool Connect()const {
			//�Ȃ���܂Ń��[�v
			while (connect(m_sock, (LPSOCKADDR)&m_serverData, sizeof(m_serverData)) == SOCKET_ERROR)
			{
			}
			return true;
		}

		int Send(const std::string& str) const{
			return send(m_sock, str.c_str(), str.size(), 0);
		}

	};

	ClientSocket::ClientSocket(unsigned short port, const std::string & serverIp)
		:impl(std::make_unique<ClientSocket_impl>(port,serverIp))
	{
	}

	ClientSocket::~ClientSocket()
	{
	}

	bool ClientSocket::Connect()const
	{
		return impl->Connect();
	}

	int ClientSocket::Send(const std::string & str)const
	{
		return impl->Send(str);
	}

}