/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** read_file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *open_file(char const *filepath)
{
    struct stat info;
    char *buffer;
    int fd = open(filepath, O_RDONLY);

    if (fd < 0)
        return (NULL);
    fstat(fd, &info);
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    if (read(fd, buffer, info.st_size) <= 0)
        return NULL;
    buffer[info.st_size] = '\0';
    close(fd);
    return (buffer);
}