#include <tarefa.h>

int tarefa_get_code(void){
  GtkBuilder *main_builder = gtk_builder_new_from_file(MAIN_WND_BUILDER);
  if(!main_builder){
    gtk_widget_show_all(gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_NONE, "Não foi possível abrir construtor"));
    return 1;
  }

  GtkWidget *tarefa_code_entry = GTK_WIDGET(gtk_builder_get_object(main_builder,"tarefa_code"));
  if(tarefa_code_entry){
    gchar *tarefa_code_gchar =(gchar*) gtk_entry_get_text(GTK_ENTRY(tarefa_code_entry));
    if(tarefa_code_gchar){
        int tarefa_code = atoi(tarefa_code_gchar);
        tarefa_get_path(tarefa_code);
    }
  }

  return 0;
}

int tarefa_get_path(int tarefa_code){

  return 0;
}

int tarefa_get_obj(void){


  return 0;
}
