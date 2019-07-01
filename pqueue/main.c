#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define max 20
struct pq
{
    int item[max],f,r;
};
void pq_init(struct pq *);
void insert(struct pq *,int);
int is_empty(struct pq *);
int is_full(struct pq *);
int deque(struct pq *);
void pq_init(struct pq *p)
{
    p->f=-1;
    p->r=-1;
}
int is_empty(struct pq *p)
{
    if(p->r==p->f)
        return 1;
    else
        return 0;
}
int is_full(struct pq *p)
{
    if(p->r>=max)
        return 1;
    else
        return 0;
}
void insert(struct pq *p,int x)
{
    if(is_full(p))
    printf("\tQueue Overflow\n");
    else
    {
     p->r++;
     p->item[p->r]=x;
    }
    }
    int deque(struct pq *p)
    {
        int c,i,maxi=p->item[0];
        if(is_empty(p))
            printf("\tQueue Underflow\n");
        else
        {
            for(i=0;i<=p->r;i++)
            {
                if(p->item[i]>=maxi)
                {
                maxi=p->item[i];
                c=i;
                }
            }
            for(c;c<=p->r-1;c++)
            {
                p->item[c]=p->item[c+1];
            }


            return maxi;
        }
    }
void main()
{
    system("cls");

    struct pq p;
    pq_init(&p);
    insert(&p,10);
    insert(&p,2);
    insert(&p,12);
    insert(&p,19);
     insert(&p,1);
    printf("\nDEQUE=%d",deque(&p));
    printf("\nDEQUE=%d",deque(&p));
    printf("\nDEQUE=%d",deque(&p));
    printf("\nDEQUE=%d",deque(&p));
    getch();
}
