#ifndef _ASTARPATHFINDING_H
#define _ASTARPATHFINDING_H

// 用户自定义的权重数组。长度和Grid.gridCostList相同。
#define LENGTH_COST_LIST 100
// uint[] endPoints in class Grid
#define ENDPOINT 10

typedef unsigned int uint;

typedef struct para_path_find
{
    // A*寻路的启发式权重。
    double AStarWeight;
    // 用户自定义的权重数组。长度和Grid.gridCostList相同。
    uint* costList[LENGTH_COST_LIST];
    // 寻路到终点的范围大小。比如说设定范围为3，就把该终点周围距离为3的点作为终点。
    uint range;
    // 是否逃跑，即寻找远离目标的路径。（这个比较麻烦，可以先不做）
    bool flee;
    // 搜索的格子数量的上限，当该上限为0时，忽略该参数。
    // 当搜索的格子数量大于该值时，终止寻路。
    uint maxOps;
}para_path_find;

typedef struct result_path_find
{
    uint ops; // 搜索的格子数量
    uint cost; // 路径总的权重和
    bool isFinish; // 寻路是否完成
    uint* path[]; // 寻路得到的路径，按照[x,y,x,y...]的顺序。
}result_path_find;

class Grid
{
    public:
        Grid(uint width,uint height): width(width),height(height){}
        uint width; // 网格坐标系的宽度，取值为[0, width-1]
        uint height; // 网格坐标系的高度，取值为[0, height-1]
        // 网格坐标系对应每一个格子的权重数组
        // 使用gridCostList[x + y * this.width]的写法来访问某一个格子(x,y)的cost。
        uint gridCostList[LENGTH_COST_LIST]; 
        // 成员函数声明
        // 权重的最大值，如果一个格子的权重大于等于这个权重，
        // 那么这个格子应该被当作无法到达的（也就是忽略掉。）
        uint maxCost; 
        result_path_find* findPath(uint startX, uint startY, uint endPoint[], para_path_find *opts);

};


#endif

