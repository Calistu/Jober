#include <analise.h>

int *analis_mouseMove(char *coordenadas){

  int x=0,y=0;
  if(sscanf(coordenadas,"%ix%i",&x,&y)){
    if(x > params.max_XScreen){
      g_print("posição %i (X máximo) atingida\n",params.max_XScreen);
      return NULL;
    }
    if(y > params.max_YScreen){
      g_print("posição %i (Y máximo) atingida\n",params.max_YScreen);
      return NULL;
    }
  }else{
    g_print("Posições não encontradas\n");
    return NULL;
  }

  int *pos = malloc(sizeof(int)*2);
  pos[0] = x;
  pos[1] = y;

  return pos;
}
