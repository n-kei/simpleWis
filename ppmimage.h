/*
  名前 : ppmimage.c
  概要 : PPM形式画像処理ライブラリ
  引数 : なし
  返値 : なし
  履歴 : 2006/10/30 ver. 1.0 笹間 作成
*/

/*
  PPM形式はPGM形式を包括するカラーの画像形式で、
  先頭に型番、コメント、縦横サイズ、画像深度が、
  その後に各画素の画素値が(アスキー又はバイナリで)並ぶ、
  という単純な構造の画像形式。
  (画素値は今回はRGBの3つで各0〜255)

  $ convert test1.png test1.ppm
  $ convert test2.ppm test2.jpg
  のようにconvertコマンドで自由に画像形式は変更可能。
  $ display test3.ppm
  のように画像表示が可能。
*/

#include "ppmimage.h"

/*
  名前 : ppm_read
  概要 : ppm ファイルの読込
  引数 : (入力) char *filename 読込画像ファイル名
  返値 : (出力) PpmImage *     画像データ
  注意 : (入力) file           ファイル名は filename 参照
  履歴 : 2006/10/30 ver. 1.0 笹間 作成
*/

PpmImage *ppm_read(char *filename)
{
  PpmImage *image;
  PpmPixel *pixel;
  FILE *fp;
  char str[MAX_PPM_COMMENT_LENGTH];
  int i, j;

  image = (PpmImage *)malloc(sizeof(PpmImage) * 1);

  fp = fopen(filename, "r");
  if(fp == NULL){
    fprintf(stderr, "ERR; ppm_read : file open error.\n");
    return(NULL);
  }

  fgets(image->type, MAX_PPM_STR_LENGTH, fp); // 1行めに型番
  image->type[strlen(image->type)-1] = '\0';
  fgets(str, MAX_PPM_COMMENT_LENGTH, fp);
  image->comment[0] = '\0';
  if(str[0] == '#'){ // 2行めは # で始まってればコメント
    strncpy(image->comment, str, MAX_PPM_COMMENT_LENGTH);
    image->comment[strlen(image->comment)-1] = '\0';
    fgets(str, MAX_PPM_COMMENT_LENGTH, fp);
  }
  sscanf(str, "%d %d", &image->x, &image->y); // 次行は縦横
  fscanf(fp, "%d\n", &image->z);              // 次行は色深度

  /*
  fprintf(stderr, "CHK; %s %s %d %d %d\n", image->type, image->comment, image->x, image->y, image->z);
  */

  // 2次元的に領域確保
  image->pixels = (PpmPixel **)malloc(sizeof(PpmPixel *) * image->x);
  for(i = 0; i < image->x; i++){
    image->pixels[i] = (PpmPixel *)malloc(sizeof(PpmPixel) * image->y);
  }
  // あるいは 1次元的な確保、つまり、
  // typedef { PpmPixel *pixels; } PpmImage;
  // image->pixels = (PpmPixel)malloc(sizeof(PpmPixel) * image->x * image->y);
  // image->pixels[i * image->y + j]
  // 等の方がCらしいかもしれない。freeの時も変な階層にひっかからずにすむし。

  for(i = 0; i < image->y; i++){ // 全画素について
    for(j = 0; j < image->x; j++){
      pixel = &image->pixels[j][i];
      pixel->r = fgetc(fp); // R, G, B を 1byte ずつ読込
      pixel->g = fgetc(fp);
      pixel->b = fgetc(fp);
    }
  }

  fclose(fp);

  return(image);
}

/*
  名前 : ppm_write
  概要 : ppm ファイルの書込
  引数 : (入力) char *filename 書込画像ファイル名
         (入力) PpmImage *     画像データ
  返値 : (出力) int            成功すれば 0 を返す
  注意 : (出力) file           ファイル名は filename 参照
  履歴 : 2006/10/30 ver. 1.0 笹間 作成
*/

int ppm_write(char *filename, PpmImage *image)
{
  PpmPixel *pixel;
  FILE *fp;
  int i, j;

  /*
  fprintf(stderr, "CHK; %s %s %d %d %d\n", image->type, image->comment, image->x, image->y, image->z);
  */

  fp = fopen(filename, "w");
  if(fp == NULL){
    fprintf(stderr, "ERR; ppm_write : file open error.\n");
    return((int)NULL);
  }

  fprintf(fp, "%s\n", image->type); // 型番を筆頭にヘッダを書込
  //fprintf(fp, "%s\n", image->comment);
  fprintf(fp, "%s\n", "# Created with original PPM-Image-Library.");
  fprintf(fp, "%d %d\n", image->x, image->y);
  fprintf(fp, "%d\n", image->z);
  for(i = 0; i < image->y; i++){ // 全画素について
    for(j = 0; j < image->x; j++){
      pixel = &image->pixels[j][i];
      fputc(pixel->r, fp); // R, G, B を 1byte ずつ書込
      fputc(pixel->g, fp);
      fputc(pixel->b, fp);
    }
  }

  fclose(fp);

  return(0);
}

/*
  名前 : ppm_alloc
  概要 : ppm 画像データの領域確保
  引数 : (入力) int x      画像Xサイズ
         (入力) int y      画像Yサイズ
  返値 : (出力) PpmImage * 画像データ(領域)
  履歴 : 2006/10/30 ver. 1.0 笹間 作成
*/

PpmImage *ppm_alloc(int x, int y)
{
  PpmImage *image;
  int i;

  image = (PpmImage *)malloc(sizeof(PpmImage) * 1);

  strcpy(image->type, "P6");
  image->comment[0] = '\0';
  image->x = x;
  image->y = y;
  image->z = 255;
  image->pixels = (PpmPixel **)malloc(sizeof(PpmPixel *) * image->x);
  for(i = 0; i < image->x; i++){ // 2次元的に領域確保
    image->pixels[i] = (PpmPixel *)malloc(sizeof(PpmPixel) * image->y);
  }

  return(image);
}

/*
  名前 : ppm_free
  概要 : ppm 画像データの領域開放
  引数 : (入力兼出力) PpmImage *     画像データ
  返値 : (出力) int            成功すれば 0 を返す
  履歴 : 2006/10/30 ver. 1.0 笹間 作成
*/

int ppm_free(PpmImage *image)
{
  int i;

  for(i = 0; i < image->x; i++){ // 2次元的に領域開放
    free(image->pixels[i]);
  }
  free(image->pixels);
  free(image);

  return(0);
}

/*
  名前 : ppm_copy
  概要 : ppm 画像のコピー
  引数 : (入力) PpmImage *image 画像データ
  返値 : (出力) PpmImage *      画像データ
  履歴 : 2006/10/30 ver. 1.0 笹間 作成
*/

PpmImage *ppm_copy(PpmImage *image)
{
  PpmImage *copy;
  int i, j;

  copy = ppm_alloc(image->x, image->y);

  for(i = 0; i < image->x; i++){
    for(j = 0; j < image->y; j++){
      copy->pixels[i][j] = image->pixels[i][j];
    }
  }

  return(copy);
}

/*
  名前 : ppm_glassmerge
  概要 : 2枚の ppm 画像ファイルの加算 (指定色の部分を透過扱いで重ねる)
  引数 : (入力) PpmImage *org  原画像データ
         (入力) PpmImage *mask マスク画像データ
         (入力) PpmPixel glass 透過色(マスク画像データ内の特定色を指定)
  返値 : (出力) PpmImage *     画像データ
  履歴 : 2006/10/30 ver. 1.0 笹間 作成
*/

PpmImage *ppm_glassmerge(PpmImage *org, PpmImage *mask, PpmPixel glass)
{
  PpmImage *image;
  PpmPixel *pixel;
  int r, g, b;
  int i, j;

  image = ppm_copy(org);
  r = glass.r;
  g = glass.g;
  b = glass.b;

  for(i = 0; i < image->x; i++){
    for(j = 0; j < image->y; j++){
      pixel = &mask->pixels[i][j];
      if((pixel->r != r) || (pixel->g != g) || (pixel->b != b)){
        image->pixels[i][j] = *pixel;
      }
    }
  }

  return(image);
}
