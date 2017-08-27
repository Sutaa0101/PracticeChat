#pragma once
#include "chat\header\SceneBase.hpp"

class LoginScene : public chat::MySceneBase
{
	const siv::Font font;
	siv::GUI gui;

	public:
		LoginScene() :font(10) {}

	void init() override
	{
		gui = siv::GUI(siv::GUIStyle::Default);

		//���[�U�[���̓��͗�
		gui.addln(siv::GUIText::Create(L"���[�U�[��"));
		gui.addln(L"userName", siv::GUITextArea::Create(1, 10));

		//�{�^��
		gui.add(L"login", siv::GUIButton::Create(L"Login"));
		gui.add(L"exit", siv::GUIButton::Create(L"Exit"));

		gui.setCenter(siv::Window::Center());

	}

	void update() override
	{
		if (gui.button(L"login").pushed)
			changeScene(L"Server");
		if (gui.button(L"exit").pushed)
			siv::System::Exit();
	}

	void draw() const override
	{
		font(L"���O�C���V�[���\��").draw();

	}
};
