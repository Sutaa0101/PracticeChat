#pragma once

namespace chat {
	//�V�[���Ԃŋ��L����f�[�^
	struct ShareGameData {
		siv::String userName;
		siv::String ipAddress;
		siv::String portNumber;
		siv::Font font{ 10 };
	};

	//�V�[������N���X
	using MySceneManager = ham::SceneManager<siv::String, ShareGameData>;
	//�V�[���̊��N���X
	using MySceneBase = MySceneManager::Scene;
}