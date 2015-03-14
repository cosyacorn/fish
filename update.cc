#include<cstdlib>
#include "fish_classes.h"
#include "move_fish.h"
#include<cmath>

void choose_arrival_func(fish **head, int x, int y, int z);

void update(fish **head, int num_minnows, int num_tuna, int num_sharks){

  int species, min_flag, tuna_flag, shark_flag;
  fish *cur;
  double r;

  
  min_flag=tuna_flag=shark_flag=0;

  if(num_minnows==0)
    min_flag=1;
  
  if(num_tuna==0)
    tuna_flag=1;

  if(num_sharks==0)
    shark_flag==1;


  if(min_flag==0 && tuna_flag==0 && shark_flag==0)
    species=rand()%3;
  else if(min_flag==1 && tuna_flag==0 && shark_flag==0)
    species=1+rand()%2;
  else if(min_flag==0 && tuna_flag==1 && shark_flag==0)
    species=1+pow(-1,rand()%2);
  else if(min_flag==0 && tuna_flag==0 && shark_flag==1)
     species=rand()%2;
  else if(min_flag==1 && tuna_flag==1 && shark_flag==0)
    species=2;
  else if(min_flag==1 && tuna_flag==0 && shark_flag==1)
     species=1;
 else if(min_flag==0 && tuna_flag==1 && shark_flag==1)
     species=0;
 else if(min_flag==1 && tuna_flag==1 && shark_flag==1)
   return;



  cur=*head;

  while(cur!=NULL && cur->next!=NULL){
    if(cur->type==species){
      break;
    }
    cur=cur->next;
  }
  r=drand48();

  if(r<0.9){
    move_fish(cur);
    choose_arrival_func(head, cur->xcoord, cur->ycoord, cur->zcoord);
  }
}
