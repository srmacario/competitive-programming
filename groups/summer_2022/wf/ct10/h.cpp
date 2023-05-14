#include <bits/stdc++.h>

using namespace std;

typedef long long ld;
typedef long long type;


struct point{
    ld x, y, z;

    point(ld x = 0, ld y = 0, ld z = 0) : x(x), y(y), z(z){}
    point operator -(){ return point(-x, -y, -z);}
    point operator +(point p){ return point(x + p.x, y + p.y, z + p.z);}
    point operator -(point p){ return point(x - p.x, y - p.y, z - p.z);}
    
    point operator *(type k){ return point(k*x, k*y, k*z);}
    point operator /(type k){ return point(x/k, y/k, z/k);}
    ld abs(){return sqrt(x*x + y*y + z*z);}
};

type dot(point p, point q){ return p.x * q.x + p.y * q.y + p.z * q.z;}
point cross(point p, point q){return point((p.y * q.z - p.z * q.y), (p.z * q.x - p.x * q.z), (p.x * q.y - p.y * q.x));}

ld distance_point_plane(ld x, ld y, ld z,
                        ld a, ld b, ld c, ld d)
{
      return fabs(a*x + b*y + c*z - d);                      
}

ostream &operator<<(ostream &os, const point &p){
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}

bool tetra(vector<point> t, point cur){
    for(int i = 0; i < 4; i++){
        vector<point> p;
        p.push_back(t[i]); 
        p.push_back((t[(i + 1)%4])); 
        p.push_back((t[(i + 2)%4]));
        point op = t[(i + 3)%4] - p[0];
        point test = cur - p[0];
        point u = (p[1] - p[0]), v = (p[2] - p[0]);
        point n = cross(u, v);
        if(dot(test, n) * dot(op, n) < 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        vector<point> pts(5);
        for(int i = 0; i < 5; i++){
            cin >> pts[i].x >> pts[i].y >> pts[i].z;
        }
        for(int i = 0; i < 5; i++){
            vector<point> tmp;
            for(int j = 0; j < 5; j++) if(i != j) tmp.push_back(pts[j]);
            if(tetra(tmp, pts[i])){
                cout << i + 1 << "\n";
                break;
            }
        }
    }
}