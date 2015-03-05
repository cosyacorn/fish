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
    t.xcoord=(5+t.xcoord+(int)pow(-1,x))%5;
    t.ycoord=(5+t.ycoord+(int)pow(-1,y))%5;
  }
  //movement in xz plane
  else if(plane==1){
    t.xcoord=(5+t.xcoord+(int)pow(-1,x))%5;
    t.zcoord=(5+t.zcoord+(int)pow(-1,y))%5;
  }
  //movement in yz plane
  else{
    t.ycoord=(5+t.ycoord+(int)pow(-1,x))%5;
    t.zcoord=(5+t.zcoord+(int)pow(-1,y))%5;
  }
}

void move_shark(shark &s){
  int first_dir, second_dir, dist, dist2, x, y;

  //use these to pick axes to move on
  first_dir=rand()%3;
  second_dir=rand()%2;

  //how far to go on first part of movemnet (1 or 2 places)
  dist=1+(rand()%2);
  
  //if fist move is 1 then second is 2 places and vice versa
  if(dist==1){
    dist2=2;
  }
  else{
    dist2=1;
  }

  //use this to determine the direction along axis (+ or -)
  x=rand()%2;
  y=rand()%2;

  x=pow(-1,x);
  y=pow(-1,y);


  //first move in x dir
  if(first_dir==0){
    s.xcoord=(5+s.xcoord+x*dist)%5;
    //then in y or z
    if(second_dir==0){
      s.ycoord=(5+s.ycoord+y*dist2)%5;
    }
    else{
      s.zcoord=(5+s.zcoord+y*dist2)%5;
    }
  }
  //first move in y dir
  else if(first_dir==1){
    s.ycoord=(5+s.ycoord+x*dist)%5;
    //then in x or z
    if(second_dir==0){
      s.xcoord=(5+s.xcoord+y*dist2)%5;
    }
    else{
      s.zcoord=(5+s.zcoord+y*dist2)%5;
    }
  }
  //first move in z dir
  else{
    s.zcoord=(5+s.zcoord+x*dist)%5;
    //then in y or x
    if(second_dir==0){
      s.ycoord=(5+s.ycoord+y*dist2)%5;
    }
    else{
      s.xcoord=(5+s.xcoord+y*dist2)%5;
    }
  }
}
