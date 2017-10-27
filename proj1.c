/*
 * Soubor:  proj1.c
 * Datum:   2017/10/15
 * Autor:   Petr Krehlik, xkrehl04
 * Projekt: Prace s textem, 1. projekt do IZP
 */

//nacist knihovny

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int test_input(int argc, char *argv[]){
	int input_len=0;
	if(argc==2 && argv[1]!=NULL){
		input_len=strlen((argv[1]));
	}else{
		return 0;
	}
	return input_len;
}

void load_input(char *argv[], char *input){
	unsigned int a=0;
	while(a<strlen(argv[1])){
		input[a]=toupper(argv[1][a]);
		a++;
	}
	input[a]='\0';
}

/*int load_cities(char *cities[]){

	return 0;
}*/

int main(int argc, char *argv[]){
	int character = 0;
	char cities[50][101];
	int cities_count=0;
	int char_count=0;

	int input_len=test_input(argc,argv);


	char input[input_len];
	
	if(input_len!=0){

		load_input(argv,input);
	}else{
		fprintf( stderr, "Warning: No input parameter detected!\n");
	}
	

	while((character=toupper(getchar()))!=EOF){
		while(character!='\n'){
			if(!(character>31 && character<127)){
				printf("%c",character);
				fprintf( stderr, "Error: Cities input characters are not valid ASCII characters!\n");
				return EXIT_FAILURE;
			}
			if(char_count<100){
				cities[cities_count][char_count]=character;
				char_count++;
			}
			character=toupper(getchar());
		}
		if(char_count>100){
			//printf("%c",cities[cities_count][100]);
			//printf("%d",char_count);
			cities[cities_count][100]='\0';
		}else{
			cities[cities_count][char_count]='\0';
		}
		char_count=0;
		cities_count++;
	}

	char result_chars[cities_count];
	int n=0;
	int i=0;
	int found=0;
	while(i<cities_count){
		if(strlen(cities[i])>strlen(input)){
			int equal=1;
			int z=0;

			while(input[z]!='\0'){

				if(input[z]==cities[i][z]){
				}else{
					equal=0;
					break;
				}
				z++;
			}
			if(equal==1){
				int exist=0;
				for(int y=0;y<n;y++){
					if(result_chars[y]==cities[i][z]){
						exist=1;
						break;
					}
				}
				if(exist==0)
					result_chars[n++]=cities[i][z];
			}
		}else if(strlen(cities[i])==strlen(input)){
			int equal=1;
			int z=0;
			while(cities[i][z]!='\0'){
				if(input[z]==cities[i][z]){
				}else{
					equal=0;
					break;
				}
				z++;
			}
			if(equal==1 && input_len!=0){
				found=1;
				printf("Found: %s\n",input);
			}
		}
		i++;
	}
	if(n>0){
		char v;
		for(int i=0;i<n;i++){
			for(int z=0;z<n;z++){
				if(result_chars[i]<result_chars[z]){
					v=result_chars[i];
					result_chars[i]=result_chars[z];
					result_chars[z]=v;
				}
			}
		}
		printf("Enable: ");
		for(int i=0;i<n;i++){
			if(result_chars[i]==32)
				printf("(SPACE)");
			else
				printf("%c",result_chars[i]);
		}
		printf("\n");
	}else if(found==0){
		printf("Not found\n");
	}

	return EXIT_SUCCESS;
}
