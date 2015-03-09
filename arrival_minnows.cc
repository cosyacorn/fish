#include "fish_classes.h"
#include<cstdlib>
#include<iostream>

void append_fish(fish *h, int species, int x, int y, int z);

void arrival_minnows(fish *head, int x, int y, int z){

  fish *temp;
  int num_minnows;

  temp=head;
  temp->type=head->type;
  temp->xcoord=head->xcoord;
  temp->ycoord=head->ycoord;
  temp->zcoord=head->zcoord;

  num_minnows=0;

  while(temp!=NULL){
    if(temp->type==0){
      std::cout << head->type << std::endl;
      if(temp->xcoord==x && temp->ycoord==y && temp->zcoord==z)
	num_minnows++;
      if(num_minnows>=2){
	append_fish(head, 0, x, y, z);
	append_fish(head, 0, x, y, z);
	break;
      }
    }
    temp=temp->next;
  }
}


void arrival_tuna(fish *head, int x, int y, int z){

  fish *temp;
  int num_fed_tuna;

  temp=head;
  temp->type=head->type;
  temp->xcoord=head->xcoord;
  temp->ycoord=head->ycoord;
  temp->zcoord=head->zcoord;

  num_fed_tuna=0;

   while(temp!=NULL){
     if(temp->type==1){
       if(temp->eaten==1){
	 if(temp->xcoord==x && temp->ycoord==y && temp->zcoord==z)
	   num_fed_tuna++;
	 if(num_fed_tuna>=2){
	   append_fish(head, 1, x, y, z);
	   break;
	 }
       }
     }
     temp=temp->next;
   }
}
