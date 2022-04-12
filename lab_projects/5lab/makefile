all : clear clean compile run

clear:
	@clear


clean: 
	@rm -rf main.o
	@rm -rf main.out

compile:
	@gcc -c main.c
	@gcc -o main.out main.c -lm

run: 
	@./main.out