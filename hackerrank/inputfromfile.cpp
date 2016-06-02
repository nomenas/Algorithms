#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main1(){

#ifdef FILEINPUT
    freopen("input.dat","r",stdin);
#endif

    int n;
    scanf("%d",&n);
    long long int sum = 0;
    for(int arr_i = 0; arr_i < n; arr_i++){
        int value = 0;
        scanf("%d",&value);
        sum += value;
    }
    printf("%lld\n", sum);
    return 0;
}

