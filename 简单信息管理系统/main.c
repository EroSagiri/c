#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id; // 学号
    char name[10]; // 名字
    char gender; // 性别 x是女 y是男
} Student;


typedef struct StudentLink {
    struct Student data;
    struct StudentLink *next;
} StudentLink;

// 返回链长度
int getLinkLangth(StudentLink *p) {
    int i = 0;
    while(p->next != NULL) {
        ++ i;
        p = p->next;
    }
    
    return i;
}

/**
 * 初始化链
 * return StudentLink* 
 */
StudentLink* initLink() {
    StudentLink *l = (StudentLink *) malloc(sizeof(StudentLink));
    l->next = NULL;
    
    return l;
}

/**
 * 在链的最后插入数据
 * StudentLink *p 链
 * Student s 数据
 */
int insLink(StudentLink *p, Student s) {
    while(p->next != NULL) {
        p = p->next;
    }
    StudentLink *t = (StudentLink *) malloc(sizeof(StudentLink));
    p->data = s;
    p->next = t;
    
    return 0;
}

/**
 * 在链的头部插入数据
 * StudentLink *l 链
 * Student s 数据
 */
int insLinkHead(StudentLink *l, Student s) {
    StudentLink *t = (StudentLink *) malloc(sizeof(StudentLink));
    
    //t->data = s;
    //t->next = l;
    //*l = *t; 这个指针嵌套了不能这样写
    
    t->next = l->next;
    l->next = t;
    Student tt = l->data;
    l->data = s;
    t->data = tt;
    
    return 0;
}

/**
 * 在链的特定位置插入数据
 * StudentLink *l 链
 * Student s 数据
 * int index 位置
 */
int insLinkLo(StudentLink *l, Student s, int index) {
    StudentLink *per = l, *p = l->next;
    if(index < 1 || index > getLinkLangth(l)) {
        return 0;
    }
    
    StudentLink *t = (StudentLink *) malloc(sizeof(StudentLink));
    
    if(index == 1) {
        insLinkHead(l, s);
    } else {
        for(int i = 2; i < index; i ++) {
            per = p;
            p = p->next;
        }
        t->data = s;
        per->next = t;
        t->next = p;
    }
    
    
    return 0;
}


int insStudent(StudentLink *p, int id, char* name, char gender) {
    Student s = {id, "", gender};
    strcpy(s.name, name);
    
    insLink(p, s);
    
    return 0;
}

int insStudentHead(StudentLink *p, int id, char* name, char gender) {
    Student s = {id, "", gender};
    strcpy(s.name, name);
    insLinkHead(p, s);
    
    return 0;
}

int insStudentIndex(StudentLink *p, int index, int id, char *name, char gender) {
    Student s = {id, "", gender};
    strcpy(s.name, name);
    insLinkLo(p, s, index);
    
    return 0;
}

/**
 * 删除链通过名字
 */
int delLinkByName(StudentLink *l, char *name) {
    StudentLink *per = l ,*p = l->next; // 当前工作的节点
    
    // 删掉头部
    while(strcmp(per->data.name, name) == 0) {
        *l = *p;
        per = l;
        p = l->next;
    }
    
    while(p!= NULL) {
        if(strcmp(p->data.name, name) == 0) {
            per->next = p->next; // p的前驱的后续等于p的后续
            free(p);
            p = per->next;
            
        } else {
            per = p;
            p = p->next;
        }
    }
    return 0;
}

int delLinkById(StudentLink *l, int id) {
    StudentLink *per = l ,*p = l->next; // 当前工作的节点
    
    // 删掉头部
    while(per->data.id == id) {
        *l = *p;
        per = l;
        p = l->next;
    }
    
    while(p!= NULL) {
        if(p->data.id == id) {
            per->next = p->next; // p的前驱的后续等于p的后续
            free(p);
            p = per->next;
            
        } else {
            per = p;
            p = p->next;
        }
    }
    return 0;
}

int delLinkByGender(StudentLink *l, char gender) {
    StudentLink *per = l ,*p = l->next; // 当前工作的节点
    
    // 删掉头部
    while(per->data.gender == gender) {
        *l = *p;
        per = l;
        p = l->next;
    }
    
    while(p!= NULL) {
        if(p->data.gender == gender) {
            per->next = p->next; // p的前驱的后续等于p的后续
            free(p);
            p = per->next;
            
        } else {
            per = p;
            p = p->next;
        }
    }
    return 0;
}

int delLinkByIndex(StudentLink *l, int index) {
    
    if(index > getLinkLangth(l) || index < 1) {
        // 不可能的
        
        return 0;
    }
    
    StudentLink *per = l, *p = l->next;
    if(index == 1) {
        *l = *p;
        per = l;
        p = l->next;
    } else {
        for(int i = 2; i < index; i ++) {
            per = p;
            p = p->next;
        }
            per->next = p->next; // p的前驱的后续等于p的后续
            free(p);
            p = per->next;
    }
    
    
    return 0;
}

int delLinkByAll(StudentLink *l) {
    free(l);
    l = initLink();
    return 0;
}

void printStudent(Student s) {
    printf("id: %d\tname: %s\tgender: %c\n", s.id, s.name, s.gender);
}
/**
 * 列出链
 * StudentLink *p 一个链的指针
 */
void show(StudentLink *p) {
    printf("--------------------------------------------------\n");
    printf("链长度%d\n", getLinkLangth(p));
    while(p->next != NULL) {
        printStudent(p->data);
        p = p->next;
    }
}

int searchById(StudentLink *l, int id) {
    StudentLink *p = l;
    int i = 0;
    while(p != NULL) {
        if(p->data.id == id) {
            printStudent(p->data);
            i ++;
        }
        p = p->next;
    }
    return i;
}

int searchByGender(StudentLink *l, char gender) {
    StudentLink *p = l;
    int i = 0;
    while(p != NULL) {
        if(p->data.gender == gender) {
            printStudent(p->data);
            i ++;
        }
        p = p->next;
    }
    return i;
}

int searchByName(StudentLink *l, char *name) {
    StudentLink *p = l;
    int i = 0;
    while(p != NULL) {
        if(strcmp(p->data.name, name) == 0) {
            printStudent(p->data);
            i ++;
        }
        p = p->next;
    }
    return i;
}


void mainMenu() {
    printf("-------------------------------------------------------\n1. 插入操作\n2.删除操作\n3.查找操作\n4.显示全部\n9.退出\n\n");
}

void insMenu() {
    printf("-------------------------------------------------------\n1. 结尾插入\n 2.头部插入\n3.特定位置插入\n4. 退出\n");
}

void delMenu() {
    printf("--------------------------------------------------------\n1. 通过id删除\n2. 通过名字删除\n3. 通过位置删除\n4,删除所有\n9.退出\n");
}

void searchMenu() {
    printf("---------------------------------------------------------\n1.通过id查找\n2. 通过名字查找\n3. 通过性别查找\nq.退出\n");
}

void c_insEnd(StudentLink *l) {
    int id;
    char name[10], gender;
    printf("输入id name gender: ");
    scanf("%d %s %s", &id, name, &gender);
    
    int s = insStudent(l, id, name, gender);
    if(s == 0) {
        printf("插入数据成功\n");
    }
}

void c_insHead(StudentLink *l) {
    int id = 0;
    char name[10], gender;
    
    printf("输入id name gender: ");
    scanf("%d %s %s", &id, name, &gender);
    
    printf("id: %d name: %s gender %c\n", id, name, gender);
    int s = insStudentHead(l, id, name, gender);
    if(s == 0) {
        printf("插入数据成功\n");
    }
}

void c_insIndex(StudentLink *l) {
    int index = 0;
    int id = 0;
    char name[10], gender;
    
    printf("输入id name gender index: ");
    scanf("%d %s %s %d", &id, name, &gender, &index);
    
    printf("index %d id: %d name: %s gender %c\n", index, id, name, gender);
    int s = insStudentIndex(l, index, id, name, gender);
    if(s == 0) {
        printf("插入数据成功\n");
    }
}

void c_del_id(StudentLink *l) {
    int id = 0;
    printf("输入id :");
    scanf("%d", &id);
    int s = delLinkById(l, id);
    
    if(s == 0){
        printf("删除成功");
    }
}

void c_del_name(StudentLink *l) {
    char name[10];
    printf("输入名字: ");
    scanf("%s", name);
    
    int s = delLinkByName(l, name);
    
    if(s == 0) {
        printf("删除成功");
    }
}

void c_del_gender(StudentLink *l) {
    char gender;
    printf("输入性别(x或y): ");
    scanf("%s", &gender);
    
    int s = delLinkByGender(l, gender);
    
    if(s == 0) {
        printf("删除成功");
    }
}

void c_del_all(StudentLink *l) {
    int s = delLinkByAll(l);
    
    if(s == 0) {
        printf("删除成功");
    }
}

void c_search_id(StudentLink *l) {
    int id = 0;
    printf("输入id: ");
    scanf("%d", &id);
    searchById(l, id);
}

void c_search_name(StudentLink *l) {
    char name[10];
    printf("输入名字: ");
    scanf("%s", name);
    searchByName(l, name);
}

void c_search_gender(StudentLink *l) {
    char gender;
    printf("输入性别(x或y): ");
    scanf("%s", &gender);
    searchByGender(l, gender);
}

int main(int argc, char **argv) {
    // 初始化链
    StudentLink *sl = initLink();
    insStudentHead(sl, 1, "sagiri", 'x');
    
    int q = 0, c = -1, c1;
    while(q == 0) {
        mainMenu();
        scanf("%d", &c);
        
        
        switch(c) {
            case 1:
                insMenu();

                scanf("%d", &c1);
                

                switch(c1) {
                    case 1 :
                        c_insEnd(sl);
                        break;
                    case 2 :
                        c_insHead(sl);
                        break;
                    case 3 :
                        c_insIndex(sl);
                        break;
                }
                break;
            case 2: 
                delMenu();
                scanf("%d", &c);
                
                switch(c) {
                    case 1 :
                        c_del_id(sl);
                        break;
                    case 2 :
                        c_del_name(sl);
                        break;
                    case 3 :
                        c_del_gender(sl);
                        break;
                    case 4 :
                        c_del_all(sl);
                        break;
                    case 9 :
                        
                        break;
                    default :
                        
                        break;
                }
                
                break;
            case 3: 
                searchMenu();
                scanf("%d", &c);
                switch(c) {
                    case 1 :
                        c_search_id(sl);
                        break;
                    case 2 :
                        c_search_name(sl);
                        break;
                    case 3 :
                        c_search_gender(sl);
                        break;
                        
                    case 9 :
                        
                        break;
                    default :
                        
                        break;
                }
                break;
            case 4: 
                show(sl);
                break;
            case 9:
                q = 1;
                break;
            default :
                printf("错误\n");
                break;
        }
        
    }
    
    return 0;
}
