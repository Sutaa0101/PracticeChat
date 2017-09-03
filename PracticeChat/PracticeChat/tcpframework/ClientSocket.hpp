#pragma once
#include <memory>
#include <string>
#include "ByteArray.hpp"

namespace tcpframework {
	class ClientSocket {
		class ClientSocket_impl;
		std::unique_ptr<ClientSocket_impl> impl;
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