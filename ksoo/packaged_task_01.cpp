
#include <iostream>
#include <thread>
#include <future>
#include <utility>
#include <vector>


std::vector<int> GetCharItems(int CharCd)
{
	auto ThreadID = std::this_thread::get_id(); 
	std::cout << "GetCharItems ?????? ID: " << ThreadID << std::endl;

	std::vector<int> itemlist;

	for (int i = 1; i <= 5; ++i) 
	{
		itemlist.push_back(i);
	}

	return itemlist;
}

int main()
{
	auto ThreadID = std::this_thread::get_id(); 
	std::cout << "???? ?????? ID: " << ThreadID << std::endl;

	std::packaged_task<std::vector<int>(int)> task(&GetCharItems);
	std::future<std::vector<int>> f = task.get_future();

	std::thread t(std::move(task), 11);
	t.detach();


	auto result = f.get();
	
	for(auto ItemCode : result)
	{
		std::cout << "ĳ?????? ??????: " << ItemCode << std::endl;
	}
  
	return 0;
}

