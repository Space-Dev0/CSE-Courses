#include<stdio.h>
#include<string.h>

int main()
{
    /*int n;
    int** ptr;
    ptr = (int**)malloc(10*sizeof(int*));
    if(ptr==NULL){
        printf("Memory allocaiton failed");
        exit(1);
    }

    for(int i=0;i<10;i++)
    {
        ptr[i]= (int*)malloc(20*sizeof(int));
        if(ptr[i]==NULL)
        {
        printf("Memory allocaiton failed in the pointer");
        exit(1);
        }



    }*/
//char A[] = {'R', 'A', 'M'};
char name[10]="Ramesh";
int i, count=0;

/*for(i=0;i<3;i++)
    printf("%c", A[i]);

printf("\n");*/
i=0;
while(name[i]!='\0')
{
    printf("%c", name[i]);
    //printf("%u ", &name[i]);
    i++;
   // count++;
}
printf("\n%c",name[4]);
//printf ("\nThe number of times the while loop is running is %d", count);
    
    return 0;
}