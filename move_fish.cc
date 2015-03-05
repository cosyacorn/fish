#include "fish_classes.h"
#include<stdlib.h>
#include<math.h>

void move_minnow(minnow &m){
  int axis;
  int direction;

  axis=rand()%3;
  direction=rand()%2;

  if(axis==0){
    if(direction==1){
      m.xcoord=(m.xcoord+1)%5;
    }
    else{
       m.xcoord=(m.xcoord-1+5)%5;
    }
  }
  else if(axis==1){
    if(direction==1){
      m.ycoord=(m.ycoord+1)%5;
    }
    else{
      m.ycoord=(m.ycoord-1+5)%5;
    }
  }
  else if(axis==2){
    if(direction==1){
      m.zcoord=(m.zcoord+1)%5; 
    }
    else{
      m.zcoord=(m.zcoord-1+5)%5;
    }
  }
}

void move_tuna(tuna &t){
  int plane, x, y;

  plane=rand()%3;
  x=rand()%2;
  y=rand()%2;

  //movement in xy plane
  if(plane==0){
    t.xcoord=(t.xcoord+pow(-1,x))%5;
    t.ycoord=(t.ycoord+pow(-1,y))%5;
  }
  //movement in xz plane
  else if(plane==1){
    t.xcoord=(t.xcoord+pow(-1,x))%5;
    t.zcoord=(t.zcoord+pow(-1,y))%5;
  }
  //movement in yz plane
  else{
    t.ycoord=(t.ycoord+pow(-1,x))%5;
    t.zcoord+=pow(-1,y);
  }
}

void move_shark(shark &s){
  int first_dir, second_dir;

  first_dir=rand()%3;
  second_dir=rand()%2;

  //first move in x dir
  if(first_dir==0){
    s.xcoord
  }
  //first move in y dir
  else if(first_dir==1){

  }
  //first move in z dir
  else{

  }
}
