#include <acao.h>

void acao_add_acao(void){

  JsonObject *acao_prop = acao_choose_props();
  JsonNode *tipo_string, *nome, *tipo_int, *valor;

  if(acao_prop){
    nome = json_object_get_member(acao_prop,"nome");
    valor = json_object_get_member(acao_prop,"valor");
    tipo_int = json_object_get_member(acao_prop,"tipo_int");
    tipo_string = json_object_get_member(acao_prop,"tipo_string");
  }else{
    return ;
  }

  char acao_name[10];

  if(acao_get_qnt() >= params.max_acoes){
    printf("Limite de ações\n");
    return ;
  }
  min_pos_livre = acao_get_pos_livre();

  acao_pos_livres[min_pos_livre] = ACAO_POS_ACTIVE;

  GtkBuilder *acao_box_builder = gtk_builder_new_from_file(ACAO_BOX_BUILDER);
  if(!acao_box_builder){
    gtk_widget_show_all(gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_NONE, "Não foi possível abrir construtor"));
    return ;
  }

  acao_box[min_pos_livre] = GTK_WIDGET(gtk_builder_get_object(acao_box_builder,"acao_box"));
  GtkWidget *nome_label = GTK_WIDGET(gtk_builder_get_object(acao_box_builder,"nome_acao_label"));
  GtkWidget *tipo_label = GTK_WIDGET(gtk_builder_get_object(acao_box_builder,"tipo_acao_label"));
  GtkWidget *valor_label = GTK_WIDGET(gtk_builder_get_object(acao_box_builder,"valor_acao_label1"));

  gtk_builder_connect_signals(acao_box_builder,NULL);

  if( tipo_label && valor_label ){

    char id[20];
    sprintf(id,"Acão %i",min_pos_livre);

    const gchar *nome_gchar = strdup( id );
    json_node_set_string(nome, nome_gchar);
    gtk_label_set_text(GTK_LABEL(nome_label),nome_gchar);

    const gchar *tipo_gchar = json_node_get_string(tipo_string);
    gtk_label_set_text(GTK_LABEL(tipo_label),tipo_gchar);

    gint64 tipo_gint = json_node_get_int(tipo_int);

    const gchar *valor_gchar = json_node_get_string(valor);
    gtk_label_set_text(GTK_LABEL(valor_label),valor_gchar);

    struct _acao acao;
    acao.id = min_pos_livre;
    acao.tipo_int = (int)tipo_gint;
    acao.tipo_string = g_strdup(tipo_gchar);
    acao.json_node = acao_prop;

    tarefa.acoes[min_pos_livre] = &acao;

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

static int acao_get_pos_livre(void){
  for(int i=0; i<MAX_ACOES_QNT; i++){
    if(acao_pos_livres[i])
      continue;

    return i;
  }
  return 0;
}

static int acao_get_qnt(void){
  int qnt=0;
  for(int i=0; i<MAX_ACOES_QNT; i++){
    if(acao_pos_livres[i])
      qnt++;
  }
  return qnt;
}

JsonObject *acao_choose_props(void){
  GError *erro=NULL;
  JsonObject *props = json_object_new();
  if(erro){
    g_print("Erro ao criar instância json da ação\n");
    g_print("%s\n",erro->message);
    return NULL;
  }
  JsonNode *tipo_string, *nome, *tipo_int, *valor;
  nome = json_node_new(JSON_NODE_VALUE);
  tipo_string = json_node_new(JSON_NODE_VALUE);
  tipo_int = json_node_new(JSON_NODE_VALUE);
  valor = json_node_new(JSON_NODE_VALUE);

  GtkBuilder *builder = gtk_builder_new_from_file(ACAO_CHOOSE_BUILDER);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder,"wnd"));
  GtkWidget *tipos = GTK_WIDGET(gtk_builder_get_object(builder,"tipo_combo"));
  GtkWidget *entry_valor = GTK_WIDGET(gtk_builder_get_object(builder,"entry_valor"));

  gtk_builder_connect_signals(builder,NULL);

  int res = gtk_dialog_run(GTK_DIALOG(dialog));

  if(res == GTK_RESPONSE_ACCEPT){
    gint tipoi_selct = gtk_combo_box_get_active(GTK_COMBO_BOX(tipos));
    gchar *tipos_selct = strdup(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(tipos)));
    gchar *valor_selct = (gchar*)strdup(gtk_entry_get_text(GTK_ENTRY(entry_valor)));

    if(!tipos_selct){
      g_print("Tipo não foi selecionado");
      return NULL;
    }

    char id[12];
    sprintf(id,"%i", tipoi_selct);

    if(!tipos_selct){
      tipos_selct = strdup("");
      valor_selct = strdup("");

      tipoi_selct = 0;
      tipos_selct = strdup("");
    }

    json_node_set_string(nome,"");
    json_node_set_string(tipo_string,tipos_selct);
    json_node_set_int(tipo_int,tipoi_selct);
    json_node_set_string(valor,valor_selct);

	  json_object_set_member(props,"nome",nome);
    json_object_set_member(props,"tipo_string",tipo_string);
    json_object_set_member(props,"tipo_int",tipo_int);
    json_object_set_member(props,"valor",valor);

    gtk_widget_destroy(dialog);
    return props;
  }else{
    gtk_widget_destroy(dialog);
    return NULL;
  }

}
