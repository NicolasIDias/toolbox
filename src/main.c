#include <stdio.h>
#include <toolbox/cadv_math.h>

int main(void)
{
    float x = 10.0f, y = 5.0f;
    int a = 7, b = 10;
    
    printf("%f\n", MAX(x, y));
    printf("%d\n", MIN(a, b));

    return 0;
}