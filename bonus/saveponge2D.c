#include <SFML/Audio.h>
#include <stdio.h>
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
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfTexture* texture2;
    sfTexture* texture3;
    sfSprite* sprite;
    sfSprite* sprite2;
    sfSprite* sprite3;
    sfEvent event;
    int a = 1;

    sfVector2f toto = {12, 0};
    sfVector2f tata = {1240, 0};
    sfVector2f balle = {60, 60};

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
      if (balle.x != 0 && balle.x != 1170) {
        sfRenderWindow_clear(window, sfWhite);
        if(tata.y < 600) {
           sfSprite_setPosition(sprite, tata);
           sfRenderWindow_drawSprite(window, sprite, NULL);
           tata.y += 1;
        }

        if(toto.y < 600) {
            sfSprite_setPosition(sprite2, toto);
            sfRenderWindow_drawSprite(window, sprite2, NULL);
            toto.y += 1;
        }
        sfSprite_setPosition(sprite3, balle);
        sfRenderWindow_drawSprite(window, sprite3, NULL);
        if (balle.y == -200) {
            a = 1;
          }
        if (balle.y == 500) {
          a = -1;
        }
        balle.x += 1;
        balle.y = (balle.y + 1 * a);

        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite2, NULL);
        sfRenderWindow_drawSprite(window, sprite3, NULL);
        sfRenderWindow_display(window);
        printf("je suis une balle%f\n", balle.y);
      } else {
        sfRenderWindow_close(window);
      }
  }
    sfSprite_destroy(sprite);
    sfSprite_destroy(sprite2);
    sfSprite_destroy(sprite3);
    sfTexture_destroy(texture);
    sfTexture_destroy(texture2);
    sfTexture_destroy(texture3);
    sfRenderWindow_destroy(window);
}
