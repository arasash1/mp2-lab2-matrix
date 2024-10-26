#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	const int size = 10;
	TDynamicMatrix<int> m1(size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = i;
		}
	}
	TDynamicMatrix<int> m2(m1);

	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	const int size = 10;
	TDynamicMatrix<int> m1(size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = i;
		}
	}
	TDynamicMatrix<int> m2(m1);

	for(size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			m2[i][j] = i+j;
		}
	}

	EXPECT_NE(m1, m2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m1(10);

	EXPECT_EQ(10, m1.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m1(10);
	m1[0][1] = 322;

	EXPECT_EQ(322, m1[0][1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m1(10);

	ASSERT_ANY_THROW(m1[-1][-5] = 322);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m1(10);

	ASSERT_ANY_THROW(m1[23232][0] = 322);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m1(10);
	m1[2][5] = 88;

	ASSERT_NO_THROW(m1 = m1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 100;
	TDynamicMatrix<int> m1(size), m2(size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = 2*i;
		}
	}

	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	const int size1 = 100, size2 = 200;
	TDynamicMatrix<int> m1(size1), m2(size2);
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size1; j++)
		{
			m1[i][j] = 2 * i;
		}
	}

	m2 = m1;

	EXPECT_EQ(100, m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	const int size1 = 100, size2 = 200;
	TDynamicMatrix<int> m1(size1), m2(size2);
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size1; j++)
		{
			m1[i][j] = 2 * i;
		}
	}

	m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	const int size = 100;
	TDynamicMatrix<int> m1(size), m2(size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = 2 * i;
		}
	}

	m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	const int size = 100;
	TDynamicMatrix<int> m1(size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = 2 * i;
		}
	}

	EXPECT_EQ(m1, m1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	const int size1 = 100, size2 = 200;
	TDynamicMatrix<int> m1(size1), m2(size2);
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size1; j++)
		{
			m1[i][j] = 2 * i;
		}
	}

	EXPECT_NE(m1, m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	const int size = 100;
	TDynamicMatrix<int> m1(size), m2(size), sum(size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = i;
			m2[i][j] = 2*i;
			sum[i][j] = (2 * i) + i;
		}
	}

	m2 = m1 + m2;

	EXPECT_EQ(sum, m2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	const int size1 = 100, size2 = 200;
	TDynamicMatrix<int> m1(size1), m2(size2);
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size1; j++)
		{
			m1[i][j] = 2 * i;
		}
	}

	for (size_t i = 0; i < size2; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			m2[i][j] = i+j;
		}
	}

	ASSERT_ANY_THROW(m2 + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	const int size = 100;
	TDynamicMatrix<int> m1(size), m2(size), sub(size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = i;
			m2[i][j] = 2 * i;
			sub[i][j] = (2 * i) - i;
		}
	}

	m2 = m2 - m1;

	EXPECT_EQ(sub, m2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int size1 = 100, size2 = 200;
	TDynamicMatrix<int> m1(size1), m2(size2);
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size1; j++)
		{
			m1[i][j] = 2 * i;
		}
	}

	for (size_t i = 0; i < size2; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			m2[i][j] = i + j;
		}
	}

	ASSERT_ANY_THROW(m2 - m1);
}

