#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    gid_t gid;
    struct group *pg;
    int i;

    gid = getgid();
    pg = getgrgid(gid);
    printf("group name : %s\n", pg->gr_name);
    exit(0);
}