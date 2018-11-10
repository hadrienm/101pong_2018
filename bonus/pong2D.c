#include <SFML/Audio.h>
#include <SFML/Graphics.h>
int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    texture = sfTexture_createFromFile("rectangle.bmp", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}