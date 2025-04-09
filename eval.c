#include <stdio.h>

float GetFloat(const char* msg)
{
    float var;
    puts(msg);
    scanf("%d", &var);
    return var;
}

int main(void)
{
    float a, b, c, d, e, f, g;
    
    a = GetFloat("a: ");
    b = GetFloat("b: ");
    c = GetFloat("c: ");
    d = GetFloat("d: ");
    e = GetFloat("e: ");
    f = GetFloat("f: ");
    g = GetFloat("g: ");

    float res = ((a + b / c * d - e) * (f - g));

    printf("res = %f\n", res);
}