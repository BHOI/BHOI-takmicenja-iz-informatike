#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

void do_command(string cmd) {
    char* char_array = new char[cmd.size() + 1];
    strcpy(char_array, cmd.c_str());
    system(char_array);
}

pii get_rand_point(int l, int r) {
    return mp(rand() % (r - l + 1) + l, rand() % (r - l + 1) + l);
}

ofstream fout;

int main() {
    string pref1, pref2;
    cin >> pref1 >> pref2;
    int l_task, r_task;
    cin >> l_task >> r_task;
    int l, r;
    cin >> l >> r;
    int nmin, nmax, q;
    cin >> nmin >> nmax >> q;

    ofstream numbers("nums.txt");

    for (int task_num = l_task; task_num <= r_task; task_num++) {
        numbers << task_num << endl;
        int n = rand() % (nmax - nmin + 1) + nmin;
        if (task_num >= r_task - 3)
            n = nmax;
        vector<pii> points_original(n);
        vector<pii> query_points(q);
        for (int i = 0; i < n; i++)
            points_original[i] = get_rand_point(l, r);
        for (int i = 0; i < q; i++)
            query_points[i] = get_rand_point(l, r);

        string in_path = "./" + pref1 + "/" + "input" + to_string(task_num) + ".txt";
        string out_path = "./" + pref2 + "/" + "output" + to_string(task_num) + ".txt";

        fout = ofstream(in_path);
        fout << n << " " << q << endl;
        for (pii a : points_original)
            fout << a.first << " " << a.second << endl;
        for (pii b : query_points) {
            fout << rand() % 2 + 1 << " " << b.first << " " << b.second << endl;
        }
        fout.close();
        
        string sol_path = "./main";
        string cmd_create = "touch " + out_path;
        do_command(cmd_create);

        string get_sol_command = sol_path + " >" + out_path + " <" + in_path;
        do_command(get_sol_command);
    }
}