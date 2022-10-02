#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
struct punct
{
    float x;
    float y;
};

struct dreptunghi
{
    struct punct sj;
    struct punct ds;
};

float euclid(struct punct a, struct punct b)
{
    float rez;
    rez=sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    return rez;
}

void distantaMax(struct punct v[], int n, float max)
{
    struct punct a,b;
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0; j<=n-1; j++)
        {
            if(euclid(v[i],v[j]) > max)
            {
                max = euclid(v[i],v[j]);
                a = v[i];
                b = v[j];
            }
        }
    }
    printf("Perechea cu distanta cea mai mare este: %f %f ; %f %f",a.x,a.y,b.x,b.y);
}

int apartinere(struct punct a, struct dreptunghi drept)
{
    if(a.x >= drept.sj.x && a.x <= drept.ds.x)
    {
        if(a.y >= drept.sj.y && a.y <= drept.ds.y)
        {
            return 1;
        }
    }
    return 0;
}

float aria(struct dreptunghi drept)
{
    float l1, l2;
    l1 = drept.ds.x-drept.sj.x;
    l2 = drept.ds.y-drept.sj.y;
    return l1*l2;
}

int main()
{
    struct punct a,b,v[100];
    struct dreptunghi drept;
    float rez,max=0,ar;
    int n,apar,cerinta;
    printf("Alegeti ce doriti sa faca acest program:\n1 - Calculul distanței euclidiene dintre două puncte \n2 - Determină perechea de puncte care se află la distanța cea mai mare din o mulțime de puncte \n3 - determină dacă un punct este în interiorul unui dreptunghi sau în afara \n4 -  determinarea ariei deptunghiului");
    scanf("%d",&cerinta);
    if(cerinta == 1)
    {
        printf("Introduceti coordonatele punctului a(x,y): ");
        scanf("%f %f", &a.x,&a.y);
        printf("Introduceti coordonatele punctului b(x,y): ");
        scanf("%f %f", &b.x,&b.y);
        rez=euclid(a,b);
        printf("Distanta euclidiana este: %f",rez);
    }

    if(cerinta == 2)
    {
        printf("introduceti numarul de puncte: ");
        scanf("%d",&n);
        printf("introduceti numerele: ");
        for(int i=0; i<n; i++)
        {
            scanf("%f %f", &v[i].x, &v[i].y);
        }

        distantaMax(v,n,max);
    }

    if(cerinta == 3)
    {
        printf("Introduceti coordonatele punctului din stanga jos a dreptunchiului(x,y): ");
        scanf("%f %f", &drept.sj.x, &drept.sj.y);
        printf("Introduceti coordonatele punctului din dreapta sus a dreptunchiului(x,y): ");
        scanf("%f %f", &drept.ds.x, &drept.ds.y);
        printf("Introduceti coordonatele punctului a(x,y): ");
        scanf("%f %f", &a.x,&a.y);

        apar=apartinere(a,drept);
        if(apar == 1)
        {
            printf("Punctul apartine dreptunghiului");
        }
        if(apar == 0)
        {
            printf("Punctul nu apartine dreptunghiului");
        }
    }

    if(cerinta == 4)
    {
        printf("Introduceti coordonatele punctului din stanga jos a dreptunchiului(x,y): ");
        scanf("%f %f", &drept.sj.x, &drept.sj.y);
        printf("Introduceti coordonatele punctului din dreapta sus a dreptunchiului(x,y): ");
        scanf("%f %f", &drept.ds.x, &drept.ds.y);

        ar = aria(drept);
        printf("Aria este: %f",ar);
    }


    return 0;
}
