/*CURRENCY CONVERTOR BY ARYAN ROSHAN*/

/* DISCLAIMER:
 * This program uses static exchange rates which is not suitable for real-world currency conversion where rates fluctuate.
 * An API should be used to get real-time exchange rates.
 * Error handling in this program is basic. For robust applications, more comprehensive error checking is recommended.
 */

#include <stdio.h>
#include <string.h>


// Define a structure for a currency
typedef struct {
    char code[4];    // 3-letter currency code (e.g., USD)
    double toUSD;    // Exchange rate to convert this currency to USD
} Currency;

// Function to convert currency
double convertCurrency(double amount, double fromRate, double toRate) {
    return amount * fromRate * toRate; // Convert the amount to USD first, then to the target currency
}

int main() {
    // Here, an array of 10 global currencies with their corresponding exchange rates to USD is written.
    Currency currencies[] = {
        {"USD", 1.0},
        {"EUR", 1.12},
        {"GBP", 1.31},
        {"JPY", 0.0089},
        {"AUD", 0.71},
        {"CAD", 0.78},
        {"CHF", 1.08},
        {"CNY", 0.15},
        {"SEK", 0.11},
        {"NZD", 0.68}
    };
    
    int numCurrencies = sizeof(currencies) / sizeof(currencies[0]);

    double amount;
    char fromCurrency[4], toCurrency[4];
    double fromRate = 0.0, toRate = 0.0;
    int i, fromFound = 0, toFound = 0;

    // User input
    printf("Currency Converter\n");
    printf("Enter amount: "); //Asks user for amount.
    scanf("%lf", &amount);
    printf("Enter currency to convert from (e.g., USD): "); //Asks user for the current that it needs to convert from.
    scanf("%s", fromCurrency);
    printf("Enter currency to convert to (e.g., EUR): "); //Asks user for current that it needs to convert to.
    scanf("%s", toCurrency);

    // Find the exchange rates for the input currencies
    for (i = 0; i < numCurrencies; i++) {
        if (strcmp(currencies[i].code, fromCurrency) == 0) {
            fromRate = currencies[i].toUSD;
            fromFound = 1;
        }
        if (strcmp(currencies[i].code, toCurrency) == 0) {
            toRate = currencies[i].toUSD;
            toFound = 1;
        }
    }

    // Perform the conversion if both currency codes are found
    if (fromFound && toFound) {
        double convertedAmount = convertCurrency(amount, fromRate, 1 / toRate);
        printf("%.2f %s is %.2f %s\n", amount, fromCurrency, convertedAmount, toCurrency);
    } else {
        printf("Invalid currency code.\n");
    }

    return 0;
}
