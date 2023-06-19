// 1036

#include <stdio.h>
#include <math.h>

int main() {
  
  double a, b, c, delta, r1, r2, raizdelta;
  scanf("%lf %lf %lf", &a, &b, &c);
  delta=pow(b,2)-(4*a*c);
  raizdelta=sqrt(delta);
  r1 = (-b + raizdelta)/(2*a);
  r2 = (-b - raizdelta)/(2*a);
    if(raizdelta<0 || a==0 || delta<0){
      printf("Impossivel calcular\n");
  }else{
    printf("R1 = %.5lf\nR2 = %.5lf\n", r1, r2);
  }
  }