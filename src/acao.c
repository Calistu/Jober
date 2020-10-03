#include <acao.h>

void acao_add_acao(){

  xmlNodePtr acao_prop = acao_choose_props();
  xmlNodePtr tipo,valor;

  if(acao_prop){

    if(!(tipo = getElementByTagName(acao_prop,"tipo"))){
      g_print("node tipo não encontrado\n");
      return ;
    }

    if(!(valor = getElementByTagName(acao_prop,"valor"))){
      g_print("node tipo não encontrado\n");
      return ;
    }
  }else{
    return ;
  }

  GtkBuilder *acao_builder = gtk_builder_new_from_file(MAIN_WND_BUILDER);
  char acao_name[10];
  min_pos_livre = acao_get_pos_livre();
  acao_pos_livres[min_pos_livre] = 1;

  if(!acao_builder){
    gtk_widget_show_all(gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_NONE, "Não foi possível abrir construtor"));
    return ;
  }

  acao_box[min_pos_livre] = GTK_WIDGET(gtk_builder_get_object(acao_builder,"acao_box"));
  GtkWidget *tipo_label = GTK_WIDGET(gtk_builder_get_object(acao_builder,"valor_acao_label"));
  GtkWidget *valor_label = GTK_WIDGET(gtk_builder_get_object(acao_builder,"valor_acao_label1"));

  gtk_builder_connect_signals(acao_builder,NULL);

  if(tipo_label){
    if(tipo && tipo->content)
      gtk_label_set_text(GTK_LABEL(tipo_label),tipo->content);
  }

  if(valor_label){
    if(valor && valor->content)
      gtk_label_set_text(GTK_LABEL(valor_label),valor->content);
  }

  sprintf(acao_name,"%i",min_pos_livre);
  gtk_widget_set_name(acao_box[min_pos_livre],acao_name);

  gtk_grid_attach(GTK_GRID(acoes_list_grid),acao_box[min_pos_livre],min_pos_livre,0,1,1);

}

void acao_rem_acao(GtkButton *button, gpointer user_data){

  if(user_data){
    char *nome = g_strdup(gtk_widget_get_name(user_data));
    int posicao = atoi(nome);
    acao_pos_livres[posicao] = 0;
    gtk_widget_destroy(user_data);
  }else{
    g_print("Não foi possível encontrar acao_box\n");
  }

}

static int acao_get_pos_livre(){

  for(int i=0; i<MAX_ACOES_QNT; i++){
    if(acao_pos_livres[i])
      continue;

    return i;
  }

  return 0;
}

static int acao_get_qnt(){
  int qnt=0;

  for(int i=0; i<MAX_ACOES_QNT; i++){
    if(acao_pos_livres[i])
      qnt++;
  }

  return qnt;
}

xmlNodePtr acao_choose_props(){

  xmlNodePtr props = xmlNewNode(NULL, "acao");
  xmlNodePtr tipo = xmlNewNode(NULL, "tipo");
  xmlNodePtr valor = xmlNewNode(NULL, "valor");

  GtkBuilder *builder = gtk_builder_new_from_file(ACAOCHOOSE_BUILDER);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder,"wnd"));
  GtkWidget *tipos = GTK_WIDGET(gtk_builder_get_object(builder,"tipo_combo"));
  GtkWidget *entry_valor = GTK_WIDGET(gtk_builder_get_object(builder,"entry_valor"));

  gtk_builder_connect_signals(builder,NULL);

  int res = gtk_dialog_run(GTK_DIALOG(dialog));

  if(res == GTK_RESPONSE_ACCEPT){
    gchar *tipo_selct = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(tipos));
    gchar *valor_selct = (gchar*)gtk_entry_get_text(GTK_ENTRY(entry_valor));
    if(!tipo_selct){
      g_print("Tipo não foi selecionado");
      return NULL;
    }

    xmlNodeAddContent(tipo,tipo_selct);
    xmlNodeAddContent(valor,valor_selct);
    xmlAddChild(props,tipo);
    xmlAddChild(props,valor);

    gtk_widget_destroy(dialog);
    return props;
  }else{
    gtk_widget_destroy(dialog);
    return NULL;
  }

}
