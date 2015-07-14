#ifndef _DUNGEON_INCLUDED_
#define _DUNGEON_INCLUDED_  
#include "ppmimage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XMAX  80
#define YMAX  24
#define MAXSITE (XMAX * YMAX / 4)

#define DUNGEON_CANT_MOVE        -1
#define DUNGEON_CAN_MOVE         0
#define DUNGEON_DIRECTION_CONSTANT   400
#define DUNGEON_DIRECTION_KEY        4

#define WALL          0
#define ROAD          1
#define STEP_UP       2
#define STEP_DOWN     3
#define DOOR          4
     
#define NORTH          0
#define EAST           1
#define SOUTH          2
#define WEST           3

#define MAP_LON       10
#define MAP_BES       10

#define WALL_PICK_SIZE  15
#define SCREEN_LON    360
#define SCREEN_BES    500


extern char map[XMAX + 1][YMAX + 1];
extern int nsite;
extern int xx[MAXSITE], yy[MAXSITE];
extern int dx[4];
extern int dy[4];
extern int dirtable[24][4];

typedef struct {
  char map[XMAX + 1][YMAX + 1];
  int wall_pick[WALL_PICK_SIZE];
  int direction;

  struct{
    int x;
    int y;
  } current;

  unsigned int aitemstep_cnt;
  unsigned int monsterstep_cnt;
  unsigned int aitemstep_op;
  unsigned int monsterstep_op;
  int boss;
} DUNGEON_MAP;


void add_site(int , int );
int select_site(int *, int *);
int GetRandom(int , int );
int dungeon_move(DUNGEON_MAP *);
int dungeon_free_map(DUNGEON_MAP *);
int dungeon_make_map(DUNGEON_MAP *);
void dungeon_init_map(DUNGEON_MAP *);
void serach_table(DUNGEON_MAP *);
void serach_n(DUNGEON_MAP *);
void serach_e(DUNGEON_MAP *);
void serach_s(DUNGEON_MAP *);
void serach_w(DUNGEON_MAP *);
void make_view(DUNGEON_MAP *, PpmImage *);

# endif
