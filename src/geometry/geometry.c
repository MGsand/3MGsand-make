#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../src/lib/circle.h"

int main()
{
    int i=0,check=0,cout=0,erb=0,c=0;
    char name[20],stl[7]="circle";
    float P,S,a,r,PI=3.14;
    
    fgets(name,20,stdin);
    
    
    
    while (i < 20){
        if(name[i]==' '){
            i++;
        }
        if(strncmp(name,stl,6) !=0 ){
            if(check == 1)break;
            
            puts (name);
            printf(" expected circle");
            break;
        }else{
            check++;
            i+=6;
        }
        
        if(name[i] != '('){
            if(cout == 1)break;
            puts (name);
            printf(" expected '('");
            break;
        }else{
            i++;
            cout++;
        }
        
        if('0' <= name[i] && name[i] <= '9'){
           
            a=name[i] - '0';
            
            i++;
            erb++;
            
        }else{
            if(erb == 1)break;
            puts (name);
            printf(" expected number ");
            break;
        }
        
        if(name[i] != ','){
            if(c == 1)break;
            puts (name);
            printf(" expected ','");
            
            break;
        }else{
            i++;
            c++;
        }
        
         if('0' <= name[i] && name[i] <= '9'){
            r=name[i] - '0';
            i++;
             P=2*PI*r;
              printf("\n P=%f",P);
             S=PI*r*r;
              printf("\n S=%f",S);
            
        }else{
            if(erb == 1)break;
            puts (name);
            printf(" expected number ");
            break;
        }
        
        
     /*   if(name[i] != ','){
            if(check == 4)break;
            puts (name);
            printf(" expected ','");
            break;
        }else{
            i++;
            check++;
        }
        
          if('0' <= name[i] && name[i] <= '9'){
             c1=name[i] - '0';
            i++;
            
            
        }else{
            if(erb == 1)break;
            puts (name);
            printf(" expected number ");
            break;
        }*/
        
         if(name[i] != ')'){
            if(check == 6)break;
            puts (name);
            printf(" expected ')'");
            break;
        }else{
            i++;
            check++;
        }
        
           if('0' <= name[i] && name[i] <= '9'){
             if(erb == 1)break;
            puts (name);
            printf(" expected number ");
            break;
        }else{
           i++;
        }
        
        
        
    }
    circle(r, &a, &P);

    
     //puts(name);

    return 0;
}
