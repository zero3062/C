#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    uid_t uid;
    gid_t gid;
    struct passwd *pw;
    struct group *pg;
    int i;

    uid = getuid();
    pw = getpwuid(uid);
    gid = getgid();
    pg = getgrgid(gid);

    printf("uid=%d(%s) ", uid, pw->pw_name);
    printf("gid=%d(%s) groups=", gid, pg->gr_name);

    while(pg=getgrent())
        for(i=0;pg->gr_mem[i] != NULL; i++)
            if(!strcmp(pw->pw_name, pg-gr_mem[i]))
                printf("%d(%s) ", pg->gr_gid, pg->gr_name);

    printf("\n");
    exit(0);
}