const double eps=1e-8;
const int N=2100;
const double pi=acos(-1.0); 
struct Point 
{
    double x,y; 
    void input()
    {
        scanf("%lf%lf",&x,&y); 
    } 
}point[N];

int n;
double r;

struct node 
{
    double angle;
    int flag; 
}que[N*2+10];
inline int dcmp(double d) {
    return d < -eps ? -1 : d > eps;
}

bool cmp(const node &a,const node &b)
{
    if (dcmp(a.angle-b.angle)==0) return a.flag>b.flag;
    return a.angle<b.angle; 
}
double sqr(double x)
{
    return x*x; 
} 
double dis(const Point &a,const Point &b)
{
    return sqrt(sqr(a.x - b.x)+sqr(a.y - b.y)); 
} 

class Solution {
public:
    int numPoints(vector<vector<int>>& points, int ra) {
        n = points.size();
        for (int i=0;i<n;i++) {
            point[i].x = points[i][0];
            point[i].y = points[i][1];
        }
        r = ra;
        
        int ans=0; 
        
        for (int i=0;i<n;i++)
        {
            int sz=0; 
            for (int j=0;j<n;j++)
            {
                if (i==j) continue;
                double d=dis(point[i],point[j]);
                if (d>2*r+0.001) continue;
                double th=atan2(point[j].y-point[i].y,point[j].x-point[i].x) ; 
                if (th<0) th+=2*pi; 
                double ph=acos(d/2.0/r);
                que[sz++].angle=th-ph+2*pi;que[sz-1].flag=1;
                 que[sz++].angle=th+ph+2*pi;que[sz-1].flag=-1;
            }    
            sort(que,que+sz,cmp);
            int sum=0; 
            for (int j=0;j<sz;j++) ans=max(ans,sum+=que[j].flag);        
        } 
        return ans+1;
    }
};
