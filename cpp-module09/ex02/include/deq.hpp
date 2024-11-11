#ifndef DEQ_HPP
#define DEQ_HPP


#include <vector>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <deque>

void fillDequeWithArguments(int argc, char* argv[], std::deque<int>& deq);

void displayDeque(const std::deque<int>& deq);
void swap(int& a, int& b);
void makePairSort(std::deque<int>& deq);
std::deque<int> getSmallValue(const std::deque<int>& deq);
void removeSmallValue(std::deque<int>& deq);
void insertValue(std::deque<int>& deq, int value);
void insertElements(std::deque<int>& deq, const std::deque<int>& deqToPush);
bool isSorted(const std::deque<int>& deq);
int removeLastAndReturn(std::deque<int>& deq);
int removeFirstAndReturn(std::deque<int>& deq);
void insertAtBeginning(std::deque<int>& deq, int value);
int handleFirstCase(std::deque<int>& deq, int& lastValue, size_t& size);
void PmergeAlgo(std::deque<int>& deq);

#endif