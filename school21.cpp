#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

int h;
double x,p,e,z;

    scanf("%lf",&h);

p=1.29;
z=0.000125;
e=2.7182818284590452353602874713527;

x=p*pow(e, -h*z);

    printf("%.2lf", x);



return 0;
}