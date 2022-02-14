#pragma once
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <utility>
#include <functional>
using CharacterComparator = std::function<bool(char)>;

std::vector<std::string> split(std::string);

std::vector<std::string> split(std::istringstream&);

std::vector<std::string> split(std::string, char);

std::vector<std::string> split(std::istringstream&, char);

std::vector<std::string> split(std::string, char[]);

std::vector<std::string> split(std::istringstream&, char[]);

std::vector<std::string> split(std::string, std::vector<char>);

std::vector<std::string> split(std::istringstream&, std::vector<char>);

std::vector<std::string> split(std::string, std::string);

std::vector<std::string> split(std::istringstream&, std::string);

std::vector<std::string> split(std::string, std::string[]);

std::vector<std::string> split(std::istringstream&, std::string[]);

std::vector<std::string> split(std::string, std::vector<std::string>);

std::vector<std::string> split(std::istringstream&, std::vector<std::string>);

std::vector<std::string> split(std::string, CharacterComparator);

std::vector<std::string> split(std::istringstream&, CharacterComparator);

std::vector<std::string> split(std::string, std::regex);

std::vector<std::string> split(std::istringstream&, std::regex);


template <class T>
std::vector<T> split(std::string str) {
	std::vector<std::string> str_vec = split(str);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::istringstream& iss) {
	std::vector<std::string> str_vec = split(iss);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::string str, char del) {
	std::vector<std::string> str_vec = split(str, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::istringstream& iss, char del) {
	std::vector<std::string> str_vec = split(iss, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::string str, char del[]) {
	std::vector<std::string> str_vec = split(str, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::istringstream& iss, char del[]) {
	std::vector<std::string> str_vec = split(iss, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;

}
template <class T>
std::vector<T> split(std::string str, std::vector<char> del) {
	std::vector<std::string> str_vec = split(str, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::istringstream& iss, std::vector<char> del) {
	std::vector<std::string> str_vec = split(iss, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::string str, std::string del) {
	std::vector<std::string> str_vec = split(str, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::istringstream& iss, std::string del) {
	std::vector<std::string> str_vec = split(iss, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::string str, std::string del[]) {
	std::vector<std::string> str_vec = split(str, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::istringstream& iss, std::string del[]) {
	std::vector<std::string> str_vec = split(iss, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::string str, std::vector<T> del) {
	std::vector<std::string> str_vec = split(str, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}
template <class T>
std::vector<T> split(std::istringstream& iss, std::vector<std::string> del) {
	std::vector<std::string> str_vec = split(iss, del);
	T tmp;
	std::vector<T> vec;
	std::istringstream ss;

	for (std::string s : str_vec)
	{
		ss.str(std::string());
		ss.clear();
		ss.str(s);
		ss >> tmp;
		vec.emplace_back(std::move(tmp));
	}
	return vec;
}

