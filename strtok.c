/*
시스템프로그래밍기초(CSE2018)
2018.12.10
strtok 구현 
*/

#include <stdio.h>

int noMatchPoint(char *,char *);
int yesMatchPoint(char *,char *);
char *strtok(char *,char *);

int main(){
	char str[]="h1 h2 h3 h4 h5 h6";
	char deli[]="9";
	char *ptrArg=strtok(str,deli);
	while(ptrArg!=NULL){
		printf("%s\n",ptrArg);
		ptrArg = strtok(NULL,deli);
	}
	return 0;
}

/* until delimter not find */
int noMatchPoint(char *str,char *deli){
	int index=0;
	
	/* base deli */
	char *baseDeli = deli;
	
	while(*(str+index) != '\0'){
		if(*(str+index) == *deli){
			index++;
			deli=baseDeli;
		} 
		else if (*(deli) != '\0'){
			deli++;
		}
		else{
			break;
		}
	}
	return index;
}


/* until delimeter find */
int yesMatchPoint(char *str,char *deli){
	int index=0;
	
	/* base deli */
	char *baseDeli = deli;
	
	while(*(str+index) != '\0'){
		if(*(str+index) == *deli){
			break;
		} 
		if (*(deli) != '\0'){
			deli++;
		}
		else{
			deli=baseDeli;
			index++;
		}
	}
	return index;
}

char *strtok(char *str,char *deli){
	/* target */
	static char *targetString;
	
	/* initial */
	if(str != NULL){
		targetString = str;
	}

	/* find first index */
	targetString += noMatchPoint(targetString, deli);
	
	/* check last index */
	if (*(targetString)=='\0'){
		return '\0';
	}

	/* create return */
	char *rtn = targetString;
	
	/* find last index */
	targetString += yesMatchPoint(targetString,deli);
	
	/* make char last */
	if (*targetString != '\0'){
		*targetString = '\0';
		targetString++;
	}
	
    return rtn;
}

 
