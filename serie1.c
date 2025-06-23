#include <stdio.h>
#include <math.h>

int main (){

    //Exercice 2 :

    // printf("donne moi le premier reel :\n");
    // int A;
    // scanf("%d",&A);

    // printf("donne moi le deuxieme reel :\n");
    // int B;
    // scanf("%d",&B);

    // int S = A + B;
    // int D = A - B;
    // int M = A * B;
    // int DI = A / B;
    // int MO = A % B;

    // printf("somme : %d\n",S);
    // printf("différence : %d\n",D);
    // printf("multiplication : %d\n",M);
    // printf("division : %d\n",DI);
    // printf("reste : %d\n",MO);

    //Exercice 3 :

    // printf("donne moi le premier nombre :");
    // int num1;
    // scanf("%d",&num1);

    // printf("donne moi le premier nombre :");
    // int num2;
    // scanf("%d",&num2);

    // int moyenne = (num1 + num2) / 2;
     
    // if (moyenne<=0 || moyenne>=20){
    //     printf("il y a une erreur done le saisir des note !!!");
    //     return 0;
    // };

    // printf("la moyenne est : %d/20",moyenne);

    //Exercice 4 :
    //1
    // int A = 5;
    // int B = 2;
    // int C = A;

    // A = B ;
    // B = C ;
    
    // printf("A = %d ,B = %d",A,B);
    //2
    // int A = 5;
    // int B = 2;
    // int C = 10;
    // int D = A;

    // A = B ;
    // B = C ;
    // C = D ;
    
    // printf("A = %d ,B = %d,C = %d",A,B,C);

    //Exercice 5 :

    // printf("donne moi le rayon de cercle :");
    // int R;
    // scanf("%d",&R);

    // const double PI = 3.14159;
    // float surface , circonférence;

    // surface = 2 * PI * R;
    // circonférence = PI * pow(R,2);

    // printf("la surface est : %.2f \n",surface);
    // printf("la circonference est : %.2f",circonférence);

    printf("donne moi le rayon de cercle :");
    char* s;
    scanf("%c",&s);

    char* result = (char*)malloc(9 * sizeof(char));
    
    int hour = ((s[0] - '0') * 10) + (s[1] - '0');
    char am_pm = s[8];

    if (am_pm == 'A' && hour == 12) {
        hour = 0; 
    } else if (am_pm == 'P' && hour != 12) {
        hour += 12; 
    }
    
    sprintf(result, "%02d:%c%c:%c%c", hour, s[3], s[4], s[6], s[7]);

    printf(result);


    return 0;
}