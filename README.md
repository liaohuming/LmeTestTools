# LmeTestTools
> 局部最大熵(Localx Maximum Entropy)插值函数构建代理模型时的辅助测试小工具


2016年4月11日10:36:13

* 此程序中包含：样本点生成工具、Isight数据处理工具以及误差分析工具
* 其中样本点生成工具，支持的是均匀抽样，控制参数需要在代码里去修改，以后有时间可以做成输入参数的形式
* Isight数据处理工具，可读取由Isight构建的代理模型而得的预测值，以及样本点初始值和误差分析点初始值等数据
* 误差分析工具，对LME生成的代理模型和Isight生成的代理模型进行误差分析，支持的算法有：L2、R2和NRMSE（目前程序还存在一个小bug，即当LME_predicted_data.txt和Isight_predicted_data.txt最后一行不是空行时，计算程序会出问题，在此先做个备忘，有时间再改进）


2016年4月15日14:44:45

* 增加三维情况的处理

