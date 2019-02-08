一、运行

1.运行环境：VS2017

2.参考结果

(1)小数据测试注：可以修改不同的alpha比较准确率。训练集数据少结果可能不稳定。


训练集：data/train.conll

开发集：data/dev.conll    平滑参数：0.3    准确率:0.772313    执行时间：3.112s

（2）大数据集测试：

训练集：train.conll

开发集：train.conll   平滑参数:0.3     准确率：0.934261    执行时间: 12.145

开发集：dev.conll     平滑参数：0.01   准确率：0.883518    执行时间：6.916s

开发集：test.conll    平滑参数：0.01   准确率：0.884969    执行时间：8.281s

平滑补充：
std::unordered_map<std::wstring, std::unordered_map<std::wstring, double>> transfer;//当前词，前一个词的概率。

平滑方法：

1.当前词性在数据集中没统计出来的前一个词性给一定的概率。

2.如果前一个词性是空，即当前词性是第一个词，计算其概率、其对应前一个词性是start、

补充统计的误差//

3.统计频数的数据结构，没法统计出来，一些词性只在第一个词性中。故遍历第一个词性，把未统计的该词性去加入进来。



std::unordered_map<std::wstring, std::unordered_map<std::wstring, double>> launch_prob;//当前词，对应词性的概率、

平滑方法：

1.每个词都对应所有词性一定的概率，

2.未登录词给一定的概率

