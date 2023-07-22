/**
 * free_list - Frees a linked list.
 * @head: The head of the list.
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}

/**
 * node_end - Adds a node to the end of a linked list.
 * @head: A pointer to the head of the list.
 * @dir: The directory path for the new node to contain.
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
list_t *node_end(list_t **head, char *dir)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *last;

	if (!new)
		return (NULL);

	new->dir = dir;
	new->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	else
		*head = new;

	return (new);
}
