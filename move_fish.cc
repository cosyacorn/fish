#include "fish_classes.h"
#include<stdlib.h>

void move_minnow(minnow& m){
  int axis;
  int direction;

  axis=rand()%3;
  direction=rand()%2;

  if(axis==1){
    if(direction==1){
      m.xcoord=(m.xcoord+1)%5;
    }
    else{
       m.xcoord=(m.xcoord-1+5)%5;
    }
  }
  else if(axis==2){
    if(direction==1){
      m.ycoord=(m.ycoord+1)%5;
    }
    else{
        m.ycoord=(m.ycoord-1+5)%5;
    }
  }
  else{
    if(direction==1){
       m.zcoord=(m.zcoord+1)%5; 
    }
    else{
      m.zcoord=(m.zcoord-1+5)%5;
    }
  }
}

void move_tuna(tuna t){

}

void move_shark(shark s){

}
