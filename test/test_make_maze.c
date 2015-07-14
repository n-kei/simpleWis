#include "make_maze.h"


int main(void)
{
  int i, j, i1, j1, d, t, **tt;

  srand((unsigned)time(NULL));
  for(i = 0; i <= XMAX; i++)
    for(j = 0; j <= YMAX; j++)
      map[i][j] = 1;

  for(i = 3; i <= XMAX - 3; i++)
    for(j = 3; j <= YMAX - 3; j++)
      map[i][j] = 0;

  map[2][3] = 0;
  map[XMAX - 2][YMAX - 3] = 0;

  for(i = 4; i <= XMAX - 4; i += 2) {
    add_site(i, 2);
    add_site(XMAX - 2, j);
  }


  for(j = 4; j <= YMAX - 4; j += 2) {
    add_site(2, j);
    add_site(XMAX - 2, j);
  }
  while(select_site(&i, &j)) {
    for( ; ; ) {
      tt = dirtable[(int)(24 * (rand() / (RAND_MAX + 1.0)))];
      for(d = 3; d >= 0; d--) {
	t = tt[d];
	i1 = i + dx[t];
	j1 = j + dy[t];
	if(map[i1][j1] == 0)
	  break;
      }
      if(d < 0) 
	break;
      map[(i + i1) / 2][(j + j1) / 2] = 1;
      i = i1;
      j = j1;
      map[i][j] = 1;
      add_site(i, j);
    }
  }
  for(j = 2; j <= YMAX - 2; j++) {
    for(i = 2; i <= XMAX - 2; i++) 
      if(map[i][j])
	putchar('X');
      else
	putchar(' ');
      putchar('\n');
  }

  return(0);
}
