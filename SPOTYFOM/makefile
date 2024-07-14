index:
	gcc -o executavel *.c ./NCurses/*.c -lncurses -lpanel -lmenu
	
	./executavel

testes:
	@if [ -f executavel ]; then \
		rm executavel; \
	fi
	
	gcc -o executavel *.c -g -lncurses -lpanel -lmenu
	gdb ./executavel

clear:
	@if [ -f executavel ]; then \
		rm executavel; \
	fi
	clear

instala_ncurses:
	sudo apt-get update
	sudo apt-get install -y libncurses5-dev libncursesw5-dev
