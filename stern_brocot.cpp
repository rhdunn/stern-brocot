/* Stern-Brocot Sequence Generator.
 *
 * Copyright (C) 2014 Reece H. Dunn
 *
 * This file is part of stern-brocot.
 *
 * stern-brocot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * stern-brocot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with stern-brocot.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdint>
#include <cstdio>
#include <deque>

struct stern_brocot
{
	stern_brocot(uint32_t aLimit)
		: limit(aLimit)
	{
	}

	struct iterator
	{
		iterator(uint32_t x)
			: n(x)
		{
			values.push_back(1); // t_0 = 1
			values.push_back(1); // t_1 = 1
		}

		iterator &operator++()
		{
			uint32_t a = values.front();
			values.pop_front();
			uint32_t b = values.front();

			values.push_back(a + b);
			values.push_back(b);

			++n;
			return *this;
		}

		const uint32_t &operator*() const
		{
			return values.front();
		}

		bool operator!=(const iterator &rhs)
		{
			return n != rhs.n;
		}
	private:
		std::deque<uint32_t> values;
		uint32_t n;
	};

	iterator begin() { return { 1 }; }

	iterator end() { return { limit }; }
private:
	uint32_t limit;
};

int main(int argc, char ** argv)
{
	for (auto &n : stern_brocot(10))
	{
		fprintf(stdout, "%d,", n);
	}
	fprintf(stdout, "\n");

	return 0;
}
