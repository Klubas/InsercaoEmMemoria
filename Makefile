default: ./sources/main.cpp ./sources/lista.cpp ./sources/memoria.cpp ./sources/processo.cpp ./sources/view.cpp
	g++ -o ./bin/main.exe ./sources/main.cpp ./sources/lista.cpp ./sources/memoria.cpp ./sources/processo.cpp ./sources/view.cpp -O3
run:
	./bin/main.exe
clean:
	rm ./bin/main.exe