#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "OPTIMIZE.h"
using namespace std;

struct Student {
    long long int num;
    char name[12];
    double score;
    struct Student* next;
};

class Oper {
private:
    int amount;
public:
    struct Student* head;
    Oper();
    void creatList();
    void loadList();
    void showList();
    void delList();
    void sortListByNum();
    void sortListByScore();
    void addNode();
    void delNode();
    void searchNode();
    void editNode();
    void saveList();
};
Oper::Oper() {
    head = NULL;
}
void Oper::creatList(){
    int i = 0;
    struct Student* noed;
    struct Student* none;
    cout<<"��������Ҫ¼���ѧ��������"<<endl;
    cin>>amount;
    cout<<"����������ѧ��ѧ����Ϣ (ѧ�� ���� �ɼ�):"<<endl;
    head = new Student;
    noed = head;
    cin>>noed->num>>noed->name>>noed->score;
    while(i < amount-1){
        none = noed->next;
        none = new Student;
        cin>>none->num>>none->name>>none->score;
        noed->next = none;
        noed = none;
        i++;
    }
    noed->next = NULL;
    cout<<"¼��ɹ���"<<endl;
}

void Oper::loadList() {
    struct Student* noed;
    struct Student* none;
    head = NULL;
    head = new Student;
    noed = head;
    ifstream db("StuInfo.db",ios::in|ios::binary);
    stringstream ss;
    string s;
    db.seekg(0,ios_base::end);
    int fileLength = db.tellg();
    if (!db||!fileLength){
        head = NULL;
    } else {
        db.seekg(0,ios_base::beg);
        ss.clear();
        db >> s;
        ss << s;
        ss >> noed->num;
        db >> s;
        ss.clear();
        ss << s;
        ss >> noed->name;
        db >> s;
        ss.clear();
        ss << s;
        ss >> noed->score;
        ss.clear();
        while(db>>s){
            none = noed->next;
            none = new Student;
            ss<<s;
            ss>>none->num;
            db>>s;
            ss.clear();
            ss<<s;
            ss>>none->name;
            db>>s;
            ss.clear();
            ss<<s;
            ss>>none->score;
            ss.clear();
            noed->next = none;
            noed = none;
        }
        noed->next = NULL;
    }
    db.close();
}
void Oper::showList(){
    struct Student* noed;
    noed = head;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<setw(3)<<"ѧ��"<<setw(22)<<"����"<<setw(22)<<"�ɼ�"<<endl;
    while(noed!=NULL){
        cout<<setw(3)<<noed->num<<setw(17)<<noed->name<<setw(19)<<noed->score<<endl;
        noed = noed->next;
    }
    cout<<"-----------------------------------------------------"<<endl;
}
void Oper::delList() {
    head = NULL;
    cout<<"����գ�"<<endl;
}

void Oper::addNode(){
    char confirm;
    struct Student* noed;
    struct Student* add;
    noed = head;
    add = new Student;
    cout<<"������Ҫ�����ѧ��ѧ����Ϣ��"<<endl;
    cin>>add->num>>add->name>>add->score;
    add->next = noed;
    noed = add;
    head = add;
    cout<<"���ѧ����Ϣ�ɹ����Ƿ�������: (y/n)"<<endl;
    cin>>confirm;
    if(confirm == 'y'||confirm == 'Y')
        addNode();
}
void Oper::delNode() {
    struct Student* noed;
    noed = head;
    char name[12];
    long long int keynum;
    char confirm;
    bool exist = false;
    cout<<"������Ҫɾ����ѧ��������ѧ�ţ�";
    cin>>name;
    keynum = atoll(name);
    while(noed!=NULL){
        if(!strcmp(name,noed->name)||keynum == noed->num){
            exist = true;
            cout<<"ȷ��Ҫɾ����"<<noed->name<<" ����Ϣ��(y/n)"<<endl;
            cin>>confirm;
            if(confirm == 'y'||confirm =='Y'){
            head=noed->next;
            delete noed;
            cout<<"ɾ���ɹ����Ƿ���Ҫ����ɾ����(y/n)"<<endl;
            cin>>confirm;
            if(confirm == 'y'||confirm == 'Y')
                delNode();
            break;
        }
        else {
            BACKTIP
            delay();
            break;
            }
        }
        else if (!strcmp(name,noed->next->name)||keynum == noed->next->num){
            exist = true;
            cout<<"ȷ��Ҫɾ����"<<noed->next->name<<" ����Ϣ��(y/n)"<<endl;
            cin>>confirm;
            if(confirm == 'y'||confirm =='Y'){
                struct Student* p;
                p = noed->next;
                noed->next = noed->next->next;
                delete p;
                cout<<"ɾ���ɹ����Ƿ���Ҫ����ɾ����(y/n)"<<endl;
                cin>>confirm;
                if(confirm == 'y'||confirm == 'Y')
                    delNode();
                break;
            } else{
                BACKTIP
                delay();
                break;
            }
        }
            noed = noed->next;
        }
    if (!exist)
        cout<<"��Ǹ�����޴���"<<endl;
}
void Oper::searchNode(){
    struct Student* noed;
    noed = head;
    char name[12];
    long long int keynum;
    bool exist = false;
    cout<<"��������Ҫ��ѯ��ѧ��������ѧ��:";
    cin>>name;
    cout<<endl;
    keynum = atoll(name);
    while(noed!=NULL){
        if(!strcmp(name,noed->name)||keynum == noed->num){
            exist = true;
            cout<<"��Ҫ���ҵ�ѧ����Ϣ���£�"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<setw(3)<<"ѧ��"<<setw(22)<<"����"<<setw(22)<<"�ɼ�"<<endl;
            cout<<setw(3)<<noed->num<<setw(17)<<noed->name<<setw(19)<<noed->score<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            break;
        }
        noed = noed->next;
    }
    if (!exist)
        cout<<"��Ǹ�����޴���"<<endl;
}
void Oper::editNode() {
    struct Student* noed;
    noed = head;
    char name[12];
    long long int keynum;
    bool exist = false;
    char confirm;
    cout<<"��������Ҫ�޸���Ϣ��ѧ��������ѧ��:"<<endl;
    cin>>name;
    keynum = atoll(name);
    cout<<endl;
    while(noed!=NULL){
        if((!strcmp(name,noed->name))||keynum == noed->num){
            cout<<noed->name<<" ����Ϣ���£��Ƿ�ȷ���޸ģ�(y/n)"<<endl;
            cout<<"������"<<noed->name<<" ѧ�ţ�"<<noed->num<<" �ɼ���"<<noed->score<<endl;
            cin>>confirm;
            if(confirm == 'y'||confirm == 'Y'){
                exist = true;
                cout<<"�޸ĺ��ѧ�ţ�";
                cin>>noed->num;
                cout<<endl;
                cout<<"�޸ĺ��������";
                cin>>noed->name;
                cout<<endl;
                cout<<"�޸ĺ�ĳɼ���";
                cin>>noed->score;
                cout<<endl;
                cout<<"ѧ����Ϣ�޸ĳɹ���"<<endl;
            break;
            } else{
                BACKTIP
                delay();
                break;
            }
        }
        noed = noed->next;
    }
    if (!exist)
        cout<<"��Ǹ�����޴���"<<endl;
}

void Oper::sortListByNum() {
    struct Student* noed;
    struct Student* none;
    noed = head;
    none = NULL;
    bool isChange = true;
    while(none != noed->next && isChange)
    {
        Student *q = noed;
        isChange = false;
        for(; q->next && q->next != none; q = q->next)
        {
            if(q->num > q->next->num)
            {
                swap(q->num, q->next->num);
                swap(q->name,q->next->name);
                swap(q->score,q->next->score);
                isChange = true;
            }
        }
        none = q;
    }
}
void Oper::sortListByScore() {
    struct Student* noed;
    struct Student* none;
    noed = head;
    none = NULL;
    bool isChange = true;
    while(none != noed->next && isChange)
    {
        Student *q = noed;
        isChange = false;
        for(; q->next && q->next != none; q = q->next)
        {
            if(q->score < q->next->score)
            {
                swap(q->num, q->next->num);
                swap(q->name,q->next->name);
                swap(q->score,q->next->score);
                isChange = true;
            }
        }
        none = q;
    }
}

void Oper::saveList() {
    struct Student* noed;
    noed = head;
    ofstream outfile("StuInfo.db",ios::out|ios::binary);
    if(!outfile){
        cout<<"�����Զ�����ʧ��"<<endl;
    }
    else{
        while(noed){
            outfile<<noed->num<<" "<<noed->name<<" "<<noed->score<<" ";
            noed = noed->next;
        }
        cout<<"�����Զ�����ɹ���"<<endl;
    }
    outfile.close();
}