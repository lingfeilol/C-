class BrowserHistory {
    string vv[5001];
    int cur=-1;//当前网页
    int top=0;//可以访问到的最后面的网页
public:
    BrowserHistory(string homepage) {
        cur++;
        top=cur;
        vv[top++]=homepage;
    }
    
    void visit(string url) {
        cur++;
        top=cur;
        vv[top++]=url;
    }
    
    string back(int steps) {
        if(steps>cur)
            steps=cur;
        cur-=steps;
        return vv[cur];
    }
    
    string forward(int steps) {
        steps=min(steps,top-cur-1);
        cur+=steps;
        return vv[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */