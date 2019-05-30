# FontPlus
Siv3D(旧版)で基準位置を指定してテキストを描画するモジュール
OpenSiv3Dにある基準位置指定を移植しようとしましたが、名前付き引数が実装できずに断念しました。FontAsset対応もちゃんとしたいですね...

## Version
Siv3D August 2016 v2

## 追加されるメソッド

- `FontP::draw(const String& text, Arg::Args arg, Vec2 pos, ColorF color, double lineHeight)`
  `Font.draw()` の形で使用するメソッドです。基本的にはこちらではなく下記メソッドを使うことになります。
- `DrawableStringP::draw(Arg::Args arg, Vec2 pos, ColorF color, double lineHeight)`
  `Font(...args).draw()` の形で使用するメソッドです。

## 使い方

基本的には`Font`と同様に使用できます。
注意点として、`FontAsset`はそのままでは使用できません。Main.cpp:11行目のように、`DrawableStringP`に型変換する必要があります。~いつか技術力が上がったら対応します...多分...~

## 基準位置一覧

- topLeft
- topRight
- bottomLeft
- bottomRight
- topCenter
- bottomCenter
- leftCenter
- rightCenter
- center

## bug等

- [issue](https://github.com/subaru2003/FontPlus/issues)
- [Twitter](https://twitter.com/subaru2003_)
