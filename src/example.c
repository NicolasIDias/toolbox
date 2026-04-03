#include <stdio.h>
#include <toolbox/cadv_math.h>
#include <toolbox/cadv_log.h>

int main(void)
{
    int a = 10;
    int b = 42;
    float x = 1.5f;
    float y = 3.25f;

    printf("== math examples ==\n");
    printf("INT  MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    printf("INT  MAX(%d, %d) = %d\n", a, b, MAX(a, b));

    printf("FLOAT MIN(%f, %f) = %f\n", x, y, MIN(x, y));
    printf("FLOAT MAX(%f, %f) = %f\n", x, y, MAX(x, y));

    printf("\n== log examples ==\n");

    LOG_INFO("[INFO] ints: a=%d b=%d\n", a, b);
    LOG_INFO("[INFO] floats: x=%.2f y=%.2f\n", x, y);

    LOGGER("[RAW] mixed: a=%d, y=%.2f\n", a, y);

    printf("\n== ABS examples ==\n");

    LOG_INFO("[INFO] ints: a=%d b=%d\n", ABS(a), ABS(-b));
    LOG_INFO("[INFO] floats: x=%.2f y=%.2f\n", ABS(x), ABS(-y));

    LOGGER("[RAW] mixed: a=%d, y=%.2f\n", ABS(-a), ABS(-y));

    return 0;
}