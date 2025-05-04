/*Student grading system*/

#include <stdio.h>

int main(){
	float ca_mark, exam_mark;
	float ca_percent, exam_percent;

	printf("Enter Continuous Assessment mark (out of 50): ");
	scanf("%f", &ca_mark);
	printf("Enter Exam mark (out of 100): ");
	scanf("%f", &exam_mark);

	ca_percent = (ca_mark / 50.0) * 100;
	exam_percent = (exam_mark / 100.0) * 100;

	if(ca_percent > 40 && exam_percent > 40){
		printf("Result: Pass\n");
	}
	else if((ca_percent > 80 && exam_percent >= 35 && exam_percent <= 40) || (exam_percent > 80 && ca_percent >= 35 && ca_percent <= 40)){
		printf("Result: Pushed Up\n");
	}
	else {
		printf("Result: Fail\n");
	}

	return 0;
}
