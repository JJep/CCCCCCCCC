//
//  main.c
//  Exp
//
//  Created by Jep Xia on 2017/12/5.
//  Copyright © 2017年 Jep Xia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXTRACKNUM (50+1) //磁道号序列最大长度
#define LENGTH sizeof(struct TRACK)
struct TRACK  //磁道链表
{
    struct TRACK *pre;
    int num; //磁道号
    struct TRACK *next;
};

int trackarray[MAXTRACKNUM]; //磁道号序列，-1为磁道序列结束

struct TRACK* track_sort();  //按磁道号大小加入磁道链表排序
int FCFS(int array[]);        //先来先服务
// array: 需寻道的磁道号序列
int SSTF(struct TRACK *head, int now); //最短寻道时间优先
//head: 磁道链表链头指针，now: 当前磁头位置
int SCAN(struct TRACK *head,int now,int direction); //扫描(电梯)算法
//head: 磁道链表链头指针
int CSCAN(struct TRACK *head,int now,int direction); //扫描(电梯)算法
//now: 当前磁头位置
//direction: 当前磁头方向3、参考代码

//主函数代码
int main()
{
    struct TRACK *head;  //磁道链表链头指针
    int seektime=0;
    int i,direction=0;
    int ch, select;
    printf("\n随机产生磁道序列.... \n");
    srand( (unsigned)time( NULL ) );
    for(i=0;i<MAXTRACKNUM-1;i++)
    {
        trackarray[i]=rand();
        trackarray[i] = trackarray[i] / 1000000;
        printf("%d\t", trackarray[i]);
        if((i+1) % 5 == 0)printf("\n");
    }
    trackarray[MAXTRACKNUM-1]=-1;
    head=track_sort();

Menu:
    printf("按任意键继续...\n");
    getchar();
    printf("       磁盘调度模拟系统\n");
    printf("   1-----先来先服务\n");
    printf("   2-----最短寻道时间优先\n");
    printf("   3-----扫描(电梯)算法\n");
    printf("   4-----循环扫描算法\n");
    printf("   5-----退出系统\n");
    printf("请选择:");
    
Input:
    select=getchar();
    if(select<'1' || select>'4')
    {
        if(select==27)
        {
            printf("\n\n");
            goto Exit;
        }
        
        goto Input;
    }
    putchar(select);
    if(getchar()==8) //backsapce key
    {
        putchar(8); putchar(' '); putchar(8);
        goto Input;
    }
    printf("\n\n");
    
    switch(select)
    {
        case '1':
            goto FCFS;
        case '2':
            goto SSTF;
        case '3':
            goto SCAN;
        case '4':
            goto CSCAN;
        case '5':
            goto Exit;
    }
    
FCFS:
    seektime=FCFS(trackarray);/*              */
    printf("FCFS算法平均寻道距离: %.2f 条磁道\n",seektime/100.);
    goto Menu;
SSTF:
    seektime=SSTF(head,trackarray[0]);
    printf("SSTF算法平均寻道距离: %2.f 条磁道\n",seektime/100.);
    goto Menu;
SCAN:
    printf("正方向寻道(Y/N)? ");
    direction=getchar();
    putchar(direction);
    seektime=SCAN(head,trackarray[0],direction);
    printf("SCAN算法平均寻道距离: %.2f 条磁道\n",seektime/100.);
    goto Menu;
CSCAN:
    printf("正方向寻道(Y/N)? ");
    direction=getchar();
    putchar(direction);
    seektime=CSCAN(head,trackarray[0],direction);
    printf("SCAN算法平均寻道距离: %.2f 条磁道\n",seektime/100.);
    goto Menu;
Exit:
    printf("\n确定退出吗?(Y/N)");
    ch=getchar();
    putchar(ch);
    if(ch=='Y' || ch=='y')
    {
        printf("\n谢谢使用本系统!\n");
        printf("按任意键退出本系统...");
        getchar();
        exit(0);
    }
}

struct TRACK* track_sort() {
    int array[MAXTRACKNUM];
    for (int k = 0; k < MAXTRACKNUM; k++)
        array[k] = trackarray[k];
    
    int i = 0,j = 0;
    for (i = 0; i < MAXTRACKNUM-1; i++) {
        for (j = i; j < MAXTRACKNUM-1; j++) {
            if (array[j]<array[i]) {
                int value = array[i];
                array[i] = array[j];
                array[j] = value;
            }
        }
    }
    printf("排序后的磁道序列...\n");
    int value = array[0];
    for(i=0;i<MAXTRACKNUM-1;i++)
    {
        printf("%d\t", array[i]);
        if((i+1) % 5 == 0)printf("\n");
        if (i > 0) {
            if (array[i] == value) {
                exit(3);
            } else {
                value = array[i];
            }
        }
    }

    struct TRACK *p,*H,*r;
    H=(struct TRACK *)malloc(sizeof(struct TRACK));
    H->pre = NULL;
    H->num = 0;
    r = H; //初始化r
    for(i=0;i<MAXTRACKNUM-1;i++){
        p=(struct TRACK*)malloc(sizeof(struct TRACK));
        p->pre = r;
        p->num=array[i];
        r->next=p;
        
        r=p;
    } 
    r->next=NULL; 
    return (H);
}

//先来先服务，array: 需寻道的磁道号序列
int FCFS(int array[])
{
    int i,j,sum=0;
    printf("\nFCFS算法寻道...\n");
    for(i=0;array[i]!=-1;i++)
    {
        printf("%d\t",array[i]);
        if((i+1)%5 == 0)printf("\n");
    }
    i=0;
    for(i=0,j=1;array[j]!=-1;i++,j++)
    {
        if(array[i]>array[j])   sum+=(array[i]-array[j]);
        else sum+=(array[j]-array[i]);
    }
    return(sum);
}

////最短寻道时间优先，head: 磁道链表链头指针，now: 当前磁头位置
int SSTF(struct TRACK *head, int now)
{
    struct TRACK *p,*lp,*rp;
    int i=0,sum=0,front,behind;
    p=head;
    printf("\nSSTF算法寻道...\n");
    while(p->num!=now) p=p->next; //查找当前磁道
    lp=p->pre;
    rp=p->next;
    do
    {
        if(p->next!=NULL&&p->pre!=NULL)
        {
            front=p->num-lp->num;
            behind=rp->num-p->num;
            if(front>=behind)
            {
                sum+=behind;
                p=rp;
                printf(" %d ",p->num);
                i++;
                if((i+1)%5 == 0)printf("\n");
                rp=p->next;
            }
            else
            {
                sum+=front;
                p=lp;
                printf(" %d ",p->num);
                i++;
                if((i+1)%5 == 0)printf("\n");
                lp=p->pre;
            }
        }
        else
        {
            if(p->next==NULL)
            {
                while(lp!=NULL&&lp->num!=0)
                {
                    sum+=p->num-lp->num;
                    p=lp;
                    printf(" %d ",p->num);
                    i++;
                    if((i+1)%5 == 0)printf("\n");
                    lp=p->pre;
                }
                return(sum);
            }
            if(p->pre==NULL)
            {
                while(rp!=NULL&&rp->num!=0)
                {
                    sum+=rp->num-p->num;
                    p=rp;
                    printf(" %d ",p->num);
                    i++;
                    if((i+1)%5 == 0)printf("\n");
                    rp=p->next;
                }
                return(sum);
            }
        }
    }while(p->next!=NULL||p->pre!=NULL);

    return 0;
}

//扫描(电梯)算法，head: 磁道链表链头指针，now: 当前磁头位置，direction: 当前磁头方向
int SCAN(struct TRACK *head,int now,int direction)
{
    struct TRACK *p,*pp;
    int i=0, sum=0;
    printf("\nSCAN算法寻道...\n");
    p=head;
    while(p->num!=now)   p=p->next;/*   找到当前磁头的位置    */
    pp=p;
    if(direction=='y'||direction=='Y')
    {
        while(pp->next!=NULL)
        {
            sum+=pp->next->num - pp->num; //两个相邻磁头指针的距离
            pp=pp->next;
            printf(" %d ",pp->num);
            i++;
            if((i+1)%5 == 0)printf("\n");
        }
        sum+=pp->num -p->pre->num;
        pp=p->pre;
        if(pp->num==0) return(sum);
        else
        {
            while(pp->pre!=NULL)
            {
                sum+=pp->num-pp->pre->num;
                printf(" %d ",pp->num);
                i++;
                if((i+1)%5 == 0)printf("\n");
                pp=pp->pre;
            }
            printf(" %d ",pp->num);
            i++;
            if((i+1)%5 == 0)printf("\n");
            return(sum);
        }
    }
    else //direction=='n'|direction=='N'
    {
        while(pp->pre!=NULL)
        {
            sum+=pp->num-pp->pre->num;
            pp=pp->pre;
            printf(" %d ",pp->num);
            i++;
            if((i+1)%5 == 0)printf("\n");
        }
        sum+=p->next->num-pp->num;
        pp=p->next;
        if(pp->num==0) return(sum);
        else
        {
            while(pp->next!=NULL)
            {
                sum+=pp->next->num-pp->num;
                printf(" %d ",pp->num);
                i++;
                if((i+1)%5 == 0)printf("\n");
                pp=pp->next;
            }
            printf(" %d ",pp->num);
            i++;
            if((i+1)%5 == 0)printf("\n");
            return(sum);
        }
    }
}

//扫描(电梯)算法，head: 磁道链表链头指针，now: 当前磁头位置，direction: 当前磁头方向
int CSCAN(struct TRACK *head,int now,int direction)
{
    struct TRACK *p,*pp,*flag;
    int i=0, sum=0;
    printf("\nCSCAN算法寻道...\n");
    p=head;
    while(p->num!=now)   p=p->next;/*   找到当前磁头的位置    */
    flag = p;
    pp=p;
    if(direction=='y'||direction=='Y')
    {
        while(pp->next!=NULL)
        {
            sum+=pp->next->num - pp->num; //两个相邻磁头指针的距离
            pp=pp->next;
            printf(" %d ",pp->num);
            i++;
            if((i+1)%5 == 0)printf("\n");
        }
        if (head->num == now) return (sum);
        else
        {
            sum+= pp->num - head->num ;
            pp=head;
            while(pp->next!=p)
            {
                sum+=pp->next->num-pp->num;
                printf(" %d ",pp->num);
                i++;
                if((i+1)%5 == 0)printf("\n");
                pp=pp->next;
            }
            printf(" %d ",pp->num);
            i++;
            if((i+1)%5 == 0)printf("\n");
            return(sum);
        }
    }
    else //direction=='n'|direction=='N'
    {
        struct TRACK* nail;
        nail = head;
        while (nail->next!=NULL) {
            nail = nail -> next;
        }
        while(pp->pre!=NULL)
        {
            sum+=pp->num-pp->pre->num;
            pp=pp->pre;
            printf(" %d ",pp->num);
            i++;
            if((i+1)%5 == 0)printf("\n");
        }
        if(nail->num==now) return(sum);
        else
        {
            sum+=nail->num-pp->num;
            pp=nail;
            while(pp->next!=p)
            {
                sum+=pp->num-pp->pre->num;
                printf(" %d ",pp->num);
                i++;
                if((i+1)%5 == 0)printf("\n");
                pp=pp->pre;
            }
            printf(" %d ",pp->num);
            i++;
            if((i+1)%5 == 0)printf("\n");
            return(sum);
        }
    }
}

