default: ./sources/main.cpp ./sources/lista.cpp ./sources/memoria.cpp ./sources/processo.cpp ./sources/view.cpp
	g++ -o ./bin/Memorias.exe ./sources/main.cpp ./sources/lista.cpp ./sources/memoria.cpp ./sources/processo.cpp ./sources/view.cpp -std=c++11
run:
	./bin/Memorias.exe
clean:
	rm -rf ./bin/Memorias.exe