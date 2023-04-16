/**
MIT License

Copyright (c) 2023 Rami Mtier

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
**/

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