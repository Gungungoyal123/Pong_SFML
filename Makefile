default: 
	g++ src/*.cpp -I include -o pong -lsfml-graphics -lsfml-window -lsfml-system

run:
	g++ src/*.cpp -I include -o pong -lsfml-graphics -lsfml-window -lsfml-system && ./pong