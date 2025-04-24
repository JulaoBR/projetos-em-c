#include <ncurses.h>
#include <stdlib.h>

#define QTD_OPCOES 3

const char *opcoes[QTD_OPCOES] = {
	"Calculadora",
	"Agenda",
	"Sair"
};

void desenha_menu(WINDOW *janela, int highlight) {
	box(janela, 0, 0);
	for (int i = 0; i < QTD_OPCOES; ++i) {
		if (i == highlight) {
			wattron(janela, A_REVERSE);
		}

		mvwprintw(janela, i + 2, 2, "%s", opcoes[i]);
		wattroff(janela, A_REVERSE);
	}

	mvwprintw(janela, QTD_OPCOES + 3, 2, "Use ↑ ↓ e ENTER para escolher");
	wrefresh(janela);
}

int main() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);

	int altura = 10, largura = 40, start_y = 4, start_x = 10;
	WINDOW *menuwin = newwin(altura, largura, start_y, start_x);

	wbkgd(menuwin, COLOR_PAIR(1));
	keypad(menuwin, TRUE);

	int escolha = 0;
	int tecla;

	while (1) {
		werase(menuwin);
		desenha_menu(menuwin, escolha);

		tecla = wgetch(menuwin);
		switch (tecla) {
			case KEY_UP:
				escolha = (escolha -1 + QTD_OPCOES) % QTD_OPCOES;
				break;
			case KEY_DOWN:
				escolha = (escolha + 1) % QTD_OPCOES;
				break;
			case 10:
				if (escolha == 0) {
					werase(menuwin);
					box(menuwin, 0, 0);
					mvwprintw(menuwin, 2, 2, "Abrindo Calculadora...");
					wrefresh(menuwin);
					getch();
				} else if (escolha == 1) {
					werase(menuwin);
					box(menuwin, 0, 0);
					mvwprintw(menuwin, 2, 2, "Abrindo Agenda...");
					wrefresh(menuwin);
					getch();
				} else if (escolha == 2) {
					endwin();
					return 0;
				}
				break;
		}

	}

	delwin(menuwin);
	endwin();
	return 0;
}

