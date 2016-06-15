/* 
* @Author: anchen
* @Date:   2016-06-14 17:06:14
* @Last Modified by:   anchen
* @Last Modified time: 2016-06-15 09:56:04
*/

#include <stdio.h>
#include <stdlib.h>

void f(int *p,int no)
{
    int i = 0,j = 0;
    int temp;
    for(i = 0;i < no ;i++)
    {
        for(j = i+1;j< no; j++)
        {
            if(p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
}

int main() 
{
    char ReadBuf[128] = {0};
    int Num[128] = {0};
    int i = 0,end = 0;
    FILE *fp = NULL;

    fp = fopen("a.txt", "r");
    while(!feof(fp))
    {
        fgets(ReadBuf,sizeof(ReadBuf),fp);
        Num[i++] = atoi(ReadBuf);
    }
    fclose(fp);

    end = i - 1;
    f(Num,end);
    for( i =0 ; i < end;i ++)
    {
        printf("%d\n", Num[i]);
    }

    fp = fopen("b.txt", "w");
    for( i =0 ; i < end;i ++)
    {
        char str[5] = { 0 };
        sprintf( str, "%d\n\r", Num[i] );
        fputs(str,fp);
    }
    fclose(fp);

    return 0;
}

