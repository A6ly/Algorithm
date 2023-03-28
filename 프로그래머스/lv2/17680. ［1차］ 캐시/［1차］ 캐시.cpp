#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;
	list<string> cache;

	for (int i = 0; i < cities.size(); i++)
	{
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
	}

	for (int i = 0; i < cities.size(); i++)
	{
		list<string>::iterator itr = find(cache.begin(), cache.end(), cities[i]);

		if (itr == cache.end())
		{
			answer += 5;

			if (cache.size() < cacheSize)
			{
				cache.push_back(cities[i]);
			}
			else if (cache.size() == cacheSize && cacheSize > 0)
			{
				cache.pop_front();
				cache.push_back(cities[i]);
			}

		}
		else
		{
			answer++;

			cache.erase(itr);
			cache.push_back(cities[i]);
		}
	}

	return answer;
}