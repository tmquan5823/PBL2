#pragma once
#include"LinkedList.cpp"
#include"Pair.cpp"
#include"Vector.cpp"
#include"order.h"
#include"foods.h"
#include"drinks.h"
#include"NhanVien.h"
#include"Bill.h"

template class Pair<order, int>;
template class LinkedList<order>;
template class LinkedList<Pair<order, int>>;
// template class LinkedList<bill>;
template class Vector<Bill>;
template class Vector<order>;
template class Vector<Pair<order, int>>;
template class Vector<NhanVien>;