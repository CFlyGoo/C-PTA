//
// 7-15 QQ帐户的申请与登陆 （25 分）
//实现QQ新帐户申请和老帐户登陆的简化版功能。最大挑战是：据说现在的QQ号码已经有10位数了。
//
//输入格式:
//输入首先给出一个正整数N（≤10^5)，随后给出N行指令。每行指令的格式为：“命令符（空格）QQ号码（空格）密码”。其中命令符为“N”（代表New）时表
// 示要新申请一个QQ号，后面是新帐户的号码和密码；命令符为“L”（代表Login）时表示是老帐户登陆，后面是登陆信息。QQ号码为一个不超过10位、但大
// 于1000（据说QQ老总的号码是1001）的整数。密码为不小于6位、不超过16位、且不包含空格的字符串。
//
//输出格式:
//针对每条指令，给出相应的信息：
//
//1）若新申请帐户成功，则输出“New: OK”；
//2）若新申请的号码已经存在，则输出“ERROR: Exist”；
//3）若老帐户登陆成功，则输出“Login: OK”；
//4）若老帐户QQ号码不存在，则输出“ERROR: Not Exist”；
//5）若老帐户密码错误，则输出“ERROR: Wrong PW”。
//
//输入样例:
//5
//L 1234567890 myQQ@qq.com
//N 1234567890 myQQ@qq.com
//N 1234567890 myQQ@qq.com
//L 1234567890 myQQ@qq
//L 1234567890 myQQ@qq.com
//
//输出样例:
//ERROR: Not Exist
//New: OK
//ERROR: Exist
//ERROR: Wrong PW
//Login: OK
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QQ_MAX_LEN 11
#define PWD_MAX_LEN 17

typedef struct __user *User;
typedef struct __user_repo *UserRepo;

UserRepo newUserRepo(int);

void registerUser(UserRepo, char *, char *);

User newUser(char *, char *);

void login(UserRepo, char *, char *);

User find(UserRepo, char *);

int idx(UserRepo, char *);

int hash(char *);

struct __user {
    char qq[QQ_MAX_LEN];
    char pwd[PWD_MAX_LEN];
    User next;
};

struct __user_repo {
    User *pails;
    int capacity;
};

int main(void) {
    int count;
    scanf("%d", &count); // NOLINT(cert-err34-c)
    UserRepo repo = newUserRepo(count);
    char command;
    char qq[QQ_MAX_LEN];
    char pwd[PWD_MAX_LEN];

    for (int i = 0; i < count; ++i) {
        getchar();
        scanf("%c %s %s", &command, qq, pwd);
        if ('N' == command)
            registerUser(repo, qq, pwd);
        else if ('L' == command)
            login(repo, qq, pwd);
    }
    return 0;
}

UserRepo newUserRepo(int capacity) {
    UserRepo repo = malloc(sizeof(struct __user_repo));
    repo->pails = malloc(sizeof(struct __user) * capacity);
    repo->capacity = capacity;
    for (int i = 0; i < capacity; ++i)
        repo->pails[i] = newUser("", "");
    return repo;
}

void registerUser(UserRepo repo, char *qq, char *pwd) {
    if (find(repo, qq) == NULL) {
        User pre = repo->pails[idx(repo, qq)];
        while (pre->next != NULL)
            pre = pre->next;
        pre->next = newUser(qq, pwd);
        printf("New: OK\n");
        return;
    }
    printf("ERROR: Exist\n");
}

User newUser(char *qq, char *pwd) {
    User user = malloc(sizeof(struct __user));
    strcpy(user->qq, qq);
    strcpy(user->pwd, pwd);
    user->next = NULL;
    return user;
}

void login(UserRepo repo, char *qq, char *pwd) {
    User user = find(repo, qq);
    if (user == NULL)
        printf("ERROR: Not Exist\n");
    else if (strcmp(user->pwd, pwd) == 0)
        printf("Login: OK\n");
    else
        printf("ERROR: Wrong PW\n");
}

User find(UserRepo repo, char *qq) {
    User user = repo->pails[idx(repo, qq)];
    while ((user = user->next) != NULL)
        if (strcmp(user->qq, qq) == 0)
            return user;
    return NULL;
}

int idx(UserRepo repo, char *s) {
    return hash(s) % repo->capacity;
}

int hash(char *s) {
    int hash = 0;
    for (int i = 0, len = (int) strlen(s); i < len; ++i)
        hash = 3 * hash + (s[i] - '0');
    return hash;
}