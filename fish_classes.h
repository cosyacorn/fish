class fish{
 public:
  //type specifies the fish: 0=minnow, 1=tuna, 2=shark
  int type;
  
  int xcoord;
  int ycoord;
  int zcoord;

  int age;
  int eaten;

  //set up linked list
  fish *next;
  fish *prev;
};
