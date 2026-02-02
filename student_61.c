#include <stdio.h>

struct student 
{
  int roll_no;
  float percentage;
  char name[10];
};
int main()
{
  struct student students [3];
  int i;
  for(int i=0 ;i<=3 ;i++)
  {
    printf("enter the details for student %d\n",i+1);
    printf("roll no:");
    scanf("%d",&student[i].roll_no);
    
    fgets(student[i].roll_no,sizeof(student[i].roll_no),stdin);
    
    printf("name:");
    sizeof(s[i].name),stdin);
    scanf("%d",&student[i].name);
    
    printf("percentage");
    scanf("%f",&student[i].percentage);
    
    getchar();
    }
    printf("\n details of the 3 students entered:\n");
    for (int i=0 ;i<=3 ;i++)
  {
    printf("\n student %d\n",i+1);
    printf("roll_no:%s",student[i].roll_no);
    printf("name:%s",student[i].name);
    printf("percentage:%s",student[i].percentage);
  }
   return 0;
 }   
    
    
