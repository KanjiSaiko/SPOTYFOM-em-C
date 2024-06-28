#include "bibliotecas.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

int printMenu()
{	
    char *choices[] = {
                        "Executar",
                        "Playlist",
                        "Buscar",
                        "Imprimir",
                        "Relatorio",
                        "Backup",
                        "Sair",
                        "Exit",
                        (char *)NULL,
    };
    
    ITEM **my_items;

	int c, n_choices, i, highlight, choice;

	MENU *my_menu;

    WINDOW *my_menu_win;
	
	/* Initialize curses */
	initscr();
	start_color();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	/* Create items */
        n_choices = ARRAY_SIZE(choices);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i)
                my_items[i] = new_item(choices[i], choices[i]);

	/* Crate menu */
	my_menu = new_menu((ITEM **)my_items);
    

	/* Create the window to be associated with the menu */
        my_menu_win = newwin(10, 40, 4, 4);
        keypad(my_menu_win, TRUE);
     
	/* Set main window and sub window */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));

	/* Set menu mark to the string " * " */
        set_menu_mark(my_menu, " * ");

	/* Print a border around the main window and print a title */
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, "SPOTYFOM", COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        mvprintw(LINES - 2, 0, "F1 to exit");
	refresh();
        
	/* Post the menu */
	post_menu(my_menu);
	wrefresh(my_menu_win);

	while((c = wgetch(my_menu_win)) != KEY_F(1)) //ENQUANTO FOR DIFERENTE DE F1
	{       switch(c)
	        {	case KEY_DOWN:
                    menu_driver(my_menu, REQ_DOWN_ITEM);
                    if (highlight == 0)
                        highlight = n_choices - 1;
                    else
                        --highlight;
                    break;
                    
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
                if (highlight == n_choices - 1)
                        highlight = 0;
                    else
                        ++highlight;
				break;

            case 10: //enter
                choice = highlight;
                break;

		}
        if (choice != -1) // Se uma escolha foi feita
            break;
        wrefresh(my_menu_win);

	}	

	/* Unpost and free all the memory taken up */
        /*unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);*/
	endwin();

    return choice;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}
