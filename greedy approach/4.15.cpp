/*有n项任务的集合T={1,2,…, n}
每项任务需要先放到机器A上进行预处理
然后再放到机器B上加工
第i(i=1,2,…, n)项任务的预处理和加工时间分别是a(i)和b(i)
如果机器A只有1台 机器B的数量不限
问如何安排这些任务在机器A上的处理顺序
以使得总的加工时间最短?
总加工时间的含义是:从0时刻机器A开始预处理,到t时刻最后一台机器B停止工作,总加工时间就是t*/
#include <iostream>
#include <algorithm>

using namespace std;

struct Task {
    int aTime;   // 任务预处理时间
    int bTime;   // 任务加工时间
    int finishTime;  // 任务完成时间
};

// 在机器B上加工时间长的任务先做预处理
bool compareTasks(Task task1, Task task2) {
    return task1.bTime > task2.bTime;
}

void scheduleTasks(Task tasks[], int n) {

    sort(tasks, tasks + n, compareTasks);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
        {
            tasks[i].finishTime += tasks[j].aTime;
        }
        tasks[i].finishTime +=  tasks[i].bTime;
    }

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        cout << "Task : Start Time " << currentTime << ", Finish Time " << tasks[i].finishTime << endl;
        currentTime += tasks[i].aTime;
    }
}

int main() {

    // 示例活动
    Task tasks[] = { {2, 5, 0}, {1, 3, 0}, {4, 2, 0} };
    int n = sizeof(tasks) / sizeof(tasks[0]);
    scheduleTasks(tasks, n);

    return 0;
}
