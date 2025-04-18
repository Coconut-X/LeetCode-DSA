class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjMatrix(numCourses, vector<int>(numCourses, 0));
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adjMatrix[prereq][course] = 1; 
            indegree[course]++; 
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>result;
        while(!q.empty()){

            int node = q.front();
            q.pop();   
            result.push_back(node);

            for(int i=0;i<numCourses;i++)
            {
                if (adjMatrix[node][i] == 1) {
                    indegree[i]--;  
                    if (indegree[i] == 0) {
                        q.push(i); 
                    }
                }
            }
        }

        return result.size()==numCourses;
    }
};