#include <stdio.h>
#include <string.h>
#define   MAX_LEN  10                	   /* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
typedef struct student
{
    long num;	/* 每个学生的学号 */
    char name[MAX_LEN];            	/* 每个学生的姓名 */
    float score[COURSE_NUM];	/* 每个学生COURSE_NUM门功课的成绩 */
    float sum;                       /* 每个学生的总成绩 */
    float aver;                   /* 每个学生的平均成绩 */
}STU;
int   Menu(void);
void  ReadScore(STU stu[], int n, int m);
void  AverSumofEveryStudent(STU stu[], int n, int m);
void  AverSumofEveryCourse(STU stu[], int n, int m);
void  SortbyScore(STU stu[],int n,int m,int (*compare)(float a,float b));
int   Ascending(float a, float b);
int   Descending(float a, float b);
void  SwapFloat(float *x, float *y);
void  SwapLong(long *x, long *y);
void  SwapChar(char x[], char y[]);
void  AsSortbyNum(STU stu[], int n, int m);
void  SortbyName(STU stu[], int n, int m);
void  SearchbyNum(STU stu[], int n, int m);
void  SearchbyName(STU stu[], int n, int m);
void  StatisticAnalysis(STU stu[], int n, int m);
void  PrintScore(STU stu[], int n, int m);
main ()
{
    float aver1[MAX_LEN],aver2[MAX_LEN];
    STU stu[MAX_LEN];
    int n,m,i,j,k;
    int choice;
    float sum1[MAX_LEN],sum2[MAX_LEN];
    printf("Input student number(n<30):\n");
    scanf("%d",&n);
    choice=Menu();
    printf("Input course number(m<=6):\n");
    scanf("%d",&m);   /*输入学生人数n,课程总数m*/
    while(1)
    {
        if(choice==0)
         {
             printf("End of program!\n");
             break;
         }
       switch(choice)
       {
        case 1:
        ReadScore(stu,n,m);
        break;
        case 2:
        AverSumofEveryCourse(stu,n,m);
        break;
        case 3:
        AverSumofEveryStudent(stu,n,m);
         break;
         case 4:
         printf("Sort in descending order by score:\n");
         SortbyScore(stu,n,m,Descending);
         PrintScore(stu,n,m);
         break;
         case 5:
         printf("Sort in ascending order by score:\n");
         SortbyScore(stu,n,m,Ascending);
         PrintScore(stu,n,m);
         break;
         case 6:
         AsSortbyNum(stu,n,m);
         PrintScore(stu,n,m);
         break;
         case 7:
         SortbyName(stu,n, m);
         PrintScore(stu,n,m);
         break;
         case 8:
         SearchbyNum(stu,n,m);
         break;
         case 9:
         SearchbyName(stu, n, m);
         break;
         case 10:/*按五个类别对每门课程统计人数和所占百分比*/
         StatisticAnalysis(stu, n, m);
         break;
         case 11:
         SortbyName(stu,n, m);
         PrintScore(stu,n,m);
         break;
         default:
             printf("Input error!\n");

    }
    choice=Menu();
    }
    return 0;
}
int Menu(void)
{
    int choice;
    printf("Management for Students' scores\n");
    printf("1.Input record\n2.Caculate total and average score of every course\n3.Caculate total and average score of every student\n");
    printf("4.Sort in descending order by total score of every student\n5.Sort in ascending order by total score of every student\n");
    printf("6.Sort in ascending order by number\n7.Sort in dictionary order by name\n");
    printf("8.Seach by number\n9.Seach by name\n10.Statistic analysis for every course\n");
    printf("11.List record\n0.Exist\n");
    printf("Please Input your choice:\n");
    scanf("%d",&choice);
    return choice;

}
void ReadScore(STU stu[],int n,int m)
{
    int i,j;
    printf("Input student's ID, name and score:\n");
    for(i=0;i<n;i++)
    {

        scanf("%ld",&stu[i].num);
        scanf("%s",stu[i].name);
        for(j=0;j<m;j++)
        {
           scanf("%f",&stu[i].score[j]);
        }
    }
}
void AverSumofEveryCourse(STU stu[],int n,int m)/*每门课程的总分和平均分*/
{
   int i,j;
   float sum2[STU_NUM];
   float aver2[STU_NUM];
   for(i=0;i<m;i++)
   {
       sum2[i]=0;
       for(j=0;j<n;j++)
       {
           sum2[i] =sum2[i]+stu[j].score[i];
       }
       aver2[i]=sum2[i]/n;
   }
   for(i=0;i<m;i++)
        {
        printf("course %d:sum=%.0f,aver=%.0f\n",i+1,sum2[i],aver2[i]);
        }
}
void AverSumofEveryStudent(STU stu[],int n,int m)/*每个学生的总分和平均分*/
{
   int i,j;
   float sum2[STU_NUM];
   float aver2[STU_NUM];
   for(i=0;i<n;i++)
   {
       sum2[i]=0;
       for(j=0;j<m;j++)
       {
           sum2[i] =sum2[i]+stu[i].score[j];
       }
       aver2[i] = sum2[i]/m;
       stu[i].sum=sum2[i];
       stu[i].aver=aver2[i];
   }
   for(i=0;i<n;i++)
    {
       printf("student %d: sum=%.0f,aver=%.0f\n",i+1,stu[i].sum,stu[i].aver);
    }
}
void  SortbyScore(STU stu[],int n,int m,int (*compare)(float a,float b))
{
    int i,j,k,l;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=k+1;j<n;j++)
        {
            if((*compare)(stu[j].sum,stu[k].sum))
                k = j;
        }
        if(k!=i)
        {
            SwapFloat(&stu[k].sum,&stu[i].sum);
            SwapFloat(&stu[k].aver,&stu[i].aver);
            for(l=0;l<m;l++)
            {
                SwapFloat(&stu[k].score[l],&stu[i].score[l]);
            }
            SwapLong(&stu[k].num,&stu[i].num);
            SwapChar(stu[k].name,stu[i].name);
        }
    }
}
int Ascending(float a, float b)
{
    if(a<b)
    return 1;
    else
    return 0;
}
int Descending(float a, float b)
{
    if(a>b)
    return 1;
    else
    return 0;
}
void  SwapFloat(float *x, float *y)
 {
     float temp;
     temp = *x;
     *x = *y;
     *y = temp;
 }
void  SwapLong(long *x, long *y)
{
     long temp;
     temp = *x;
     *x = *y;
     *y = temp;
}
void  SwapChar(char x[], char y[])
{
    char temp[STU_NUM ];
     strcpy(temp,x);
     strcpy(x ,y);
     strcpy(y ,temp);
}
void  AsSortbyNum(STU stu[], int n, int m)
{
    int i,j,k;
    float sc;
    long temp;
    char a[10];
    printf("Sort in ascending order by number:\n");
    for(i=0;i<n-1;i++)
    {
        temp=stu[i].num;
        for(j=i+1;j<n;j++)
        {
        if(temp>stu[j].num)
        {
            temp = stu[j].num;
            for(k=0;k<m;k++)
            {
             SwapFloat(&stu[i].score[k],&stu[j].score[k]);
            }
         SwapFloat(&stu[i].num,&stu[j].num);
         SwapChar(stu[i].name,stu[j].name);
         SwapFloat(&stu[i].sum,&stu[j].sum);
         SwapFloat(&stu[i].aver,&stu[j].aver);
        }
        }
    }

}
void SortbyName(STU stu[], int n, int m)
{
    int i,j,k;
    float sc;
    char temp[10];
    long a;
    for(i=0;i<n-1;i++)
    {

        for(j=i+1;j<n;j++)
        if(strcmp(stu[i].name,stu[j].name)>0)
        {
            strcpy(temp,stu[j].name);
            strcpy(stu[j].name,stu[i].name);
            strcpy(stu[i].name,temp);
            for(k=0;k<m;k++)
            {
                sc=stu[i].score[k];
                stu[i].score[k]=stu[j].score[k];
                stu[j].score[k]=sc;
            }
            a=stu[i].num;
            stu[i].num=stu[j].num;
            stu[j].num=a;
        }
    }
}
void SearchbyNum(STU stu[],int n,int m)/*输入长整数不相等*/
{
    int i,j,kl=1;
    long num1,k;
    printf("Input the number you want to search:\n");
    scanf(" %ld",&num1);
    float sum2[STU_NUM];
    float aver2[STU_NUM];
    for(i=0;i<n;i++)
    {

        if(num1==stu[i].num)
        {
            kl=0;
            sum2[i]=0;
            for(j=0;j<m;j++)
            {
                sum2[i] =sum2[i]+stu[i].score[j];
            }
            aver2[i] = sum2[i]/m;
            stu[i].sum = sum2[i];
            stu[i].aver = aver2[i];
        }
    }
    for(i=0;i<n;i++)
    {

        if(num1==stu[i].num)
        {

            printf("%ld\t%s\t",stu[i].num,stu[i].name);
            for(j=0;j<m;j++)
            {
                printf("%.0f\t",stu[i].score[j]);
            }
            printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
        }
    }
    if(kl==1)
    {printf("Not found!\n");}
}



void SearchbyName(STU stu[],int n,int m)
{
    int i,j,kl=1;
    char name1[10];
    printf("Input the name you want to search:\n");
    scanf("%s",name1);
    float sum2[STU_NUM];
    float aver2[STU_NUM];
     for(i=0;i<n;i++)
    {
      if(strcmp(stu[i].name,name1)==0)
       {
           kl=0;
           for(j=0;j<m;j++)
       {
           sum2[i] =sum2[i]+stu[i].score[j];
       }
       aver2[i] = sum2[i]/m;
       stu[i].sum = sum2[i];
       stu[i].aver = aver2[i];
       }

    }
    if(kl==1)
    {
        printf("Not found!\n");
    }

    for(i=0;i<n;i++)
    {
        if(strcmp(name1,stu[i].name)==0)
        {
        printf("%ld\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<m;j++)
        {
           printf("%.0f\t",stu[i].score[j]);
        }
           printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
        }
    }
}
void StatisticAnalysis(STU stu[],int n,int m)/*只出现课程一*/
{
    int i,j,k,l,p;
    int count[6]={0};
    float aver[6];
    for(j=0;j<m;j++)
    {
        for(p=0;p<6;p++)
         {
             count[p]=0;
         }
        printf("For course %d:\n",j+1);
        for(i=0;i<n;i++)
        {
            if(stu[i].score[j]<=59)
            {
                count[0]++;
            }
            else if(stu[i].score[j]<=69&&stu[i].score[j]>=60)
            {
                count[1]++;
            }
            else if(stu[i].score[j]<=79&&stu[i].score[j]>=70)
            {
                count[2]++;
            }
             else if(stu[i].score[j]<=89&&stu[i].score[j]>=80)
            {
                count[3]++;
            }
             else if(stu[i].score[j]<=99&&stu[i].score[j]>=90)
            {
                count[4]++;
            }
            else if(stu[i].score[j]==100)
            {
                count[5]++;
            }

        }
        aver[0]=(float)(count[0]*100)/n;
        printf("<60\t%d\t%.2f%%\n",count[0],aver[0]);
         for(k=1;k<=4;k++)
         {
         aver[k]=(float)(count[k]*100)/n;
         }
         for(p=69,k=1;p<=99;p+=10,k++)
         {
           printf("%d-%d\t%d\t%.2f%%\n",p-9,p,count[k],aver[k]);
         }
         aver[5]=(float)(count[5]*100)/n;
         printf("100\t%d\t%.2f%%\n",count[5],aver[5]);

    }
}
void PrintScore(STU stu[],int n,int m)
{
    int i,j;
    float sum2[STU_NUM];
    float aver2[STU_NUM];
    for(i=0;i<n;i++)
    {
       sum2[i]=0;
       for(j=0;j<m;j++)
       {
           sum2[i] =sum2[i]+stu[i].score[j];
       }
       aver2[i] = sum2[i]/m;
       stu[i].sum = sum2[i];
       stu[i].aver = aver2[i];
    }
    for(i=0;i<n;i++)
    {

        printf("%ld\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<m;j++)
        {
           printf("%.0f\t",stu[i].score[j]);
        }
        printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);

    }
}
