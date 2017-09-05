#pragma once
namespace experiment {
	namespace ATH {
		class Text
		{
			s3d::Font font;
			s3d::String text;
			int drawX, drawY; // ���ۂ� draw ����
			int fontPattern;
			int fontSize;
			siv::Color color;

			Text();
		public:
			/*
			Text(int fontSize);
			// Text(int fontSize, s3d::Typeface tf, s3d::FontStyle fs);
			Text(int fontSize, int fontPattern);
			Text(int fontSize, int fontPattern, int _drawX, int _drawY, siv::Color color);
			Text(int fontSize, int fontPattern, int _drawX, int _drawY);
			*/
			Text(const siv::String& _text, int _fontSize = 24, int _fontPattern = 0, int _drawX = 0, int _drawY = 0, const siv::Color& _color = { 0, 0, 0 });

			void Update();
			void Draw();
			void SetFontsize(int fontSize) noexcept;
			void SetColor(const siv::Color& color) noexcept; // siv::Palette::Lightgreen
			void End(){}

			~Text();
		};
	}
}

