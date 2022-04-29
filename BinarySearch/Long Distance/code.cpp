void m(vector<int>& a, vector<int>& idx, vector<int>& ans, int l, int mid, int r){
    int i=0, j=0;
    vector<int> tmp(r-l+1);
    while(i<=mid-l && j<=r-mid-1){
        if(a[idx[i+l]] <= a[idx[j+mid+1]]){
            tmp[i+j] = idx[i+l];
            ans[idx[i+l]] += j;
            i++;
        }
        else{
            tmp[i+j] = idx[j+mid+1];
            j++;
        }
    }
    while(i<=mid-l){
        tmp[i+j] = idx[i+l];
        ans[idx[i+l]] += j;
        i++;
    }
    while(j<=r-mid-1){
        tmp[i+j] = idx[j+mid+1];
        j++;
    }
    for(i=l;i<=r;i++){
        idx[i] = tmp[i-l];
    }
}

void merge(vector<int>& a, vector<int>& idx, vector<int>& ans, int l, int r){
    if(l>=r){
        return;
    }
    int mid = (l+r)/2;
    merge(a,idx,ans,l,mid);
    merge(a,idx,ans,mid+1,r);
    m(a,idx,ans,l,mid,r);
}

vector<int> solve(vector<int>& lst) {
    vector<int> a;
    for(int i=0;i<lst.size();i++){
        a.push_back(i);
    }

    vector<int> ans(lst.size(),0);
    merge(lst,a,ans,0,lst.size()-1);
    return ans;
}
