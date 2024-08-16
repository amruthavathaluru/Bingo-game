#include<stdio.h>
#include<stdlib.h>
int p1[5][5], p2[5][5],v, i, j,key;
char m1[20],m2[20];
void box1() ;
void box2() ;
void game();
void box1()
{
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("Enter value for[%d%d] pos",i,j) ;
            scanf("%d",&v) ;
            if(v>0 && v<26)
            {
                p1[i][j]=v;
            }
            else
            {
                printf("Enter valid key\n");
                j=j-1;
            }
        }
    }
}
void box2()
{
   for(int i=0;i<5;i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("Enter value for[%d%d]pos",i,j) ;
            scanf("%d", &v) ;
            if(v>0 && v<26)
            {
                p2[i][j]=v;
            }
            else
            {
                 printf("Enter valid key\n");
                j=j-1;
            }
        }
    }
}
void print()
{  
    printf("\n %s \n",m1);
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("| %d |\t", p1[i][j]);
        }
        printf("\n");
    }
    printf("\n %s \n",m2);
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("| %d |\t", p2[i][j]);
        }
        printf("\n") ;
    }
}
void player1()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(p1[i][j]==key)
            {
                p1[i][j]=0;
            }
        }
    }
}
void player2()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(p2[i][j]==key)
            {
                p2[i][j]=0;
            }
        }
    }
   
}
void game()
{
    int c1=0,s1=0,c2=0,s2=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(p1[i][j]==0)
            {
                s1=s1+1;
            }
        }
        if(s1==5)
        {
            c1=c1+1;
        }
        s1=0;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(p1[j][i]==0)
            {
                s1=s1+1;
            }
        }
        if(s1==5)
        {
            c1=c1+1;
        }
        s1=0;
    }
    if(p1[0][0]==0 && p1[1][1]==0 && p1[2][2]==0 && p1[3][3]==0 && p1[4][4]==0)
    {
        c1=c1+1;
    }
    if(p1[0][4]==0 && p1[1][3]==0 && p1[2][2]==0 && p1[3][1]==0 && p1[4][0]==0)
    {
        c1=c1+1;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(p2[i][j]==0)
            {
                s2=s2+1;
            }
        }
        if(s2==5)
        {
            c2=c2+1;
        }
        s2=0;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(p2[j][i]==0)
            {
                s2=s2+1;
            }
        }
        if(s2==5)
        {
            c2=c2+1;
        }
        s2=0;
    }
    if(p2[0][0]==0 && p2[1][1]==0 && p2[2][2]==0 && p2[3][3]==0 && p2[4][4]==0)
    {
        c2=c2+1;
    }
    if(p2[0][4]==0 && p2[1][3]==0 && p2[2][2]==0 && p2[3][1]==0 && p2[4][0]==0)
    {
        c2=c2+1;
    }
    if(c1==5 && c2!=5)
    {
        printf("BINGO!!!!%s is Winner",m1);
        exit(0);
    }
    else if(c2==5 && c1!=5)
    {
        printf("BINGO!!!!%s is Winner",m2);
        exit(0);
    }
    else if(c1==5 && c2==5)
    {
        printf("It's a tie");
    }
    else
    {
        c1=0;
        c2=0;
    }
}
int main()
{
    printf("Enter name for player1\n");
    scanf("%s",m1);
    box1();
    printf("Enter name for player2\n");
    scanf("%s",m2);
    box2();
    print();
    while(1)
    {
        printf("%s's turn\n",m1);
        printf("Enter key to cross");
        scanf("%d",&key);
        player1();
        player2();
        print();
        game();
        printf("%s's turn\n",m2);
        printf("Enter key to cross");
        scanf("%d",&key);
        player2();
        player1();
        print();
        game();
        
    }
    return 0;
} 

