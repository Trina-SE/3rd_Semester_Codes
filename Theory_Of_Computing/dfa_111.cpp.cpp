#include<stdio.h>

int main()
{
    char str[200],f='p';
    int i;
    printf("String?\n");
    scanf("%s",str);
    for(i=0; str[i]!='\0'; i++)
    {
        switch(f)
        {
        case 'p':
            if(str[i]=='0')
            {
                f='p';
                printf("(p,0)->p\n");
            }
            else if(str[i]=='1')
            {
                f='q';
                printf("(p,1)->q\n");
            }
            break;
        case 'q':
            if(str[i]=='0')
            {

                f='p';
                printf("(q,0)->p\n");
            }

            else if(str[i]=='1')
            {
                f='r';
                printf("(q,1)->r\n");
            }
            break;
        case 'r':
            if(str[i]=='0') {
                    f='p';
             printf("(r,0)->p\n");
            }
            else if(str[i]=='1') {
                    f='s';
            printf("(r,1)->s\n");
            }
            break;
        case 's':
            if(str[i]=='0') {
                    f='s';
             printf("(s,0)->s\n");
            }
            else if(str[i]=='1') {
                    f='s';
            printf("(s,1)->s\n");
            }
            break;
        }
    }
    if(f=='s')
        printf("String is Accepted\n");
    else printf("String is not accepted");

}


