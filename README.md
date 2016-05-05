# LmeTestTools
> 局部最大熵(Localx Maximum Entropy)插值函数构建代理模型时的辅助测试小工具


2016年4月11日10:36:13

* 此程序中包含：样本点生成工具、Isight数据处理工具以及误差分析工具
* 其中样本点生成工具，支持的是均匀抽样，控制参数需要在代码里去修改，以后有时间可以做成输入参数的形式
* Isight数据处理工具，可读取由Isight构建的代理模型而得的预测值，以及样本点初始值和误差分析点初始值等数据
* 误差分析工具，对LME生成的代理模型和Isight生成的代理模型进行误差分析，支持的算法有：L2、R2和NRMSE（目前程序还存在一个小bug，即当LME_predicted_data.txt和Isight_predicted_data.txt最后一行不是空行时，计算程序会出问题，在此先做个备忘，有时间再改进）


2016年4月15日14:44:45

* 增加三维情况的处理


2016年4月27日22:28:38

* Uniform_sampler：在UniformSampling的基础上进行了扩展，可以用于均匀抽样误差分析点，也可以用于均匀抽样样本点同时生成相应的误差分析点
* Isight_data_reader：修正了输出文件末尾输出空行的小bug，取消ErrorPoints的输出
* H_calculator：新增误差分析点的h计算器，计算原理：计算样本点钟到每个误差分析点的最小欧式距离h，由此每个误差分析点都有一个h，这个h用于LME中计算beta用
* Error_analysor：修正了输入输出文件中末尾空行时的bug，此bug的来源即是“[多思考，勤笔记][1]”中提到的`getline()`使用不当引起的，即：

> @ 2016年4月17日00:35:15

>使用getline(infile, lineStr);时，如果infile文件中最后一行不是空行，则会死循环（跳不出循环），这可能是LmeTestTool中有空行没空行时计算出bug的症结之所在。有时间可以去检查一下代码，在这做个备忘。


2016年4月29日16:17:36

* 修正了H_calculator的两个bug：
第一，当ErrorPoints文件末尾存在空行时，最后多输出一个h；
第二增加了 h_all.clear()，避免了在循环寻找每个误差分析点最小h的时候其它误差分析点h的影响。


2016年4月29日18:37:27

* 原Isight_data_reader中，缺少下列任何一个文件时将无法继续处理数据得到Isight_predicted_data.txt，修改为，当缺少文件时仅给出提示，继续处理其他数据，生成Isight_predicted_data.txt，这样做的目的是，有的时候并不需要同时处理7个代理模型的数据，这个时候就不会同时有7份数据，为了处理这样的情况，做此修改
```cpp
RBF-Predicted-Error-Points.txt
RSM2-Predicted-Error-Points.txt
RSM4-Predicted-Error-Points.txt
Kriging1-Predicted-Error-Points.txt
Kriging2-Predicted-Error-Points.txt
Kriging3-Predicted-Error-Points.txt
Kriging4-Predicted-Error-Points.txt
```


2016年5月5日10:42:56

* H_calculator更改了h的计算方法，原h是计算每个error point在样本空间中到sample point的最近距离，修正为寻找error point（设ep1）最近的sample point（设sp1） 然后在样本空间中寻找离sp1最近的sp2，计算sp1到sp2的距离h，这个h即为ep1的h，具体实现通过给error point和sample point创建两个结构体进行实现

* Error_analysor修正了一个bug，取绝对值函数的使用错误，原来是用abs(double x)，这在windows下使用的时候并没有出错，当放到linux上gcc编译的时候，发现同样的公式算出来的数据对不上，在用gcc编译时，double类型的数据用abs()来算会出现数据截断，因为abs()是对int类型的取绝对值函数，要保证代码的正确性应该用fabs()来对double的数据进行取绝对值

* 对double数组进行递增排序的算法学习，详见[多思考，勤笔记][1]

* lme_test主程序，修改了若干问题：
（1）修改了当h非常小时的特例处理情况，如果h非常小ep的预估值就用邻近它的sp的响应值代替（原来的做法是将ep代入已知的方程计算得出响应，现在测试过程这个方程是已知的，但是在实际工程应用的时候这个方程是未知的，所以如果采用代入计算的方法是没有方法得到预估值的，所以存在逻辑错误，所以给h的判断值定非常小，H_TOLERANCE = 1.0e-5，如果h比这个数还小，说明几乎和sp点重合，因此用sp的响应值代替ep的预估值是合理和正确的）

（2）修改了输出出来中显示ep真实响应值的方法，原方法是定义了已知的测试函数，将ep代入该函数公式计算得到响应值，从而输出显示，同上，这样也是存在逻辑错误的，当公式不知道的时候就无法显示了，而其实ep的真实响应已经通过前一阶段的有限元分析提供了，这个时候只需要把结果读进来即可，现在的实现方案也是通过ep和sp的struct来实现的

（3）将读取数据、计算h、lme计算、误差分析都合并至lme_test主程序，并优化了输出显示，改善了操作体验和显示体验



















































[1]: http://liaohuming.net/2016/03/31/20160331-%E5%A4%9A%E6%80%9D%E8%80%83%EF%BC%8C%E5%8B%A4%E7%AC%94%E8%AE%B0/
