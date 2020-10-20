#include<stdio.h>
#include<string.h>
#define TSIZE 128

int table[100][TSIZE];
char rowone[10][10],rowtwo[10][10],rowthree[10][10],rowfour[10][10];
char terminal[TSIZE];
char nonterminal[26];
struct product {
	char str[100];
	int len;
}pro[20];

int no_pro;
char first[26][TSIZE];
char follow[26][TSIZE];
char first_rhs[100][TSIZE];

int isNT(char c) {
	return c >= 'A' && c <= 'Z';
}

void readFromFile() {
	char buffer[255];
	int i;
	int j,z=0;
	int n;
	printf("\n\n\tEnter the number of lines - ");
	scanf("%d",&n);
	printf("\n\tNote - to enter NULL use ^ \n");
	printf("\n\tEnter the grammar below - \n");
	while (z<n) {
		printf("\t\t\t");
		scanf("%s", buffer);
		j = 0;
		nonterminal[buffer[0] - 'A'] = 1;
		for (i = 0; i < strlen(buffer) - 1; ++i) {
			if (buffer[i] == '|') {
				++no_pro;
				pro[no_pro - 1].str[j] = '\0';
				pro[no_pro - 1].len = j;
				pro[no_pro].str[0] = pro[no_pro - 1].str[0];
				pro[no_pro].str[1] = pro[no_pro - 1].str[1];
				pro[no_pro].str[2] = pro[no_pro - 1].str[2];
				j = 3;
			}
			else {
				pro[no_pro].str[j] = buffer[i];
				++j;
				if (!isNT(buffer[i]) && buffer[i] != '-' && buffer[i] != '>') {
					terminal[buffer[i]] = 1;
				}
			}
		}
		pro[no_pro].len = j;
		++no_pro;z++;
	}

}
void add_FIRST_A_to_FOLLOW_B(char A, char B) {
	int i;
	for (i = 0; i < TSIZE; ++i) {
		if (i != '^')
			follow[B - 'A'][i] = follow[B - 'A'][i] || first[A - 'A'][i];
	}
}

void add_FOLLOW_A_to_FOLLOW_B(char A, char B) {
	int i;
	for (i = 0; i < TSIZE; ++i) {
		if (i != '^')
			follow[B - 'A'][i] = follow[B - 'A'][i] || follow[A - 'A'][i];
	}
}

void FOLLOW() {
	int t = 0;
	int i, j, k, x;
	while (t++ < no_pro) {
		for (k = 0; k < 26; ++k) {
			if (!nonterminal[k])	continue;
			char nt = k + 'A';
			for (i = 0; i < no_pro; ++i) {
				for (j = 3; j < pro[i].len; ++j) {
					if (nt == pro[i].str[j]) {
						for (x = j + 1; x < pro[i].len; ++x) {
							char sc = pro[i].str[x];
							if (isNT(sc)) {
								add_FIRST_A_to_FOLLOW_B(sc, nt);
								if (first[sc - 'A']['^'])
									continue;
							}
							else {
								follow[nt - 'A'][sc] = 1;
							}
							break;
						}
						if (x == pro[i].len)
							add_FOLLOW_A_to_FOLLOW_B(pro[i].str[0], nt);
					}
				}
			}
		}
	}
}

void add_FIRST_A_to_FIRST_B(char A, char B) {
	int i;
	for (i = 0; i < TSIZE; ++i) {
		if (i != '^') {
			first[B - 'A'][i] = first[A - 'A'][i] || first[B - 'A'][i];
		}
	}
}

void FIRST() {
	int i, j;
	int t = 0;
	while (t < no_pro) {
		for (i = 0; i < no_pro; ++i) {
			for (j = 3; j < pro[i].len; ++j) {
				char sc = pro[i].str[j];
				if (isNT(sc)) {
					add_FIRST_A_to_FIRST_B(sc, pro[i].str[0]);
					if (first[sc - 'A']['^'])
						continue;
				}
				else {
					first[pro[i].str[0] - 'A'][sc] = 1;
				}
				break;
			}
			if (j == pro[i].len)
				first[pro[i].str[0] - 'A']['^'] = 1;
		}
		++t;
	}

}

void add_FIRST_A_to_FIRST_RHS__B(char A, int B) {
	int i;
	for (i = 0; i < TSIZE; ++i) {
		if (i != '^')
			first_rhs[B][i] = first[A - 'A'][i] || first_rhs[B][i];
	}
}

void FIRST_RHS() {
	int i, j;
	int t = 0;
	while (t < no_pro) {
		for (i = 0; i < no_pro; ++i) {
			for (j = 3; j < pro[i].len; ++j) {
				char sc = pro[i].str[j];
				if (isNT(sc)) {
					add_FIRST_A_to_FIRST_RHS__B(sc, i);
					if (first[sc - 'A']['^'])
						continue;
				}
				else {
					first_rhs[i][sc] = 1;
				}
				break;
			}
			if (j == pro[i].len)
				first_rhs[i]['^'] = 1;
		}
		++t;
	}

}

int main() {

	readFromFile();

	follow[pro[0].str[0] - 'A']['$'] = 1;

	FIRST();
	FOLLOW();
	FIRST_RHS();
	int i, j, k;
	printf("\n");
	for (i = 0; i < no_pro; ++i) {
		if (i == 0 || (pro[i - 1].str[0] != pro[i].str[0])) {
			char c = pro[i].str[0];
			printf("FIRST OF %c: ", c);
			for (j = 0; j < TSIZE; ++j) {
				if (first[c - 'A'][j]) {
					printf("%c ", j);
				}
			}
			printf("\n");
		}
	}

	printf("\n");
	for (i = 0; i < no_pro; ++i) {
		if (i == 0 || (pro[i - 1].str[0] != pro[i].str[0])) {
			char c = pro[i].str[0];
			printf("FOLLOW OF %c: ", c);
			for (j = 0; j < TSIZE; ++j) {
				if (follow[c - 'A'][j]) {
					printf("%c ", j);
				}
			}
			printf("\n");
		}
	}
	printf("\n");
	printf("\n\t**************** LL(1) PARSING TABLE ENTRIES *******************\n");
	printf("\t--------------------------------------------------------\n\n");
	for (i = 0; i < no_pro; ++i) {
		//printf("FIRST OF %s: ", pro[i].str);
		for (j = 0; j < TSIZE; ++j) {
			if (first_rhs[i][j]) {
				printf("\t\t\t(%c, ",pro[i].str[0]);
				if (j=='^'){
					printf("$): ");
				}
				else{
					printf("%c): ", j);
				}
				
				printf("%s ", pro[i].str);
				printf("\n");
			}
		}
	}
	printf("\n");return 0;

}
