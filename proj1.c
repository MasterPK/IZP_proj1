/*
 * File:  proj1.c
 * Date:   2017/10/15
 * Author:   Petr Krehlik, xkrehl04
 * Project: First project to IZP
 */

//load libraries

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*test input is correct
-1: err
 0: no arg
>0: input length
*/
//plýtvání místem!!!
int test_input(int argc, char *argv[]){
	int input_len=0;
	if(argc==2 && argv[1]!=NULL){
		input_len=strlen((argv[1]));
	}else if(argc>2){
		return -1;
	}
	return input_len;
}

//load input to array

void load_input(char *argv[], char *input){
	unsigned int a=0;
	while(a<strlen(argv[1])){
		input[a]=toupper(argv[1][a]);
		a++;
	}
	input[a]='\0';
}

/*process line by line
-1:none found
 0:found
 1:prefix found
*/
int process_line(char *line, short int *result_chars, char *input){
	printf("%s\n",line);
	if(strlen(line)>strlen(input)){
		int equal=1;
		int z=0;

		while(input[z]!='\0'){
			if(input[z]!=line[z]){
				equal=0;
				return -1;
			}
			z++;
		}
		if(equal==1){
			int position=(int)line[z]-32;
			if(position>=97 && position<=122){
				position=position-32;
			}
			result_chars[position]=1;
			return 1;
		}

	}else if(strlen(line)==strlen(input)){
		int equal=1;
		int z=0;
		while(line[z]!='\0'){
			if(input[z]!=line[z]){
				equal=0;
				return -1;
			}
			z++;
		}
		if(equal==1 && strlen(input)!=0){
			printf("Found: %s\n",input);
			return 0;
		}
	}
	return -1;
}

/*nacte radek
pokud neni co cist vrati chybu
*/

int load_line(char *line){
	if(scanf("%100s[^\n]",line)==EOF){
		return EXIT_FAILURE;
	}else{
		return EXIT_SUCCESS;
	}
	
}


void print_enable(short int *result_chars){
	printf("Enable: ");
	for(int i=0;i<94;i++){
		if(result_chars[i]==1)
			printf("%d",i);
			printf("%c",(char)i+32);
	}
	printf("\n");
}

void print_result(short int *result_chars, int prefix_found, char *prefix_value, int found){
	if(prefix_found==1){
		printf("Found: %s\n",prefix_value);
		if(prefix_found>1){
			print_enable(result_chars);
		}
	}else if(prefix_found>1){
		print_enable(result_chars);
	}else if(found==0){
		printf("Not found\n");
	}
}



int main(int argc, char *argv[]){
	//další dekompozice
	//zrušit dvourozměrné pole
	//zrušit řazení

	//variable init
	
	int input_len=test_input(argc,argv);

	char input[input_len];

	// test of input length
	if(input_len>0){
		load_input(argv,input);
	}else if(input_len==-1){
		fprintf( stderr, "Error: Invalid input!\n");
		return EXIT_FAILURE;
	}else{
		fprintf( stderr, "Warning: No input parameter detected!\n");
	}

	int found=0;
	int cities_count=0;
	short int result_chars[95];
	char line[101];
	char prefix_value[101];
	int prefix_found=0;

	while(load_line(line)!=EXIT_FAILURE){
		for(int i=0;i<100;i++){
			line[i]=toupper(line[i]);
		}
		if(cities_count==42){
			fprintf( stderr, "Error: Cities count is bigger than 42! Program won't accept it!\n");
			return EXIT_FAILURE;
		}
		int vys = process_line(line,result_chars,input);
		if(vys==1){
			prefix_found++;
			for(int i=0;i<100;i++)
				prefix_value[i]=line[i];
		}else if(vys==0){
			found=1;
		}

	}

	// test of cities count
	

	/*}else if(cities_count==-1){
		fprintf( stderr, "Error: Cities input is not valid ASCII characters!\n");
		return EXIT_FAILURE;
	}*/
	


	// lépe rozvrhnout

	//do funkce
	print_result(result_chars,prefix_found,prefix_value,found);
	

	return EXIT_SUCCESS;
}
