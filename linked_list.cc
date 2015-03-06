#include "fish_classes.h"
#include<stdlib.h>

void init_minnow(minnow *head, int x, int y, int z){

  head->xcoord=x;
  head->ycoord=y;
  head->zcoord=z;

  head->next=NULL;
  head->prev=NULL;
}

void new_minnow(minnow *head, int x, int y, int z){

  minnow *m=new minnow;

  m->next=NULL;
  m->prev=head;

  m->xcoord=x;
  m->ycoord=y;
  m->zcoord=z;

  
}
