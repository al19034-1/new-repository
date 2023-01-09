#include <stdio.h>

/* 盤のサイズ */
#define SIZE (8)
#define WIDTH (SIZE)
#define HEIGHT (SIZE)

/* 石の色 */
typedef enum color {
  white,
  black,
  empty
} COLOR;

/* 石を置けるかどうかの判断 */
typedef enum put {
  ok,
  ng
} PUT;

/* 盤を表す二次元配列 */
COLOR b[HEIGHT][WIDTH];

/* 盤を初期化 */
int init(void){
  unsigned char x, y;

  for(y = 0; y < HEIGHT; y++){
    for(x = 0; x < WIDTH; x++){
      b[y][x] = empty;
    }
  }

  /* 盤面の真ん中に石を置く */
  b[HEIGHT / 2][WIDTH / 2] = white;
  b[HEIGHT / 2 - 1][WIDTH / 2 - 1] = white;
  b[HEIGHT / 2 - 1][WIDTH / 2] = black;
  b[HEIGHT / 2][WIDTH / 2 - 1] = black;

  return 0;
}

/* マスを表示 */
int displaySquare(COLOR square){

  switch(square){
  case white:
    /* 白色の石は "o" で表示 */
    printf("o");
    break;
  case black:
    /* 黒色の石は "*" で表示 */
    printf("*");
    break;
  case empty:
    /* 空きは " " で表示 */
    printf(" ");
    break;
  default:
    printf("エラー");
    return -1;
  }
  return 0; 
}

/* 盤を表示 */
int display(void){
  int x, y;

  for(y = 0; y < HEIGHT; y++){
    /* 盤の横方向のマス番号を表示 */
    if(y == 0){
      printf(" ");
      for(x = 0; x < WIDTH; x++){
        printf("%d", x);
      }
      printf("\n");
    }

    for(x = 0; x < WIDTH; x++){
      /* 盤の縦方向のます番号を表示 */
      if(x == 0){
        printf("%d", y);
      }

      /* 盤に置かれた石の情報を表示 */
      displaySquare(b[y][x]);
    }
    printf("\n");
  }

  return 0;
}