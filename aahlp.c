#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(__APPLE__)
#include <malloc.h>
#endif

#define VERSION "1.0.1"

int main(int argc, char *argv[]) {
	int rc = 0, filename_start = 0, counter = 0;
	int i = 0, j = 0, k = 0, l = 0;
	size_t filesize = 0, filename_size = 0;
	char *filename = NULL, *filedata = NULL;
	char *filename_alpha = NULL, *alpha = NULL;
	FILE *infile = NULL, *outfile = NULL;

	if (argc < 2) {
		printf("aahlp, v%s\n", VERSION);
		printf("Copyright (C)  2014, Kevin Selwyn <kevinselwyn@gmail.com>\n\n");
		printf("Usage: %s <infile>\n\n", argv[0]);

		rc = 1;
		goto cleanup;
	}

	filename = argv[1];
	infile = fopen(filename, "rb");

	if (!infile) {
		printf("Could not open %s\n", filename);

		rc = 1;
		goto cleanup;
	}

	fseek(infile, 0, SEEK_END);
	filesize = ftell(infile);
	fseek(infile, 0, SEEK_SET);

	if (!filesize) {
		printf("%s is empty\n", filename);

		rc = 1;
		goto cleanup;
	}

	filedata = malloc(sizeof(char) * filesize + 1);
	alpha = malloc(sizeof(char) * filesize + 1);

	if (!filedata || !alpha) {
		printf("Memory error\n");

		rc = 1;
		goto cleanup;
	}

	if (fread(filedata, 1, filesize, infile) != filesize) {
		printf("Could not read %s\n", filename);

		rc = 1;
		goto cleanup;
	}

	for (i = 0, j = 26, counter = 0; i < j; i++) {
		for (k = 0, l = filesize; k < l; k++) {
			if (filedata[k] == 65 + i || filedata[k] == 97 + i) {
				alpha[counter++] = filedata[k];
			}
		}
	}

	for (i = 0, l = filesize, counter = 0; i < l; i++) {
		if ((filedata[i] >= 65 && filedata[i] <= 90) || (filedata[i] >= 97 && filedata[i] <= 122)) {
			filedata[i] = alpha[counter++];
		}
	}

	filename_size = strlen(filename);
	filename_alpha = malloc(sizeof(char) * filename_size + 1);

	if (!filename_alpha) {
		printf("Memory error\n");

		rc = 1;
		goto cleanup;
	}

	for (i = filename_size - 1, l = 0; i >= l; i--) {
		if (filename[i] == '/') {
			filename_start = i;
			i = l;
		}
	}

	for (i = 0, j = 26, counter = 0; i < j; i++) {
		for (k = filename_start, l = filename_size; k < l; k++) {
			if (filename[k] == 65 + i || filename[k] == 97 + i) {
				filename_alpha[counter++] = filename[k];
			}
		}
	}

	for (i = filename_start, l = filename_size, counter = 0; i < l; i++) {
		if ((filename[i] >= 65 && filename[i] <= 90) || (filename[i] >= 97 && filename[i] <= 122)) {
			filename[i] = filename_alpha[counter++];
		}
	}

	outfile = fopen(filename, "w+");

	if (!outfile) {
		printf("Could not open %s\n", filename);

		rc = 1;
		goto cleanup;
	}

	if (fwrite(filedata, 1, filesize, outfile) != filesize) {
		printf("Could not write %s\n", filename);

		rc = 1;
		goto cleanup;
	}

cleanup:
	if (infile) {
		fclose(infile);
	}

	if (outfile) {
		fclose(outfile);
	}

	if (filedata) {
		free(filedata);
	}

	if (alpha) {
		free(alpha);
	}

	if (filename_alpha) {
		free(filename_alpha);
	}

	return rc;
}