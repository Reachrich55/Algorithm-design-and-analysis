#include<iostream>
#include<algorithm>

using namespace std;

// 活动结构体，包含开始时间和结束时间
struct Activity {
    int start;
    int end;
};

// 比较函数，按照结束时间从小到大排序
bool compareActivities(Activity a, Activity b) {
    return a.end < b.end;
}

void ActivitySelection(Activity activities[], int n) {
    // 按照结束时间从小到大排序
    sort(activities, activities + n, compareActivities);

    // 输出排序后的活动列表
    cout << "Sorted Activities: \n";
    for (int i = 0; i < n; i++) {
        cout << "Start: " << activities[i].start << " End: " << activities[i].end << endl;
    }

    // 选择活动的过程
    cout << "\nSelected Activities: \n";
    cout << "Start: " << activities[0].start << " End: " << activities[0].end << endl;

    int lastActivityEnd = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastActivityEnd) {
            cout << "Start: " << activities[i].start << " End: " << activities[i].end << endl;
            lastActivityEnd = activities[i].end;
        }
    }
}

int main() {
    // 示例活动
    Activity activities[] = { {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9} };
    int n = sizeof(activities) / sizeof(activities[0]);

    // 解决活动选择问题
    ActivitySelection(activities, n);

    return 0;
}
