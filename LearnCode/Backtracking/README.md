# Backtracking 回溯

```sparks
递归实现
算法ReBack(k)
if k>n then <x1,x2,...,xn>是解
else while Sk ≠ ∅ do
    xk ← Sk中最小值
    Sk ← Sk - {xk}
    计算S[k+1]
    ReBack(k+1)
算法 ReBacktrack(n)
输入: n
输出: 所有的解
for k ← 1 to n 计算Xk且Sk ← Xk
ReBack(1)
```

```sparks
迭代算法Backtrack
输入: n
输出: 所有的解
对于i=1,2,...,n确定Xi // 确定初始取值
k ← 1
计算Sk
while: while Sk ≠ ∅ do // 满足约束分支搜索
    xk ← Sk中最小值; Sk ← Sk-{xk}
    if k < n then
        k ← k+1; 计算Sk
    else <x1,x2,...,xn>是解
if k > 1 then k ← k-1; goto while // 回溯
```

> 装载问题 - [LoadingProblem](LoadingProblem.c)
>
> 着色问题 - [ColoringProblem] (ColoringProblem.c)
>
> 最大团问题 - [MaximumClique](MaximumClique.c)
>
> 货郎问题 - [TravelingSalesman](TravelingSalesman.c)
>
> 圆排列问题 - [CirclePermutation](CirclePermutation.c)
>
> 连续邮资问题 - [ContinuousPostage](ContinuousPostage.c)
>