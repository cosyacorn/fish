#include "fish_classes.h"
#include<cstdlib>
#include<iostream>

void append_fish(fish *h, int species, int x, int y, int z);

//Function for creating 3 minnows if 2 are already at the arrival site
void arrival_minnows(fish *head, int x, int y, int z){
 
  int num_minnows;
 
  num_minnows=0;

  //go through the list
  while(head!=NULL){
    //if minnow at x y z is found then increase num_minnows
    if(head->type==0){
      if(head->xcoord==x && head->ycoord==y && head->zcoord==z)
	num_minnows++;
      //if two minnows are found at site then append three minnows
      if(num_minnows>=2){
	append_fish(head, 0, x, y, z);
	append_fish(head, 0, x, y, z);
	append_fish(head, 0, x, y, z);
	break;
      }
    }
    head=head->next;
  }
}


///////////////////////////////////
///////////////////////////////////
///////////////////////////////////



//Function to add tuna if two fed tuna are at arrival site
void arrival_tuna(fish *head, int x, int y, int z){

  int num_fed_tuna;

  num_fed_tuna=0;
 
  //traverse linked list
  while(head!=NULL){
    //if tuna who has eaten in found and (x,y,z) then increment num_fed_tuna
    if(head->type==1){
      if(head->eaten!=0){
	if(head->xcoord==x && head->ycoord==y && head->zcoord==z)
	  num_fed_tuna++;
	//if we find 2 fed tuna add a tuna and break the while loop
	if(num_fed_tuna>=2){
	  append_fish(head, 1, x, y, z);
	  break;
	}
      }
    }
    head=head->next;
  }
}

/////////////////////////////////////
/////////////////////////////////////
/////////////////////////////////////


//Function to add a shark if two fed sharks are at the arrival site
//This is exxentially the same as the tuna funciton above but with sharks
void arrival_shark(fish *head, int x, int y, int z){

  int num_fed_shark;

  num_fed_shark=0;

   while(head!=NULL){
     if(head->type==2){
       if(head->eaten!=0){
	 if(head->xcoord==x && head->ycoord==y && head->zcoord==z)
	   num_fed_shark++;
	 if(num_fed_shark>=2){
	   append_fish(head, 2, x, y, z);
	   break;
	 }
       }
     }
     head=head->next;
   }
}


////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////


//Function to delete all minnows at arrival site if there are tuna and minnows at site
void arrival_tuna_minnows(fish **head, int x, int y, int z){

  fish *cur, *prev, *temp;
  int del_flag;

  cur=*head;
  del_flag=0;

  //if the list is empty
  if(cur==NULL) return;

  //set prev to be the first fish and cur to be the second
  prev=cur;
  cur=cur->next;
  
  //traverse list until last entry
  while(cur!=NULL && cur->next!=NULL){
    //set del_flag to be zero each time
    del_flag=0;
    //check for minnow at (x,y,z)
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==0){
	//delete that minnow (and keep track of pointers
	temp=cur->next;
	prev->next=cur->next;
	delete cur;
	cur=temp;
	//set del_flag=1
	del_flag=1;
      }
      //increment the eaten val for the tuna to show they were fed
      if(cur->type==1){
	cur->eaten++;
      }
    }
    //only advance to the next member of the list if the del_flag is zero
    //the reason for this check is that if we do advance in the list then we won't have checked our current cur
    //when we set cur=temp above we never check the type of temp and with out this if statement we'd have advanced wihout checking it
    if(del_flag==0){
      cur=cur->next;
      prev=prev->next;
      }
  }

  //check the last fish
  if(cur!=NULL){
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type == 0 ){
	prev->next = NULL;
	delete cur;
      }
      if(cur->type==1){
	cur->eaten++;
      }
    }
  }
  //check the first fish
  if ((*head)->type == 0){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      temp = (*head)->next;
      delete *head;
      *head = temp;
    }
  }
  if ((*head)->type == 1){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      (*head)->eaten++;
    }
  }
}



//This function deletes 1 tuna if there are tuna and sharks at the arrival site
//It is essentially the same as the function above but this time only one fish is deleted
void arrival_tuna_shark(fish **head, int x, int y, int z){

  fish *cur, *prev, *temp;
  int del_flag;

  cur=*head;
  del_flag=0;

  if(cur==NULL) return;

  prev=cur;
  cur=cur->next;
  
  while(cur!=NULL && cur->next!=NULL){
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==1 && del_flag==0){
	temp=cur->next;
	prev->next=cur->next;
	delete cur;
	cur=temp;
	del_flag=1;
      }
      if(cur->type==2){
	cur->eaten++;
      }
    }
    cur=cur->next;
    prev=prev->next;  
  }

  if(cur!=NULL){
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(del_flag==0){
	if(cur->type == 1){
	  prev->next = NULL;
	  delete cur;
	  del_flag=1;
	}
      }
      if(cur->type==2){
	cur->eaten++;
      }
    }
  }
  if ((*head)->type == 1){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      if(del_flag==0){
	temp = (*head)->next;
	delete *head;
	*head = temp;
	del_flag=1;
      }
    }
  }
  if ((*head)->type == 2){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      (*head)->eaten++;
    }
  }
}


//Function for sharks to eat all minnows at arrival site and nn sites
void feeding_frenzy(fish **head, int x, int y, int z){

  fish *cur, *prev, *temp;
  int del_flag;

  cur=*head;
  del_flag=0;

  if(cur==NULL) return;

  prev=cur;
  cur=cur->next;
  
  //traverse list of fish
  while(cur!=NULL && cur->next!=NULL){
    del_flag=0;
    //check x, x+1 and x-1 (same for y and z) for minnows
    if(cur->xcoord==x || cur->xcoord==(x+1)%5 || cur->xcoord==(x-1+5)%5){
      if(cur->ycoord==y || cur->ycoord==(y+1)%5 || cur->ycoord==(y-1+5)%5){
	if(cur->zcoord==z || cur->zcoord==(z+1)%5 || cur->zcoord==(z-1+5)%5){
	  if(cur->type==0){
	    //delete minnows found
	    temp=cur->next;
	    prev->next=cur->next;
	    delete cur;
	    del_flag=1;
	    cur=temp;
	  }
	}
      }
    }
    //feed the sharkies at the arrival site
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==2){
	cur->eaten++;
      }
    }
    //same argument as earlier
    //this time advance if it's not a minnow (won't have been deleted) or if the flag is zero
    if(cur->type!=0 || del_flag==0){
      cur=cur->next;
      prev=prev->next;
    }
  }

  //check end of the list
  if(cur!=NULL){
    if(cur->xcoord==x || cur->xcoord==(x+1)%5 || cur->xcoord==(x-1+5)%5){
      if(cur->ycoord==y || cur->ycoord==(y+1)%5 || cur->ycoord==(y-1+5)%5){
	if(cur->zcoord==z || cur->zcoord==(z+1)%5 || cur->zcoord==(z-1+5)%5){
	  if(cur->type == 0){
	    prev->next = NULL;
	    delete cur;
	  }
	}
      }
    }
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==2){
	cur->eaten++;
      }
    }
  }
  //check head of list
  if ((*head)->type == 0){
    if((*head)->xcoord==x || (*head)->xcoord==(x+1)%5 || (*head)->xcoord==(x-1+5)%5){
      if((*head)->ycoord==y || (*head)->ycoord==(y+1)%5 || (*head)->ycoord==(y-1+5)%5){
	if((*head)->zcoord==z || (*head)->zcoord==(z+1)%5 || (*head)->zcoord==(z-1+5)%5){
	  temp = (*head)->next;
	  delete *head;
	  *head = temp;
	}
      }
    }
  }
  if ((*head)->type == 2){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      (*head)->eaten++;
    }
  }
}



//Function to delete tuna and sharks if they don't eat after moving five times
void not_eaten_five_moves(fish **head){

  fish *cur, *prev, *temp;
  int del_flag;
  
  cur=*head;

  //return if list is empty
  if(cur==NULL) return;

  prev=cur;
  cur=cur->next;

  //traverse list
  while(cur!=NULL && cur->next!=NULL){
    del_flag=0;
    //find tuna+sharks that are 5+ moves old and haven't eaten
    if(cur->age>=5 && cur->eaten==0){
      if(cur->type==1 ||cur->type==2){
	temp=cur->next;
	prev->next=cur->next;
	delete cur;
	cur=temp;
	del_flag=1;
      }
    }
    //apply criteria from before about advancing through list
    if(del_flag==0)
      cur=cur->next;
  }
  
  //check last node
  if(cur!=NULL){
    if(cur->age>=5 && cur->eaten==0){
      if(cur->type == 1 || cur->type==2){
	prev->next = NULL;
	delete cur;	 
      }
    }
  }
  if((*head)->age>=5 && (*head)->eaten==0){
    if((*head)->type==1 || (*head)->type==2){
      temp = (*head)->next;
      delete *head;
      *head = temp;
    }
  }
}




//func to choose which of the above functions to call if a number of them may be applied
void choose_arrival_func(fish **head, int x, int y, int z){

  //x,y,z are the arrival site coords

  int minnows, fed_tuna, fed_sharks, tuna, shark, tuna_minnows, tuna_shark, frenzy;
  int opt[6], tot, i;
  double prob[6], r;
  fish *cur;

  //first get rid of fish that are 5 and haven't eaten
  not_eaten_five_moves(head);//check if a tuna or shark has eaten and its age

  cur=*head;

  //set all criteria counters to zero
  minnows=fed_tuna=fed_sharks=tuna=shark=tuna_minnows=tuna_shark=frenzy=0;
  
  //set the array of possible opitions to zero
  for(i=0;i<6;i++)
    opt[i]=0;
  //set the tot to zero
  tot=0;

  //traverse loop
  while(cur!=NULL){
    //check if the coords match those of the arrival site
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==0)
	minnows++;//count minnows
      if(cur->type==1){
	tuna++;//count tuna
	  if(cur->eaten!=0){
	    fed_tuna++;//count fed tuna
	  }
      }
      if(cur->type==2){
	shark++;//count sharks
	if(cur->eaten!=0){
	  fed_sharks++;//count fed sharks
	}
      }
      if(tuna>=1 && shark>=1)
	tuna_shark++;//count if at least one tuna and at least one shark are present at site
    }
    cur=cur->next;
  }
  if(tuna==1 && minnows>=1)
    tuna_minnows++;//check if one tuna and any no of minnows are present
  if(shark==1 && minnows!=0)
    frenzy++;//check if one shark and any no of minnows are presen

  if(minnows>=2)//can apply arrival minnows
    opt[0]=1;
  if(fed_tuna>=2)//can apply fed
    opt[1]=1;
  if(fed_sharks>=2)
    opt[2]=1;
  if(tuna_minnows!=0)
    opt[3]=1;
  if(tuna_shark!=0)
    opt[4]=1;
  if(frenzy>=1)
    opt[5]=1;


  for(i=0;i<6;i++)
    tot+=opt[i];


  prob[0]=((double)opt[0])/((double)tot);

  for(i=1;i<6;i++)
    prob[i]=prob[i-1]+((double)opt[i])/((double)tot);


  r=drand48();
  
  if(r<prob[0]){
    std::cout<<"minnows"<<std::endl;
    arrival_minnows(*head, x, y, y);
  }

  else if(r>=prob[0] && r<prob[1]){
    std::cout<<"tuna"<<std::endl;
    arrival_tuna(*head, x, y, z);
  }
  else if(r>=prob[1] && r<prob[2]){
    std::cout<<"shark"<<std::endl;
    arrival_shark(*head, x, y, z);
  }
  else if(r>=prob[2] && r<prob[3]){
    std::cout<<"minnows and tuna"<<std::endl;
    arrival_tuna_minnows(head, x, y, z);
  }
  else if(r>=prob[3] && r<prob[4]){
    std::cout<<"tuna and shark"<<std::endl;
    arrival_tuna_shark(head, x, y, z);
  }
  else if(r>=prob[4] && r<prob[5]){
     std::cout<<"nom nom nom"<<std::endl;
    feeding_frenzy(head, x, y, z);
  }
}

