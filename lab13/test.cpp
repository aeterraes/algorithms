#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
  int isu_number;
  int score;
  Student(int isu_number, int score) : isu_number(isu_number), score(score) {}
};

class Group {
public:
  vector<Student> students;

  void add_student(const Student& student) {
    students.push_back(student);
  }

  void remove_student(int isu) {
    for (auto it = students.begin(); it != students.end(); ++it) {
      if (it->isu_number == isu) {
        students.erase(it);
        break;
      }
    }
  }

  int find_avg() const {
    if (students.empty()) {
      return 0;
    }
    int total_score = 0;
    for (const auto& student : students) {
      total_score += student.score;
    }
    return total_score / students.size();
  }

  int find_mx_score() const {
    if (students.empty()) {
      return 0;
    }
    int max_score = students[0].score;
    for (const auto& student : students) {
      if (student.score > max_score) {
        max_score = student.score;
      }
    }
    return max_score;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, q;
  cin >> m >> q;
  vector<Group> groups(m + 1);
  vector<int> ans;
  for (int i = 0; i < q; i++) {
    char op;
    int group, isu, score;
    cin >> op >> group;
    switch (op) {
    case 'a':
      ans.emplace_back(groups[group].find_avg());
      break;
    case '-':
      cin >> isu;
      groups[group].remove_student(isu);
      break;
    case '+':
      cin >> isu >> score;
      groups[group].add_student(Student(isu, score));
      break;
    case 'm':
      ans.emplace_back(groups[group].find_mx_score());
      break;
    }
  }
  for (const auto& i : ans) {
    cout << i << '\n';
  }
  return 0;
}