all: clear clean compile  run

clear:
	@clear

clean:
	@echo "Removing old outputs..."
	@echo "=========================="
	@rm -rf main.o
	@rm -rf main.out
	@rm -rf utils.o
	@rm -rf customeraccount.txt

compile:
	@echo "\nCompiling..."
	@echo "=========================="
	@gcc main.c utils.c -c
	@gcc main.c utils.c -o main.out

run:
	@echo "\nRunning..."
	@echo "==========================\n"
	@./main.out
