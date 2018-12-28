#ifndef LINKLIST_OPTIMIZE_H
#define LINKLIST_OPTIMIZE_H
#define HEADEXIST if(!((*list).head)){cout<<"您还没有录入任何信息，请先录入或先加载信息后再操作！"<<endl;delay();break;}
#define DELAYTIME 0.6
#define CLEAR system("cls");
#endif //LINKLIST_OPTIMIZE_H

void delay(){
    float delays;
    clock_t start;
    delays = DELAYTIME*CLOCKS_PER_SEC;
    start =clock();
    while (clock()-start<delays);
}
void swap(char* p,char* q){
    char temp;
    int n1=strlen(p);
    int n2=strlen(q);
    if(n1>n2) {
        for(int i=0;i<n2;i++) {
            temp=p[i];
            p[i]=q[i];
            q[i]=temp;
        }
        for(int i=n2;i<n1;i++) {
            q[i]=p[i];
            p[i]='\0';
        }
    }
    else {
        for(int i=0;i<n1;i++) {
            temp=p[i];
            p[i]=q[i];
            q[i]=temp;
        }
        for(int i=n1;i<n2;i++) {
            p[i]=q[i];
            q[i]='\0';
        }
    }
}

