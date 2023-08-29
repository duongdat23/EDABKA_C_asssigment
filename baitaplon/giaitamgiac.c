#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define PI 3.14159265 // định nghĩa giá trị của PI
#define epcilon 0.00001
// khai báo hàm nguyên mẫu vào các biến toàn cục
bool checkStatus;
int toado[6];
float trongtam[2];
int laplai;
float Ax, Ay, Bx, By, Cx, Cy;
float a, b, c;
float goccanh[6] = {0};
float duongcao[3];
float trungtuyen[3];
void kiemtra_tamgiac(float Ax, float Ay, float Bx, float By, float Cx, float Cy);
void goccanh_tamgiac();
void xet_tamgiac();
float dientich_tamgiac(float a, float b, float c);
void duongcao_tamgiac(float a, float b, float c);
void trungtuyen_tamgiac(float a, float b, float c);
void tam_tamgiac();
void giai_matamgiac();
int main()
{
    checkStatus = false;
    // ham do while khi ta nhập sai tọa độ yêu cầu nhập lại
    // thực hiện câu lệnh trong do và điều kiện lặp lại là khi checkStatus = false
    do
    {
        printf("Nhap toa do diem A:\n");
        printf("Ax: ");
        scanf("%d", &toado[0]);
        printf("\nAy: ");
        scanf("%d", &toado[1]);
        printf("\nNhap toa do diem B:\n");
        printf("Bx: ");
        scanf("%d", &toado[2]);
        printf("\nBy: ");
        scanf("%d", &toado[3]);
        printf("\nNhap toa do diem C:\n");
        printf("Cx: ");
        scanf("%d", &toado[4]);
        printf("\nCy: ");
        scanf("%d", &toado[5]);
        printf("\nToa do diem A da nhap: A(%.2f, %.2f)\n", (float)toado[0], (float)toado[1]);
        printf("Toa do diem B da nhap: B(%.2f, %.2f)\n", (float)toado[2], (float)toado[3]);
        printf("Toa do diem C da nhap: C(%.2f, %.2f)\n", (float)toado[4], (float)toado[5]);
        printf("-----------------------------------------------");
        giai_matamgiac(); // hàm giải mã tam giác
    } while (checkStatus == false);
    return 0;
}
// A(1;2) B(4;5) C(2;1) Tọa độ tam giác vuông với sai số 0.000008
// A(0;1) B(2;4) C(5;6) Tam giác tù cân
// A(-1;1) B(1;3) C(2;0) Tam giác cân
// A(1;3); B(-5;6); C(0;1) Tam giác vuông tại A
// A(10;5) B(3;2) C(6;-5) Tam giác vuông cân tại B
// A(10;5) B(1;2) C(4;-5) Tam giác nhọn
//============================================================================
// Hàm kiểm tra tam giác
// Kiểm tra 3 điểm A, B, C có thẳng hàng không
// Nếu không thẳng hàng thì A, B, C sẽ tạo thành một tam giác
// Nếu xABBC != yABBC thì 3 điểm A, B, C là một tam giác
void kiemtra_tamgiac(float Ax, float Ay, float Bx,
                     float By, float Cx, float Cy)
{
    Ax = toado[0]; // gán các giá trị tọa độ được lưu trong mảng toado[6]
    Ay = toado[1]; // tương ứng với A(Ax;Ay) B(Bx;By) C(Cx;Cy)
    Bx = toado[2];
    By = toado[3];
    Cx = toado[4];
    Cy = toado[5];
    float xABBC, yABBC;
    if (Cx - Bx != 0 && Cy - By != 0)
    {
        xABBC = (Bx - Ax) / (Cx - Bx); // vì thực hiện phép chia nên điều kiện mẫu số phải khác 0
        yABBC = (By - Ay) / (Cy - By);
        //       printf("\n%f so sánh %f", (float)xABBC,(float)yABBC);
        if (xABBC != yABBC)
        {
            printf("\nToa do 3 diem nhap vao tao thanh mot tam giac\n\n");
            checkStatus = true;
        }
        else
        {
            printf("\nToa do 3 diem nhap vao khong tao thanh mot tam giac\n\n");
            printf("Hay nhap lai toa do 3 diem!\n");
            checkStatus = false;
        }
    }
    else
    {
        printf("\nToa do 3 diem nhap vao khong tao thanh mot tam giac\n\n");
        printf("Hay nhap lai toa do 3 diem!\n");
    }
}
/*=========================================================================
 Tính cạnh của tam giác bằng công thức tính khoảng cách
 VD độ dài AB = sqrt(pow((Bx-Ax),2) + pow((By-Ay),2)); trong đó A(Ax, Ay) và B(Bx, By)
 Áp dụng định lý cosin của một tam giác bất kì tính các góc A, góc B, góc C
 goccanh[0] = AB
 goccanh[1] = BC
 goccanh[2] = CA
 goccanh[3] = Góc A
 goccanh[4] = Góc B
 goccanh[5] = Góc C
*/
void goccanh_tamgiac()
{
    Ax = toado[0]; // list [Ax,Ay,Bx,By,Cx,Cy] tương ứng với các phần tử trong toado
    Ay = toado[1];
    Bx = toado[2];
    By = toado[3];
    Cx = toado[4];
    Cy = toado[5];
    //  Sử dụng các hàm toán học trong thư viện math.h
    //  Tính cạnh bằng công thức tính khoảng cách
    goccanh[0] = sqrt(pow((Bx - Ax), 2) + pow((By - Ay), 2));
    printf("\n   Chieu dai canh AB la: %.2f", goccanh[0]);
    goccanh[1] = sqrt(pow((Cx - Bx), 2) + pow((Cy - By), 2));
    printf("\n   Chieu dai canh BC la: %.2f", goccanh[1]);
    goccanh[2] = sqrt(pow((Ax - Cx), 2) + pow((Ay - Cy), 2));
    printf("\n   Chieu dai canh CA la: %.2f", goccanh[2]);
    //=================================================================================================
    //  Tính Góc bằng công thức cosin
    goccanh[3] = acos(((pow(goccanh[2], 2) + pow(goccanh[0], 2) - pow(goccanh[1], 2)) / (2 * goccanh[0] * goccanh[2]))) * 180 / PI;
    printf("\n   Goc A: %.2f", goccanh[3]);
    goccanh[4] = acos((pow(goccanh[1], 2) + pow(goccanh[0], 2) - pow(goccanh[2], 2)) / (2 * goccanh[1] * goccanh[0])) * 180 / PI;
    printf("\n   Goc B: %.2f", goccanh[4]);
    goccanh[5] = 180 - goccanh[3] - goccanh[4];
    printf("\n   Goc C: %.2f\n", goccanh[5]);
}
// Hàm xét và phân loại tam giác
// Sử dụng các điều kiện là các góc, cạnh của tam giác để phân loại
void xet_tamgiac()
{
    // Tam giác vuông
    // Điều khiện có 1 góc = 90 độ và các góc còn lại khác 45 độ và với đk sai số +- 0.000008
    if ((goccanh[3] == 90 && goccanh[4] != 45 && goccanh[5] != 45) || (goccanh[3] - 90 <= epcilon && goccanh[3] - 90 > 0) || (90 - goccanh[3] <= epcilon && 90 - goccanh[3] > 0))
    {
        printf("\nTam giac ABC la tam giac vuong tai A");
    }
    else if ((goccanh[4] == 90 && goccanh[3] != 45 && goccanh[5] != 45) || (goccanh[4] - 90 <= epcilon && goccanh[4] - 90 > 0) || (90 - goccanh[4] <= epcilon && 90 - goccanh[4] > 0))
    {
        printf("\nTam giac ABC la tam giac vuong tai B");
    }
    else if ((goccanh[5] == 90 && goccanh[3] != 45 && goccanh[4] != 45) || (goccanh[5] - 90 <= epcilon && goccanh[5] - 90 > 0) || (90 - goccanh[5] <= epcilon && 90 - goccanh[5] > 0))
    {
        printf("\nTam giac ABC la tam giac vuong tai C");
    }
    // Tam giác cân
    else if (goccanh[3] < 90 && goccanh[0] == goccanh[2])
    {
        printf("\nTam giac ABC la tam giac can tai A");
    }
    else if (goccanh[4] < 90 && goccanh[0] == goccanh[1])
    {
        printf("\nTam giac ABC la tam giac can tai B");
    }
    else if (goccanh[5] < 90 && goccanh[1] == goccanh[2])
    {
        printf("\nTam giac ABC la tam giac can tai C");
    }
    // Tam giác vuông cân
    else if (goccanh[3] == 90 && goccanh[0] == goccanh[2])
    {
        printf("\nTam giac ABC la tam giac vuong can tai A");
    }
    else if (goccanh[4] == 90 && goccanh[0] == goccanh[1])
    {
        printf("\nTam giac ABC la tam giac vuong can tai B");
    }
    else if (goccanh[5] == 90 && goccanh[1] == goccanh[2])
    {
        printf("\nTam giac ABC la tam giac vuong can tai C");
    }
    // Tam giác tù và cân
    else if (goccanh[3] > 90 && goccanh[0] == goccanh[2])
    {
        printf("\nTam giac ABC la tam giac tu va can tai A");
    }
    else if (goccanh[4] > 90 && goccanh[0] == goccanh[1])
    {
        printf("\nTam giac ABC la tam giac tu va can tai A");
    }
    else if (goccanh[5] > 90 && goccanh[1] == goccanh[2])
    {
        printf("\nTam giac ABC la tam giac tu va can tai A");
    }
    // Tam giác đều
    else if (goccanh[3] == 60 && goccanh[4] == 60 && goccanh[5] == 60)
    {
        printf("\nTam giac ABC la tam giac deu");
    }
    // Tam giác tù
    // lớn hơn giá trị sai số 0.000008

    else if (goccanh[3] > 90 && goccanh[0] != goccanh[1] && goccanh[1] != goccanh[2] && goccanh[3] - 90 > epcilon)
    {
        printf("\nTam giac ABC la tam giac tu tai A");
    }
    else if (goccanh[4] > 90 && goccanh[0] != goccanh[1] && goccanh[1] != goccanh[2] && goccanh[4] - 90 > epcilon)
    {
        printf("\nTam giac ABC la tam giac tu tai B");
    }
    else if (goccanh[5] > 90 && goccanh[0] != goccanh[1] && goccanh[1] != goccanh[2] && goccanh[5] - 90 > epcilon)
    {
        printf("\nTam giac ABC la tam gia tu tai C");
    }
    // Tam giác nhọn
    // Là các trường hợp còn lại nên ta sử dụng else
    else
    {
        printf("\nTam giac ABC la tam giac nhon");
    }
}
// hàm tính chu vi của tam giác
float chuvi(float a, float b, float c)
{
    a = goccanh[0];
    b = goccanh[2];
    c = goccanh[1];
    return a + b + c;
}
// Hàm tính diện tích tam giác
//  Sử dụng công thức heron
float dientich_tamgiac(float a, float b, float c)
{
    a = goccanh[0];
    b = goccanh[2];
    c = goccanh[1];
    float p = chuvi(a, b, c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
// Hàm tính đường cao của tam giác
// list[dcA,dcB,dcC]
// dcA = duongcao[0]
// dcB = duongcao[1]
// dcC = duongcao[2]
void duongcao_tamgiac(float a, float b, float c)
{
    a = goccanh[0];
    b = goccanh[2];
    c = goccanh[1];
    float p = chuvi(a, b, c) / 2.0;
    duongcao[0] = (2 * sqrt(p * (p - a) * (p - b) * (p - c))) / c;
    duongcao[1] = (2 * sqrt(p * (p - a) * (p - b) * (p - c))) / b;
    duongcao[2] = (2 * sqrt(p * (p - a) * (p - b) * (p - c))) / a;
    printf("\nDo dai duong cao tu dinh A: %.2f", duongcao[0]);
    printf("\nDo dai duong cao tu dinh B: %.2f", duongcao[1]);
    printf("\nDo dai duong cao tu dinh C: %.2f", duongcao[2]);
}
// Hàm tính trung tuyến của tam giác
// list[ttA, ttB, ttC];
// ttA = trungtuyen[0]
// ttB = trungtuyen[1]
// ttC = trungtuyen[2]
void trungtuyen_tamgiac(float a, float b, float c)
{
    a = goccanh[0];
    b = goccanh[2];
    c = goccanh[1];
    trungtuyen[0] = sqrt(((a * a + b * b) / 2) - (c * c / 4));
    trungtuyen[1] = sqrt(((a * a + c * c) / 2) - (b * b / 4));
    trungtuyen[2] = sqrt(((b * b + c * c) / 2) - (a * a / 4));
    printf("\nDo dai duong trung tuyen tu dinh A: %.2f", trungtuyen[0]);
    printf("\nDo dai duong trung tuyen tu dinh B: %.2f", trungtuyen[1]);
    printf("\nDo dai duong trung tuyen tu dinh C: %.2f", trungtuyen[2]);
}
// Trọng tâm của tam giác
// Gọi G là trọng tâm của tam giác G(Xg,Yg)
void tam_tamgiac()
{
    Ax = toado[0]; // list [Ax,Ay,Bx,By,Cx,Cy] tương ứng với các phần tử trong toado
    Ay = toado[1];
    Bx = toado[2];
    By = toado[3];
    Cx = toado[4];
    Cy = toado[5];
    trongtam[0] = (Ax + Bx + Cx) / 3;
    trongtam[1] = (Ay + By + Cy) / 3;
    printf("\nToa do trong tam: [%.2f, %.2f]", trongtam[0], trongtam[1]);
}
// Hàm giải mã tam giác tổng hợp của các hàm
void giai_matamgiac()
{
    kiemtra_tamgiac(Ax, Ay, Bx, By, Cx, Cy);
    if (checkStatus == true)
    {
        printf("\n1. So do co ban cua tam giac:");
        goccanh_tamgiac();
        xet_tamgiac();
        printf("\n\n2.Dien tich cua tam giac ABC la: %.2f", dientich_tamgiac(a, b, c));
        printf("\n\n3. So do nang cao cua tam giac:");
        duongcao_tamgiac(a, b, c);
        trungtuyen_tamgiac(a, b, c);
        printf("\n\n4.Toa do dac biet cua tam giac ABC");
        tam_tamgiac();
        printf("\n----------------------------------------------");
    }
}
