

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include <LoremIpsumGenerator.hpp>
#include <iostream>
#include <numeric>
#include <functional>
#include <chrono>

TEST_CASE("speed_test_Runtime")
{
	for (int i = 0; i < 10000; ++i)
	{
		auto li = lorem_ipsum::generate_lorem_ipsum_lines(24);
	}
}

TEST_CASE("speed_test")
{
	for (int i = 0; i < 10000; ++i)
	{
		auto li = lorem_ipsum::generate_lorem_ipsum_lines<24>();
	}
}

TEST_CASE("validity_test")
{
	auto lorem_ipsum = lorem_ipsum::generate_lorem_ipsum_lines<3>();

	REQUIRE(lorem_ipsum == std::string("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Cras elementum ultrices diam."));
}

TEST_CASE("validity_test_Runtime")
{
	auto lorem_ipsum = lorem_ipsum::generate_lorem_ipsum_lines(3);

	REQUIRE(lorem_ipsum == std::string("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Cras elementum ultrices diam."));
}

TEST_CASE("validity_test_Runtime_zero_lines")
{
	auto lorem_ipsum = lorem_ipsum::generate_lorem_ipsum_lines(0);

	REQUIRE(lorem_ipsum == std::string(""));
}

TEST_CASE("validity_test_Runtime_to_much_lines")
{
	CHECK_THROWS(lorem_ipsum::generate_lorem_ipsum_lines(1000));
}