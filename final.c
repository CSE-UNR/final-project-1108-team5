//cs135
//josh chen
//josh morris
//chase grundy
//final group project
//due date:12/10/2024
//this progam takes a file and replaces N/V/A(nouns,verbs,adjectives) with user inputs
#include<stdio.h>
#define smol 100
#define big 1000
//prototype
void scan(int *nouns, int *verbs, int *adjs, char madlib[]);
void Uinputs(int nouns,int verbs, int adjs,char nounsA[][smol],char verbsA[][smol],char adjsA[][smol]);
void replaceNouns(int nouns, char nounsA[][smol],char madlib[],char result[],char plsfix[]);
void replaceVerbs(int verbs,char verbsA[][smol],char plsfix[],char result[]);
void replaceAdjs(int adjs, char adjsA[][smol],char plsfix[],char result[]);
int main(){
//this is something i found as an issue with segmentation faults or whatever, cant get past it
	printf("please dont use the capital letters of N, V, or A in the original madlib file or any of the prompts or else it ruins the whole thing\n");

//initiate integers to count how many nouns/verbs/adjectives there are in the file
	int nouns = 0, verbs = 0, adjs = 0;
//an array to store all  of the characters from the madlib txt file as a template and then another array to store the final result after changes
	char madlib[big] ={0};
	char result[big] ={0};
	char plsfix[big] ={0};
	result[6000] ='\0';//adding a terminate
//scans the file and adds value to the according variables for every N,V or A in the file
	scan(&nouns,&verbs,&adjs,madlib);
//2d arrays initialized with eariler variables to determine size
	char nounsA[nouns][smol];
	char verbsA[verbs][smol];
	char adjsA[adjs][smol];
//user inputs also if for some reason there arent any nouns/verbs/adjectives then it wont run the questions
	Uinputs(nouns,verbs,adjs, nounsA, verbsA, adjsA);
//and simply just replace all the N/V/A with user inputs from the 2d arrays
	replaceNouns(nouns,nounsA,madlib,result,plsfix);
	replaceVerbs(verbs,verbsA,plsfix,result);
	replaceAdjs(adjs,adjsA,plsfix,result);
//and print
	printf("here is the result: \n%s",result);

return 0;
}
//scan madlib for nouns verbs and adjectives and stores those values in integers
void scan(int *nouns, int *verbs, int *adjs, char madlib[]) { 
	FILE *madlibb = fopen("madlib.txt", "r"); 
	int read;
	int i = 0;
	for(i =0;(read = fgetc(madlibb)) != EOF;){//reads the madlib file until the end
		madlib[i++] = read; //stores the file into a string
	if(read == 'N'){
		(*nouns)++;//if the letter N is detected it adds 1 to the int nouns
	}else if(read == 'V'){ 
		(*verbs)++; //sane with this but with verbs and V
	}else if (read == 'A'){
		(*adjs)++;//and same with this
	}
	}
	madlib[6000] = '\0';//adds a terminate thingy so i can use it in future functions
	fclose(madlibb); 
}
//get inputs from the user
void Uinputs(int nouns,int verbs,int adjs,char nounsA[][smol],char verbsA[][smol],char adjsA[][smol]){
	
	if(nouns>0){
		for(int i = 0; i < nouns;i++){//asks the user to input nouns until the nouns integer is reached
			printf("Enter a noun: ");
			scanf("%69s", nounsA[i]);
			}
	}
	if(verbs>0){
	for(int i = 0; i < verbs;i++){//same as nouns but with verbs
		printf("Enter a verb: ");
		scanf("%69s", verbsA[i]);
		}
	}
	if(adjs>0){
	for(int i = 0; i < adjs;i++){//yea same thing
		printf("Enter an adjective: ");
		scanf("%69s", adjsA[i]);
		}
	}
}
//append/replace nouns to the result array
void replaceNouns(int nouns,char nounsA[][smol],char madlib[],char result[], char plsfix[]){
	int row = 0;//this thing is for selecting the row of the nounsA array
	int p =0;//just used for updating the result array
	for(int i =0; madlib[i]!= '\0'; i++){
		if(madlib[i] == 'N' && (row<nouns)){//this thing scans for the letter N
	 	for(int e=0; nounsA[row][e]!='\0';e++){//this loop replaces the letter N with the string stored in the nounsA array
	 		result[p++] = nounsA[row][e];
	 		
			}
			row++;//moves the array to the next row for the next string
		}else{
		result[p++] = madlib[i];//if N is not detected then the result array just matches whatever was in the madlib txt
		}
	}
	result[p++] = '\0';
	for(int i =0;result[i]!= '\0';i++){
		plsfix[i] =result[i];
	}
}
//verbs (not gonna explain it but its the same as the nouns one)
void replaceVerbs(int verbs,char verbsA[][smol],char plsfix[],char result[]){
	int row = 0;
	int p =0;
	for(int i =0;plsfix[i]!= '\0';i++){
		if(plsfix[i] == 'V' && (row<verbs)){
	 	for(int e=0; verbsA[row][e]!='\0';e++){
	 		result[p++] = verbsA[row][e];
			}
			row++;
		}else{
		result[p++] = plsfix[i];
		}
	}
	result[p++] = '\0';
	for(int i =0;result[i]!= '\0';i++){
		plsfix[i] =result[i];
	}

}
//adjectives(not gonna explain it but its the same as the nouns one)
void replaceAdjs(int adjs, char adjsA[][smol],char plsfix[],char result[]){
	int row = 0;
	int p =0;
	for(int i =0;plsfix[i]!= '\0';i++){
		if(plsfix[i] == 'A' && (row<adjs)){
	 	for(int e=0; adjsA[row][e]!='\0';e++){
	 		result[p++] = adjsA[row][e];
			}
			row++;
		}else{
		result[p++] = plsfix[i];
		}
	}
}

















































