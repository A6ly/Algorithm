#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job
{
	int startJob;
	int JobTime;
};

struct Comp
{
	bool operator()(Job a, Job b)
	{
		return a.JobTime > b.JobTime;
	}
};

int solution(vector<vector<int>> jobs)
{
	int answer = 0;
	int currentJob = 0;
	int time = 0;
    sort(jobs.begin(), jobs.end());
	priority_queue<Job, vector<Job>, Comp> pq;

	while (!pq.empty() || currentJob < jobs.size())
	{
		if (jobs.size() > currentJob && time >= jobs[currentJob][0])
		{
			pq.push({ jobs[currentJob][0], jobs[currentJob][1] });
			currentJob++;
		}
		else if (!pq.empty())
		{
			time += pq.top().JobTime;
			answer += time - pq.top().startJob;
			pq.pop();
		}
		else
		{
			time = jobs[currentJob][0];
		}
	}

	answer /= jobs.size();

	return answer;
}