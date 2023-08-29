#include <stdio.h>

#define PAYRATE 12.00    // 12$ / 1hour
#define TAXATE_300 0.15  // 15%
#define TAXATE_450 0.20  // 20%
#define TAXATE_REST 0.25 // 25%
#define OVERTIME 40      // hour

int main()
{
    double paygross = 0, taxes = 0;
    int hour;
    scanf("%d", &hour);

    // calculate paygross
    if (hour <= OVERTIME) // Changed '<' to '<=' for inclusivity
    {
        paygross = hour * PAYRATE;
    }
    else
    {
        paygross = 40 * PAYRATE;
        double overtime = (hour - 40) * 1.5 * PAYRATE;
        paygross += overtime;
    }

    // calculate taxes
    if (paygross <= 300)
    {
        taxes = paygross * TAXATE_300;
    }
    else if (paygross > 300 && paygross <= 450)
    {
        taxes = 300 * TAXATE_300;               // Tax for the first 300
        taxes += (paygross - 300) * TAXATE_450; // Additional tax for the amount above 300
    }
    else
    {
        taxes = 300 * TAXATE_300;                // Tax for the first 300
        taxes += 150 * TAXATE_450;               // Tax for the amount between 301 and 450
        taxes += (paygross - 450) * TAXATE_REST; // Additional tax for the amount above 450
    }

    // calculate the netpay
    double netpay = paygross - taxes;
    // display results
    printf("Your gross pay this week is %.2f\n", paygross);
    printf("Your taxes this week is %.2f\n", taxes);
    printf("Your net pay this week is %.2f", netpay);
    return 0;
}
