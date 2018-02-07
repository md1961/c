#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#define M_PI 3.14159265358979323846

int tankVol(int h, int d, int vt) {
    double theta = acos((double)(d - h) / d);
    double area_fan = M_PI * pow(d, 2) * theta / (2 * M_PI);
    double area_tri = (float)(d - h) * (d * sin(theta)) / 2;
    double frac = (area_fan - area_tri) / (M_PI * pow(d, 2) / 4);
    return (int)(vt * frac);
}

int main(void) {
    int d = 7;
    int vt = 3848;
    for (int h = 0; h <= 7; h++) {
        printf("%2d : %4d\n", h, tankVol(h, d, vt));
    }

    return 0;
}
