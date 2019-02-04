#pragma once
#define init_size 10;
template <typename Elem>
struct my_deque<Elem>{
	*Elem data;
	int l, r;
	int capicity;

	my_deque();
}
