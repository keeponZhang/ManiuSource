#include <stdio.h>
// sizeStat类
#include<sys/stat.h>
#include <malloc.h>
#define   BLOCK_SIZE 1024*64 //64K
int main(int argc, char** argv) {
//    argv[0]
    FILE *pr = fopen(argv[1], "rb");
    printf("path1 : %s", argv[1]);
    if (pr == NULL) return 0;
    FILE *pw = fopen(argv[2], "wb");
    printf("path2 : %s", argv[2]);
    if (pr == NULL) return 0;
    if(pw == NULL) return 0;
    struct  stat st={0};
    //能够读出文件的大小
    stat(argv[1], &st);
    int size = st.st_size;
    if(size >BLOCK_SIZE) {
        size = BLOCK_SIZE;
    }
    printf("size = %d\n", size);

    char *buf = calloc(1, size);
    unsigned  int index = 0;//正数
    while (!feof(pr)) {
        int res = fread(buf, 1, size, pr);
        fwrite(buf, 1, res, pw);
        index++;
    }
    free(buf);
    fclose(pw);
    fclose(pr);
    pw = NULL;
    pr = NULL;
    printf("index=%ld\n",index);
    return 0;
}
