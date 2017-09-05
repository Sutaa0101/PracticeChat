#pragma once
#include <memory>
#include "ByteArray.hpp"

//������winsock�Œ�`����Ă���^��O���錾
#ifdef	_WIN64
	typedef unsigned __int64 UINT_PTR;
#elif defined _WIN32
	typedef unsigned int UINT_PTR;
#endif 

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

		//�f�[�^���󂯎����buf�ɒ��߂�
		int Receive();

		//buf�𓾂�
		ByteArray GetBuf()noexcept;

		//�\�P�b�g�I������
		bool Close();

		//�f�[�^�𑗐M����i�Ԃ�l�͑��M�����o�C�g���B -1�ŃG���[�j
		int Send(const std::string& str);
	};
}