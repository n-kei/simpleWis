/*#include <stdlib.h>
#include <stdio.h>
*/
#include "dungeon.h"
#include "ppmimage.h"
#include <stdlib.h>
#include <stdio.h>

char map[XMAX + 1][YMAX + 1];
int nsite = 0;
int xx[MAXSITE], yy[MAXSITE];
int dx[4] = {2, 0, -2, 0};
int dy[4] = {0, 2, 0, -2};
int dirtable[24][4] = {
  0,1,2,3, 0,1,3,2, 0,2,1,3, 0,2,3,1, 0,3,1,2, 0,3,2,1,
  1,0,2,3, 1,0,3,2, 1,2,0,3, 1,2,3,0, 1,3,0,2, 1,3,2,0,
  2,0,1,3, 2,0,3,1, 2,1,0,3, 2,1,3,0, 2,3,0,1, 2,3,1,0,
  3,0,1,2, 3,0,2,1, 3,1,0,2, 3,1,2,0, 3,2,0,1, 3,2,1,0 };

void add_site(int i, int j) 
{
  xx[nsite] = i;
  yy[nsite] = j;
  nsite++;
}


int select_site(int *i, int *j)
{
  int r;

  if(nsite == 0) 
    return(0);

  nsite--;
  r = (int)(nsite * (rand() / (RAND_MAX + 1.0)));
 
  *i = xx[r];
  xx[r] = xx[nsite];
  
  *j = yy[r]; 
  yy[r] = yy[nsite];
  return(1);
}

int GetRandom(int min, int max)
{
  return(min+(int)(rand()*(max-min+1.0)/(1.0+RAND_MAX)));
}

int dungeon_move(DUNGEON_MAP *test)
{
  
  switch(test->direction % DUNGEON_DIRECTION_KEY) {
  case NORTH:
    if(map_test[test->current.y - 1][test->current.x] == WALL)
      return(-1);

    else if(map_test[test->current.y - 1][test->current.x] == STEP_UP){
      test->current.y -= 1;
      return(STEP_UP);
    }
    else if(map_test[test->current.y - 1][test->current.x] == STEP_DOWN){
      test->current.y -= 1;
      return(STEP_DOWN);
    }

    else
      test->current.y -= 1;
    break;
    
  case EAST:
    if(map_test[test->current.y][test->current.x + 1] == WALL)
      return(-1);
    else if(map_test[test->current.y][test->current.x+1] == STEP_UP){
      test->current.x += 1;
      return(STEP_UP);
    }
    else if(map_test[test->current.y][test->current.x+1] == STEP_DOWN){
      test->current.x += 1;
      return(STEP_DOWN);
    }
    else 
      test->current.x += 1;
    break;
    
  case WEST:
    if(map_test[test->current.y][test->current.x - 1] == WALL)
      return(-1);
    else if(map_test[test->current.y][test->current.x-1] == STEP_UP){
      test->current.x -= 1;
      return(STEP_UP);
    }
    else if(map_test[test->current.y][test->current.x-1] == STEP_DOWN){
      test->current.x -= 1;
      return(STEP_DOWN);
    }
    else
      test->current.x -= 1;
    break;
    
  case SOUTH:
    if(map_test[test->current.y + 1][test->current.x] == WALL)
      return(-1);
    else if(map_test[test->current.y + 1][test->current.x] == STEP_UP){
      test->current.y += 1;
      return(STEP_UP);
    }
    else if(map_test[test->current.y + 1][test->current.x] == STEP_DOWN){
      test->current.y += 1;
      return(STEP_DOWN);
    }

    else
	 test->current.y += 1;
    break;
       }
      
  printf("X = %d\nY = %d\n", test->current.x,
	 test->current.y);
  return(0);
}

int dungeon_free_map(DUNGEON_MAP *test)
{
  int i,j;

  for(i=0; i<MAP_LON; i++){
    for(j=0; j<MAP_BES; j++){
      test->map[i][j]=WALL;
    }
  }

}

int dungeon_make_map(DUNGEON_MAP *test)
{
  //dungeon_free_map(test);
  test->current.x = 2;
  test->current.y = 7;

  return(0);
}


void dungeon_init_map(DUNGEON_MAP *test)
{
   
  int i,j;
  /*
  for(i=0; i<MAP_LON; i++){
    for(j=0; j<MAP_BES; j++){
      test->map[i][j]=WALL;
    }
  }
  */

  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      printf("%d, ",map_test[i][j]);
    }
    printf("\n");
  }

  test->direction = DUNGEON_DIRECTION_CONSTANT;
  test->current.x = 2;
  test->current.y = 7;
  test->aitemstep_cnt = 0;
  test->monsterstep_cnt = 0;
  test->aitemstep_op = 0;
  test->monsterstep_op = 0;
  test->boss = 0;
}


void search_table(DUNGEON_MAP *test)
{
  if(test->direction >= 1000 || test->direction <= 0)
    test->direction = 400;

  switch(test->direction % DUNGEON_DIRECTION_KEY){
  case NORTH:
    puts("NORTH");
    search_n(test);
    break;
  case EAST:
    puts("EAST");
    search_e(test);
    break;
  case SOUTH:
    puts("SOUTH");
    search_s(test);
    break;
  case WEST:
    puts("WEST");
    search_w(test);
    break;
  default:
    break;
  }
}

void search_n(DUNGEON_MAP *test)
{
  int i,j;
  int index = 0;

  for(i=0;i<3;i++){
    for(j=0;j<5;j++){
      if(map_test[(test->current.y-2)+i][(test->current.x-2)+j] == WALL){
	test->wall_pick[index] = WALL;
      }
      else if(map_test[(test->current.y-2)+i][(test->current.x-2)+j] == ROAD){
	test->wall_pick[index] = ROAD;
      }

      else if(map_test[(test->current.y-2)+i][(test->current.x-2)+j] == STEP_UP){
	test->wall_pick[index] = STEP_UP;
      }

      else if(map_test[(test->current.y-2)+i][(test->current.x-2)+j] == STEP_DOWN){
	test->wall_pick[index] = STEP_DOWN;
      }

      index++;
    }
  }

}

void search_e(DUNGEON_MAP *test){
  int i,j;
  int index = 0;

  for(j=0;j<3;j++){
    for(i=0;i<5;i++){
      if(map_test[(test->current.y-2)+i][(test->current.x+2)-j] == WALL){
	test->wall_pick[index] = WALL;
      }
      
      else if(map_test[(test->current.y-2)+i][(test->current.x+2)-j] == ROAD){
	test->wall_pick[index] = ROAD;
      }
      
      else if(map_test[(test->current.y-2)+i][(test->current.x+2)-j] == STEP_UP){
	test->wall_pick[index] = STEP_UP;
      }

      else if(map_test[(test->current.y-2)+i][(test->current.x+2)-j] == STEP_DOWN){
	test->wall_pick[index] = STEP_DOWN;
      }

      index++;
    }
  }

}

void search_s(DUNGEON_MAP *test){
  int i,j;
  int index = 0;
  
  for(i=0;i<3;i++){
    for(j=0;j<5;j++){
      if(map_test[(test->current.y+2)-i][(test->current.x+2)-j] == WALL){
	test->wall_pick[index] = WALL;
      }

      else if(map_test[(test->current.y+2)-i][(test->current.x+2)-j] == ROAD){
	test->wall_pick[index] = ROAD;
      }

      else if(map_test[(test->current.y+2)-i][(test->current.x+2)-j] == STEP_UP){
	test->wall_pick[index] = STEP_UP;
      }

      else if(map_test[(test->current.y+2)-i][(test->current.x+2)-j] == STEP_DOWN){
	test->wall_pick[index] = STEP_DOWN;
      }

      index++;
    }
  }
 
}

void search_w(DUNGEON_MAP *test){
  int i,j;
  int index = 0;

  for(j=0;j<3;j++){
    for(i=0;i<5;i++){
      if(map_test[(test->current.y+2)-i][(test->current.x-2)+j] == WALL){
	test->wall_pick[index] = WALL;
      }
      else if(map_test[(test->current.y+2)-i][(test->current.x-2)+j] == ROAD){
	test->wall_pick[index] = ROAD;
      }

      else if(map_test[(test->current.y+2)-i][(test->current.x-2)+j] == STEP_UP){
	test->wall_pick[index] = STEP_UP;
      }
    
      if(map_test[(test->current.y+2)-i][(test->current.x-2)+j] == STEP_DOWN){
	test->wall_pick[index] = STEP_DOWN;
      }

      index++;
    }
  }

}

void make_view(DUNGEON_MAP *test, PpmImage * image){
  display_flash(image);
  if(test->wall_pick[0] == WALL)display_wall1(image);
  if(test->wall_pick[1] == WALL)display_wall2(image);
  if(test->wall_pick[2] == WALL)display_wall3(image);
  if(test->wall_pick[3] == WALL)display_wall4(image);
  if(test->wall_pick[4] == WALL)display_wall5(image);
  
  if(test->wall_pick[5] == WALL)
    display_wall6(image);
  else if(test->wall_pick[5] == STEP_UP)
    display_stepup1(image);
  else if(test->wall_pick[5] == STEP_DOWN)
    display_stepdown1(image);

  if(test->wall_pick[9] == WALL)
    display_wall10(image);
  else if(test->wall_pick[9] == STEP_UP)
    display_stepup2(image);
  else if(test->wall_pick[9] == STEP_DOWN)
    display_stepdown2(image);

  if(test->wall_pick[6] == WALL)
    display_wall7(image);
  else if(test->wall_pick[6] == STEP_UP)
    display_stepup3(image);
  else if(test->wall_pick[6] == STEP_DOWN)
    display_stepdown3(image);
 
  if(test->wall_pick[8] == WALL)
    display_wall9(image);
  else if(test->wall_pick[8] == STEP_UP)
    display_stepup4(image);
  else if(test->wall_pick[8] == STEP_DOWN)
    display_stepdown4(image);

  if(test->wall_pick[7] == WALL)
    display_wall8(image);
  else if(test->wall_pick[7] == STEP_UP)
    display_stepup5(image);
  else if(test->wall_pick[7] == STEP_DOWN)
    display_stepdown5(image);

  if(test->wall_pick[10] == WALL)display_wall11(image);
  if(test->wall_pick[11] == WALL)display_wall12(image);

  if(test->wall_pick[12] == WALL)
    display_wall0(image);
  else if(test->wall_pick[12] == STEP_UP)
    display_stepup6(image);
  else if(test->wall_pick[12] == STEP_DOWN)
    display_stepdown6(image);
 
  if(test->wall_pick[13] == WALL)display_wall13(image);
  if(test->wall_pick[14] == WALL)display_wall14(image);
}
