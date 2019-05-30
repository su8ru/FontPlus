# include <Siv3D.hpp> // Siv3D August 2016 v2
# include "./FontPlus/FontP.hpp"

void Main()
{
	const FontP font(30);
	FontAsset::Register(L"font", 30, L"Yu Gothic UI Regular");

	while (System::Update())
	{
		((DrawableStringP)FontAsset(L"font")(L"＊This is old Siv3D.")).draw(Arg::bottomRight, Window::Size());

		font(L"＊This is old Siv3D.").draw(Arg::center, Window::Center());
	}
}
