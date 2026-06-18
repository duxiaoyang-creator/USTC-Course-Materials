#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define INF 1000000  // 设定一个足够大的值表示不可达

// 定义城市结构体
typedef struct {
    int id;
    char name[50];
} City;

// 图的邻接矩阵
int dist[MAX_CITIES][MAX_CITIES];
City cities[MAX_CITIES];
int city_count = 0;

// 读取城市信息
void read_city_info(const char *city_file) {
    FILE *file = fopen(city_file, "r");
    if (!file) {
        perror("打开城市文件失败");
        exit(1);
    }
    while (fscanf(file, "%d %s", &cities[city_count].id, cities[city_count].name) == 2) {
        city_count++;
    }
    fclose(file);
}

// 读取铁路网距离信息
void read_rail_info(const char *dist_file) {
    for (int i = 0; i < city_count; i++) {
        for (int j = 0; j < city_count; j++) {
            if (i == j) {
                dist[i][j] = 0;  // 自己到自己是0
            } else {
                dist[i][j] = INF;  // 默认初始化为不可达
            }
        }
    }

    FILE *file = fopen(dist_file, "r");
    if (!file) {
        perror("打开铁路网文件失败");
        exit(1);
    }

    int cityA, cityB, distance;
    while (fscanf(file, "%d %d %d", &cityA, &cityB, &distance) == 3) {
        dist[cityA][cityB] = distance;
        dist[cityB][cityA] = distance;  // 假设铁路是双向的
    }
    fclose(file);
}

// Floyd-Warshall 算法
void floyd_warshall() {
    for (int k = 0; k < city_count; k++) {
        for (int i = 0; i < city_count; i++) {
            for (int j = 0; j < city_count; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// 打印最短路径
void print_shortest_path(int src, int dest) {
    if (dist[src][dest] == INF) {
        printf("从 %s 到 %s 没有可行路径。\n", cities[src].name, cities[dest].name);
    } else {
        printf("从 %s 到 %s 的最短路径长度是：%d\n", cities[src].name, cities[dest].name, dist[src][dest]);
    }
}

// 删除城市
void remove_city(int city_id) {
    for (int i = 0; i < city_count; i++) {
        if (cities[i].id == city_id) {
            for (int j = 0; j < city_count; j++) {
                dist[i][j] = INF;
                dist[j][i] = INF;
            }
        }
    }
}

// 显示城市列表
void display_cities() {
    printf("\n所有城市：\n");
    for (int i = 0; i < city_count; i++) {
        printf("%d. %s\n", cities[i].id, cities[i].name);
    }
}

// 主菜单
void menu() {
    int choice;
    while (1) {
        printf("\n请选择操作：\n");
        printf("1. 计算两个城市之间的最短路径\n");
        printf("2. 删除城市\n");
        printf("3. 退出程序\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int src, dest;
                printf("请输入第一个城市编号：");
                scanf("%d", &src);
                printf("请输入第二个城市编号：");
                scanf("%d", &dest);
                if (src >= 0 && src < city_count && dest >= 0 && dest < city_count) {
                    print_shortest_path(src, dest);
                } else {
                    printf("无效的城市编号！\n");
                }
                break;
            }
            case 2: {
                display_cities();
                int city_id;
                printf("请输入要删除的城市编号：");
                scanf("%d", &city_id);
                remove_city(city_id);
                printf("城市 %d 已删除。\n", city_id);
                floyd_warshall();  // 删除城市后重新计算最短路径
                break;
            }
            case 3:
                printf("退出程序。\n");
                return;
            default:
                printf("无效选择，请重新输入！\n");
                break;
        }
    }
}

// 主函数
int main() {
    // 读取城市和铁路网信息
    read_city_info("city.txt");
    read_rail_info("dist.txt");

    // 执行Floyd-Warshall算法
    floyd_warshall();

    // 显示主菜单
    menu();

    return 0;
}
