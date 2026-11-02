#include "fmenu.h"

struct fmenu *fmenuAdd(struct fmenu *menu, const char *text, void (*cb)(struct fmenu*)) {
    struct fmenu *nMenu = (struct fmenu*)malloc(sizeof(struct fmenu));
    strncpy(nMenu->text, text, 8);
    nMenu->cb = cb;
    nMenu->next = NULL;
    if (menu == NULL) {
        nMenu->fN = 1;
        return nMenu;
    } else {
        struct fmenu *m = menu;
        int i = 1;
        while (m->next != NULL) {
            m = menu->next;
            i++;
        }
        nMenu->fN = i;
        m->next = nMenu;
        return menu;
    }
}
void fmenuFree(struct fmenu *menu) {
    struct fmenu *next;
    do {
        next = menu->next;
        free(menu);
    } while (next != NULL);
}