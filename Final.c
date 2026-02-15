#include<stdio.h>
#include<string.h>
/* 
        {'*','-','-','*','-','-','*'},
        {'-','*','-','*','-','*','-'},
        {'-','-','*','*','*','-','-'},
        {'*','*','*',' ','*','*','*'},
        {'-','-','*','*','*','-','-'},
        {'-','*','-','*','-','*','-'},
        {'*','-','-','*','-','-','*'},

        diagonal  4
     2   0,0     1,1     2,2
     3   2,4     1,5     0,6
     5   6,0     5,1     4,2         
     7   4,4     5,5     6,6
        
        vertical   8
     11   0,0     3,0     6,0       y,y == 3,y == 6-y,y 
     13   1,1     3,1     5,1
     17   2,2     3,2     4,2
     19   0,3     1,3     2,3
     23   4,3     5,3     6,3         
     29   2,4     3,4     4,4
     31   1,5     3,5     5,5
     37   0,6     3,6     6,6 

	    horizontal   8
     41   0,0     0,3     0,6       x,x==x,3==x,6-x  
     43   1,1     1,3     1,5
     47   2,2     2,3     2,4
     53   3,0     3,1     3,2     
     59   3,4     3,5     3,6         
     61   4,2     4,3     4,5
     67   5,1     5,3     5,5
     71   6,0     6,3     6,6
*/

void checkx(int* x)
{
    if(*x<0||*x>6)
{
    do
    {
        printf("Incorrect place, please enter rotation X again: ");
        scanf("%d", &*x);
    }while(*x<0||*x>6);
    
}

}
void checky(int rotationx, int* rotationy)
{

if(rotationx==3 && *rotationy==3)
{
    do
    {
        printf("Incorrect place, please enter rotation Y again: ");
        scanf("%d", &*rotationy);
    }while(rotationx==3 && *rotationy==3);
}
if(rotationx==0||rotationx==6)
{
    if(*rotationy == 0||*rotationy == 3||*rotationy == 6)
    {
        
    }
    else
    {
        do{
            printf("Incorrect place, please enter rotation Y again: ");
            scanf("%d", &*rotationy);
        }while(*rotationy<0 || *rotationy>=1 && *rotationy<3 || *rotationy>=4 && *rotationy<=5 ||*rotationy>6);
    }
}
if(rotationx==1||rotationx==5)
{
    if(*rotationy == 1||*rotationy == 3||*rotationy == 5)
    {
        
    }
    else
    {
        do
        {
            printf("Incorrect place, please enter rotation Y again: ");
            scanf("%d", &*rotationy);
        }while(*rotationy<1 || *rotationy==2 || *rotationy==4 ||*rotationy>5);
    }
}
if(rotationx==2||rotationx==4)
{
    if(*rotationy == 2||*rotationy == 3||*rotationy == 4)
    {
        
    }
    else
    {
        do
        {
            printf("Incorrect place, please enter rotation Y again: ");
            scanf("%d", &*rotationy);
        }while(*rotationy<2 ||*rotationy>4);
    }
}
}

void checkbin(char foo[][7], int* x, int* y)
{
    int a=0;
    do
    {
        if(foo[*x][*y]=='1' || foo[*x][*y]=='2')
        {
            printf("This place is full please enter another one, X: ");
            scanf("%d", &*x);
            checkx(&*x);
            printf("And rotation Y: ");
            scanf("%d", &*y);
            checky(*x,&*y);
        }
        else
            a=1;
    }while(a==0);
}

void checkrewrite(int*x,int*y)
{
    int a=0;
    do
    {
        if(*y==9)
        {
            printf("Please enter rotation X: ");
            scanf("%d",&*x);
            checkx(&*x);
            printf("Rotation Y (Enter 9 for new X value): ");
            scanf("%d",&*y);
        }
        else
            a=1;
    }while(a==0);
}

/*
    There are 20 if here.
    A prime number is defined within each if condition, and these prime numbers ensure that each if condition runs only once.
*/

void point(char foo[][7], int x, int y, int* point1, int *point2, int *bin1, int *bin2,int* unique)
{
    if(*unique%2==0)
    {}
    else
    {
        if((foo[x][y]==foo[0][0] && foo[x][y]==foo[1][1] && foo[x][y]==foo[2][2] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 2;
        }
        else if((foo[x][y]==foo[0][0] && foo[x][y]==foo[1][1] && foo[x][y]==foo[2][2] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 2;
        }
    }
    if(*unique%3==0)
    {}
    else
    {
        if((foo[x][y]==foo[2][4] && foo[x][y]==foo[1][5] && foo[x][y]==foo[0][6] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 3;
        }
        else if((foo[x][y]==foo[2][4] && foo[x][y]==foo[1][5] && foo[x][y]==foo[0][6] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 3;
        }
    }
    if(*unique%5==0)
    {}
    else
    {
        if((foo[x][y]==foo[6][0] && foo[x][y]==foo[5][1] && foo[x][y]==foo[4][2] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 5;
        }
        else if((foo[x][y]==foo[6][0] && foo[x][y]==foo[5][1] && foo[x][y]==foo[4][2] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 5;
        }
    }
    if(*unique%7==0)
    {}
    else
    {
        if((foo[x][y]==foo[6][6] && foo[x][y]==foo[5][5] && foo[x][y]==foo[4][4] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 7;
        }
        else if((foo[x][y]==foo[6][6] && foo[x][y]==foo[5][5] && foo[x][y]==foo[4][4] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 7;
        }
    }
    if(*unique%11==0)
    {}
    else
    {
        if((foo[x][y]==foo[0][0] && foo[x][y]==foo[3][0] && foo[x][y]==foo[6][0] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 11;
        }
        else if((foo[x][y]==foo[0][0] && foo[x][y]==foo[3][0] && foo[x][y]==foo[6][0] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 11;
        }
    }
    if(*unique%13==0)
    {}
    else
    {
        if((foo[x][y]==foo[3][1] && foo[x][y]==foo[1][1] && foo[x][y]==foo[5][1] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 13;
        }
        else if((foo[x][y]==foo[3][1] && foo[x][y]==foo[1][1] && foo[x][y]==foo[5][1] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 13;
        }
    }
    if(*unique%17==0)
    {}
    else
    {
        if((foo[x][y]==foo[4][2] && foo[x][y]==foo[3][2] && foo[x][y]==foo[2][2] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 17;
        }
        else if((foo[x][y]==foo[4][2] && foo[x][y]==foo[3][2] && foo[x][y]==foo[2][2] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 17;
        }
    }
    if(*unique%19==0)
    {}
    else
    {
        if((foo[x][y]==foo[0][3] && foo[x][y]==foo[1][3] && foo[x][y]==foo[2][3] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 19;
        }
        else if((foo[x][y]==foo[0][0] && foo[x][y]==foo[1][1] && foo[x][y]==foo[2][2] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 19;
        }
    }
    if(*unique%23==0)
    {}
    else
    {
        if((foo[x][y]==foo[4][3] && foo[x][y]==foo[5][3] && foo[x][y]==foo[6][3] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 23;
        }
        else if((foo[x][y]==foo[4][3] && foo[x][y]==foo[5][3] && foo[x][y]==foo[6][3] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 23;
        }
    }
    if(*unique%29==0)
    {}
    else
    {
        if((foo[x][y]==foo[2][4] && foo[x][y]==foo[3][4] && foo[x][y]==foo[4][4] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 29;
        }
        else if((foo[x][y]==foo[2][4] && foo[x][y]==foo[3][4] && foo[x][y]==foo[4][4] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 29;
        }
    }
    if(*unique%31==0)
    {}
    else
    {
        if((foo[x][y]==foo[5][5] && foo[x][y]==foo[1][5] && foo[x][y]==foo[3][5] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 31;
        }
        else if((foo[x][y]==foo[5][5] && foo[x][y]==foo[1][5] && foo[x][y]==foo[3][5] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 31;
        }
    }
    if(*unique%37==0)
    {}
    else
    {
        if((foo[x][y]==foo[0][6] && foo[x][y]==foo[3][6] && foo[x][y]==foo[6][6] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 37;
        }
        else if((foo[x][y]==foo[0][6] && foo[x][y]==foo[3][6] && foo[x][y]==foo[6][6] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 37;
        }
    }
    if(*unique%41==0)
    {}
    else
    {
        if((foo[x][y]==foo[0][0] && foo[x][y]==foo[0][3] && foo[x][y]==foo[0][6] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 41;
        }
        else if((foo[x][y]==foo[0][0] && foo[x][y]==foo[0][3] && foo[x][y]==foo[0][6] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 41;
        }
    }
    if(*unique%43==0)
    {}
    else
    {
        if((foo[x][y]==foo[1][3] && foo[x][y]==foo[1][1] && foo[x][y]==foo[1][5] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 43;
        }
        else if((foo[x][y]==foo[1][3] && foo[x][y]==foo[1][1] && foo[x][y]==foo[1][5] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 43;
        }
    }
    if(*unique%47==0)
    {}
    else
    {
        if((foo[x][y]==foo[2][4] && foo[x][y]==foo[2][3] && foo[x][y]==foo[2][2] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 47;
        }
        else if((foo[x][y]==foo[2][4] && foo[x][y]==foo[2][3] && foo[x][y]==foo[2][2] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 47;
        }
    }
    if(*unique%53==0)
    {}
    else
    {
        if((foo[x][y]==foo[3][0] && foo[x][y]==foo[3][1] && foo[x][y]==foo[3][2] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 53;
        }
        else if((foo[x][y]==foo[3][0] && foo[x][y]==foo[3][1] && foo[x][y]==foo[3][2] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 53;
        }
    }
    if(*unique%59==0)
    {}
    else
    {
        if((foo[x][y]==foo[3][4] && foo[x][y]==foo[3][5] && foo[x][y]==foo[3][6] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 59;
        }
        else if((foo[x][y]==foo[3][4] && foo[x][y]==foo[3][5] && foo[x][y]==foo[3][6] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 59;
        }
    }
    if(*unique%61==0)
    {}
    else
    {
        if((foo[x][y]==foo[4][5] && foo[x][y]==foo[4][3] && foo[x][y]==foo[4][2] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 61;
        }
        else if((foo[x][y]==foo[4][5] && foo[x][y]==foo[4][3] && foo[x][y]==foo[4][2] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 61;
        }
    }
    if(*unique%67==0)
    {}
    else
    {
        if((foo[x][y]==foo[5][3] && foo[x][y]==foo[5][1] && foo[x][y]==foo[5][5] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 67;
        }
        else if((foo[x][y]==foo[5][3] && foo[x][y]==foo[5][1] && foo[x][y]==foo[5][5] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 67;
        }
    }
    if(*unique%71==0)
    {}
    else
    {
        if((foo[x][y]==foo[6][0] && foo[x][y]==foo[6][3] && foo[x][y]==foo[6][6] && foo[x][y]=='1'))
        {
            printf("\n1.Player gets a point!\n\n");
            *point1 = *point1 + 1;
            *bin2 = *bin2 + 1;
            *unique = *unique * 71;
        }
        else if((foo[x][y]==foo[6][0] && foo[x][y]==foo[6][3] && foo[x][y]==foo[6][6] && foo[x][y]=='2'))
        {
            printf("\n2.Player gets a point !\n\n");
            *point2 = *point2 + 1;
            *bin1 = *bin1 + 1;
            *unique = *unique * 71;
        }
    }
}


void printarr(char foo[][7])
{
    for(int i =0; i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            printf("%3c",foo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    char arr[7][7]={
        {'*','-','-','*','-','-','*'},
        {'-','*','-','*','-','*','-'},
        {'-','-','*','*','*','-','-'},
        {'*','*','*',' ','*','*','*'},
        {'-','-','*','*','*','-','-'},
        {'-','*','-','*','-','*','-'},
        {'*','-','-','*','-','-','*'},
        };
    printarr(arr);
    int bin1=0, bin2=0;
    int point_1=0, point_2=0;
    int rotationx, rotationy;
    int turn=1;
    int round=0;
    int unique=1;
    do{
        int player=1;

        if(bin1<12){
            printf("%d. Turn \n%d. Player's turn please enter a rotation X (0 to 6): ",turn, player);
            scanf("%d", &rotationx);
            checkx(&rotationx);

            printf("Rotation Y (Enter 9 for new X value): ");
            scanf("%d",&rotationy);

            checkrewrite(&rotationx,&rotationy);
            checky(rotationx,&rotationy);
            checkbin(arr,&rotationx,&rotationy);

            arr[rotationx][rotationy]='1';
            bin1++;
            point(arr, rotationx, rotationy, &point_1, &point_2, &bin1, &bin2, &unique);
            player ++;
            turn ++;
            printf("Remaining bin number--> 1. Player= %d, 2. Player= %d",12-bin1, 12-bin2);
            printf("\nPoints:\n1. Player = %d \n2. Player = %d\n", point_1, point_2);
        }
        
        if(bin2<12){
            printf("\n");
            printarr(arr);
            printf("%d. Turn \n%d. Player's turn please enter a rotation X: ",turn, player);
            scanf("%d", &rotationx);
            checkx(&rotationx);

            printf("Rotation Y (Enter 9 for new X value): ");
            scanf("%d",&rotationy);

            checkrewrite(&rotationx,&rotationy);
            checky(rotationx,&rotationy);
            checkbin(arr,&rotationx,&rotationy);

            arr[rotationx][rotationy]='2';
            bin2++;
            point(arr, rotationx, rotationy, &point_1, &point_2, &bin1, &bin2, &unique);
            player --;
            turn ++;
            printf("Remaining bin number--> 1. Player= %d, 2. Player= %d",12-bin1, 12-bin2);
            printf("\nPoints:\n1. Player = %d \n2. Player = %d\n", point_1, point_2);
        }

        printf("\n");
        printarr(arr);
        round=bin1+bin2;
    }while(round<24);
    printf("\nGame Over 1.Player: %d, 2. Player: %d\n", point_1, point_2);
    if(point_1>point_2)
    {
        printf("\t1. Player won the game!!! ");
    }
    else if(point_2>point_1)
    {
        printf("\t2. Player won the game!!!");
    }
    else
    {
        printf("\tDraw!!!");
    }
}