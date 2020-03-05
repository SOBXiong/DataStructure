#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

#define LINEAR_INIT_SIZE 20 // 初始分配量
#define LINEAR_INCREMENT 10 // 分配增量
typedef int ElemType;       //定义ElemType为int类型
typedef struct
{
    ElemType *elem; // 存储空间基址
    int length;     // 当前长度
    int linearSize; // 当前分配的存储容量(sizeof(ElemType)为单位)
} lTable;

/*
	构造一个空的线性表L
	C语言中没有引用,C++才有
*/

// 初始化线性表
Status initList(lTable *lt)
{
    lt->elem = (ElemType *)malloc(sizeof(ElemType) * LINEAR_INIT_SIZE);
    if (!lt->elem)
        exit(OVERFLOW);
    lt->length = 0;
    lt->linearSize = LINEAR_INIT_SIZE;
    return OK;
}

// 销毁线性表
void DestoryList(lTable **lt)
{
    if (*lt != NULL)
    {
        free((*lt)->elem);
        free(*lt);
    }
    *lt = NULL;
}

// 将L重置为空表
void ClearList(lTable *lt)
{
    // 可只设置长度为0
    // for (int i = 0; i < lt->length; i++) lt->elem[i] = 0;
    lt->length = 0;
}

// 判断是否为空
Status ListEmpty(lTable lt)
{
    return lt.length == 0 ? TRUE : FALSE;
}

// 返回线性表的长度
int ListLength(lTable lt)
{
    return lt.length;
}

// 用e取出lt中第i个元素的值
void GetElem(lTable lt, int i, ElemType *e)
{
    if (i < 1 || i > lt.length)
        return;
    *e = lt.elem[i - 1];
}

// 按位置插入元素
Status ListInsert(lTable *lt, int i, ElemType e)
{
    if (i < 1 || i > lt->length + 1)
        return ERROR;
    if (lt->length >= lt->linearSize)
    {
        ElemType *base = NULL;
        base = (ElemType *)realloc(lt->elem,
                                   (lt->linearSize + LINEAR_INCREMENT) * sizeof(ElemType));
        if (!base)
            exit(OVERFLOW);
        // 如果基址不与elem一致
        if (lt->elem != base)
        {
            ElemType *s = lt->elem;
            lt->elem = base;
            free(s);
        }
        lt->linearSize += LINEAR_INCREMENT;
    }
    ElemType *q = &(lt->elem[i - 1]);
    for (ElemType *p = &(lt->elem[lt->length - 1]); p >= q; --p)
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++lt->length;
    return OK;
}

// 尾插元素
Status InsertEnd(lTable *lt, ElemType e)
{
    return ListInsert(lt, lt->length + 1, e);
}

// 按位置删除元素
Status ListDelete(lTable *lt, int i, ElemType *e)
{
    if (i < 1 || i > lt->length)
        return ERROR;
    ElemType *p = &lt->elem[i - 1];
    *e = *p;
    ElemType *q = lt->elem + lt->length - 1;
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p;
    }
    --lt->length;
    return OK;
}

// 元素遍历
void ListTraverse(lTable lt, void (*visit)(int, ElemType))
{
    for (int i = 0; i < lt.length; i++)
    {
        (*visit)(i, lt.elem[i]);
    }
}

// 遍历具体函数
void visit(int i, ElemType e)
{
    printf(" >>> the data in index %2d is %2d \n", i, e);
}

// 是否相等的比较函数
Status compare(ElemType e1, ElemType e2)
{
    return e1 == e2 ? TRUE : FALSE;
}

// 返回元素e第一次出现在线性表中的位置
int LocateElem(lTable lt, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i = 1;
    ElemType *p = lt.elem;
    while (i <= lt.length && !(*compare)(*p++, e))
        i++;
    if (i <= lt.length)
        return i;
    return 0;
}

// 返回元素e的前一个元素
Status PriorElem(lTable lt, ElemType e, ElemType *pre)
{
    int cIndex = LocateElem(lt, e, compare);
    if (cIndex <= 1)
        return ERROR;
    *pre = lt.elem[cIndex - 2];
    return OK;
}

// 返回元素e的后一个元素
Status NextElem(lTable lt, ElemType e, ElemType *next)
{
    int cIndex = LocateElem(lt, e, compare);
    if (cIndex == 0 || cIndex == ListLength(lt))
        return ERROR;
    *next = lt.elem[cIndex];
    return OK;
}

// A = A∪B
void unionlTables(lTable *lta, lTable ltb)
{
    int lengthB = ListLength(ltb);
    ElemType e;
    for (int i = 1; i <= lengthB; i++)
    {
        GetElem(ltb, i, &e);
        int index = LocateElem(*lta, e, compare);
        if (!index)
        {
            InsertEnd(lta, e);
        }
    }
}

// 非递减的A和B合并成C(下标)
void MergeListPlanA(lTable lta, lTable ltb, lTable *ltc)
{
    int i, j;
    i = j = 1;
    int k = 0;
    int lengthA = ListLength(lta);
    int lengthB = ListLength(ltb);
    ElemType ai, bi;
    while (i <= lengthA && j <= lengthB)
    {
        GetElem(lta, i, &ai);
        GetElem(ltb, j, &bi);
        if (ai <= bi)
        {
            ListInsert(ltc, ++k, ai);
            i++;
        }
        else
        {
            ListInsert(ltc, ++k, bi);
            j++;
        }
    }
    while (i <= lengthA)
    {
        GetElem(lta, i++, &ai);
        ListInsert(ltc, ++k, ai);
    }
    while (j <= lengthB)
    {
        GetElem(ltb, j++, &bi);
        ListInsert(ltc, ++k, bi);
    }
}

// 非递减的A和B合并成C(指针)
void MergeListPlanB(lTable lta, lTable ltb, lTable *ltc)
{
    ElemType *pa = lta.elem;
    ElemType *pb = ltb.elem;
    ltc->linearSize = ltc->length = lta.length + ltb.length;
    ElemType *pc = ltc->elem = (ElemType *)malloc(ltc->linearSize * sizeof(ElemType));
    if (!ltc->elem)
        exit(OVERFLOW);
    ElemType *qa = pa + lta.length - 1;
    ElemType *qb = pb + ltb.length - 1;
    while (pa <= qa && pb <= qb)
    {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while (pa <= qa)
        *pc++ = *pa++;
    while (pb <= qb)
        *pc++ = *pb++;
}

int main()
{
    lTable *la, *lb, *lc;
    la = (lTable *)malloc(sizeof(lTable));
    lb = (lTable *)malloc(sizeof(lTable));
    lc = (lTable *)malloc(sizeof(lTable));
    initList(la);
    initList(lb);
    initList(lc);
    int i = 1;
    while (ListLength(*lb) != 10)
    {
        int a = i % 2;
        int b = i % 3;
        if (a == 0 && ListLength(*la) != 10)
        {
            InsertEnd(la, i);
        }
        if (b == 0)
        {
            InsertEnd(lb, i);
        }
        ++i;
    }
    printf("Before Merge la >>> \n");
    ListTraverse(*la, visit);
    printf("\nBefore Merge lb >>> \n");
    ListTraverse(*lb, visit);
    printf("\n");
    MergeListPlanB(*la, *lb, lc);
    printf("After Merge lc >>> \n");
    printf("lc length >>> %d\n", ListLength(*lc));
    ListTraverse(*lc, visit);
    return 0;
}