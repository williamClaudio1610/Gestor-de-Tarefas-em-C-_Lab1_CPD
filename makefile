build: 
	gcc -o tarefa.o tarefa.c -c -g
	gcc -o main.o main.c -c -g
	gcc -o main *.o

run:
	./main

clean: 
	rm *.o
	rm main
