#include <gtk/gtk.h>

int init_main();

#define MAIN_WND_BUILDER "glade/main.glade"
#define MAX_ACOES_QNT 20

extern void acao_add_acao();

extern int acao_pos_livres[MAX_ACOES_QNT];

GtkWidget *main_wnd, *acoes_list_grid;
GtkWidget **acao_box;
