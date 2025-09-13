all: clear compile run clean


clear:
	@clear

compile:
	@gcc main.c -o main.out -lm
	@gcc -c main.c 

run:
	@./main.out

clean:
	@rm -rf main.out
	@rm -rf main.o