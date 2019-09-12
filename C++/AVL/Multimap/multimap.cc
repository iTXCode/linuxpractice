#include<iostream>
#include<map>
#include<string>
#include<functional>

void TestMultimap(){
  std::multimap<int,std::string,std::greater<int>> testMap;
}

int  main()
{
  TestMultimap();
  return 0;
}
