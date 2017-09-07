#pragma once
#include <memory>
#include <string>
#include "def.hpp"
#include "ByteArray.hpp"

namespace tcpframework {
	class ClientSocket {
		SOCKET m_sock;
		std::unique_ptr<sockaddr_in> m_serverData;
		const unsigned short m_port;
		//��M�����f�[�^���ЂƂ����߂�
		ByteArray m_buf;
		//�\�P�b�g�I���t���O
		bool closeFlag = false;
	public:

		ClientSocket(unsigned short port,const std::string& serverIp);

		~ClientSocket();

		//�ڑ���ҋ@����B
		bool Connect()const;

		//�f�[�^�𑗐M����
		int Send(const std::string&)const;

		//�f�[�^��Buf�ɒ��߂�
		//�Ԃ�l�̓o�C�g����
		//�G���[�Ȃ�-1���Ԃ�
		int Receive();

		//Buf�𓾂�
		ByteArray GetBuf();

		//�\�P�b�g���I������
		bool Close();
	};
}