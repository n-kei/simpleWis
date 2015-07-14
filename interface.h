#ifndef _INTERFACE_H_INCLUDED
#define _INTERFACE_H_INCLUDED

#define INTERFACE_NUM       9   //インターフェースの個数

//////////////挌状態管理変数型の変数の個数///////////////////////
#define INTERFACE_STATE_NUM 9
#define TITLE_STATE_NUM     3
#define CASTLE_STATE_NUM    3
#define INN_STATE_NUM       2
#define STORE_STATE_NUM     4
#define WASTELAND_STATE_NUM 5
#define BATTLE_STATE_NUM    3
///////////////////////////////////////////////////////////////


/////////////インターフェースの状態管理変数///////////////////
 
enum StateOfInterface {
  TITLE = 0,
  CASTLE,
  INN,
  STORE,
  WASTELAND,
  DUNGEON,
  BATTLE,
  INVENTORY,
  STATUS
};

extern enum StateOfInterface cur_interface_state;
///////////////////////////////////////////////////////////


///////////////タイトルの状態管理変数//////////////////////////
enum StateOfTitle {
  START = 0,
  LOAD,
  END
};

extern enum StateOfInterface cur_title_state;
/////////////////////////////////////////////////////////////


///////////////////城の状態管理変数///////////////////////////
enum StateOfCastle {
  INN = 2,
  STORE,
  WASTELAND
};

extern enum StateOfCastle cur_castle_state;
////////////////////////////////////////////////////////////


////////////////////宿の状態管理変数/////////////////////////////
enum StateOfInn {
  STAY = 0,
  CASTLE,
};

extern enum StateOfInn cur_inn_state;
///////////////////////////////////////////////////////////////


//////////////////////店の状態管理変数/////////////////////////
enum StateOfStore {
  BUY = 0,
  SELL,
  INVENTORY = 7,
  CASTLE = 1,
};

extern enum StateOfStore cur_store_state;
//////////////////////////////////////////////////////////////


///////////////////////荒地の状態管理変数////////////////////////////
enum StateOfWasteland {
  DUNGEON = 0,
  CASTLE,
  STATUS = 8,
  SAVE,
  END,
};

extern enum StateOfWasteland cur_wasteland_state;
////////////////////////////////////////////////////////////////////


///////////////////////戦いの状態管理変数////////////////////////////
enum StateOfBattle {
  ATTACK = 0,
  INVENTORY = 7,
  RUNAWAY,
};

extern enum StateOfBattle cur_battle_state;
////////////////////////////////////////////////////////////////////

////////////////////////はいかいいえ///////////////////////////////
enum StateOfYesOrNo {
  YES = 0,
  No
};
///////////////////////////////////////////////////////////////////

extern void (*interfaceFunc_talble)(void)[INTERFACE_NUM];  //それぞれのインターフェース関数管理用関数ポインタ配列

void interface_init(void);
void interface_title(void);
void interface_castle(void);
void interface_inn(void);
void interface_store(void);
void interface_wasteland(void);
void interface_dungeon(void);
void interface_battle(void);
void interface_inventory(void);
void interface_status(void);

#endif
