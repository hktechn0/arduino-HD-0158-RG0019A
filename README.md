# arduino-HD-0158-RG0019A
Arduino library for the KOHA HD-0158-RG0019A (32x16 dot matrix LED panel) built on top of [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library).

## KOHA HD-0158-RG0019A
デジットなどで販売中の、ドットマトリクス LED パネル向けのライブラリです。赤と緑の2色の LED をコントロールできます。

シフトレジスタ方式で、ケーブルで複数パネルを連結するだけで、横に表示領域を拡張することができます。
このライブラリでは、3枚までの動作確認をしていますが、更に接続することも可能です。

- [32×16ドットマトリクスLEDパネル(赤/橙/緑)■限定特価品■ / 32x16DOT-0158-DJK](http://eleshop.jp/shop/g/gEB8411/)
- [★特売品★ドットマトリック表示器（32x16） [HD-0158-RG0019A]](http://www.aitendo.com/product/14111)

## How to use

[Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) を利用しているので、標準で対応しているメソッドが利用可能です。

詳しくは、[Adafruit GFX Library -  Graphics Primitives](https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives) などを参照してください。

## Sample code
ESP32 で動くサンプルコードはこちら。

- [hd-0158-esp32.ino](examples/hd-0158-esp32/hd-0158-esp32.ino)
- [line-things-snippets/esp32-ledmatrix.ino](https://github.com/techno/line-things-snippets/blob/master/esp32/arduino/esp32-ledmatrix/esp32-ledmatrix.ino)
- [動作例 on Twitter](https://twitter.com/hktechno/status/1101720041987366919)
