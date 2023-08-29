#include <stdio.h>
int main()
{
    enum Company
    {
        Google,
        Facebook,
        Xerox,
        Yahoo,
        Ebay,
        Microsoft
    };
    enum Company google = Microsoft;
    enum Company facebook = Facebook;
    enum Company xerox = Xerox;
    enum Company yahoo = Yahoo;

    printf("Google %d\n", google);
    printf("Yahoo = %d\n", yahoo);

    // Chèn dòng sau để thay đổi giá trị của biến Google
    google = Xerox;

    printf("New Google %d\n", google); // In giá trị mới của biến Google

    return 0;
}