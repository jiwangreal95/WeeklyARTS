/*
题目描述  
张景中院士给青少年出过一道趣题。这道题来自阿拉伯传统故事，有个老父亲，有17头羊，临终前把三个儿子叫来。分给大儿子一半的羊，二儿子1/3的羊，小儿子1/9的羊。
三个儿子不知道怎么分，只好请叫邻居。聪明的邻居借给了他们一头羊，这样总共就有18头。大儿子领走一半9头羊，二儿子领走1/3共6头羊，小儿子领走1/9，也就是2头羊。邻居最后把借的羊牵回去了。
我们的问题是，满足这样条件的数字还有哪些？即遗产有n头羊，大儿子分得1/x, 二儿子分得1/y, 小儿子分得1/z，邻居借给一头羊。请编程找出这些满足条件的(n, x, y, z)。

解析：
(n+1) 是 xyz的最小公倍数

根据不等式 1/2 + 1/3 + 1/7 >= 1/x + 1/y + 1/z
求出n的最大值为41.
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,x,y,z,counter;
    for(x = 1;x < 50;x++){
        for(y = 1;y < 50;y++){
            for(z = 1; z < 50;z++){
                for(n = 1;n < 50;n++){
                    //判断条件 1，等式成立；2，x y z 三个值不相等；3，n要大于 x y z三个任一的值；4，x > y > z
                    if(((n+1)*(y*z + x*z + x*y) == n*x*y*z) && (x != y && x != z && y!=z) && (((n+1) >= x && (n+1) >= y && (n+1) >= z))) {
                        if ((x>y && y>z) && ((n+1)%x == 0 && (n+1)%y == 0 && (n+1)%z == 0)){
                            printf("n=%d,x=%d,y=%d,z=%d\n",n,x,y,z);
                            counter++;
                        }
                    }
                }
            }
        }
    }

    printf("满足条件的(n, x, y, z)为%d\n",counter);

    return 0;
}

/*
Output
n=19,x=5,y=4,z=2
n=11,x=6,y=4,z=2
n=41,x=7,y=3,z=2
n=23,x=8,y=3,z=2
n=7,x=8,y=4,z=2
n=17,x=9,y=3,z=2
n=11,x=12,y=3,z=2
满足条件的(n, x, y, z)为7
*/
