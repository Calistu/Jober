#include <gtk/gtk.h>
#include <libxml/xinclude.h>

#define MAIN_WND_BUILDER "glade/main.glade"
#define ACAOCHOOSE_BUILDER "glade/escolher_acao.glade"

#define MAX_ACOES_QNT 20

int min_pos_livre=0;

extern GtkWidget **acao_box,  *acoes_list_grid;

int acao_pos_livres[MAX_ACOES_QNT];

void acao_rem_acao(GtkButton *button, gpointer user_data);

static int acao_get_qnt();
static int acao_get_pos_livre();

xmlNodePtr acao_choose_props();

extern xmlNodePtr getContentByTagName( xmlNodePtr nodes,char *TagName );

extern xmlNodePtr getElementByTagName( xmlNodePtr nodes,char *TagName );
