#include<stdio.h>
#include<string.h>

int analyseStock(char name[])
{
    float mp, roe, eps, pe, indPE, debt, div, book, face, pb;
    int budget,score = 0;

    printf("\nEnter Market Price : ");
    scanf("%f", &mp);

    printf("Enter ROE : ");
    scanf("%f", &roe);

    printf("Enter EPS : ");
    scanf("%f", &eps);

    printf("Enter P/E Ratio : ");
    scanf("%f", &pe);

    printf("Enter Industry P/E : ");
    scanf("%f", &indPE);

    printf("Enter Debt to Equity : ");
    scanf("%f", &debt);

    printf("Enter Dividend Yield : ");
    scanf("%f", &div);

    printf("Enter Book Value : ");
    scanf("%f", &book);

    printf("Enter Face Value : ");
    scanf("%f", &face);

    printf("Enter Budget : ");
    scanf("%d", &budget);

    pb = mp / book;

    printf("\n------ STOCK ANALYSIS : %s ------\n", name);

    /* ROE check */

    if (roe >= 20)
    {
        printf("ROE : Very Good\n");
        score = score + 3;
    }
    else if (roe >= 15)
    {
        printf("ROE : Good\n");
        score = score + 2;
    }
    else if (roe >= 10)
    {
        printf("ROE : Average\n");
        score = score + 1;
    }
    else
        printf("ROE : Bad\n");

    /* EPS check */

    if (eps > 20)
    {
        printf("EPS : Strong\n");
        score = score + 3;
    }
    else if (eps > 5)
    {
        printf("EPS : Good\n");
        score = score + 2;
    }
    else if (eps > 0)
    {
        printf("EPS : Weak\n");
        score = score + 1;
    }
    else
        printf("EPS : Do Not Buy\n");

    /* PE comparison */

    if (pe < indPE)
    {
        printf("P/E : Good (Below Industry)\n");
        score = score + 3;
    }
    else if (pe == indPE)
    {
        printf("P/E : Same as Industry\n");
        score = score + 2;
    }
    else if (pe <= indPE + 10)
    {
        printf("P/E : Slightly High\n");
        score = score + 1;
    }
    else
        printf("P/E : Overvalued\n");

    /* Debt check */

    if (debt <= 0.5)
    {
        printf("Debt Level : Very Safe\n");
        score = score + 3;
    }
    else if (debt <= 1)
    {
        printf("Debt Level : Safe\n");
        score = score + 2;
    }
    else if (debt <= 2)
    {
        printf("Debt Level : Risky\n");
        score = score + 1;
    }
    else
        printf("Debt Level : Very Risky\n");

    /* Dividend */

    if (div >= 3)
    {
        score = score + 2;
    }
    else if (div >= 1)
    {
        score = score + 1;
    }

    /* PB ratio */

    printf("P/B Ratio : %.2f\n", pb);

    if (pb <= 3)
    {
        score = score + 3;
    }
    else if (pb <= 5)
    {
        score = score + 2;
    }
    else if (pb <= 8)
    {
        score = score + 1;
    }

    /* stability */

    if (pe <= 50)
    {
        score = score + 3;
    }
    else if (pe <= 70)
    {
        score = score + 1;
    }

    /* valuation */

    if (pe < indPE)
    {
        printf("Stock Valuation : UNDERVALUED\n");
    }
    else if (pe == indPE)
    {
        printf("Stock Valuation : FAIRLY VALUED\n");
    }
    else
        printf("Stock Valuation : OVERVALUED\n");

    printf("\nStock Score : %d / 20\n", score);

    if (score >= 16)
    {
        printf("FINAL DECISION : STRONG BUY\n");
    }
    else if (score >= 12)
    {
        printf("FINAL DECISION : BUY\n");
    }
    else if (score >= 8)
    {
        printf("FINAL DECISION : RISKY\n");
    }
    else
        printf("FINAL DECISION : DO NOT BUY\n");

    if (roe >= 15 && debt <= 1 && eps > 0)
    {
        printf("Suitable for LONG TERM investment\n");
    }
    else if (eps > 0 && pe < indPE)
    {

        printf("Suitable for SHORT TERM investment\n");
    }
    else
        printf("Not recommended to buy\n");

    int shares = budget / mp;

    printf("You can buy approximately %d shares\n", shares);

    return score;
}

int main()
{
    int choice;
    int n;
    char name[50];

    char stockName[20][50];
    int score[20];

    printf("===== STOCK ANALYZER =====\n");
    printf("1. Analyse Stock\n");
    printf("2. Compare Stocks\n");

    printf("Enter choice : ");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:

        printf("Enter Stock Name : ");
        scanf("%s", name);

        analyseStock(name);

        break;

    case 2:

        printf("How many stocks you want to compare : ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            printf("\nEnter Stock Name : ");
            scanf("%s", stockName[i]);

            score[i] = analyseStock(stockName[i]);
        }

        int best = 0;

        for (int i = 1; i < n; i++)
        {
            if (score[i] > score[best])
                best = i;
        }

        printf("\n=========== FINAL COMPARISON ===========\n");
        printf("BEST STOCK IS : %s\n", stockName[best]);
        printf("Score : %d / 20\n", score[best]);
        printf("========================================\n");

        break;

    default:
        printf("Invalid choice");
    }

    return 0;
}
