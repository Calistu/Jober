#include <acao.h>

void add_acao(){

  GtkBuilder *acao_builder = gtk_builder_new_from_file(MAIN_WND_BUILDER);
  if(!acao_builder){
    gtk_widget_show_all(gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_NONE, "Não foi possível abrir construtor"));
    return ;
  }

  acao_box[min_pos_livre] = GTK_WIDGET(gtk_builder_get_object(acao_builder,"acao_box"));
  gtk_grid_attach(GTK_GRID(acoes_list_grid),acao_box[min_pos_livre],min_pos_livre,0,1,1);

}
