#pragma once

#include <cstdint>

struct GridData
{
	std::uint16_t row = 0;
	std::uint16_t col = 0;
	std::uint16_t rowSpan = 0;
	std::uint16_t colSpan = 0;
};

struct UIProps
{
	GridData gridData = { 0, 0, 0, 0 };
};
