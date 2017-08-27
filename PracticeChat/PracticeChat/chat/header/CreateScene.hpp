#pragma once
#include "chat\header\SceneBase.hpp"

class CreateScene : public chat::MySceneBase
{
	const siv::Font font;
	siv::GUI gui;

public:
	CreateScene() :font(10) {}

	void init() override
	{
		gui = siv::GUI(siv::GUIStyle::Default);

		//���[�U�[���̓��͗�
		gui.addln(siv::GUIText::Create(L"Port�ԍ�"));
		gui.addln(L"portNumber", siv::GUITextArea::Create(1, 10));

		//�{�^��
		gui.add(L"create", siv::GUIButton::Create(L"ServerCreate"));
		gui.add(L"logout", siv::GUIButton::Create(L"LogOut"));

		gui.setCenter(siv::Window::Center());

	}

	void update() override
	{
		if (gui.button(L"create").pushed)
			CreatePush();
		if (gui.button(L"logout").pushed)
			LogoutPush();
	}

	void draw() const override
	{
		font(L"�N���G�C�g�V�[���\��").draw();
	}
	
	//Create�{�^�������������̊֐�
	void CreatePush()
	{
		changeScene(L"Room");
	}

	//LogOut�{�^�������������̊֐�
	void LogoutPush()
	{
		changeScene(L"Login");
	}
};
