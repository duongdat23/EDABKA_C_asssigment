#include <stdio.h>

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    // set bit thứ 5 của n
    int result = (1 << 4) | n;
    printf("result = %d ", result);
    return 0;
}
