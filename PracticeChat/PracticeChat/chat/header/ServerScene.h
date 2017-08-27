#pragma once
#include "chat\header\SceneBase.hpp"

class ServerScene : public chat::MySceneBase
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
		gui.addln(L"ipAddress", siv::GUITextArea::Create(1,10));

		//�{�^��
		gui.add(L"serverIn", siv::GUIButton::Create(L"ServerIn"));
		gui.add(L"logout", siv::GUIButton::Create(L"LogOut"));

		gui.setCenter(siv::Window::Center());

	}

	void update() override
	{
		if (gui.button(L"serverIn").pushed)
			changeScene(L"Room");
		if (gui.button(L"logout").pushed)
			changeScene(L"Login");
	}

	void draw() const override
	{
		font(L"�T�[�o�[�V�[���\��").draw();

	}
};
