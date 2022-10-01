#include <stdio.h>
#include <malloc.h>

//c---->.o---->.exe
//java -class- jar
int main1() {
    printf("---------main1---------------\n");
    printf("file write\n");
    FILE *p = fopen("./test/maniu.txt", "w");
    if (p) {
        fclose(p);
//        p 悬空指针
        p = NULL;
//        文件存在
    } else {

    }
    return 0;
}
//读文件
int main2() {
    printf("---------main2---------------\n");
}
//读文件
int main3() {
    printf("---------main3---------------\n");
    printf("file read\n");
    FILE *p = fopen("./test/maniu.txt", "r");

    if (p) {
        char c = fgetc(p);
        printf("char %c\n", c);
    }
    fclose(p);
//        p 悬空指针
    p = NULL;
}

//循环读文件
int main4() {
    printf("---------main4---------------\n");
    printf("file read\n");
    FILE *p = fopen("./test/maniu.txt", "r");
    if (p) {
        while (1) {
            char c = fgetc(p);
            if (c == EOF) {
                break;
            }
            printf("char %c\n", c);
        }
    }
    fclose(p);
//        p 悬空指针
    p = NULL;
}

//写文件
int main5() {
    printf("---------main5---------------\n");
    printf("file write\n");

    FILE *p = fopen("./test/maniu.txt", "w");
    if (p) {
        fputc('a', p);
        fclose(p);
        p = NULL;
    }
}

//copy文件
int main6() {
    printf("---------main6---------------\n");
    printf("file copy\n");
    FILE *p = fopen("./test/maniu.txt", "r");
    FILE *p1 = fopen("./test/write.txt", "w");
    if (p == NULL || p1 == NULL) {
        return -1;
    }
    while (1) {
        char c = fgetc(p);
        if (c == EOF) {
            break;
        }
        fputc(c, p1);
    }
    fclose(p);
    fclose(p1);
    p = NULL;
    p1 = NULL;
}

int cacl(int a, char b, int c) {
    int result = 0;
    switch (b) {
        case '+':
            result = a + c;
            break;
        case '-':
            result = a - c;
            break;
        case '*':
            result = a * c;
            break;
        case '/':
            result = a / c;
            break;
    }

    return result;
}

int main() {
    //main1();
    //main2();
    main3();
    main4();
    main5();
    main6();

}

void testOriginal() {
    // 字符串读写       二进制的读写
//视频文件  声音   写到
//剪影        视频 --》音频 pcm--》
    printf("file copy\n");
    FILE *p = fopen("./test/maniu.txt", "r");

    if (p) {

        while (1) {
            char buffer[100] = {0};
            fgets(buffer, sizeof(buffer), p);

            int a = 0;
            char b = 0;
            int c = 0;
            sscanf(buffer, "%d%c%d", &a, &b, &c);
//            printf("a %d  b %c c %d\n", a, b, c);
            printf("result %d \n ", cacl(a, b, c));
            if (feof(p)) {
                break;
            }
        }
        fclose(p);
        p = NULL;
    }
}