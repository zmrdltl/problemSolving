#include <bits/stdc++.h>
using namespace std;

char line[20000];

int main(){
	for(;;){
		int n;
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &n);
		if (n == 0) break;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			fgets(line, sizeof(line), stdin);
			auto len = strlen(line);
			while(len > 0 && (line[len-1] == '\r' || line[len-1] == '\n')) len--;
			line[len] = '\0';
			for (; cur < len && !isspace(line[cur]); cur++);
		}
		printf("%d\n", cur + 1);
	}
	return 0;
}