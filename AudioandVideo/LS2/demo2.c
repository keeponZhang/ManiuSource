#include <stdio.h>

//C 语言不允许返回一个完整的数组作为函数的参数,必须声明一个返回指针的函数

int * getArr(){
//
    static int nums[] = {1,2,3,4,5,6};
    return nums;
}

void getArr2(int *start, int *len){
    static int nums2[] = {1,2,3,4,5,6};

    printf("&nums2[0]=%p\n",&nums2[0]);
    *start = nums2;
    printf("start=%p\n",*start);
    *len = sizeof(nums2)/sizeof(nums2[0]);
}

int main(){
//{1,2,3,4,5,6}
	int *arr = getArr();
	
	for(int i=0;i<6;i++){
		printf("arr[%d]=%d  %p\n",i,*(arr+i),arr+i);
		// *arr 返回的指针指向数组的第一个元素，相当于下标0，通过增加指针值来访问数组元素
	}

    int *start;//野指针  当变量在用  亅
	int len=0;
//	二级指针
	getArr2(&start,&len);
    printf("----start=%p\n", start);
//	printf("start=%p, *start=%d, len=%d\n",start,*start,len);//!!!此处打印的start保存的数组首元素地址就变了
	
	for(int i=0;i<len;i++){
		printf("arr2[%d]=%d  start=%p \n",i,start[i],start+i);
	}
	
}

/*void printArr(int *start,int *len)
{
	for(int i=0;i<*len;i++){
		
	}
}*/


