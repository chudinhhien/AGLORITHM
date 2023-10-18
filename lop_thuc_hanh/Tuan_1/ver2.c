#include <stdio.h>

int main() {
    int t, n;
    scanf("%d %d", &t, &n);
    while (t--) {
        int x;
        scanf("%d", &x);
        printf("%0*d\n", n, x);
    }
    return 0;
}
