#include "LISTOPERATION.h"
void panel();
int panelOperation(Oper* list);
Oper list;
int main(){
    cout<<"                 ��ӭ��½ѧ������ϵͳ��"<<endl;
    list.loadList();
    while (1){
        panel();
        CLEAR
    }
}
void panel(){
    cout<<"*******************************************************"<<endl;
    cout<<"     1.¼��ѧ��ѧ����Ϣ       2.��ӡѧ��ѧ����Ϣ"<<endl;
    cout<<"     3.����ѧ��ѧ����Ϣ       4.ɾ��ѧ��ѧ����Ϣ"<<endl;
    cout<<"     5.�޸�ѧ��ѧ����Ϣ       6.��ѯѧ��ѧ����Ϣ"<<endl;
    cout<<"     7.���ѧ��ѧ����Ϣ       8.�˳�ѧ������ϵͳ"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"��������Ҫ���в�������ţ�"<<endl;
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
            cout<<"ע�⣡¼����Ϣ������ԭ�е���¼�����Ϣ��"<<endl;
            cout<<"�Ƿ����¼�룿(y/n)"<<endl;
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
            cout<<"1.��ѧ�������ӡ"<<endl;
            cout<<"2.���ɼ������ӡ"<<endl;
            cout<<"��������Ҫ���в��������(������������ֽ�������һ��):";
            cin>>opershow;
            if (opershow == '1'){
                (*list).sortListByNum();
                (*list).showList();
                cout<<"��������ֵ��������ҳ��"<<endl;
                cin>>back;
                BACKTIP
                delay();
            } else if (opershow == '2'){
                (*list).sortListByScore();
                (*list).showList();
                cout<<"��������ֵ��������ҳ��"<<endl;
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
            cout<<"ȷ��Ҫִ�д˲�����(y/n)"<<endl;
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
            cout<<"ȷ��Ҫִ�д˲�����(y/n)"<<endl;
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
            cout<<"��������ֵ��������ҳ��"<<endl;
            cin>>back;
            BACKTIP
            delay();
            break;
        case '7':
            cout<<"�����������ѧ����Ϣ��ȷ�ϼ�����(y/n)"<<endl;
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
            cout<<"     1.¼��ѧ��ѧ����Ϣ       2.��ӡѧ��ѧ����Ϣ"<<endl;
            cout<<"     3.����ѧ��ѧ����Ϣ       4.ɾ��ѧ��ѧ����Ϣ"<<endl;
            cout<<"     5.�޸�ѧ��ѧ����Ϣ       6.��ѯѧ��ѧ����Ϣ"<<endl;
            cout<<"     7.���ѧ��ѧ����Ϣ       8.�˳�ѧ������ϵͳ"<<endl;
            cout<<"*******************************************************"<<endl;
            cout<<"��������ȷ�Ĳ�����ţ�";
            panelOperation(list);
            break;
    }
}

