#include <stdio.h>
#include <math.h>
int main()
{
float Con, Exam;
const float ConPass = 0.4 * 50;
const float ExamPass = 0.4 * 100;
const float ConLow = 0.35 * 50;
const float ExamLow = 0.35 * 100;
const float ConHigh = 0.8 * 50;
const float ExamHigh = 0.8 * 100;
printf("Please input the score for the continuous assessment: ");
scanf("%f", &Con);
printf("Please input the score for the exam: ");
scanf("%f", &Exam);

if(Con >= ConPass && Exam >= ExamPass){
printf("Passed :D\n");
}
else if(((Con >= ConLow && Con <=ConPass) && (Exam > ExamHigh)) ||((Exam >= ExamLow && Exam <=ExamPass) && (Con > ConHigh))){
printf("Pushed up :|\n");
}
else{
printf("Failed :(\n");
}

return 0;
}
