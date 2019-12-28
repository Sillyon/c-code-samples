#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define linesize 255
#define linecount 100

typedef struct {
	char name[16];
	char surname[32];
	char loginName[8];
}OLD_USER;

typedef struct {
	int id;
	char name[16];
	char surname[32];
	char loginName[8];
	char rights[3];
}NEW_USER;

void loadUsers(FILE *, OLD_USER *, int *);
void convertUsers(NEW_USER *, OLD_USER *, int);
void saveUsers(FILE *, NEW_USER *, int);

int main(int argc, char *argv[]) {
	
	FILE *fp1, *fp2;
	if(!(fp1=fopen("OLD_USER.txt","r"))) {
		printf("File can not be opened\n");
		return -1;
	}
	
	if(!(fp2=fopen("NEW_USER.txt","w"))) {
		printf("File can not be opened\n");
		return -1;
	}
	
	OLD_USER *oldInfo;
	if(!(oldInfo=(OLD_USER*)malloc(linecount*sizeof(OLD_USER)))) {
		printf("can not allocate memory\n");
		return -1;
	}
	
	NEW_USER *newInfo;
	if(!(newInfo=(NEW_USER*)malloc(linecount*sizeof(NEW_USER)))) {
		printf("can not allocate memory\n");
		return -1;
	}
	
	int count=0;
	loadUsers(fp1,oldInfo,&count);
	convertUsers(newInfo, oldInfo, count);
	saveUsers(fp2,newInfo,count);
	
	free(oldInfo);
	free(newInfo);
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

void loadUsers(FILE *fp1, OLD_USER *oldInfo, int *count) {
	
	while(!feof(fp1)) {
		fscanf(fp1,"%s %s %s\n",oldInfo[*count].name,oldInfo[*count].surname,oldInfo[*count].loginName);
		(*count)++;
	}
}

void convertUsers(NEW_USER *newInfo, OLD_USER *oldInfo, int count) {
	
	char *rights="rwx";
	int i;
	for(i=0;i<count;i++) {
		newInfo[i].id=i;
		strcpy(newInfo[i].name, oldInfo[i].name);
		strcpy(newInfo[i].surname, oldInfo[i].surname);
		strcpy(newInfo[i].loginName, oldInfo[i].loginName);
		strcpy(newInfo[i].rights, rights);
	}
}

void saveUsers(FILE *fp2, NEW_USER *newInfo, int count) {
	
	int i;
	for(i=0;i<count;i++) {
		fprintf(fp2,"%d %s %s %s %s\n",newInfo[i].id,newInfo[i].name,newInfo[i].surname,newInfo[i].loginName,newInfo[i].rights);
	}
}
