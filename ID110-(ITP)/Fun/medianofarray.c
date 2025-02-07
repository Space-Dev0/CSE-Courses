#include<stdio.h>
int main()
{
    int nums1Size,nums2Size,i;
    scanf("%d",&nums1Size);
    int nums1[nums1Size];
    for ( i = 0; i < nums1Size; i++)
        scanf("%d",&nums1[i]);
    scanf("%d",&nums2Size);
    int nums2[nums2Size];
    for ( i = 0; i < nums2Size; i++)
        scanf("%d",&nums2[i]);
    int a,b,c;
    c = nums1Size+nums2Size;
    int merged[c];
    for(i=0,a=0,b=0;i<=c/2;i++)
    {
        if(b == nums2Size && a != nums1Size)
            {
                merged[i] = nums1[a];
                a++;
                continue;
            }
        else if(a == nums1Size)
            {
                merged[i] = nums2[b];
                b++;
                continue;
            }
        if(nums1[a]>nums2[b])
            {
                merged[i] = nums2[b];
                b++;
            }
        else
            {
                merged[i] = nums1[a];
                a++;
            }
    }
    if(c%2==0)
    {
        printf("%lf",(merged[c/2]+merged[(c/2)-1])/2.0);
    }   
    else printf("%lf",merged[c/2]);
}
