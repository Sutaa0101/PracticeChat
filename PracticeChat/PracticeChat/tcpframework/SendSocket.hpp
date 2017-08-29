#pragma once
#include <memory>

//������winsock�Œ�`����Ă���^��O���錾
	typedef unsigned int UINT_PTR;
	typedef UINT_PTR SOCKET;
	struct sockaddr_in;
namespace tcpframework {



	//���M�p�\�P�b�g�N���X
	class SendSocket {
		class SendSocket_impl;
		std::unique_ptr<SendSocket_impl> impl;

	public:
		//�ڑ���̃\�P�b�g�Ƃ��̐ڑ���̏���n��
		SendSocket(const SOCKET& sock, const sockaddr_in& addr);
		~SendSocket();

		//�f�[�^�𑗐M����i�Ԃ�l�͑��M�����o�C�g���B -1�ŃG���[�j
		int Send(const std::string& str);
	};
}