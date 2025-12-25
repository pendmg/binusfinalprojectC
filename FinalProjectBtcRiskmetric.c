#include <stdio.h>
 
// FUNCTIONS
void stockanalysis(void);
void ethanalysis(void);
void btcanalysis(void);

int main(void)
{
    int choice;

    printf("=== Market Risk Metric ===\n");
    printf("We can predict whether the price of your selected asset will rise or drop tomorrow.\n___________________________________________________________________________\n\n");
    printf("Choose one asset below, where you'll be asked its daily price for the last week.\n\n");
    printf("1. Stock from S&P500\n");
    printf("2. Ethereum\n");
    printf("3. Bitcoin\n\n");
    printf("Choose asset: ");
    scanf("%d", &choice);

    if (choice==1) {
        stockanalysis();
    } else if (choice==2) {
        ethanalysis();
    } else if (choice==3) {
        btcanalysis();
    } else {
        printf("Please select a number from 1-3\n");
    }

    return 0;
}

// STOCK
void stockanalysis(void)
{
    double price[7];
    double changeaverage = 0;
    double risk = 0;
    double change;
    int i = 0;

    printf("___________________________________________________________________________\n\nEnter the price of your stock for the last 7 days:\n");
    printf("[WARNING] Please do not enter values with commas (X 50,000) but you're allowed to add decimal numbers (V 50000.32)\n\n");

    while (i < 7) {
        printf("Day %d: ", i + 1);
        scanf("%lf", &price[i]);
        i = i + 1;
    }

    i = 1;
    while (i < 7) {
        change = (price[i] - price[i-1]) / price[i-1] * 100;
        changeaverage = changeaverage + change;

        if (change < 0) {
            risk = risk - change;
        } else {
            risk = risk + change;
        }
        i = i + 1;
    }

    changeaverage = changeaverage / 6;
    risk = risk / 6;

    printf("\nAverage Change: %.2f%%\n", changeaverage);
    printf("Risk Level: %.2f%%\n", risk);

    if (changeaverage > 0 && risk <= 1.0) {
        printf("Prediction: Your stock will likely go up (Minimal Risk)\n");
    } else if (changeaverage < 0 && risk <= 1.0) {
        printf("Prediction: Your stock will likely go down (Minimal Risk)\n");
    } else {
        printf("Currently, your stock changes too wildly (or not at all) to make a reliable prediction. There's no clear direction where it might go.\n");
    }
}

// ETHEREUM
void ethanalysis(void)
{
    double price[7];
    double changeaverage = 0;
    double risk = 0;
    double change;
    int i = 0;

    printf("___________________________________________________________________________\n\nEnter the price of Ethereum for the last 7 days:\n");
    printf("[WARNING] Please do not enter values with commas (X 50,000) but you're allowed to add decimal numbers (V 50000.32)\n\n");

    while (i < 7) {
        printf("Day %d: ", i + 1);
        scanf("%lf", &price[i]);
        i = i + 1;
    }

    i = 1;
    while (i < 7) {
        change = (price[i] - price[i-1]) / price[i-1] * 100;
        changeaverage = changeaverage + change;

        if (change < 0) {
            risk = risk - change;
        } else {
            risk = risk + change;
        }
        i = i + 1;
    }

    changeaverage = changeaverage / 6;
    risk = risk / 6;

    printf("\nAverage Change: %.2f%%\n", changeaverage);
    printf("Risk Level: %.2f%%\n", risk);

    if (changeaverage > 0 && risk <= 2.8) {
        printf("Prediction: Ethereum will likely go up (Quite Risky)\n");
    } else if (changeaverage < 0 && risk <= 2.8) {
        printf("Prediction: Ethereum will likely go down (Quite Risk)\n");
    } else {
        printf("Currently, Ethereum changes too wildly (or not at all) to make a reliable prediction. There's no clear direction where it might go.\n");
    }
}

// BITCOIN
void btcanalysis(void)
{
    double price[7];
    double changeaverage = 0;
    double risk = 0;
    double change;
    int i = 0;

    printf("___________________________________________________________________________\n\nEnter the price of Bitcoin for the last 7 days:\n");
    printf("[WARNING] Please do not enter values with commas (X 50,000) but you're allowed to add decimal numbers (V 50000.32)\n\n");

    while (i < 7) {
        printf("Day %d: ", i + 1);
        scanf("%lf", &price[i]);
        i = i + 1;
    }

    i = 1;
    while (i < 7) {
        change = (price[i] - price[i-1]) / price[i-1] * 100;
        changeaverage = changeaverage + change;

        if (change < 0) {
            risk = risk - change;
        } else {
            risk = risk + change;
        }
        i = i + 1;
    }

    changeaverage = changeaverage / 6;
    risk = risk / 6;

    printf("\nAverage Change: %.2f%%\n", changeaverage);
    printf("Risk Level: %.2f%%\n", risk);

    if (changeaverage > 0 && risk <= 2.0) {
        printf("Prediction: Bitcoin will likely go up (Moderate Risk)\n");
    } else if (changeaverage < 0 && risk <= 2.0) {
        printf("Prediction: Bitcoin will likely go down (Moderate Risk)\n");
    } else {
        printf("Currently, Bitcoin changes too wildly (or not at all) to make a reliable prediction. There's no clear direction where it might go.\n");
    }
}

