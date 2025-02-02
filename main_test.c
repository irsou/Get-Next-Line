/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:34:50 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/02 10:34:50 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int     fd;
    char    *line;
    int     test_number = 1;

	// Test 1: Archivo normal con varias líneas
    printf("\n=== Test %d: Archivo normal ===\n", test_number++);
    fd = open("test1.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea leída: [%s]\n", line);
        free(line);
    }
    close(fd);

    // Test 2: Archivo de una sola línea sin \n
    printf("\n=== Test %d: Una línea sin \\n ===\n", test_number++);
    fd = open("test2.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea leída: [%s]\n", line);
        free(line);
    }
    close(fd);

	// Test 3: Archivo vacío
    printf("\n=== Test %d: Archivo vacío ===\n", test_number++);
    fd = open("test3.txt", O_RDONLY);
    line = get_next_line(fd);
    if (line == NULL)
        printf("Correcto: devuelve NULL para archivo vacío\n");
    else
        printf("Error: debería devolver NULL\n");
    free(line);
    close(fd);

	// Test 4: fd inválido
    printf("\n=== Test %d: fd inválido ===\n", test_number++);
    line = get_next_line(-1);
    if (line == NULL)
        printf("Correcto: devuelve NULL para fd inválido\n");
    else
        printf("Error: debería devolver NULL\n");
    free(line);

  	return (0);
}