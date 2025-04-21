# 第一次作业——苗翔宇

在项目根目录下可以找到`CMakeLists.txt`，由于我已经进行了编译并在`./bin`目录下生成了可执行文件`main.exe`，可以直接运行以下命令进行测试：

```bash
./bin/main
```

下面是每个函数的测试运行结果的截图（截图左下角那个小绿色是光标的提示）

## 矩阵加法

### 行数和列数都相等的

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E6%88%90%E5%8A%9F%E5%8A%A0%E6%B3%95.png)

### 行数相等列数不相等的

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%8A%A0%E6%B3%95%E8%A1%8C%E7%AD%89%E5%88%97%E4%B8%8D%E7%AD%89.png)

### 列数相等行数不相等的

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%8A%A0%E6%B3%95%E5%88%97%E7%AD%89%E8%A1%8C%E4%B8%8D%E7%AD%89.png)

### 行数和列数都不相等的

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%A4%B1%E8%B4%A5%E5%8A%A0%E6%B3%95.png)

**由于减法的代码和加法的几乎没区别，减法只给出行数和列数都相等和不相等的情况，不再给出行数相等列数不相等的和列数相等行数不相等的情况**

## 矩阵减法

### 行数和列数都相等的

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E6%88%90%E5%8A%9F%E5%87%8F%E6%B3%95.png)

### 行数和列数都不相等的

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%A4%B1%E8%B4%A5%E5%87%8F%E6%B3%95.png)

## 矩阵乘法

### a的列数等于b的行数

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E6%88%90%E5%8A%9F%E4%B9%98%E6%B3%95.png)

### a的列数不等于b的行数

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%A4%B1%E8%B4%A5%E4%B9%98%E6%B3%95.png)

## 矩阵数乘

`main.c`文件中限定了`k = 2.0`，测试结果如下

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E6%88%90%E5%8A%9F%E6%95%B0%E4%B9%98%EF%BC%882%E5%80%8D%EF%BC%89.png)

## 矩阵转置

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E8%BD%AC%E7%BD%AE.png)

## 矩阵求行列式

### 方阵

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E6%88%90%E5%8A%9F%E8%A1%8C%E5%88%97%E5%BC%8F.png)

### 非方阵

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%A4%B1%E8%B4%A5%E8%A1%8C%E5%88%97%E5%BC%8F.png)

## 矩阵求逆

### 可逆方阵

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E6%88%90%E5%8A%9F%E6%B1%82%E9%80%86.png)

### 奇异方阵

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E6%B1%82%E9%80%86%E5%A4%B1%E8%B4%A5%EF%BC%88%E5%A5%87%E5%BC%82%E9%98%B5%EF%BC%89.png)

### 非方阵

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E6%B1%82%E9%80%86%E5%A4%B1%E8%B4%A5%EF%BC%88%E9%9D%9E%E6%96%B9%E9%98%B5%EF%BC%89.png)

## 矩阵求秩

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E7%A7%A93.png)

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%B0%8F%E9%87%8F.png)

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%B0%8F%E9%87%8F2.png)

提供了这些测试数据，包括两行差别很小的矩阵

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%B0%8F%E9%87%8F3.png)

可以发现，差别过小时会出现误判，可以通过调整程序里面的宏`EPSILON`来改变精确度

## 矩阵求迹

### 方阵

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E8%BF%B9.png)

### 非方阵

![](https://photos-1355819942.cos.ap-shanghai.myqcloud.com/undefined%E5%A4%B1%E8%B4%A5%E8%BF%B9.png)

