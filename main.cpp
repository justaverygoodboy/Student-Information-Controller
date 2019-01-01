#include "LISTOPERATION.h"
void panel();
int panelOperation(Oper* list);
Oper list;
int main(){
    cout<<"                 欢迎登陆学籍管理系统！"<<endl;
    list.loadList();
    while (1){
        panel();
        CLEAR
    }
}
void panel(){
    cout<<"*******************************************************"<<endl;
    cout<<"     1.录入学生学籍信息       2.打印学生学籍信息"<<endl;
    cout<<"     3.增添学生学籍信息       4.删除学生学籍信息"<<endl;
    cout<<"     5.修改学生学籍信息       6.查询学生学籍信息"<<endl;
    cout<<"     7.清空学生学籍信息       8.退出学籍管理系统"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"请输入您要进行操作的序号："<<endl;
    panelOperation(&list);
}
int panelOperation(Oper* list){
    char confirm;
    char opernum;
    cin>>opernum;
    CLEAR
    char back;
    switch (opernum){
        case '1':
            cout<<"注意！录入信息将覆盖原有的已录入的信息！"<<endl;
            cout<<"是否继续录入？(y/n)"<<endl;
            getchar();
            if(getchar()=='y'){
            (*list).creatList();
            (*list).saveList();
            delay();
            }
            else{
                BACKTIP
                delay();
            }
            break;
        case '2':
            HEADEXIST
            char opershow;
            cout<<"1.按学号排序打印"<<endl;
            cout<<"2.按成绩排序打印"<<endl;
            cout<<"请输入您要进行操作的序号(输入以外的数字将返回上一级):";
            cin>>opershow;
            if (opershow == '1'){
                (*list).sortListByNum();
                (*list).showList();
                cout<<"键入任意值将返回主页面"<<endl;
                cin>>back;
                BACKTIP
                delay();
            } else if (opershow == '2'){
                (*list).sortListByScore();
                (*list).showList();
                cout<<"键入任意值将返回主页面"<<endl;
                cin>>back;
                BACKTIP
                delay();
            } else{
                BACKTIP
                delay();
                panel();
            }
            break;
        case '3':
            HEADEXIST
            (*list).addNode();
            (*list).saveList();
            delay();
            break;
        case '4':
            HEADEXIST
            cout<<"确定要执行此操作？(y/n)"<<endl;
            cin>>confirm;
            if(confirm == 'y'||confirm == 'Y'){
                (*list).delNode();
                (*list).saveList();
                delay();
                break;
            }
            else{
                BACKTIP
                delay();
                break;
            }
        case '5':
            HEADEXIST
            cout<<"确定要执行此操作？(y/n)"<<endl;
            cin>>confirm;
            if(confirm == 'y'||confirm == 'Y'){
                (*list).editNode();
                (*list).saveList();
                BACKTIP
                delay();
                break;
            } else{
                BACKTIP
                delay();
                break;
            }

        case '6':
            HEADEXIST
            (*list).searchNode();
            cout<<"键入任意值将返回主页面"<<endl;
            cin>>back;
            BACKTIP
            delay();
            break;
        case '7':
            cout<<"本操作将清空学籍信息，确认继续？(y/n)"<<endl;
            cin>>confirm;
            if(confirm == 'y')
            {
                (*list).delList();
                (*list).saveList();
                delay();
                break;
            }
            else{
                BACKTIP
                delay();
                break;
            }
        case '8':
            exit(0);
        default:
            cout<<"*******************************************************"<<endl;
            cout<<"     1.录入学生学籍信息       2.打印学生学籍信息"<<endl;
            cout<<"     3.增添学生学籍信息       4.删除学生学籍信息"<<endl;
            cout<<"     5.修改学生学籍信息       6.查询学生学籍信息"<<endl;
            cout<<"     7.清空学生学籍信息       8.退出学籍管理系统"<<endl;
            cout<<"*******************************************************"<<endl;
            cout<<"请输入正确的操作序号：";
            panelOperation(list);
            break;
    }
}

