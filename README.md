# PATH_MAP(轨迹地图)
> 该工程现有是为了拿轨迹来生成对应轨迹地图。该地图会包括该轨迹，轨迹作为占据形式存在，利用该占据围成的圈用于后续路径规划使用。不过该工程为初步构建阶段，后续会根据使用重构与增设对应接口。


### 暂时设计的步骤
- 利用path算出Mat行高
- 根据path算出对应轨迹点的像素，修改值
- 利用贝汉明算法对相应次序的轨迹点，连通直线画图
- 利用图像处理方法（联通域，形态学等）技巧膨胀与移除轨迹圈内对于轨迹
- 利用imwrite保存pgm地图与根据流程修改yaml文件，供后续规划使用

### 瞎想
- 该功能既然给予后续全覆盖路径规划使用，那么本质边缘轨迹与全覆盖路径首要步骤（确定规划范围）重合，不知该生成轨迹地图算不算多此一举的操作。