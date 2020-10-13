extern int init_main(void);

int main(int argc, char *argv[]){

  if(init_main())
    return 1;

  return 0;
}
