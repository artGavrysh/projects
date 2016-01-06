#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/dir.h>

#include "dirent.h"
#include "dir.h"


void fsize(char* );

/* print file sizes */
int main(int argc, char *argv[])
{
    if (argc == 1)      /* default: current directory */
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}

//int stat(char *, struct stat *);
void dirwalk (char *, void (*fcn)(char *));

/*fsize: print size of file "name" */
void fsize(char* name)
{
    struct stat stdbuf;

    if (stat (name, &stdbuf) == -1) // the system call
    {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stdbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s\n", stdbuf.st_size, name);
}

#define MAX_PATH    1024

DIR *m_opendir(char* );
void m_closedir(DIR*);
Dirent *m_readdir(DIR* );

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;
    
    if ((dfd = m_opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = m_readdir(dfd)) != NULL)
    {
        printf("Debug: enter the main loop\n");
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
            continue;
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof (name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        else
        {
            printf("Debug: enter recursion\n");
            sprintf (name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    m_closedir(dfd);
}

/* opendir: open a directory for readdir calls */
DIR *m_opendir(char *dirname)
{
    int fd;
    struct stat stbuf;
    DIR *dp;
    printf("Debug: enter opendir\n");

    if ((fd = open(dirname, O_RDONLY, 0)) == -1
        || fstat(fd, &stbuf) == -1
        || (stbuf.st_mode & S_IFMT) != S_IFDIR
        || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
    {
            printf("opendir return NULL\n");
            return NULL;
    }
    dp->fd = fd;
    return dp;
}

/*closedir: close directory opened by opendir */
void m_closedir(DIR *dp)
{
    if (dp) 
    {
        close (dp->fd);
        free(dp);
    }
}

/* readdir: read directory entries in sequence */
Dirent *m_readdir(DIR *dp)
{
    struct direct dirbuf; /*local directory structure */
    static Dirent d;      /* return: portable structure */

    printf("Debug: enter readdir\n");
    printf("Read size %d <==> %lu\n", read(dp->fd, (char*) &dirbuf, sizeof(dirbuf)), sizeof(dirbuf));
    while (read(dp->fd, (char*) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf))
    {
        if (dirbuf.d_ino == 0)  /* slot not in use */
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0'; /*ensure termination */
        return &d;
    }
    printf("readdir return NULL\n");
    return NULL;
}
