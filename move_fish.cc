#include "fish_classes.h"
#include<stdlib.h>
#include<math.h>

void move_fish(fish *f){

  //////////////
  ////MINNOW////
  //////////////

  if(f->type==0){

    int axis;
    int direction;
    
    //randomly choose the x, y or z axis to move on
    axis=rand()%3;
    //randomly choose +ve or -ve direction
    direction=rand()%2;

    //update the coordinates accordingly
    if(axis==0){
      if(direction==1){
	f->xcoord=(f->xcoord+1)%5;
      }
      else{
	f->xcoord=(f->xcoord-1+5)%5;//need +5 for modular arithmetic
      }
    }
    else if(axis==1){
      if(direction==1){
	f->ycoord=(f->ycoord+1)%5;
      }
      else{
      f->ycoord=(f->ycoord-1+5)%5;
      }
    }
    else if(axis==2){
      if(direction==1){
	f->zcoord=(f->zcoord+1)%5; 
      }
      else{
	f->zcoord=(f->zcoord-1+5)%5;
      }
    }
  }

  ////////////////
  //////TUNA//////
  ////////////////

  if(f->type==1){
    int plane, x, y;
    
    //randomly choose xy, xz or yz plane
    plane=rand()%3;
    //need two random nos to determine direction
    x=rand()%2;
    y=rand()%2;
    
    //tuna die if move 5 times without eating. this is checked elsewhere in code
    //this just resets it eaten/age status if it is still alive after moving 5times
    if(f->age>=5){
      f->age=0;
      f->eaten=0;
    }

    //movement in xy plane
    if(plane==0){
      f->xcoord=(5+f->xcoord+(int)pow(-1,x))%5;
      f->ycoord=(5+f->ycoord+(int)pow(-1,y))%5;
    }
    //movement in xz plane
    else if(plane==1){
      f->xcoord=(5+f->xcoord+(int)pow(-1,x))%5;
      f->zcoord=(5+f->zcoord+(int)pow(-1,y))%5;
    }
    //movement in yz plane
    else{
    f->ycoord=(5+f->ycoord+(int)pow(-1,x))%5;
    f->zcoord=(5+f->zcoord+(int)pow(-1,y))%5;
    }
    f->age++;
  }

  /////////////
  ////SHARK////
  /////////////

  if(f->type==2){
    int first_dir, second_dir, dist, dist2, x, y;
    
    //use these to pick axes to move on
    first_dir=rand()%3;
    second_dir=rand()%2;

    //how far to go on first part of movemnet (1 or 2 places)
    dist=1+(rand()%2);
  

    //same criteria as for tuna
    if(f->age>=5){
      f->age=0;
      f->eaten=0;
    }

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
      f->xcoord=(5+f->xcoord+x*dist)%5;
      //then in y or z
      if(second_dir==0){
	f->ycoord=(5+f->ycoord+y*dist2)%5;
      }
      else{
	f->zcoord=(5+f->zcoord+y*dist2)%5;
      }
    }
    //first move in y dir
    else if(first_dir==1){
      f->ycoord=(5+f->ycoord+x*dist)%5;
      //then in x or z
      if(second_dir==0){
	f->xcoord=(5+f->xcoord+y*dist2)%5;
      }
      else{
	f->zcoord=(5+f->zcoord+y*dist2)%5;
      }
    }
    //first move in z dir
    else{
      f->zcoord=(5+f->zcoord+x*dist)%5;
      //then in y or x
      if(second_dir==0){
	f->ycoord=(5+f->ycoord+y*dist2)%5;
      }
      else{
	f->xcoord=(5+f->xcoord+y*dist2)%5;
      }
    }
    f->age++;
  }
}
