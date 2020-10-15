#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <json-glib-1.0/json-glib/json-glib.h>

#ifdef __linux__
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif

void interp_mouseMove(int x, int y);

int interp(char *filepath);


#define MAX_ACOES_QNT 200

extern struct _acao{
  int id;
  int tipo_int;
  char *tipo_string;
  char *valor;
  JsonObject *json_node;
}acao;

extern struct _tarefas{
  int id;
  struct _acao *acoes[MAX_ACOES_QNT];
  JsonObject *json_obj;
}tarefas;

extern int tarefa_get_code(void);

extern int tarefa_get_exe_qnt(void);

extern int tarefa_get_exe_vel(void);

extern struct _tarefas *tarefa_get_obj(int code);

enum{
  CLIQUE_ACT,
  TECLA_ACT,
  ACT_QNT
};

int *interp_mouseGetPos(void);

int interp_execute_acoes(void);

extern int *analis_mouseMove(char *coordenadas);

extern int acao_get_qnt(void);
