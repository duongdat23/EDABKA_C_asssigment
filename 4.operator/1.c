#include <stdio.h>

int main()
{
    int n;

    printf("Nhap n: ");
    scanf("%d", &n);

    // Kiểm tra bit thứ 3 của n
    int result = (n >> 2) & 1;

    printf("result = %d ", result);
    return 0;
}
