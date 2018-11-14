#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/InputStream.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector3.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdio.h>

int main()
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfTexture* texture2;
    sfTexture* texture3;
    sfTexture* texture4;
    sfSprite* sprite;
    sfSprite* sprite2;
    sfSprite* sprite3;
    sfSprite* sprite4;
    sfEvent event;
    sfMusic* music;
    sfMusic* musics;
    int a = 1;
    int d = 1;
    int score = 0;

    sfVector2f toto = {12, 0};
    sfVector2f tata = {1240, 0};
    sfVector2f balle = {60, 60};
    sfVector2f cb = {0, 0};

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    texture = sfTexture_createFromFile("rectangle.bmp", NULL);
    texture2 = sfTexture_createFromFile("rectangle.bmp", NULL);
    texture3 = sfTexture_createFromFile("balle.bmp", NULL);
    texture4 = sfTexture_createFromFile("cb.xcf", NULL);
    music = sfMusic_createFromFile("balle.ogg");
    musics = sfMusic_createFromFile("osu.ogg");

    sprite = sfSprite_create();
    sprite2 = sfSprite_create();
    sprite3 = sfSprite_create();
    sprite4 = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfSprite_setTexture(sprite3, texture3, sfTrue);
    sfSprite_setTexture(sprite4, texture4, sfTrue);

    sfSprite_setPosition(sprite, toto);
    sfSprite_setPosition(sprite2, tata);
    sfSprite_setPosition(sprite3, balle);
    sfSprite_setPosition(sprite4, cb);
    sfMusic_play(musics);
    while (sfRenderWindow_isOpen(window)) {
      if (balle.x != -180 && balle.x != 1170) {
        sfRenderWindow_clear(window, sfWhite);
        sfSprite_setPosition(sprite3, balle);
        sfRenderWindow_drawSprite(window, sprite3, NULL);
        if(toto.y < 570) {
           sfSprite_setPosition(sprite, toto);
           sfRenderWindow_drawSprite(window, sprite, NULL);
           toto.y = balle.y;
        }

        if(tata.y < 570) {
            sfSprite_setPosition(sprite2, tata);
            sfRenderWindow_drawSprite(window, sprite2, NULL);
            tata.y = balle.y;
        }
        if (balle.y == -200) {
            a = 1;
            sfMusic_play(music);
        }
        if (balle.y == 500) {
          a = -1;
          sfMusic_play(music);
        }
        if (balle.x == 1000 && balle.y == tata.y) {
          d = -1;
          sfMusic_play(music);
        }
        if (balle.x == -140  && balle.y == tata.y) {
          d = 1;
          sfMusic_play(music);
          score++;
        }
        balle.x = (balle.x + 1 * d);
        balle.y = (balle.y + 1 * a);

        sfRenderWindow_drawSprite(window, sprite4, NULL);
        sfRenderWindow_drawSprite(window, sprite3, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite2, NULL);
        sfRenderWindow_display(window);
        printf("mon score est de %d\n", score);
      } else {
        sfRenderWindow_close(window);
      }
  }
    sfMusic_destroy(music);
    sfMusic_destroy(musics);
    sfSprite_destroy(sprite);
    sfSprite_destroy(sprite2);
    sfSprite_destroy(sprite3);
    sfSprite_destroy(sprite4);
    sfTexture_destroy(texture);
    sfTexture_destroy(texture2);
    sfTexture_destroy(texture3);
    sfTexture_destroy(texture4);
    sfRenderWindow_destroy(window);
}
