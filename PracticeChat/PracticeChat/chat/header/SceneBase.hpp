#pragma once

namespace chat {
	//�V�[���Ԃŋ��L����f�[�^
	struct ShareGameData { };
	//�V�[������N���X
	using MySceneManager = ham::SceneManager<siv::String, ShareGameData>;
	//�V�[���̊��N���X
	using MySceneBase = MySceneManager::Scene;
}