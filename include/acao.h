#include <gtk/gtk.h>
#include <json-glib-1.0/json-glib/json-glib.h>

#define ACAO_POS_ACTIVE 1
#define MAIN_WND_BUILDER "glade/main.glade"
#define ACAO_CHOOSE_BUILDER "glade/escolher_acao.glade"
#define ACAO_BOX_BUILDER "glade/acao_box.glade"

extern struct _params{
  char *tarefas_path;
  int max_acoes;
}params;

#define MAX_ACOES_QNT 200

int min_pos_livre=0;

extern GtkWidget **acao_box,  *acoes_list_grid;

int acao_pos_livres[MAX_ACOES_QNT];

void acao_add_acao(void);

JsonObject *acao_choose_props(void);

void acao_rem_acao(GtkButton *button, gpointer user_data);

static int acao_get_qnt(void);
static int acao_get_pos_livre(void);

struct _acao{
  int id;
  int tipo_int;
  char *tipo_string;
  char *valor;
  JsonObject *json_node;
};

struct _tarefas{
  int id;
  struct _acao *acoes[MAX_ACOES_QNT];
  JsonObject *json_obj;
}tarefa;
