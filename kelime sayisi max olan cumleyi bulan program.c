#include <stdio.h>
int main() {
	char *S;
	S="We test coders. Give us a try?";
	printf("%s\n",S);
	printf("\nsolution: %d\n", solution(S));
	return 0;
}

int solution(char *S) {
	int max,i,count;
	max=0;
	i=0;
	count=0;
	while(S[i]!='\0') {
		if((S[i]==' ') && S[i-1]!='.' && S[i-1]!='?' && S[i-1]!='!') {
			count++;
		}
		i++;
		if(S[i]=='.' || S[i]=='?' || S[i]=='!') {
			count++;
			if(count>max) {
				max=count;
			}
			count=0;
			i++;
		}
	}
	
	return max;
}
