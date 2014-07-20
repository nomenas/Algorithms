#include <cstdio>
#include <algorithm>
using namespace std;

int N;
double pos[10000], T;

double solve(){
    double res=0;
    double p=pos[0];
    for(int i=1; i<N; i++){
        p+=T;
        res=max(res, p-pos[i]);
        p=max(p, pos[i]);
    }
    res/=2;
    printf("%f, %f\n", res, pos[0]);
    if(res>pos[0]){
        p=0;
        for(int i=1; i<N; i++){
            p+=T;
            printf("%f, %f, %f\n", pos[i], res, p);
            if(pos[i]-res>p)
                break;

            res=max(res, p-pos[i]);
            printf("res = %f\n", res);
        }
    }
    return res;
}

int main(){
    int K;
    for(scanf("%d", &K); K--; ){
        scanf("%d %lf", &N, &T);
        for(int i=0; i<N; i++)
            scanf("%lf", pos+i);
        printf("%.4lf\n", solve());
    }
    return 0;
}