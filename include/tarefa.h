#include <stdlib.h>
#include <gtk/gtk.h>
#include <json-glib-1.0/json-glib/json-glib.h>

#define MAIN_WND_BUILDER "glade/main.glade"
#define MAX_ACOES_QNT 200

struct _tarefas{
  int id;
  struct _acao *acoes[MAX_ACOES_QNT];
  JsonObject *json_obj;
}tarefas;

extern struct _wnds_compon{
  GtkWidget *tarefa_code;
  GtkWidget *iniciar_button;
  GtkWidget *exe_rept;
  GtkWidget *exe_vel;
}wnds_compon;

int tarefa_get_exe_qnt(void);

int tarefa_get_exe_vel(void);

int tarefa_get_code(void);

int tarefa_get_path(int tarefa_code);

struct _tarefas *tarefa_get_obj(int code);
