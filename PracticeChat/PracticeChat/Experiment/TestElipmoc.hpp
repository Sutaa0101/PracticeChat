#pragma once
#include "../tcpframework/tcpframework.hpp"
namespace experiment {

	class TestElipmoc {
	public:
		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
			tcpframework::ClientSocket client(19132, "localhost");
			siv::Println(client.Connect());
			client.Send("あわあああああ！");
		}
		void Update() {}
		void End() { tcpframework::TcpManager::End(); }
	};
}