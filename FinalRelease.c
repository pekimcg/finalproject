/* This is the final release of the calculator Project. This will be a console based calculator application written using the C programming language
*/

#include <stdio.h>
#include <stdlib.h>

int main()

{
	char operator; // Defining my operators 
	struct numbers { // Creating and giving meaning to the following below
		float num1;
		float num2;
		float result;
	};
	int count = 0;
	struct numbers calcnum;
	FILE* fp; //creating a pointer variable of type file to hold the address of the file location
		//fp = fopen_s("C:/Calculator/log.txt", "w+"); //This will open the page to the file and store the address in fp
		errno_t err;
		if ((err = fopen_s(&fp, "C:/Calculator/log.txt", "w+")) != 0) // This will locate the file in my computer and write everything in the output when i run the program
			printf("File was not opened\n");
		else
		{
			fprintf(fp, "File Created on Date: %s, Time: %s \n", __DATE__, __TIME__); // The file will says when it was created on and the time


			printf("starting program");
			while (count < 6) // This will loop my program five times, this means the computer will ask you six times what operation you would like to perform 
			{

				printf("Enter the operator ( +,-,*,/) :\n "); //Computer asking the user to pick a math operator from the given choices 
				scanf_s(" %c", &operator,1); // This is store the operator so the computer will know what math operator you have chosen
				

				printf("Enter the two numbers one by one :\n "); // Computer asking the user to pick two numbers to perform their operation of choice 
				scanf_s("%f %f", &calcnum.num1, &calcnum.num2); // This is store the numbers so the computer will remember to perform these functions

				switch (operator) //The operation cases
				{
				case '+': //For addition
					calcnum.result = calcnum.num1 + calcnum.num2; // Implementing the struct method and this will calculate the 2 numbers according to the  addition operator and give the user an asnwer.
					printf("%.2f %c %.2f = %.2f \n", calcnum.num1, operator, calcnum.num2, calcnum.result); // This will print the results of the whole calculation in the output screen
					fprintf(fp, "The result of %.2f %c %.2f = %.2f \n", calcnum.num1, operator, calcnum.num2, calcnum.result); // This will print the outcome to our file 
					break; 

				case '-': // For subtraction
					calcnum.result = calcnum.num1 - calcnum.num2; // Implementing the struct method and this will calculate the 2 numbers according to the subtraction operator and give the user an asnwer.
					printf("%.2f %c %.2f = %.2f \n", calcnum.num1, operator, calcnum.num2, calcnum.result); // This will print the results of the whole calculation in the output screen
					fprintf(fp, "The result of %.2f %c %.2f = %.2f \n", calcnum.num1, operator, calcnum.num2, calcnum.result); // This will print the outcome to our file
					break;

				case '*': //multiplication
					calcnum.result = calcnum.num1 * calcnum.num2; // Implementing the struct method and this will calculate the 2 numbers according to the multiplication operator and give the user an asnwer.
					printf("%.2f %c %.2f = %.2f \n", calcnum.num1, operator, calcnum.num2, calcnum.result); // This will print the results of the whole calculation in the output screen
					fprintf(fp, "The result of %.2f %c %.2f = %.2f \n", calcnum.num1, operator, calcnum.num2, calcnum.result); // This will print the outcome to our file
					break;

				case 'd': //D case rule
					
					 calcnum.result =  calcnum.num1 /  calcnum.num2; // Implementing the struct method and this will calculate the 2 numbers according to the D (division) operator and give the user an asnwer.
					printf("%f %c %f = %d \n", calcnum.num1, operator, calcnum.num2, (int) calcnum.result); // this will not display it as a decimal by typecasting the float to an int
						fprintf(fp, "The result of %f %c %f = %d \n", calcnum.num1, operator, calcnum.num2, (int) calcnum.result); // This will print the outcome in our file
						break;

				case '/': // Divison
					if (calcnum.num2 != 0.0) // If the second number the user chooses is 0
					{
						calcnum.result = calcnum.num1 / calcnum.num2; // Implementing the struct method and this will calculate the 2 numbers according to the division operator and give the user an asnwer.
						printf("%.2f %c %.2f = %.2f \n", calcnum.num1, operator, calcnum.num2, calcnum.result); // This will print the results of the whole calculation in the output screen
						fprintf(fp, "The result of %.2f %c %.2f = %.2f \n", calcnum.num1, operator, calcnum.num2, calcnum.result); // This will print the outcome in our file
					}
					else // Should the coumptuer detect the user wants to divide by 0
					{
						printf("Sorry you cannot divide by 0 \n"); // The output screen will display that they cannot divide by 0
						fprintf(fp, "Sorry you cannot divide by 0 \n"); // The error message will be displayed in our file as well
					}
				

					break;

				default:
					printf("Invalid Operator\n"); // If the user does not perform the steps asked by the computer the user will see that their rquest is not valid and cannot be performed


				}



				printf("\n \n ****************************************** \n "); // This is just a line drawn to make the output screen look more tidy
				count++;


			}
		}
	fclose(fp); //Close my file

	return 0;

}