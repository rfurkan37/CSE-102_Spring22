all: clear clean compile run

clear:
	@clear

clean:
	@rm -rf main.o
	@rm -rf main.out
	@rm -rf temp.txt

compile:
	@gcc -o main.out main.c -lm
	@gcc -c main.c 

run:
	@./main.out
