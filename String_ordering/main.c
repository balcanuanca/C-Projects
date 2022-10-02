#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordonare(char **a, int cuvinte,int (*comp)(char *, char *))
{
    char *v;
    for(int i=0; i< cuvinte-1; i++)
    {
        int rez = comp(a[i],a[i+1]);
        if(rez>0)
        {
            *v=a[i];
            a[i]=a[i+1];
            a[i+1]=*v;
        }
    }
}

int compLex(char *s1, char *s2)
{
    return strcmp(s1,s2);
}

int compLen(char *s1, char *s2)
{
    if(strlen(s1) < strlen(s2))
        return -1;
    else if (strlen(s1) > strlen(s2))
        return 1;
    else return 0;
}

int main()
{
    int n = 100,i=0,m=100,l,ord;
    char s[n],**a, cuvinte_citete = 0;

    printf("Introduceti cuvintele:\n");
    fgets(s,n,stdin);
    while(strcmp(s, "gata\n"))
    {
        cuvinte_citete++;

        a = (char **)realloc(a,cuvinte_citete*sizeof(char *));
        a[cuvinte_citete-1] = malloc((strlen(s)+1)*sizeof(char));

        strcpy(a[cuvinte_citete-1],s);

        fgets(s,n,stdin);
    }

    printf("Introduceti metoda de ordonare dorita: \n1. Dupa lungime \n2.Alfabetic \n");
    scanf("%d",&ord);

    if(ord == 1)
    {
        ordonare(a, cuvinte_citete, compLen);
    }
    if(ord == 2)
    {
        ordonare(a, cuvinte_citete, compLex);
    }

    for(i=0;i<=cuvinte_citete-1;i++)
    {
        printf("%s",a[i]);
    }
    return 0;
}
