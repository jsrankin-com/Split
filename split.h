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

std::vector<std::string> Split(std::string);

std::vector<std::string> Split(std::istringstream&);

std::vector<std::string> Split(std::string, char);

std::vector<std::string> Split(std::istringstream&, char);

std::vector<std::string> Split(std::string, char[]);

std::vector<std::string> Split(std::istringstream&, char[]);

std::vector<std::string> Split(std::string, std::vector<char>);

std::vector<std::string> Split(std::istringstream&, std::vector<char>);

std::vector<std::string> Split(std::string, std::string);

std::vector<std::string> Split(std::istringstream&, std::string);

std::vector<std::string> Split(std::string, std::string[]);

std::vector<std::string> Split(std::istringstream&, std::string[]);

std::vector<std::string> Split(std::string, std::vector<std::string>);

std::vector<std::string> Split(std::istringstream&, std::vector<std::string>);

std::vector<std::string> Split(std::string, CharacterComparator);

std::vector<std::string> Split(std::istringstream&, CharacterComparator);

std::vector<std::string> Split(std::string, std::regex);

std::vector<std::string> Split(std::istringstream&, std::regex);


template <class T>
std::vector<T> Split(std::string str) {
	std::vector<std::string> str_vec = Split(str);
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
std::vector<T> Split(std::istringstream& iss) {
	std::vector<std::string> str_vec = Split(iss);
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
std::vector<T> Split(std::string str, char del) {
	std::vector<std::string> str_vec = Split(str, del);
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
std::vector<T> Split(std::istringstream& iss, char del) {
	std::vector<std::string> str_vec = Split(iss, del);
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
std::vector<T> Split(std::string str, char del[]) {
	std::vector<std::string> str_vec = Split(str, del);
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
std::vector<T> Split(std::istringstream& iss, char del[]) {
	std::vector<std::string> str_vec = Split(iss, del);
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
std::vector<T> Split(std::string str, std::vector<char> del) {
	std::vector<std::string> str_vec = Split(str, del);
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
std::vector<T> Split(std::istringstream& iss, std::vector<char> del) {
	std::vector<std::string> str_vec = Split(iss, del);
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
std::vector<T> Split(std::string str, std::string del) {
	std::vector<std::string> str_vec = Split(str, del);
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
std::vector<T> Split(std::istringstream& iss, std::string del) {
	std::vector<std::string> str_vec = Split(iss, del);
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
std::vector<T> Split(std::string str, std::string del[]) {
	std::vector<std::string> str_vec = Split(str, del);
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
std::vector<T> Split(std::istringstream& iss, std::string del[]) {
	std::vector<std::string> str_vec = Split(iss, del);
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
std::vector<T> Split(std::string str, std::vector<T> del) {
	std::vector<std::string> str_vec = Split(str, del);
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
std::vector<T> Split(std::istringstream& iss, std::vector<std::string> del) {
	std::vector<std::string> str_vec = Split(iss, del);
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

