#include <list.h>
#include <stdio.h>
#include <assert.h>

struct linked_list *linked_list = NULL;

void set_up(void)
{
	linked_list = ll_create();
}

void tear_down(void)
{
	if(linked_list)
	{
		ll_destroy(linked_list);
		linked_list = NULL;
	}
}

static void test_ll_create(void)
{
	//Test that ll_create function works properly
	linked_list = ll_create();
	assert(linked_list != NULL);
	//Deallocate memory after every test
	ll_destroy(linked_list);
}

static void test_ll_destroy_of_empty_list(void)
{
	//Create a new linked list
	linked_list = ll_create();
	//Assert that ll_destory returns logical true because empty list was deallocated
	assert(ll_destroy(linked_list) == 1);
}

static void test_ll_destroy_of_populated_list(void)
{
	void *value;
	//int arr[10];
	//Create a new linked list
	linked_list = ll_create();
	//Populate linked list
	ll_add(linked_list, &value);
	//Assert that ll_destroy returns logical false because list is populated
	assert(ll_destroy(linked_list) == 0);
}

static void test_list_empty_returns_true(void)
{
	//Assert that an empty linked list returns true for list_is_empty
	linked_list = ll_create();
	assert(list_is_empty(linked_list) == 1);
	ll_destroy(linked_list);
}

static void test_list_filled_returns_false(void)
{
	//Insert one value into linked list
	void *value;
	linked_list = ll_create();
	ll_add(linked_list, &value);
	//Test that list_is_empty returns false when linked list is not empty
	assert(list_is_empty(linked_list) == 0);
	ll_destroy(linked_list);
}

static void test_ll_add_multiple_elements(void)
{
	void *value;
	int arr[10];

	linked_list = ll_create();

	for (int i = 0; i < 10; i++)
	{
		//Add elements to linked list
		value = &arr[i];
		ll_add(linked_list, value);
	}

	for(int i = 0; i < 10; i++)
	{
		//Test that elements were added and that list is not empty
		assert(list_is_empty(linked_list) == 0);
		ll_remove_first(linked_list);
	}
	//Test that list is empty after removing all added elements
	assert(list_is_empty(linked_list) == 1);
	ll_destroy(linked_list);
}

static void test_repopulation_of_linked_list(void)
{
	void *value;
	int arr[10];

	linked_list = ll_create();

	for (int i = 0; i < 10; i++)
	{
		//Add elements to linked list
		value = &arr[i];
		ll_add(linked_list, value);
	}

	for(int i = 0; i < 10; i++)
	{
		//Test that elements were added and that list is not empty
		assert(list_is_empty(linked_list) == 0);
		ll_remove_first(linked_list);
	}
	//Test that list is empty after removing all added elements
	assert(list_is_empty(linked_list) == 1);

	//Now, repopulate linked list
	for (int i = 0; i < 10; i++)
	{
		//Add elements to linked list
		value = &arr[i];
		ll_add(linked_list, value);
	}

	for(int i = 0; i < 10; i++)
	{
		//Test that elements were added and that list is not empty
		assert(list_is_empty(linked_list) == 0);
		ll_remove_first(linked_list);
	}
	//Test that list is empty after removing all added elements
	assert(list_is_empty(linked_list) == 1);
	ll_destroy(linked_list);
}

static void test_ll_remove_first_in_correct_order(void)
{
	void *value;
	int arr[10];

	linked_list = ll_create();

	printf("\nValues added: \n");

	for (int i = 0; i < 10; i++)
	{
		//Add elements to linked list
		value = &arr[i];
		printf("%p ", value);
		ll_add(linked_list, value);
	}

	printf("\n\nValues removed: \n");

	for(int i = 0; i < 10; i++)
	{
		value = ll_remove_first(linked_list);
		printf("%p ", value);
	}

	printf("\n\n");

	assert(list_is_empty(linked_list) == 1);
	ll_destroy(linked_list);
}

static void test_list_length_is_accurate(void)
{
	linked_list = ll_create();
	void *value;

	for (int i = 0; i < 10; i++)
	{
		ll_add(linked_list, &value);
	}
	
	//After adding elements, test that length returns correct value
	assert(ll_length(linked_list) == 10);

	ll_destroy(linked_list);
}

static void test_contains_method(void)
{
	linked_list = ll_create();
	void *value;
	int arr[10];

	linked_list = ll_create();

	for (int i = 0; i < 10; i++)
	{
		//Add multiple elements to list
		value = &arr[i];
		ll_add(linked_list, value);
	}

	//Test contains method by asserting that function returns true for specified value
	assert(ll_contains(linked_list, &arr[5]) == true);

	ll_destroy(linked_list);
}

static void test_contains_with_different_value(void)
{
	linked_list = ll_create();
	void *value;
	int x = 4;
	int *y = &x;
	int arr[10];

	linked_list = ll_create();

	for (int i = 0; i < 10; i++)
	{
		//Add multiple elements to list
		if (i == 8)
			value = &arr;
		else
			value = y;
		ll_add(linked_list, value);
	}

	//Test contains method by asserting that function returns true for specified value
	assert(ll_contains(linked_list, &arr) == true);
	//assert(ll_contains(linked_list, y) == true);

	ll_destroy(linked_list);
}

static void test_ll_contains_with_null_list(void)
{
	void *value;
	linked_list = ll_create();
	assert(ll_contains(linked_list, &value) == 0);
	ll_destroy(linked_list);
}

int main(void)
{
	test_ll_create();
	printf("ll_create test passed.\n");

	test_ll_destroy_of_empty_list();
	printf("ll_destory test of empty list passed.\n");

	test_ll_destroy_of_populated_list();
	printf("ll_destory test of populated list passed.\n");

	test_list_empty_returns_true();
	printf("list_is_empty test returns as true passed.\n");

	test_list_filled_returns_false();
	printf("list_is_empty test returns as false passed.\n");

	test_ll_add_multiple_elements();
	printf("ll_add test of multiple elements passed.\n");

	test_repopulation_of_linked_list();
	printf("Repopulation of linked list test passed.\n");

	test_ll_remove_first_in_correct_order();
	printf("ll_remove_first test passed.\n");

	test_list_length_is_accurate();
	printf("ll_length test passed.\n");

	test_contains_method();	
	printf("ll_contains test passed.\n");

	test_contains_with_different_value();
	printf("ll_contains with different values passed.\n");

	test_ll_contains_with_null_list();
	printf("ll_contains of NULL linked list passed.\n");

	printf("All tests passed.\n");	

	return 0;
}