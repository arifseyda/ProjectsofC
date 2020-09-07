all: derle	calistir

derle:
	g++ -I ./include/ -o ./lib/CiftYonluBagilListe.o -c ./src/CiftYonluBagilListe.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Yonetim.o -c ./src/Yonetim.cpp

	g++ -I ./include/ -o ./bin/Test ./lib/CiftYonluBagilListe.o ./lib/Dugum.o ./lib/Stack.o ./lib/Yonetim.o ./src/Test.cpp
calistir:
	./bin/Test