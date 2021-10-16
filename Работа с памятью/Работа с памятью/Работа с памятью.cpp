#include <iostream>
#include <string>

template <typename T>
class Grid {
private:
	T* memory;
	size_t x_size, y_size;

public:
	Grid(size_t x_size_, size_t y_size_)
	{
		memory = new T[x_size_ * y_size_];
		x_size = x_size_;
		y_size = y_size_;
	}

	Grid(Grid&& src) noexcept
	{
		this->memory = src.memory;
		this->x_size = src.get_xsize();
		this->y_size = src.get_ysize();
		src.memory = nullptr;
	}

	~Grid()
	{
		if (memory != NULL)
		{
			delete[] memory;
		}
	}

	T operator()(size_t x_idx, size_t y_idx) const
	{
		return memory[x_idx * y_size + y_idx];
	}
	T& operator()(size_t x_idx, size_t y_idx)
	{
		return this->memory[x_idx * y_size + y_idx];
	}

	Grid& operator=(Grid&& src) noexcept
	{
		Grid<T> temp(std::move(src));
		std::swap(this->x_size, temp.x_size);
		std::swap(this->y_size, temp.y_size);
		std::swap(this->memory, temp.memory);
		return *this;
	}

	size_t get_xsize() const
	{
		return x_size;
	}
	size_t get_ysize() const
	{
		return y_size;
	}

	Grid& operator = (T temp)
	{
		for (size_t i = 0; i < x_size * y_size; i++)
		{
			memory[i] = temp;
		}
		return *this;
	}

	Grid& operator = (Grid &temp)
	{
		if (get_xsize() != temp.get_xsize() || get_ysize() != temp.get_ysize())
		{
			std::cerr << "The operation is impossible\n";
			return *this;
		}
		for (size_t i = 0; i < x_size * y_size; i++)
		{
			memory[i] = temp(i / x_size, i % x_size);
		}
		return *this;
	}


	friend std::ostream& operator << (std::ostream& out, Grid const& temp)
	{
		if (temp.memory != nullptr)
		{
			size_t x_size = temp.get_xsize();
			size_t y_size = temp.get_ysize();
			for (size_t i = 0; i < x_size * y_size; i++)
			{
				if (i % y_size == 0 && i != 0)
				{
					out << "\n";
				}
				out << temp(i / x_size, i % y_size);
				out << " ";
			}
		}
		return out;
	}

	friend std::istream& operator >> (std::istream& in, Grid& temp)
	{
		size_t x_size = temp.get_xsize();
		size_t y_size = temp.get_ysize();
		for (size_t i = 0; i < x_size * y_size; i++)
		{
			in >> temp(i / x_size, i % y_size);
		}
		return in;
	}
};

int main()
{
	Grid<float> z(5, 5);
	Grid<float> x(5, 5);

	std::cin >> z;
	std::cout << "\n" << "z =" << "\n" << z << "\n\n";

	x = z;
	z = 4;

	std::cout << "\n" << "z =" << "\n" << z << "\n\n";
	std::cout << "\n" << "x =" << "\n" << x << "\n\n";

	Grid<float> &&k(std::move(z));

	std::cout << "\n" << "z =" << "\n" << z << "\n\n";
	std::cout << "\n" << "k =" << "\n" << k << "\n\n";

	Grid<float> l(5, 10);

	l = std::move(k);

	std::cout << "\n" << "l =" << "\n" << l << "\n\n";

	return 0;
}
