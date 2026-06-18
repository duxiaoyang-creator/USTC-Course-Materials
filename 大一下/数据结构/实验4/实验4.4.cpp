#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CITIES 100
#define INF INT_MAX

// 存储城市的编号和名称
typedef struct {
    int id;
    char name[100];
} City;

City cities[MAX_CITIES];
int cityCount = 0;

// 邻接矩阵表示图
int graph[MAX_CITIES][MAX_CITIES];
int dist[MAX_CITIES][MAX_CITIES]; // 储存最短路径
int path[MAX_CITIES][MAX_CITIES]; // 储存路径信息

// 读取城市数据
void readCityData(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开城市文件！\n");
        return;
    }
    while (fscanf(file, "%d %s", &cities[cityCount].id, cities[cityCount].name) != EOF) {
        cityCount++;
    }
    fclose(file);
}

// 读取铁路网数据
void readRailData(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开铁路网文件！\n");
        return;
    }

    // 初始化图为INF
    for (int i = 0; i < cityCount; i++) {
        for (int j = 0; j < cityCount; j++) {
            graph[i][j] = INF;
            if (i == j) graph[i][j] = 0;
        }
    }

    int cityA, cityB, distance;
    while (fscanf(file, "%d %d %d", &cityA, &cityB, &distance) != EOF) {
        graph[cityA][cityB] = distance;
        graph[cityB][cityA] = distance;  // 假设铁路是双向的
    }

    fclose(file);
}

// 显示城市列表
void showCityList() {
    printf("城市列表:\n");
    for (int i = 0; i < cityCount; i++) {
        printf("%d. %s\n", cities[i].id, cities[i].name);
    }
}

// 使用Floyd-Warshall算法计算最短路径
void floydWarshall() {
    for (int i = 0; i < cityCount; i++) {
        for (int j = 0; j < cityCount; j++) {
            dist[i][j] = graph[i][j];
            if (dist[i][j] != INF && i != j) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < cityCount; k++) {
        for (int i = 0; i < cityCount; i++) {
            for (int j = 0; j < cityCount; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}

// 打印最短路径
void printPath(int start, int end) {
    if (dist[start][end] == INF) {
        printf("从%s到%s没有路径。\n", cities[start].name, cities[end].name);
        return;
    }
    
    printf("从%s到%s的最短路径为：%d\n", cities[start].name, cities[end].name, dist[start][end]);
    printf("经过的城市：");

    int stack[MAX_CITIES];
    int top = -1;

    // 追溯路径
    int current = end;
    while (current != start) {
        stack[++top] = current;
        current = path[start][current];
    }
    stack[++top] = start;

    for (int i = top; i >= 0; i--) {
        printf("%s ", cities[stack[i]].name);
    }
    printf("\n");
}

// 删除城市
void deleteCity(int cityId) {
    int index = -1;
    for (int i = 0; i < cityCount; i++) {
        if (cities[i].id == cityId) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("城市未找到！\n");
        return;
    }

    // 删除城市对应的行和列
    for (int i = 0; i < cityCount; i++) {
        graph[i][index] = INF;  // 删除列
        graph[index][i] = INF;  // 删除行
    }

    // 重新计算最短路径
    floydWarshall();
}

// 菜单界面
void menu() {
    int choice, cityIdA, cityIdB;

    while (1) {
        printf("\n===== 铁路网最短路径计算系统 =====\n");
        printf("1. 查看城市列表\n");
        printf("2. 查询任意两个城市之间的最短路径\n");
        printf("3. 删除城市并重新计算最短路径\n");
        printf("4. 退出\n");
        printf("请输入选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showCityList();
                break;
            case 2:
                {printf("请输入第一个城市编号: ");
                scanf("%d", &cityIdA);
                printf("请输入第二个城市编号: ");
                scanf("%d", &cityIdB);
                int start = cityIdA;  // 从0开始
                int end = cityIdB;
                floydWarshall();
                printPath(start, end);
                break;}
            case 3:
                printf("请输入要删除的城市编号: ");
                scanf("%d", &cityIdA);
                deleteCity(cityIdA);
                break;
            case 4:
                printf("退出程序\n");
                return;
            default:
                printf("无效选项！\n");
        }
    }
}

int main() {
    // 读取数据
    readCityData("city.txt");
    readRailData("dist.txt");

    // 启动菜单
    floydWarshall();  // 程序启动时首先计算最短路径
    menu();

    return 0;
}
