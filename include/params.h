#include <stdio.h>
#include <gtk/gtk.h>
#include <json-glib-1.0/json-glib/json-glib.h>

#define PARAMS_PATH "params.json"

struct _params{
  char *tarefas_path;
  int max_acoes_qnt;
  int max_XScreen;
  int max_YScreen;
}params;

int params_read_params(char *path);
