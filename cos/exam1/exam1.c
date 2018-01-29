#include <stdio.h>
#include <stdlib.h>

#define yes 1
#define no 0

int *available;
int **max;
int **allocation ;
int **need ;
int *recordAry;
int *secureAry;
int *work;
int *finish;
int processNum,resourceNum,count = 0,number;
void initArray();//将文件中的数据写入数组
int bank(int process);//银行家算法
int secure();//系统安全性算法
int forSecure();
int main(int argc, const char * argv[]) {
    int i,j;
    while(1){
        printf("输入进程数和资源数\n");
        scanf("%d%d",&processNum,&resourceNum);
        
        initArray();
        
    //     if (secure()==yes)
    //     {
    //         for (int i = 0; i < processNum; ++i)
    //             printf("%d ", recordAry[i]);
    //         printf("\n");
    //     } else
    //         printf("无安全序列\n");
        secureAry = (int*)malloc(sizeof(int)*processNum);
        work = (int*)malloc(sizeof(int)*resourceNum);
        for (int i = 0; i < resourceNum; ++i)
            work[i] = available[i];
        finish = (int*)malloc(sizeof(int)*processNum);
        for (int i = 0; i < processNum; ++i)
            finish[i] = no;
        number = 0;
        forSecure();
        if (number==0)
            printf("没有安全序列\n");
        else
            printf("有%d个安全序列\n", number);
    }
}

void initArray()
{
    
    available = (int *)malloc(sizeof(int) * resourceNum);//给available数组分配空间
    max = (int**)malloc(sizeof(int*) * processNum);//给max矩阵分配空间
    for (int i = 0; i < processNum; ++i)
        max[i] = (int *)malloc(sizeof(int) * resourceNum);
    allocation = (int **)malloc(sizeof(int*) * processNum);//给allocation矩阵分配空间
    for (int i = 0; i < processNum; ++i)
        allocation[i] = (int*)malloc(sizeof(int) * resourceNum);
    need = (int**)malloc(sizeof(int*) * processNum);//给need矩阵分配空间
    for (int i = 0; i < processNum; ++i)
        need[i] = (int *)malloc(sizeof(int) * resourceNum);
    
    
    int i,j;
    //打开输入文件
    FILE * fAvai = fopen("available", "r");
    FILE * fMax = fopen("max", "r");
    FILE * fAlloc = fopen("allocation", "r");
    FILE * fNeed = fopen("need","r");
    if (fAvai==NULL || fMax == NULL || fAlloc == NULL || fNeed == NULL) {//若打开文件失败则退出
        puts("不能打开文件！");
        exit(0);
    }
    //将文件中的数据写入数组中
    for (i = 0; i < resourceNum; i++)
        fscanf(fAvai, "%d", available+i);
    for ( i = 0; i < processNum; ++i)
    {
        for ( j = 0; j < resourceNum; ++j)
            fscanf(fMax, "%d", max[i]+j);
        fscanf(fMax,"%*[^\n]");//提示文件指针指向下一行
    }
    for (int i = 0; i < processNum; ++i)
    {
        for (int j = 0; j < resourceNum; ++j)
            fscanf(fAlloc, "%d", allocation[i]+j);
        fscanf(fAlloc,"%*[^\n]");
    }
    for (int i = 0; i < processNum; ++i)
    {
        for (int j = 0; j < resourceNum; ++j)
            fscanf(fNeed, "%d", need[i]+j);
        fscanf(fNeed,"%*[^\n]");
    }
    fclose(fAvai);
    fclose(fMax);
    fclose(fAlloc);
    fclose(fNeed);
    for (int i = 0; i < processNum; ++i)
    {
        printf("P%d\t", i);
        for (int j = 0; j < resourceNum; ++j)
            printf(" %d", max[i][j]);
        printf("\t");
        for (int j = 0; j < resourceNum; ++j)
            printf(" %d", allocation[i][j]);
        printf("\t");
        for (int j = 0; j < resourceNum; ++j)
            printf(" %d", need[i][j]);
        printf("\t");
        if (i == 0)
        {
            for (int j = 0; j < resourceNum; ++j)
                printf(" %d", available[j]);
            printf("\n");
        } else
            printf("\n");
    }
    //验证数据的准确性
    for (int i = 0; i < processNum; ++i)
    {
        for (int j = 0; j < resourceNum; ++j)
        {
            if (need[i][j]!=max[i][j]-allocation[i][j])
            {
                printf("数据初始化错误\n");
                exit(1);
            }
        }
    }
    
}

//检查系统是否处于安全状态
int secure()
{
    recordAry = (int*)malloc(sizeof(int)*processNum);
    int count = 0;
    int *work = (int*)malloc(sizeof(int)*resourceNum);
    for (int i = 0; i < resourceNum; ++i)
        work[i] = available[i];
    int *finish = (int*)malloc(sizeof(int)*processNum);
    for (int i = 0; i < processNum; ++i)
        finish[i] = no;
    while (count != processNum-1)
    {
        for (int i = 0; i < processNum; ++i)
        {
            if (finish[i] == no)
            {
                for (int j = 0; j < resourceNum; ++j)
                {
                    if (need[i][j]>work[j])
                    {
                        if (i == processNum-1)
                        {
                            return no;
                        }
                        break;
                    }
                    else if (j == resourceNum-1)
                    {
                        for (int j = 0; j < resourceNum; ++j)
                            work[j] = work[j]+allocation[i][j];
                        finish[i] = yes;
                        recordAry[count] = i;
                        count++;
                    }
                }
            } else if (i == processNum-1)
                return yes;
        }
    }
    if (count == processNum-1)
        return yes;
    else
        return no;
}

//使用递归方法查询所有的安全序列
int forSecure()
{
    for (int i = 0; i < processNum; ++i)
    {
        if (finish[i]==no)
        {
            for (int j = 0; j < resourceNum; ++j)
            {
                if (need[i][j]>work[j])
                {
                    if (i == processNum-1)
                    {
                        return no;
                    }
                    break;
                }
                else if (j == resourceNum-1)
                {
                    for (int j = 0; j < resourceNum; ++j)
                        work[j] = work[j]+allocation[i][j];
                    finish[i] = yes;
                    secureAry[count] = i;
                    count++;
                    if (count == processNum)
                    {
                        for (int i = 0; i < processNum; ++i)
                            printf("%d ", secureAry[i]);
                        printf("\n");
                        number ++;//进行计数
                        for (int j = 0; j < resourceNum; ++j)
                            work[j] = work[j]-allocation[i][j];
                        finish[i] = no;
                        secureAry[count] = -1;
                        count--;
                    } else {
                        if (forSecure() == no)
                        {
                            for (int j = 0; j < resourceNum; ++j)
                                work[j] = work[j]-allocation[i][j];
                            finish[i] = no;
                            secureAry[count] = -1;
                            count--;
                        }
                    }
                }
            }
            
        }
    }
    return no;
}
