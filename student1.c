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

void findStu()
{
    system("clear");
    //system("cls");
	//printf("%s","\033[1H\033[2J");
    puts("***************请选择查找方式*************");
    puts("**                                      **");
    puts("**              1按学号查找             **");
    puts("**              2按姓名查找             **");
    puts("**                                      **");
    puts("**                OIDCAT                **");
    puts("******************************************");
    puts("请键入选项：");int choose;
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        {
            char num[20];
            puts("请输入查找学号：");
            scanf("%s",num);
            puts("查找结果如下");
            //printf("序号\t学号\t姓名\t体温\t专业\t\n");
            for(int i=0;i<n;i++)
            {
                if(strcmp(s[i].id,num)==0)
                {
					printf("序号\t学号\t\t\t姓名\t\t体温\t专业\t\n");
                    printf("%d\t%s\t\t%s\t\t%s\t%s\t\n",i+1,s[i].id,s[i].name,s[i].tem,s[i].major);
					sign = 1;
                }
            }
			if(sign==0){
				puts("无此学号！请核对！");
			}
			sign = 0;
            getchar();
            getchar();
            break;
        }
    case 2:
        {
            char name[50];
            puts("请输入查找姓名：");
            scanf("%s",name);
            puts("查找结果如下");
            //printf("序号\t学号\t姓名\t体温\t专业\t\n");
            for(int i=0;i<n;i++)
            {
                if(strcmp(s[i].name,name)==0)
                {
					printf("序号\t学号\t\t\t姓名\t\t体温\t专业\t\n");
                    printf("%d\t%s\t\t%s\t\t%s\t%s\t\n",i+1,s[i].id,s[i].name,s[i].tem,s[i].major);
				sign = 1;
				}
            }
			if(sign==0){
				puts("无此姓名！请核对！");
			}
			sign = 0;
            getchar();
            getchar();
            break;
        }
    default:puts("输入错误");break;
    }
}
void addStu()  //添加重名学生待解决
{
    system("clear");
    //system("cls");
	//printf("%s","\033[1H\033[2J");
    int person,i;
    printf("此次操作需要输入多少名学生："); scanf("%d",&person);
    for(i=0;i<person;i++){
        printf("请输入第%d个学生信息\n",i+1);
        printf("请输入学生学号\n学号："); scanf("%s",s[n+i].id);
        getchar();
        printf("请输入学生姓名\n姓名："); scanf("%s",s[n+i].name);
        getchar();
        printf("请输入学生体温\n体温："); scanf("%s",s[n+i].tem);
        getchar();
        printf("请输入学生专业\n专业："); scanf("%s",s[n+i].major);
    }
    n += i;
    puts("over");
    getchar();
    getchar();
}
void delStu()
{
    system("clear");
    //system("cls");
	//printf("%s","\033[1H\033[2J");
    puts("***************请选择删除方式**************");
    puts("**                                       **");
    puts("**              1按学号删除              **");
    puts("**              2按姓名删除              **");
    puts("**                                       **");
    puts("**                OIDCAT                 **");
    puts("*******************************************");
    puts("请键入选项：");int choose;
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        {
            char num[50];
            puts("请输入删除学号：");
            scanf("%s",num);
            for(int i=0;i<n;i++)
            {
                if(strcmp(s[i].id,num)==0)
                {
                    for(;i<n;i++)
                    {
                        strcpy(s[i].id,s[i+1].id);
                        strcpy(s[i].name,s[i+1].name);
                        strcpy(s[i].tem,s[i+1].tem);
                        strcpy(s[i].major,s[i+1].major);
                    }
					sign = 1;
                    n -= 1;
                    puts("删除成功!");
                }
            }
			if(sign==0){
				puts("无此学号！请核对！");
			}
			sign = 0;
            getchar();
            getchar();
            break;
        }
    case 2:
        {
            char name[50];
            puts("请输入删除姓名：");
            scanf("%s",name);
            for(int i=0;i<n;i++)
            {
                if(strcmp(s[i].name,name)==0)
                {
                    for(;i<n;i++)
                    {
                        strcpy(s[i].id,s[i+1].id);
                        strcpy(s[i].name,s[i+1].name);
                        strcpy(s[i].tem,s[i+1].tem);
                        strcpy(s[i].major,s[i+1].major);
                    }
					sign = 1;
                    n -= 1;
                    puts("删除成功!");
                }
            }
			if(sign==0){
				puts("无此姓名！请核对！");
			}
			sign = 0;
            getchar();
            getchar();
            break;
        }
    default:puts("输入错误");break;
    }
}
void changeStu()
{
    system("clear");
    //system("cls");
	//printf("%s","\033[1H\033[2J");
    char num[20];
    puts("请输入需要修改学号：");
    scanf("%s",num);
    for(int i=0;i<n;i++)
    {
        if(strcmp(s[i].id,num)==0)
        {
			sign = 1;
            puts("已定位到待修改参数,请修改:");
            printf("修改学号为："); scanf("%s",s[i].id);
            getchar();
            printf("修改学生姓名为："); scanf("%s",s[i].name);
            getchar();
            printf("修改学生体温为："); scanf("%s",s[i].tem);
            getchar();
            printf("修改学生专业为："); scanf("%s",s[i].major);
            puts("修改成功!");
        }
    }
	if(sign==0){
		puts("无此学号！请核对！");
	}
	sign = 0;
    getchar();
    getchar();
}

stu temp;

void allStu()
{
    system("clear");
    //system("cls");
	//printf("%s","\033[1H\033[2J");
    printf("序号\t学号\t\t\t姓名\t\t体温\t专业\t\n");
    //选择排序
    for(int i=0;i<n;i++)
	{
		int max=i;
		for(int j=i+1;j<n;j++)
		{
			if(atoi(s[j].id)<atoi(s[max].id))
			{
				max=j;
			}
		}
			if(max!=i)
			{
			    temp = s[i];
			    s[i] = s[max];
			    s[max] = temp;
			}
	}
    for(int i=0;i<n;i++)
    {
        printf("%d\t%s\t\t%s\t\t%s\t%s\t\n",i+1,s[i].id,s[i].name,s[i].tem,s[i].major);
    }
    getchar();
    getchar();
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

