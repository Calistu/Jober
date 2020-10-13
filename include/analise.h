#include <stdio.h>
#include <gtk/gtk.h>

int analis_mouseMove(char *coordenadas);

extern struct _params{
  char *tarefas_path;
  int max_acoes_qnt;
  int max_XScreen;
  int max_YScreen;
}params;
