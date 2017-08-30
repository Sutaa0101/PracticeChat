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

		int Send(const std::string&)const;
		ByteArray Receive()const;

		bool Close();
	};
}