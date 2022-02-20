#include <bits/stdc++.h>

using namespace std;

class Box {
public:
    int dim[3];
    int v = 1;
    Box(){};
    Box(int arr[]) {
        dim[0] = arr[0];
        dim[1] = arr[1];
        dim[2] = arr[2];
        v = dim[0] * dim[1] * dim[2];
        sort(dim, dim+3);
    }
};

bool cmp(Box a, Box b) {
    return a.v <= b.v;
}

Box box[1000];
int cb[3] = {0};
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int arr[3] = {0};
        scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
        box[i] = Box(arr);
    }
    sort(box, box + n, cmp);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d%d", &cb[0], &cb[1], &cb[2]);
        sort(cb, cb + 3);
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (box[i].v >= cb[0] * cb[1] * cb[2] && box[i].dim[0] >= cb[0] && box[i].dim[1] >= cb[1] && box[i].dim[2] >= cb[2]) {
                flag = 1;
                printf("%d\n", box[i].v);
                break;
            }
        }
        if (!flag) printf("Item does not fit.\n");
    }
    return 0;
}