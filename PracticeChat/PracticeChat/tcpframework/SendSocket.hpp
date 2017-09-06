#pragma once
#include <memory>
#include <thread>
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
		//class SendSocket_impl;
		//std::unique_ptr<SendSocket_impl> impl;
		const SOCKET m_sock;

	public:
		//�ڑ���̃\�P�b�g��n��
		SendSocket(const SOCKET& sock) :m_sock(sock){};
		~SendSocket();

		//�f�[�^���󂯎��
		int Receive(ByteArray&&);

		//Receive�̔񓯊���
		template<class GetResultFunc>
		void ReceiveAsync(GetResultFunc func) {
			std::thread thr([&func, this]() {
				ByteArray bytes;
				while (true) {
					int byteSize = this->Receive(std::move(bytes));
					if (func(std::move(bytes), byteSize) == false)return;
				}
			});
			thr.detach();
		}

		//�\�P�b�g�I������
		bool Close();

		//�f�[�^�𑗐M����i�Ԃ�l�͑��M�����o�C�g���B -1�ŃG���[�j
		int Send(const std::string& str);
	};
}