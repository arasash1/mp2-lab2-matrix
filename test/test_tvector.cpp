#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v1(10);
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	TDynamicVector<int> v2(v1);

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v1(10);
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	TDynamicVector<int> v2(v1);
	v2[0] = 12345;

	EXPECT_NE(v1, v2);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v1(10);
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}

	ASSERT_ANY_THROW(v1[-1] = 12345);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v1(10);
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}

	ASSERT_ANY_THROW(v1[v1.size()+10] = 12345);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v1(10);
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}

	ASSERT_NO_THROW(v1 = v1);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	const int size = 100;
	TDynamicVector<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = 0;
		v2[i] = i;
	}
	v1 = v2;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	const int size1 = 5, size2 = 13;
	TDynamicVector<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	EXPECT_EQ(5, v2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	const int size1 = 50, size2 = 100;
	TDynamicVector<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	const int size = 100;
	TDynamicVector<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	EXPECT_EQ(v2, v1);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	const int size = 100;
	TDynamicVector<int> v1(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}

	EXPECT_EQ(v1, v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	const int size1 = 50, size2 = 100;
	TDynamicVector<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}

	for (int i = 0; i < size2; i++)
	{
		v2[i] = 15*i;
	}

	EXPECT_NE(v1, v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	const int size1 = 10;
	TDynamicVector<int> v1(size1);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	v1 = v1 + 15;

	TDynamicVector<int> v2(size1);
	for (int i = 0; i < size1; i++)
	{
		v2[i] = i+15;
	}

	EXPECT_EQ(v2, v1);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	const int size1 = 10;
	TDynamicVector<int> v1(size1);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	v1 = v1 - 15;

	TDynamicVector<int> v2(size1);
	for (int i = 0; i < size1; i++)
	{
		v2[i] = i - 15;
	}

	EXPECT_EQ(v2, v1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	const int size1 = 10;
	TDynamicVector<int> v1(size1);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	v1 = v1 * 15;

	TDynamicVector<int> v2(size1);
	for (int i = 0; i < size1; i++)
	{
		v2[i] = i * 15;
	}

	EXPECT_EQ(v2, v1);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	const int size = 100;
	TDynamicVector<int> v1(size), v2(size), v3(size), v4(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	v2 = v1 + 45;
	v3 = v1 + v2;

	for (int i = 0; i < size; i++)
	{
		v4[i] = (i+45)+i;
	}

	EXPECT_EQ(v4, v3);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	const int size1 = 100, size2 = 200;
	TDynamicVector<int> v1(size1), v2(size2), v3(size1+size2);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	for (int i = 0; i < size2; i++)
	{
		v2[i] = i+322;
	}
	ASSERT_ANY_THROW(v3 = v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	const int size = 100;
	TDynamicVector<int> v1(size), v2(size), v3(size), v4(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	v2 = v1 + 45;
	v3 = v1 - v2;

	for (int i = 0; i < size; i++)
	{
		v4[i] = i - (i + 45);
	}

	EXPECT_EQ(v4, v3);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	const int size1 = 100, size2 = 200;
	TDynamicVector<int> v1(size1), v2(size2), v3(size1 + size2);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	for (int i = 0; i < size2; i++)
	{
		v2[i] = i + 322;
	}
	ASSERT_ANY_THROW(v3 = v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	const int size = 100;
	TDynamicVector<int> v1(size), v2(size), v4(size);
	int mul, my_mul = 0;
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	v2 = v1 + 45;
	mul = v1 * v2;

	for (int i = 0; i < size; i++)
	{
		my_mul += i * (i + 45);
	}

	EXPECT_EQ(my_mul, mul);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	const int size1 = 100, size2 = 200;
	TDynamicVector<int> v1(size1), v2(size2);
	int mul = 0;
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	for (int i = 0; i < size2; i++)
	{
		v2[i] = i + 322;
	}
	ASSERT_ANY_THROW(mul = v1 * v2);
}

