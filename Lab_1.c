#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    bool test = true;
    int x;
    while(test)
    {
        double a,b,c,d,x1,x2;

        printf("Введите a: ");
        scanf("%lf",&a);
        printf("Введите b: ");
        scanf("%lf",&b);
        printf("Введите c: ");
        scanf("%lf",&c);

        d = b*b - 4*a*c;

        printf("d = %lf", d);
        printf("d = %lf\n", d);

        x1 = (-b+sqrt(d))/(2*a);
        x2 = (-b-sqrt(d))/(2*a);
        printf("x1=%lf x2=%lf\n",x1,x2);

        if (d>0)
        {
            x1 = (-b+sqrt(d))/(2*a);
            x2 = (-b-sqrt(d))/(2*a);
            printf("x1=%lf x2=%lf\n",x1,x2);
        }
        if (d==0)
        {
            x1 = (-b/(2*a));
            printf("x1=%lf\n",x1);
        }
    
        if (d<0) 
            printf("Корне нет\n");

        printf("Желаете продолжить? 5-да, 4-нет");    
        scanf("%d", &x);    
        if(x > 5 || x < 5)
            test = false;
    }
    return 0;
}
