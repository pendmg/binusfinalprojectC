#include <stdio.h>
 
// FUNCTIONS
void stockanalysis(void);
void ethanalysis(void);
void btcanalysis(void);

int main(void)
{
    int choice;

    printf("=== Market Risk Metric ===\n");
    printf("We can predict whether the price of your selected asset will rise or drop tomorrow.\n");
    printf("___________________________________________________________________________\n\n");
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

// STOCKS
void stockanalysis(void)
{
    double price[7];
    double sortedprice[7];
    double changeaverage = 0;
    double risk = 0;
    double change;
    double min, max;
    double searchvalue;
    double temp;
    int found = 0;
    int i = 0;
    int j;
    FILE *fp;

    printf("___________________________________________________________________________\n\n");
    printf("Enter the price of your stock for the last 7 days:\n");
    printf("[WARNING] Please do not enter values with commas (X 50,000) but you're allowed to add decimal numbers (V 50000.32)\n\n");

    // FILE PROCESSING
    fp = fopen("stockdata.txt", "w");

    while (i < 7) {
        printf("Day %d: ", i + 1);
        scanf("%lf", &price[i]);
        sortedprice[i] = price[i];
        fprintf(fp, "%.2f\n", price[i]);
        i = i + 1;
    }
    fclose(fp);

    // SORTING
    i = 0;
    while (i < 6) {
        j = 0;
        while (j < 6) {
            if (sortedprice[j] > sortedprice[j+1]) {
                temp = sortedprice[j];
                sortedprice[j] = sortedprice[j+1];
                sortedprice[j+1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    // MIN & MAX
    min = sortedprice[0];
    max = sortedprice[6];

    // SEARCHING
    printf("\n___________________________________________________________________________\n\n");
    printf("Just to make sure we've added your value properly, please mention a random price you've listed:\n");
    scanf("%lf", &searchvalue);

    i = 0;
    while (i < 7) {
        if (sortedprice[i] == searchvalue) {
            found = 1;
        }
        i = i + 1;
    }

    printf("\n");
    if (found == 1) printf("Value confirmed in the data.\n");
    else printf("Value not found in the data.\n");

    // RISK CALCULATION
    i = 1;
    while (i < 7) {
        change = (price[i] - price[i-1]) / price[i-1] * 100;
        changeaverage = changeaverage + change;

        if (change < 0) risk = risk - change;
        else risk = risk + change;

        i = i + 1;
    }

    changeaverage = changeaverage / 6;
    risk = risk / 6;

    printf("\n___________________________________________________________________________\n\n");
    printf("Minimum Price: %.2f\n", min);
    printf("Maximum Price: %.2f\n\n", max);
    printf("Average Change: %.2f%%\n", changeaverage);
    printf("Risk Level: %.2f%%\n", risk);

    printf("\nPREDICTION:\n");
    if (changeaverage > 0 && risk <= 1.0)
        printf("Your stock will likely go up (Minimal Risk)\n");
    else if (changeaverage < 0 && risk <= 1.0)
        printf("Your stock will likely go down (Minimal Risk)\n");
    else
        printf("Currently, your stock changes too wildly (or not at all) to make a reliable prediction.\n");
}

// ETH
void ethanalysis(void)
{
    double price[7];
    double sortedprice[7];
    double changeaverage = 0;
    double risk = 0;
    double change;
    double min, max;
    double searchvalue;
    double temp;
    int found = 0;
    int i = 0;
    int j;
    FILE *fp;

    printf("___________________________________________________________________________\n\n");
    printf("Enter the price of Ethereum for the last 7 days:\n");
    printf("[WARNING] Please do not enter values with commas (X 50,000) but you're allowed to add decimal numbers (V 50000.32)\n\n");

    fp = fopen("ethdata.txt", "w");

    while (i < 7) {
        printf("Day %d: ", i + 1);
        scanf("%lf", &price[i]);
        sortedprice[i] = price[i];
        fprintf(fp, "%.2f\n", price[i]);
        i = i + 1;
    }
    fclose(fp);

    i = 0;
    while (i < 6) {
        j = 0;
        while (j < 6) {
            if (sortedprice[j] > sortedprice[j+1]) {
                temp = sortedprice[j];
                sortedprice[j] = sortedprice[j+1];
                sortedprice[j+1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    min = sortedprice[0];
    max = sortedprice[6];

    printf("\n___________________________________________________________________________\n\n");
    printf("Just to make sure we've added your value properly, please mention a random price you've listed:\n");
    scanf("%lf", &searchvalue);

    i = 0;
    while (i < 7) {
        if (sortedprice[i] == searchvalue) found = 1;
        i = i + 1;
    }

    printf("\n");
    if (found == 1) printf("Value confirmed in the data.\n");
    else printf("Value not found in the data.\n");

    i = 1;
    while (i < 7) {
        change = (price[i] - price[i-1]) / price[i-1] * 100;
        changeaverage = changeaverage + change;

        if (change < 0) risk = risk - change;
        else risk = risk + change;

        i = i + 1;
    }

    changeaverage = changeaverage / 6;
    risk = risk / 6;

    printf("\n___________________________________________________________________________\n\n");
    printf("Minimum Price: %.2f\n", min);
    printf("Maximum Price: %.2f\n\n", max);
    printf("Average Change: %.2f%%\n", changeaverage);
    printf("Risk Level: %.2f%%\n", risk);

    printf("\nPREDICTION:\n");
    if (changeaverage > 0 && risk <= 2.8)
        printf("Ethereum will likely go up (Quite Risky)\n");
    else if (changeaverage < 0 && risk <= 2.8)
        printf("Ethereum will likely go down (Quite Risk)\n");
    else
        printf("Currently, Ethereum changes too wildly (or not at all) to make a reliable prediction.\n");
}

// BTC
void btcanalysis(void)
{
    double price[7];
    double sortedprice[7];
    double changeaverage = 0;
    double risk = 0;
    double change;
    double min, max;
    double searchvalue;
    double temp;
    int found = 0;
    int i = 0;
    int j;
    FILE *fp;

    printf("___________________________________________________________________________\n\n");
    printf("Enter the price of Bitcoin for the last 7 days:\n");
    printf("[WARNING] Please do not enter values with commas (X 50,000) but you're allowed to add decimal numbers (V 50000.32)\n\n");

    fp = fopen("btcdata.txt", "w");

    while (i < 7) {
        printf("Day %d: ", i + 1);
        scanf("%lf", &price[i]);
        sortedprice[i] = price[i];
        fprintf(fp, "%.2f\n", price[i]);
        i = i + 1;
    }
    fclose(fp);

    i = 0;
    while (i < 6) {
        j = 0;
        while (j < 6) {
            if (sortedprice[j] > sortedprice[j+1]) {
                temp = sortedprice[j];
                sortedprice[j] = sortedprice[j+1];
                sortedprice[j+1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    min = sortedprice[0];
    max = sortedprice[6];

    printf("\n___________________________________________________________________________\n\n");
    printf("Just to make sure we've added your value properly, please mention a random price you've listed:\n");
    scanf("%lf", &searchvalue);

    i = 0;
    while (i < 7) {
        if (sortedprice[i] == searchvalue) found = 1;
        i = i + 1;
    }

    printf("\n");
    if (found == 1) printf("Value confirmed in the data.\n");
    else printf("Value not found in the data.\n");

    i = 1;
    while (i < 7) {
        change = (price[i] - price[i-1]) / price[i-1] * 100;
        changeaverage = changeaverage + change;

        if (change < 0) risk = risk - change;
        else risk = risk + change;

        i = i + 1;
    }

    changeaverage = changeaverage / 6;
    risk = risk / 6;

    printf("\n___________________________________________________________________________\n\n");
    printf("Minimum Price: %.2f\n", min);
    printf("Maximum Price: %.2f\n\n", max);
    printf("Average Change: %.2f%%\n", changeaverage);
    printf("Risk Level: %.2f%%\n", risk);

    printf("\nPREDICTION:\n");
    if (changeaverage > 0 && risk <= 2.0)
        printf("Bitcoin will likely go up (Moderate Risk)\n");
    else if (changeaverage < 0 && risk <= 2.0)
        printf("Bitcoin will likely go down (Moderate Risk)\n");
    else
        printf("Currently, Bitcoin changes too wildly (or not at all) to make a reliable prediction.\n");
}

