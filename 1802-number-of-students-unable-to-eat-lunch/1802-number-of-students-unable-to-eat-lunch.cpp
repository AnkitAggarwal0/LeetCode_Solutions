class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        std::queue<int> students_q; 
        for (int i = 0; i < students.size(); i++){
            students_q.push(students[i]);
        }
        std::queue<int> sandwiches_q; 
        for (int i = 0; i < sandwiches.size(); i++){
            sandwiches_q.push(sandwiches[i]);
        }

        int try_count = 0;
        while (!students_q.empty()){
            
            if (students_q.front() == sandwiches_q.front()){
                students_q.pop(); 
                sandwiches_q.pop(); 
                try_count = 0;
            }

            else {
                int temp = students_q.front(); 
                students_q.pop(); 
                students_q.push(temp); 
                try_count++;
            }
            
            if (try_count >= students_q.size()) return try_count;
        }
        return 0;
    }
};