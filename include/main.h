#include <gtk/gtk.h>

int init_main();

#define MAIN_WND_BUILDER "glade/main.glade"
#define MAX_ACOES_QNT 20

int min_pos_livre=0;
GtkWidget *main_wnd, *acoes_list_grid;
GtkWidget **acao_box;
