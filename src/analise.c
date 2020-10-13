#include <analise.h>

int analis_mouseMove(char *coordenadas){
  int x=0,y=0;
  if(sscanf(coordenadas,"%ix%i",&x,&y)==2){
    if(x > params.max_XScreen){
      g_print("posição X máxima atingida");
      return 1;
    }
    if(y > params.max_YScreen){
      g_print("posição Y máxima atingida");
      return 1;
    }
  }
  return 0;
}
