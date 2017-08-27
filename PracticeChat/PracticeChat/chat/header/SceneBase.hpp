#pragma once

namespace chat {
	//シーン間で共有するデータ
	struct ShareGameData { };
	//シーン操作クラス
	using MySceneManager = ham::SceneManager<siv::String, ShareGameData>;
	//シーンの基底クラス
	using MySceneBase = MySceneManager::Scene;
}