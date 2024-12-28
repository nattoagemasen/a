#include <stdio.h>
 
#define N 10
#define M 10
 
void average_calc(int data[][2], double mean[], int no);
int max_calc(double mean[], int no);
 
int main(void) {
    char id_num[N][M];
    int n, i;
    while (1) {
        printf("Input the number of data:");
        scanf("%d", &n);
        if (0 < n && n <= N) {
            break;
        } else {
            printf("The number of data is greater than 10 or negative\n");
        }
    }
    for (i = 0; i < n; i++) {
        printf("ID number of data No. %d:", i + 1);
        scanf("%s", id_num[i]);
    }
    printf("Input the data of each ID\n");
 
    int data[N][2];
    double mean[N];
 
    for (i = 0; i < n; i++) {
        printf("%s\n", id_num[i]);
        while (1) {
            printf("Data No. %d-a:", i + 1);
            scanf("%d", &data[i][0]);
            if (0 < data[i][0] && data[i][0] <= 100) {
                break;
            } else {
                printf("Input data is greater than 100 or negative\n");
            }
        }
        while (1) {
            printf("Data No. %d-b:", i + 1);
            scanf("%d", &data[i][1]);
            if (0 < data[i][1] && data[i][1] <= 100) {
                break;
            } else {
                printf("Input data is greater than 100 or negative\n");
            }
        }
    }
    printf("\nInput data:\n");
    for (i = 0; i < n; i++) {
        printf("[%s] (a) %3d (b) %3d\n", id_num[i], data[i][0], data[i][1]);
    }
 
    average_calc(data, mean, n);
    printf("\nThe average value of each data set:\n");
    for (i = 0; i < n; i++) {
        printf("[%s] %.1f\n", id_num[i], mean[i]);
    }
    int maxn;
 
    maxn = max_calc(mean, n);
    printf("\nThe maximum value of the average value is %.1f of %s\n",
           mean[maxn], id_num[maxn]);
 
    return 0;
}
 
void average_calc(int data[][2], double mean[], int no) {
    for (int i = 0; i < no; i++) {
        mean[i] = (data[i][0] + data[i][1]) / 2.0;
    }
}
 
int max_calc(double mean[], int no) {
    int i, maxn, max;
    for (i = 0; i < no; i++) {
        if (mean[i] > max || i == 0) {
            max = mean[i];
            maxn = i;
        }
    }
    return maxn;
}
