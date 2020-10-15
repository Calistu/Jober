#include <interpretador.h>

int *interp_mouseGetPos(void){
  int x,y;
  GdkDisplay *display = gdk_display_get_default();
  GdkSeat* seat = gdk_display_get_default_seat(display);
  GdkDevice* pointer = gdk_seat_get_pointer(seat);
  int *coordenadas = malloc(sizeof(int)*2);

  gdk_device_get_position (pointer, NULL, &x, &y);
  coordenadas[0] = x;
  coordenadas[1] = y;
  return coordenadas;
}


void interp_mouseMove(int x, int y){

  GdkDisplay *display = gdk_display_get_default();
  GdkScreen *screen = gdk_screen_get_default();
  GdkSeat* seat = gdk_display_get_default_seat(display);
  GdkDevice* pointer = gdk_seat_get_pointer(seat);

  gdk_device_warp(pointer,screen,x,y);
  return ;
}

int interp(char *filepath){


	return 0;
}

int interp_execute_acoes(void){

  struct _tarefas *task = &tarefas;
  int acao_qnt = acao_get_qnt();
  int qnt = tarefa_get_exe_qnt();
  int vel = tarefa_get_exe_vel();

  for(int exe_qnt=0;exe_qnt<qnt;exe_qnt++){
    g_print("--------------\n");
    for(int cont=0;cont<acao_qnt;cont++){
      int *coordenadas = NULL;
      g_print("Acao %i\n",task->acoes[cont]->id);
      g_print("Acao Tipo %i\n",task->acoes[cont]->tipo_int);
      g_print("Acao Valor %s\n",task->acoes[cont]->valor);

      switch(task->acoes[cont]->tipo_int){
        case CLIQUE_ACT:
          coordenadas = analis_mouseMove(task->acoes[cont]->valor);
          if(coordenadas){
            g_print("Clicando em %ix%i\n",coordenadas[0],coordenadas[1]);
            interp_mouseMove(coordenadas[0],coordenadas[1]);
          }
          break;
      }
      g_usleep( G_USEC_PER_SEC - (gulong) vel * 10000);
    }
    g_print("--------------\n");
  }
  return 0;
}
