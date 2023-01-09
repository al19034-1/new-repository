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
/* 指定された場所に石を置く */
int put(int x, int y, COLOR color){
  int i, j;
  int s, n;
  COLOR other;

  /* 相手の石の色 */
  if(color == white){
    other = black;
  } else if(color == black){
    other = white;
  } else {
    return -1;
  }

  /* 全方向に対して挟んだ石をひっくり返す */
  for(j = -1; j < 2; j++){
    for(i = -1; i < 2; i++){

      /* 真ん中方向はチェックしてもしょうがないので次の方向の確認に移る */
      if(i == 0 && j == 0){
        continue;
      }

      if(y + j <0 || x + i < 0 || y + j >= HEIGHT || x + i >= WIDTH){
        continue;
      }
      /* 隣が相手の色でなければその方向でひっくり返せる石はない */
      if(b[y + j][x + i] != other){
        continue;
      }

      /* 置こうとしているマスから遠い方向へ１マスずつ確認 */
      for(s = 2; s < SIZE; s++){
        /* 盤面外のマスはチェックしない */
        if(
          x + i * s >= 0 &&
          x + i * s < WIDTH &&
          y + j * s >= 0 &&
          y + j * s < HEIGHT
        ){

          if(b[y + j * s][x + i * s] == empty){
            /* 自分の石が見つかる前に空きがある場合 */
            /* この方向の石はひっくり返せないので次の方向をチェック */
            break;
          }

          /* その方向に自分の色の石があれば石がひっくり返せる */
          if(b[y + j * s][x + i * s] == color){
            /* 石を置く */
            b[y][x] = color;

            /* 挟んだ石をひっくり返す */
            for(n = 1; n < s; n++){
              b[y + j * n][x + i * n] = color;
            }
            break;
          }
        }
      }
    }
  }

  return 0;
}
