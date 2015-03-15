CPP=g++

fish: main.cc linked_list.cc arrival_funcs.cc update.cc move_fish.cc
	$(CPP) -o fish main.cc linked_list.cc arrival_funcs.cc update.cc move_fish.cc

clean:
	$(RM) fish
