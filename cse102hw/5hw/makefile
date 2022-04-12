all : clear clean compile run


clear : 	
	@clear

clean :

	@rm -rf main.o
	@rm -rf main.out

compile:
	@gcc -c main.c
	@gcc main.c -o main.out -lm

run:
	@./main.out

