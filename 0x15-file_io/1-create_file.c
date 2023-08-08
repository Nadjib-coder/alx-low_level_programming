#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: A pointer to the name of the file.
 * @text_content: A pointer to a string to write.
 * Return: 1 (Success) or -1 if the function fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len, w;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content == NULL)
	{
		fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
		return (1);
	}
	len = 0;
	while (text_content[len] != '\0')
	{
		len++;
	}
	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		fd = open(filename, O_CREAT | O_WRONLY, 0600);
	}
	if (fd == -1)
	{
		return (-1);
	}
	w = write(fd, text_content, len);
	if (w == -1)
	{
		return (-1);
	}
	close(fd);
	return (1);
}

