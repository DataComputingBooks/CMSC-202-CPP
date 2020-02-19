CXX = g++
CXXFLAGS = -Wall

proj4: Game.o Room.o Entity.o Character.o Paladin.o Rogue.o Wizard.o Monster.o BabyDragon.o Goblin.o Skeleton.o proj4.cpp
	$(CXX) $(CXXFLAGS) Game.o Room.o Entity.o Character.o Paladin.o Rogue.o Wizard.o Monster.o BabyDragon.o Goblin.o Skeleton.o proj4.cpp -o proj4

Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Room.o: Room.h Room.cpp
	$(CXX) $(CXXFLAGS) -c Room.cpp

Entity.o: Entity.h Entity.cpp
	$(CXX) $(CXXFLAGS) -c Entity.cpp

Character.o: Character.h Character.cpp
	$(CXX) $(CXXFLAGS) -c Character.cpp

Paladin.o: Paladin.h Paladin.cpp
	$(CXX) $(CXXFLAGS) -c Paladin.cpp

Rogue.o: Rogue.h Rogue.cpp
	$(CXX) $(CXXFLAGS) -c Rogue.cpp

Wizard.o: Wizard.h Wizard.cpp
	$(CXX) $(CXXFLAGS) -c Wizard.cpp

Monster.o: Monster.h Monster.cpp
	$(CXX) $(CXXFLAGS) -c Monster.cpp

BabyDragon.o: BabyDragon.h BabyDragon.cpp
	$(CXX) $(CXXFLAGS) -c BabyDragon.cpp

Goblin.o: Goblin.h Goblin.cpp
	$(CXX) $(CXXFLAGS) -c Goblin.cpp

Skeleton.o: Skeleton.h Skeleton.cpp
	$(CXX) $(CXXFLAGS) -c Skeleton.cpp

run1:
	./proj4 map1_data.txt

run2:
	./proj4 map2_data.txt

val1:
	valgrind ./proj4 map1_data.txt

val2:
	valgrind ./proj4 map2_data.txt

clean:
	rm *.o*
	rm *~
