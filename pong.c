/*
** EPITECH PROJECT, 2018
** 101pong.c
** File description:
** function reverse.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    int g = 0;
    int e = 1;
    int f = 0;
    if(argc != 8) {
        printf("pas assez d'argument pour éxécuter le programme\n");
        return(84);
    }

    float norm_w = 0;
    int i = 0;
    int d = 1;
    float teta = 0;
    float x0 = atof(argv[1]);
    float x1 = atof(argv[4]);
    float y0 = atof(argv[2]);
    float y1 = atof(argv[5]);
    float z0 = atof(argv[3]);
    float z1 = atof(argv[6]);
    int n = atof(argv[7]);
    float w2[3] = {x1 - x0, y1 - y0, z1 - z0};
    float w[6] = {x0, x1, y0, y1 ,z0, z1};
    float w1[3] = {x1 - x0, y1 - y0, z1 - z0};
    float norm_v = 0;


    printf("The velocity vector of the ball is :\n");

    for(i = 0; i <= 2; i++) {
        if(i == 0)
            printf("(");
        printf("%0.2f", w2[i]);
        if (i != 2)
            printf(", ");
        if(i == 2)
            printf(")\n");
    }

    for(i = 0; i <3; i ++) {
        norm_v += w2[i] * w2[i];
    }

    norm_v = sqrt(norm_v);

    for(i = 0; i < 3; i++) {
        w1[i] = (w1[i] * n + 1) + w[d] - 1;
        d += 2;
    }

    for(i = 0; i < 3; i++) {
        norm_w += w1[i]*w1[i];
    }
    norm_w = sqrtf(norm_w);

    printf("At time t + 4, ball coordinates will be:\n");

    for(i = 0; i <= 2; i++){
        if(i == 0)
            printf("(");
        printf("%0.2f", w1[i]);
        if (i != 2)
            printf(", ");
        if(i == 2)
            printf(")\n");
    }

    teta = asin(fabs(w2[2])/norm_v);
    teta = (teta * 180) / M_PI;

    if ((w[4] > 0 && z1 > 0 && w2[2] > 0) || (w[4] < 0 && z1 > 0 && w2[2] > 0) || (w[4] < 0 && z1 < 0 && w[2] < 0) || (w[4] > 0 && z1 < 0 && w2[2] < 0 )) {
      printf("The ball won't reach the bat\n");
    } else if (w2[2] == 0){
      printf("The incidence angle is:\n");
      printf("0.00");
      printf(" degrees\n");
    } else {
        printf("The incidence angle is:\n");
        printf("%0.2f", teta);
        printf(" degrees\n");
    }
}
