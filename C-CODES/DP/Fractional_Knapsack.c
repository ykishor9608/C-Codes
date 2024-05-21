#include <stdio.h>
#include <conio.h>
void simple_fill()
{
    int n, m, i, c[20], v[20];
    int W;
    int cur_w;
    float tot_v;
    int maxi;
    int used[10];
    printf("\n\n\t KNAPSACK PROBLEM SOLUTION IN C\n");
    printf("----------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------\n");
    printf("\n Enter total number of items: ");
    scanf("%d", &n);
    printf("\n Enter the Maximum capacity of the Sack: ");
    scanf("%d", &W);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the weight of the item %d : ", i + 1);
        scanf("%d", &c[i]);
        printf("\n Enter the profit of the item %d : ", i + 1);
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; ++i)
        used[i] = 0;
    cur_w = W;
    while (cur_w > 0)
    {
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maxi == -1) || ((float)v[i] / c[i] > (float)v[maxi] / c[maxi])))
                maxi = i;
        used[maxi] = 1;
        cur_w -= c[maxi];
        tot_v += v[maxi];
        if (cur_w >= 0)
            printf("Added object %d (%d$, %dKg) completly in the bag. Space left: %d.\n", maxi + 1, v[maxi], c[maxi], cur_w);
        else
        {
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", (int)((1 + (float)cur_w / c[maxi]) * 100), v[maxi], c[maxi], maxi + 1);
            tot_v -= v[maxi];
            tot_v += (1 + (float)cur_w / c[maxi]) * v[maxi];
        }
    }
    printf("Filled the bag with objects worth %.2f$.\n", tot_v);
}
int main(int argc, char *argv[])
{
    clrscr();
    simple_fill();
    getch();
    return 0;
}