#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool sortBySec(vector<int> vec1, vector<int> vec2){
    return vec1[1] < vec2[1];
}
int scheduleCourse(vector<vector<int>> &courses)
{
    int duration, deadline;
    int finished = 0;
    priority_queue<int> maxHeap;
    sort(courses.begin(), courses.end(), sortBySec);

    for(int i=0; i<courses.size(); i++){
        duration = courses[i][0];
        deadline = courses[i][1];

        // short version
        /**
         * finished += duration;
         * maxHeap.push(duration);
         * if(finished > deadline) maxHeap.pop();
         */
        if(duration <= deadline){
            if(finished+duration > deadline){
                int max_dur = maxHeap.top();
                if(max_dur > duration){
                    finished = finished - max_dur + duration;
                    maxHeap.pop();
                    maxHeap.push(duration);
                }                
            }else{
                finished += duration;
                maxHeap.push(duration);
            }
        }
    }
    return maxHeap.size();
}
int main()
{
    vector<vector<int>> courses = {{9,10},{3,12},{7,17},{4,18},{10,19},{5,20},{10,20}};
    cout << scheduleCourse(courses) << endl;
    return 0;
}