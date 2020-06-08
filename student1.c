#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int menu();        //菜单界面
void func_flag(int flag);   //功能选择
void findStu();     //查询学生信息
void addStu();      //添加学生信息
void delStu();      //删除学生信息
void changeStu();   //修改学生信息
void allStu();      //显示所有学生信息

int n=0,flag=-1,sign=0;
typedef struct student {
    char id[50];
    char name[50];
    char tem[50];
    char major[50];
}stu;

stu s[N];

int menu()
{
    system("clear"); //Linux下清屏函数
    //system("cls"); //windows下清屏函数
	//printf("%s","\033[1H\033[2J"); //也是Linux下清屏函数但操作不是很舒服
    puts("************欢迎使用疫情期间学生管理系统************");
    puts("**                                                **");
    puts("**          键入对应数字选择操作                  **");
    puts("**                                                **");
    puts("**      1查询学生信息 |  2添加学生信息            **");
    puts("**      3删除学生信息 |  4修改学生信息            **");
    puts("**      5所有学生信息 |  6退出该程序              **");
    puts("**                                                **");
    puts("**         使用前请先录入学生信息                 **");
    puts("**                                                **");
    puts("**                OIDCAT                          **");
    puts("****************************************************");
    puts("请键入选项：");
    int flag;
    scanf("%d",&flag);
    return flag;
}

void func_flag(int flag)
{
    switch(flag)
    {
    case 1:findStu();break;
    case 2:addStu();break;
    case 3:delStu();break;
    case 4:changeStu();break;
    case 5:allStu();break;
    case 6:exit(0);break;
    default:printf("error");break;
    }
}


int main(int argc,const char *argv[])
{
    for(;;)
    {
      flag = menu();
      func_flag(flag);
      flag = -1;
    }
    return 0;
}

