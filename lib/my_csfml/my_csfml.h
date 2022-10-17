/*
** EPITECH PROJECT, 2021
** my defender
** File description:
** buttons
*/

#ifndef BUTTONS_H
#define BUTTONS_H

#include "my_lib.h"
#include "SFML/Audio.h"
#include "SFML/System.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/Audio.h"

#define ANIM_RED        &red_anim
#define ANIM_RIGHT      &moveright_anim
#define ANIM_LEFT       &moveleft_anim

#define get_Second(clock, error) \
                    sfTime_asSeconds(clock_get_elapsed_time(clock, error))
#define get_Microseconds(clock, error)  \
                    sfTime_asMicroseconds(clock_get_elapsed_time(clock, error))
#define get_Milliseconds(clock, error)  \
                    sfTime_asMilliseconds(clock_get_elapsed_time(clock, error))

#define RDM_BOOL        rand() % 2
#define RDM(min, max)   min + rand() % (max - min)

#define RV2F(rect)      (sfVector2f) {(rect).left, (rect).top}
#define RR2F(rect)      (sfFloatRect) {(rect).left, (rect).top, \
                        (rect).whith, (rect).height}
#define R2F(left, top, whith, height) \
                        (sfFloatRect) {left, top, whith, height}
#define R2I(left, top, whith, height) \
                        (sfIntRect) {left, top, whith, height}
#define VV2F(vec)       (sfVector2f) {(vec).x, (vec).y}
#define V2F(x, y)       (sfVector2f) {x, y}

////////////////////////////////////////////////////////////
/// \brief Add a new button_t to a list_l.
///
/// \param list             The head of a list_l (it can be NULL)
/// \param x                the x position of the button (float)
/// \param y                the y position of the button (float)
/// \param size_x           the width of the button (float)
/// \param size_y           the height of the button (float)
/// \param animation        A macro wich define the animation of
///                         the button when mouse pass over it (*f)
/// \param texture_filname  The path of the sprite texture (char *)
/// \param txt              The string wich will be displayed (char *)
///
/// \return A new button_t (NULL if failed)
///
////////////////////////////////////////////////////////////
#define ADD_BUTTON(list, x, y, size_x, size_y, anim, sprite, txt)\
    add_nod(&list, create_button((sfFloatRect) {x, y, size_x, size_y}\
    , anim, sprite, txt));

////////////////////////////////////////////////////////////
/// \brief Parse the given list_l and give a tmp pointed to each node.
///
/// \param head     head of the list_l
///
////////////////////////////////////////////////////////////
#define PARSE_LIST(head)\
    for (list_l *tmp = head; tmp != NULL; tmp = tmp->next)\
        if (tmp->data)

////////////////////////////////////////////////////////////
/// \brief Parse the given array and give a i index.
///
/// \param array     pointer to the array
///
////////////////////////////////////////////////////////////
#define PARSE_ARRAY(array)\
    for (int i = 0; (array)[i]; i++)

#define PARSE_MAP(map) \
    for (int y = 0; map[y]; y++) \
        for (size_t x = 0; map[y][x]; x++)

#define FOR_FOR(width, height) \
    for (int y = 0; y < height; y++) \
        for (int x = 0; x < width; x++)

typedef struct button
{
    sfSprite *sprite;
    sfText *txt;
    sfVector2f pos;
    sfFloatRect box;
    sfBool txt_display;
    void (*animation)(struct button *);
} button_t;

typedef struct display
{
    sfSprite **sprites;
    list_l *buttons;
    sfText **texts;
    sfRectangleShape **shapes;
} display_t;

////////////////////////////////////////////////////////////
/// \brief Create a new sfText.
///
/// \param pos          x and y position of the text
/// \param text         The string wich will be displayed
/// \param size         The size of the text charactere
/// \param font         The font used
///
/// \return A new sfText (NULL if failed)
///
////////////////////////////////////////////////////////////
sfText *create_text(const sfVector2f pos, const char *text, \
                    const unsigned int size, const sfFont *font);

////////////////////////////////////////////////////////////
/// \brief Create a new sfSprite.
///
/// \param pos              x and y position of the sprite (x, y)
/// \param size             The size of the sprite (width, height)
/// \param texture_filname  The path of the sprite texture
///
/// \return A new sfSprite (NULL if failed)
///
////////////////////////////////////////////////////////////
sfSprite *create_sprite(const sfVector2f pos, const sfVector2f size, \
                                            sfTexture *texture);

////////////////////////////////////////////////////////////
/// \brief Create a new button_t.
///
/// \param rectangle        position and size of the button
///                         (x, y, width, height)
/// \param animation        A macro wich define the animation of
///                         the button when mouse pass over it
/// \param texture_filname  The path of the button texture
/// \param txt              The string wich will be displayed
///
/// \return A new button_t (NULL if failed)
///
////////////////////////////////////////////////////////////
button_t *create_button(sfFloatRect rectangle, void (*animation)(button_t *), \
                        sfTexture *texture, const char *txt);

////////////////////////////////////////////////////////////
/// \brief Create a new sfSound.
///
/// \param sound_filename   The path of the audio file
/// \param volume           A float wich define the volume
///
/// \return A new sfSound (NULL if failed)
///
////////////////////////////////////////////////////////////
sfSound *create_sound(const char *sound_filename, float volume);

////////////////////////////////////////////////////////////
/// \brief Draw a drawable object to the render-target.
///
/// \param renderWindow render window object
/// \param object       Object to draw
///
////////////////////////////////////////////////////////////
void render_window_draw_button(sfRenderWindow *window, button_t *object);

////////////////////////////////////////////////////////////
/// \brief Draw all buttons to the render-target.
///
/// \param renderWindow render window object
/// \param head         head of a list_l of buttons
///
////////////////////////////////////////////////////////////
static inline void RenderWindow_drawAllButtons(sfRenderWindow *renderWindow, \
                                                list_l *head) {
    for (list_l *tmp = head; tmp; tmp = tmp->next)
        render_window_draw_button(renderWindow, tmp->data);
}

////////////////////////////////////////////////////////////
/// \brief get the index of the pressed button.
///
/// The index will corespond to the last create button and
/// increase by 1 to the first button create
///
/// \param renderWindow render window object
/// \param object       Object to draw
///
/// \return A int superior to 0 (-1 if no button pressed)
///
////////////////////////////////////////////////////////////
int get_button(list_l *buttons, sfRenderWindow *window);

sfRectangleShape *create_rectangleshape(sfFloatRect rect, sfColor color);
void move_rect(sfSprite *sprite, int offset, int max_value);
void switch_anim(sfSprite *sprite, int y);
void moveright_anim(button_t *button);
void moveleft_anim(button_t *button);
void displaytxt_anim(button_t *button);
void red_anim(button_t *button);
void free_button(button_t *button);
void button_move(button_t *button, sfVector2f vector);
void button_set_position(button_t *button, sfVector2f vector);
void button_set_textsize(button_t *button, unsigned int *size,
                    sfColor *color, sfFont *font);
sfVector2f button_get_position(button_t *button);
sfMusic *play_music(const char *sound_filename, const float volume, \
                    sfBool loop);
int is_having_to_close(sfRenderWindow *window);
sfRenderWindow *create_window(sfVector2f size, char *name);
sfTime clock_get_elapsed_time(sfClock *clock, sfTime error);
void clock_restart(sfClock *clock, sfTime *error);
void clock_skip_passed_time(sfClock *clock, sfTime *error);
void display_display(sfRenderWindow *window, display_t *display);
display_t *init_display(int sprite_nbr, int text_nbr, int shapes_nbr);
void free_display(display_t *display);

#endif /* !BUTTONS_H */