#ifndef FMENU_H
#define FMENU_H

struct fmenu {
    char text[8];
    char fN;
    void (*cb)(struct fmenu*);
    struct fmenu *next;
};

struct fmenu *fmenuAdd(struct fmenu *menu, const char *text, void (*cb)(struct fmenu*));
void fmenuFree(struct fmenu *menu);

#endif