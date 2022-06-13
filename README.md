# SuperHexagonOptimize
降低延迟消灭卡顿！  
Reduce Lags/Latency in SuperHexagon  

## 由于2022/05/31的游戏更新，本项目不再可用
## Due to game update on 2022/05/31, this project won't work any more.

## 如何使用？How to use?
下载Release内的压缩包，解压全部文件到游戏根目录，运行`SuperHexagonOptimize.exe`  
Download release pacgake and extract all files to game directory, then run `SuperHexagonOptimize.exe`.  

## 它是如何工作的？How does it work?  
### glut优化 glut optimization
通过修改glut源码强制创建一个游戏模式的窗口，降低渲染延迟，可参考[我的文章](https://zhuanlan.zhihu.com/p/166658579)  
I modified glut source code to force creating a game mode window, here's [my article (Chinese only)](https://zhuanlan.zhihu.com/p/166658579)  
### DPI优化 DPI optimization
修改了游戏主程序的manifest强制使用每个显示器V2缩放  
I modified game executable's manifest to force use PerMonitor/V2 scailing mode  
### d3d12优化 d3d12 optimization
使用微软开发的d3d12 mesa驱动替代原生opengl，在支持d3d12良好的设备上显著降低延迟并解决卡顿，mesa二进制文件来自[这里](https://github.com/pal1000/mesa-dist-win)  
Use Microsoft's d3d12 mesa gallium driver replace native opengl driver, which can significantly decrease latency and lags on devices with good d3d12 support, mesa binary got from [here](https://github.com/pal1000/mesa-dist-win)  

## optimizeData里面包含什么？What does optimizeData contain?
这是一个zip格式的文件  This is a Zip file.  
`glut.dll`自编译的修改版glut  Modified glut compiled by myself  
`superhexagon.exe`修改版的游戏主程序  Modified game executable  
`dxil.dll,libglapi.dll,opengl32.dll`包含d3d12驱动的Mesa库  Mesa binary with d3d12 support  

## 支持我Support me
1. 你可以在知乎、头条、B站、YouTube搜索`@琴梨梨`并点个关注  
2. 你可以给本项目点个star和watch，并分享本项目给更多需要的人  
3. 你可以[访问这里](https://qinlili.bid/Support/)获取更多直接支持琴梨梨的方法  
4. 你可以向琴梨梨送一些Steam库存内的集换式卡牌或其他道具，使用这个[交易链接](https://steamcommunity.com/tradeoffer/new/?partner=316537125&token=k-jMd5b9)  
  
1. You can give star/watch to this repo and share it to more people in need  
2. You can send cards or other items in Steam inventory to me use this [trade link](https://steamcommunity.com/tradeoffer/new/?partner=316537125&token=k-jMd5b9)  
