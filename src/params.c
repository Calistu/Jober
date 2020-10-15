#include <params.h>

int params_read_params(char *path){

  if(!path)
    path = PARAMS_PATH;
  JsonParser *parser = json_parser_new();
  GError *erro = NULL;
  if(!json_parser_load_from_file(parser,path,&erro)){
    g_print("Erro ao abrir arquivo de parametros %s\n",erro->message);
    return 1;
  }
  JsonNode *root = json_parser_get_root(parser);
  if(!root){
    g_print("Arquivo sem node Root\n");
    return 1;
  }
  JsonObject *obj = json_node_get_object(root);

  JsonNode *tarefas_path = json_object_get_member(obj,"tarefas_path");
  if(!tarefas_path){
    g_print("Caminho para tarefas não configurado\n");
    return 1;
  }

  JsonNode *max_acoes = json_object_get_member(obj,"max_acoes");
  if(!max_acoes){
    g_print("Máximo de ações não configurado\n");
    return 1;
  }

  JsonNode *dimen_tela = json_object_get_member(obj,"dimen_tela");
  if(!dimen_tela){
    g_print("Tamanho da tela não configurado\n");
    return 1;
  }

  params.tarefas_path = (char *) json_node_get_string(tarefas_path);
  params.max_acoes_qnt = (int) json_node_get_int(max_acoes);
  char *dimensoes = (char *) json_node_get_string(dimen_tela);
  if(dimensoes){
    if(sscanf(dimensoes,"%ix%i",
    &params.max_XScreen,
    &params.max_YScreen)!=2){
      g_print("Não foi possivel identificar tamanho da tela\n");
      return 1;
    }
  }


  return 0;
}
