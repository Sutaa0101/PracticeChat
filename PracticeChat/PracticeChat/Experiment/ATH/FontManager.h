#pragma once

namespace experiment {
	namespace ATH {
		// 0 = �m�[�}���e�L�X�g
		// 1 = �{�[���h�e�L�X�g
		// 2 = �C�^���b�N�e�L�X�g
		// 3 = �{�[���h�C�^���b�N

		/* �t�@�N�g���p�^�[�����ۂ����� */
		class FontManager
		{
		public:
			siv::Font static makeFont(int kind, int fontsize);

			/*
			void setFontsize(int kind, int FontSize);
			FontManager();
			*/

			~FontManager();
		};
	}
}