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

#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <deque>
#include <list>

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

static uint32_t *find(std::list<uint32_t> &values, uint32_t n)
{
	for (auto &value : values)
	{
		if (value == n)
			return &value;
	}
	return nullptr;
}

static void list(uint32_t terms)
{
	for (auto &n : stern_brocot(terms + 1))
		fprintf(stdout, "%d,", n);
	fprintf(stdout, "\n");
}

static void filter(uint32_t terms, uint32_t filter, uint32_t i)
{
	for (auto &n : stern_brocot(terms + 1))
	{
		if (n == filter)
			fprintf(stdout, "%d,", i);
		++i;
	}
	fprintf(stdout, "\n");
}

static void sequences(uint32_t terms, uint32_t filter)
{
	std::list<uint32_t> seq;
	uint32_t i = 1;
	for (auto &n : stern_brocot(terms + 1))
	{
		if (n == filter)
		{
			uint32_t *match = find(seq, i);
			if (match == nullptr)
			{
				fprintf(stdout, "%d,", i);
				seq.push_back(i * 2); // next instance of this sequence value
			}
			else
			{
				*match = *match * 2; // next instance of this sequence value
			}
		}
		++i;
	}
	fprintf(stdout, "\n");
}

static void usage()
{
	fprintf(stdout, "usage: stern_brocot list    NUMBER_OF_TERMS\n");
	fprintf(stdout, "usage: stern_brocot filter0 NUMBER_OF_TERMS FILTER_BY_VALUE\n");
	fprintf(stdout, "usage: stern_brocot filter1 NUMBER_OF_TERMS FILTER_BY_VALUE\n");
	fprintf(stdout, "usage: stern_brocot sequences NUMBER_OF_TERMS FILTER_BY_VALUE\n");
}

int main(int argc, char ** argv)
{
	switch (argc)
	{
	case 3:
		if (strcmp(argv[1], "list") == 0)
			list(strtol(argv[2], nullptr, 10));
		else
			usage();
		break;
	case 4:
		if (strcmp(argv[1], "filter0") == 0)
			filter(strtol(argv[2], nullptr, 10), strtol(argv[3], nullptr, 10), 0);
		else if (strcmp(argv[1], "filter1") == 0)
			filter(strtol(argv[2], nullptr, 10), strtol(argv[3], nullptr, 10), 1);
		else if (strcmp(argv[1], "sequences") == 0)
			sequences(strtol(argv[2], nullptr, 10), strtol(argv[3], nullptr, 10));
		else
			usage();
		break;
	default:
		usage();
		break;
	}


	return 0;
}
