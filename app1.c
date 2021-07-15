#include<stdio.h>
#include<string.h>
struct Student
{
int rollnumber;
char name[37];
char gender;
};
void addStudent();
void editStudent();
void deleteStudent();
void searchStudent();
void displayListofStudent();
void printLine(char g,int size)
{
for(int i=0;i<size;i++) printf("%c",g);
printf("\n");
}
int main()
{
int ch;
while(1)
{
printf("1.Add Student\n");
printf("2.Edit Student\n");
printf("3.Delete Student\n");
printf("4.Search Student\n");
printf("5.Display List of Student\n");
printf("6.Exit\n");
printf("Enter your choice :");
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addStudent();
else if(ch==2) editStudent();
else if(ch==3) deleteStudent();
else if(ch==4) searchStudent();
else if(ch==5) displayListofStudent();
else if(ch==6) break;
else printf("Invalid Choice\n");
}
return 0;
}
void addStudent()
{
FILE *f;
struct Student t,g;
int rollnumber;
char name[37];
char gender;
char m;
printf("Enter Rollnumber to add student :");
scanf("%d",&rollnumber);
fflush(stdin);
if(rollnumber<=0)
{
printf("Invalid rollnumber\n");
return;
}
f=fopen("student.dat","rb");
if(f!=NULL)
{
while(1)
{
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollnumber==t.rollnumber)
{
printf("That rollnumber has been alloted to %s\n",t.name);
return ;
}
}
fclose(f);
}
printf("Enter name :");
fgets(name,37,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter gender(M/F):");
gender=getchar();
fflush(stdin);
if(gender!='M'&&gender!='m'&&gender!='F'&&gender!='f')
{
printf("Inavlid Gender\n");
return ;
}
printf("Save(Y/N):");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='Y')
{
printf("Student not added\n");
return ;
}
g.rollnumber=rollnumber;
strcpy(g.name,name);
g.gender=gender;
f=fopen("student.dat","ab");
fwrite(&g,sizeof(struct Student),1,f);
fclose(f);
printf("Student addded,press enter to continue..");
getchar();
fflush(stdin);
}
void editStudent()
{
FILE *f1,*f2;
struct Student t,g;
int rollnumber;
char name[37];
char gender;
char m;
int found;
printf("Student(Edit Module)\n");
printf("Enter roll number to search student :");
scanf("%d",&rollnumber);
fflush(stdin);
if(rollnumber<=0)
{
printf("Invalid rollnumber\n");
return;
}
found=01;
f1=fopen("student.dat","rb");
if(f1==NULL)
{
printf("Invalid Roll number\n");
return ;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(rollnumber==t.rollnumber)
{
found=1;
break;
}
}
fclose(f1);
if(found==0)
{
printf("Invalid Rollnumber\n");
return;
}
printf("Name :%s\n",t.name);
if(t.gender=='M' || t.gender=='m') printf("Gender :Male\n");
else printf("Gender : Female\n");
printf("Edit(Y/N) :");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='Y')
{
printf("Student not edited\n");
return ;
}
printf("Enter name :");
fgets(name,37,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter Gender(M/F) :");
gender=getchar();
fflush(stdin);
if(gender!='M'&&gender!='m'&&gender!='F'&&gender!='f')
{
printf("Invalid Gender\n");
return ;
}
printf("Update(Y/N):");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='Y')
{
printf("Student Not updated\n");
return ;
}
g.rollnumber=rollnumber;
strcpy(g.name,name);
g.gender=gender;
f1=fopen("student.dat","rb");
f2=fopen("tmp.tmp","wb");
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(rollnumber!=t.rollnumber)
{
fwrite(&t,sizeof(struct Student),1,f2);
}
else
{
fwrite(&g,sizeof(struct Student),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("student.dat","wb");
f2=fopen("tmp.tmp","rb");
while(1)
{
fread(&t,sizeof(struct Student) ,1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Student),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.tmp","w");
fclose(f2);
printf("Student Updated,press enter to continue...");
getchar();
fflush(stdin);
}
void deleteStudent()
{
FILE *f1,*f2;
struct Student t;
int rollnumber;
char m;
int found;
printf("Student(Delete Module)\n");
printf("Enter roll number to search student :");
scanf("%d",&rollnumber);
fflush(stdin);
if(rollnumber<=0)
{
printf("Invalid rollnumber\n");
return;
}
found=0;
f1=fopen("student.dat","rb");
if(f1==NULL)
{
printf("Invalid Roll number\n");
return ;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(rollnumber==t.rollnumber)
{
found=1;
break;
}
}
fclose(f1);
if(found==0)
{
printf("Invalid Rollnumber\n");
return;
}
printf("Name :%s\n",t.name);
if(t.gender=='M' || t.gender=='m') printf("Gender :%s\n","Male");
else printf("Gender : %s\n","Female");
printf("Delete(Y/N):");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='Y')
{
printf("Student Not Deleted\n");
return ;
}
f1=fopen("student.dat","rb");
f2=fopen("tmp.tmp","wb");
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(rollnumber!=t.rollnumber)
{
fwrite(&t,sizeof(struct Student),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("student.dat","wb");
f2=fopen("tmp.tmp","rb");
while(1)
{
fread(&t,sizeof(struct Student) ,1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Student),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.tmp","w");
fclose(f2);
printf("Student Deleted,press enter to continue...");
getchar();
fflush(stdin);
}
void searchStudent()
{
FILE *f;
struct Student t;
int rollnumber;
int found;
printf("Student(Search Module)\n");
printf("Enter roll number to search student :");
scanf("%d",&rollnumber);
fflush(stdin);
if(rollnumber<=0)
{
printf("Invalid rollnumber\n");
return;
}
f=fopen("student.dat","rb");
if(f==NULL)
{
printf("Invalid Roll number\n");
return ;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollnumber==t.rollnumber)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("Invalid Rollnumber\n");
return;
}
printf("Name :%s\n",t.name);
if(t.gender=='M' || t.gender=='m') printf("Gender :Male\n");
else printf("Gender : Female\n");
printf("Press enter to continue..");
getchar();
fflush(stdin);
}
void displayListofStudent()
{
FILE *f;
struct Student t;
int newPage,pageSize;
int sno;
f=fopen("student.dat","rb");
if(f==NULL)
{
printf("Student(List Module)\n");
printLine('-',75);
printf("%10s %-12s %-35s %s\n","S.No.","Roll Number","Name","Gender");
printLine('-',70);
printf("No student added\n");
printLine('-',70);
printf("Press enter to continue..");
getchar();
fflush(stdin);
}
sno=0;
newPage=1;
pageSize=5;
while(1)
{
if(newPage==1)
{
printf("Student(List Module)\n");
printLine('-',75);
printf("%10s %-12s %-35s %s\n","S.No.","Roll Number","Name","Gender");
printLine('-',75);
newPage=0;
}
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
sno++;
if(t.gender=='M' || t.gender=='m')
{
printf("%9d %-10d  %-35s %-6s\n",sno,t.rollnumber,t.name,"Male");
}
else
{
printf("%9d %-10d  %-35s %-6s\n",sno,t.rollnumber,t.name,"Female");
}
if(sno%pageSize==0)
{
printLine('-',75);
printf("Press enter to continue...");
getchar();
fflush(stdin);
newPage=1;
}
}
if(sno==0)
{
printf("No Student Added\n");
printLine('-',75);
printf("Press enter to continue...");
getchar();
fflush(stdin);
}
if(sno%pageSize!=0)
{
printLine('-',75);
printf("Press enter to continue...");
getchar();
fflush(stdin);
}
fclose(f);
}
