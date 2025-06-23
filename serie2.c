#include <stdio.h>
#include <math.h>

int main (){
    //Exercice 1 :

    // printf("saise 3 numbre ici :");
    // int num1,num2,num3,max;
    // scanf("%d %d %d",&num1,&num2,&num3);

    // if (num1>num2 && num1>num3){
    //     max = num1;
    // }else if (num2>num1 && num2>num3)
    // {
    //     max = num2;
    // }else if (num3>num1 && num3>num2)
    // {
    //     max = num3;
    // }else if (num1==num2 && num1==num3)
    // {
    //     printf("egalite de tout");
    //     return 0;
    // }

    // printf("le maximum est : %d",max);

    //Exercice 2 :

    // printf("Entrez la moyenne generale : ");
    // int moy;
    // char *montion;
    // scanf("%d", &moy);

    // if (moy <= 20 && moy >= 16) {
    //     montion = "tres bien";
    //     printf("Votre mention est : %s\n", montion);
    // } else if (moy < 16 && moy >= 14) {
    //     montion = "bien";
    //     printf("Votre mention est : %s\n", montion);
    // } else if (moy < 14 && moy >= 12) {
    //     montion = "assez bien";
    //     printf("Votre mention est : %s\n", montion);
    // } else if (moy < 12 && moy >= 10) {
    //     montion = "passable";
    //     printf("Votre mention est : %s\n", montion);
    // } else if (moy < 10 && moy >= 0) {
    //     montion = "reddublegne";
    //     printf("Votre mention est : %s\n", montion);
    // } else {
    //     printf("Il y a une erreur dans la saisie de la moyenne !!!\n");
    // }

    //Exercice 3 :

    // printf("donne moi les 3 facteur A B et C : \n");
    // float A,B,C;
    // double D;
    // scanf("%f %f %f",&A,&B,&C);

    // if (A==0){
    //     printf("A est egale 0 donne une autre valeur \n");
    //     scanf("%f %f %f",&A,&B,&C);
    // }

    // D = pow(B,2) - 4 * A * C;

    // printf("DELTA = %f\n",D);

    // if (D>0)
    // {
    //     double X1,X2;
    //     X1 = (-B - sqrt(D)) / (2.0 * A);
    //     X2 = (-B + sqrt(D)) / (2.0 * A);
    //     printf("il y a deux solution\n");
    //     printf("X1 = %.2f , X2 = %.2f \n",X1,X2);
    //     printf("S = { %.2f , %.2f } \n",X1,X2);
    // }else if (D<0)
    // {
    //     printf("Aucune solution reelle\n");
    //     printf("S = vide \n");
    // }
    // else if (D==0)
    // {
    //     double X;
    //     X = -B / (2.0 * A);
    //     printf("il y a une solution\n");
    //     printf("X = %.2f \n",X);
    //     printf("S = %.2f \n",X);
    // }

    //Exercice 4 :

    // float W,H,BMI,PI ;
    // char G ;
    // char *S;

    // printf("Enter your height (in cm):\n");
    // scanf("%f",&H);
    // printf("enter your Weight (in kg):\n");
    // scanf("%f",&W);
    // printf("enter your gender (F/H):\n");
    // scanf("%s",&G);

    // if (G == 'F'){
    //     PI = (H - 100) - (H - 150) / 4 ;
    //     printf("your PI (poids ideal) is : %.2f \n",PI);
    // }else if (G == 'H')
    // {
    //     PI = (H - 100) - (H - 120) / 4 ;
    //     printf("your PI (poids ideal) is : %.2f \n",PI);
    // }

    // BMI = W / pow(H /100,2) ;

    // printf("your BMI (Body Mass Index) is : %.2f \n",BMI);

    // if (BMI<=25 && BMI>=16)
    // {
    //     S = "Normal";
    // }
    // else if (BMI>27 && BMI<32)
    // {
    //     S = "Overweight";
    // }
    // else if (BMI>=32 && BMI<60)
    // {
    //     S = "Obesity";
    // }
    // else
    // {
    //     S = "Unnormal";
    // }
    
    // printf("une personne est consideree comme : %s \n",S);

    //Exercice 5 :

    // int num ;
    // printf("give me the number of mount in the year and i tall witch mount is this :");
    // scanf("%d",&num);

    // switch (num)
    // {
    // case 1:
    //     printf("its Jan :)");
    //     break;
    // case 2:
    //     printf("its Feb :)");
    //     break;
    // case 3:
    //     printf("its Mar :)");
    //     break;
    // case 4:
    //     printf("its Apr :)");
    //     break;
    // case 5:
    //     printf("its May :)");
    //     break;
    // case 6:
    //     printf("its Jun :)");
    //     break;
    // case 7:
    //     printf("its Jul :)");
    //     break;
    // case 8:
    //     printf("its Aug :)");
    //     break;
    // case 9:
    //     printf("its Sep :)");
    //     break;
    // case 10:
    //     printf("its Oct :)");
    //     break;
    // case 11:
    //     printf("its Nov :)");
    //     break;
    // case 12:
    //     printf("its Dec :)");
    //     break;
    
    // default:
    //     printf("you're joking :D");
    //     break;
    // }

    //Exercice 6 :

    // double num1, num2, res;
    // char opt;

    // printf("num1: ");
    // scanf("%lf", &num1);

    // printf("num2: ");
    // scanf("%lf", &num2);

    // printf("operator: ");
    // scanf(" %c", &opt);

    // switch (opt) {
    //     case '+':
    //         res = num1 + num2;
    //         break;
    //     case '-':
    //         res = num1 - num2;
    //         break;
    //     case '*':
    //         res = num1 * num2;
    //         break;
    //     case '/':
    //         if (num2 != 0)
    //             res = num1 / num2;
    //         else {
    //             printf("Error: Division by zero.\n");
    //             return 1;
    //         }
    //         break;
    //     case '^':
    //         res = pow(num1, num2);
    //         break;
    //     default:
    //         printf("Error: Unsupported operator.\n");
    //         return 1;
    // }
    
    // printf("Result: %.2lf\n", res);

    //Exercice 7 :

    // int num ,mod ;
    // printf("donne un numbre :");
    // scanf("%d",&num);

    // mod = num % 2 ;

    // if ( mod == 0 ){
    //     printf("num pair");
    // }else{
    //     printf("num impaire");
    // }

    //Exercice 8 :



    return 0;
};