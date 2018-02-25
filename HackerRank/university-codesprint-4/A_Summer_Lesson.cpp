vector<int> howManyStudents(int m, vector<int> c) {
    // Return an array denoting the number of students taking each class.
    vector<int> rt(m,0);
    for(int i:c){
        ++rt[i];
    }
    return rt;
}
