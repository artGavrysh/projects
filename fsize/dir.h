#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct direct /*directory entry */
{
    ino_t d_ino;
    char d_name[DIRSIZ];
};
