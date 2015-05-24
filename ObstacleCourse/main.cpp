#include <stdio.h>
#include <math.h>
#define max(a,b)	 (a>b?a:b)
#define D(a,b)	 ((a-b)*(a-b))
#define Q(a,b)	 (a*a+b*b)

int main()
{
int fall, n, i, r, R, temp, bio[500];
long long x[500],y[500];
double d[500], min[501], tt;

for(scanf("%d",&fall); fall--; printf("%.3lf\n",sqrt(min[n])))
    {
    for(i=!scanf("%d %d %d",&r,&R,&n)-1; ++i<n; scanf("%lld %lld",x+i,y+i),tt=sqrt(Q(x[i],y[i])),d[i]=D(R,tt),min[i]=D(tt,r)+(bio[i]=0));
    for(min[n]=D(R,r)+(bio[n]=0);;min[n]=((tt=max(min[temp],d[temp]))<min[n])?tt:min[n])
        {
        for(i=temp=-1; ++i<=n; temp=(!bio[i]&&(temp==-1||min[temp]>min[i]))?i:temp);
        if(temp==n)
            break;
        for(i=-(bio[temp]=1); ++i<n; min[i]=(!bio[i]&&min[temp]>(tt=Q((x[temp]-x[i]),(y[temp]-y[i]))))?min[temp]:((!bio[i]&&tt<min[i])?tt:min[i]));
        }
    }

return 0;
}

/*
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

typedef std::pair<int, int> Point;
typedef std::map<double, std::vector<Point> > Points;

int main(int, const char**)
{
    int T = 0;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int r = 0;
        int R = 0;
        scanf("%d %d", &r, &R);
        
        int N = 0;
        scanf("%d", &N);

        Points points;
        for (int i = 0; i < N; ++i)
        {
            int x = 0;
            int y = 0;
            scanf("%d %d", &x, &y);

            double radii = 0;
            if (x > 0 && y >= 0)
            {
                radii = atan(double(y) / x);
            }
            else if (x <= 0 && y > 0)
            {
                radii = M_PI_2 + atan(double(-x) / y);
            }
            else if (y == 0)
            {
                radii = M_PI;
            }
            else if (x < 0 && y <= 0)
            {
                radii = M_PI + atan(double(y) / x);
            }
            else if (x >= 0 && y < 0)
            {
                radii = M_PI_2 + M_PI + atan(double(x) / -y);
            }
            points[radii].push_back(Point(x, y));
            printf("%f\n", radii);
        }
    }
    
    
    
    return 0;
}
*/
