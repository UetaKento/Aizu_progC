#include<stdio.h>

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

typedef struct {
  int B[3][3];
}board;

board P,Q;

int dfs(int,int,int,int,int);
int heuri(void);
void move(int,int);

int main() {
  int i, j,k, x, y, time;
  board S;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &P.B[i][j]);
      if (P.B[i][j] == 0) {
	x = j;
	y = i;
      }
    }
  }

  S = P;

  for (i = 1; i < 46; i++) {
    P = S;

    time = dfs(x, y, i, 0, -1);
    if (time != -1) {
      printf("%d\n", time);
      break;
    }
  }

  return 0;
}

int dfs(int x, int y, int max, int cnt, int n) {
  int i, temp, x0, y0, time, h;

  h = heuri();
  if (h == 0) return cnt;
  else if (cnt + h > max) return -1;

  for (i = 0; i < 4; i++) {
    x0 = x + dx[i];
    y0 = y + dy[i];

    if ((i == (n + 2) % 4 && n != -1) || (x0 < 0 || 3 <= x0 || y0 < 0 || 3 <= y0)) continue;
    temp = P.B[y][x];
    P.B[y][x] = P.B[y0][x0];
    P.B[y0][x0] = temp;

    time = dfs(x0, y0, max, cnt + 1, i);

    if (time != -1) return time;
    temp = P.B[y][x];
    P.B[y][x] = P.B[y0][x0];
    P.B[y0][x0] = temp;
  }

  return -1;
}

int heuri() {
  int i, j, x, y, sum = 0;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (P.B[i][j] == 0) continue;

      x = (P.B[i][j] - 1) % 3 - j;
      y = (P.B[i][j] - 1) / 3 - i;

      if (x < 0) sum -= x;
      else sum += x;

      if (y < 0) sum -= y;
      else sum += y;
    }
  }

  return sum;
}

void move(int x,int y){

}
