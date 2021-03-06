#include"../../../include/fast_io_device.h"
#include"../../timer.h"
#include<random>

int main()
{
	constexpr std::size_t N{10000000};
	std::vector<std::size_t> values(N);
	std::mt19937_64 eng;
	std::uniform_int_distribution<std::size_t> uind(0,9);
	std::uniform_int_distribution<std::size_t> dist(0, std::numeric_limits<std::size_t>::digits10);
	std::generate(values.begin(), values.end(), [&]()
	{
		std::size_t ret{};
		std::size_t digits{dist(eng)};
		for(std::size_t i{};i!=digits;++i)
			ret=ret*10+uind(eng);
		return ret;
	});
	{
	fast_io::timer t("output");
	fast_io::obuf_file obf("obuf_file.txt");
	for(std::size_t i{};i!=N;++i)
		println(obf,values[i]);
	}
}

/*
output: 0.13900700000000002s
*/