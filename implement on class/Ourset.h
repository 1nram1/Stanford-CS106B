#include<iostream>
class Ourset
{
public:
Ourset();
bool contain(const std::string &value) const;
void add(const std::string &value) const;

int size() const;
bool isEmpty() const;

private:
int hashfunc(std::string value) ;
int *buckets;
};