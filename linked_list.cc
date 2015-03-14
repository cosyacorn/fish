#include "fish_classes.h"
#include<cstdlib>
#include<iostream>


void init_fish(fish *head, int species, int x, int y, int z){

  head->type=species;

  head->xcoord=x;
  head->ycoord=y;
  head->zcoord=z;

  head->age=0;
  head->eaten=0;

  head->next=NULL;
  //head->prev=NULL;
}

fish* new_fish(int species, int x, int y, int z){

  fish *f=new fish;

  f->next=NULL;
  //f->prev=NULL;

  f->type=species;

  f->xcoord=x;
  f->ycoord=y;
  f->zcoord=z;

  f->age=0;
  f->eaten=0;

  return f;
  
}

void append_fish(fish *h, int species, int x, int y, int z){
  while(h->next != NULL){
    if(species==0 && (h->next)->type==1)
      break;
    if(species==1 && (h->next)->type==2)
      break;
    h=h->next;
  }
  fish *f = new_fish(species, x, y, z);
  f->next=h->next;
  h->next=f;
  //f->prev=h;
}


void print_fish(fish *head){

  while(head!=NULL){
    std::cout << "type " << head->type << " x: " << head->xcoord << " y: " << head->ycoord << " z: " << head->zcoord <<  std::endl; 

    head=head->next;
  }
}

int * count_fish(fish * head){

  int min, tuna, shark, num[3];

  min=tuna=shark=0;

  while(head!=NULL){
    if(head->type==0)
      min++;
    if(head->type==1)
      tuna++;
    if(head->type==2)
      shark++;
    head=head->next;
  }
  num[0]=min;
  num[1]=tuna;
  num[2]=shark;

  return num;
}
