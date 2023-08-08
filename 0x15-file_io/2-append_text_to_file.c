#include "main.h"

/**
 * append_text_to_file - a function that appends text at
 * the end of a file.
 * @filename: a pointer to the name of the file
 * @text_content: the text to add at the end of the file
 * Return: 1 (Success), -1 otherwise.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fp, w, length = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}
	fp = open(filename, O_WRONLY | O_APPEND);
	w = write(fp, text_content, length);
	if (fp == -1 || w == -1)
	{
		return (-1);
	}
	close(fp);
	return (1);
}

