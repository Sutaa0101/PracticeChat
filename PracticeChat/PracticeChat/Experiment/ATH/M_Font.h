#pragma once

namespace experiment {
	namespace ATH {
		class M_Font
		{
			// 0 = �m�[�}���e�L�X�g
			// 1 = �{�[���h�e�L�X�g
			// 2 = �C�^���b�N�e�L�X�g
			// 3 = �{�[���h�C�^���b�N
		public:
			static siv::Font MakeFont(int kind, int fontsize);
			M_Font();
			~M_Font();
		};
	}
}