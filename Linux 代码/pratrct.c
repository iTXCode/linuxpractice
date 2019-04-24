RT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
        int i, j, k, m, n, rest, a[100][100], gain[100];
        float q[100], f[100], temp[100];
        printf("how many items?\n");
        scanf("%d", &m);
        printf("how many money?\n");
        scanf("%d", &n);
        printf("please input one item gain table:\n");
        for (j = 0; j <= n; j++)
    {
                scanf("%f", &q[j]);
                f[j] = q[j];
            
    }
        for (j = 0; j <= n; j++)
            a[1][j] = j;
        for (k = 2; k <= m; k++)
    {
                printf("input another item gain table:\n");
                for (j = 0; j <= n; j++)
        {
                        temp[j] = q[j];
                        scanf("%f", &q[j]);
                        a[k][j] = 0;
                    
        }
                for (j = 0; j <= n; j++)
                for (i = 0; i <= j; i++)
                if (f[j - i] + q[i] > temp[j])
        {
                        temp[j] = f[j - i] + q[i];
                        a[k][j] = i;
                    
        }
                for (j = 0; j <= n; j++)
                    f[j] = temp[j];
            
    }
        rest = n;
        for (i = m; i >= 1; i--)
    {
                gain[i] = a[i][rest];
                rest = rest - gain[i];
            
    }

        for (i = 1; i <= m; i++)
            printf("%f ", gain[i]);
        printf("%f", f[n]);
        system("pause");
        return 0;

}
