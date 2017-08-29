#pragma once
#include <memory>
namespace tcpframework {

	class SendSocket;

	//�T�[�o�ŃN���C�A���g�̑ҋ@�Ɏg���\�P�b�g�N���X
	class ServerSocket {
		class ServerSocket_impl;
		std::unique_ptr<ServerSocket_impl> impl;


	public:
		ServerSocket(unsigned short port, int max_connect);

		~ServerSocket();

		//�\�P�b�g�Ƀ|�[�g�A�A�h���X�t�@�~���[�A�T�[�o�[��IP��R�Â�
		bool Bind();

		//�\�P�b�g�̐ڑ��ҋ@����������
		bool Listen();

		//�ڑ���ҋ@����B�ڑ����ꂽ�炻�̐ڑ���̃\�P�b�g��Ԃ�
		std::unique_ptr<SendSocket> Accept();
	};

}