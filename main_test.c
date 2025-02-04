/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:42:32 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/02 14:42:32 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*text;
	int		test_number;

	test_number = 1;
	// Test 1: Archivo normal con varias líneas
	printf("\n=== Test %d: Archivo normal ===\n", test_number++);
	fd = open("test1.txt", O_RDONLY);
	while ((text = get_next_line(fd)) != NULL)
	{
		printf("Línea leída: [%s]\n", text);
		free(text);
	}
	close(fd);
	// Test 2: Archivo de una sola línea sin \n
	printf("\n=== Test %d: Una línea sin \\n ===\n", test_number++);
	fd = open("test2.txt", O_RDONLY);
	while ((text = get_next_line(fd)) != NULL)
	{
		printf("Línea leída: [%s]\n", text);
		free(text);
	}
	close(fd);
	// Test 3: Archivo vacío
	printf("\n=== Test %d: Archivo vacío ===\n", test_number++);
	fd = open("test3.txt", O_RDONLY);
	text = get_next_line(fd);
	if (text == NULL)
		printf("Correcto: devuelve NULL para archivo vacío\n");
	else
		printf("Error: debería devolver NULL\n");
	free(text);
	close(fd);
	// Test 4: fd inválido
	printf("\n=== Test %d: fd inválido ===\n", test_number++);
	text = get_next_line(-1);
	if (text == NULL)
		printf("Correcto: devuelve NULL para fd inválido\n");
	else
		printf("Error: debería devolver NULL\n");
	free(text);
	// Test 5: Big line sin newline
	printf("\n=== Test %d: BigLine sin salto ===\n", test_number++);
	fd = open("test5.txt", O_RDONLY);
	while ((text = get_next_line(fd)) != NULL)
	{
		printf("Línea leída: [%s]\n", text);
		free(text);
	}
	close(fd);
	// Test 6: Big line con newline
	printf("\n=== Test %d: BigLine con salto ===\n", test_number++);
	fd = open("test6.txt", O_RDONLY);
	while ((text = get_next_line(fd)) != NULL)
	{
		printf("Línea leída: [%s]\n", text);
		free(text);
	}
	close(fd);
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	char *str;
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			break;
		printf("%s\n", str);
		free(str);
	}
	return (0);
}*/
