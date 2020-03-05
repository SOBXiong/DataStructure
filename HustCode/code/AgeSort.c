#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Worker{
    int id;
    char name[11];
    int age;
}Worker;
int compare(const void *p1,const void *p2){
    Worker* w1 = (Worker*)p1;
    Worker* w2 = (Worker*)p2;
    if(w1->age != w2->age) return w1->age - w2->age;
    if(w1->id != w2->id) return w1->id - w2->id;
    return strcmp(w1->name,w2->name);
}
int main(){
    int n,i;
    while(~scanf("%d",&n)){
        Worker* workers = (Worker*)malloc(sizeof(Worker) * n);
        for(i = 0;i < n;i++){
            scanf("%d %s %d",&workers[i].id,workers[i].name,&workers[i].age);
        }
        qsort(workers,n,sizeof(Worker),compare);
        int outLength = n < 3 ? n : 3;
        for(i = 0;i < outLength;i++){
            printf("%d %s %d\n",workers[i].id,workers[i].name,workers[i].age);
        }
        free(workers);
    }
    return 0;
}
