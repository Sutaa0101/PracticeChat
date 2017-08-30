#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class LoginScene : public MySceneBase
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
			gui.add(L"create", siv::GUIButton::Create(L"�����쐬"));
			gui.add(L"login", siv::GUIButton::Create(L"����"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			//if (gui.)
			if (gui.button(L"login").pushed)
				LoginPush();
			if (gui.button(L"create").pushed)
				CreatePush();
		}

		void draw() const override
		{
			font(L"���O�C���V�[���\��").draw();
		}

		//Login�{�^�������������̊֐�
		void LoginPush()
		{
			changeScene(L"Server");

		}

		//Create�{�^�������������̊֐�
		void CreatePush()
		{
			changeScene(L"Create");
		}
	};
}