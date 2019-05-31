//----------------------------------------------------------------------------------------
//
//	FontPlus for Siv3D
//
//	Copyright(c) 2019 subaru2003
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this softwareand associated documentation files(the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions :
//
//	The above copyright noticeand this permission notice shall be included in all
//	copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//	SOFTWARE.
//
//----------------------------------------------------------------------------------------

# pragma once
# include <Siv3D.hpp> // Siv3D August 2016 v2

namespace s3d {

	namespace Arg {
		enum Args {
			topLeft,
			topRight,
			bottomLeft,
			bottomRight,
			topCenter,
			bottomCenter,
			leftCenter,
			rightCenter,
			center,
		};
	}


	class DrawableStringP : public DrawableString {

	public:

		DrawableStringP(const Font& font, String&& text) : DrawableString(font, text) {}
		DrawableStringP(const DrawableString& drawableString) : DrawableString(drawableString) {}
		DrawableStringP(const Font& font, const String& text) : DrawableString(font, text) {}

		/// <summary>
		/// ��ʒu���w�肵�ăe�L�X�g��`�悵�܂��B
		/// </summary>
		/// <param name="arg">
		/// ��ʒu
		/// </param>
		/// <param name="pos">
		/// ���W
		/// </param>
		/// <param name="color">
		/// �F
		/// </param>
		/// <param name="lineHeight">
		/// �s�Ԃ̃X�P�[��
		/// </param>
		/// <returns>
		/// �`��̈�
		/// </returns>
		RectF draw (
			Arg::Args arg = Arg::topLeft,
			Vec2 pos = { 0.0, 0.0 },
			ColorF color = Palette::White,
			double lineHeight = 1.0
		) const;

		/// <summary>
		/// �e�L�X�g��`�悵�܂��B
		/// </summary>
		/// <param name="pos">
		/// ���W
		/// </param>
		/// <param name="color">
		/// �F
		/// </param>
		/// <param name="lineHeight">
		/// �s�Ԃ̃X�P�[��
		/// </param>
		/// <returns>
		/// �`��̈�
		/// </returns>
		RectF draw (
			Vec2 pos = { 0.0, 0.0 },
			ColorF color = Palette::White,
			double lineHeight = 1.0
		) const {
			return DrawableString::draw(pos, color, lineHeight);
		}
	};


	class FontP : public Font {

	public:

		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		FontP() : Font() {};

		/// <summary>
		/// �t�H���g���쐬���܂��B
		/// </summary>
		/// <param name="size">
		/// �t�H���g�̃T�C�Y
		/// </param>
		/// <param name="name">
		/// �t�H���g��
		/// </param>
		/// <param name="style">
		/// �t�H���g�̃X�^�C��
		/// </param>
		explicit FontP (
			int32 size,
			const String& name = Typeface::Default,
			FontStyle style = FontStyle::Regular
		) : Font(size, name, style) {}

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~FontP() = default;

		/// <summary>
		/// ��ʒu���w�肵�ăe�L�X�g��`�悵�܂��B
		/// </summary>
		/// <param name="text">
		/// ������
		/// </param>
		/// <param name="arg">
		/// ��ʒu
		/// </param>
		/// <param name="pos">
		/// ���W
		/// </param>
		/// <param name="color">
		/// �F
		/// </param>
		/// <param name="lineHeight">
		/// �s�Ԃ̃X�P�[��
		/// </param>
		/// <returns>
		/// �`��̈�
		/// </returns>
		RectF draw (
			const String& text,
			Arg::Args arg = Arg::topLeft,
			Vec2 pos = { 0.0, 0.0 },
			ColorF color = Palette::White,
			double lineHeight = 1.0
		) const;

		/// <summary>
		/// �`�悷��e�L�X�g���쐬���܂��B
		/// </summary>
		/// <param name="text">
		/// ������
		/// </param>
		/// <returns>
		/// DrawableString
		/// </returns>
		DrawableStringP operator()(const String& text) const {
			return DrawableStringP(*this, text);
		}

		/// <summary>
		/// �`�悷��e�L�X�g���쐬���܂��B
		/// </summary>
		/// <param name="args">
		/// ������ɕϊ�����f�[�^
		/// </param>
		/// <returns>
		/// DrawableString
		/// </returns>
		template <class ... Args>
		inline DrawableStringP operator()(const Args& ... args) const {
			return DrawableStringP(*this, Format(args...));
		}
	};

}
