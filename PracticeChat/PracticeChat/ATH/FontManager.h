#pragma once

namespace experiment {
	namespace ATH {
		// 0 = �m�[�}���e�L�X�g
		// 1 = �{�[���h�e�L�X�g
		// 2 = �C�^���b�N�e�L�X�g
		// 3 = �{�[���h�C�^���b�N

		class FontManager
		{
			void _makeFont(int kind, int fontsize);
		public:
			siv::Font f[4];
			void setFontsize(int kind, int FontSize);
			FontManager();
			~FontManager();
		};
	}
}