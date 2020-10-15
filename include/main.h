#include <gtk/gtk.h>

int init_main(void);

extern struct _params{
  char *tarefas_path;
  int max_acoes;
}params;

struct _wnds_compon{
  GtkWidget *tarefa_code;
  GtkWidget *iniciar_button;
  GtkWidget *exe_rept;
  GtkWidget *exe_vel;

}wnds_compon;

#define MAIN_WND_BUILDER "glade/main.glade"
#define OPC_BOX_BUILDER "glade/opcoes_box.glade"
#define MAX_ACOES_QNT 100

extern void acao_add_acao(void);

extern int acao_pos_livres[MAX_ACOES_QNT];

int load_main_wnd(void);

int params_read_params(char *path);

GtkWidget *main_wnd, *acoes_list_grid;
GtkWidget **acao_box;
