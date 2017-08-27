#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class ServerScene : public MySceneBase
	{
		const siv::Font font;
		siv::GUI gui;

	public:
		ServerScene() :font(10) {}

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);

			//IPv4�̓��͗�
			gui.add(siv::GUIText::Create(L"IPv4"));
			gui.addln(L"ipAddress", siv::GUITextArea::Create(1, 10));

			//�{�^��
			gui.add(L"serverIn", siv::GUIButton::Create(L"ServerIn"));
			gui.add(L"logout", siv::GUIButton::Create(L"LogOut"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			if (gui.button(L"serverIn").pushed)
				ServerInPush();
			if (gui.button(L"logout").pushed)
				LogoutPush();

		}

		void draw() const override
		{
			font(L"�T�[�o�[�V�[���\��").draw();

		}

		//ServerIn�{�^�������������̊֐�
		void ServerInPush()
		{
			changeScene(L"Room");
		}

		//Logout�{�^�������������̊֐�
		void LogoutPush()
		{
			changeScene(L"Login");
		}
	};
}