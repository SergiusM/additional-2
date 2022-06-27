#include <iostream>
#include <chrono>
#include <vector>
#define N 10
#define d 10
class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
void ShellSort(int n,int* mas) 
{
	int h = 1;
	while (h < (n / d)) {
		h = 3 * h + 1;
	}
	while (h > 0) 
	{
		for (int k = 0; k < h; k++) 
		{
			int i = k + h;
			while (i < n) 
			{
				int y = mas[i];
				int j = i - h;
				while (j >= 0 && mas[j] > y) {
					mas[j + h] = mas[j];
					j = j - h;
				}
				mas[j + h] = y;
				i = i + h;
			}
		}
		h = h / 3;
	}
}

int main()
{
	int* mas = new int[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand();
	for (int i = 0; i < N; i++)
	{
		std::cout << mas[i] << std::endl;
	}
	Timer A;
	ShellSort(N,mas);
	std::cout << "Time=  " << A.elapsed() << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << mas[i] << std::endl;
	}
	return 0;
}