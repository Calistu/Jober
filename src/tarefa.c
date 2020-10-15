#include <tarefa.h>

int tarefa_get_exe_qnt(void){
  int qnt = (int) gtk_spin_button_get_value(GTK_SPIN_BUTTON(wnds_compon.exe_rept));
  return qnt;
}

int tarefa_get_exe_vel(void){
  int qnt = (int) gtk_spin_button_get_value(GTK_SPIN_BUTTON(wnds_compon.exe_vel));
  return qnt;
}

int tarefa_get_code(void){

  if(wnds_compon.tarefa_code){
    gchar *tarefa_code_gchar =(gchar*) gtk_entry_get_text(GTK_ENTRY(wnds_compon.tarefa_code));
    if(tarefa_code_gchar)
      return atoi(tarefa_code_gchar);
  }else{
    g_print("Campo para código não encontrado");
    return 0;
  }

  return 0;
}

int tarefa_get_path(int tarefa_code){

  return 0;
}

struct _tarefas *tarefa_get_obj(int code){


  return 0;
}
