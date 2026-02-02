#include <stdio.h>


struct Student {
    int r_no;
    char name[50];
    float marks;
};

int main() {
    struct Student students[3]; 

    
    for(int i = 0; i < 3; i++) {
        printf("Enter details for student %d\n", i+1);

        printf("r_no: ");
        scanf("%d", &students[i].r_no);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);  

        printf("Marks: ");
        scanf("%f", &students[i].marks);

        printf("\n");
    }

   
    printf("Student details:\n");
    for(int i = 0; i < 3; i++) {
        printf("r_no: %d, Name: %s, Marks: %.2f\n", students[i].r_no, students[i].name, students[i].marks);
    }

    return 0;
}

