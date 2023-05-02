all:
	g++ -std=c++11 -Wall -O0 -g *.cpp -o main -I src/include/SDL2 -L src/lib -lSDl2 -lSDl2_image -lSDl2_mixer -lSDl2_ttf -lSDL2main
run: 
	./main