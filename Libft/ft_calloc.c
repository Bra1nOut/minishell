/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:49:20 by jockova           #+#    #+#             */
/*   Updated: 2024/12/13 13:11:16 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (size != 0 && ((total_size / size) != nmemb))
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*
int main() {
    // Test 1: Standard allocation
    size_t count = 10;
    size_t size = sizeof(int);
    int *arr = ft_calloc(count, size);
    
    if (arr != NULL) {
        printf("Test 1: Allocation successful! Initialized to zeros.\n");
        for (size_t i = 0; i < count; i++) {
            printf("arr[%zu] = %d\n", i, arr[i]);  // prints 0 for each element
        }
        free(arr);  // Don't forget to free the allocated memory
    } else {
        printf("Test 1: Allocation failed!\n");
    }

    // Test 2: Zero allocation (count == 0 or size == 0)
    count = 0;
    size = 10;  // Allocating zero bytes
    arr = ft_calloc(count, size);
    
    if (arr == NULL) {
        printf("Test 2: Allocation correctly failed for zero bytes.\n");
    } else {
        printf("Test 2: Unexpected allocation success.\n");
        free(arr);  // This would be unexpected, so freeing it in case it happens
    }

    // Test 4: Allocating an empty array of chars
    count = 5;
    size = sizeof(char);
    char *str = ft_calloc(count, size);

    if (str != NULL) {
        printf("Test 4: Allocation successful for char array.\n");
        for (size_t i = 0; i < count; i++) {
            printf("str[%zu] = '%c'\n", i, str[i]);  // prints '\0' for each elmt
        }
        free(str);
    } else {
        printf("Test 4: Allocation failed for char array.\n");
    }

    return 0;
}
*/
