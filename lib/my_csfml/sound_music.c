/*
** EPITECH PROJECT, 2021
** my_csfml
** File description:
** sound_music
*/

#include "my_csfml.h"
#include <stdlib.h>

sfSound *create_sound(const char *sound_filename, const float volume)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buf = sfSoundBuffer_createFromFile(sound_filename);

    if (sound == NULL || buf == NULL)
        return NULL;
    sfSound_setBuffer(sound, buf);
    sfSound_setVolume(sound, volume);
    return sound;
}

sfMusic *play_music(const char *sound_filename, const float volume, \
                    sfBool loop)
{
    sfMusic *music = sfMusic_createFromFile(sound_filename);

    if (music == NULL)
        return NULL;
    sfMusic_setVolume(music, volume);
    sfMusic_setLoop(music, loop);
    sfMusic_play(music);
    return music;
}