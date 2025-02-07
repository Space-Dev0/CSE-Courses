#include<stdio.h>
#include<stdlib.h>

struct player
{
    char name[50];
    int matches_played;
    char team_name[30];
    int total_runs,total_wickets;
};

union omg
{
    int n;
    float m;
    char k;
};

int main()
{
    int n;
    printf("Enter number of players: ");
    scanf("%d",&n);
    struct player P[n]; 
    union omg test;
    test.k = 'y';
    printf("%f",test.m); 
}