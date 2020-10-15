#include <main.h>

int load_main_wnd(void){

  GtkWidget *tarefa_code_entry, *exe_rept_entry, *exe_vel_entry;

  params.max_acoes = 10;
  for(int i=0; i<params.max_acoes; i++)
    acao_pos_livres[i] = 0;

  GtkBuilder *main_builder = gtk_builder_new_from_file(MAIN_WND_BUILDER);
  if(!main_builder){
    gtk_widget_show_all(gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_NONE, "Não foi possível abrir construtor"));
    return 1;
  }

  tarefa_code_entry = GTK_WIDGET(gtk_builder_get_object(main_builder,"tarefa_code"));
  main_wnd = GTK_WIDGET(gtk_builder_get_object(main_builder,"main_wnd"));
  acoes_list_grid = GTK_WIDGET(gtk_builder_get_object(main_builder,"acoes_list_grid"));
  tarefa_code_entry = GTK_WIDGET(gtk_builder_get_object(main_builder,"tarefa_code"));
  exe_rept_entry = GTK_WIDGET(gtk_builder_get_object(main_builder,"exe_rept_entry"));
  exe_vel_entry = GTK_WIDGET(gtk_builder_get_object(main_builder,"exe_vel_entry"));

  if(tarefa_code_entry)
    wnds_compon.tarefa_code = tarefa_code_entry;

  if(exe_rept_entry)
    wnds_compon.exe_rept = exe_rept_entry;

  if(exe_vel_entry)
    wnds_compon.exe_vel = exe_vel_entry;

  acao_box = malloc(sizeof(GtkWidget*)*MAX_ACOES_QNT);

  gtk_window_maximize(GTK_WINDOW(main_wnd));
  gtk_builder_connect_signals(main_builder,NULL);

  gtk_widget_show_all(main_wnd);
  return 0;
}

int init_main(void){

  gtk_init(NULL,NULL);

  if(params_read_params(NULL))
    return 1;

  if(load_main_wnd())
    return 1;

  gtk_main();

  return 0;
}
