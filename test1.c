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