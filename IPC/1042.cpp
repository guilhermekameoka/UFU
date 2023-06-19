// 1042

#include <stdio.h>

int main(){

    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    if (x>y && y>z){
        printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", z, y, x, x, y, z);
    }else if (x>z && z>y){
        printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", y, z, x, x, y, z);
    }else if (z>y && y>x){
        printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", x, y, z, x, y, z);
    }else if (z>x && x>y){
        printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", y, x, z, x, y, z);
    }else if (y>x && x>z){
        printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", z, x, y, x, y, z);
    }else{
        printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", x, z, y, x, y, z);
    }
}