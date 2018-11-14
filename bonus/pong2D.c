#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfTexture* texture2;
    sfTexture* texture3;
    sfSprite* sprite;
    sfSprite* sprite2;
    sfSprite* sprite3;
    sfEvent event;

    sfVector2f toto = {1890, 0};
    sfVector2f tata = {0, 0};
    sfVector2f balle = {945, 410};

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    texture = sfTexture_createFromFile("rectangle.bmp", NULL);
    texture2 = sfTexture_createFromFile("rectangle.bmp", NULL);
    texture3 = sfTexture_createFromFile("balle.bmp", NULL);

    sprite = sfSprite_create();
    sprite2 = sfSprite_create();
    sprite3 = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfSprite_setTexture(sprite3, texture3, sfTrue);

    sfSprite_setPosition(sprite, toto);
    sfSprite_setPosition(sprite2, tata);
    sfSprite_setPosition(sprite3, balle);
    while (sfRenderWindow_isOpen(window)) {
      if (balle.x != 0 || balle.x != 1890) {
        sfRenderWindow_clear(window, sfWhite);
        if(tata.y < 820) {
           sfSprite_setPosition(sprite, tata);
           sfRenderWindow_drawSprite(window, sprite, NULL);
           tata.y += 1;
        }

        if(toto.y < 820) {
            sfSprite_setPosition(sprite2, toto);
            sfRenderWindow_drawSprite(window, sprite2, NULL);
            toto.y += 1;
        }
        balle.x += 1;
        balle.y += 1;
     }

    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite2, NULL);
    sfRenderWindow_drawSprite(window, sprite3, NULL);
    sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(sprite2);
    sfSprite_destroy(sprite3);
    sfTexture_destroy(texture);
    sfTexture_destroy(texture2);
    sfTexture_destroy(texture3);
    sfRenderWindow_destroy(window);
}
