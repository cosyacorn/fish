#include<cstdlib>
#include "fish_classes.h"
#include<cmath>

void choose_arrival_func(fish **head, int x, int y, int z);
void move_fish(fish *f);


void update(fish **head, int num_minnows, int num_tuna, int num_sharks){

  int species, min_flag, tuna_flag, shark_flag, i;
  fish *cur;
  double r;

  //set zero population falgs for each species to zero
  min_flag=tuna_flag=shark_flag=0;


  //set flags to 1 if necessary
  if(num_minnows==0)
    min_flag=1;
  
  if(num_tuna==0)
    tuna_flag=1;

  if(num_sharks==0)
    shark_flag==1;



  //choose a species at random (taking into account possible extinct species
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

  int num_fish;

  //choose a minnow/tuna/shark at random.
  if(species==0)
    num_fish=rand()%(num_minnows);

  else if(species==1)
    num_fish=rand()%(num_tuna);

  else if(species==2)
    num_fish=rand()%(num_sharks);

  while(cur!=NULL && cur->next!=NULL){
    if(cur->type==species){
      //increment up to our random fish as chosen above
      for(i=0;i<num_fish;i++){
	cur=cur->next;
	break;
      }
    }
    cur=cur->next;
  }
  //move fish with prob=0.9
  r=drand48();

  if(r<0.9){
    move_fish(cur);
    choose_arrival_func(head, cur->xcoord, cur->ycoord, cur->zcoord);
  }
}
