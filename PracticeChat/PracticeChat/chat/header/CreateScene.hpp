#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class CreateScene : public MySceneBase
	{
		siv::GUI gui;

	public:

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);

			//���[�U�[���̓��͗�
			gui.addln(siv::GUIText::Create(L"Port�ԍ�"));
			gui.addln(L"portNumber", siv::GUITextField::Create(11));
			
			//�{�^��
			gui.add(L"create", siv::GUIButton::Create(L"�����쐬"));
			gui.add(L"logout", siv::GUIButton::Create(L"���O�A�E�g"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			//IME�̈ʒu�ύX
			if (gui.textField(L"portNumber").active)
				siv::IME::SetCompositionWindowPos(gui.getPos() + siv::Point(25, 48));

			if (gui.button(L"create").pushed)
				CreatePush();
			if (gui.button(L"logout").pushed)
				LogoutPush();
		}

		void draw() const override
		{
			m_data->font(L"�N���G�C�g�V�[���\��").draw();
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
}