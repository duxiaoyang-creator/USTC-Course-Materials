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

// 打印最短路径和路径信息
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

// 主函数
int main() {
    // 读取城市和铁路网信息
    read_city_info("city.txt");
    read_rail_info("dist.txt");

    // 执行Floyd-Warshall算法
    floyd_warshall();

    // 查询最短路径
    printf("查询最短路径：\n");
    print_shortest_path(0, 1); // 假设沈阳是城市0，西安是城市1
    print_shortest_path(2, 3); // 假设呼和浩特是城市2，成都是城市3
    print_shortest_path(4, 5); // 假设上海是城市4，乌鲁木齐是城市5

    // 删除城市（例如郑州，假设郑州的城市编号为某个值）
    int city_id_to_remove = 10;  // 假设郑州的编号为10
    remove_city(city_id_to_remove);

    // 删除城市后重新计算最短路径
    printf("\n删除郑州后的最短路径：\n");
    floyd_warshall();
    print_shortest_path(0, 1);  // 重新查询沈阳至西安的最短路径
    print_shortest_path(2, 3);  // 重新查询呼和浩特至成都的最短路径
    print_shortest_path(4, 5);  // 重新查询上海至乌鲁木齐的最短路径

    return 0;
}
