#include <stdlib.h>
#include <stdio.h>
extern char ***_NSGetArgv();

void usage(void) {
	printf("Usage: %s source_file dest_file\n", **_NSGetArgv());
	exit(-1);
}

int main(int argc, char **argv, char **envp) {
	if (argc != 3)
		usage();

	FILE *dyld = fopen(argv[1], "r");
	FILE *dyldnew = fopen(argv[2], "w");
	if (!dyld || !dyldnew)
		usage();

	int read=0;
	void *ptr = malloc(16384);
	while ((read=fread(ptr, 1, 16384, dyld))>0)
		fwrite(ptr, 1, read, dyldnew);

	free(ptr);
	return 0;
}

// vim:ft=objc
