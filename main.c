/*
  名前 : ppmimage_view2.c
  概要 : 画像表示及びGUIによる黒帯マスク修正(PPM形式画像)
  引数 : なし
  返値 : なし
  履歴 : 2006/12/20 ver. 1.0 笹間 作成
         2007/11/10 ver. 1.1 笹間 誤殖他修正
*/

/*
// Makefile
ppmimage_view: ppmimage_view.c ppmimage.c
        gcc ppmimage_view.c ppmimage.c -o ppmimage_view -L/usr/X11R6/lib -lX11 -Wall
*/

/*
 * === 初期の動作 ===
 * 表示用の画像をimageとして用意
 * display(モニタ)からroot_window(全画面／親画面)を取得
 * root_windowの中に画像表示用windowを配置
 *   windowの配置は (window_x, window_y) に設定
 *   windowの大きさは (image->x, image->y) に設定
 * windowに対応する形でpixmapという表示画像データ領域を用意
 * imageからpixmapへ画像データをコピー
 * pixmapからwindowへ画像データをコピー=表示

 * === メイン ===
 * eventでキー／マウスの動きを取る
 * キー入力があれば、メインループ終了
 * マウスに併せて、マウスの (x, y) を記録
 * マウスに併せて、window表示をいじる(緑枠線、黒塗り)
 *   緑枠線の場合は、一度pixmapで塗り直して(前に書いた枠線をこれで消して)から緑枠線をひく
 *   黒塗り野場合は、imageを編集->pixmap->windowへと順に作業／コピー
*/

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include "ppmimage.h"

#define FILENAME_SIZE 64

/*
  名前 : image_copy_to_pixmap
  概要 : 画像(PpmImage)を表示用の画像データ(Pixmap)へコピー
  引数 : (入力)      PpmImage *image   画像
         (入力兼出力) Pixmap *pixmap    表示部(編集対象)
         (入力)      Display *display  表示部操作に必要 ディスプレイ
         (入力)      GC *gc            表示部操作に必要 グラフィックコンテキスト
  返値 : なし
  履歴 : 2006/12/20 ver. 1.0 笹間 作成
*/
void image_copy_to_pixmap(PpmImage * image, Pixmap * pixmap, Display * display,
                          GC * gc)
{
  PpmPixel *pixel;
  int x, y, pixel_color;

  for (x = 0; x < image->x; x++) {
    for (y = 0; y < image->y; y++) {
      pixel = &image->pixels[x][y];
      // XWindowでは画素値はRGBを個別に扱うのでなく3つの総計値
      pixel_color = pixel->r * 256 * 256 + pixel->g * 256 + pixel->b;
      XSetForeground(display, *gc, pixel_color);
      XDrawPoint(display, *pixmap, *gc, x, y); // 全画素について色点打ちで再生
    }
  }
}

/*
  名前 : blackmask
  概要 : 画像修正 指定矩形領域を黒帯マスク化
  引数 : (入力兼出力) PpmImage *image  画像(編集対象)
         (入力)      int sx           矩形端座標 (sx, sy) - (ex, ey)
         (入力)      int sy
         (入力)      int ex
         (入力)      int ey
  返値 : なし
  履歴 : 2006/12/20 ver. 1.0 笹間 作成
*/
void blackmask(PpmImage * image, int sx, int sy, int ex, int ey)
{
  PpmPixel *pixel;
  int x, y;

  for (x = sx; x < ex; x++) {
    for (y = sy; y < ey; y++) {
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
}



int main(int argc, char *argv[])
{
  // ウィンドウ関係
  Display *display;                    // ディスプレイ
  Window root_window;                  // ルートウィンドウ
  Window window;                       // 表示するウィンドウ
  GC gc;                               // グラフィックスコンテキスト(筆)
  XEvent event;                        // イベント構造体(キー/マウス)
  int window_x = 100, window_y = 100;  // ウィンドウの表示位置(x, y)
  int window_border = 2;               // ウィンドウのボーダの幅
  Pixmap pixmap;                       // 表示画像データの保持体

  KeySym ksy_sym;           

  // ウィンドウ色関係
  int screen;
  Colormap colormap;
  XColor color, exact;
  unsigned long black, white, green;   // 黒白緑の画素値

  // 画像関係
  PpmImage *image;
  char input_file[FILENAME_SIZE], output_file[FILENAME_SIZE];

  // 制御関係
  int keyflag;                         // キーが押されたチェックのフラグ
  int sx, sy, ex, ey;                  // 選択領域の左上端/右下端
  int x, y;


  // 引数処理 入力画像ファイル名必須
  if (argc < 2) {
    fprintf(stderr, "Usage: %s input_file [output_file=output.ppm]\n",
            argv[0]);
    return (1);
  }
  strncpy(input_file, argv[1], FILENAME_SIZE);
  if (argc > 2)
    strncpy(output_file, argv[2], FILENAME_SIZE);
  else
    strncpy(output_file, "output.ppm", FILENAME_SIZE);
  fprintf(stderr, "CHK; 入力画像ファイル名 : %s\n", input_file);
  fprintf(stderr, "CHK; 出力画像ファイル名 : %s\n", output_file);

  // 画像読込
  image = ppm_read(input_file);

  printf("X = %d\n", image->x);
  printf("Y = %d\n", image->y);
  // 画像表示/操作用のウィンドウの準備
  display = XOpenDisplay("");                // ディスプレイ
  root_window = DefaultRootWindow(display);  // ルートウィンドウ

  // 色関係の処理
  screen   = DefaultScreen(display);
  colormap = DefaultColormap(display, screen);
  white    = WhitePixel(display, screen);    // 白
  black    = BlackPixel(display, screen);    // 黒
  XAllocNamedColor(display, colormap, "green", &color, &exact);
  green    = color.pixel;                    // 緑

  // ウィンドウを作成(まだ否表示)
  window =
    XCreateSimpleWindow(display, root_window, window_x, window_y, image->x,
                          image->y, window_border, black, white);
  // グラフィックスコンテキスト(画素操作用構造体/いわば筆)を作成
  gc = XCreateGC(display, window, 0, NULL);
  // Xサーバから通知して貰うイベントを指定 マウス操作とキー操作の一部
  XSelectInput(display, window,
               KeyPressMask | ButtonPressMask | ButtonMotionMask |
               ButtonReleaseMask);

  // 表示用の画像データ(Pixmap)の作成
  pixmap = XCreatePixmap(display, window, image->x, image->y, DefaultDepth(display, 0));
  image_copy_to_pixmap(image, &pixmap, display, &gc);

  XMapWindow(display, window);    // ウィンドウ表示
  XFlush(display);
  XCopyArea(display, pixmap, window, gc, 0, 0, image->x, image->y, 0, 0); // 画像表示
  XFlush(display);

  keyflag = 1;
  while (keyflag) {               // Xサーバからイベントを読み込むイベントループ
    XNextEvent(display, &event);  // Xサーバからイベントを読み込む
    switch (event.type) {
    case KeyPress:                // キーが押された      
      keyflag = 0;
      break;
    case ButtonPress:             // マウスボタンが押された
      sx = event.xbutton.x;
      sy = event.xbutton.y;
      printf("sx = %d\n", sx);
      printf("sy = %d\n", sy);
      ex = sx;
      ey = sy;
      break;
    case ButtonRelease:           // マウスボタンが離された
      printf("ex = %d\n", ex);
      printf("ey = %d\n", ey);
      blackmask(image, sx, sy, ex, ey); // 画像処理
      image_copy_to_pixmap(image, &pixmap, display, &gc); //表示用部にコピー
      // ウィンドウ表示操作
      XCopyArea(display, pixmap, window, gc, 0, 0, image->x, image->y, 0, 0); // 画像表示
      XFlush(display);
      break;
    case MotionNotify:            // マウスがドラッグされた
      x = event.xbutton.x;
      y = event.xbutton.y;
      if (x <= sx)
        sx = x;
      else
        ex = x;
      if (y <= sy)
        sy = y;
      else
        ey = y;
      // ウィンドウ表示操作
      XCopyArea(display, pixmap, window, gc, 0, 0, image->x, image->y, 0, 0); // 画像表示
      XSetForeground(display, gc, green); // 緑で書く選択
      XDrawRectangle(display, window, gc, sx, sy, ex - sx, ey - sy); // 選択領域を表示
      XFlush(display);
      break;
    }
  }

  // 画像書込
  ppm_write(output_file, image);

  // 後始末
  ppm_free(image);
  XFreeGC(display, gc);
  XDestroyWindow(display, window);
  XCloseDisplay(display);

  return (0);
}
