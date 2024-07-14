index:
	gcc -o SPOTYFOM *.c ./NCurses/*.c -lncurses -lpanel -lmenu
	
	./SPOTYFOM

testes:
	@if [ -f executavel ]; then \
		rm executavel; \
	fi
	
	gcc -o SPOTYFOM *.c ./NCurses/*.c -g -lncurses -lpanel -lmenu
	gdb ./SPOTYFOM

clear:
	@if [ -f SPOTYFOM ]; then \
		rm SPOTYFOM; \
	fi
	clear

instala_ncurses:
	sudo apt-get update
	sudo apt-get install -y libncurses5-dev libncursesw5-dev
