#include<stdio.h>
#include<string.h>

//structure for student
typedef struct student{
 char name[100];
 long int admission_num;
 int marks[3][9];
}student;

//global variable
struct student s[10];
int count=0;   // number of students added

void grade(int i)
{
 int k;
 for(k=0;k<3;k++)
 {
 if(s[i].marks[k][7]==100)
 s[i].marks[k][8]=1;
 else if(s[i].marks[k][7]>75)
 s[i].marks[k][8]=2;
 else if(s[i].marks[k][7]>50)
 s[i].marks[k][8]=3;
 else if(s[i].marks[k][7]>=32)
 s[i].marks[k][8]=4;
 else
 s[i].marks[k][8]=0;
 }
}

void caluclation(int i)
{
 int k,j,sum=0;
 for(k=0;k<3;k++)
 {
 for(j=0;j<6;j++)
 {
 sum+=s[i].marks[k][j];
 }
 s[i].marks[k][6]=sum;
 sum=0;
 }
 for(k=0;k<3;k++)
 {
 s[i].marks[k][7]=s[i].marks[k][6]/6;
 }
 grade(i);
}

void marks(int j)
{
 int i,k;
 for(k=0;k<3;k++)
 {
 if(k==0)
 printf("enter FA marks:");
 if(k==1)
 printf("enter MID marks:");
 if(k==2)
 printf("enter FINAL marks:");
 for(i=0;i<6;i++)
 {
 scanf(" %d",&s[j].marks[k][i]);
 }
 }
 caluclation(j);
}

void add_student(void)
{
 int i=count;
 if(i>=10)
 {
 printf("Student list is full\n");
 return;
 }
 printf("Enter the name of student:"),scanf(" %[^\n]",s[i].name);
 printf("Enter the student admission number:"),scanf("%ld",&s[i].admission_num);
 marks(i);
 count++;
}
int index_finder(void)
{
 long int num;
 int i;
 printf("Enter the student admission number:"),scanf("%ld",&num);
 for(i=0;i<count;i++)
 {
 if(s[i].admission_num==num)
 return i;
 }
 printf("invalid admission number\n");
 return -9;
}

void printing_progress(int j)
{
 int i,k;
 printf("progress report of %s:\nadmission number:%ld\n",s[j].name,s[j].admission_num);
 printf("mat\t\ttel\t\thin\t\teng\t\tsoc\t\tsci\t\ttotal avg grade\n");
 for(k=0;k<3;k++)
 {
 for(i=0;i<6;i++)
 {
 printf("%.3d\t\t",s[j].marks[k][i]);
 }
 printf("%.3d ",s[j].marks[k][6]);
 printf("%.3d ",s[j].marks[k][7]);
 printf("%.3d\n",s[j].marks[k][8]);
 }
}

int main(void)
{
 int i,j,c;
 while(1)
 {
 printf("1.Add a student\n2.Print student Progress\n3.Exit\nchoose a service:");
 if(scanf("%d",&i)!=1)
 {
 while((c=getchar())!='\n' && c!=EOF);
 if(c==EOF)
 return 0;
 continue;
 }
 switch(i)
 {
 case 1:add_student();break;
 case 2:
 j=index_finder();
 if(j==-9)
 continue;
 printing_progress(j);
 break;
 case 3:
 printf("exiting...\n");
 return 0;
 default:
 continue;
 }
 }
 return 0;
}
