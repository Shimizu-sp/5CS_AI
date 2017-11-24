#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

main() {

	int a;
	int i;
	char str1[256];		//Ši”[
	char str2[] = "ƒIƒEƒ€";
	char str3[] = "“Á‹Z";
	char str4[] = "ŒÄ‹z‚·‚é";
	char str5[] = "’¹";
	char str6[] = "¶•¨";

	printf("•¶š‚Ì“ü—Í => ");
	gets(str1);		//•¶š—ñ‚Ì“ü—Í

	printf("isaŠÖŒW‚Í1AhasaŠÖŒW‚Í2 => ");
	scanf("%d", &i);	//”»’è


	if (strstr(str1, str2) != NULL) {	//ƒIƒEƒ€‚ª“ü—Í‚³‚ê‚Ä‚¢‚ê‚Îa‚É1‚ğ‘ã“ü
		a = 1;
	}if (strstr(str1, str5) != NULL) {	//’¹‚ª“ü—Í‚³‚ê‚Ä‚¢‚ê‚Îa‚É2‚ğ‘ã“ü
		a = 2;
	}if (strstr(str1, str6) != NULL) {	//¶•¨‚ª“ü—Í‚³‚ê‚Ä‚¢‚ê‚Îa‚É3‚ğ‘ã“ü
		a = 3;
	
	}

	if (i == 2) {
		if (strstr(str1, str2) != NULL) {

			if (strstr(str1, str3) != NULL) {
				printf("ƒ‚ƒmƒ}ƒl\n");
			}
		}
	}
	if(i == 1){
		if (strstr(str1, str2) != NULL && (str1, str4) != NULL) {
			printf("YES\n");
		}
		switch (a){
			break;
		case 1:
			printf("isaŠÖŒW‚Í\n%s\n«\n%s\n«\n%s\n", str6, str5, str2);
			break;
		case 2:
			printf("isaŠÖŒW‚Í\n%s\n«\n%s\n", str6, str5);
			break;
		case 3:
			printf("isaŠÖŒW‚Í\n%s\n", str6);
			break;
		default:
			printf("ERROR\n");
			break;
		}
	}

	return 0;
}
