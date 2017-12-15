#include <stdio.h>

int main()
{
        int free_fram[12] = {4,7,8,5,1,2,11,12,10,13,14,15};
        int page_out[4] = {0,3,6,9};
        char pa[8][2] = {"ab","ef","cd","gh","xa","ta","ab","cg"};
        char pb[8][2] = {"rx","yy","zz","ww","mr","mk","fn","zx"};
        char phy[16][2] = {"ee","","","ww","","","gg","","","ff","","","","","",""};
        char page_table[2][8];
        int key = 1;
        int input,process;
        int count = 0,page_out_count = 0;
        int a_count = 0,b_count = 0;
        while(key)
        {
                printf("Input process and page_number:");
                scanf("%d %d",&process,&input);
                if(count < 12)
                {
                        if(process == 1)
                        {
                                phy[free_fram[count]][0] = pa[input][0];
                                                                             1,1          頂端
 phy[free_fram[count]][1] = pa[input][1];
                                page_table[0][input] = free_fram[count];
                        }
                        else if(process == 2 )
                        {
                                phy[free_fram[count]][0] = pb[input][0];
                                phy[free_fram[count]][1] = pb[input][1];
                                page_table[1][input] = free_fram[count];
                        }
                        count++;
                }
                else
                {
                        if(process == 1)
                        {
phy[page_out[page_out_count]][0] = pa[input][0];
                                phy[page_out[page_out_count]][1] = pa[input][1];
                                page_table[0][input] = page_out[page_out_count];
                        }
                        else if(process ==2 )
                        {
                                phy[page_out[page_out_count]][0] = pb[input][0];
                                phy[page_out[page_out_count]][1] = pb[input][1];
                                page_table[1][input] = page_out[page_out_count];
                        }
                        page_out_count++;
                }
                if(page_out_count == 4)
                {
                        key = 0}
        }
        int i;
        printf("process1's page table:\n");
        for(i = 0;i < 8;i++)
        {
                printf("page:%d insert to phy's table:%d\n",i,page_table[0][i]);
        }

        printf("process2's page table:\n");
        for(i = 0;i < 8;i++)
        {
                printf("page:%d insert to phy's table:%d\n",i,page_table[1][i]);
        }

        printf("phy's table:\n");
        for(i = 0;i < 16;i++)
        {
                printf("%d %c%c\n",i,phy[i][0],phy[i][1]);
        }


return 0;
}
