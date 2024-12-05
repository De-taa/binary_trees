#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 * 
 * Return: Pointer to the sorted array, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t heap_size, i;

    if (!heap || !size)
        return (NULL);

    // Calculate the heap size
    heap_size = binary_tree_size(heap);
    *size = heap_size;

    // Allocate memory for the array
    array = malloc(heap_size * sizeof(int));
    if (!array)
        return (NULL);

    // Extract elements from the heap and store in the array
    for (i = 0; i < heap_size; i++)
    {
        array[i] = heap_extract(&heap);
    }

    return (array);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 * 
 * Return: Size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
