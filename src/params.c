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

  JsonNode *tarefas_path = json_object_get_member(root,"tarefas_path");
  if(!tarefas_path){
    g_print("Caminho para tarefas não configurado\n");
    return 1;
  }
  JsonNode *max_acoes = json_object_get_member(root,"max_acoes");
  if(!max_acoes){
    g_print("Máximo de ações não configurado\n");
    return 1;
  }

  return 0;
}
