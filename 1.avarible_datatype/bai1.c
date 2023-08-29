#include <stdio.h>

int main()
{
    float width, length, perimeter, arceage; // chu vi , diện tích
    scanf("%f%f", &width, &length);
    perimeter = 2 * (width + length);
    arceage = width * length;
    printf("Chu vi cua hinh chu nhat co chieu dai %f va chieu rong %f la %f ", length, width, perimeter);
    printf("\nDien tich cua hinh chu nhat co chieu dai %f va chieu rong %f la %f ", length, width, arceage);
    return 0;
}