/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** my_rpg
*/

#include "my_rpg.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *open_map(char *path)
{
    struct stat fileStat;
    char *buff;
    int fd;
    if (stat(path, &fileStat) < 0)
        return (NULL);
    if (fileStat.st_size == 0)
        return (NULL);
    fd = open(path, O_RDONLY);
    buff = malloc(sizeof(char) * fileStat.st_size + 1);
    buff[fileStat.st_size] = '\0';
    if (fd == -1)
        return (NULL);
    if ((read(fd, buff, fileStat.st_size) < 0))
        return (NULL);
    close(fd);
    return (buff);
}