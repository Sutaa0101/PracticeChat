#pragma once
#include "../tcpframework/tcpframework.hpp"
#include <vector>
#include <mutex>
namespace experiment {
	template<class T>
	using u_ptr = std::unique_ptr<T>;
	using tcpframework::ServerSocket;
	using tcpframework::SendSocket;

	class TestElipmoc {
		u_ptr<ServerSocket> server;
		std::mutex mtx;
		std::vector<u_ptr<SendSocket>> send;
	public:
		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
			//���_1
			//�ڑ����@5�ɂ��Ă��̂�
			//���ʂɒ����ꂽ
			server = std::make_unique<tcpframework::ServerSocket>(19132, 5);
			siv::Println(server->Bind());
			siv::Println(server->Listen());
			server->AcceptAsync([&send=send,&mtx=mtx](auto sendsock) mutable
			{
				sendsock->Send("��������킗��������");
				sendsock->ReceiveAsync([](tcpframework::ByteArray&& bytes, int byteSize) 
				{
					if (byteSize == -1)return false;
					std::string s(bytes.GetBytes(), bytes.Size());
					siv::Println(siv::CharacterSet::Widen(s));
					return true;
				});

				std::lock_guard<std::mutex> lock(mtx);
				send.push_back(std::move(sendsock));
				return true;
			});
		}
		void Update() {
		}
		void End() {
			tcpframework::TcpManager::End(); 
		}
	};
}