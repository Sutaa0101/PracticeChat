#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class RoomScene : public MySceneBase
	{
		siv::GUI gui;

	public:

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);
			//���[�U�[�l�[��
			gui.add(siv::GUIText::Create(L"���[�U�[��"));
			gui.addln(L"userName", siv::GUITextField::Create(10));

			//�{�^��
			gui.addln(L"serverOut", siv::GUIButton::Create(L"�ގ�"));

			gui.add(L"hr1", siv::GUIHorizontalLine::Create(1));

			//�`���b�g��
			gui.addln(L"chatMain", siv::GUITextArea::Create(10, 25));

			gui.add(L"hr2", siv::GUIHorizontalLine::Create(1));

			//���b�Z�[�W���͗�
			gui.add(L"message", siv::GUITextField::Create(14));
			//���M�{�^��
			gui.addln(L"send", siv::GUIButton::Create(L"���M"));

			//�F�R�[�h��
			gui.add(L"color", siv::GUITextField::Create(7));
			//�G�t�F�N�g
			gui.add(L"effect", siv::GUICheckBox::Create({ L"Bold",L"Italic" }));

			gui.setCenter(siv::Window::Center());
		}

		void update() override
		{
			if (gui.button(L"serverOut").pushed)
				ServerOutPush();
			if (gui.button(L"send").pushed)
				SendPush();
		}

		void draw() const override
		{
			m_data->font(L"���[���V�[���\��").draw();

		}

		//ServerOut�{�^�������������̊֐�
		void ServerOutPush()
		{
			changeScene(L"Login");
		}

		//Send�{�^�������������̊֐�
		void SendPush()
		{

		}


	};
}